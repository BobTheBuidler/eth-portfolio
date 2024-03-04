import abc
import asyncio
import logging
from functools import partial
from itertools import product
from typing import (TYPE_CHECKING, AsyncGenerator, AsyncIterator, Generic, List, Optional,
                    Tuple, Type, TypeVar, Union)

import a_sync
import dank_mids
import eth_retry
from pandas import DataFrame  # type: ignore
from tqdm.asyncio import tqdm_asyncio
from y import ERC20
from y.datatypes import Block
from y.decorators import stuck_coro_debugger
from y.utils.events import BATCH_SIZE

from eth_portfolio import _loaders
from eth_portfolio._cache import cache_to_disk
from eth_portfolio._decorators import set_end_block_if_none
from eth_portfolio._loaders.transaction import get_nonce_at_block
from eth_portfolio._ydb.token_transfers import TokenTransfers
from eth_portfolio.structs import InternalTransfer, TokenTransfer, Transaction
from eth_portfolio.utils import (_AiterMixin, PandableList, _unpack_indicies,
                                 get_buffered_chain_height)

if TYPE_CHECKING:
    from eth_portfolio.address import PortfolioAddress

logger = logging.getLogger(__name__)

class BadResponse(Exception):
    pass
  
class BlockRangeIsCached(Exception):
    pass

class BlockRangeOutOfBounds(Exception):
    def __init__(self, start_block: Block, end_block: Block, ledger: "AddressLedgerBase") -> None:
        self.ledger = ledger
        self.start_block = start_block
        self.end_block = end_block
    async def load_remaining(self) -> None:
        return await asyncio.gather(
            self.ledger._load_new_objects(self.start_block, self.ledger.cached_thru - 1),
            self.ledger._load_new_objects(self.ledger.cached_from + 1, self.end_block)
        )



T = TypeVar('T')

_LedgerEntryList = TypeVar("_LedgerEntryList", "TransactionsList", "InternalTransfersList", "TokenTransfersList")
PandableLedgerEntryList = Union["TransactionsList", "InternalTransfersList", "TokenTransfersList"]

class AddressLedgerBase(a_sync.ASyncGenericBase, _AiterMixin[T], Generic[_LedgerEntryList, T], metaclass=abc.ABCMeta):
    __slots__ = "address", "asynchronous", "cached_from", "cached_thru", "load_prices", "objects", "portfolio_address", "_lock"
    def __init__(self, portfolio_address: "PortfolioAddress") -> None:

        # TODO replace the following line with an abc implementation.
        # assert isinstance(portfolio_address, PortfolioAddress), f"address must be a PortfolioAddress. try passing in PortfolioAddress({portfolio_address}) instead."

        self.portfolio_address = portfolio_address
        self.address = self.portfolio_address.address
        self.asynchronous = self.portfolio_address.portfolio.asynchronous
        self.load_prices = self.portfolio_address.portfolio.load_prices
        self.objects: _LedgerEntryList = self._list_type()
        # The following two properties will both be ints once the cache has contents
        self.cached_from: int = None # type: ignore
        self.cached_thru: int = None # type: ignore
        self._lock = asyncio.Lock()
    
    def __hash__(self) -> int:
        return hash(self.address)

    @abc.abstractproperty
    def _list_type(self) -> Type[_LedgerEntryList]:
        ...

    @property
    def _start_block(self) -> int:
        return self.portfolio_address.portfolio._start_block

    async def _get_and_yield(self, start_block: Block, end_block: Block) -> AsyncGenerator[T, None]:
        yielded = set()
        for obj in self.objects:
            block = obj.block_number
            if block < start_block:
                continue
            elif end_block and block > end_block:
                break
            yield obj
            yielded.add(obj)
        async for obj in self._get_new_objects(start_block, end_block):
            if obj not in yielded:
                yield obj
                yielded.add(obj)
        for obj in self.objects:
            block = obj.block_number
            if block < start_block:
                continue
            elif end_block and block > end_block:
                break
            if obj not in yielded:
                yield obj
                yielded.add(obj)
        
    
    @set_end_block_if_none
    @stuck_coro_debugger
    async def get(self, start_block: Block, end_block: Block) -> _LedgerEntryList:
        objects = self._list_type()
        async for obj in self[start_block: end_block]:
            objects.append(obj)
        return objects
    
    @stuck_coro_debugger
    async def new(self) -> _LedgerEntryList:
        start_block = 0 if self.cached_thru is None else self.cached_thru + 1
        end_block = await get_buffered_chain_height()
        return self[start_block, end_block]
    
    @set_end_block_if_none
    @stuck_coro_debugger
    async def _get_new_objects(self, start_block: Block, end_block: Block) -> AsyncIterator[T]:
        async with self._lock:
            async for obj in self._load_new_objects(start_block, end_block):
                yield obj
    
    @abc.abstractmethod
    async def _load_new_objects(self, start_block: Block, end_block: Block) -> AsyncIterator[T]:
        yield

    def _check_blocks_against_cache(self, start_block: Block, end_block: Block) -> Tuple[Block, Block]:
        if start_block > end_block:
            raise ValueError(f"Start block {start_block} is after end block {end_block}")
        
        # There is no cache
        elif self.cached_from is None or self.cached_thru is None:
            return start_block, end_block

        # Range is cached
        elif start_block >= self.cached_from and end_block <= self.cached_thru:
            raise BlockRangeIsCached()
        
        # Beginning of range is cached
        elif start_block >= self.cached_from and start_block < self.cached_thru and end_block > self.cached_thru:
            return self.cached_thru + 1, end_block

        # End of range is cached
        elif start_block < self.cached_from and end_block >= self.cached_from and end_block < self.cached_thru:
            return start_block, self.cached_from - 1
        
        # Beginning and end both outside bounds of cache to high side
        elif start_block > self.cached_thru:
            return self.cached_thru + 1, end_block
        
        # Beginning and end both outside bounds of cache to low side
        elif end_block < self.cached_from:
            return start_block, self.cached_from - 1
            
        # Beginning and end both outside bounds of cache, split
        elif start_block < self.cached_from and end_block > self.cached_thru:
            raise BlockRangeOutOfBounds(start_block, end_block, self)
        
        raise NotImplementedError(
            f"""This is a work in progress and we still need code for this specific case. Feel free to create an issue on our github if you need this.
            start_block: {start_block} end_block: {end_block} cached_from: {self.cached_from} cached_thru: {self.cached_thru}""")


