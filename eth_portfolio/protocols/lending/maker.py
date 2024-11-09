import asyncio
from typing import Optional

from async_lru import alru_cache
from y import Network, get_price
from y._decorators import stuck_coro_debugger
from y.constants import dai
from y.contracts import Contract
from y.datatypes import Address, Block

from eth_portfolio._utils import Decimal
from eth_portfolio.protocols.lending._base import LendingProtocolWithLockedCollateral
from eth_portfolio.typing import Balance, TokenBalances

try:
    # this is only available in 4.0.0+
    from eth_abi import encode

    encode_bytes = lambda bytestring: encode(["bytes32"], [bytestring])
except ImportError:
    from eth_abi import encode_single

    encode_bytes = lambda bytestring: encode_single("bytes32", bytestring)

yfi = "0x0bc529c00C6401aEF6D220BE8C6Ea1667F6Ad93e"


class Maker(LendingProtocolWithLockedCollateral):
    networks = [Network.Mainnet]

    def __init__(self) -> None:
        self.proxy_registry = Contract("0x4678f0a6958e4D2Bc4F1BAF7Bc52E8F3564f3fE4")
        self.cdp_manager = Contract("0x5ef30b9986345249bc32d8928B7ee64DE9435E39")
        self.vat = Contract("0x35D1b3F3D7966A1DFe207aa4514C12a259A0492B")

    @stuck_coro_debugger
    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances: TokenBalances = TokenBalances()
        ilk = encode_bytes(b"YFI-A")
        urn = await self._urn(address)
        ink = (await self.vat.urns.coroutine(ilk, urn, block_identifier=block)).dict()["ink"]
        if ink:
            balance = ink / Decimal(10**18)
            value = round(balance * Decimal(await get_price(yfi, block, sync=False)), 18)
            balances[yfi] = Balance(balance, value)
        return balances

    @stuck_coro_debugger
    async def _debt(self, address: Address, block: Optional[int] = None) -> TokenBalances:
        ilk = encode_bytes(b"YFI-A")
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
