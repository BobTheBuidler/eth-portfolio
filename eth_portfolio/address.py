
import asyncio
import logging
from typing import Dict, List, Literal, Optional, Tuple, Type, Union

from aiohttp import ClientError
from async_lru import alru_cache
from brownie import chain
from brownie.network.event import _EventItem
from eth_abi import encode_single
from eth_utils import encode_hex
from pandas import DataFrame
from web3.types import BlockData, TxData
from y import Contract, convert, get_price_async
from y.classes.common import ERC20
from y.constants import EEE_ADDRESS, weth
from y.datatypes import Address, Block, UsdPrice
from y.exceptions import ContractNotVerified, NonStandardERC20
from y.utils.dank_mids import dank_w3
from y.utils.events import decode_logs

from eth_portfolio.constants import TRANSFER_SIGS
from eth_portfolio.decorators import await_if_sync, set_end_block_if_none
from eth_portfolio.lending import _lending
from eth_portfolio.shitcoins import SHITCOINS
from eth_portfolio.staking import _staking
from eth_portfolio.utils import (Decimal, PandableListOfDicts, _get_price,
                                 _unpack_indicies, get_buffered_chain_height, is_erc721)

logger = logging.getLogger(__name__)

debug_semaphore = asyncio.Semaphore(value=100)


async def _get_eth_balance(address: Address, block: Optional[Block]) -> Decimal:
    return Decimal(await dank_w3.eth.get_balance(address, block_identifier=block)) / Decimal(1e18)


class PortfolioAddress:
    def __init__(self, address: Address, portfolio: "Portfolio") -> None:
        self.address = convert.to_address(address)
        self.portfolio = portfolio
        self.transactions = AddressTransactionsCache(self)
        self.internal_transfers = AddressInternalTransfersCache(self)
        self.token_transfers = AddressTokenTransfersCache(self)

    @property
    def asynchronous(self) -> bool:
        return self.portfolio.asynchronous

    @property
    def load_prices(self) -> bool:
        return self.portfolio.load_prices
    
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

    @await_if_sync
    def assets(self, block: Optional[Block] = None) -> Dict:
        return self._assets_async(block)
    
    async def _assets_async(self, block: Optional[Block] = None) -> Dict:
        balances, collateral = await asyncio.gather(
            self._balances_async(block=block),
            self._collateral_async(block=block),
        )
        balances.update(collateral)
        return balances

    @await_if_sync
    def debt(self, block: Optional[Block] = None) -> Dict:
        return self._debt_async(block)
    
    async def _debt_async(self, block: Optional[Block] = None) -> Dict:
        return await _lending._debt_async(self.address, block=block)

    # Assets

    @await_if_sync
    def balances(self, block: Optional[Block]):
        return self._balances_async(block)
    
    async def _balances_async(self, block: Optional[Block]):
        eth_balance, token_balances = await asyncio.gather(
            self._eth_balance_async(block),
            self._token_balances_async(block),
        )
        balances = token_balances
        balances['ETH'] = eth_balance
        return {token: balance for token, balance in balances.items() if balance['balance'] != 0 and balance['usd value'] != 0}
    
    @await_if_sync
    def eth_balance(self, block: Optional[Block]) -> Dict[Literal["balance", "usd value"], Decimal]:
        return self._eth_balance_async(block)

    async def _eth_balance_async(self, block: Optional[Block]) -> Dict[Literal["balance", "usd value"], Decimal]:
        balance, price = await asyncio.gather(
            _get_eth_balance(self.address, block),
            get_price_async(weth, block),
        )
        return {'balance': balance, 'usd value': balance * Decimal(price)}
    
    @await_if_sync
    def token_balances(self, block: Optional[Block]):
        return self._token_balances_async(block)
    
    async def _token_balances_async(self, block):
        tokens = await self.token_transfers._list_tokens_at_block_async(block=block)
        token_balances, token_prices = await asyncio.gather(
            asyncio.gather(*[token.balance_of_readable_async(self.address, block) for token in tokens]),
            asyncio.gather(*[_get_price(token, block) for token in tokens]),
        )
        token_balances = [
            {'balance': balance, 'usd value': None if price is None else balance * price}
            for balance, price in zip(token_balances, token_prices)
        ]
        return dict(zip(tokens, token_balances))
    
    @await_if_sync
    def collateral(self, block: Optional[Block] = None) -> Dict:
        return self._collateral_async(block)
    
    async def _collateral_async(self, block: Optional[Block] = None) -> Dict:
        return await _lending._collateral_async(self.address, block=block)
    
    @await_if_sync
    def staking(self, block: Optional[Block] = None) -> Dict:
        return self._staking_async(block)
    
    async def _staking_async(self, block: Optional[Block] = None) -> Dict:
        return await _staking._balances_async(self.address, block=block)
    
    # Ledger Entries

    @await_if_sync
    def all(self, load_prices: bool = False) -> None:
        return self._all_async(load_prices=load_prices)
    
    async def _all_async(self, load_prices: bool = False) -> Dict[str, List[Union[TxData, _EventItem]]]:
        transactions, internal_transactions, token_transfers = await asyncio.gather(
            self.transactions._get_async(load_prices=load_prices),
            self.internal_transfers_async(load_prices=load_prices),
            self.token_transfers_async(load_prices=load_prices),
        )
        return {
            "transactions": transactions,
            "internal_transactions": internal_transactions,
            "token_transfers": token_transfers,
        }


