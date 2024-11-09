import logging
from typing import TYPE_CHECKING, AsyncIterator, Dict, Generic, TypeVar

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

    @property
    def _start_block(self) -> int:
        """Returns the start block for analysis of this portfolio."""
        return self.portfolio._start_block

    def _get_and_yield(self, start_block: int, end_block: int) -> AsyncIterator[T]:
        aiterators = [
            getattr(address, self.property_name)[start_block:end_block]
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
        Returns a DataFrame with all entries for this ledger.
        NOTE: Override this method if you want to do something special with the dataframe
        """
        df = await self._df_base(start_block, end_block)
        if len(df) > 0:
            df = self._cleanup_df(df)
        return df

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
    property_name = "transactions"


class PortfolioTokenTransfersLedger(PortfolioLedgerBase[TokenTransfersList, TokenTransfer]):
    property_name = "token_transfers"


class PortfolioInternalTransfersLedger(
    PortfolioLedgerBase[InternalTransfersList, InternalTransfer]
):
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
        We cant use drop_duplicates when one of the columns, `traceAddress`, contains lists.
        We must first convert the lists to strings
        """
        df = df.reset_index(drop=True)
        return df.loc[df.astype(str).drop_duplicates().index]
