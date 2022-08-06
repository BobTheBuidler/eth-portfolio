
import asyncio
import decimal
import logging
from typing import TYPE_CHECKING, Dict, Optional

from y import convert, get_price_async
from y.constants import EEE_ADDRESS, weth
from y.datatypes import Address, Block
from y.utils.dank_mids import dank_w3

from eth_portfolio._decorators import await_if_sync
from eth_portfolio._ledgers.address import (AddressInternalTransfersLedger,
                                            AddressTokenTransfersLedger,
                                            AddressTransactionsLedger,
                                            PandableLedgerEntryList)
from eth_portfolio.protocols.lending import _lending
from eth_portfolio.protocols.staking import _staking
from eth_portfolio.typing import (Balance, RemoteTokenBalances, TokenBalances,
                                  WalletBalances)
from eth_portfolio.utils import Decimal, _get_price

if TYPE_CHECKING:
    from eth_portfolio.portfolio import Portfolio

logger = logging.getLogger(__name__)

debug_semaphore = asyncio.Semaphore(value=100)


async def _get_eth_balance(address: Address, block: Optional[Block]) -> decimal.Decimal:
    return Decimal(await dank_w3.eth.get_balance(address, block_identifier=block)) / Decimal(1e18)

class PortfolioAddress:
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
    
    # Primary functions

    @await_if_sync
    def describe(self, block: int) -> WalletBalances:
        return self._describe_async(block=block) # type: ignore
    
    async def _describe_async(self, block: int) -> WalletBalances:
        assert block
        assets: TokenBalances
        debt: TokenBalances
        balances = WalletBalances()
        assets, debt = await asyncio.gather(*[self._assets_async(block), self._debt_async(block)])
        balances['assets'] = assets
        balances['debt'] = debt
        return balances
    
    @await_if_sync
    def assets(self, block: Optional[Block] = None) -> TokenBalances:
        return self._assets_async(block) # type: ignore
    
    async def _assets_async(self, block: Optional[Block] = None) -> TokenBalances:
        balances, collateral = await asyncio.gather(
            self._balances_async(block=block),
            self._collateral_async(block=block),
        )
        for token, _balances in collateral.items():
            balances[token]['balance'] += _balances['balance']
            balances[token]['usd_value'] += _balances['usd_value']
        balances.update(collateral)
        return balances

    @await_if_sync
    def debt(self, block: Optional[Block] = None) -> TokenBalances:
        return self._debt_async(block) # type: ignore
    
    async def _debt_async(self, block: Optional[Block] = None) -> TokenBalances:
        return await _lending._debt_async(self.address, block=block)

    # Assets

    @await_if_sync
    def balances(self, block: Optional[Block]) -> TokenBalances:
        return self._balances_async(block) # type: ignore
    
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

    async def _eth_balance_async(self, block: Optional[Block]) -> Balance:
        balance, price = await asyncio.gather(
            _get_eth_balance(self.address, block),
            get_price_async(weth, block),
        )
        value = round(balance * Decimal(price), 18)
        return Balance(balance, value)
    
    @await_if_sync
    def token_balances(self, block: Optional[Block]) -> TokenBalances:
        return self._token_balances_async(block) # type: ignore
    
    async def _token_balances_async(self, block) -> TokenBalances:
        tokens = await self.token_transfers._list_tokens_at_block_async(block=block)
        token_balances, token_prices = await asyncio.gather(
            asyncio.gather(*[token.balance_of_readable_async(self.address, block) for token in tokens]),
            asyncio.gather(*[_get_price(token, block) for token in tokens]),
        )
        token_balances = [
            Balance(Decimal(balance), Decimal(0) if price is None else round(Decimal(balance) * Decimal(price), 18))
            for balance, price in zip(token_balances, token_prices)
        ]
        return TokenBalances(zip(tokens, token_balances))
    
    @await_if_sync
    def collateral(self, block: Optional[Block] = None) -> TokenBalances:
        return self._collateral_async(block) # type: ignore
    
    async def _collateral_async(self, block: Optional[Block] = None) -> TokenBalances:
        return await _lending._collateral_async(self.address, block=block)
    
    @await_if_sync
    def staking(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return self._staking_async(block) # type: ignore
    
    async def _staking_async(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        return await _staking._balances_async(self.address, block=block)
    
    # Ledger Entries

    @await_if_sync
    def all(self, load_prices: bool = False) -> Dict[str, PandableLedgerEntryList]:
        return self._all_async(load_prices=load_prices) # type: ignore
    
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
