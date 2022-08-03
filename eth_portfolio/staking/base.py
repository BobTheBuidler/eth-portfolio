
from typing import Optional
from y.datatypes import Address, Block

from eth_portfolio.decorators import await_if_sync
from eth_portfolio.typing import StakedTokenBalances

class StakingPool:

    @await_if_sync
    def balances(self, address: Address, block: Optional[Block] = None) -> StakedTokenBalances:
        return self._balances_async(address, block)
    
    async def _balances_async(self, address: Address, block: Optional[Block] = None):
        raise NotImplementedError
