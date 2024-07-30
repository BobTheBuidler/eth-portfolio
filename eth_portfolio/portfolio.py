"""
This module defines the `Portfolio` and `PortfolioWallets` classes, which are used to manage and interact with a collection of `PortfolioAddress` objects.
It also includes the `PortfolioLedger` class for handling transactions, internal transfers, and token transfers associated with the portfolio.
The `Portfolio` class leverages the `a_sync` library to support both synchronous and asynchronous operations. This allows it to efficiently gather data, perform portfolio-related tasks, and handle network calls without blocking, thus improving the overall responsiveness and performance of portfolio operations.

This file is part of a larger system that includes modules for handling portfolio addresses, ledger entries, and other related tasks.
"""

import asyncio
import logging
from functools import cached_property, wraps
from typing import Any, Dict, Iterable, Iterator, List, Tuple, Union

import a_sync
from a_sync.a_sync import ASyncFunction
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
from eth_portfolio import _argspec
from eth_portfolio._utils import _LedgeredBase
from eth_portfolio.address import PortfolioAddress
from eth_portfolio.constants import ADDRESSES
from eth_portfolio.typing import Addresses, PortfolioBalances

logger = logging.getLogger(__name__)


class PortfolioWallets(Iterable[PortfolioAddress], Dict[Address, PortfolioAddress]):  # type: ignore [misc]
    """
    A container that holds all :class:`PortfolioAddress` objects for a specific :class:`Portfolio`.

    Works like a `Dict[Address, PortfolioAddress]` except when you iterate you get the values instead of the keys.
    You should not initialize these. They are created automagically during :class:`Portfolio` init.

    """
    _wallets: ChecksumAddressDict[PortfolioAddress]

    def __init__(self, portfolio: "Portfolio", addresses: Iterable[Address]) -> None:
        """
        Initialize a PortfolioWallets instance.

        :param portfolio: The :class:`Portfolio` instance to which this wallet belongs.
        :type portfolio: Portfolio
        :param addresses: An iterable of addresses to be included in the portfolio.
        :type addresses: Iterable[Address]
        """
        self._wallets: ChecksumAddressDict[PortfolioAddress] = ChecksumAddressDict({
            """
            :ivar _wallets: A checksummed dictionary of PortfolioAddress objects.
            :vartype _wallets: ChecksumAddressDict[PortfolioAddress]
            """
            address: PortfolioAddress(address, portfolio, asynchronous=portfolio.asynchronous)
            for address in addresses
        })

    def __repr__(self) -> str:
        """
        Return a string representation of the PortfolioWallets instance.

        :return: String representation of the instance.
        :rtype: str
        """
        return f"<{type(self).__name__} wallets={list(self._wallets.values())}>"

    def __contains__(self, address: Union[Address, PortfolioAddress]) -> bool:
        """
        Check if an address is in the portfolio wallets.

        :param address: The address to check.
        :type address: Union[Address, PortfolioAddress]
        :return: True if the address is in the wallets, False otherwise.
        :rtype: bool
        """
        return address in self._wallets

    def __getitem__(self, address: Address) -> PortfolioAddress:
        """
        Get the PortfolioAddress object for a given address.

        :param address: The address to look up.
        :type address: Address
        :return: The PortfolioAddress object.
        :rtype: PortfolioAddress
        """
        return self._wallets[address]

    def __iter__(self) -> Iterator[PortfolioAddress]:
        """
        Iterate over the PortfolioAddress objects in the wallets.

        :return: An iterator over PortfolioAddress objects.
        :rtype: Iterator[PortfolioAddress]
        """
        yield from self._wallets.values()

    def __len__(self) -> int:
        """
        Get the number of PortfolioAddress objects in the wallets.

        :return: The number of PortfolioAddress objects.
        :rtype: int
        """
        return len(self._wallets)

    def __bool__(self) -> bool:
        """
        Check if the wallets contain any addresses.

        :return: True if there are addresses in the wallets, False otherwise.
        :rtype: bool
        """
        return bool(self._wallets)

    def keys(self) -> Iterable[Address]:
        """
        Get the keys (addresses) of the wallets.

        :return: An iterable of addresses.
        :rtype: Iterable[Address]
        """
        return self._wallets.keys()

    def values(self) -> Iterable[PortfolioAddress]:
        """
        Get the values (PortfolioAddress objects) of the wallets.

        :return: An iterable of PortfolioAddress objects.
        :rtype: Iterable[PortfolioAddress]
        """
        return self._wallets.values()

    def items(self) -> Iterable[Tuple[Address, PortfolioAddress]]:
        """
        Get the items (address, PortfolioAddress pairs) of the wallets.

        :return: An iterable of (address, PortfolioAddress) tuples.
        :rtype: Iterable[Tuple[Address, PortfolioAddress]]
        """
        return self._wallets.items()


