from asyncio import gather
from typing import List, Optional

from a_sync import igather
from async_lru import alru_cache
from dank_mids.exceptions import Revert
from eth_typing import HexStr
from y import Contract, Network, contract_creation_block_async, get_price
from y._decorators import stuck_coro_debugger
from y.constants import dai
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
dai: Contract


class Maker(LendingProtocolWithLockedCollateral):
    networks = [Network.Mainnet]

    def __init__(self) -> None:
        self.proxy_registry = Contract("0x4678f0a6958e4D2Bc4F1BAF7Bc52E8F3564f3fE4")
        self.cdp_manager = Contract("0x5ef30b9986345249bc32d8928B7ee64DE9435E39")
        self.ilk_registry = Contract("0x5a464C28D19848f44199D003BeF5ecc87d090F87")
        self.vat = Contract("0x35D1b3F3D7966A1DFe207aa4514C12a259A0492B")

    @stuck_coro_debugger
    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        ilks, urn = await gather(self.get_ilks(block), self._urn(address))

        gem_coros = igather(map(self.get_gem, map(str, ilks)))
        ink_coros = igather(
            self.vat.urns.coroutine(ilk, urn, block_identifier=block) for ilk in ilks
        )

        gems, ink_data = await gather(gem_coros, ink_coros)

        balances: TokenBalances = TokenBalances(block=block)
        for token, data in zip(gems, ink_data):
            if ink := data.dict()["ink"]:
                balance = ink / Decimal(10**18)
                value = round(balance * Decimal(await get_price(token, block, sync=False)), 18)
                balances[token] = Balance(balance, value, token=token, block=block)
        return balances

    @stuck_coro_debugger
    async def _debt(self, address: Address, block: Optional[int] = None) -> TokenBalances:
        if block is not None and block <= await contract_creation_block_async(self.ilk_registry):
            return TokenBalances(block=block)

        ilks, urn = await gather(self.get_ilks(block), self._urn(address))

        data = await igather(
            gather(
                self.vat.urns.coroutine(ilk, urn, block_identifier=block),
                self.vat.ilks.coroutine(ilk, block_identifier=block),
            )
            for ilk in ilks
        )

        balances: TokenBalances = TokenBalances(block=block)
        for urns, ilk_info in data:
            art = urns.dict()["art"]
            rate = ilk_info.dict()["rate"]
            debt = art * rate / Decimal(1e45)
            balances[dai.address] += Balance(debt, debt, token=dai, block=block)
        return balances

    async def get_ilks(self, block: Optional[int]) -> List[HexStr]:
        """List all ilks (cdp keys of sorts) for MakerDAO"""
        try:
            return await self.ilk_registry.list.coroutine(block_identifier=block)
        except Revert:
            return []

    @alru_cache
    async def get_gem(self, ilk: bytes) -> str:
        return await self.ilk_registry.gem.coroutine(ilk)

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
