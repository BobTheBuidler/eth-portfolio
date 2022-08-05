
from typing import Optional

from eth_portfolio._decorators import await_if_sync
from eth_portfolio.typing import TokenBalances
from y.datatypes import Address, Block


class StakingPool:

    @await_if_sync
    def balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._balances_async(address, block) # type: ignore
    
    async def _balances_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        raise NotImplementedError
