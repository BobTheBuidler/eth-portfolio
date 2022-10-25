
import abc
from typing import Optional

from eth_portfolio._decorators import await_if_sync
from eth_portfolio.protocols._base import ProtocolABC
from eth_portfolio.typing import TokenBalances
from y.datatypes import Address, Block


class LendingProtocol(metaclass=abc.ABCMeta):
    """
    Subclass this class for any protocol that maintains a debt balance for a user but doesn't maintain collateral internally.
    Example: Aave, because the user holds on to their collateral in the form of erc-20 aTokens.

    You must define the following async method:
        `_debt_async(self, address: Address, block: Optional[Block] = None)`
    """ 
    asynchronous: bool
    
    @await_if_sync
    def debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._debt_async(address, block)  # type: ignore
    
    @abc.abstractmethod
    async def _debt_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        ...

class LendingProtocolWithLockedCollateral(LendingProtocol, ProtocolABC):
    """
    Subclass this class for any protocol that maintains a debt balance for a user AND holds collateral internally.
    Example: Maker, because collateral is locked up inside of Maker's smart contracts.

    You must define the following async methods:
        - `_debt_async(self, address: Address, block: Optional[Block] = None)`
        - `_balances_async(self, address: Address, block: Optional[Block] = None)`
    """
