
import asyncio
from decimal import Decimal
from typing import Dict, Optional

from eth_portfolio.staking.base import StakingPool
from multicall.utils import await_awaitable
from y import Contract
from y.classes.common import ERC20
from y.datatypes import Address, Block

from eth_portfolio.typing import StakedTokenBalances

convex_locker_v2 = Contract("0x72a19342e8F1838460eBFCCEf09F6585e32db86E")
cvx = ERC20("0x4e3FBD56CD56c3e72c1403e103b45Db9da5B9D2B")


class Convex(StakingPool):
    def __init__(self, asynchronous: bool) -> None:
        self.asynchronous = asynchronous
    
    def balances(self, address: Address, block: Optional[Block] = None) -> StakedTokenBalances:
        coro = self.balances_async(address, block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def balances_async(self, address: Address, block: Optional[Block] = None) -> StakedTokenBalances:
        balance = await convex_locker_v2.balanceOf.coroutine(address, block_identifier=block)
        if balance:
            scale, price = await asyncio.gather(cvx.scale, cvx.price_async(block))
            balance /= scale
            return {cvx.address: {'balance': balance, 'usd value': balance * price}}
        return {}

