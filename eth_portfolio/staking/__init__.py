
import asyncio
from typing import Dict, List, Optional

from eth_portfolio._decorators import await_if_sync
from eth_portfolio.staking._base import StakingPool
from eth_portfolio.typing import StakedTokenBalances, TokenBalances
from eth_portfolio.utils import (_get_protocols_for_submodule,
                                 _import_submodules)
from y.datatypes import Address, Block

_import_submodules()


class Staking:
    def __init__(self, asynchronous: bool) -> None:
        self.asynchronous = asynchronous
        self.protocols: List[StakingPool] = _get_protocols_for_submodule(asynchronous)
    
    @await_if_sync
    def balances(self, address: Address, block: Optional[Block] = None) -> Dict[str, TokenBalances]:
        return self._balances_async(address, block) # type: ignore
    
    async def _balances_async(self, address: Address, block: Optional[Block] = None) -> StakedTokenBalances:
        balances = await asyncio.gather(*[protocol._balances_async(address, block) for protocol in self.protocols])
        return {type(protocol).__name__: protocol_balances for protocol, protocol_balances in zip(self.protocols, balances)}

_staking = Staking(asynchronous=True)
