
import asyncio
import logging
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from typing import AsyncIterator, Dict, List, Literal, Optional, Union

from aiohttp import ClientError
from async_lru import alru_cache
from async_property import async_property
from brownie import chain
from brownie.network.event import _EventItem
from eth_abi import encode_single
from eth_utils import encode_hex
from multicall.utils import await_awaitable
from tqdm.asyncio import tqdm_asyncio
from web3.types import BlockData, TxData
from y import Contract, convert, get_price_async
from y.classes.common import ERC20
from y.constants import EEE_ADDRESS, weth
from y.datatypes import Address, Block
from y.exceptions import ContractNotVerified
from y.utils.dank_mids import dank_w3
from y.utils.events import decode_logs

from eth_portfolio.constants import TRANSFER_SIGS
from eth_portfolio.decorators import sentry_catch_all, wait_or_exit_after
from eth_portfolio.lending import lending
from eth_portfolio.shitcoins import SHITCOINS
from eth_portfolio.utils import Decimal, _get_price

logger = logging.getLogger(__name__)

debug_semaphore = asyncio.Semaphore(value=100)

threadpool = ThreadPoolExecutor(max_workers=128)


async def _get_eth_balance(address: Address, block: Optional[Block]) -> Decimal:
    if block:
        return Decimal(await dank_w3.eth.get_balance(address, block_identifier=block)) / Decimal(1e18)
    else:
        return Decimal(await dank_w3.eth.get_balance(address)) / Decimal(1e18)

async def _get_block(block: Block) -> BlockData:
    while True:
        try:
            return await dank_w3.eth.get_block(block, full_transactions=True)
        except ClientError:
            pass


