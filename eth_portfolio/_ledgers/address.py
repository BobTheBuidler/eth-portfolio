import abc
import asyncio
import logging
from functools import partial
from itertools import product
from typing import (TYPE_CHECKING, Any, Dict, Generic, List, Optional, Tuple,
                    Type, TypeVar, Union)

import a_sync
import eth_retry
import inflection
from async_lru import alru_cache
from brownie import chain
from brownie.exceptions import ContractNotFound
from brownie.network.event import _EventItem
from dank_mids.semaphores import BlockSemaphore
from eth_abi import encode_single
from eth_utils import encode_hex, to_checksum_address
from pandas import DataFrame  # type: ignore
from tqdm.asyncio import tqdm_asyncio
from web3.types import TxData, TxReceipt
from y import ERC20, Contract, get_price
from y.constants import EEE_ADDRESS
from y.datatypes import Address, Block
from y.exceptions import ContractNotVerified, NonStandardERC20
from y.utils.dank_mids import dank_w3
from y.utils.events import BATCH_SIZE, decode_logs, get_logs_asap_generator

from eth_portfolio._cache import cache_to_disk
from eth_portfolio._decorators import await_if_sync, set_end_block_if_none
from eth_portfolio._shitcoins import SHITCOINS
from eth_portfolio.constants import TRANSFER_SIGS, sync_threads
from eth_portfolio.structs import InternalTransfer, TokenTransfer, Transaction
from eth_portfolio.utils import (Decimal, PandableList, _get_price,
                                 _unpack_indicies, get_buffered_chain_height)

if TYPE_CHECKING:
    from eth_portfolio.address import PortfolioAddress

logger = logging.getLogger(__name__)

transaction_semaphore = BlockSemaphore(100, name='eth_portfolio.transactions')  # Some arbitrary number
token_transfer_semaphore = BlockSemaphore(5_000, name='eth_portfolio.token_transfers')  # Some arbitrary number

class BadResponse(Exception):
    pass
  
class BlockRangeIsCached(Exception):
    pass

class BlockRangeOutOfBounds(Exception):
    pass

receipt_semaphore = a_sync.Semaphore(50)

@eth_retry.auto_retry
@cache_to_disk
async def _get_transaction_receipt(txhash: str) -> TxReceipt:
    async with receipt_semaphore:
        return await dank_w3.eth.get_transaction_receipt(txhash)

_LedgerEntryList = TypeVar("_LedgerEntryList", "TransactionsList", "InternalTransfersList", "TokenTransfersList")
PandableLedgerEntryList = Union["TransactionsList", "InternalTransfersList", "TokenTransfersList"]

