import asyncio
import logging
from functools import cached_property
from typing import Dict, Iterable, List

from async_property import async_property
from brownie import web3
from eth_abi import encode_single
from pandas import DataFrame, concat  # type: ignore
from web3 import Web3
from y import Contract, Network, get_price_async
from y.datatypes import Address, Block

from eth_portfolio._ledgers.address import PandableLedgerEntryList
from eth_portfolio._ledgers.portfolio import (PortfolioInternalTransfersLedger,
                                              PortfolioTokenTransfersLedger,
                                              PortfolioTransactionsLedger)
from eth_portfolio.address import PortfolioAddress
from eth_portfolio.constants import ADDRESSES
from eth_portfolio.decorators import await_if_sync, set_end_block_if_none
from eth_portfolio.typing import (Addresses, PortfolioBalances,
                                  StakedTokenBalances)
from eth_portfolio.utils import ChecksumAddressDict

logger = logging.getLogger(__name__)


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

        self.ledger = PortfolioLedger(self)

        self.w3: Web3 = web3
    
    @cached_property
    def chain_id(self) -> int:
        return self.w3.eth.chainId
    
    @property
    def transactions(self) -> PortfolioTransactionsLedger:
        return self.ledger.transactions
    
    @property
    def internal_transfers(self) -> PortfolioInternalTransfersLedger:
        return self.ledger.internal_transfers
    
    @property
    def token_transfers(self) -> PortfolioTokenTransfersLedger:
        return self.ledger.token_transfers

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


def _get_missing_cols_from_KeyError(e: KeyError) -> List[str]:
    split = str(e).split("'")
    return [split[i * 2 + 1] for i in range(len(split)//2)]

class PortfolioLedger:
    def __init__(self, portfolio: "Portfolio") -> None:
        self.portfolio = portfolio

        self.transactions = PortfolioTransactionsLedger(portfolio)
        self.internal_transfers = PortfolioInternalTransfersLedger(portfolio)
        self.token_transfers = PortfolioTokenTransfersLedger(portfolio)
    
    @property
    def asynchronous(self) -> bool:
        return self.portfolio.asynchronous
        
    @property
    def load_prices(self) -> bool:
        return self.portfolio.load_prices
    
    @property
    def w3(self) -> Web3:
        return self.portfolio.w3
    
    # All Ledger entries
    
    @await_if_sync
    def all_entries(self, start_block: Block = 0, end_block: Block = None) -> Dict[PortfolioAddress, Dict[str, PandableLedgerEntryList]]:
        return self._all_entries_async(start_block, end_block)
    
    @async_property
    async def _all_entries_async(self, start_block: Block, end_block: Block) -> Dict[PortfolioAddress, Dict[str, PandableLedgerEntryList]]:
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
                for column in _get_missing_cols_from_KeyError(e):
                    df[column] = None
        return df.sort_index()


# Use this var for a convenient way to set up your portfolio using env vars.
portfolio = Portfolio(ADDRESSES)
