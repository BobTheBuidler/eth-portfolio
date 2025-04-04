import abc
from asyncio import gather
from typing import List, Optional

import a_sync
from a_sync import igather
from a_sync.a_sync import ASyncFunctionSyncDefault, HiddenMethod
from brownie.network.contract import ContractCall
from y import ERC20, Contract
from y._decorators import stuck_coro_debugger
from y.contracts import contract_creation_block
from y.datatypes import Address, Block

from eth_portfolio._utils import Decimal
from eth_portfolio.typing import Balance, TokenBalances


class ProtocolABC(metaclass=abc.ABCMeta):
    @a_sync.future
    async def balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return await self._balances(address, block=block)

    @abc.abstractmethod
    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances: ...


class ProtocolWithStakingABC(ProtocolABC, metaclass=abc.ABCMeta):
    pools: List["StakingPoolABC"]

    @stuck_coro_debugger
    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        return sum(await igather(pool.balances(address, block) for pool in self.pools))  # type: ignore


class StakingPoolABC(ProtocolABC, metaclass=abc.ABCMeta):
    contract_address: Address
    """
    The address of the staking pool.
    """

    balance_method_name: str
    """
    The name of the method that is used to query a staker's balance in the staking pool.
    """

    @a_sync.future
    async def __call__(self, *args, block: Optional[Block] = None, **_) -> int:
        if _:
            raise ValueError(
                "SingleTokenStakingPoolABC.__call__ does not support keyword arguments"
            )
        return await self.contract_call.coroutine(*args, block_identifier=block)

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

    token: ERC20
    """
    The token that is used for staking in this pool.
    """

    @property
    def price(self) -> ASyncFunctionSyncDefault[Block, Decimal]:
        return self.token.price

    @property
    def scale(self) -> HiddenMethod[ERC20, int]:
        return self.token.__scale__

    @stuck_coro_debugger
    async def _balances(self, address: Address, block: Optional[Block] = None) -> TokenBalances:
        balances: TokenBalances = TokenBalances(block=block)
        if self.should_check(block):
            balance = Decimal(await self(address, block=block))  # type: ignore
            if balance:
                scale, price = await gather(self.scale, self.price(block, sync=False))
                balance /= scale  # type: ignore
                balances[self.token.address] = Balance(
                    balance, balance * Decimal(price), token=self.token.address, block=block
                )
        return balances
