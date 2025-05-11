"""
This module defines the :class:`~eth_portfolio.Portfolio` and :class:`~eth_portfolio.PortfolioWallets` classes, which are used to manage and interact with a collection of :class:`~eth_portfolio.address.PortfolioAddress` objects.
It also includes the :class:`~eth_portfolio.PortfolioLedger` class for handling transactions, internal transfers, and token transfers associated with the portfolio.
The :class:`~eth_portfolio.Portfolio` class leverages the `a_sync` library to support both synchronous and asynchronous operations. This allows it to efficiently gather data, perform portfolio-related tasks, and handle network calls without blocking, thus improving the overall responsiveness and performance of portfolio operations.

This file is part of a larger system that includes modules for handling portfolio addresses, ledger entries, and other related tasks.
"""

import logging
from functools import wraps
from typing import Any, AsyncIterator, Dict, Iterable, Iterator, List, Optional, Tuple, Union

import a_sync
from a_sync import igather
from a_sync.a_sync import ASyncFunction
from brownie import web3
from checksum_dict import ChecksumAddressDict
from pandas import DataFrame, concat  # type: ignore
from web3 import Web3
from y.datatypes import Address, Block

from eth_portfolio import _argspec
from eth_portfolio._decorators import set_end_block_if_none
from eth_portfolio._ledgers.address import PandableLedgerEntryList
from eth_portfolio._ledgers.portfolio import (
    PortfolioInternalTransfersLedger,
    PortfolioLedgerBase,
    PortfolioTokenTransfersLedger,
    PortfolioTransactionsLedger,
)
from eth_portfolio._utils import _LedgeredBase
from eth_portfolio.address import PortfolioAddress
from eth_portfolio.constants import ADDRESSES
from eth_portfolio.structs import LedgerEntry
from eth_portfolio.typing import Addresses, PortfolioBalances

logger = logging.getLogger(__name__)


class PortfolioWallets(Iterable[PortfolioAddress], Dict[Address, PortfolioAddress]):  # type: ignore [misc]
    """
    A container that holds all :class:`~eth_portfolio.address.PortfolioAddress` objects for a specific :class:`~eth_portfolio.Portfolio`.

    Works like a ``Dict[Address, PortfolioAddress]`` except when you iterate you get the values instead of the keys.
    You should not initialize these. They are created automatically during :class:`~eth_portfolio.Portfolio` initialization.

    Attributes:
        _wallets: A checksummed dictionary of :class:`~eth_portfolio.address.PortfolioAddress` objects.
    """

    _wallets: ChecksumAddressDict[PortfolioAddress]

    def __init__(
        self,
        addresses: Iterable[Address],
        start_block: Block,
        load_prices: bool,
        num_workers_transactions: int,
    ) -> None:
        """
        Initialize a PortfolioWallets instance.

        Args:
            portfolio: The :class:`~eth_portfolio.Portfolio` instance to which this wallet belongs.
            addresses: An iterable of addresses to be included in the portfolio.
        """
        self._wallets: ChecksumAddressDict[PortfolioAddress] = ChecksumAddressDict()
        """
        A checksummed dictionary of :class:`~eth_portfolio.address.PortfolioAddress` objects.

        Type: 
            ChecksumAddressDict[PortfolioAddress]
        """

        for address in addresses:
            self._wallets[address] = PortfolioAddress(
                address,
                start_block,
                load_prices,
                num_workers_transactions=num_workers_transactions,
                asynchronous=portfolio.asynchronous,
            )

    def __repr__(self) -> str:
        """
        Return a string representation of the PortfolioWallets instance.

        Returns:
            String representation of the instance.
        """
        return f"<{type(self).__name__} wallets={list(self._wallets.values())}>"

    def __contains__(self, address: Union[Address, PortfolioAddress]) -> bool:
        """
        Check if an address is in the portfolio wallets.

        Args:
            address: The address to check.

        Returns:
            True if the address is in the wallets, False otherwise.
        """
        return address in self._wallets

    def __getitem__(self, address: Address) -> PortfolioAddress:
        """
        Get the :class:`~eth_portfolio.address.PortfolioAddress` object for a given address.

        Args:
            address: The address to look up.

        Returns:
            PortfolioAddress: The :class:`~eth_portfolio.address.PortfolioAddress` object.
        """
        return self._wallets[address]

    def __iter__(self) -> Iterator[PortfolioAddress]:
        """
        Iterate over the :class:`~eth_portfolio.address.PortfolioAddress` objects in the wallets.

        Returns:
            Iterator[PortfolioAddress]: An iterator over :class:`~eth_portfolio.address.PortfolioAddress` objects.
        """
        yield from self._wallets.values()

    def __len__(self) -> int:
        """
        Get the number of :class:`~eth_portfolio.address.PortfolioAddress` objects in the wallets.

        Returns:
            The number of :class:`~eth_portfolio.address.PortfolioAddress` objects.
        """
        return len(self._wallets)

    def __bool__(self) -> bool:
        """
        Check if the wallets contain any addresses.

        Returns:
            True if there are addresses in the wallets, False otherwise.
        """
        return bool(self._wallets)

    def keys(self) -> Iterable[Address]:
        """
        Get the keys (addresses) of the wallets.

        Returns:
            Iterable[Address]: An iterable of addresses.
        """
        return self._wallets.keys()

    def values(self) -> Iterable[PortfolioAddress]:
        """
        Get the values (:class:`~eth_portfolio.address.PortfolioAddress` objects) of the wallets.

        Returns:
            Iterable[PortfolioAddress]: An iterable of :class:`~eth_portfolio.address.PortfolioAddress` objects.
        """
        return self._wallets.values()

    def items(self) -> Iterable[Tuple[Address, PortfolioAddress]]:
        """
        Get the items (address, :class:`~eth_portfolio.address.PortfolioAddress` pairs) of the wallets.

        Returns:
            Iterable[Tuple[Address, PortfolioAddress]]: An iterable of (address, :class:`~eth_portfolio.address.PortfolioAddress`) tuples.
        """
        return self._wallets.items()


