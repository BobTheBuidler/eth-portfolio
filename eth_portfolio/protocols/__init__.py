
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
        return RemoteTokenBalances({
            type(protocol).__name__: protocol_balances
            async for protocol, protocol_balances
            in a_sync.map(lambda p: p.balances(address, block), self.protocols)
            if protocol_balances is not None
        })

_external = ExternalBalances()