class Portfolio(a_sync.ASyncGenericBase):
    """
    Used to export information about a group of :class:`PortfolioAddress` objects.

    - Has all attributes of a :class:`PortfolioAddress`.
    - All calls to `function(*args, **kwargs)` will return `{address: PortfolioAddress(Address).function(*args, **kwargs)}`
    """
    def __init__(
        self,
        addresses: Addresses,
        start_block: int = 0,
        label: str = "your portfolio",
        load_prices: bool = True,
        asynchronous: bool = False,
    ) -> None:
        
        """
        Initialize a Portfolio instance.
        """
        assert isinstance(start_block, int), f"`start_block` must be an integer, not {type(start_block)}"
        assert start_block >= 0, "`start_block` must be >= 0"
        self._start_block = start_block
        """
        :ivar _start_block: The starting block number.
        :vartype _start_block: int
        """

        assert isinstance(label, str), f"`label` must be a string, you passed {type(label)}"
        self.label = label
        """
        :param label: A label for the portfolio, defaults to "your portfolio".
        :type label: str
        """

        assert isinstance(load_prices, bool), f"`load_prices` must be a boolean, you passed {type(load_prices)}"
        self.load_prices: bool = load_prices
        """
        :param load_prices: Whether to load prices when fetching account history, defaults to True.
        :type load_prices: bool
        """

        assert isinstance(asynchronous, bool), f"`asynchronous` must be a boolean, you passed {type(load_prices)}"
        self.asynchronous: bool = asynchronous
        """
        :param asynchronous: Whether to use asynchronous operations, defaults to False.
        :type asynchronous: bool
        """
        
        assert isinstance(addresses, Iterable), f"`addresses` must be an iterable, not {type(addresses)}"
        if isinstance(addresses, str):
            addresses = [addresses]
            """
            :param addresses: The addresses to include in the portfolio.
            :type addresses: Addresses
            """

        self.addresses = PortfolioWallets(self, addresses)
        """
        A container for your :class:`Portfolio`'s :class:`PortfolioAddress` objects.
        Works like a `Dict[Address, PortfolioAddress]` except you get the values when you iterate instead of the keys.
        """

        self.ledger = PortfolioLedger(self)
        """A container for all of your fun taxable events"""

        self.w3: Web3 = web3
        """The `Web3` object which will be used to call your rpc for all read operations"""
    
    def __getitem__(self, key: Address) -> PortfolioAddress:
        """
        Get a PortfolioAddress by its key.

        :param key: The address key.
        :type key: Address
        :return: The PortfolioAddress object.
        :rtype: PortfolioAddress
        """
        return self.addresses[key]
    
    def __iter__(self) -> Iterator[PortfolioAddress]:
        """
        Iterate over the PortfolioAddress objects.

        :return: An iterator over PortfolioAddress objects.
        :rtype: Iterator[PortfolioAddress]
        """
        yield from self.addresses
    
    @property
    def transactions(self) -> PortfolioTransactionsLedger:
        """
        A container for all transactions to or from any of your :class:`PortfolioAddress`.

        :return: The :class:`PortfolioTransactionsLedger` object.
        :rtype: PortfolioTransactionsLedger
        """
        return self.ledger.transactions
    
    @property
    def internal_transfers(self) -> PortfolioInternalTransfersLedger:
        """
        A container for all internal transfers to or from any of your :class:`PortfolioAddress`.

        :return: The :class:`PortfolioInternalTransfersLedger` object.
        :rtype: PortfolioInternalTransfersLedger
        """
        return self.ledger.internal_transfers
    
    @property
    def token_transfers(self) -> PortfolioTokenTransfersLedger:
        """
        A container for all token transfers to or from any of your :class:`PortfolioAddress`.

        :return: The :class:`PortfolioTokenTransfersLedger` object.
        :rtype: PortfolioTokenTransfersLedger
        """
        return self.ledger.token_transfers
    
    @cached_property
    def chain_id(self) -> int:
        """
        Returns the chain ID for the connected brownie network.

        :return: The chain ID.
        :rtype: int
        """
        return self.w3.eth.chainId
    
    async def describe(self, block: int) -> PortfolioBalances:
        """
        Returns a full snapshot of your portfolio at a given block.

        :param block: The block number.
        :type block: int
        :return: A snapshot of the portfolio balances.
        :rtype: PortfolioBalances
        """
        assert block
        return PortfolioBalances(await a_sync.gather({address: address.describe(block, sync=False) for address in self}))
    
    
