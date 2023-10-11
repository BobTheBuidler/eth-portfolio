
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
        protocols = [protocol for protocol in self.protocols if isinstance(protocol, LendingProtocolWithLockedCollateral)]
        balances = await asyncio.gather(*[protocol.balances(address, block) for protocol in protocols])
        return RemoteTokenBalances({
            type(protocol).__name__: token_balances
            for protocol, token_balances in zip(protocols, balances)
            if token_balances is not None
        })

    @a_sync.future
    @stuck_coro_debugger
    async def debt(self, address: Address, block: Optional[Block] = None) -> RemoteTokenBalances:
        balances = await asyncio.gather(*[protocol.debt(address, block) for protocol in self.protocols])
        return RemoteTokenBalances({
            type(protocol).__name__: token_balances
            for protocol, token_balances in zip(self.protocols, balances)
            if token_balances is not None
        })

_lending = Lending()