class BlockRangeIsCached(Exception):
    pass

class BlockRangeOutOfBounds(Exception):
    pass

class AddressObjectCacheBase:
    list_type: Type[PandableListOfDicts]

    def __init__(self, portfolio_address: PortfolioAddress) -> None:
        assert hasattr(self.__class__, 'list_type'), f"{self.__class__.__name__} must have a list_type attribute."
        assert hasattr(self, 'list_type'), f"{self.__class__.__name__} must have a list_type attribute."
        assert isinstance(portfolio_address, PortfolioAddress), f"address must be a PortfolioAddress. try passing in PortfolioAddress({portfolio_address}) instead."

        self.portfolio_address = portfolio_address
        self.objects = []
        self.cached_from = None
        self.cached_thru = None
    
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
    def portfolio(self) -> "Portfolio":
        return self.portfolio_address.portfolio
    
    def __getitem__(self, indicies: Union[Block,Tuple[Block,Block]]) -> PandableListOfDicts:
        start_block, end_block = _unpack_indicies(indicies)
        if asyncio.get_event_loop().is_running():
            return self._get_async(start_block, end_block)
        return self.get(start_block, end_block)
    
    @await_if_sync
    def get(self, start_block: Block, end_block: Block) -> PandableListOfDicts:
        return self._get_async(start_block, end_block)
    
    @set_end_block_if_none
    async def _get_async(self, start_block: Block, end_block: Block) -> PandableListOfDicts:
        await self._load_new_objects(start_block, end_block)
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
    def new(self) -> PandableListOfDicts:
        return self._new_async()
    
    async def _new_async(self) -> PandableListOfDicts:
        start_block = 0 if self.cached_thru is None else self.cached_thru + 1
        end_block = await get_buffered_chain_height()
        return self[start_block, end_block]
    
    @set_end_block_if_none
    async def _load_new_objects(self, start_block: Block, end_block: Block) -> None:
        raise NotImplementedError()
    
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
    

async def _get_block(block: Block) -> BlockData:
    while True:
        try:
            return await dank_w3.eth.get_block(block, full_transactions=True)
        except ClientError:
            pass

class TransactionsList(PandableListOfDicts):
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