class AddressLedgerBase(Generic[_LedgerEntryList], metaclass=abc.ABCMeta):
    list_type: Type[_LedgerEntryList]

    def __init__(self, portfolio_address: "PortfolioAddress") -> None:
        assert hasattr(self.__class__, 'list_type'), f"{self.__class__.__name__} must have a list_type attribute."
        assert hasattr(self, 'list_type'), f"{self.__class__.__name__} must have a list_type attribute."

        # TODO replace the following line with an abc implementation.
        # assert isinstance(portfolio_address, PortfolioAddress), f"address must be a PortfolioAddress. try passing in PortfolioAddress({portfolio_address}) instead."

        self.portfolio_address = portfolio_address
        self.objects: _LedgerEntryList = self.list_type()
        # The following two properties will both be ints once the cache has contents
        self.cached_from: int = None # type: ignore
        self.cached_thru: int = None # type: ignore
        self._semaphore = asyncio.Semaphore(1)
    
    def __hash__(self) -> int:
        return hash(self.address)
    
    @property
    def address(self) -> Address:
        return self.portfolio_address.address
    
    @property
    def asynchronous(self) -> bool:
        return self.portfolio.asynchronous
    
    @property
    def load_prices(self) -> bool:
        return self.portfolio.load_prices
    
    @property
    def portfolio(self) -> "Portfolio": # type: ignore
        return self.portfolio_address.portfolio
    
    def __getitem__(self, indicies: Union[Block,Tuple[Block,Block]]) -> _LedgerEntryList:
        start_block, end_block = _unpack_indicies(indicies)
        if asyncio.get_event_loop().is_running():
            return self._get_async(start_block, end_block) #type: ignore
        return self.get(start_block, end_block)
    
    @await_if_sync
    def get(self, start_block: Block, end_block: Block) -> _LedgerEntryList:
        return self._get_async(start_block, end_block) # type: ignore
    
    @set_end_block_if_none
    async def _get_async(self, start_block: Block, end_block: Block) -> _LedgerEntryList:
        await self._get_new_objects(start_block, end_block)
        objects = self.list_type()
        for obj in self.objects:
            block = obj['blockNumber']
            if block < start_block:
                continue
            elif block > end_block:
                break
            objects.append(obj)
        return objects
    
    @await_if_sync
    def new(self) -> _LedgerEntryList:
        return self._new_async() # type: ignore
    
    async def _new_async(self) -> _LedgerEntryList:
        start_block = 0 if self.cached_thru is None else self.cached_thru + 1
        end_block = await get_buffered_chain_height()
        return self[start_block, end_block]
    
    @set_end_block_if_none
    async def _get_new_objects(self, start_block: Block, end_block: Block) -> None:
        async with self._semaphore:
            await self._load_new_objects(start_block, end_block)
    
    @abc.abstractmethod
    async def _load_new_objects(self, start_block: Block, end_block: Block) -> None:
        ...

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
            raise BlockRangeOutOfBounds()
        
        raise NotImplementedError(
            f"""This is a work in progress and we still need code for this specific case. Feel free to create an issue on our github if you need this.
            start_block: {start_block} end_block: {end_block} cached_from: {self.cached_from} cached_thru: {self.cached_thru}""")
    

full_block_semaphore = asyncio.Semaphore(10)

@eth_retry.auto_retry
async def _get_block_transactions(block: Block) -> List[TxData]:
    async with full_block_semaphore:
        block = await dank_w3.eth.get_block(block, full_transactions=True)
        return block.transactions

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

