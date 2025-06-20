import asyncio
from typing import Final, Optional

import y
from y.datatypes import Address, Block

from eth_portfolio import _decimal
from eth_portfolio.protocols._base import ProtocolABC
from eth_portfolio.typing import Balance, TokenBalances


gather: Final = asyncio.gather

Contract: Final = y.Contract
Network: Final = y.Network
contract_creation_block: Final = y.contract_creation_block
dai: Final = y.dai

Decimal: Final = _decimal.Decimal


class MakerDSR(ProtocolABC):
    networks = [Network.Mainnet]

    def __init__(self) -> None:
        dsr_manager = "0x373238337Bfe1146fb49989fc222523f83081dDb"
        pot = "0x197E90f9FAD81970bA7976f33CbD77088E5D7cf7"
        self.dsr_manager = Contract(dsr_manager)
        self.pot = Contract(pot)
        self._start_block = max(contract_creation_block(dsr_manager), contract_creation_block(pot))
        self._get_chi = self.pot.chi.coroutine

    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances = TokenBalances(block=block)
        if block and block < self._start_block:
            return balances
        pie, exchange_rate = await gather(
            self.dsr_manager.pieOf.coroutine(address, block_identifier=block),
            self._exchange_rate(block),
        )
        if pie:
            dai_in_dsr = pie * exchange_rate / 10**18
            balances[dai] = Balance(dai_in_dsr, dai_in_dsr, token=dai, block=block)
        return balances

    async def _exchange_rate(self, block: Optional[Block] = None) -> Decimal:
        return Decimal(await self._get_chi(block_identifier=block)) / 10**27
