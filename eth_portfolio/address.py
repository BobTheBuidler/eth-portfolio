
import asyncio
import logging
from typing import TYPE_CHECKING, Dict, Optional

import a_sync
from a_sync.exceptions import MappingIsEmptyError
from y import convert
from y.constants import EEE_ADDRESS
from y.datatypes import Address, Block
from y.decorators import stuck_coro_debugger

from eth_portfolio._ledgers.address import (AddressInternalTransfersLedger,
                                            AddressLedgerBase,
                                            AddressTokenTransfersLedger,
                                            AddressTransactionsLedger,
                                            PandableLedgerEntryList)
from eth_portfolio._loaders import balances
from eth_portfolio.protocols import _external
from eth_portfolio.protocols.lending import _lending
from eth_portfolio.typing import (Balance, RemoteTokenBalances, TokenBalances,
                                  WalletBalances)
from eth_portfolio.utils import _LedgeredBase

if TYPE_CHECKING:
    from eth_portfolio.portfolio import Portfolio

logger = logging.getLogger(__name__)

class PortfolioAddress(_LedgeredBase[AddressLedgerBase]):
    def __init__(self, address: Address, portfolio: "Portfolio", asynchronous: bool = False) -> None: # type: ignore
        self.address = convert.to_address(address)
        super().__init__(portfolio)
        self.transactions = AddressTransactionsLedger(self)
        self.internal_transfers = AddressInternalTransfersLedger(self)
        self.token_transfers = AddressTokenTransfersLedger(self)
        if not isinstance(asynchronous, bool):
            raise TypeError(f"`asynchronous` must be a boolean, you passed {type(asynchronous)}")
        self.asynchronous = asynchronous
    
    def __str__(self) -> str:
        return self.address

    def __repr__(self) -> str:
        return f"<{self.__class__.__name__} address={self.address} at {hex(id(self))}>"
    
    def __eq__(self, other: object) -> bool:
        if isinstance(other, PortfolioAddress):
            return self.address == other.address
        elif isinstance(other, str):
            return self.address == convert.to_address(other)
        return False
    
    def __hash__(self) -> int:
        return hash(self.address)
    
    # Primary functions
    
    @stuck_coro_debugger
    async def describe(self, block: int) -> WalletBalances:
        assert block, "You must provide a valid block number"
        assert isinstance(block, int), f"Block must be an integer. You passed {type(block)} {block}"
        return WalletBalances(await a_sync.gather({
            "assets": self.assets(block, sync=False), 
            "debt": self.debt(block, sync=False), 
            "external": self.external_balances(block, sync=False),
        }))
    
    @stuck_coro_debugger
    async def assets(self, block: Optional[Block] = None) -> TokenBalances:
        return await self.balances(block=block, sync=False)
    
    @stuck_coro_debugger
    async def debt(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return await _lending.debt(self.address, block=block)
    
    @stuck_coro_debugger
    async def external_balances(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return sum(await asyncio.gather(self.staking(block, sync=False), self.collateral(block, sync=False)))

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
        try:
            data = await a_sync.map(
                balances.load_token_balance, 
                self.token_transfers._yield_tokens_at_block_async(block=block),
                address=self.address, 
                block=block,
            )
            return TokenBalances(await data)
        except MappingIsEmptyError:
            return TokenBalances()
   
    @stuck_coro_debugger 
    async def collateral(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return await _lending.collateral(self.address, block=block)
    
    @stuck_coro_debugger
    async def staking(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return await _external.balances(self.address, block=block)
    
    # Ledger Entries
    
    @stuck_coro_debugger
    async def all(self, start_block: Block, end_block: Block) -> Dict[str, PandableLedgerEntryList]:
        return a_sync.gather({
            "transactions": self.transactions.get(start_block, end_block, sync=False),
            "internal_transactions": self.internal_transfers.get(start_block, end_block, sync=False),
            "token_transfers": self.token_transfers.get(start_block, end_block, sync=False),
        })
