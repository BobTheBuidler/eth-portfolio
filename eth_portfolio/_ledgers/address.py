"""
This module defines the :class:`~eth_portfolio.AddressLedgerBase`, :class:`~eth_portfolio.TransactionsList`, 
:class:`~eth_portfolio.AddressTransactionsLedger`, :class:`~eth_portfolio.InternalTransfersList`, 
:class:`~eth_portfolio.AddressInternalTransfersLedger`, :class:`~eth_portfolio.TokenTransfersList`, 
and :class:`~eth_portfolio.AddressTokenTransfersLedger` classes. These classes manage and interact with ledger entries 
such as transactions, internal transfers, and token transfers associated with Ethereum addresses within the `eth-portfolio` system.

These classes leverage the `a_sync` library to support both synchronous and asynchronous operations, allowing efficient data gathering
and processing without blocking, thus improving the overall responsiveness and performance of portfolio operations.
"""

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
from y import ERC20
from y._decorators import stuck_coro_debugger
from y.datatypes import Block
from y.utils.events import BATCH_SIZE

from eth_portfolio import _exceptions, _loaders
from eth_portfolio._cache import cache_to_disk
from eth_portfolio._decorators import set_end_block_if_none
from eth_portfolio._loaders.transaction import get_nonce_at_block
from eth_portfolio._utils import _AiterMixin, PandableList, get_buffered_chain_height
from eth_portfolio._ydb.token_transfers import TokenTransfers
from eth_portfolio.structs import InternalTransfer, TokenTransfer, Transaction

if TYPE_CHECKING:
    from eth_portfolio.address import PortfolioAddress

logger = logging.getLogger(__name__)

class BadResponse(Exception):
    """
    Exception raised for errors in the response from the web3 provider.
    """


T = TypeVar('T')

_LedgerEntryList = TypeVar("_LedgerEntryList", "TransactionsList", "InternalTransfersList", "TokenTransfersList")
PandableLedgerEntryList = Union["TransactionsList", "InternalTransfersList", "TokenTransfersList"]

