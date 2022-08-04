import asyncio
import logging
from functools import cached_property
from typing import Dict, Generic, Iterable, List, Tuple, Union

from async_property import async_property
from brownie import web3
from eth_abi import encode_single
from pandas import DataFrame, concat  # type: ignore
from web3 import Web3
from y import Contract, Network, get_price_async
from y.datatypes import Address, Block

from eth_portfolio.address import (AddressObjectCacheBase,
                                   InternalTransfersList, PortfolioAddress,
                                   TokenTransfersList, TransactionsList,
                                   _LedgerEntryList, _PandableList)
from eth_portfolio.constants import ADDRESSES
from eth_portfolio.decorators import await_if_sync, set_end_block_if_none
from eth_portfolio.typing import (Addresses, PortfolioBalances,
                                  StakedTokenBalances)
from eth_portfolio.utils import ChecksumAddressDict, _unpack_indicies

logger = logging.getLogger(__name__)


class PortfolioLedgerBase(Generic[_LedgerEntryList]):
    property_name: str

    def __init__(self, portfolio: "Portfolio"):
        assert hasattr(self, "property_name"), "Subclasses must define a property_name"
        self.object_caches: Dict[Address, AddressObjectCacheBase] = {address.address: getattr(address, self.property_name) for address in portfolio.addresses.values()}
        self.portfolio = portfolio
    
    def __getitem__(self, indicies: Union[Block,Tuple[Block,Block]]) -> Dict[Address, _LedgerEntryList]:
        start_block, end_block = _unpack_indicies(indicies)
        if asyncio.get_event_loop().is_running():
            return self._get_async(start_block, end_block) # type: ignore
        return self.get(start_block, end_block)
    
    @property
    def asynchronous(self) -> bool:
        return self.portfolio.asynchronous
    
    @property
    def load_prices(self) -> bool:
        return self.portfolio.load_prices
    
    @await_if_sync
    def get(self, start_block: Block, end_block: Block) -> Dict[Address, _LedgerEntryList]:
        return self._get_async(start_block, end_block) # type: ignore
    
    @set_end_block_if_none
    async def _get_async(self, start_block: Block, end_block: Block) -> Dict[Address, _LedgerEntryList]:
        token_transfers = await asyncio.gather(*[cache._get_async(start_block, end_block) for cache in self.object_caches.values()])
        return {address: transfers for address, transfers in zip(self.portfolio.addresses, token_transfers)}

    @await_if_sync
    def _df(self, start_block: Block = 0, end_block: Block = None) -> DataFrame:
        return self._df_async(start_block, end_block)
    
    @set_end_block_if_none
    async def _df_async(self, start_block: Block, end_block: Block) -> DataFrame:
        """ Override this method if you want to do something special with the dataframe """
        df = await self._df_base(start_block, end_block)
        if len(df) > 0:
            df = self._cleanup_df(df)
        return df
    
    async def _df_base(self, start_block: Block, end_block: Block) -> DataFrame:
        data: Dict[Address, _LedgerEntryList] = await self._get_async(start_block, end_block)
        df = concat(pandable.df for pandable in data.values())
        return df
    
    def _deduplicate_df(self, df: DataFrame) -> DataFrame:
        return df.drop_duplicates(inplace=False)
    
    def _cleanup_df(self, df: DataFrame) -> DataFrame:
        df = self._deduplicate_df(df)
        return df.set_index('blockNumber')


class PortfolioTransactions(PortfolioLedgerBase[TransactionsList]):
    property_name = "transactions"

class PortfolioTokenTransfers(PortfolioLedgerBase[TokenTransfersList]):
    property_name = "token_transfers"

