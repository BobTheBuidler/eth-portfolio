
import asyncio
from typing import Optional

from eth_portfolio.decorators import await_if_sync
from eth_portfolio.staking.base import StakingPool
from eth_portfolio.typing import StakedTokenBalances
from eth_portfolio.utils import Decimal
from y import Contract
from y.classes.common import ERC20
from y.contracts import contract_creation_block
from y.datatypes import Address, Block

convex_locker_v2 = Contract("0x72a19342e8F1838460eBFCCEf09F6585e32db86E")
locker_deploy_block = contract_creation_block(convex_locker_v2.address)
cvx = ERC20("0x4e3FBD56CD56c3e72c1403e103b45Db9da5B9D2B")


class Convex(StakingPool):
    def __init__(self, asynchronous: bool) -> None:
        self.asynchronous = asynchronous
    
    @await_if_sync
    def balances(self, address: Address, block: Optional[Block] = None) -> StakedTokenBalances:
        return self._balances_async(address, block)
    
    async def _balances_async(self, address: Address, block: Optional[Block] = None) -> StakedTokenBalances:
        if block and block < locker_deploy_block:
            return {}
        balance = Decimal(await convex_locker_v2.balanceOf.coroutine(address, block_identifier=block))
        if balance:
            scale, price = await asyncio.gather(cvx.scale, cvx.price_async(block))
            balance /= scale
            return {cvx.address: {'balance': balance, 'usd value': balance * Decimal(price)}}
        return {}

