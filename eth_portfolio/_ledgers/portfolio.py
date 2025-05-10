import logging
from typing import TYPE_CHECKING, AsyncIterator, Dict, Generic, Optional, TypeVar

import a_sync
from pandas import DataFrame, concat  # type: ignore
from y.datatypes import Address, Block

from eth_portfolio._decorators import set_end_block_if_none
from eth_portfolio._ledgers.address import (
    AddressLedgerBase,
    InternalTransfersList,
    TokenTransfersList,
    TransactionsList,
    _LedgerEntryList,
)
from eth_portfolio._utils import _AiterMixin
from eth_portfolio.structs import InternalTransfer, TokenTransfer, Transaction

if TYPE_CHECKING:
    from eth_portfolio.portfolio import Portfolio

logger = logging.getLogger(__name__)

T = TypeVar("T")


class PortfolioLedgerBase(a_sync.ASyncGenericBase, _AiterMixin[T], Generic[_LedgerEntryList, T]):
    property_name: str
    object_caches: Dict[Address, AddressLedgerBase[_LedgerEntryList, T]]

    def __init__(self, portfolio: "Portfolio"):  # type: ignore
        assert hasattr(self, "property_name"), "Subclasses must define a property_name"
        self.object_caches = {
            address.address: getattr(address, self.property_name) for address in portfolio
        }
        self.portfolio = portfolio
        super().__init__()

    @property
    def _start_block(self) -> int:
        """Returns the start block for analysis of this portfolio."""
        return self.portfolio._start_block

    def _get_and_yield(self, start_block: int, end_block: int, mem_cache: bool) -> AsyncIterator[T]:
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
        aiterators = [
            getattr(address, self.property_name)._get_and_yield(start_block, end_block, mem_cache)
            for address in self.portfolio
        ]
        return a_sync.as_yielded(*aiterators)

    @property
    def asynchronous(self) -> bool:
        """Returns `True` if the portfolio associated with this ledger is asynchronous, `False` if not."""
        return self.portfolio.asynchronous

    @set_end_block_if_none
    async def get(self, start_block: Block, end_block: Block) -> Dict[Address, _LedgerEntryList]:
        """
        Fetches ledger entries for all portfolio addresses within the specified block range.

        Args:
            start_block: The starting block number for the query.
            end_block: The ending block number for the query.

        Returns:
            A dictionary mapping each portfolio address to its corresponding ledger entries within the specified block range.

        Note:
            The @set_end_block_if_none decorator ensures that if end_block is not provided,
            it defaults to the latest block.

        Example:
            >>> ledger = PortfolioTransactionsLedger(portfolio=portfolio)
            >>> ledger_entries = await ledger.get(start_block=1000000, end_block=1100000)
            >>> print("\n".join(f"Address {addr}: {len(entries)} entries" for addr, entries in ledger_entries.items()))
        """
        coros = {
            address: cache.get(start_block, end_block, sync=False)
            for address, cache in self.object_caches.items()
        }
        return await a_sync.gather(coros)

    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block) -> DataFrame:
        """
        Returns a DataFrame containing all entries for this ledger.

        This method provides an easy way to access your data in a standardized, clean format
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

    async def sent(
        self, start_block: Optional[Block] = None, end_block: Optional[Block] = None
    ) -> AsyncIterator[T]:
        portfolio_addresses = set(self.portfolio.addresses.keys())
        async for obj in self[start_block:end_block]:
            if (
                obj.from_address in portfolio_addresses
                and obj.to_address not in portfolio_addresses
            ):
                yield obj

    async def received(
        self, start_block: Optional[Block] = None, end_block: Optional[Block] = None
    ) -> AsyncIterator[T]:
        portfolio_addresses = set(self.portfolio.addresses.keys())
        async for obj in self[start_block:end_block]:
            if (
                obj.to_address in portfolio_addresses
                and obj.from_address not in portfolio_addresses
            ):
                yield obj

    async def _df_base(self, start_block: Block, end_block: Block) -> DataFrame:
        """
        Fetches and concatenates raw ledger data into a :class:`~DataFrame` for all addresses in the portfolio.

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
        return concat(pandable.df for pandable in data.values())

    @classmethod
    def _deduplicate_df(cls, df: DataFrame) -> DataFrame:
        """
        Deduplicate the DataFrame to prevent double-counting of transfers within the portfolio.

        This method is crucial for ensuring accurate portfolio analysis by removing duplicate entries
        where transfers between owned addresses appear once in each result set.

        Note:
            - This method can be overridden in subclasses if needed.
            - If the DataFrame contains columns with list-type values, they are converted to strings for comparison.

        Args:
            df: The DataFrame to deduplicate.

        Returns:
            A deduplicated version of the input DataFrame.

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

        Args:
            df: The DataFrame to clean up.

        Returns:
            A cleaned and deduplicated DataFrame sorted by block number.

        Example:
            >>> cleaned_df = ledger._cleanup_df(df)
            >>> print(cleaned_df)
        """
        df = cls._deduplicate_df(df)
        return df.sort_values(["blockNumber"]).reset_index(drop=True)


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


class PortfolioInternalTransfersLedger(
    PortfolioLedgerBase[InternalTransfersList, InternalTransfer]
):
    """
    The :class:`~eth_portfolio._ledgers.PortfolioInternalTransfersLedger` class manages internal
    transfer entries across all addresses in a portfolio. It aggregates and processes internal transfers
    for the entire portfolio within specified block ranges.

    In the eth-portfolio ecosystem, this class plays a vital role in:
    - Tracking internal Ethereum transfers between addresses within the same portfolio.
    - Providing insights into complex transactions that involve multiple internal transfers.
    - Supporting accurate portfolio analysis of internal transfer data from EVM traces.

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
            df.rename(
                columns={"transactionHash": "hash", "transactionPosition": "transactionIndex"},
                inplace=True,
            )
            df = self._cleanup_df(df)
        return df

    @classmethod
    def _deduplicate_df(cls, df: DataFrame) -> DataFrame:
        """
        Deduplicates the DataFrame.

        This deduplication is essential for ensuring accurate portfolio analysis by removing
        duplicate entries due to transfers between addresses within the same portfolio.

        Args:
            df: The DataFrame to deduplicate.

        Returns:
            A deduplicated DataFrame.

        Example:
            >>> deduped_df = PortfolioInternalTransfersLedger._deduplicate_df(df)
            >>> print(deduped_df)
        """
        df = df.reset_index(drop=True)
        # We cant use drop_duplicates when one of the columns, `traceAddress`, contains lists.
        # We must first convert the lists to strings
        return df.loc[df.astype(str).drop_duplicates().index]
