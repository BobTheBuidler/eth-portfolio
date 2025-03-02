import abc
from typing import Optional

import a_sync
from y.datatypes import Address, Block

from eth_portfolio.protocols._base import ProtocolABC
from eth_portfolio.typing import TokenBalances


class LendingProtocol(metaclass=abc.ABCMeta):
    """
    Subclass this class for any protocol that maintains a debt balance for a user but doesn't maintain collateral internally.
    Example: Aave, because the user holds on to their collateral in the form of ERC-20 aTokens.

    You must define the following async method:
        `_debt(self, address: Address, block: Optional[Block] = None)`

    Example:
        >>> class AaveProtocol(LendingProtocol):
        ...     async def _debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        ...         # Implementation for fetching debt from Aave
        ...         pass

    See Also:
        - :class:`LendingProtocolWithLockedCollateral`
    """

    @a_sync.future
    async def debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return await self._debt(address, block)  # type: ignore

    @abc.abstractmethod
    async def _debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances: ...


class LendingProtocolWithLockedCollateral(LendingProtocol, ProtocolABC):
    """
    Subclass this class for any protocol that maintains a debt balance for a user AND holds collateral internally.
    Example: Maker, because collateral is locked up inside of Maker's smart contracts.

    You must define the following async methods:
        - `_debt(self, address: Address, block: Optional[Block] = None)`
        - `_balances(self, address: Address, block: Optional[Block] = None)`

    Example:
        >>> class MakerProtocol(LendingProtocolWithLockedCollateral):
        ...     async def _debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        ...         # Implementation for fetching debt from Maker
        ...         pass
        ...     async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        ...         # Implementation for fetching balances from Maker
        ...         pass

    See Also:
        - :class:`LendingProtocol`
    """
