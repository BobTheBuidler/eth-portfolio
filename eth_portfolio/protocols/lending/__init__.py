
from typing import List, Optional, Union

import a_sync
from eth_portfolio._utils import (_get_protocols_for_submodule,
                                 _import_submodules)
from eth_portfolio.protocols.lending._base import (
    LendingProtocol, LendingProtocolWithLockedCollateral)
from eth_portfolio.typing import RemoteTokenBalances
from y._decorators import stuck_coro_debugger
from y.datatypes import Address, Block

_import_submodules()

protocols: List[Union[LendingProtocol, LendingProtocolWithLockedCollateral]] = _get_protocols_for_submodule()  # type: ignore [assignment]

@a_sync.future
@stuck_coro_debugger
async def collateral(address: Address, block: Optional[Block] = None) -> RemoteTokenBalances:
    return RemoteTokenBalances({
        type(protocol).__name__: token_balances
        async for protocol, token_balances
        in a_sync.map(
            lambda p: p.balances(address, block),
            (protocol for protocol in protocols if isinstance(protocol, LendingProtocolWithLockedCollateral)),
        )
        if token_balances is not None
    })

@a_sync.future
@stuck_coro_debugger
async def debt(address: Address, block: Optional[Block] = None) -> RemoteTokenBalances:
    if not protocols:
        return RemoteTokenBalances()
    return RemoteTokenBalances({
        type(protocol).__name__: token_balances
        async for protocol, token_balances in a_sync.map(lambda p: p.debt(address, block), protocols)
        if token_balances is not None
    })