class AddressLedgerBase(a_sync.ASyncGenericBase, _AiterMixin[T], Generic[_LedgerEntryList, T], metaclass=abc.ABCMeta):
    """
    Abstract base class for address ledgers in the eth-portfolio system.
    """
    __slots__ = "address", "asynchronous", "cached_from", "cached_thru", "load_prices", "objects", "portfolio_address", "_lock"
    def __init__(self, portfolio_address: "PortfolioAddress") -> None:

        # TODO replace the following line with an abc implementation.
        # assert isinstance(portfolio_address, PortfolioAddress), f"address must be a PortfolioAddress. try passing in PortfolioAddress({portfolio_address}) instead."
        """
        Initializes the AddressLedgerBase instance.

        Args:
            portfolio_address: The :class:`~eth_portfolio.address.PortfolioAddress` this ledger belongs to.
        """
      
        self.portfolio_address = portfolio_address
        """
        The portfolio address this ledger belongs to.
        """
      
        self.address = self.portfolio_address.address
        """
        The Ethereum address being managed.
        """
      
        self.asynchronous = self.portfolio_address.asynchronous
        """
        Flag indicating if the operations are asynchronous.
        """
      
        self.load_prices = self.portfolio_address.load_prices
        """
        Indicates if price loading is enabled.
        """
      
        self.objects: _LedgerEntryList = self._list_type()
        """
        _LedgerEntryList: List of ledger entries.
        """
      
        # NOTE: The following two properties will both be ints once the cache has contents
        self.cached_from: int = None  # type: ignore
        """
        The block from which all entries for this ledger have been loaded into memory.
        """
      
        self.cached_thru: int = None  # type: ignore
        """
        The block through which all entries for this ledger have been loaded into memory.
        """
      
        self._lock = asyncio.Lock()
        """
        asyncio.Lock: Lock for synchronizing access to ledger entries.
        """
    
    def __hash__(self) -> int:
        """
        Returns the hash of the address.

        Returns:
            The hash value.
        """
        return hash(self.address)

    @abc.abstractproperty
    def _list_type(self) -> Type[_LedgerEntryList]:
        """
        Type of list used to store ledger entries.
        """
        ...

    @property
    def _start_block(self) -> int:
        """
        Returns the starting block for the portfolio address.

        Returns:
            The starting block number.
        """
        return self.portfolio_address._start_block

    async def _get_and_yield(self, start_block: Block, end_block: Block) -> AsyncGenerator[T, None]:
        """
        Yields ledger entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Yields:
            AsyncGenerator[T, None]: An async generator of ledger entries.
        """
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
            try:
                if obj not in yielded:
                    yield obj
                    yielded.add(obj)
            except TypeError as e:
                raise TypeError(e, obj) from None
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
        """
        Retrieves ledger entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Returns:
            _LedgerEntryList: The list of ledger entries.

        Examples:
            >>> entries = await ledger.get(12000000, 12345678)
        """
        objects = self._list_type()
        async for obj in self[start_block: end_block]:
            objects.append(obj)
        return objects
    
    @stuck_coro_debugger
    async def new(self) -> _LedgerEntryList:
        """
        Retrieves new ledger entries since the last cached block.

        Returns:
            _LedgerEntryList: The list of new ledger entries.

        Examples:
            >>> new_entries = await ledger.new()
        """
        start_block = 0 if self.cached_thru is None else self.cached_thru + 1
        end_block = await get_buffered_chain_height()
        return self[start_block, end_block]
    
    @set_end_block_if_none
    @stuck_coro_debugger
    async def _get_new_objects(self, start_block: Block, end_block: Block) -> AsyncIterator[T]:
        """
        Retrieves new ledger entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Yields:
            AsyncIterator[T]: An async iterator of new ledger entries.
        """
        async with self._lock:
            async for obj in self._load_new_objects(start_block, end_block):
                yield obj
    
    @abc.abstractmethod
    async def _load_new_objects(self, start_block: Block, end_block: Block) -> AsyncIterator[T]:
        """
        Abstract method to load new ledger entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Yields:
            AsyncIterator[T]: An async iterator of new ledger entries.
        """
        yield

    def _check_blocks_against_cache(self, start_block: Block, end_block: Block) -> Tuple[Block, Block]:
        """
        Checks the specified block range against the cached block range.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Returns:
            Tuple: The adjusted block range.

        Raises:
            ValueError: If the start block is after the end block.
            _exceptions.BlockRangeIsCached: If the block range is already cached.
            _exceptions.BlockRangeOutOfBounds: If the block range is out of bounds.
        """
        if start_block > end_block:
            raise ValueError(f"Start block {start_block} is after end block {end_block}")
        
        # There is no cache
        elif self.cached_from is None or self.cached_thru is None:
            return start_block, end_block

        # Range is cached
        elif start_block >= self.cached_from and end_block <= self.cached_thru:
            raise _exceptions.BlockRangeIsCached()
        
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
            raise _exceptions.BlockRangeOutOfBounds(start_block, end_block, self)
        
        raise NotImplementedError(
            f"""This is a work in progress and we still need code for this specific case. Feel free to create an issue on our github if you need this.
            start_block: {start_block} end_block: {end_block} cached_from: {self.cached_from} cached_thru: {self.cached_thru}""")


class TransactionsList(PandableList[Transaction]):
    """
    A list class for handling transaction entries and converting them to DataFrames.
    """
    def __init__(self):
        super().__init__()
    
    def _df(self) -> DataFrame:
        """
        Converts the list of transactions to a DataFrame.

        Returns:
            DataFrame: The transactions as a DataFrame.
        """
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
    """
    A ledger for managing transaction entries.
    """
    _list_type = TransactionsList
    __slots__ = "cached_thru_nonce", 

    def __init__(self, portfolio_address: "PortfolioAddress"):
        """
        Initializes the AddressTransactionsLedger instance.

        Args:
            portfolio_address: The :class:`~eth_portfolio.address.PortfolioAddress` this ledger belongs to.
        """
        super().__init__(portfolio_address)
        self.cached_thru_nonce = -1
        """
        The nonce through which all transactions have been loaded into memory.
        """

    @set_end_block_if_none
    @stuck_coro_debugger
    async def _load_new_objects(self, _: Block, end_block: Block) -> AsyncIterator[Transaction]:
        """
        Loads new transaction entries between the specified blocks.

        Args:
            _: The starting block number (unused).
            end_block: The ending block number.

        Yields:
            AsyncIterator[Transaction]: An async iterator of transaction entries.
        """
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
    """
    A list class for handling internal transfer entries.
    """
    pass