async_functions = {name: obj for name, obj in PortfolioAddress.__dict__.items() if isinstance(obj, ASyncFunction)}
for func_name, func in async_functions.items():
    if not callable(getattr(PortfolioAddress, func_name)):
        raise RuntimeError(f"A PortfolioAddress object should not have a non-callable attribute suffixed with '_async'")
    @a_sync.a_sync(default=func.default)
    @wraps(func)
    async def imported_func(self: Portfolio, *args: Any, **kwargs: Any) -> _argspec.get_return_type(getattr(PortfolioAddress, func_name)):  # type: ignore
    async def imported_func(self: Portfolio, *args: Any, **kwargs: Any) -> get_return_type(getattr(PortfolioAddress, func_name)):  # type: ignore
        """
        Import an asynchronous function from PortfolioAddress to Portfolio.

        :param self: The :class:`Portfolio` instance.
        :type self: Portfolio
        :param args: Positional arguments for the function.
        :type args: Any
        :param kwargs: Keyword arguments for the function.
        :type kwargs: Any
        :return: The return type of the function.
        :rtype: Any
        """
        return await a_sync.gather({address: func(address, *args, **kwargs, sync=False) for address in self})
    setattr(Portfolio, func_name, imported_func)
    logger.debug(f"Ported {func_name} from PortfolioAddress to Portfolio")


def _get_missing_cols_from_KeyError(e: KeyError) -> List[str]:
    """
    Extract missing column names from a KeyError.

    :param e: The KeyError exception.
    :type e: KeyError
    :return: A list of missing column names.
    :rtype: List[str]
    """
    split = str(e).split("'")
    return [split[i * 2 + 1] for i in range(len(split)//2)]

class PortfolioLedger(_LedgeredBase[PortfolioLedgerBase]):
    """
    A container for all transactions, internal transfers, and token transfers to or from any of the wallets in your :class:`Portfolio`.

    :ivar portfolio: The :class:`Portfolio` containing the wallets this ledger will pertain to.
    :vartype portfolio: Portfolio
    :ivar transactions: A container for all transactions to or from any of your :class:`PortfolioAddress`.
    :vartype transactions: PortfolioTransactionsLedger
    :ivar internal_transfers: A container for all internal transfers to or from any of your :class:`PortfolioAddress`.
    :vartype internal_transfers: PortfolioInternalTransfersLedger
    :ivar token_transfers: A container for all token transfers to or from any of your :class:`PortfolioAddress`.
    :vartype token_transfers: PortfolioTokenTransfersLedger
    :ivar asynchronous: True if default mode is async, False if sync.
    :vartype asynchronous: bool
    """
    def __init__(self, portfolio: "Portfolio") -> None:
        """
        Internally self-initializes a PortfolioLedger instance.

        :param portfolio: The :class:`Portfolio` instance to which this ledger belongs.
        :type portfolio: Portfolio
        """
        super().__init__(portfolio._start_block)
        self.portfolio = portfolio
        """The :class:`Portfolio` containing the wallets this ledger will pertain to"""
        self.transactions = PortfolioTransactionsLedger(portfolio)
        """A container for all transactions to or from any of your :class:`PortfolioAddress`"""
        self.internal_transfers = PortfolioInternalTransfersLedger(portfolio)
        """A container for all internal transfers to or from any of your :class:`PortfolioAddress`"""
        self.token_transfers = PortfolioTokenTransfersLedger(portfolio)
        """A container for all token transfers to or from any of your :class:`PortfolioAddress`"""
        self.asynchronous = portfolio.asynchronous
        """True if default mode is async, False if sync"""
    
    async def all_entries(self, start_block: Block, end_block: Block) -> Dict[PortfolioAddress, Dict[str, PandableLedgerEntryList]]:
        """
        Returns a mapping containing all transactions, internal transfers, and token transfers to or from each wallet in your portfolio.

        :param start_block: The starting block number.
        :type start_block: Block
        :param end_block: The ending block number.
        :type end_block: Block
        :return: A dictionary mapping PortfolioAddress to their ledger entries.
        :rtype: Dict[PortfolioAddress, Dict[str, PandableLedgerEntryList]]
        """
        return await a_sync.gather({address: address.all(start_block, end_block, sync=False) for address in self.portfolio})

    # Pandas
    
    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block, full: bool = False) -> DataFrame:
        """
        Returns a DataFrame containing all transactions, internal transfers, and token transfers to or from any wallet in your portfolio.

        :param start_block: The starting block number.
        :type start_block: Block
        :param end_block: The ending block number.
        :type end_block: Block
        :param full: Whether to include all columns or a subset, defaults to False.
        :type full: bool
        :return: A DataFrame with the ledger entries.
        :rtype: DataFrame
        """
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
