
import asyncio
from typing import List, Optional

import a_sync
from y.datatypes import Address, Block

from eth_portfolio.protocols._base import StakingPoolABC
from eth_portfolio.typing import RemoteTokenBalances
from eth_portfolio.utils import (_get_protocols_for_submodule,
                                 _import_submodules)

_import_submodules()


class ExternalBalances:
    def __init__(self) -> None:
        self.protocols: List[StakingPoolABC] = _get_protocols_for_submodule()  # type: ignore
    
    @a_sync.future
    async def balances(self, address: Address, block: Optional[Block] = None) -> RemoteTokenBalances:
        balances = await asyncio.gather(*[protocol.balances(address, block) for protocol in self.protocols])
        return RemoteTokenBalances({type(protocol).__name__: protocol_balances for protocol, protocol_balances in zip(self.protocols, balances) if protocol_balances is not None})

_external = ExternalBalances()