class PortfolioAddress:
    def __init__(self, address: Address, portfolio: "Portfolio", watch_events_forever: bool = False) -> None:
        self.address = convert.to_address(address)
        self.portfolio = portfolio
        self._transactions: List[TxData] = []
        self._token_transfers: List[_EventItem] = []
        self.watch_events_forever = watch_events_forever

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

        self._done = threading.Event()
        self._has_exception = False
        self._thread = threading.Thread(target=self.watch_token_transfers, daemon=True)
    
    def __str__(self) -> str:
        return self.address

    def __repr__(self) -> str:
        return f"<PortfolioAddress: {self.address}>"
    
    def __eq__(self, other: object) -> bool:
        if isinstance(other, PortfolioAddress):
            return self.address == other.address
        elif isinstance(other, str):
            return self.address == convert.to_address(other)
        return False
    
    def __hash__(self) -> int:
        return hash(self.address)
    
    # Primary functions

    def assets(self, block: Optional[Block] = None) -> Dict:
        coro = self.assets_async(block)
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def assets_async(self, block: Optional[Block] = None) -> Dict:
        balances, collateral = await asyncio.gather(
            self.balances_async(block=block),
            self.collateral_async(block=block),
        )
        balances.update(collateral)
        return balances

    def debt(self, block: Optional[Block] = None) -> Dict:
        coro = self.debt_async(block)
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def debt_async(self, block: Optional[Block] = None) -> Dict:
        return await lending.debt_async(self.address, block=block)

    # Assets

    def balances(self, block: Optional[Block]):
        return await_awaitable(self.balances_async(block))
    
    async def balances_async(self, block: Optional[Block]):
        eth_balance, token_balances = await asyncio.gather(
            self.eth_balance_async(block),
            self.token_balances_async(block),
        )
        balances = token_balances
        balances['ETH'] = eth_balance
        return {token: balance for token, balance in balances.items() if balance['balance'] != 0 and balance['usd value'] != 0}
    
    def eth_balance(self, block: Optional[Block]) -> Dict[Literal["balance", "usd value"], Decimal]:
        return await_awaitable(self.eth_balance_async(block))

    async def eth_balance_async(self, block: Optional[Block]) -> Dict[Literal["balance", "usd value"], Decimal]:
        balance, price = await asyncio.gather(
            _get_eth_balance(self.address, block),
            get_price_async(weth, block),
        )
        return {'balance': balance, 'usd value': balance * Decimal(price)}
    
    def token_balances(self, block: Optional[Block]):
        return await_awaitable(self.token_balances_async(block))
    
    async def token_balances_async(self, block):
        tokens = await self.list_tokens_at_block_async(block=block)
        token_balances, token_prices = await asyncio.gather(
            asyncio.gather(*[token.balance_of_readable_async(self.address, block) for token in tokens]),
            asyncio.gather(*[_get_price(token, block) for token in tokens]),
        )
        token_balances = [
            {'balance': balance, 'usd value': balance * price}
            for balance, price in zip(token_balances, token_prices)
        ]
        return dict(zip(tokens, token_balances))
    
    def collateral(self, block: Optional[Block] = None) -> Dict:
        coro = self.collateral_async(block)
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def collateral_async(self, block: Optional[Block] = None) -> Dict:
        return await lending.collateral_async(self.address, block=block)
    
    # ETH Transactions

    @property
    def transactions(self) -> List[TxData]:
        coro = self.transactions_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    @async_property
    async def transactions_async(self) -> List[TxData]:
        if not self._transactions:
            # TODO keep transactions updated in background
            await self.load_transactions()
        return self._transactions

    async def load_transactions(self) -> None:
        height = chain.height
        current_nonce = await self.get_nonce_at_block(height)
        nonces = range(current_nonce + 1)
        self._transactions = await tqdm_asyncio.gather(*[self.get_transaction_by_nonce(nonce, height) for nonce in nonces])
        prices = await asyncio.gather(*[get_price_async(EEE_ADDRESS, block = transaction['blockNumber']) for transaction in self._transactions])
        for transaction, price in zip(self._transactions, prices):
            #transaction['price'] = Decimal(price)
            #transaction['value_usd'] = Decimal(transaction['value']) * Decimal(price)
            pass
        return None

    async def get_transaction_by_nonce(self, nonce: int, height: Block) -> TxData:
        lo = 0
        hi = height
        while True:
            _nonce = await self.get_nonce_at_block(lo)
            if _nonce < nonce:
                old_lo = lo
                lo += int((hi - lo) / 2) or 1
                logger.debug(f"Nonce at {old_lo} is {_nonce}, checking higher block {lo}")
            elif _nonce >= nonce:
                prev_block_nonce = await self.get_nonce_at_block(lo - 1)
                if prev_block_nonce < nonce:
                    logger.debug(f"Found nonce {nonce} at block {lo}")
                    return await self.get_transaction_by_nonce_and_block(nonce, lo)
                hi = lo
                lo = int(lo / 2)
                logger.debug(f"Nonce at {hi} is {_nonce}, checking lower block {lo}")
    
    async def get_transaction_by_nonce_and_block(self, nonce: int, block: Block) -> TxData:
        block = await _get_block(block)
        for tx in block.transactions:
            if tx['from'] == self.address and tx['nonce'] == nonce:
                return tx
            # Special handler for contract creation transactions
            elif tx['to'] == None and chain.get_transaction(tx['hash']).contract_address == self.address:
                return tx
            # Special handler for Gnosis Safe deployments
            elif tx['to'] == "0xa6B71E26C5e0845f74c812102Ca7114b6a896AB2":
                events = chain.get_transaction(tx['hash']).events
                if "SafeSetup" in events and "ProxyCreation" in events and any(event['proxy'] == self.address for event in events['ProxyCreation']):
                    return tx
        raise ValueError(f"No transaction with nonce {nonce} in block {block.number}")
    
    @alru_cache(maxsize=None)
    async def get_nonce_at_block(self, block: Block) -> int:
        while True:
            try:
                return await dank_w3.eth.get_transaction_count(self.address, block_identifier = block) - 1
            except ClientError:
                pass
    
    # Internal Transactions
    
    @property
    def internal_transfers(self):
        coro = self.internal_transfers_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    @async_property
    async def internal_transfers_async(self):
        to_traces, from_traces = await asyncio.gather(
            dank_w3.provider.make_request('trace_filter', [{"toAddress": [self.address],"fromBlock": "0x1", "toBlock": '0xe861a3'}]),
            dank_w3.provider.make_request('trace_filter', [{"fromAddress": [self.address],"fromBlock": "0x1", "toBlock": '0xe861a3'}]),
        )

        internal_transfers: List = to_traces['result'] + from_traces['result']
        internal_transfers.sort(key=lambda x: (x['blockNumber'], x['transactionPosition']))

        # Un-nest the dicts
        for transfer in internal_transfers:
            if 'action' in transfer and transfer['action'] is not None:
                for k in list(transfer['action'].keys()):
                    assert k not in transfer
                    transfer[k] = transfer['action'][k]
                    del transfer['action'][k]
                if transfer['action']:
                    raise ValueError(transfer['action'])
                del transfer['action']

            if 'result' in transfer and transfer['result'] is not None:
                for k in list(transfer['result'].keys()):
                    assert k not in transfer
                    transfer[k] = transfer['result'][k]
                    del transfer['result'][k]
                if transfer['result']:
                    raise ValueError(transfer['result'])
                del transfer['result']
        
        prices = await asyncio.gather(*[get_price_async(EEE_ADDRESS, transfer['blockNumber']) for transfer in internal_transfers])
        for transfer, price in zip(internal_transfers, prices):
            value = Decimal(int(transfer['value'], 16)) / Decimal(1e18)
            price = round(Decimal(price), 18)
            transfer['value'] = value
            transfer['price'] = price
            transfer['value_usd'] = round(value * price, 18)

        return internal_transfers
    
    async def _get_relevant_blocks_from_batch(self, batch: List[Block]) -> List[Block]:
        relevant_blocks = await asyncio.gather(*[self._check_if_block_range_contains_internal_transactions([block]) for block in batch])
        return [block for block, is_relevant in zip(batch, relevant_blocks) if is_relevant]

    async def _check_if_block_range_contains_internal_transactions(self, blocks: List[Block]) -> List[Block]:
        start = blocks[0]
        stop = blocks[-1]
        async with debug_semaphore:
            while True:
                try:
                    if self.address.lower() in await dank_w3.manager.coro_request("debug_getModifiedAccountsByNumber", [start, stop]):
                        return blocks
                    else:
                        return []
                except ClientError:
                    pass
    
    async def _internal_transfer_blocks(self) -> AsyncIterator[Block]:
        blocks = list(range(self.portfolio._start_block, chain.height))
        batches = [blocks[i:i+100] for i in range(0, len(blocks), 100)]
        for blocks in tqdm_asyncio.as_completed([self._check_if_block_range_contains_internal_transactions(batch) for batch in batches], timeout=600):
            blocks = await blocks
            _batches = [blocks[i:i+10] for i in range(0, len(blocks), 10)]
            for _blocks in asyncio.as_completed([self._check_if_block_range_contains_internal_transactions(_batch) for _batch in _batches], timeout=600):
                for block in asyncio.as_completed([self._check_if_block_range_contains_internal_transactions([block]) for block in await _blocks], timeout=600):
                    block = await block
                    if block:
                        yield block[0]
    
    # Token Transfers

    @property
    def token_transfers(self) -> List[_EventItem]:
        coro = self.token_transfers_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    @async_property
    async def token_transfers_async(self) -> List[_EventItem]:
        self.load_token_transfers()
        return self._token_transfers
    
    @property
    def all(self) -> None:
        coro = self.all_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    @async_property
    async def all_async(self) -> Dict[str, List[Union[TxData, _EventItem]]]:
        transactions, internal_transactions, token_transfers = await asyncio.gather(
            self.transactions_async,
            self.internal_transfers_async,
            self.token_transfers_async,
        )
        return {
            "transactions": transactions,
            "internal_transactions": internal_transactions,
            "token_transfers": token_transfers,
        }

    # Background thread

    @wait_or_exit_after
    def load_token_transfers(self) -> None:
        if not self._thread._started.is_set():
            self._thread.start()
    
    @sentry_catch_all
    def watch_token_transfers(self) -> None:
        start = time.time()
        logger.info(
            f'pulling {self.address} transfer events, please wait patiently this takes a while...'
        )
        transfer_filters = [
            self.portfolio.w3.eth.filter({"fromBlock": self.portfolio._start_block, "topics": topics})
            for topics in self._topics
        ]

        transfer_logs = [transfer_filter.get_all_entries() for transfer_filter in transfer_filters]

        while True:
            for logs in transfer_logs:
                self.import_token_transfers(logs)

            if not self._done.is_set():
                self._done.set()
                logger.info(f"loaded {len(self._token_transfers)} ERC20 transfer events for {self.address} in {time.time() - start}")
            if not self.watch_events_forever:
                return

            time.sleep(15)

            # read new logs at end of loop
            transfer_logs = [transfer_filter.get_new_entries() for transfer_filter in transfer_filters]
    
    def import_token_transfers(self, logs: List) -> None:
        shitcoins = SHITCOINS.get(chain.id, [])
        for log in logs:
            if log.address in shitcoins:
                continue
            #if log.address in NFTS or log.address in SKIP_LOGS:
            #    continue
            try:
                Contract(log.address)
            except ContractNotVerified:
                logger.warning(f"Token {log.address} is not verified and is most likely a shitcoin. Skipping. Please submit a PR at github.com/BobTheBuidler/eth-portfolio if this is not a shitcoin and should be included.")
            try:
                try:
                    event = decode_logs(
                        [log]
                    )  # NOTE: We have to decode logs here because NFTs prevent us from batch decoding logs
                except Exception as e:
                    logger.warning('reach')
                    raise e
                try:
                    self._token_transfers.append(event['Transfer'][0])
                except Exception as e:
                    logger.error(event)
                    raise e
            except Exception as e:
                logger.error('unable to decode logs, dev figure out why')
                logger.error(e)
                logger.error(log)

    def list_tokens_at_block(self, block: Optional[int] = None) -> List[ERC20]:
        coro = self.list_tokens_at_block_async(block)
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def list_tokens_at_block_async(self, block: Optional[int] = None) -> List[ERC20]:
        if block is None:
            return list({ERC20(transfer.address) for transfer in await self.token_transfers_async})
        else:
            return list({ERC20(transfer.address) for transfer in await self.token_transfers_async if transfer.block_number <= block})
