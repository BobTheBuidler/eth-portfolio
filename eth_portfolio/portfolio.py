import asyncio
import logging
from functools import cached_property
from typing import Dict, Iterable, List, Optional, Union

from async_property import async_property
from brownie import chain, web3
from brownie.network.event import EventDict, _EventItem
from eth_abi import encode_single
from multicall.utils import await_awaitable, gather
from pandas import DataFrame, concat
from tqdm.asyncio import tqdm_asyncio
from web3 import Web3
from web3.types import TxData
from y import Contract, Network, get_price_async
from y.classes.common import ERC20
from y.datatypes import Address, Block, UsdPrice
from y.exceptions import PriceError

from eth_portfolio.address import PortfolioAddress
from eth_portfolio.constants import ADDRESSES
from eth_portfolio.typing import PortfolioBalanceDetails
from eth_portfolio.utils import Decimal, get_token_from_event

logger = logging.getLogger(__name__)

Addresses = Union[Address, Iterable[Address]]

class Portfolio:
    '''
    Used to export financial reports
    '''

    def __init__(
        self,
        addresses: Addresses,
        start_block: int = 0,
        watch_events_forever: bool = False,
        label: str = "your portfolio",
        asynchronous: bool = False
    ) -> None:
        assert isinstance(addresses, Iterable), f"`addresses` must be an iterable, not {type(addresses)}"
        self.addresses = {PortfolioAddress(addresses, self)} if isinstance(addresses, str) else {PortfolioAddress(address, self) for address in addresses}
        assert isinstance(start_block, int), f"`start_block` must be an integer, not {type(start_block)}"
        assert start_block >= 0, "`start_block` must be >= 0"
        self._start_block = start_block
        assert isinstance(label, str), f"`label` must be a string, you passed {type(label)}"
        self.label = label
        assert isinstance(asynchronous, bool), f"`asynchronous` must be a boolean, you passed {type(asynchronous)}"
        self.asynchronous = asynchronous
        self.w3: Web3 = web3
        self.ledger = Ledger(
            portfolio = self,
            watch_events_forever = watch_events_forever,
        )
    
    @cached_property
    def chain_id(self) -> int:
        return self.w3.eth.chainId

    # descriptive functions
    # assets

    def assets(self, block: int = None) -> PortfolioBalanceDetails:
        coro = self.assets_async(block=block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def assets_async(self, block: int = None) -> PortfolioBalanceDetails:
        assets = await gather([address.assets_async(block=block) for address in self.addresses])
        return {address: data for address, data in zip(self.addresses, assets)}

    def held_assets(self, block: int = None) -> PortfolioBalanceDetails:
        coro = self.held_assets_async(block=block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def held_assets_async(self, block: int = None) -> PortfolioBalanceDetails:
        assets = await gather(address.balances_async(block=block) for address in self.addresses)
        return {address: data for address, data in zip(self.addresses, assets)}

    def collateral(self, block: int = None) -> PortfolioBalanceDetails:
        coro = self.collateral_async(block=block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def collateral_async(self, block: int = None) -> PortfolioBalanceDetails:
        collateral = {}

        maker_collateral, unit_collateral = await gather([
            self.maker_collateral_async(block=block),
            self.unit_collateral_async(block=block)
        ])

        if maker_collateral:
            for address, data in maker_collateral.items():
                collateral[f'{address} Maker CDP'] = data

        if unit_collateral:
            for address, data in unit_collateral.items():
                collateral[f'{address} Unit CDP'] = data

        collateral = {key: value for key, value in collateral.items() if len(value)}
        return collateral

    
    def maker_collateral(self, block: int = None) -> Optional[PortfolioBalanceDetails]:
        coro = self.maker_collateral_async(block=block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def maker_collateral_async(self, block: int = None) -> Optional[PortfolioBalanceDetails]:
        if self.chain_id != Network.Mainnet:
            return None
        proxy_registry = Contract('0x4678f0a6958e4D2Bc4F1BAF7Bc52E8F3564f3fE4')
        cdp_manager = Contract('0x5ef30b9986345249bc32d8928B7ee64DE9435E39')
        vat = Contract('0x35D1b3F3D7966A1DFe207aa4514C12a259A0492B')
        yfi = "0x0bc529c00C6401aEF6D220BE8C6Ea1667F6Ad93e"
        ilk = encode_single('bytes32', b'YFI-A')
        collateral = {}
        for address in self.addresses:
            proxy = await proxy_registry.proxies.coroutine(address)
            cdp = await cdp_manager.first.coroutine(proxy)
            urn = await cdp_manager.urns.coroutine(cdp)
            ink = (await vat.urns.coroutine(ilk, urn, block_identifier=block)).dict()["ink"]
            if ink:
                collateral[address] = {
                    yfi: {
                        'balance': ink / 1e18,
                        'usd value': ink / 1e18 * await get_price_async(yfi, block) if ink > 0 else 0,
                    }
                }
        return collateral
    '''
    '''
    def unit_collateral(self, block: int = None) -> Optional[PortfolioBalanceDetails]:
        coro = self.unit_collateral_async(block=block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def unit_collateral_async(self, block: int = None) -> Optional[PortfolioBalanceDetails]:
        if self.chain_id != Network.Mainnet:
            return None
        if block and block < 11315910:
            return None
        
        # NOTE: This only works for YFI collateral, must extend before using for other collaterals
        unitVault = Contract("0xb1cff81b9305166ff1efc49a129ad2afcd7bcf19")
        yfi = "0x0bc529c00C6401aEF6D220BE8C6Ea1667F6Ad93e"
        collateral = {}
        
        for address in self.addresses:
            bal = await unitVault.collaterals.coroutine(yfi, address, block_identifier=block)
            if bal:
                collateral[address] = {
                    yfi: {
                        'balance': bal / 1e18,
                        'usd value': bal / 1e18 * await get_price_async(yfi, block),
                    }
                }
        return collateral
    
    # descriptive functions
    # debt

    def debt(self, block: int = None) -> PortfolioBalanceDetails:
        coro = self.debt_async(block=block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def debt_async(self, block: int = None) -> PortfolioBalanceDetails:
        debt = await gather([address.debt_async(block=block) for address in self.addresses])
        return {address: data for address, data in zip(self.addresses, debt)}

    # export functions
    def describe(self, block: int) -> dict:
        return await_awaitable(self.describe_async(block))
    
    async def describe_async(self, block: int) -> Dict[str, Dict]:
        assert block
        assets, debt = await gather([self.assets_async(block), self.debt_async(block)])
        return {'assets': assets, 'debt': debt}



class Ledger:
    """
    Stores a ledger of all transactions for a ``Portfolio`` object, along with information about them .
    """
    def __init__(self, portfolio: Portfolio, watch_events_forever: bool = False) -> None:
        self.portfolio = portfolio
        self.max_block = self.portfolio._start_block - 1
        assert isinstance(watch_events_forever, bool), f"`watch_events_forever` must be a boolean, not {type(watch_events_forever)}"
        self.watch_events_forever = watch_events_forever
        self.w3: Web3 = web3

        self._token_transfers = []
    
    # Transactions
    
    @property
    def transactions(self) -> Dict[PortfolioAddress, List[TxData]]:
        coro = self.transactions_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    @async_property
    async def transactions_async(self) -> Dict[PortfolioAddress, List[TxData]]:
        txs = await asyncio.gather(*[address.transactions_async for address in self.portfolio.addresses])
        return {address: txs for address, txs in zip(self.portfolio.addresses, txs)}
    
    # Internal Transactions

    @property
    def internal_transfers(self) -> Dict[PortfolioAddress, List]:
        coro = self.internal_transfers_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    @async_property
    async def internal_transfers_async(self) -> Dict[PortfolioAddress, List]:
        int_txs = await asyncio.gather(*[address.internal_transfers_async for address in self.portfolio.addresses])
        return {address: int_txs for address, int_txs in zip(self.portfolio.addresses, int_txs)}
    
    # Token Transfers

    @property
    def token_transfers(self) -> Dict[PortfolioAddress, List[EventDict]]:
        coro = self.token_transfers_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    @async_property
    async def token_transfers_async(self) -> Dict[PortfolioAddress, List[EventDict]]:
        token_transfers = await asyncio.gather(*[address.token_transfers_async for address in self.portfolio.addresses])
        return {address: transfers for address, transfers in zip(self.portfolio.addresses, token_transfers)}

    # All Ledger entries
    
    @property
    def all_transactions(self) -> Dict:
        coro = self.all_entries_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    @async_property
    async def all_entries_async(self) -> Dict[PortfolioAddress, Dict[str, List[Union[TxData, _EventItem]]]]:
        all_transactions = await asyncio.gather(*[address.all_async for address in self.portfolio.addresses])
        return {address: data for address, data in zip(self.portfolio.addresses, all_transactions)}

    def __getitem__(self, block: Block) -> Dict:
        assert isinstance(block, int), f"You must pass an integer block number, not {block}"
        assert block >= self.portfolio._start_block, f"Input block must be greater than `self.start_block`, {self.portfolio._start_block}"
    
    # Pandas

    def df(self, full: bool = False) -> DataFrame:
        coro = self.df_async(full=full)
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def df_async(self, full: bool = False) -> DataFrame:
        df = concat(
            await asyncio.gather(
                self.transactions_df_async,
                self.internal_transfers_df_async,
                self.token_transfers_df_async,
            )
        )
        
        # Reorder columns
        if full:
            df = df[[
                'chainId',
                'blockHash',
                'transactionIndex',
                'hash',
                'log_index',
                'nonce',
                'from',
                'to',
                'token',
                'value',
                'price',
                'value_usd',
                'gas',
                'gasPrice',
                'gasUsed',
                'maxFeePerGas',
                'maxPriorityFeePerGas',
                'type',
                'callType',
                'traceAddress',
                'subtraces',
                'output',
                'error',
                'result',
                'address',
                'code',
                'init',
                'r',
                's',
                'v',
                'input'
            ]]
        else:
            df = df[[
                'chainId',
                'hash',
                'from',
                'to',
                'token',
                'value',
                'price',
                'value_usd',
                'gas',
                'gasPrice',
                'gasUsed',
                'maxFeePerGas',
                'maxPriorityFeePerGas',
                'type',
                'callType',
                'traceAddress',
                'subtraces',
                'output',
                'error',
                'result',
                'address',
            ]]
            df = df[df['value'] != 0]
        df.sort_index(inplace=True)


        logger.critical(df)
        logger.critical(df.columns)
        logger.critical(df.dtypes)
        return df

    @property
    def transactions_df(self) -> DataFrame:
        coro = self.transactions_df_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)

    @async_property
    async def transactions_df_async(self) -> DataFrame: 
        transactions = await self.transactions_async
        transactions = {address: DataFrame(data) for address, data in transactions.items()}
        transactions = concat(transactions.values())
        transactions.chainId = transactions.chainId.apply(lambda x: int(x, 16))
        transactions.chainId = transactions.chainId.apply(int)
        transactions.blockNumber = transactions.blockNumber.apply(int)
        transactions.blockHash = transactions.blockHash.apply(lambda x: x.hex())
        transactions.transactionIndex = transactions.transactionIndex.apply(int)
        transactions.hash = transactions.hash.apply(lambda x: x.hex())
        transactions.nonce = transactions.nonce.apply(int)
        transactions.gas = transactions.gas.apply(int)
        transactions.gasPrice = transactions.gasPrice.apply(int)
        transactions.r = transactions.r.apply(lambda x: x.hex())
        transactions.s = transactions.s.apply(lambda x: x.hex())
        transactions.type = transactions.type.apply(lambda x: int(x, 16))
        transactions.set_index('blockNumber', inplace=True)
        return transactions
    
    @property
    def internal_transfers_df(self) -> DataFrame:
        coro = self.internal_transfers_df_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    @async_property
    async def internal_transfers_df_async(self) -> DataFrame:
        internal_transfers = await self.internal_transfers_async
        internal_transfers = {address: DataFrame(data) for address, data in internal_transfers.items()}
        internal_transfers = concat(internal_transfers.values())
        internal_transfers['chainId'] = chain.id
        internal_transfers.blockNumber = internal_transfers.blockNumber.apply(int)
        internal_transfers.gas = internal_transfers.gas.apply(lambda x: int(x, 16))
        #internal_transfers.gasUsed = internal_transfers.gasUsed.apply(lambda x: int(x, 16))
        internal_transfers.rename(columns={'transactionHash': 'hash', 'transactionPosition': 'transactionIndex'}, inplace=True)
        internal_transfers.transactionIndex = internal_transfers.transactionIndex.apply(int)
        internal_transfers[internal_transfers['value'] != 0]
        internal_transfers.set_index('blockNumber', inplace=True)
        return internal_transfers
    
    @property
    def token_transfers_df(self) -> DataFrame:
        coro = self.token_transfers_df_async
        if self.portfolio.asynchronous:
            return coro
        return await_awaitable(coro)
    
    @async_property
    async def token_transfers_df_async(self) -> DataFrame:
        token_transfers = await self.token_transfers_async
        prices, scales, symbols = await asyncio.gather(*[
            asyncio.gather(*[
                tqdm_asyncio.gather(*[_get_price(transfer.address, transfer.block_number) for transfer in token_transfers[address]])
                for address in token_transfers
            ]),
            asyncio.gather(*[
                asyncio.gather(*[ERC20(transfer.address).scale for transfer in token_transfers[address]])
                for address in token_transfers
            ]),
            asyncio.gather(*[
                asyncio.gather(*[ERC20(transfer.address).symbol_async for transfer in token_transfers[address]])
                for address in token_transfers
            ]),
        ])

        for i, address in enumerate(token_transfers):
            _transfers = []
            _prices = prices[i]
            _scales = scales[i]
            _symbols = symbols[i]
            for i, transfer in enumerate(token_transfers[address]):
                sender, receiver, amount = transfer.values()
                scale = Decimal(_scales[i])
                amount = Decimal(amount) / scale
                price = _prices[i]
                price = round(Decimal(price), 18) if price is not None else None
                _transfers.append({
                    'chainId': chain.id,
                    'blockNumber': transfer.block_number,
                    'log_index': transfer.log_index,
                    'hash': transfer.transaction_hash,
                    'token': _symbols[i],
                    'token_address': transfer.address,
                    'from': sender,
                    'to': receiver,
                    'value': amount,
                    'price': price,
                    'value_usd': round(amount * price, 18) if price is not None else None,
                })
            token_transfers[address] = DataFrame(_transfers)
        token_transfers = concat(token_transfers.values())
        token_transfers.hash = token_transfers.hash.apply(lambda x: x.hex())
        token_transfers.set_index('blockNumber', inplace=True)
        logger.warning(f"token transfers: {token_transfers}")
        return token_transfers

async def _get_price(token, block) -> UsdPrice:
    try:
        return await get_price_async(token, block, fail_to_None=True)
    except PriceError:
        return None

# Use this var for a convenient way to set up your portfolio using env vars.
portfolio = Portfolio(ADDRESSES)
