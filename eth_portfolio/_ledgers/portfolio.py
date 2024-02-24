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
from eth_portfolio.utils import _AiterMixin, _unpack_indicies
from eth_portfolio.structs import Transaction, InternalTransfer, TokenTransfer

if TYPE_CHECKING:
    from eth_portfolio.portfolio import Portfolio

logger = logging.getLogger(__name__)

T = TypeVar('T')

class PortfolioLedgerBase(a_sync.ASyncGenericBase, _AiterMixin[T], Generic[_LedgerEntryList, T]):
    property_name: str

    def __init__(self, portfolio: "Portfolio"): # type: ignore
        assert hasattr(self, "property_name"), "Subclasses must define a property_name"
        self.object_caches: Dict[Address, AddressLedgerBase[_LedgerEntryList]] = {address.address: getattr(address, self.property_name) for address in portfolio}
        self.portfolio = portfolio
    
    def __getitem__(self, indicies: Union[Block, Tuple[Block, Block]]) -> Dict[Address, _LedgerEntryList]:
        start_block, end_block = _unpack_indicies(indicies)
        if asyncio.get_event_loop().is_running():
            return self.get(start_block, end_block, sync=False) # type: ignore
        return self.get(start_block, end_block)

    @property
    def _start_block(self) -> int:
        return self.portfolio._start_block
    
    def _get_and_yield(self, start_block: int, end_block: int) -> AsyncIterator[T]:
        return a_sync.as_yielded(*[getattr(address, self.property_name)[start_block: end_block] for address in self.portfolio])
    
    @property
    def asynchronous(self) -> bool:
        return self.portfolio.asynchronous
    
    @property
    def load_prices(self) -> bool:
        return self.portfolio.load_prices
    
    @set_end_block_if_none
    async def get(self, start_block: Block, end_block: Block) -> Dict[Address, _LedgerEntryList]:
        token_transfers = await asyncio.gather(*[cache.get(start_block, end_block, sync=False) for cache in self.object_caches.values()])
        return {address: transfers for address, transfers in zip(self.portfolio.addresses, token_transfers)}
    
    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block) -> DataFrame:
        """ Override this method if you want to do something special with the dataframe """
        df = await self._df_base(start_block, end_block)
        if len(df) > 0:
            df = self._cleanup_df(df)
        return df
    
    async def _df_base(self, start_block: Block, end_block: Block) -> DataFrame:
        data: Dict[Address, _LedgerEntryList] = await self.get(start_block, end_block, sync=False)
        df = concat(pandable.df for pandable in data.values())
        return df
    
    def _deduplicate_df(self, df: DataFrame) -> DataFrame:
        # If there is a value of list type in the DataFrame, it must be converted to a string for comparison.
        return df.loc[df.astype(str).drop_duplicates().index]
    
    def _cleanup_df(self, df: DataFrame) -> DataFrame:
        df = self._deduplicate_df(df)
        return df.sort_values(['blockNumber']).reset_index(drop=True)


class PortfolioTransactionsLedger(PortfolioLedgerBase[TransactionsList, Transaction]):
    property_name = "transactions"

class PortfolioTokenTransfersLedger(PortfolioLedgerBase[TokenTransfersList, TokenTransfer]):
    property_name = "token_transfers"

class PortfolioInternalTransfersLedger(PortfolioLedgerBase[InternalTransfersList, InternalTransfer]):
    property_name = "internal_transfers"

    @set_end_block_if_none
    async def df(self, start_block: Block, end_block: Block) -> DataFrame:
        df = await self._df_base(start_block, end_block)
        if len(df) > 0:
            df.rename(columns={'transactionHash': 'hash', 'transactionPosition': 'transactionIndex'}, inplace=True)
            df = self._cleanup_df(df)
        return df

    def _deduplicate_df(self, df: DataFrame) -> DataFrame:
        """
        We cant use drop_duplicates when one of the columns, `traceAddress`, contains lists.
        We must first convert the lists to strings
        """
        df = df.reset_index(drop=True)
        return df.loc[df.astype(str).drop_duplicates().index]
