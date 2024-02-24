
import asyncio
from typing import List, Optional, Union

import a_sync
from eth_portfolio.protocols.lending._base import (
    LendingProtocol, LendingProtocolWithLockedCollateral)
from eth_portfolio.typing import RemoteTokenBalances
from eth_portfolio.utils import (_get_protocols_for_submodule,
                                 _import_submodules)
from y.datatypes import Address, Block
from y.decorators import stuck_coro_debugger

_import_submodules()


class Lending:
    def __init__(self) -> None:
        self.protocols: List[Union[LendingProtocol, LendingProtocolWithLockedCollateral]] = _get_protocols_for_submodule()  # type: ignore

    @a_sync.future
    @stuck_coro_debugger
    async def collateral(self, address: Address, block: Optional[Block] = None) -> RemoteTokenBalances:
        protocols = (protocol for protocol in self.protocols if isinstance(protocol, LendingProtocolWithLockedCollateral))
        return RemoteTokenBalances({
            type(protocol).__name__: token_balances
            async for protocol, token_balances in a_sync.map(lambda p: p.balances(address, block), protocols)
            if token_balances is not None
        })

    @a_sync.future
    @stuck_coro_debugger
    async def debt(self, address: Address, block: Optional[Block] = None) -> RemoteTokenBalances:
        return RemoteTokenBalances({
            type(protocol).__name__: token_balances
            async for protocol, token_balances in a_sync.map(lambda p: p.debt(address, block), self.protocols)
            if token_balances is not None
        })

_lending = Lending()
