"""
This module provides the core functionality for handling portfolio ledger entries, 
which include transactions, token transfers, and internal transfers for Ethereum addresses.

Key features:
- Supports fetching portfolio-wide Ethereum transaction and token transfer history.
- Organizes ledger entries by address and supports fetching data for specific block ranges.
- Provides asynchronous operations for improved performance.
- Deduplicates and cleans ledger data before returning them as DataFrames.

Main Classes and Functions:
- :class:`~eth_portfolio._ledgers.PortfolioLedgerBase`: Base class for managing portfolio-wide ledger entries.
- :class:`~eth_portfolio._ledgers.PortfolioTransactionsLedger`: Ledger for Ethereum transactions.
- :class:`~eth_portfolio._ledgers.PortfolioTokenTransfersLedger`: Ledger for ERC20 token transfers.
- :class:`~eth_portfolio._ledgers.PortfolioInternalTransfersLedger`: Ledger for internal transfers between Ethereum addresses.

Module-Wide Example:
    This example demonstrates how to use the module to fetch transaction data from a portfolio.

    >>> from eth_portfolio.portfolio import Portfolio
    >>> from eth_portfolio._ledgers import PortfolioTransactionsLedger
    >>> my_portfolio = Portfolio(addresses=["0x1234...", "0xABCD..."])
    >>> transactions_ledger = PortfolioTransactionsLedger(portfolio=my_portfolio)
    >>> df = await transactions_ledger.df(start_block=1000000, end_block=1100000)
    >>> print(df)
"""

import asyncio
import logging
from typing import (TYPE_CHECKING, AsyncIterator, Dict, Generic, Tuple,
                    TypeVar, Union)

import a_sync
from pandas import DataFrame, concat  # type: ignore
from y.datatypes import Address, Block

from eth_portfolio._decorators import set_end_block_if_none
from eth_portfolio._ledgers.address import (AddressLedgerBase,
                                            InternalTransfersList,
                                            TokenTransfersList,
                                            TransactionsList, _LedgerEntryList)
from eth_portfolio._utils import _AiterMixin, _unpack_indicies
from eth_portfolio.structs import Transaction, InternalTransfer, TokenTransfer

if TYPE_CHECKING:
    from eth_portfolio.portfolio import Portfolio

logger = logging.getLogger(__name__)

T = TypeVar('T')

class PortfolioLedgerBase(a_sync.ASyncGenericBase, _AiterMixin[T], Generic[_LedgerEntryList, T]):
    """
    The :class:`~eth_portfolio._ledgers.PortfolioLedgerBase` class provides
    common methods for fetching and cleaning ledger entries across Ethereum addresses
    in a portfolio. This is a base class for managing portfolio-wide ledger operations.

    Attributes:
        property_name: The name of the ledger property (e.g., 'transactions', 'token_transfers', etc.).
        portfolio: The portfolio containing the addresses.
        object_caches: A dictionary mapping Ethereum addresses to their respective address ledgers.

    Example:
        >>> ledger = PortfolioLedgerBase(portfolio=my_portfolio)
    """

    property_name: str

    def __init__(self, portfolio: "Portfolio"): # type: ignore
        """
        Initializes the :class:`~eth_portfolio._ledgers.PortfolioLedgerBase` class.

        Args:
            portfolio: The portfolio containing the Ethereum addresses.

        Raises:
            AssertionError: If the subclass does not define a `property_name`.

        Example:
            >>> ledger = PortfolioLedgerBase(portfolio=my_portfolio)
        """
        assert hasattr(self, "property_name"), "Subclasses must define a property_name"
        self.object_caches: Dict[Address, AddressLedgerBase[_LedgerEntryList, T]] = {address.address: getattr(address, self.property_name) for address in portfolio}
        self.portfolio = portfolio

    @property
    def _start_block(self) -> int:
        """Returns the starting block for the portfolio."""
        return self.portfolio._start_block
    
    def _get_and_yield(self, start_block: int, end_block: int) -> AsyncIterator[T]:
        """
        Yields ledger entries for each address in the portfolio for the specified block range.

        Args:
            start_block: The starting block for the ledger query.
            end_block: The ending block for the ledger query.

        Example:
            >>> async for entry in ledger._get_and_yield(start_block=1000000, end_block=1100000):
            >>>     print(entry)
        """
        return a_sync.as_yielded(*[getattr(address, self.property_name)[start_block: end_block] for address in self.portfolio])
    
    @property
    def asynchronous(self) -> bool:
        """Returns `True` if the portfolio associated with this ledger is asynchronous, `False` if not."""
        return self.portfolio.asynchronous
    
    @set_end_block_if_none
    async def get(self, start_block: Block, end_block: Block) -> Dict[Address, _LedgerEntryList]:
        """
        Asynchronously fetches ledger entries for the portfolio addresses within a block range.

        Args:
            start_block: The starting block for the query.
            end_block: The ending block for the query.

        Example:
            >>> ledger_entries = await ledger.get(start_block=1000000, end_block=1100000)
            >>> print(ledger_entries)
        """
        return await a_sync.gather({
            address: cache.get(start_block, end_block, sync=False)
            for address, cache in self.object_caches.items()
        })
    
    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block) -> DataFrame:
        """
        Returns a DataFrame with all entries for this ledger, deduplicated and cleaned up.

        NOTE: Override this method if you want to do something special with the dataframe

        Args:
            start_block: The starting block for the query.
            end_block: The ending block for the query.

        Example:
            >>> df = await ledger.df(start_block=1000000, end_block=1100000)
            >>> print(df)
        """
        df = await self._df_base(start_block, end_block)
        if len(df) > 0:
            df = self._cleanup_df(df)
        return df
    
    async def _df_base(self, start_block: Block, end_block: Block) -> DataFrame:
        """
        Fetches the raw ledger data and returns it as a DataFrame.

        Args:
            start_block: The starting block for the query.
            end_block: The ending block for the query.

        Example:
            >>> df_base = await ledger._df_base(start_block=1000000, end_block=1100000)
            >>> print(df_base)
        """
        data: Dict[Address, _LedgerEntryList] = await self.get(start_block, end_block, sync=False)
        df = concat(pandable.df for pandable in data.values())
        return df

    @classmethod
    def _deduplicate_df(cls, df: DataFrame) -> DataFrame:
        """
        Deduplicate the dataframe so transfers sending crypto to yourself are not double counted
        NOTE: This can be overridden if needed.

        # If there is a value of list type in the DataFrame, it must be converted to a string for comparison.

        Args:
            df: The DataFrame to deduplicate.

        Example:
            >>> deduped_df = ledger._deduplicate_df(df)
            >>> print(deduped_df)
        """
        return df.loc[df.astype(str).drop_duplicates().index]

    @classmethod
    def _cleanup_df(cls, df: DataFrame) -> DataFrame:
        """
        Cleans up the DataFrame by deduplicating and sorting it by block number.

        Args:
            df: The DataFrame to clean up.

        Example:
            >>> cleaned_df = ledger._cleanup_df(df)
            >>> print(cleaned_df)
        """
        df = cls._deduplicate_df(df)
        return df.sort_values(['blockNumber']).reset_index(drop=True)
    