_DEFAULT_LABEL = "your portfolio"


class Portfolio(a_sync.ASyncGenericBase):
    """
    Used to export information about a group of :class:`~eth_portfolio.address.PortfolioAddress` objects.

    - Has all attributes of a :class:`~eth_portfolio.address.PortfolioAddress`.
    - All calls to `function(*args, **kwargs)` will return `{address: PortfolioAddress(Address).function(*args, **kwargs)}`
    """

    label: str = _DEFAULT_LABEL
    """
    A label for the portfolio. Defaults to "your portfolio"
    """

    load_prices: bool = True
    """
    Whether to load prices. Defaults to True.
    """

    asynchronous: bool = False
    """
    Whether to use asynchronous operations. Defaults to False.
    """

    _start_block = 0
    """
    The starting block number. Defaults to 0.
    """

    def __init__(
        self,
        addresses: Addresses,
        start_block: int = 0,
        label: str = _DEFAULT_LABEL,
        load_prices: bool = True,
        num_workers_transactions: int = 1000,
        asynchronous: bool = False,
    ) -> None:
        """
        Initialize a Portfolio instance.

        Args:
            addresses: The addresses to include in the portfolio.
        Examples:
            >>> portfolio = Portfolio(addresses=["0xAddress1", "0xAddress2"])
            >>> print(portfolio)
        """
        if not isinstance(start_block, int):
            raise TypeError(f"`start_block` must be an integer, not {type(start_block)}")
        if start_block < 0:
            raise ValueError("`start_block` must be >= 0")
        super().__init__()

        if start_block:
            self._start_block = start_block

        assert isinstance(label, str), f"`label` must be a string, you passed {type(label)}"
        if label != _DEFAULT_LABEL:
            self.label = label

        if load_prices is False:
            self.load_prices = False
        elif load_prices is not True:
            raise TypeError(f"`load_prices` must be a boolean, you passed {type(load_prices)}")

        if asynchronous is True:
            self.asynchronous = True
        elif asynchronous is not False:
            raise TypeError(f"`asynchronous` must be a boolean, you passed {type(asynchronous)}")

        if isinstance(addresses, str):
            addresses = [addresses]
        elif not isinstance(addresses, Iterable):
            raise TypeError(f"`addresses` must be an iterable, not {type(addresses)}")

        self.addresses = PortfolioWallets(
            addresses, start_block, load_prices, num_workers_transactions
        )
        """
        A container for the :class:`~eth_portfolio.Portfolio`'s :class:`~eth_portfolio.address.PortfolioAddress` objects.
        
        Type: 
            :class:`~eth_portfolio.PortfolioWallets`
        
        Works like a ``Dict[Address, PortfolioAddress]`` except you get the values when you iterate instead of the keys.
        """

        self.ledger = PortfolioLedger(self)
        """
        A container for all of your fun taxable events.
        
        Type: 
            :class:`~eth_portfolio.PortfolioLedger`
        """

        self.w3: Web3 = web3
        """
        The `Web3` object which will be used to call your rpc for all read operations.
        
        Type: 
            :class:`~web3.Web3`
        """

    def __repr__(self) -> str:
        # NOTE: should we show addresses? for now we won't
        # string = f"{type(self).__name__}(addresses={list(map(str, self.addresses))}"
        string = f"{type(self).__name__}(label={self.label}"
        if self._start_block:
            string += f", start_block={self._start_block}"
        return string + f", load_prices={self.load_prices}, asynchronous={self.asynchronous})"

    def __repr__(self) -> str:
        # NOTE: should we show addresses? for now we won't
        # string = f"{type(self).__name__}(addresses={list(map(str, self.addresses))}"
        string = f"{type(self).__name__}(label={self.label}"
        if self._start_block:
            string += f", start_block={self._start_block}"
        return string + f", load_prices={self.load_prices}, asynchronous={self.asynchronous})"

    def __getitem__(self, key: Address) -> PortfolioAddress:
        """
        Get a :class:`~eth_portfolio.address.PortfolioAddress` by its key.

        Args:
            key: The address key.

        Returns:
            PortfolioAddress: The :class:`~eth_portfolio.address.PortfolioAddress` object.

        Example:
            >>> portfolio = Portfolio(addresses=["0xAddress1", "0xAddress2"])
            >>> address = portfolio["0xAddress1"]
            >>> print(address)
        """
        return self.addresses[key]

    def __iter__(self) -> Iterator[PortfolioAddress]:
        """
        Iterate over the :class:`~eth_portfolio.address.PortfolioAddress` objects.

        Returns:
            Iterator[PortfolioAddress]: An iterator over :class:`~eth_portfolio.address.PortfolioAddress` objects.

        Example:
            >>> portfolio = Portfolio(addresses=["0xAddress1", "0xAddress2"])
            >>> for address in portfolio:
            ...     print(address)
        """
        yield from self.addresses

    @property
    def transactions(self) -> PortfolioTransactionsLedger:
        """
        A container for all transactions to or from any of your :class:`~eth_portfolio.address.PortfolioAddress`.

        Returns:
            PortfolioTransactionsLedger: The :class:`~eth_portfolio._ledgers.portfolio.PortfolioTransactionsLedger` object.

        Example:
            >>> portfolio = Portfolio(addresses=["0xAddress1", "0xAddress2"])
            >>> transactions = portfolio.transactions
            >>> print(transactions)
        """
        return self.ledger.transactions

    @property
    def internal_transfers(self) -> PortfolioInternalTransfersLedger:
        """
        A container for all internal transfers to or from any of your :class:`~eth_portfolio.address.PortfolioAddress`.

        Returns:
            PortfolioInternalTransfersLedger: The :class:`~eth_portfolio._ledgers.portfolio.PortfolioInternalTransfersLedger` object.

        Example:
            >>> portfolio = Portfolio(addresses=["0xAddress1", "0xAddress2"])
            >>> internal_transfers = portfolio.internal_transfers
            >>> print(internal_transfers)
        """
        return self.ledger.internal_transfers

    @property
    def token_transfers(self) -> PortfolioTokenTransfersLedger:
        """
        A container for all token transfers to or from any of your :class:`~eth_portfolio.address.PortfolioAddress`.

        Returns:
            PortfolioTokenTransfersLedger: The :class:`~eth_portfolio._ledgers.portfolio.PortfolioTokenTransfersLedger` object.

        Example:
            >>> portfolio = Portfolio(addresses=["0xAddress1", "0xAddress2"])
            >>> token_transfers = portfolio.token_transfers
            >>> print(token_transfers)
        """
        return self.ledger.token_transfers

    async def describe(self, block: int) -> PortfolioBalances:
        """
        Returns a full snapshot of your portfolio at a given block.

        Args:
            block: The block number.

        Returns:
            PortfolioBalances: A snapshot of the portfolio balances.

        Example:
            >>> portfolio = Portfolio(addresses=["0xAddress1", "0xAddress2"])
            >>> balances = await portfolio.describe(block=1200000)
            >>> print(balances)
        """
        assert block
        return PortfolioBalances(
            await a_sync.gather(
                {address.address: address.describe(block, sync=False) for address in self}
            ),
            block=block,
        )

    async def sent(
        self,
        start_block: Optional[Block] = None,
        end_block: Optional[Block] = None,
        *,
        mem_cache: bool = True,
    ) -> AsyncIterator[LedgerEntry]:
        async for obj in self.ledger.sent(start_block, end_block, mem_cache=mem_cache):
            yield obj

    async def received(
        self,
        start_block: Optional[Block] = None,
        end_block: Optional[Block] = None,
        *,
        mem_cache: bool = True,
    ) -> AsyncIterator[LedgerEntry]:
        async for obj in self.ledger.received(start_block, end_block, mem_cache=mem_cache):
            yield obj


