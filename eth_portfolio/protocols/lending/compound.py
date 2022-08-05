
import asyncio
from typing import Optional

from brownie import ZERO_ADDRESS, Contract
from eth_portfolio._decorators import await_if_sync
from eth_portfolio.protocols.lending._base import LendingProtocol
from eth_portfolio.typing import Address, TokenBalances, _BalanceItem
from y import fetch_multicall, get_prices_async, weth
from y.classes.common import ERC20
from y.datatypes import Block
from y.prices.lending.compound import compound

from eth_portfolio.utils import Decimal


class Compound(LendingProtocol):
    def __init__(self, asynchronous: bool = False) -> None:
        self.asynchronous = asynchronous
        markets = [market.contract for comp in compound.trollers.values() for market in comp.markets if hasattr(market.contract, 'borrowBalanceStored')] # this last part takes out xinv
        gas_token_markets = [market for market in markets if not hasattr(market,'underlying')]
        other_markets = [market for market in markets if hasattr(market,'underlying')]

        markets = gas_token_markets + other_markets
        underlyings = [weth for market in gas_token_markets] + fetch_multicall(*[[market,'underlying'] for market in other_markets])

        markets_zip = zip(markets,underlyings)
        self.markets, underlyings = [], []
        for contract, underlying in markets_zip:
            if underlying != ZERO_ADDRESS:
                self.markets.append(contract)
                underlyings.append(underlying)
        self.underlyings = [ERC20(underlying) for underlying in underlyings]

    @await_if_sync
    def debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._debt_async(address, block=block) # type: ignore
    
    async def _debt_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        if len(compound.trollers) == 0: # if ypricemagic doesn't support any Compound forks on current chain
            return TokenBalances()

        address = str(address)
        debt_data, underlying_scale = await asyncio.gather(
            asyncio.gather(*[_borrow_balance_stored(market, address, block) for market in self.markets]),
            asyncio.gather(*[underlying.scale for underlying in self.underlyings]),
        )

        debts = {underlying: Decimal(debt) / scale for underlying, scale, debt in zip(self.underlyings, underlying_scale, debt_data) if debt}
        prices = await get_prices_async(debts.keys(), block=block)
        balances: TokenBalances = TokenBalances()
        for (underlying, debt), price in zip(debts.items(), prices):
            balances[underlying] += _BalanceItem(debt, debt * Decimal(price))
        return balances

async def _borrow_balance_stored(market: Contract, address: Address, block: Optional[Block] = None) -> Optional[int]:
    try:
        return await market.borrowBalanceStored.coroutine(str(address), block_identifier=block)
    except ValueError as e:
        if str(e) != "No data was returned - the call likely reverted":
            raise
        return None
