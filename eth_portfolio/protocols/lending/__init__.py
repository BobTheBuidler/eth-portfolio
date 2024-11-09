from typing import List, Optional, Union

import a_sync
from eth_portfolio._utils import _get_protocols_for_submodule, _import_submodules
from eth_portfolio.protocols.lending._base import (
    LendingProtocol,
    LendingProtocolWithLockedCollateral,
)
from eth_portfolio.typing import RemoteTokenBalances
from y._decorators import stuck_coro_debugger
from y.datatypes import Address, Block

_import_submodules()

protocols: List[Union[LendingProtocol, LendingProtocolWithLockedCollateral]] = _get_protocols_for_submodule()  # type: ignore [assignment]

has_collateral = lambda protocol: isinstance(protocol, LendingProtocolWithLockedCollateral)


@a_sync.future
@stuck_coro_debugger
async def collateral(address: Address, block: Optional[Block] = None) -> RemoteTokenBalances:
    protocol_balances = a_sync.map(
        lambda protocol: protocol.balances(address, block),
        filter(has_collateral, protocols),
    )
    data = {
        type(protocol).__name__: token_balances
        async for protocol, token_balances in protocol_balances
        if token_balances is not None
    }
    return RemoteTokenBalances(data, block=block)


@a_sync.future
@stuck_coro_debugger
async def debt(address: Address, block: Optional[Block] = None) -> RemoteTokenBalances:
    if not protocols:
        return RemoteTokenBalances(block=block)
    protocol_debts = a_sync.map(
        lambda protocol: protocol.debt(address, block),
        protocols,
    )
    data = {
        type(protocol).__name__: token_balances
        async for protocol, token_balances in protocol_debts
        if token_balances is not None
    }
    return RemoteTokenBalances(data, block=block)