class AddressTransactionsCache(AddressObjectCacheBase):
    list_type = TransactionsList

    def __init__(self, portfolio_address: PortfolioAddress):
        super().__init__(portfolio_address)
        self.cached_thru_nonce = -1

    @set_end_block_if_none
    async def _load_new_objects(self, _: Block, end_block: Block) -> None:
        if end_block is None:
            end_block = await get_buffered_chain_height()
        if self.cached_thru and end_block < self.cached_thru:
            return
        end_block_nonce = await self._get_nonce_at_block(end_block)
        nonces = range(self.cached_thru_nonce + 1, end_block_nonce + 1)
        new_transactions = await asyncio.gather(*[self._get_transaction_by_nonce(nonce, end_block) for nonce in nonces])
        for i, transaction in enumerate(new_transactions):
            transaction = dict(transaction)
            transaction['chainId'] = int(transaction['chainId'], 16)
            transaction['blockHash'] = transaction['blockHash'].hex()
            transaction['hash'] = transaction['hash'].hex()
            transaction['value'] = Decimal(transaction['value']) / Decimal(1e18)
            transaction['type'] = int(transaction['type'], 16)
            transaction['r'] = transaction['r'].hex()
            transaction['s'] = transaction['s'].hex()
            new_transactions[i] = transaction

        if self.load_prices:
            prices = await asyncio.gather(*[get_price_async(EEE_ADDRESS, block = transaction['blockNumber']) for transaction in new_transactions])
            for transaction, price in zip(new_transactions, prices):
                price = round(Decimal(price), 18)
                transaction['price'] = price
                transaction['value_usd'] = transaction['value'] * price
            
        for transaction in new_transactions:
            self.objects.append(transaction)
            self.cached_thru_nonce = transaction['nonce']
        
        if self.cached_from is None:
            self.cached_from = 0
        if self.cached_thru is None:
            self.cached_thru = end_block
        elif end_block > self.cached_thru:
            self.cached_thru = end_block

    async def _get_transaction_by_nonce(self, nonce: int, height: Block) -> TxData:
        lo = 0
        hi = height
        while True:
            _nonce = await self._get_nonce_at_block(lo)
            if _nonce < nonce:
                old_lo = lo
                lo += int((hi - lo) / 2) or 1
                logger.debug(f"Nonce at {old_lo} is {_nonce}, checking higher block {lo}")
            elif _nonce >= nonce:
                prev_block_nonce = await self._get_nonce_at_block(lo - 1)
                if prev_block_nonce < nonce:
                    logger.debug(f"Found nonce {nonce} at block {lo}")
                    return dict(await self._get_transaction_by_nonce_and_block(nonce, lo))
                hi = lo
                lo = int(lo / 2)
                logger.debug(f"Nonce at {hi} is {_nonce}, checking lower block {lo}")
    
    async def _get_transaction_by_nonce_and_block(self, nonce: int, block: Block) -> TxData:
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
    async def _get_nonce_at_block(self, block: Block) -> int:
        while True:
            try:
                return await dank_w3.eth.get_transaction_count(self.address, block_identifier = block) - 1
            except ClientError:
                pass


class InternalTransfersList(PandableListOfDicts):
    def __init__(self):
        super().__init__()
    
    def _df(self) -> DataFrame:
        df = DataFrame(self)
        if len(df) > 0:
            df['chainId'] = chain.id
        return df

class AddressInternalTransfersCache(AddressObjectCacheBase):
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
        
        to_traces, from_traces = await asyncio.gather(
            dank_w3.provider.make_request('trace_filter', [{"toAddress": [self.address],"fromBlock": hex(start_block), "toBlock": hex(end_block)}]),
            dank_w3.provider.make_request('trace_filter', [{"fromAddress": [self.address],"fromBlock": hex(start_block), "toBlock": hex(end_block)}]),
        )
        to_traces = to_traces['result'] if "result" in to_traces else []
        from_traces = from_traces['result'] if "result" in from_traces else []

        new_internal_transfers = [transfer for transfer in to_traces + from_traces if 'error' not in transfer or transfer['error'] != "Reverted"]
        
        for transfer in new_internal_transfers:
            # Un-nest the action dict
            if 'action' in transfer and transfer['action'] is not None:
                for k in list(transfer['action'].keys()):
                    assert k not in transfer
                    transfer[k] = transfer['action'][k]
                    del transfer['action'][k]
                if transfer['action']:
                    raise ValueError(transfer['action'])
                del transfer['action']

            # Un-nest the result dict
            if 'result' in transfer and transfer['result'] is not None:
                for k in list(transfer['result'].keys()):
                    assert k not in transfer
                    transfer[k] = transfer['result'][k]
                    del transfer['result'][k]
                if transfer['result']:
                    raise ValueError(transfer['result'])
                del transfer['result']
        
            transfer['value'] = Decimal(int(transfer['value'], 16)) / Decimal(1e18)
            transfer['gas'] = int(transfer['gas'], 16)
            transfer['gasUsed'] = int(transfer['gasUsed'], 16) if transfer['gasUsed'] else None

        if self.load_prices:
            prices = await asyncio.gather(*[get_price_async(EEE_ADDRESS, transfer['blockNumber']) for transfer in new_internal_transfers])
            for transfer, price in zip(new_internal_transfers, prices):
                price = round(Decimal(price), 18)
                transfer['price'] = price
                transfer['value_usd'] = round(transfer['value'] * price, 18)

        self.objects.extend(new_internal_transfers)
        self.objects.sort(key=lambda x: (x['blockNumber'], x['transactionPosition'], x['traceAddress'], x['subtraces']))

        if self.cached_from is None or start_block < self.cached_from:
            self.cached_from = start_block
        if self.cached_thru is None or end_block > self.cached_thru:
            self.cached_thru = end_block


