
import asyncio
from typing import Optional

import a_sync
from async_lru import alru_cache
from brownie import chain
from eth_abi import encode_single
from y import Network, get_price
from y.constants import dai
from y.contracts import Contract
from y.datatypes import Address, Block
from y.decorators import stuck_coro_debugger

from eth_portfolio.protocols._base import ProtocolABC
from eth_portfolio.protocols.lending._base import \
    LendingProtocolWithLockedCollateral
from eth_portfolio.typing import Balance, TokenBalances
from eth_portfolio.utils import Decimal

yfi = "0x0bc529c00C6401aEF6D220BE8C6Ea1667F6Ad93e"

class Maker(LendingProtocolWithLockedCollateral):
    networks = [Network.Mainnet]

    def __init__(self) -> None:
        self.proxy_registry = Contract('0x4678f0a6958e4D2Bc4F1BAF7Bc52E8F3564f3fE4')
        self.cdp_manager = Contract('0x5ef30b9986345249bc32d8928B7ee64DE9435E39')
        self.vat = Contract('0x35D1b3F3D7966A1DFe207aa4514C12a259A0492B')
    
    @stuck_coro_debugger
    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances: TokenBalances = TokenBalances()
        ilk = encode_single('bytes32', b'YFI-A')
        urn = await self._urn(address)
        ink = (await self.vat.urns.coroutine(ilk, urn, block_identifier=block)).dict()["ink"]
        if ink:
            balance = ink / Decimal(1e18)
            value = round(balance * Decimal(await get_price(yfi, block, sync=False)), 18)
            balances[yfi] = Balance(balance, value)
        return balances
    
    @stuck_coro_debugger
    async def _debt(self, address: Address, block: Optional[int] = None) -> TokenBalances:
        ilk = encode_single('bytes32', b'YFI-A')
        urn = await self._urn(address)
        urns, ilks = await asyncio.gather(
            self.vat.urns.coroutine(ilk, urn, block_identifier=block),
            self.vat.ilks.coroutine(ilk, block_identifier=block),
        )
        art = urns.dict()["art"]
        rate = ilks.dict()["rate"]
        debt = art * rate / Decimal(1e45)
        balances: TokenBalances = TokenBalances()
        balances[dai] += Balance(debt, debt)
        return balances

    @alru_cache
    async def _proxy(self, address: Address) -> Address:
        return await self.proxy_registry.proxies.coroutine(address)
    
    @alru_cache
    async def _cdp(self, address: Address) -> Address:
        proxy = await self._proxy(address)
        return await self.cdp_manager.first.coroutine(proxy)
    
    @alru_cache
    async def _urn(self, address: Address) -> Address:
        cdp = await self._cdp(address)
        return await self.cdp_manager.urns.coroutine(cdp)

class MakerDSR(ProtocolABC):
    networks = [Network.Mainnet]
    def __init__(self) -> None:
        self.dsr_manager = Contract('0x373238337Bfe1146fb49989fc222523f83081dDb')
        self.pot = Contract('0x197E90f9FAD81970bA7976f33CbD77088E5D7cf7')
        
    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        pie, exchange_rate = await asyncio.gather(
            self.dsr_manager.pieOf.coroutine(address, block_identifier=block),
            self._exchange_rate(block),
        )
        dai_in_dsr = pie * exchange_rate / 10 ** 18
        return TokenBalances({dai: Balance(dai_in_dsr, dai_in_dsr)})
    
    async def _exchange_rate(self, block: Optional[Block] = None):
        return await self.pot.chi.coroutine(block_identifier=block) / 10 ** 18
