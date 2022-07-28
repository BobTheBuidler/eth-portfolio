
from typing import Dict, Optional

from eth_portfolio.lending.compound import Compound
from eth_portfolio.lending.maker import Maker
from eth_portfolio.lending.unit import UnitXyz
from multicall.utils import await_awaitable, gather
from y.datatypes import Address, Block

protocols = [Compound, Maker, UnitXyz]

class Lending:
    def __init__(self, asynchronous: bool = False) -> None:
        self.asynchronous = bool(asynchronous)
        self.protocols = [protocol(asynchronous) for protocol in protocols if protocol]

    def collateral(self, address: Address, block: Optional[Block] = None) -> Dict:
        coro = self.collateral_async(address, block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)

    async def collateral_async(self, address: Address, block: Optional[Block] = None) -> Dict:
        # Under contrcutcion
        collaterals = await gather([
            protocol.collateral_async(address, block)
            for protocol in self.protocols
            if hasattr(protocol, 'collateral')
        ])
        return {
            token: balances
            for protocol_collaterals in collaterals if protocol_collaterals
            for token, balances in protocol_collaterals.items() # if balances['balance'] != 0
        }

    def debt(self, address: Address, block: Optional[Block] = None) -> Dict:
        coro = self.debt_async(address, block)
        if self.asynchronous:
            return coro
        return await_awaitable(coro)
    
    async def debt_async(self, address: Address, block: Optional[Block] = None) -> Dict:
        # Under construction
        debts = await gather([protocol.debt_async(address, block) for protocol in self.protocols])
        return {
            token: balances
            for protocol_debts in debts if protocol_debts
            for token, balances in protocol_debts.items() #if balances['balance'] != 0
        }

lending = Lending(asynchronous=True)