class TransactionsList(PandableList[Transaction]):
    def __init__(self):
        super().__init__()
    
    def _df(self) -> DataFrame:
        df = DataFrame(self)
        if len(df) > 0:
            df.chainId = df.chainId.apply(int)
            df.blockNumber = df.blockNumber.apply(int)
            df.transactionIndex = df.transactionIndex.apply(int)
            df.nonce = df.nonce.apply(int)
            df.gas = df.gas.apply(int)
            df.gasPrice = df.gasPrice.apply(int)
        return df

class AddressTransactionsLedger(AddressLedgerBase[TransactionsList, Transaction]):
    _list_type = TransactionsList
    __slots__ = "cached_thru_nonce", 
    def __init__(self, portfolio_address: "PortfolioAddress"):
        super().__init__(portfolio_address)
        self.cached_thru_nonce = -1

    @set_end_block_if_none
    @stuck_coro_debugger
    async def _load_new_objects(self, _: Block, end_block: Block) -> AsyncIterator[Transaction]:
        if self.cached_thru and end_block < self.cached_thru:
            return
        end_block_nonce = await get_nonce_at_block(self.address, end_block)
        nonces = list(range(self.cached_thru_nonce + 1, end_block_nonce + 1))

        if nonces:
            objects = []
            transaction: Transaction
            async for nonce, transaction in a_sync.as_completed([_loaders.load_transaction(self.address, nonce, self.load_prices) for nonce in nonces], aiter=True, tqdm=True, desc=f"Transactions        {self.address}"):
                if transaction:
                    objects.append(transaction)
                    yield transaction
                elif nonce == 0 and self.cached_thru_nonce == -1:
                    # Gnosis safes
                    self.cached_thru_nonce = 0
                else:
                    # NOTE Are we sure this is the correct way to handle this scenario? Are we sure it will ever even occur with the new gnosis handling?
                    logger.warning("No transaction with nonce %s for %s", nonce, self.address)
            
            if objects:
                self.objects.extend(objects)
            if self.objects:
                self.objects.sort(key=lambda t: t.nonce)
                self.cached_thru_nonce = self.objects[-1].nonce
        
        if self.cached_from is None:
            self.cached_from = 0
        if self.cached_thru is None:
            self.cached_thru = end_block
        elif end_block > self.cached_thru:
            self.cached_thru = end_block

    
class InternalTransfersList(PandableList[InternalTransfer]):
    pass

trace_semaphore = a_sync.Semaphore(32, __name__ + ".trace_semaphore")

