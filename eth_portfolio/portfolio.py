
import asyncio
import logging
from functools import cached_property, wraps
from types import MethodType
from typing import Any, Dict, Iterable, Iterator, List, Tuple

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
from eth_portfolio.typing import Addresses, PortfolioBalances
from eth_portfolio.utils import _LedgeredBase

logger = logging.getLogger(__name__)


class PortfolioWallets(Iterable[PortfolioAddress], Dict[Address, PortfolioAddress]):
    """
    A container that holds all `PortfolioAddress` objects for a specific `Portfolio`.
    Works like a `Dict[Address, PortfolioAddress]` except when you iterate you get the values instead of the keys.
    You should not initialize these. They are created automagically during Portfolio init.
    """
    _wallets: ChecksumAddressDict[PortfolioAddress]
    def __init__(self, portfolio: "Portfolio", addresses: Iterable[Address]) -> None:
        self._wallets: ChecksumAddressDict[PortfolioAddress] = ChecksumAddressDict({
            address: PortfolioAddress(address, portfolio, asynchronous=portfolio.asynchronous)
            for address in addresses
        })
    def __repr__(self) -> str:
        return f"<{type(self).__name__} wallets={list(self._wallets.values())}>"
    def __getitem__(self, address: Address) -> PortfolioAddress:
        return self._wallets[address]
    def __iter__(self) -> Iterator[PortfolioAddress]:
        yield from self._wallets.values()
    def __len__(self) -> int:
        return len(self._wallets)
    def __bool__(self) -> bool:
        return bool(self._wallets)
    def keys(self) -> Iterator[Address]:
        return self._wallets.keys()
    def values(self) -> Iterator[PortfolioAddress]:
        return self._wallets.values()
    def items(self) -> Iterator[Tuple[Address, PortfolioAddress]]:
        return self._wallets.items()


class Portfolio(a_sync.ASyncGenericBase):
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

        self.addresses = PortfolioWallets(self, addresses)
        """
        A container for your `Portfolio`'s `PortfolioAddress` objects.
        Works like a `Dict[Address, PortfolioAddress]` except you get the values when you iterate instead of the keys.
        """

        self.ledger = PortfolioLedger(self)
        """A container for all of your fun taxable events"""

        self.w3: Web3 = web3
        """The `Web3` object which will be used to call your rpc for all read operations"""
    
    def __getitem__(self, key: Address) -> PortfolioAddress:
        return self.addresses[key]
    
    def __iter__(self) -> Iterator[PortfolioAddress]:
        yield from self.addresses
    
    @property
    def transactions(self) -> PortfolioTransactionsLedger:
        """A container for all transactions to or from any of your `PortfolioAddress`"""
        return self.ledger.transactions
    
    @property
    def internal_transfers(self) -> PortfolioInternalTransfersLedger:
        """A container for all internal transfers to or from any of your `PortfolioAddress`"""
        return self.ledger.internal_transfers
    
    @property
    def token_transfers(self) -> PortfolioTokenTransfersLedger:
        """A container for all token transfers to or from any of your `PortfolioAddress`"""
        return self.ledger.token_transfers
    
    @cached_property
    def chain_id(self) -> int:
        """Returns the chainid for the connected brownie network"""
        return self.w3.eth.chainId
    
    async def describe(self, block: int) -> PortfolioBalances:
        """Returns a full snapshot of your portfolio at `block`"""
        assert block
        return PortfolioBalances(await a_sync.map(lambda address: address.describe(block, sync=False), self))
    
    
async_functions = {name: obj for name, obj in PortfolioAddress.__dict__.items() if isinstance(obj, a_sync.modified.ASyncFunction)}
for func_name, func in async_functions.items():
    if not callable(getattr(PortfolioAddress, func_name)):
        raise RuntimeError(f"A PortfolioAddress object should not have a non-callable attribute suffixed with '_async'")
    @a_sync.a_sync(default=func.default)
    @wraps(func)
    async def imported_func(self: Portfolio, *args: Any, **kwargs: Any) -> get_return_type(getattr(PortfolioAddress, func_name)):  # type: ignore
        return await a_sync.gather({address: func(address, *args, **kwargs, sync=False) for address in self})
    setattr(Portfolio, func_name, imported_func)
    logger.debug(f"Ported {func_name} from PortfolioAddress to Portfolio")


def _get_missing_cols_from_KeyError(e: KeyError) -> List[str]:
    split = str(e).split("'")
    return [split[i * 2 + 1] for i in range(len(split)//2)]

class PortfolioLedger(_LedgeredBase[PortfolioLedgerBase]):
    """A container for all transactions, internal transfers, and token transfers to or from any of the wallets in your `Portfolio`"""
    def __init__(self, portfolio: "Portfolio") -> None:
        super().__init__(portfolio._start_block)
        self.portfolio = portfolio
        """The `Portfolio` containing the wallets this ledger will pertain to"""
        self.transactions = PortfolioTransactionsLedger(portfolio)
        """A container for all transactions to or from any of your `PortfolioAddress`"""
        self.internal_transfers = PortfolioInternalTransfersLedger(portfolio)
        """A container for all internal transfers to or from any of your `PortfolioAddress`"""
        self.token_transfers = PortfolioTokenTransfersLedger(portfolio)
        """A container for all token transfers to or from any of your `PortfolioAddress`"""
        self.asynchronous = portfolio.asynchronous
        """True if default mode is async, False if sync"""
    
    async def all_entries(self, start_block: Block, end_block: Block) -> Dict[PortfolioAddress, Dict[str, PandableLedgerEntryList]]:
        """Returns a mapping containing all transactions, internal transfers, and token transfers to or from each wallet in your portfolio."""
        return await a_sync.gather({address: address.all(start_block, end_block, sync=False) for address in self.portfolio})

    # Pandas
    
    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block, full: bool = False) -> DataFrame:
        """Returns a DataFrame containing all transactions, internal transfers, and token transfers to or from any wallet in your portfolio."""
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
