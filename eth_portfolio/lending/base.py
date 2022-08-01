
from typing import Dict, Optional
from y.datatypes import Address, Block

class LendingProtocol:
    def debt(self, address: Address, block: Optional[Block] = None) -> Dict:
        raise NotImplementedError
    
    async def debt_async(self, address: Address, block: Optional[Block] = None) -> Dict:
        raise NotImplementedError

class LendingProtocolWithLockedCollateral(LendingProtocol):
    """ Locked collateral would be like Maker, not Aave, because Aave gives you atokens. """
    def collateral(self, address: Address, block: Optional[Block] = None) -> Dict:
        raise NotImplementedError

    async def collateral_async(self, address: Address, block: Optional[Block] = None) -> Dict:
        raise NotImplementedError