@cache_to_disk
# we double stack these because high-volume wallets will likely need it
@eth_retry.auto_retry
@eth_retry.auto_retry
@stuck_coro_debugger
async def get_traces(params: list) -> List[dict]:
    async with trace_semaphore:
        traces = await dank_mids.web3.provider.make_request("trace_filter", params)  # type: ignore [arg-type, misc]
        if 'result' not in traces:
            raise BadResponse(traces)
        return [trace for trace in traces['result'] if "error" not in trace]
    
class AddressInternalTransfersLedger(AddressLedgerBase[InternalTransfersList, InternalTransfer]):
    _list_type = InternalTransfersList
    
    @set_end_block_if_none
    @stuck_coro_debugger
    async def _load_new_objects(self, start_block: Block, end_block: Block) -> AsyncIterator[InternalTransfer]:
        if start_block == 0:
            start_block = 1

        try:
            start_block, end_block = self._check_blocks_against_cache(start_block, end_block)
        except BlockRangeIsCached:
            return
        except BlockRangeOutOfBounds as e:
            await e.load_remaining()
            return

        block_ranges = [[hex(i), hex(i + BATCH_SIZE - 1)] for i in range(start_block, end_block, BATCH_SIZE)]
        
        trace_filter_coros = [
            get_traces([{direction: [self.address],"fromBlock": start, "toBlock": end}])
            for direction, (start, end) in product(["toAddress", "fromAddress"], block_ranges)
        ]

        generator_function = a_sync.as_completed
        # NOTE: We only want tqdm progress bar when there is work to do
        if len(block_ranges) > 1:
            generator_function = partial(generator_function, tqdm=True, desc=f"Trace Filters       {self.address}")

        if tasks := [
            asyncio.create_task(coro=_loaders.load_internal_transfer(trace, self.load_prices), name="load_internal_transfer")
            for traces in generator_function(trace_filter_coros)
            for trace in await traces
        ]:
            objects = []
            async for obj in a_sync.as_completed(tasks, aiter=True, tqdm=True, desc=f"Internal Transfers  {self.address}"):
                if obj:
                    objects.append(obj)
                    yield obj
            if objects:
                self.objects.extend(objects)
            self.objects.sort(key=lambda t: (t.block_number, t.transaction_index))

        if self.cached_from is None or start_block < self.cached_from:
            self.cached_from = start_block
        if self.cached_thru is None or end_block > self.cached_thru:
            self.cached_thru = end_block


class TokenTransfersList(PandableList[TokenTransfer]):
    pass
  
class AddressTokenTransfersLedger(AddressLedgerBase[TokenTransfersList, TokenTransfer]):
    _list_type = TokenTransfersList
    __slots__ = "_transfers",
    def __init__(self, portfolio_address: "PortfolioAddress"):
        super().__init__(portfolio_address)
        self._transfers = TokenTransfers(self.address, self.portfolio_address.portfolio._start_block, load_prices=self.load_prices)
    
    @stuck_coro_debugger
    async def list_tokens_at_block(self, block: Optional[int] = None) -> List[ERC20]:
        return [token async for token in self._yield_tokens_at_block(block)]
    
    async def _yield_tokens_at_block(self, block: Optional[int] = None) -> AsyncIterator[ERC20]:
        yielded = set()
        async for transfer in self[0: block]:
            if transfer.token_address not in yielded:
                yielded.add(transfer.token_address)
                yield ERC20(transfer.token_address, asynchronous=self.asynchronous)
    
    @set_end_block_if_none
    @stuck_coro_debugger
    async def _load_new_objects(self, start_block: Block, end_block: Block) -> AsyncIterator[TokenTransfer]:
        try:
            start_block, end_block = self._check_blocks_against_cache(start_block, end_block)
        except BlockRangeIsCached:
            return
        except BlockRangeOutOfBounds as e:
            await e.load_remaining()
            return
                        
        if tasks := [task async for task in self._transfers.yield_thru_block(end_block) if start_block <= task.block]:
            objects = []
            async for obj in a_sync.as_completed(tasks, aiter=True, tqdm=True, desc=f"Token Transfers     {self.address}"):
                if obj:
                    objects.append(obj)
                    yield obj
            if objects:
                self.objects.extend(objects)
            self.objects.sort(key=lambda t: (t.block_number, t.transaction_index, t.log_index))
            
        if self.cached_from is None or start_block < self.cached_from:
            self.cached_from = start_block
        if self.cached_thru is None or end_block > self.cached_thru:
            self.cached_thru = end_block
