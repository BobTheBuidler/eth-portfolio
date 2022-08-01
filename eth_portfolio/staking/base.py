
from typing import Optional
from y.datatypes import Address, Block

class StakingPool:
    def balances(self, address: Address, block: Optional[Block] = None):
        raise NotImplementedError
    
    async def balances_async(self, address: Address, block: Optional[Block] = None):
        raise NotImplementedError
