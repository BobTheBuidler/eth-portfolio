from asyncio import gather
from typing import Optional

from y import Contract, Network, dai
from y.datatypes import Address, Block

from eth_portfolio._decimal import Decimal
from eth_portfolio.protocols._base import ProtocolABC
from eth_portfolio.typing import Balance, TokenBalances


class MakerDSR(ProtocolABC):
    networks = [Network.Mainnet]

    def __init__(self) -> None:
        self.dsr_manager = Contract("0x373238337Bfe1146fb49989fc222523f83081dDb")
        self.pot = Contract("0x197E90f9FAD81970bA7976f33CbD77088E5D7cf7")

    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances = TokenBalances(block=block)
        pie, exchange_rate = await gather(
            self.dsr_manager.pieOf.coroutine(address, block_identifier=block),
            self._exchange_rate(block),
        )
        if pie:
            dai_in_dsr = pie * exchange_rate / 10**18
            balances[dai] = Balance(dai_in_dsr, dai_in_dsr, token=dai, block=block)
        return balances

    async def _exchange_rate(self, block: Optional[Block] = None) -> Decimal:
        return Decimal(await self.pot.chi.coroutine(block_identifier=block)) / 10**27
