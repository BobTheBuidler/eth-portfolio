
import asyncio
import logging
from typing import TYPE_CHECKING, AsyncGenerator, Dict, Optional

import a_sync
from y import convert
from y.constants import EEE_ADDRESS
from y.datatypes import Address, Block
from y.decorators import stuck_coro_debugger

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

class PortfolioAddress(a_sync.ASyncGenericBase, _AiterMixin[LedgerEntry]):
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
    
    @stuck_coro_debugger
    async def describe(self, block: int) -> WalletBalances:
        assert block, "You must provide a valid block number"
        assert isinstance(block, int), f"Block must be an integer. You passed {type(block)} {block}"
        fns = [self.assets, self.debt, self.external_balances]
        balances = WalletBalances()
        balances['assets'], balances['debt'], balances['external'] = await asyncio.gather(*[fn(block, sync=False) for fn in fns])
        return balances
    
    @stuck_coro_debugger
    async def assets(self, block: Optional[Block] = None) -> TokenBalances:
        return await self.balances(block=block, sync=False)
    
    @stuck_coro_debugger
    async def debt(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return await _lending.debt(self.address, block=block)
    
    @stuck_coro_debugger
    async def external_balances(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        staked, collateral = await asyncio.gather(
            self.staking(block, sync=False),
            self.collateral(block, sync=False)
        )
        return staked + collateral

    # Assets
    
    @stuck_coro_debugger
    async def balances(self, block: Optional[Block]) -> TokenBalances:
        eth_balance, token_balances = await asyncio.gather(
            self.eth_balance(block, sync=False),
            self.token_balances(block, sync=False),
        )
        token_balances[EEE_ADDRESS] = eth_balance
        return token_balances

    @stuck_coro_debugger
    async def eth_balance(self, block: Optional[Block]) -> Balance:
        return await balances.load_eth_balance(self.address, block)
    
    @stuck_coro_debugger
    async def token_balances(self, block) -> TokenBalances:
        futs = []
        async for token in self.token_transfers._yield_tokens_at_block_async(block=block):
            futs.append(asyncio.create_task(coro=balances.load_token_balance(token, self.address, block), name=f"load_token_balance {self.address} at block {block}"))
        return TokenBalances((token, balance) for token, balance in await asyncio.gather(*futs) if balance)
   
    @stuck_coro_debugger 
    async def collateral(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return await _lending.collateral(self.address, block=block)
    
    @stuck_coro_debugger
    async def staking(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return await _external.balances(self.address, block=block)
    
    # Ledger Entries
    
    @stuck_coro_debugger
    async def all(self, start_block: Block, end_block: Block) -> Dict[str, PandableLedgerEntryList]:
        transactions, internal_transactions, token_transfers = await asyncio.gather(
            self.transactions.get(start_block, end_block, sync=False),
            self.internal_transfers.get(start_block, end_block, sync=False),
            self.token_transfers.get(start_block, end_block, sync=False),
        )
        return {
            "transactions": transactions,
            "internal_transactions": internal_transactions,
            "token_transfers": token_transfers,
        }
