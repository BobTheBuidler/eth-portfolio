
import asyncio
import logging
from typing import TYPE_CHECKING, AsyncGenerator, Dict, Optional

import a_sync
from y import convert
from y.constants import EEE_ADDRESS
from y.datatypes import Address, Block
from y.decorators import stuck_coro_debugger

from eth_portfolio._decorators import await_if_sync
from eth_portfolio._ledgers.address import (AddressInternalTransfersLedger,
                                            AddressTokenTransfersLedger,
                                            AddressTransactionsLedger,
                                            PandableLedgerEntryList)
from eth_portfolio._loaders import balances
from eth_portfolio.protocols import _external
from eth_portfolio.protocols.lending import _lending
from eth_portfolio.structs import LedgerEntry
from eth_portfolio.typing import (Balance, RemoteTokenBalances, TokenBalances,
                                  WalletBalances)
from eth_portfolio.utils import _AiterMixin

if TYPE_CHECKING:
    from eth_portfolio.portfolio import Portfolio

logger = logging.getLogger(__name__)

class PortfolioAddress(_AiterMixin[LedgerEntry]):
    def __init__(self, address: Address, portfolio: "Portfolio") -> None: # type: ignore
        self.address = convert.to_address(address)
        self.portfolio = portfolio
        self.transactions = AddressTransactionsLedger(self)
        self.internal_transfers = AddressInternalTransfersLedger(self)
        self.token_transfers = AddressTokenTransfersLedger(self)

    @property
    def asynchronous(self) -> bool:
        return self.portfolio.asynchronous

    @property
    def load_prices(self) -> bool:
        return self.portfolio.load_prices
    
    def __str__(self) -> str:
        return self.address

    def __repr__(self) -> str:
        return f"<PortfolioAddress: {self.address}>"
    
    def __eq__(self, other: object) -> bool:
        if isinstance(other, PortfolioAddress):
            return self.address == other.address
        elif isinstance(other, str):
            return self.address == convert.to_address(other)
        return False
    
    def __hash__(self) -> int:
        return hash(self.address)
    
    @property
    def _start_block(self) -> int:
        return self.portfolio._start_block

    async def _get_and_yield(self, start_block: Block, end_block: Block) -> AsyncGenerator[LedgerEntry, None]:
        # TODO: make this an actual generator
        async for entry in a_sync.as_yielded(
            self.transactions._get_and_yield(start_block, end_block),
            self.internal_transfers._get_and_yield(start_block, end_block),
            self.token_transfers._get_and_yield(start_block, end_block),
        ):
            yield entry
    
    # Primary functions

    @await_if_sync
    def describe(self, block: int) -> WalletBalances:
        return self._describe_async(block=block) # type: ignore
    
    @stuck_coro_debugger
    async def _describe_async(self, block: int) -> WalletBalances:
        assert block, "You must provide a valid block number"
        assert isinstance(block, int), f"Block must be an integer. You passed {type(block)} {block}"
        fns = [self._assets_async, self._debt_async, self._external_balances_async]
        balances = WalletBalances()
        balances['assets'], balances['debt'], balances['external'] = await asyncio.gather(*[fn(block) for fn in fns])
        return balances
    
    @await_if_sync
    def assets(self, block: Optional[Block] = None) -> TokenBalances:
        return self._assets_async(block) # type: ignore
    
    @stuck_coro_debugger
    async def _assets_async(self, block: Optional[Block] = None) -> TokenBalances:
        return await self._balances_async(block=block)

    @await_if_sync
    def debt(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return self._debt_async(block) # type: ignore
    
    @stuck_coro_debugger
    async def _debt_async(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return await _lending.debt(self.address, block=block)
    
    @await_if_sync
    def external_balances(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return self._external_balances_async(block) # type: ignore
    
    @stuck_coro_debugger
    async def _external_balances_async(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        staked, collateral = await asyncio.gather(
            self._staking_async(block),
            self._collateral_async(block)
        )
        return staked + collateral

    # Assets

    @await_if_sync
    def balances(self, block: Optional[Block]) -> TokenBalances:
        return self._balances_async(block) # type: ignore
    
    @stuck_coro_debugger
    async def _balances_async(self, block: Optional[Block]) -> TokenBalances:
        eth_balance, token_balances = await asyncio.gather(
            self._eth_balance_async(block),
            self._token_balances_async(block),
        )
        token_balances[EEE_ADDRESS] = eth_balance
        return token_balances
    
    @await_if_sync
    def eth_balance(self, block: Optional[Block]) -> Balance:
        return self._eth_balance_async(block) # type: ignore

    @stuck_coro_debugger
    async def _eth_balance_async(self, block: Optional[Block]) -> Balance:
        return await balances.load_eth_balance(self.address, block)
    
    @await_if_sync
    def token_balances(self, block: Optional[Block]) -> TokenBalances:
        return self._token_balances_async(block) # type: ignore
    
    @stuck_coro_debugger
    async def _token_balances_async(self, block) -> TokenBalances:
        futs = []
        async for token in self.token_transfers._yield_tokens_at_block_async(block=block):
            futs.append(asyncio.create_task(coro=balances.load_token_balance(token, self.address, block), name=f"load_token_balance {self.address} at block {block}"))
        return TokenBalances((token, balance) for token, balance in await asyncio.gather(*futs) if balance)
    
    @await_if_sync
    def collateral(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return self._collateral_async(block) # type: ignore
   
    @stuck_coro_debugger 
    async def _collateral_async(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return await _lending.collateral(self.address, block=block)
    
    @await_if_sync
    def staking(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return self._staking_async(block) # type: ignore
    
    @stuck_coro_debugger
    async def _staking_async(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return await _external.balances(self.address, block=block)
    
    # Ledger Entries

    @await_if_sync
    def all(self, load_prices: bool = False) -> Dict[str, PandableLedgerEntryList]:
        return self._all_async(load_prices=load_prices) # type: ignore
    
    @stuck_coro_debugger
    async def _all_async(self, start_block: Block, end_block: Block) -> Dict[str, PandableLedgerEntryList]:
        transactions, internal_transactions, token_transfers = await asyncio.gather(
            self.transactions._get_async(start_block, end_block),
            self.internal_transfers._get_async(start_block, end_block),
            self.token_transfers._get_async(start_block, end_block),
        )
        return {
            "transactions": transactions,
            "internal_transactions": internal_transactions,
            "token_transfers": token_transfers,
        }
