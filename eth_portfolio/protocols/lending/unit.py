from typing import Optional

from y import Contract, Network
from y._decorators import stuck_coro_debugger
from y.datatypes import Address, Block

from eth_portfolio._decimal import Decimal
from eth_portfolio._utils import _get_price
from eth_portfolio.protocols.lending._base import LendingProtocolWithLockedCollateral
from eth_portfolio.typing import Balance, TokenBalances

# NOTE: This only works for YFI collateral, must extend before using for other collaterals
yfi = "0x0bc529c00C6401aEF6D220BE8C6Ea1667F6Ad93e"
usdp = "0x1456688345527bE1f37E9e627DA0837D6f08C925"


class UnitXyz(LendingProtocolWithLockedCollateral):
    networks = [Network.Mainnet]

    def __init__(self) -> None:
        self.unitVault = Contract("0xb1cff81b9305166ff1efc49a129ad2afcd7bcf19")
        self.start_block = 11315910

    @stuck_coro_debugger
    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances: TokenBalances = TokenBalances(block=block)
        if block and block < self.start_block:
            return balances
        bal: int = await self.unitVault.collaterals.coroutine(yfi, address, block_identifier=block)
        if bal:
            bal = Decimal(bal) / 10**18
            balances[yfi] = Balance(bal, bal * await _get_price(yfi, block), token=yfi, block=block)
        return balances

    @stuck_coro_debugger
    async def _debt(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances: TokenBalances = TokenBalances(block=block)
        if block and block < self.start_block:
            return balances
        # NOTE: This only works for YFI based debt, must extend before using for other collaterals
        if debt := await self.unitVault.getTotalDebt.coroutine(
            yfi, address, block_identifier=block
        ):
            debt = Decimal(debt) / 10**18
            balances[usdp] = Balance(debt, debt, token=usdp, block=block)
        return balances
