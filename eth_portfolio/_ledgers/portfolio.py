"""
This module provides the core functionality for managing portfolio-wide ledger entries, 
including Ethereum transactions, token transfers, and internal transfers across multiple addresses.

It plays a crucial role in the eth-portfolio ecosystem by:
- Aggregating portfolio-wide data across multiple Ethereum addresses.
- Serving as an abstraction layer between address-specific ledgers and overall portfolio management.
- Providing standardized data processing and presentation methods.
- Implementing asynchronous operations for efficient data retrieval and processing.
- Offering extensibility for different types of ledger entries.
- Ensuring data accuracy through deduplication, especially for internal transfers.
- Supporting block range queries for time-specific analysis.

Key features:
- Fetches and aggregates portfolio-wide Ethereum transaction, token transfer, and internal transfer history.
- Organizes ledger entries by address and supports querying data for specific block ranges.
- Implements asynchronous operations for improved performance.
- Deduplicates and cleans ledger data before returning them as DataFrames.

Main Classes:
- :class:`~eth_portfolio._ledgers.PortfolioLedgerBase`: Abstract base class for managing portfolio-wide ledger entries.
- :class:`~eth_portfolio._ledgers.PortfolioTransactionsLedger`: Ledger for Ethereum transactions across the portfolio.
- :class:`~eth_portfolio._ledgers.PortfolioTokenTransfersLedger`: Ledger for ERC20 token transfers across the portfolio.
- :class:`~eth_portfolio._ledgers.PortfolioInternalTransfersLedger`: Ledger for internal transfers between Ethereum addresses in the portfolio.

Module-Wide Example:
    This example demonstrates how to use the module to fetch transaction data for a portfolio.

    >>> from eth_portfolio.portfolio import Portfolio
    >>> from eth_portfolio._ledgers import PortfolioTransactionsLedger
    >>> ledger = PortfolioTransactionsLedger(portfolio=Portfolio(addresses=["0x1234...", "0xABCD..."]))
    >>> df = await ledger.df(start_block=1000000, end_block=1100000)
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
    an abstract base for fetching and processing ledger entries across multiple Ethereum addresses
    in a portfolio. It defines common methods and properties for portfolio-wide ledger operations.

    This class is a key component in the eth-portfolio ecosystem, serving as:
    - An abstraction layer between address-specific ledgers and portfolio-wide data management.
    - A foundation for standardized data processing across different ledger types.
    - A base for implementing asynchronous operations for efficient data retrieval.

    Attributes:
        property_name: The name of the ledger property (e.g., 'transactions', 'token_transfers', 'internal_transfers').
        portfolio: The portfolio containing the addresses to be queried.
        object_caches: A dictionary mapping Ethereum addresses to their respective address-specific ledgers.

    Example:
        >>> ledger = PortfolioLedgerBase(portfolio=Portfolio(addresses=["0x1234...", "0xABCD..."]))
    """

    property_name: str

    def __init__(self, portfolio: "Portfolio"): # type: ignore
        """
        Initializes the :class:`~eth_portfolio._ledgers.PortfolioLedgerBase` class.

        This constructor is crucial in the eth-portfolio ecosystem as it:
        - Sets up the foundation for portfolio-wide ledger management.
        - Establishes connections between portfolio addresses and their respective ledgers.
        - Ensures proper initialization for subclasses handling different ledger types.

        Args:
            portfolio: The :class:`~eth_portfolio.portfolio.Portfolio` instance containing the Ethereum addresses to be managed.

        Raises:
            AssertionError: If the subclass does not define a `property_name`, which is essential
                            for identifying the specific ledger type (e.g., transactions, token transfers).

        Example:
            >>> from eth_portfolio.portfolio import Portfolio
            >>> from eth_portfolio._ledgers import PortfolioTransactionsLedger
            >>> ledger = PortfolioTransactionsLedger(portfolio=Portfolio(addresses=["0x1234...", "0xABCD..."]))

        Note:
            Subclasses must define a `property_name` attribute to specify the type of ledger
            they manage (e.g., 'transactions', 'token_transfers', 'internal_transfers').
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
        Asynchronously yields ledger entries for each address in the portfolio for the specified block range.

        This method is crucial for efficient data retrieval across multiple addresses, as it:
        - Utilizes asynchronous iteration to process addresses concurrently.
        - Reduces memory usage by yielding entries one at a time.

        Args:
            start_block: The starting block for the ledger query.
            end_block: The ending block for the ledger query.

        Yields:
            Individual ledger entries of type T for each address in the portfolio.

        Example:
            >>> async for entry in ledger._get_and_yield(start_block=1000000, end_block=1100000):
            ...     print(entry)
        """
        return a_sync.as_yielded(*[getattr(address, self.property_name)[start_block: end_block] for address in self.portfolio])
    
    @property
    def asynchronous(self) -> bool:
        """Returns `True` if the portfolio associated with this ledger is asynchronous, `False` if not."""
        return self.portfolio.asynchronous
    
    @set_end_block_if_none
    async def get(self, start_block: Block, end_block: Block) -> Dict[Address, _LedgerEntryList]:
        """
        Asynchronously fetches ledger entries for all portfolio addresses within the specified block range.

        This method is crucial in the eth-portfolio ecosystem as it:
        - Aggregates ledger data across multiple addresses efficiently.
        - Utilizes asynchronous operations for improved performance.
        - Provides a comprehensive view of portfolio activity within a given time frame.

        Args:
            start_block: The starting block number for the query.
            end_block: The ending block number for the query.

        Returns:
            Dict: A dictionary mapping each portfolio address to its
            corresponding ledger entries within the specified block range.

        Example:
            >>> ledger = PortfolioTransactionsLedger(portfolio=portfolio)
            >>> ledger_entries = await ledger.get(start_block=1000000, end_block=1100000)
            >>> print("\n".join(f"Address {addr}: {len(entries)} entries" for addr, entries in ledger_entries.items()))

        Note:
            The @set_end_block_if_none decorator ensures that if end_block is not provided,
            it defaults to the latest block.
        """
        return await a_sync.gather({
            address: cache.get(start_block, end_block, sync=False)
            for address, cache in self.object_caches.items()
        })
    
    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block) -> DataFrame:
        """
        Returns a DataFrame containing all entries for this ledger type across the portfolio,
        deduplicated and cleaned up.

        This method is essential in the ecosystem for providing standardized, clean data
        for further analysis and reporting.

        NOTE: Subclasses may override this method for type-specific DataFrame processing.

        Args:
            start_block: The starting block for the query.
            end_block: The ending block for the query.

        Returns:
            A DataFrame containing processed ledger entries.

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
        Fetches and concatenates raw ledger data for all addresses in the portfolio.

        This method is a crucial part of the data processing pipeline, as it:
        - Retrieves ledger entries for the specified block range across all portfolio addresses.
        - Combines the data from multiple addresses into a single DataFrame.
        - Serves as the foundation for further data cleaning and analysis.

        Args:
            start_block: The starting block number for the query.
            end_block: The ending block number for the query.

        Returns:
            DataFrame: A concatenated DataFrame containing raw ledger entries from all addresses.

        Example:
            >>> df_base = await ledger._df_base(start_block=1000000, end_block=1100000)
            >>> print(f"Total entries: {len(df_base)}", df_base.head(), sep="\n")

        Note:
            This method returns raw data that may contain duplicates or require further processing.
            For cleaned and deduplicated data, use the `df()` method instead.
        """
        data: Dict[Address, _LedgerEntryList] = await self.get(start_block, end_block, sync=False)
        df = concat(pandable.df for pandable in data.values())
        return df

    @classmethod
    def _deduplicate_df(cls, df: DataFrame) -> DataFrame:
        """
        Deduplicate the DataFrame to prevent double-counting of transfers within the portfolio.

        NOTE: This can be overridden if needed.

        This method is crucial for:
        - Ensuring accurate portfolio analysis by removing duplicate entries.
        - Handling cases where transfers between owned addresses appear multiple times.

        Args:
            df: The DataFrame to deduplicate.

        Returns:
            DataFrame: A deduplicated version of the input DataFrame.

        Note:
            - This method can be overridden in subclasses if needed.
            - If the DataFrame contains columns with list-type values, they are converted to strings for comparison.

        Example:
            >>> original_df = pd.DataFrame(...)  # Your original DataFrame
            >>> deduped_df = PortfolioLedgerBase._deduplicate_df(original_df)
            >>> print(f"Original rows: {len(original_df)}, Deduplicated rows: {len(deduped_df)}")
        """
        return df.loc[df.astype(str).drop_duplicates().index]

    @classmethod
    def _cleanup_df(cls, df: DataFrame) -> DataFrame:
        """
        Cleans up the DataFrame by deduplicating and sorting it by block number.

        This method is essential for ensuring the accuracy and consistency of the ledger data by:
        - Removing duplicate entries to prevent double-counting.
        - Sorting the entries by block number for chronological analysis.

        Args:
            df: The DataFrame to clean up.

        Returns:
            DataFrame: A cleaned and deduplicated DataFrame sorted by block number.

        Example:
            >>> cleaned_df = ledger._cleanup_df(df)
            >>> print(cleaned_df)
        """
        df = cls._deduplicate_df(df)
        return df.sort_values(['blockNumber']).reset_index(drop=True)
    
