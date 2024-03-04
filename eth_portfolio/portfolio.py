import asyncio
import logging
from functools import cached_property
from types import MethodType
from typing import Any, Dict, Iterable, Iterator, List

import a_sync
import a_sync.modified
from brownie import web3
from checksum_dict import ChecksumAddressDict
from pandas import DataFrame, concat  # type: ignore
from web3 import Web3
from y.datatypes import Address, Block

from eth_portfolio._decorators import set_end_block_if_none
from eth_portfolio._ledgers.address import PandableLedgerEntryList
from eth_portfolio._ledgers.portfolio import (PortfolioInternalTransfersLedger,
                                              PortfolioLedgerBase,
                                              PortfolioTokenTransfersLedger,
                                              PortfolioTransactionsLedger)
from eth_portfolio.address import PortfolioAddress
from eth_portfolio.argspec import get_return_type
from eth_portfolio.constants import ADDRESSES
from eth_portfolio.structs import _LE
from eth_portfolio.typing import Addresses, PortfolioBalances
from eth_portfolio.utils import _LedgeredBase

logger = logging.getLogger(__name__)


class Portfolio(a_sync.ASyncGenericBase):
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
        load_prices: bool = True,
        asynchronous: bool = False,
    ) -> None:

        assert isinstance(start_block, int), f"`start_block` must be an integer, not {type(start_block)}"
        assert start_block >= 0, "`start_block` must be >= 0"
        self._start_block = start_block

        assert isinstance(label, str), f"`label` must be a string, you passed {type(label)}"
        self.label = label

        assert isinstance(load_prices, bool), f"`load_prices` must be a boolean, you passed {type(load_prices)}"
        self.load_prices: bool = load_prices

        assert isinstance(asynchronous, bool), f"`asynchronous` must be a boolean, you passed {type(load_prices)}"
        self.asynchronous: bool = asynchronous
        
        assert isinstance(addresses, Iterable), f"`addresses` must be an iterable, not {type(addresses)}"
        if isinstance(addresses, str):
            addresses = [addresses]

        self.addresses = ChecksumAddressDict({address: PortfolioAddress(address, self, asynchronous=self.asynchronous) for address in addresses})

        self.ledger = PortfolioLedger(self)

        self.w3: Web3 = web3
        self.__import_address_functions()
    
    def __getitem__(self, key: Address) -> PortfolioAddress:
        return self.addresses[key]
    
    def __iter__(self) -> Iterator[PortfolioAddress]:
        return iter(self.addresses.values())
    
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
    
    async def describe(self, block: int) -> PortfolioBalances:
        assert block
        return PortfolioBalances(await a_sync.map(lambda address: address.describe(block, sync=False), self))
    
    def __import_address_functions(self) -> None:
        if self.addresses:
            async_functions = [name for name, obj in PortfolioAddress.__dict__.items() if isinstance(obj, a_sync.modified.ASyncFunction)]
            for async_name in async_functions:
                if not callable(getattr(PortfolioAddress, async_name)):
                    raise RuntimeError(f"A PortfolioAddress object should not have a non-callable attribute suffixed with '_async'")
                sync_name = async_name[1:-6]
                if hasattr(self, sync_name):
                    logger.debug(f"Portfolio already has an attribute `{sync_name}`. Will not porting {sync_name} from PortfolioAddress to Portfolio")
                    continue
                self.__new_async_func(async_name)
                logger.debug(f"Ported {sync_name} from PortfolioAddress to Portfolio")
    
    def __new_async_func(self, async_name: str) -> None:
        a_sync.a_sync
        async def async_func(self: Portfolio, *args: Any, **kwargs: Any) -> get_return_type(getattr(PortfolioAddress, async_name)):  # type: ignore
            vals = await asyncio.gather(*[getattr(address, async_name)(*args, **kwargs) for address in self])
            return {address: data for address, data in zip(self.addresses, vals)}
        setattr(self, async_name, MethodType(async_func, self))


def _get_missing_cols_from_KeyError(e: KeyError) -> List[str]:
    split = str(e).split("'")
    return [split[i * 2 + 1] for i in range(len(split)//2)]

class PortfolioLedger(_LedgeredBase[PortfolioLedgerBase]):
    def __init__(self, portfolio: "Portfolio") -> None:
        super().__init__(portfolio)
        self.transactions = PortfolioTransactionsLedger(portfolio)
        self.internal_transfers = PortfolioInternalTransfersLedger(portfolio)
        self.token_transfers = PortfolioTokenTransfersLedger(portfolio)
    
    @property
    def asynchronous(self) -> bool:
        return self.portfolio.asynchronous
    
    @property
    def w3(self) -> Web3:
        return self.portfolio.w3
    
    # All Ledger entries
    
    async def all_entries(self, start_block: Block, end_block: Block) -> Dict[PortfolioAddress, Dict[str, PandableLedgerEntryList]]:
        all_transactions = await asyncio.gather(*[address.all(start_block, end_block, sync=False) for address in self.portfolio])
        return {address: data for address, data in zip(self.portfolio.addresses, all_transactions)}

    # Pandas
    
    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block, full: bool = False) -> DataFrame:
        df = concat(await asyncio.gather(*(ledger.df(start_block, end_block, sync=False) for ledger in self._ledgers)))
        
        # Reorder columns
        while True:
            try:
                if full:
                    df = df[[
                        'chainId',
                        'blockNumber',
                        'blockHash',
                        'transactionIndex',
                        'hash',
                        'log_index',
                        'nonce',
                        'from',
                        'to',
                        'token',
                        'token_address',
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
                        'input',
                    ]]
                else:
                    df = df[[
                        'chainId',
                        'blockNumber',
                        'hash',
                        'from',
                        'to',
                        'token',
                        'token_address',
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
        
        try:
            if full:
                return df.sort_values(["blockNumber", "transactionIndex", "log_index"]).reset_index(drop=True)
            else:
                return df.sort_values(['blockNumber','hash']).reset_index(drop=True)
        except KeyError:
            logger.error(df)
            logger.error(df.columns)
            raise


# Use this var for a convenient way to set up your portfolio using env vars.
portfolio = Portfolio(ADDRESSES)