class AddressTransactionsLedger(AddressLedgerBase[TransactionsList]):
    list_type = TransactionsList

    def __init__(self, portfolio_address: "PortfolioAddress"):
        super().__init__(portfolio_address)
        self.cached_thru_nonce = -1

    @set_end_block_if_none
    async def _load_new_objects(self, _: Block, end_block: Block) -> None:
        if end_block is None:
            end_block = await get_buffered_chain_height()
        if self.cached_thru and end_block < self.cached_thru:
            return
        end_block_nonce = await self._get_nonce_at_block(end_block)
        nonces = list(range(self.cached_thru_nonce + 1, end_block_nonce + 1))

        if nonces:
            transaction: Transaction
            for fut in tqdm_asyncio.as_completed([self._get_transaction_by_nonce(nonce) for nonce in nonces], desc=f"Transactions        {self.address}"):
                transaction = await fut
                if transaction is not None:
                    self.objects.append(transaction)
            
            if self.objects:
                self.objects.sort(key=lambda t: t.nonce)
                self.cached_thru_nonce = self.objects[-1].nonce
        
        if self.cached_from is None:
            self.cached_from = 0
        if self.cached_thru is None:
            self.cached_thru = end_block
        elif end_block > self.cached_thru:
            self.cached_thru = end_block

    @cache_to_disk
    @eth_retry.auto_retry
    async def _get_transaction_by_nonce(self, nonce: int) -> Optional[Transaction]:
        lo = 0
        hi = await dank_w3.eth.block_number
        while True:
            async with transaction_semaphore[lo]:
                _nonce = await self._get_nonce_at_block(lo)
                if _nonce < nonce:
                    old_lo = lo
                    lo += int((hi - lo) / 2) or 1
                    logger.debug(f"Nonce at {old_lo} is {_nonce}, checking higher block {lo}")
                elif _nonce >= nonce:
                    prev_block_nonce = await self._get_nonce_at_block(lo - 1)
                    if prev_block_nonce < nonce:
                        logger.debug(f"Found nonce {nonce} at block {lo}")
                        tx = await self._get_transaction_by_nonce_and_block(nonce, lo)
                        if tx is None:
                            return None
                        tx = dict(tx)
                        tx['chainid'] = int(tx.pop('chainId'), 16) if 'chainId' in tx else chain.id
                        tx['block_hash'] = tx.pop('blockHash').hex()
                        tx['hash'] = tx['hash'].hex()
                        tx['from_address'] = tx.pop('from')
                        tx['to_address'] = tx.pop('to')
                        tx['value'] = Decimal(tx['value']) / Decimal(1e18)
                        tx['type'] = int(tx['type'], 16) if "type" in tx else None
                        tx['r'] = tx['r'].hex()
                        tx['s'] = tx['s'].hex()
                        if self.load_prices:
                            tx['price'] = round(Decimal(await get_price(EEE_ADDRESS, block = tx['blockNumber'], sync=False)), 18)
                            tx['value_usd'] = tx['value'] * tx['price']
                        return Transaction(**{inflection.underscore(k): v for k, v in tx.items()})
                    hi = lo
                    lo = int(lo / 2)
                    logger.debug(f"Nonce at {hi} is {_nonce}, checking lower block {lo}")
    
    @eth_retry.auto_retry
    async def _get_transaction_by_nonce_and_block(self, nonce: int, block: Block) -> Optional[TxData]:
        txs = await _get_block_transactions(block)
        for tx in txs:
            if tx['from'] == self.address and tx['nonce'] == nonce:
                return tx
            # Special handler for contract creation transactions
            elif tx['to'] == None and (await _get_transaction_receipt(tx['hash']))['contractAddress'] == self.address:
                return tx
            # Special handler for Gnosis Safe deployments
            elif tx['to'] == "0xa6B71E26C5e0845f74c812102Ca7114b6a896AB2":
                events = chain.get_transaction(tx['hash']).events
                if "SafeSetup" in events and "ProxyCreation" in events and any(event['proxy'] == self.address for event in events['ProxyCreation']):
                    return tx
                    
        if nonce == 0 and self.cached_thru_nonce == -1:
            # Gnosis safes
            self.cached_thru_nonce = 0
        else:
            # NOTE Are we sure this is the correct way to handle this scenario? Are we sure it will ever even occur with the new gnosis handling?
            logger.warning(f"No transaction with nonce {nonce} in block {block} for {self.address}")
            
        return None
    
    @alru_cache(maxsize=None)
    @eth_retry.auto_retry
    async def _get_nonce_at_block(self, block: Block) -> int:
        try:
            return await dank_w3.eth.get_transaction_count(self.address, block_identifier = block) - 1
        except ValueError as e:
            # NOTE this is known to occur on arbitrum
            if 'error creating execution cursor' in str(e) and block == 0:
                return -1
            raise ValueError(f"For {self.address} at {block}: {e}")

class InternalTransfersList(PandableList[InternalTransfer]):
    pass

trace_semaphore = asyncio.Semaphore(32)

@cache_to_disk
@eth_retry.auto_retry
async def get_traces(params: list) -> List[dict]:
    async with trace_semaphore:
        traces = await dank_w3.provider.make_request("trace_filter", params)
        if 'result' not in traces:
            raise BadResponse(traces)
        return [trace for trace in traces['result'] if "error" not in trace]
    
checksums = {}

def checksum(addr: str) -> str:
    """We keep a mapping here to save cpu cycles, checksumming is arduous."""
    try:
        return checksums[addr]
    except KeyError:
        checksummed = checksums[addr] = to_checksum_address(addr)
        return checksummed    

