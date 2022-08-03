
import asyncio
from typing import Dict, Optional

from eth_portfolio.decorators import await_if_sync
from eth_portfolio.utils import (Decimal, get_protocols_for_submodule,
                                 import_submodules)
from y.datatypes import Address, Block

import_submodules()


class Staking:
    def __init__(self, asynchronous: bool) -> None:
        self.asynchronous = asynchronous
        self.protocols = get_protocols_for_submodule(asynchronous)
    
    @await_if_sync
    def balances(self, address: Address, block: Optional[Block] = None) -> Dict[str, Dict[str, Decimal]]:
        return self._balances_async(address, block)
    
    async def _balances_async(self, address: Address, block: Optional[Block] = None) -> Dict[str, Dict[str, Decimal]]:
        balances = await asyncio.gather(*[protocol._balances_async(address, block) for protocol in self.protocols])
        return {type(protocol).__name__: protocol_balances for protocol, protocol_balances in zip(self.protocols, balances)}

_staking = Staking(asynchronous=True)