class PortfolioTransactionsLedger(PortfolioLedgerBase[TransactionsList, Transaction]):
    """
    The :class:`~eth_portfolio._ledgers.PortfolioTransactionsLedger` class manages Ethereum 
    transaction entries across all addresses in a portfolio. It aggregates and processes
    transactions for the entire portfolio within specified block ranges.

    In the eth-portfolio ecosystem, this class is essential for:
    - Providing a comprehensive view of all Ethereum transactions across multiple addresses.
    - Supporting portfolio-wide analysis and reporting of transaction history.
    - Enabling efficient querying of transaction data for specific time periods or block ranges.

    Example:
        >>> ledger = PortfolioTransactionsLedger(portfolio=Portfolio(addresses=["0x1234...", "0xABCD..."]))
        >>> df = await ledger.df(start_block=10000000, end_block=12000000)
        >>> print(df)
    """
    property_name = "transactions"

class PortfolioTokenTransfersLedger(PortfolioLedgerBase[TokenTransfersList, TokenTransfer]):
    """
    The :class:`~eth_portfolio._ledgers.PortfolioTokenTransfersLedger` class manages ERC20 token 
    transfer entries across all addresses in a portfolio. It aggregates and processes
    token transfers for the entire portfolio within specified block ranges.

    In the eth-portfolio ecosystem, this class is crucial for:
    - Tracking all ERC20 token movements across multiple addresses in a portfolio.
    - Facilitating token balance calculations and portfolio valuation.
    - Supporting analysis of token transfer patterns and history.

    Example:
        >>> ledger = PortfolioTokenTransfersLedger(portfolio=Portfolio(addresses=["0x1234...", "0xABCD..."]))
        >>> df = await ledger.df(start_block=10000000, end_block=12000000)
        >>> print(df)
    """
    property_name = "token_transfers"

