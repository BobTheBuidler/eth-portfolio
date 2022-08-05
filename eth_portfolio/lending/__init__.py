
import asyncio
from typing import List, Optional, Union

from eth_portfolio._decorators import await_if_sync
from eth_portfolio.lending._base import (LendingProtocol,
                                         LendingProtocolWithLockedCollateral)
from eth_portfolio.typing import TokenBalances
from eth_portfolio.utils import (_get_protocols_for_submodule,
                                 _import_submodules)
from y.datatypes import Address, Block

_import_submodules()


class Lending:
    def __init__(self, asynchronous: bool = False) -> None:
        self.asynchronous = bool(asynchronous)
        self.protocols: List[Union[LendingProtocol, LendingProtocolWithLockedCollateral]] = _get_protocols_for_submodule(self.asynchronous)

    @await_if_sync
    def collateral(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._collateral_async(address, block) # type: ignore

    async def _collateral_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        # Under contrcutcion
        collaterals = await asyncio.gather(*[
            protocol._collateral_async(address, block) # type: ignore
            for protocol in self.protocols
            if hasattr(protocol, 'collateral')
        ])
        return {
            token: balances
            for protocol_collaterals in collaterals if protocol_collaterals
            for token, balances in protocol_collaterals.items() # if balances['balance'] != 0
        }

    @await_if_sync
    def debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._debt_async(address, block) # type: ignore
    
    async def _debt_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        # Under construction
        debts = await asyncio.gather(*[protocol._debt_async(address, block) for protocol in self.protocols])
        return {
            token: balances
            for protocol_debts in debts if protocol_debts
            for token, balances in protocol_debts.items() #if balances['balance'] != 0
        }

_lending = Lending(asynchronous=True)