class PortfolioInternalTransfers(PortfolioLedgerBase[InternalTransfersList]):
    property_name = "internal_transfers"

    @set_end_block_if_none
    async def _df_async(self, start_block: Block, end_block: Block) -> DataFrame:
        df = await self._df_base(start_block, end_block)
        if len(df) > 0:
            df.rename(columns={'transactionHash': 'hash', 'transactionPosition': 'transactionIndex'}, inplace=True)
            df = self._cleanup_df(df)
        return df

    def _deduplicate_df(self, df: DataFrame) -> DataFrame:
        """
        We cant use drop_duplicates when one of the columns, `traceAddress`, contains lists.
        We must first convert the lists to strings
        """
        df = df.reset_index()
        return df.loc[df.astype(str).drop_duplicates().index]


class Portfolio:
    '''
    Used to export financial reports
    '''

    def __init__(
        self,
        addresses: Addresses,
        start_block: int = 0,
        label: str = "your portfolio",
        asynchronous: bool = False,
        load_prices: bool = True,
    ) -> None:

        self.addresses: Dict[Address, PortfolioAddress]
        assert isinstance(addresses, Iterable), f"`addresses` must be an iterable, not {type(addresses)}"
        if isinstance(addresses, str):
            addresses = [addresses]
        self.addresses = ChecksumAddressDict()
        for address in addresses:
            self.addresses[address] = PortfolioAddress(address = address, portfolio = portfolio)

        assert isinstance(start_block, int), f"`start_block` must be an integer, not {type(start_block)}"
        assert start_block >= 0, "`start_block` must be >= 0"
        self._start_block = start_block

        assert isinstance(label, str), f"`label` must be a string, you passed {type(label)}"
        self.label = label

        assert isinstance(asynchronous, bool), f"`asynchronous` must be a boolean, you passed {type(asynchronous)}"
        self.asynchronous: bool = asynchronous

        assert isinstance(load_prices, bool), f"`load_prices` must be a boolean, you passed {type(load_prices)}"
        self.load_prices: bool = load_prices

        self.w3: Web3 = web3
        self.ledger = Ledger(self)
        self.transactions = PortfolioTransactions(self)
        self.internal_transfers = PortfolioInternalTransfers(self)
        self.token_transfers = PortfolioTokenTransfers(self)
    
    @cached_property
    def chain_id(self) -> int:
        return self.w3.eth.chainId

    # descriptive functions
    # assets

    @await_if_sync
    def assets(self, block: int = None) -> PortfolioBalances:
        return self._assets_async(block=block) # type: ignore
    
    async def _assets_async(self, block: int = None) -> PortfolioBalances:
        assets = await asyncio.gather(*[address._assets_async(block=block) for address in self.addresses.values()])
        return {address: data for address, data in zip(self.addresses, assets)}

    @await_if_sync
    def held_assets(self, block: int = None) -> PortfolioBalances:
        return self._held_assets_async(block=block) # type: ignore
    
    async def _held_assets_async(self, block: int = None) -> PortfolioBalances:
        assets = await asyncio.gather(*[address._balances_async(block=block) for address in self.addresses.values()])
        return {address: data for address, data in zip(self.addresses, assets)}

    @await_if_sync
    def collateral(self, block: int = None) -> PortfolioBalances:
        return self._collateral_async(block=block) # type: ignore
    
    async def _collateral_async(self, block: int = None) -> PortfolioBalances:
        collateral = {}

        maker_collateral, unit_collateral = await asyncio.gather(
            self._maker_collateral_async(block=block),
            self._unit_collateral_async(block=block)
        )

        if maker_collateral:
            for address, data in maker_collateral.items():
                collateral[f'{address} Maker CDP'] = data

        if unit_collateral:
            for address, data in unit_collateral.items():
                collateral[f'{address} Unit CDP'] = data

        collateral = {key: value for key, value in collateral.items() if len(value)}
        return collateral

    @await_if_sync
    def maker_collateral(self, block: int = None) -> PortfolioBalances:
        return self._maker_collateral_async(block=block) # type: ignore
    
    async def _maker_collateral_async(self, block: int = None) -> PortfolioBalances:
        if self.chain_id != Network.Mainnet:
            return {}
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
    
    @await_if_sync
    def unit_collateral(self, block: int = None) -> PortfolioBalances:
        return self._unit_collateral_async(block=block) # type: ignore
    
    async def _unit_collateral_async(self, block: int = None) -> PortfolioBalances:
        if self.chain_id != Network.Mainnet:
            return {}
        if block and block < 11315910:
            return {}
        
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
    
    @await_if_sync
    def staked_assets(self, block: int = None) -> Dict[PortfolioAddress, StakedTokenBalances]:
        return self._staked_assets_async(block=block) # type: ignore
    
    async def _staked_assets_async(self, block: int = None) -> Dict[PortfolioAddress, StakedTokenBalances]:
        staked_assets = await asyncio.gather(*[address._staking_async(block=block) for address in self.addresses.values()])
        return {address: data for address, data in zip(self.addresses, staked_assets)}
    
    # descriptive functions
    # debt

    @await_if_sync
    def debt(self, block: int = None) -> PortfolioBalances:
        return self._debt_async(block=block) # type: ignore
    
    async def _debt_async(self, block: int = None) -> PortfolioBalances:
        debt = await asyncio.gather(*[address._debt_async(block=block) for address in self.addresses.values()])
        return {address: data for address, data in zip(self.addresses, debt)}

    # export functions
    @await_if_sync
    def describe(self, block: int) -> Dict[str, PortfolioBalances]:
        return self._describe_async(block=block) # type: ignore
    
    async def _describe_async(self, block: int) -> Dict[str, PortfolioBalances]:
        assert block
        assets, debt = await asyncio.gather(*[self._assets_async(block), self._debt_async(block)])
        return {'assets': assets, 'debt': debt}