class PortfolioInternalTransfersLedger(PortfolioLedgerBase[InternalTransfersList, InternalTransfer]):
    """
    The :class:`~eth_portfolio._ledgers.PortfolioInternalTransfersLedger` class manages internal 
    transfer entries across all addresses in a portfolio. It aggregates and processes internal transfers 
    for the entire portfolio within specified block ranges, and customizes the DataFrame output
    for internal transfers by renaming certain columns.

    In the eth-portfolio ecosystem, this class plays a vital role in:
    - Tracking internal Ethereum transfers between addresses within the same portfolio.
    - Providing insights into complex transactions that involve multiple internal transfers.
    - Supporting accurate portfolio analysis by deduplicating internal transfer data.

    Example:
        >>> ledger = PortfolioInternalTransfersLedger(portfolio=Portfolio(addresses=["0x1234...", "0xABCD..."]))
        >>> df = await ledger.df(start_block=10000000, end_block=12000000)
        >>> print(df)
    """
    property_name = "internal_transfers"

    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block) -> DataFrame:
        """
        Returns a DataFrame containing all internal transfers to or from any of the addresses in the portfolio.
        This method customizes the output by renaming certain columns specific to internal transfers.

        In the ecosystem, this method is crucial for:
        - Providing a standardized view of internal transfers across the portfolio.
        - Supporting analysis of complex transactions involving multiple internal transfers.

        Args:
            start_block: The starting block for the query.
            end_block: The ending block for the query.

        Returns:
            A DataFrame containing processed internal transfer entries.

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
        This method converts list-type columns to strings before deduplication to ensure proper comparison.

        This deduplication is essential in the ecosystem for:
        - Ensuring accurate portfolio analysis by removing duplicate entries.
        - Handling the complexities of internal transfers that may appear multiple times.

        Args:
            df: The DataFrame to deduplicate.

        Returns:
            A deduplicated DataFrame.

        Example:
            >>> deduped_df = PortfolioInternalTransfersLedger._deduplicate_df(df)
            >>> print(deduped_df)
        """
        df = df.reset_index(drop=True)
        return df.loc[df.astype(str).drop_duplicates().index]
