import asyncio
import logging
from typing import TYPE_CHECKING, AsyncIterator, Dict, Tuple, TypeVar, Union

import a_sync
from pandas import DataFrame, concat  # type: ignore
from y.datatypes import Address, Block

from eth_portfolio._decorators import await_if_sync, set_end_block_if_none
from eth_portfolio._ledgers.address import (AddressLedgerBase,
                                            InternalTransfersList,
                                            TokenTransfersList,
                                            TransactionsList, _LedgerEntryList)
from eth_portfolio.utils import _unpack_indicies

if TYPE_CHECKING:
    from eth_portfolio.portfolio import Portfolio

logger = logging.getLogger(__name__)

T = TypeVar('T')

class PortfolioLedgerBase(_LedgerEntryList[T]):
    property_name: str

    def __init__(self, portfolio: "Portfolio"): # type: ignore
        assert hasattr(self, "property_name"), "Subclasses must define a property_name"
        self.object_caches: Dict[Address, AddressLedgerBase[_LedgerEntryList]] = {address.address: getattr(address, self.property_name) for address in portfolio}
        self.portfolio = portfolio
    
    def __getitem__(self, indicies: Union[Block, Tuple[Block, Block]]) -> Dict[Address, _LedgerEntryList]:
        start_block, end_block = _unpack_indicies(indicies)
        if asyncio.get_event_loop().is_running():
            return self._get_async(start_block, end_block) # type: ignore
        return self.get(start_block, end_block)
    
    def __aiter__(self) -> AsyncIterator[T]:
        return self._get_and_yield(self.portfolio.start_block or 0, None).__aiter__()
    
    async def _get_and_yield(self, start_block: int, end_block: int) -> AsyncIterator[T]:
        async for entry in a_sync.as_yielded(*[
            getattr(address, self.property_name)._get_and_yield(start_block, end_block) for address in self.portfolio
        ]):
            yield entry
    
    @property
    def asynchronous(self) -> bool:
        return self.portfolio.asynchronous
    
    @property
    def load_prices(self) -> bool:
        return self.portfolio.load_prices
    
    @await_if_sync
    def get(self, start_block: Block, end_block: Block) -> Dict[Address, _LedgerEntryList]:
        return self._get_async(start_block, end_block) # type: ignore
    
    @set_end_block_if_none
    async def _get_async(self, start_block: Block, end_block: Block) -> Dict[Address, _LedgerEntryList]:
        token_transfers = await asyncio.gather(*[cache._get_async(start_block, end_block) for cache in self.object_caches.values()])
        return {address: transfers for address, transfers in zip(self.portfolio.addresses, token_transfers)}

    @await_if_sync
    def _df(self, start_block: Block = 0, end_block: Block = None) -> DataFrame:
        return self._df_async(start_block, end_block)
    
    @set_end_block_if_none
    async def _df_async(self, start_block: Block, end_block: Block) -> DataFrame:
        """ Override this method if you want to do something special with the dataframe """
        df = await self._df_base(start_block, end_block)
        if len(df) > 0:
            df = self._cleanup_df(df)
        return df
    
    async def _df_base(self, start_block: Block, end_block: Block) -> DataFrame:
        data: Dict[Address, _LedgerEntryList] = await self._get_async(start_block, end_block)
        df = concat(pandable.df for pandable in data.values())
        return df
    
    def _deduplicate_df(self, df: DataFrame) -> DataFrame:
        # If there is a value of list type in the DataFrame, it must be converted to a string for comparison.
        return df.loc[df.astype(str).drop_duplicates().index]
    
    def _cleanup_df(self, df: DataFrame) -> DataFrame:
        df = self._deduplicate_df(df)
        return df.sort_values(['blockNumber']).reset_index(drop=True)


class PortfolioTransactionsLedger(PortfolioLedgerBase[TransactionsList]):
    property_name = "transactions"

class PortfolioTokenTransfersLedger(PortfolioLedgerBase[TokenTransfersList]):
    property_name = "token_transfers"

class PortfolioInternalTransfersLedger(PortfolioLedgerBase[InternalTransfersList]):
    property_name = "internal_transfers"

    @set_end_block_if_none
    async def _df_async(self, start_block: Block, end_block: Block) -> DataFrame:
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
