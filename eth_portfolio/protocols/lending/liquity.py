from typing import Optional

from async_lru import alru_cache
from y import Contract, Network, get_price
from y._decorators import stuck_coro_debugger
from y.constants import EEE_ADDRESS
from y.datatypes import Address, Block

from eth_portfolio.protocols.lending._base import LendingProtocolWithLockedCollateral
from eth_portfolio.typing import Balance, TokenBalances

lusd = "0x5f98805A4E8be255a32880FDeC7F6728C6568bA0"


class Liquity(LendingProtocolWithLockedCollateral):
    networks = [Network.Mainnet]

    def __init__(self) -> None:
        self.troveManager = Contract("0xA39739EF8b0231DbFA0DcdA07d7e29faAbCf4bb2")
        self.start_block = 12178557

    @alru_cache(maxsize=128)
    @stuck_coro_debugger
    async def get_trove(self, address: Address, block: Block) -> dict:
        return await self.troveManager.Troves.coroutine(address, block_identifier=block)

    @stuck_coro_debugger
    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances: TokenBalances = TokenBalances(block=block)
        if block and block < self.start_block:
            return balances
        data = await self.get_trove(address, block)
        eth_collateral_balance = data[1]
        if eth_collateral_balance:
            eth_collateral_balance /= 10**18
            value = eth_collateral_balance * await get_price(EEE_ADDRESS, block, sync=False)
            balances[EEE_ADDRESS] = Balance(
                eth_collateral_balance, value, token=EEE_ADDRESS, block=block
            )
        return balances

    @stuck_coro_debugger
    async def _debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances: TokenBalances = TokenBalances(block=block)
        if block and block < self.start_block:
            return balances
        data = await self.get_trove(address, block)
        lusd_debt = data[0]
        if lusd_debt:
            lusd_debt /= 10**18
            value = lusd_debt * await get_price(lusd, block, sync=False)
            balances[lusd] = Balance(lusd_debt, value, token=lusd, block=block)
        return balances
