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
        data: Dict[Address, _LedgerEntryList] = await self.get(start_block, end_block, sync=False)
        return concat(pandable.df for pandable in data.values())

    @classmethod
    def _deduplicate_df(cls, df: DataFrame) -> DataFrame:
        """
        Deduplicate the dataframe so transfers sending crypto to yourself are not double counted
        NOTE: This can be overridden if needed.
        """
        # If there is a value of list type in the DataFrame, it must be converted to a string for comparison.
        return df.loc[df.astype(str).drop_duplicates().index]

    @classmethod
    def _cleanup_df(cls, df: DataFrame) -> DataFrame:
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
        """Returns a DataFrame containing all internal transfers to or from any of the wallets in your portfolio."""
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