@cache_to_disk
# we double stack these because high-volume wallets will likely need it
@eth_retry.auto_retry
@stuck_coro_debugger
@a_sync.Semaphore(32, __name__ + ".trace_semaphore")
@eth_retry.auto_retry
async def get_traces(params: list) -> List[dict]:
    """
    Retrieves traces from the web3 provider using the given parameters.

    Args:
        params: The parameters for the trace filter.

    Returns:
        List[dict]: The list of traces.

    Raises:
        :class:`~eth_portfolio.BadResponse`: If the response from the web3 provider is invalid.
    """
    traces = await dank_mids.web3.provider.make_request("trace_filter", params)  # type: ignore [arg-type, misc]
    if 'result' not in traces:
        raise BadResponse(traces)
    return [trace for trace in traces['result'] if "error" not in trace]
    
class AddressInternalTransfersLedger(AddressLedgerBase[InternalTransfersList, InternalTransfer]):
    """
    A ledger for managing internal transfer entries.
    """
    _list_type = InternalTransfersList
    
    @set_end_block_if_none
    @stuck_coro_debugger
    async def _load_new_objects(self, start_block: Block, end_block: Block) -> AsyncIterator[InternalTransfer]:
        """
        Loads new internal transfer entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Yields:
            AsyncIterator[InternalTransfer]: An async iterator of internal transfer entries.
        """
        if start_block == 0:
            start_block = 1

        try:
            start_block, end_block = self._check_blocks_against_cache(start_block, end_block)
        except _exceptions.BlockRangeIsCached:
            return
        except _exceptions.BlockRangeOutOfBounds as e:
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
    """
    A list class for handling token transfer entries.
    """
    pass
  
class AddressTokenTransfersLedger(AddressLedgerBase[TokenTransfersList, TokenTransfer]):
    """
    A ledger for managing token transfer entries.
    """
    _list_type = TokenTransfersList
    __slots__ = "_transfers",
    
    def __init__(self, portfolio_address: "PortfolioAddress"):
        """
        Initializes the AddressTokenTransfersLedger instance.

        Args:
            portfolio_address: The :class:`~eth_portfolio.address.PortfolioAddress` this ledger belongs to.
        """
        super().__init__(portfolio_address)
        self._transfers = TokenTransfers(self.address, self.portfolio_address._start_block, load_prices=self.load_prices)
        """
        TokenTransfers: Instance for handling token transfer operations.
        """
    
    @stuck_coro_debugger
    async def list_tokens_at_block(self, block: Optional[int] = None) -> List[ERC20]:
        """
        Lists the tokens held at a specific block.

        Args:
            block (Optional[int], optional): The block number. Defaults to None.

        Returns:
            List[ERC20]: The list of ERC20 tokens.

        Examples:
            >>> tokens = await ledger.list_tokens_at_block(12345678)
        """
        return [token async for token in self._yield_tokens_at_block(block)]
    
    async def _yield_tokens_at_block(self, block: Optional[int] = None) -> AsyncIterator[ERC20]:
        """
        Yields the tokens held at a specific block.

        Args:
            block (Optional[int], optional): The block number. Defaults to None.

        Yields:
            AsyncIterator[ERC20]: An async iterator of ERC20 tokens.
        """
        yielded = set()
        async for transfer in self[0: block]:
            if transfer.token_address not in yielded:
                yielded.add(transfer.token_address)
                yield ERC20(transfer.token_address, asynchronous=self.asynchronous)
    
    @set_end_block_if_none
    @stuck_coro_debugger
    async def _load_new_objects(self, start_block: Block, end_block: Block) -> AsyncIterator[TokenTransfer]:
        """
        Loads new token transfer entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Yields:
            AsyncIterator[TokenTransfer]: An async iterator of token transfer entries.
        """
        try:
            start_block, end_block = self._check_blocks_against_cache(start_block, end_block)
        except _exceptions.BlockRangeIsCached:
            return
        except _exceptions.BlockRangeOutOfBounds as e:
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