class AddressInternalTransfersLedger(AddressLedgerBase[InternalTransfersList]):
    list_type = InternalTransfersList
    
    @set_end_block_if_none
    async def _load_new_objects(self, start_block: Block, end_block: Block) -> None:
        if start_block == 0:
            start_block = 1

        try:
            start_block, end_block = self._check_blocks_against_cache(start_block, end_block)
        except BlockRangeIsCached:
            return
        except BlockRangeOutOfBounds:
            await asyncio.gather(
                self._load_new_objects(start_block, self.cached_thru - 1),
                self._load_new_objects(self.cached_from + 1, end_block)
            )
            return

        block_ranges = [[hex(i), hex(i + BATCH_SIZE - 1)] for i in range(start_block, end_block, BATCH_SIZE)]
        
        trace_filter_coros = [
            get_traces([{direction: [self.address],"fromBlock": start, "toBlock": end}])
            for direction, (start, end) in product(["toAddress", "fromAddress"], block_ranges)
        ]

        # NOTE: We only want tqdm progress bar when there is a lot of work to do
        generator_function = partial(tqdm_asyncio.as_completed, desc=f"Trace Filters       {self.address}") if len(block_ranges) > 1 else asyncio.as_completed

        futs = []
        for traces in generator_function(trace_filter_coros):
            futs.extend(asyncio.create_task(self._load_internal_transfer(trace)) for trace in await traces)
                
        if futs:
            transfer: InternalTransfer
            for fut in tqdm_asyncio.as_completed(futs, desc=f"Internal Transfers  {self.address}"):
                transfer = await fut
                if transfer is not None:
                    self.objects.append(transfer)

            self.objects.sort(key=lambda t: (t.block_number, t.transaction_index, t.trace_address, t.subtraces))

        if self.cached_from is None or start_block < self.cached_from:
            self.cached_from = start_block
        if self.cached_thru is None or end_block > self.cached_thru:
            self.cached_thru = end_block
    
    async def _load_internal_transfer(self, transfer) -> Optional[InternalTransfer]:
        receipt = await _get_transaction_receipt(transfer['transactionHash'])
        if receipt.status == 0:
            return None
        del receipt

        # Un-nest the action dict
        if 'action' in transfer and transfer['action'] is not None:
            for k in list(transfer['action'].keys()):
                transfer[k] = transfer['action'].pop(k)
            if transfer['action']:
                raise ValueError(transfer['action'])
            del transfer['action']

        # Un-nest the result dict
        if 'result' in transfer and transfer['result'] is not None:
            for k in list(transfer['result'].keys()):
                transfer[k] = transfer['result'].pop(k)
            if transfer['result']:
                raise ValueError(transfer['result'])
            del transfer['result']
    
        # Checksum the addresses
        if "from" in transfer:
            transfer['from_address'] = checksum(transfer.pop('from'))
        if "to" in transfer:
            transfer['to_address'] = checksum(transfer.pop('to'))
        if "address" in transfer:
            transfer['address'] = checksum(transfer.pop('address'))
            
        transfer['value'] = Decimal(int(transfer['value'], 16)) / Decimal(1e18)
        transfer['gas'] = int(transfer['gas'], 16)
        transfer['gasUsed'] = int(transfer['gasUsed'], 16) if transfer['gasUsed'] else None

        if self.load_prices:
            price = await _get_price(EEE_ADDRESS, transfer['blockNumber'])
            price = round(Decimal(price), 18)
            transfer['price'] = price
            transfer['value_usd'] = round(transfer['value'] * price, 18)
            
        transfer['hash'] = transfer.pop('transactionHash')
        transfer['transaction_index'] = transfer.pop('transactionPosition')
        transfer['chainid'] = chain.id
        
        return InternalTransfer(**{inflection.underscore(k): v for k, v in transfer.items()})


shitcoins = SHITCOINS.get(chain.id, set())

class TokenTransfersList(PandableList[TokenTransfer]):
    pass

async def _get_symbol(token: ERC20) -> Optional[str]:
    try:
        return await token.__symbol__(sync=False)
    except NonStandardERC20:
        return None

async def _decode_token_transfer(log) -> _EventItem:
    try:
        await Contract.coroutine(log.address)
    except ContractNotFound:
        logger.warning(f"Token {log.address} cannot be found. Skipping. If the contract has been self-destructed, eth-portfolio will not support it.")
    except ContractNotVerified:
        logger.warning(f"Token {log.address} is not verified and is most likely a shitcoin. Skipping. Please submit a PR at github.com/BobTheBuidler/eth-portfolio if this is not a shitcoin and should be included.")
        return
    try:
        try:
            event = decode_logs(
                [log]
            )  # NOTE: We have to decode logs here because NFTs prevent us from batch decoding logs
        except Exception as e:
            raise e
        try:
            events = event['Transfer']
        except Exception as e:
            logger.error(event)
            raise e
        try:
            return events[0]
        except Exception as e:
            logger.error(event)
            raise e
    except Exception as e:
        logger.error('unable to decode logs, dev figure out why')
        logger.error(e)
        logger.error(log)

