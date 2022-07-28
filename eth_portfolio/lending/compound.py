
from typing import Optional

from brownie import ZERO_ADDRESS, Contract
from eth_portfolio.lending.base import LendingProtocol
from eth_portfolio.typing import PortfolioBalanceDetails
from multicall.utils import await_awaitable, gather
from y import fetch_multicall, weth, get_prices_async
from y.classes.common import ERC20
from y.datatypes import Address, Block
from y.prices.lending.compound import CToken, compound


class Compound(LendingProtocol):
    def __init__(self, asynchronous: bool = False) -> None:
        self.asynchronous = bool(asynchronous)

        markets = {market.contract for comp in compound.trollers.values() for market in comp.markets if hasattr(market.contract, 'borrowBalanceStored')} # this last part takes out xinv
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

    def debt(self, address: Address, block: Optional[Block] = None) -> Optional[PortfolioBalanceDetails]:
        coro = self.debt_async(address, block=block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def debt_async(self, address: Address, block: Optional[Block] = None) -> Optional[PortfolioBalanceDetails]:
        if len(compound.trollers) == 0: # if ypricemagic doesn't support any Compound forks on current chain
            return None

        address = str(address)
        debts, underlying_scale = await gather([
            gather(_borrow_balance_stored(market, address, block) for market in self.markets),
            gather(underlying.scale for underlying in self.underlyings),
        ])

        debts = {underlying: debt / scale for underlying, scale, debt in zip(self.underlyings,underlying_scale,debts) if debt}
        prices = await get_prices_async(debts.keys(), block=block)
        return {str(underlying): {'balance': debt, 'usd value': debt * price} for (underlying, debt), price in zip(debts.items(), prices)}

async def _borrow_balance_stored(market: Contract, address: Address, block: Optional[Block] = None) -> int:
    try:
        return await market.borrowBalanceStored.coroutine(str(address), block_identifier=block)
    except ValueError as e:
        if str(e) != "No data was returned - the call likely reverted":
            raise
        return None
