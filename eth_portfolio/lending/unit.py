
from typing import Optional

from brownie import chain
from eth_portfolio._decorators import await_if_sync
from eth_portfolio.lending._base import LendingProtocolWithLockedCollateral
from eth_portfolio.typing import TokenBalances
from y import Contract, Network, get_price_async
from y.datatypes import Address, Block

# NOTE: This only works for YFI collateral, must extend before using for other collaterals
yfi = "0x0bc529c00C6401aEF6D220BE8C6Ea1667F6Ad93e"
usdp = '0x1456688345527bE1f37E9e627DA0837D6f08C925'

class UnitXyz(LendingProtocolWithLockedCollateral):
    def __init__(self, asynchronous: bool = False) -> None:
        self.asynchronous = bool(asynchronous)
        self.unitVault = Contract("0xb1cff81b9305166ff1efc49a129ad2afcd7bcf19")
        self.start_block = 11315910
    
    @await_if_sync
    def collateral(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._collateral_async(address, block) # type: ignore
    
    async def _collateral_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        if block and block < self.start_block:
            return {}
        
        bal = await self.unitVault.collaterals.coroutine(yfi, address, block_identifier=block)
        if bal:
            return {
                yfi: {
                    'balance': bal / 1e18,
                    'usd value': bal / 1e18 * await get_price_async(yfi, block),
                }
            }
        return {}

    @await_if_sync
    def debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._debt_async(address, block) # type: ignore
    
    async def _debt_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        if block and block < self.start_block:
            return {}
        # NOTE: This only works for YFI based debt, must extend before using for other collaterals
        debt = await self.unitVault.getTotalDebt.coroutine(yfi, address, block_identifier=block) / 1e18
        if debt:
            return {usdp: {'balance': debt, 'usd value': debt}}
        return {}

unit = UnitXyz(asynchronous=True) if chain.id == Network.Mainnet else None