shitcoins = SHITCOINS.get(chain.id, [])

class TokenTransfersList(PandableListOfDicts):
    def __init__(self):
        super().__init__()
    
    def _df(self) -> DataFrame:
        return DataFrame(self)

async def _get_symbol(token) -> str:
    try:
        return await ERC20(token).symbol_async
    except NonStandardERC20:
        return None

async def _get_price(token, block) -> UsdPrice:
    if await is_erc721(token):
        return None
    try:
        return await get_price_async(token, block, fail_to_None=True)
    except Exception as e:
        logger.error(f"{type(e).__name__} when fetching price for {token} at block {block}")
        logger.error(e)
        return None
class AddressTokenTransfersCache(AddressObjectCacheBase):
    list_type = TokenTransfersList

    def __init__(self, portfolio_address: PortfolioAddress):
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
        return self._list_tokens_at_block_async(block)
    
    async def _list_tokens_at_block_async(self, block: Optional[int] = None) -> List[ERC20]:
        return list({ERC20(transfer['token_address']) for transfer in await self._get_async(0, block)})
    
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
        
        transfer_filters = [
            self.portfolio.w3.eth.filter({"fromBlock": start_block, "toBlock": end_block, "topics": topics})
            for topics in self._topics
        ]

        new_token_transfers = [tx for transfer_filter in transfer_filters for tx in self._decode_token_transfers(transfer_filter.get_all_entries())]

        scales_coros = asyncio.gather(*[ERC20(token_transfer.address).scale for token_transfer in new_token_transfers])
        symbols_coros = asyncio.gather(*[_get_symbol(token_transfer.address) for token_transfer in new_token_transfers])
        receipts_coros = asyncio.gather(*[dank_w3.eth.get_transaction_receipt(token_transfer.transaction_hash) for token_transfer in new_token_transfers])
        if self.load_prices:
            prices_coros = asyncio.gather(*[_get_price(token_transfer.address, token_transfer.block_number) for token_transfer in new_token_transfers])
            scales, symbols, receipts, prices = await asyncio.gather(scales_coros, symbols_coros, receipts_coros, prices_coros)
        else:
            scales, symbols, receipts = await asyncio.gather(scales_coros, symbols_coros, receipts_coros)

        for i, token_transfer in enumerate(new_token_transfers):
            sender, receiver, value = token_transfer.values()
            amount = Decimal(value) / Decimal(scales[i])
            token_transfer = {
                'chainId': chain.id,
                'blockNumber': token_transfer.block_number,
                'transactionIndex': receipts[i].transactionIndex,
                'hash': token_transfer.transaction_hash.hex(),
                'log_index': token_transfer.log_index,
                'token': symbols[i],
                'token_address': token_transfer.address,
                'from': sender,
                'to': receiver,
                'value': amount,
            }
            if self.load_prices:
                price = round(Decimal(prices[i]), 18) if prices[i] else None
                token_transfer['price'] = price
                token_transfer['value_usd'] = round(Decimal(value) * price, 18) if price else None
            new_token_transfers[i] = token_transfer
        
        self.objects.extend(new_token_transfers)
        self.objects.sort(key=lambda x: (x["blockNumber"], x['transactionIndex'], x['log_index']))
        if self.cached_from is None or start_block < self.cached_from:
            self.cached_from = start_block
        if self.cached_thru is None or end_block > self.cached_thru:
            self.cached_thru = end_block


    def _decode_token_transfers(self, logs: List) -> List[_EventItem]:
        token_transfers = []
        for log in logs:
            if log.address in shitcoins:
                continue
            try:
                Contract(log.address)
            except ContractNotVerified:
                logger.warning(f"Token {log.address} is not verified and is most likely a shitcoin. Skipping. Please submit a PR at github.com/BobTheBuidler/eth-portfolio if this is not a shitcoin and should be included.")
                continue
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
                    token_transfers.append(events[0])
                except Exception as e:
                    logger.error(event)
                    raise e
            except Exception as e:
                logger.error('unable to decode logs, dev figure out why')
                logger.error(e)
                logger.error(log)
        return token_transfers
