from typing import List, Optional

import a_sync
from y.datatypes import Address, Block

from eth_portfolio._utils import _get_protocols_for_submodule, _import_submodules
from eth_portfolio.protocols import lending
from eth_portfolio.protocols._base import StakingPoolABC
from eth_portfolio.typing import RemoteTokenBalances

_import_submodules()

protocols: List[StakingPoolABC] = _get_protocols_for_submodule()  # type: ignore [assignment]


@a_sync.future
async def balances(address: Address, block: Optional[Block] = None) -> RemoteTokenBalances:
    if not protocols:
        return RemoteTokenBalances()
    protocol_balances = a_sync.map(
        lambda protocol: protocol.balances(address, block),
        protocols,
    )
    data = {
        type(protocol).__name__: protocol_balances
        async for protocol, protocol_balances in protocol_balances
        if protocol_balances is not None
    }
    return RemoteTokenBalances(data)