class Ledger:
    """
    Stores a ledger of all transactions for a ``Portfolio`` object, along with information about them .
    """
    def __init__(self, portfolio: Portfolio) -> None:
        self.portfolio = portfolio
        self.token_transfers = PortfolioTokenTransfers(portfolio)
        self.max_block = self.portfolio._start_block - 1
        self.w3: Web3 = web3
    
    @property
    def asynchronous(self) -> bool:
        return self.portfolio.asynchronous
        
    @property
    def load_prices(self) -> bool:
        return self.portfolio.load_prices
    
    # All Ledger entries
    
    @await_if_sync
    def all_entries(self, start_block: Block = 0, end_block: Block = None) -> Dict[PortfolioAddress, Dict[str, _PandableList]]:
        return self._all_entries_async(start_block, end_block)
    
    @async_property
    async def _all_entries_async(self, start_block: Block, end_block: Block) -> Dict[PortfolioAddress, Dict[str, _PandableList]]:
        all_transactions = await asyncio.gather(*[address._all_async(start_block, end_block) for address in self.portfolio.addresses.values()])
        return {address: data for address, data in zip(self.portfolio.addresses, all_transactions)}

    # Pandas

    @await_if_sync
    def df(self, start_block: Block = 0, end_block: Block = None, full: bool = False) -> DataFrame:
        return self._df_async(start_block, end_block, full=full)
    
    @set_end_block_if_none
    async def _df_async(self, start_block: Block, end_block: Block, full: bool = False) -> DataFrame:
        df = concat(
            await asyncio.gather(
                self.portfolio.transactions._df_async(start_block, end_block),
                self.portfolio.internal_transfers._df_async(start_block, end_block),
                self.portfolio.token_transfers._df_async(start_block, end_block),
            )
        )
        
        # Reorder columns
        while True:
            try:
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
                break
            except KeyError as e:
                for column in get_missing_cols_from_KeyError(e):
                    df[column] = None

        df.sort_index(inplace=True)


        logger.critical(df)
        logger.critical(df.columns)
        logger.critical(df.dtypes)
        return df

def get_missing_cols_from_KeyError(e: KeyError) -> List[str]:
    split = str(e).split("'")
    return [split[i * 2 + 1] for i in range(len(split)//2)]

# Use this var for a convenient way to set up your portfolio using env vars.
portfolio = Portfolio(ADDRESSES)
