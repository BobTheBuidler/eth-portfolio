
import asyncio
from decimal import Decimal
from typing import Dict, Optional

from eth_portfolio.staking.convex import Convex
from multicall.utils import await_awaitable
from y.datatypes import Address, Block

protocols = [Convex]

class Staking:
    def __init__(self, asynchronous: bool) -> None:
        self.asynchronous = asynchronous
        self.protocols = [protocol(asynchronous) for protocol in protocols if protocol]
    
    def balances(self, address: Address, block: Optional[Block] = None) -> Dict[str, Dict[str, Decimal]]:
        coro = self._balances_async(address, block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def _balances_async(self, address: Address, block: Optional[Block] = None) -> Dict[str, Dict[str, Decimal]]:
        balances = await asyncio.gather(*[protocol.balances_async(address, block) for protocol in self.protocols])
        return {type(protocol).__name__: protocol_balances for protocol, protocol_balances in zip(self.protocols, balances)}

staking = Staking(asynchronous=True)
