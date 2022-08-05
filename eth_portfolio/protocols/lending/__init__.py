
import asyncio
from typing import List, Optional, Union

from eth_portfolio._decorators import await_if_sync
from eth_portfolio.protocols.lending._base import (
    LendingProtocol, LendingProtocolWithLockedCollateral)
from eth_portfolio.typing import TokenBalances
from eth_portfolio.utils import (_get_protocols_for_submodule,
                                 _import_submodules)
from y.datatypes import Address, Block

_import_submodules()


class Lending:
    def __init__(self, asynchronous: bool = False) -> None:
        self.asynchronous = bool(asynchronous)
        self.protocols: List[Union[LendingProtocol, LendingProtocolWithLockedCollateral]] = _get_protocols_for_submodule(self.asynchronous)  # type: ignore

    @await_if_sync
    def collateral(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._collateral_async(address, block) # type: ignore

    async def _collateral_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        protocols = [protocol for protocol in self.protocols if isinstance(protocol, LendingProtocolWithLockedCollateral)]
        return sum(await asyncio.gather(*[protocol._balances_async(address, block) for protocol in protocols])) # type: ignore

    @await_if_sync
    def debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._debt_async(address, block) # type: ignore
    
    async def _debt_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return sum(await asyncio.gather(*[protocol._debt_async(address, block) for protocol in self.protocols])) # type: ignore

_lending = Lending(asynchronous=True)