class PortfolioTransactionsLedger(PortfolioLedgerBase[TransactionsList, Transaction]):
    """
    The :class:`~eth_portfolio._ledgers.PortfolioTransactionsLedger` class manages Ethereum 
    transaction entries in a portfolio. It handles fetching and organizing transactions 
    across multiple addresses in a portfolio.

    Example:
        >>> ledger = PortfolioTransactionsLedger(portfolio=my_portfolio)
        >>> df = await ledger.df(start_block=10000000, end_block=12000000)
        >>> print(df)
    """
    property_name = "transactions"

class PortfolioTokenTransfersLedger(PortfolioLedgerBase[TokenTransfersList, TokenTransfer]):
    """
    The :class:`~eth_portfolio._ledgers.PortfolioTokenTransfersLedger` class manages ERC20 token 
    transfer entries in a portfolio. It handles fetching and organizing ERC20 token transfers 
    across multiple addresses in a portfolio.

    Example:
        >>> ledger = PortfolioTokenTransfersLedger(portfolio=my_portfolio)
        >>> df = await ledger.df(start_block=10000000, end_block=12000000)
        >>> print(df)
    """
    property_name = "token_transfers"

class PortfolioInternalTransfersLedger(PortfolioLedgerBase[InternalTransfersList, InternalTransfer]):
    """
    The :class:`~eth_portfolio._ledgers.PortfolioInternalTransfersLedger` class manages internal 
    transfer entries in a portfolio. It handles fetching and organizing internal transfers 
    across multiple addresses in a portfolio and customizes the DataFrame output for internal transfers.

    Example:
        >>> ledger = PortfolioInternalTransfersLedger(portfolio=my_portfolio)
        >>> df = await ledger.df(start_block=10000000, end_block=12000000)
        >>> print(df)
    """
    property_name = "internal_transfers"

    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block) -> DataFrame:
        """
        Returns a DataFrame containing all internal transfers to or from any of the wallets in your portfolio.

        Args:
            start_block: The starting block for the query.
            end_block: The ending block for the query.

        Example:
            >>> df = await ledger.df(start_block=10000000, end_block=12000000)
            >>> print(df)
        """
        df = await self._df_base(start_block, end_block)
        if len(df) > 0:
            df.rename(columns={'transactionHash': 'hash', 'transactionPosition': 'transactionIndex'}, inplace=True)
            df = self._cleanup_df(df)
        return df

    @classmethod
    def _deduplicate_df(cls, df: DataFrame) -> DataFrame:
        #We cant use drop_duplicates when one of the columns, `traceAddress`, contains lists.
        #We must first convert the lists to strings
        """
        Deduplicates the DataFrame, handling columns with list types (e.g., `traceAddress`).

        Args:
            df: The DataFrame to deduplicate.

        Example:
            >>> deduped_df = PortfolioInternalTransfersLedger._deduplicate_df(df)
            >>> print(deduped_df)
        """
        df = df.reset_index(drop=True)
        return df.loc[df.astype(str).drop_duplicates().index]
