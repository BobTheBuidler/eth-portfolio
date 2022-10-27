
import abc
import asyncio
from typing import Any, Awaitable, Callable, Coroutine, List, Optional

from brownie.network.contract import ContractCall
from eth_portfolio._decorators import await_if_sync
from eth_portfolio.typing import Balance, TokenBalances
from eth_portfolio.utils import Decimal
from y import ERC20, Contract
from y.contracts import contract_creation_block
from y.datatypes import Address, Block


class ProtocolABC(metaclass=abc.ABCMeta):
    asynchronous: bool
    def __init__(self, asynchronous: bool) -> None:
        self.asynchronous = asynchronous

    @await_if_sync
    def balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return self._balances_async(address, block) # type: ignore
    
    @abc.abstractmethod
    async def _balances_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        """ This is the method you must override when implementing any new protocol. """


class ProtocolWithStakingABC(ProtocolABC, metaclass=abc.ABCMeta):
    pools: List["StakingPoolABC"]
    
    async def _balances_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return sum(await asyncio.gather(*[pool._balances_async(address, block) for pool in self.pools]))  # type: ignore


class StakingPoolABC(ProtocolABC, metaclass=abc.ABCMeta):
    contract_address: Address
    balance_method_name: str

    def __call__(self, *args, block: Optional[Block] = None, **_) -> int:
        if _:
            raise ValueError("SingleTokenStakingPoolABC.__call__ does not support keyword arguments")
        if self.asynchronous or asyncio.get_event_loop().is_running():
            return self.contract_call.coroutine(*args, block_identifier=block)
        return self.contract_call(*args, block_identifier=block)

    @property
    def contract(self) -> Contract:
        return Contract(self.contract_address)
    
    @property
    def contract_call(self) -> ContractCall:
        return getattr(self.contract, self.balance_method_name)
    
    @property
    def deploy_block(self) -> Block:
        return contract_creation_block(self.contract_address)
    
    def should_check(self, block: Optional[Block]) -> bool:
        return block is None or block >= self.deploy_block


class SingleTokenStakingPoolABC(StakingPoolABC, metaclass=abc.ABCMeta):
    token: ERC20
    """
    Works for any contract that has a view method with the following signature:

    ```
    methodName(address) -> uint256
    ```

    In the above example:
     - ``address`` is the user's address, provided at runtime.
     - ``methodName`` is whatever string you set for the staking pool's ``balance_method_name``.
     - ``uint256`` is the user's ``token`` balance held in ``contract_address`` at the queried block.
    """

    @property
    def price(self) -> Callable[[Block], Coroutine[Any, Any, Decimal]]:
        return self.token.price_async
    
    @property
    def scale(self) -> Awaitable[int]:
        return self.token.scale
    
    async def _balances_async(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances: TokenBalances = TokenBalances()
        if self.should_check(block):
            balance = Decimal(await self(address, block=block))  # type: ignore
            if balance:
                scale, price = await asyncio.gather(self.scale, self.price(block))
                balance /= scale  # type: ignore
                balances[self.token.address] = Balance(balance, balance * Decimal(price))
        return balances
