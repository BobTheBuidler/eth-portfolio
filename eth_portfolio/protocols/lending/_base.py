
import abc
from typing import Optional

from eth_portfolio._decorators import await_if_sync
from eth_portfolio.protocols._base import ProtocolABC
from eth_portfolio.typing import TokenBalances
from y.datatypes import Address, Block


class LendingProtocol(metaclass=abc.ABCMeta):
    asynchronous: bool
    
    @await_if_sync
    def debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._debt_async(address, block)  # type: ignore
    
    @abc.abstractmethod
    async def _debt_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        ...

class LendingProtocolWithLockedCollateral(LendingProtocol, ProtocolABC):
    """ Locked collateral would be like Maker, not Aave, because Aave gives you atokens that you hold in your wallet. """
