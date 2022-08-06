import asyncio
import logging
from functools import cached_property
from types import MethodType
from typing import Any, Dict, Iterable, List

from async_property import async_property
from brownie import web3
from checksum_dict import ChecksumAddressDict
from pandas import DataFrame, concat  # type: ignore
from web3 import Web3
from y.datatypes import Address, Block

from eth_portfolio._decorators import await_if_sync, set_end_block_if_none
from eth_portfolio._ledgers.address import PandableLedgerEntryList
from eth_portfolio._ledgers.portfolio import (PortfolioInternalTransfersLedger,
                                              PortfolioTokenTransfersLedger,
                                              PortfolioTransactionsLedger)
from eth_portfolio.address import PortfolioAddress
from eth_portfolio.argspec import get_return_type
from eth_portfolio.constants import ADDRESSES
from eth_portfolio.typing import Addresses, PortfolioBalances

logger = logging.getLogger(__name__)


class Portfolio:
    addresses: ChecksumAddressDict[PortfolioAddress]
    """
    Used to export information about a group of ``PortfolioAddress`` objects.
    - Has all attributes of a PortfolioAddress.
    - All calls to ``function(*args, **kwargs)`` will return ``{address: PortfolioAddress(Address).function(*args, **kwargs)}``
    """
    def __init__(
        self,
        addresses: Addresses,
        start_block: int = 0,
        label: str = "your portfolio",
        asynchronous: bool = False,
        load_prices: bool = True,
    ) -> None:

        assert isinstance(addresses, Iterable), f"`addresses` must be an iterable, not {type(addresses)}"
        if isinstance(addresses, str):
            addresses = [addresses]

        self.addresses = ChecksumAddressDict({address: PortfolioAddress(address, self) for address in addresses})

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
        self.__import_address_functions()
    
    def __getitem__(self, key: Address) -> PortfolioAddress:
        return self.addresses[key]
    
    @property
    def transactions(self) -> PortfolioTransactionsLedger:
        return self.ledger.transactions
    
    @property
    def internal_transfers(self) -> PortfolioInternalTransfersLedger:
        return self.ledger.internal_transfers
    
    @property
    def token_transfers(self) -> PortfolioTokenTransfersLedger:
        return self.ledger.token_transfers
    
    @cached_property
    def chain_id(self) -> int:
        return self.w3.eth.chainId
    
    @await_if_sync
    def describe(self, block: int) -> PortfolioBalances:
        return self._describe_async(block=block) # type: ignore
    
    async def _describe_async(self, block: int) -> PortfolioBalances:
        assert block
        return PortfolioBalances(await asyncio.gather(*[address._describe_async(block) for address in self.addresses.values()]))
    
    def __import_address_functions(self) -> None:
        if self.addresses:
            async_functions = [name for name in dir(PortfolioAddress) if name.startswith("_") and name.endswith("_async")]
            for async_name in async_functions:
                if not callable(getattr(PortfolioAddress, async_name)):
                    raise RuntimeError(f"A PortfolioAddress object should not have a non-callable attribute suffixed with '_async'")
                sync_name = async_name[1:-6]
                if hasattr(self, sync_name):
                    logger.debug(f"Portfolio already has an attribute `{sync_name}`. Will not porting {sync_name} from PortfolioAddress to Portfolio")
                    continue
                self.__new_sync_func(sync_name)
                self.__new_async_func(async_name)
                logger.debug(f"Ported {sync_name} from PortfolioAddress to Portfolio")
    
    def __new_sync_func(self, sync_name: str) -> None:
        @await_if_sync
        def sync_func(self: Portfolio, *args, **kwargs) -> get_return_type(getattr(PortfolioAddress, sync_name)):  # type: ignore
            async_func = getattr(self, f"_{sync_name}_async")
            return async_func(*args, **kwargs)
        setattr(self, sync_name, MethodType(sync_func, self))
    
    def __new_async_func(self, async_name: str) -> None:
        async def async_func(self: Portfolio, *args: Any, **kwargs: Any) -> get_return_type(getattr(PortfolioAddress, async_name)):  # type: ignore
            vals = await asyncio.gather(*[getattr(address, async_name)(*args, **kwargs) for address in self.addresses.values()])
            return {address: data for address, data in zip(self.addresses, vals)}
        setattr(self, async_name, MethodType(async_func, self))


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