async def _get_transaction_index(hash: str) -> int:
    receipt = await _get_transaction_receipt(hash)
    return receipt.transactionIndex
  
class AddressTokenTransfersLedger(AddressLedgerBase[TokenTransfersList]):
    list_type = TokenTransfersList

    def __init__(self, portfolio_address: "PortfolioAddress"):
        super().__init__(portfolio_address)

        # define transfer signatures for Transfer events from ERC-20 and ERC-677 contracts
        self._topics = [
            [
                TRANSFER_SIGS,
                None,
                [encode_hex(encode_single('address', str(self.address)))] # Transfers into Portfolio wallets
            ],
            [
                TRANSFER_SIGS,
                [encode_hex(encode_single('address', str(self.address)))] # Transfers out of Portfolio wallets
            ]
        ]

    @await_if_sync
    def list_tokens_at_block(self, block: Optional[int] = None) -> List[ERC20]:
        return self._list_tokens_at_block_async(block) # type: ignore
    
    async def _list_tokens_at_block_async(self, block: Optional[int] = None) -> List[ERC20]:
        tokens = {transfer.token_address for transfer in await self._get_async(0, block)}
        return [ERC20(address) for address in tokens]
    
    @set_end_block_if_none
    async def _load_new_objects(self, start_block: Block, end_block: Block) -> None:
        try:
            start_block, end_block = self._check_blocks_against_cache(start_block, end_block)
        except BlockRangeIsCached:
            return
        except BlockRangeOutOfBounds:
            await asyncio.gather(
                self._load_new_objects(start_block, self.cached_thru - 1),
                self._load_new_objects(self.cached_from + 1, end_block)
            )
            return
        
        futs = [fut for futs in await asyncio.gather(*[self._get_tasks(start_block, end_block, topics) for topics in self._topics]) for fut in futs]
        
        if futs:
            transfer: TokenTransfer
            for fut in tqdm_asyncio.as_completed(futs, desc=f"Token Transfers     {self.address}"):
                transfer = await fut
                if transfer is not None:
                    self.objects.append(transfer)
                    
            self.objects.sort(key=lambda t: (t.block_number, t.transaction_index, t.log_index))
            
        if self.cached_from is None or start_block < self.cached_from:
            self.cached_from = start_block
        if self.cached_thru is None or end_block > self.cached_thru:
            self.cached_thru = end_block
    
    async def _get_tasks(self, start_block, end_block, topics) -> List[asyncio.Task]:
        futs = []
        async for logs in get_logs_asap_generator(address=None, from_block=start_block, to_block=end_block, topics=topics, chronological=False):
            futs.extend(asyncio.create_task(self._load_transfer(log)) for log in logs)
        return futs
    
    async def _load_transfer(self, transfer_log) -> Optional[TokenTransfer]:
        if transfer_log.address in shitcoins:
            return None
        async with token_transfer_semaphore[transfer_log["blockNumber"]]:
            decoded = await _decode_token_transfer(transfer_log)
            if decoded is None:
                return None
            token = ERC20(decoded.address, asynchronous=True)
            coros = [
                token.scale,
                _get_symbol(token),
                _get_transaction_index(decoded.transaction_hash)
            ]
            if self.load_prices:
                coros.append(_get_price(token.address, decoded.block_number))
                scale, symbol, transaction_index, price = await asyncio.gather(*coros)
            else:
                scale, symbol, transaction_index = await asyncio.gather(*coros)
            
            sender, receiver, value = decoded.values()
            value = Decimal(value) / Decimal(scale)
            
            token_transfer = {
                'chainid': chain.id,
                'block_number': decoded.block_number,
                'transaction_index': transaction_index,
                'hash': decoded.transaction_hash.hex(),
                'log_index': decoded.log_index,
                'token': symbol,
                'token_address': decoded.address,
                'from_address': sender,
                'to_address': receiver,
                'value': value,
            }
            if self.load_prices:
                try:
                    price = round(Decimal(price), 18) if price else None
                except Exception as e:
                    logger.error(f"{e.__class__.__name__} {e} for {symbol} {decoded.address} at block {decoded.block_number}.")
                    price = None
                token_transfer['price'] = price
                token_transfer['value_usd'] = round(value * price, 18) if price else None
                
            return TokenTransfer(**token_transfer)