async_functions = {
    name: obj for name, obj in PortfolioAddress.__dict__.items() if isinstance(obj, ASyncFunction)
}
for func_name, func in async_functions.items():
    if not callable(getattr(PortfolioAddress, func_name)):
        raise RuntimeError(
            f"A PortfolioAddress object should not have a non-callable attribute suffixed with '_async'"
        )

    @a_sync.a_sync(default=func.default)
    @wraps(func)
    async def imported_func(self: Portfolio, *args: Any, **kwargs: Any) -> _argspec.get_return_type(getattr(PortfolioAddress, func_name)):  # type: ignore
        """
        Import an asynchronous function from :class:`~eth_portfolio.address.PortfolioAddress` to :class:`~eth_portfolio.Portfolio`.

        Args:
            self: The :class:`~eth_portfolio.Portfolio` instance.
            args: Positional arguments for the function.
            kwargs: Keyword arguments for the function.

        Returns:
            Any: The return type of the function.

        Example:
            >>> portfolio = Portfolio(addresses=["0xAddress1", "0xAddress2"])
            >>> result = await portfolio.some_async_function(*args, **kwargs)
            >>> print(result)
        """
        return await a_sync.gather(
            {address: func(address, *args, **kwargs, sync=False) for address in self}
        )

    setattr(Portfolio, func_name, imported_func)
    logger.debug("Ported %s from PortfolioAddress to Portfolio", func_name)


