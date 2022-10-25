
from typing import Optional

from async_lru import alru_cache
from brownie import chain
from eth_portfolio._decorators import await_if_sync
from eth_portfolio.protocols.lending._base import \
    LendingProtocolWithLockedCollateral
from eth_portfolio.typing import Balance, TokenBalances
from y import Contract, Network, get_price_async
from y.constants import EEE_ADDRESS
from y.datatypes import Address, Block

lusd = '0x5f98805A4E8be255a32880FDeC7F6728C6568bA0'

class Liquity(LendingProtocolWithLockedCollateral):
    networks = [Network.Mainnet]
    
    def __init__(self, asynchronous: bool = False) -> None:
        self.asynchronous = asynchronous
        self.troveManager = Contract("0xA39739EF8b0231DbFA0DcdA07d7e29faAbCf4bb2")
        self.start_block = 12178557
    
    @alru_cache(maxsize=128)
    async def get_trove(self, address: Address, block: Block) -> dict:
        return await self.troveManager.Troves.coroutine(address, block_identifier=block)
    
    async def _balances_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances: TokenBalances = TokenBalances()
        if block and block < self.start_block:
            return balances
        data = await self.get_trove(address, block)
        eth_collateral_balance = data[1]
        if eth_collateral_balance:
            eth_collateral_balance /= 1e18
            value = eth_collateral_balance * await get_price_async(EEE_ADDRESS, block)
            balances[EEE_ADDRESS] = Balance(eth_collateral_balance, value)
        return balances

    @await_if_sync
    def debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._debt_async(address, block) # type: ignore
    
    async def _debt_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances: TokenBalances = TokenBalances()
        if block and block < self.start_block:
            return 
        data = await self.get_trove(address, block)
        lusd_debt = data[0]
        if lusd_debt:
            lusd_debt /= 1e18
            value = lusd_debt * await get_price_async(lusd, block)
            balances[lusd] = Balance(lusd_debt, value)
        return balances

#liquity = Liquity(asynchronous=True) if chain.id == Network.Mainnet else None