def _get_missing_cols_from_KeyError(e: KeyError) -> List[str]:
    """
    Extract missing column names from a KeyError.

    Args:
        e: The KeyError exception.

    Returns:
        A list of missing column names.
    """
    split = str(e).split("'")
    return [split[i * 2 + 1] for i in range(len(split) // 2)]


class PortfolioLedger(_LedgeredBase[PortfolioLedgerBase]):
    """
    A container for all transactions, internal transfers, and token transfers to or from any of the wallets in your :class:`~eth_portfolio.Portfolio`.
    """

    def __init__(self, portfolio: "Portfolio") -> None:
        """
        Initialize a PortfolioLedger instance.

        Args:
            portfolio: The :class:`~eth_portfolio.Portfolio` instance to which this ledger belongs.
        """
        super().__init__(portfolio._start_block)
        self.portfolio = portfolio
        """
        The :class:`~eth_portfolio.Portfolio` containing the wallets this ledger will pertain to.
        """
        self.transactions = PortfolioTransactionsLedger(portfolio)
        """
        A container for all transactions to or from any of your :class:`~eth_portfolio.address.PortfolioAddress`.
        """
        self.internal_transfers = PortfolioInternalTransfersLedger(portfolio)
        """
        A container for all internal transfers to or from any of your :class:`~eth_portfolio.address.PortfolioAddress`.
        """
        self.token_transfers = PortfolioTokenTransfersLedger(portfolio)
        """
        A container for all token transfers to or from any of your :class:`~eth_portfolio.address.PortfolioAddress`.
        """
        self.asynchronous = portfolio.asynchronous
        """
        True if default mode is async, False if sync.
        """

    async def all_entries(
        self, start_block: Block, end_block: Block
    ) -> Dict[PortfolioAddress, Dict[str, PandableLedgerEntryList]]:
        """
        Returns a mapping containing all transactions, internal transfers, and token transfers to or from each wallet in your portfolio.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Returns:
            Dict[PortfolioAddress, Dict[str, PandableLedgerEntryList]]: A dictionary mapping :class:`~eth_portfolio.address.PortfolioAddress` to their ledger entries.

        Example:
            >>> portfolio = Portfolio(addresses=["0xAddress1", "0xAddress2"])
            >>> entries = await portfolio.ledger.all_entries(start_block=1000000, end_block=1100000)
            >>> print(entries)
        """
        return await a_sync.gather(
            {address: address.all(start_block, end_block, sync=False) for address in self.portfolio}
        )

    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block, full: bool = False) -> DataFrame:
        """
        Returns a DataFrame containing all transactions, internal transfers, and token transfers to or from any wallet in your portfolio.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.
            full (optional): Whether to include all columns or a subset. Defaults to False.

        Returns:
            DataFrame: A DataFrame with the ledger entries.

        Example:
            >>> portfolio = Portfolio(addresses=["0xAddress1", "0xAddress2"])
            >>> df = await portfolio.ledger.df(start_block=1000000, end_block=1100000)
            >>> print(df)
        """
        df = concat(
            await igather(ledger.df(start_block, end_block, sync=False) for ledger in self._ledgers)
        )

        # Reorder columns
        while True:
            try:
                if full:
                    df = df[
                        [
                            "chainId",
                            "blockNumber",
                            "blockHash",
                            "transactionIndex",
                            "hash",
                            "log_index",
                            "nonce",
                            "from",
                            "to",
                            "token",
                            "token_address",
                            "value",
                            "price",
                            "value_usd",
                            "gas",
                            "gasPrice",
                            "gasUsed",
                            "maxFeePerGas",
                            "maxPriorityFeePerGas",
                            "type",
                            "callType",
                            "traceAddress",
                            "subtraces",
                            "output",
                            "error",
                            "result",
                            "address",
                            "code",
                            "init",
                            "r",
                            "s",
                            "v",
                            "input",
                        ]
                    ]
                else:
                    df = df[
                        [
                            "chainId",
                            "blockNumber",
                            "hash",
                            "from",
                            "to",
                            "token",
                            "token_address",
                            "value",
                            "price",
                            "value_usd",
                            "gas",
                            "gasPrice",
                            "gasUsed",
                            "maxFeePerGas",
                            "maxPriorityFeePerGas",
                            "type",
                            "callType",
                            "traceAddress",
                            "subtraces",
                            "output",
                            "error",
                            "result",
                            "address",
                        ]
                    ]
                    df = df[df["value"] != 0]
                break
            except KeyError as e:
                for column in _get_missing_cols_from_KeyError(e):
                    df[column] = None

        sort_cols = (
            ["blockNumber", "transactionIndex", "log_index"] if full else ["blockNumber", "hash"]
        )

        try:
            return df.sort_values(sort_cols).reset_index(drop=True)
        except KeyError:
            logger.error(df)
            logger.error(df.columns)
            raise

    async def sent(
        self,
        start_block: Optional[Block] = None,
        end_block: Optional[Block] = None,
        *,
        mem_cache: bool = True,
    ) -> AsyncIterator[LedgerEntry]:
        portfolio_addresses = set(self.portfolio.addresses.keys())
        async for obj in self._get_and_yield(start_block or 0, end_block, mem_cache):
            if (
                obj.value
                and obj.from_address in portfolio_addresses
                and obj.to_address not in portfolio_addresses
            ):
                yield obj

    async def received(
        self,
        start_block: Optional[Block] = None,
        end_block: Optional[Block] = None,
        *,
        mem_cache: bool = True,
    ) -> AsyncIterator[LedgerEntry]:
        portfolio_addresses = set(self.portfolio.addresses.keys())
        async for obj in self._get_and_yield(start_block or 0, end_block, mem_cache):
            if (
                obj.value
                and obj.to_address in portfolio_addresses
                and obj.from_address not in portfolio_addresses
            ):
                yield obj


# Use this var for a convenient way to set up your portfolio using env vars.
portfolio = Portfolio(ADDRESSES)
