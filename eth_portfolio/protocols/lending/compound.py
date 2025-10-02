from asyncio import gather
from typing import List, Optional

import a_sync
from a_sync import igather
from async_lru import alru_cache
from brownie import ZERO_ADDRESS, Contract
from eth_typing import ChecksumAddress
from y import ERC20, Contract, map_prices, weth
from y._decorators import stuck_coro_debugger
from y.datatypes import Block
from y.exceptions import ContractNotVerified
from y.prices.lending.compound import CToken, compound

from eth_portfolio._utils import Decimal
from eth_portfolio.protocols.lending._base import LendingProtocol
from eth_portfolio.typing import Balance, TokenBalances


def _get_contract(market: CToken) -> Optional[Contract]:
    try:
        return market.contract
    except ContractNotVerified:
        # We will skip these for now. Might consider supporting them later if necessary.
        return None


class Compound(LendingProtocol):
    _markets: List[Contract]

    @a_sync.future
    @alru_cache(ttl=300)
    @stuck_coro_debugger
    async def underlyings(self) -> List[ERC20]:
        """
        Fetches the underlying ERC20 tokens for all Compound markets.

        This method gathers all markets from the Compound protocol's trollers
        and filters out those that do not have a `borrowBalanceStored` attribute
        by using the :func:`hasattr` function directly on the result of
        :func:`_get_contract`. It then separates markets into those that use
        the native gas token and those that have an underlying ERC20 token,
        fetching the underlying tokens accordingly.

        Returns:
            A list of :class:`~y.classes.common.ERC20` instances representing the underlying tokens.

        Examples:
            >>> compound = Compound()
            >>> underlyings = await compound.underlyings()
            >>> for token in underlyings:
            ...     print(token.symbol)

        See Also:
            - :meth:`markets`: To get the list of market contracts.
        """
        all_markets: List[List[CToken]] = await igather(
            comp.markets for comp in compound.trollers.values()
        )
        markets: List[Contract] = [
            market.contract
            for troller in all_markets
            for market in troller
            if hasattr(_get_contract(market), "borrowBalanceStored")
        ]  # this last part takes out xinv
        gas_token_markets = [market for market in markets if not hasattr(market, "underlying")]
        other_markets = [market for market in markets if hasattr(market, "underlying")]

        markets = gas_token_markets + other_markets
        underlyings = [weth for market in gas_token_markets] + await igather(
            market.underlying for market in other_markets
        )

        markets_zip = zip(markets, underlyings)
        self._markets, underlyings = [], []
        for contract, underlying in markets_zip:
            if underlying != ZERO_ADDRESS:
                self._markets.append(contract)
                underlyings.append(underlying)
        return [ERC20(underlying, asynchronous=True) for underlying in underlyings]

    @a_sync.future
    @stuck_coro_debugger
    async def markets(self) -> List[Contract]:
        """
        Fetches the list of market contracts for the Compound protocol.

        This method ensures that the underlying tokens are fetched first,
        as they are used to determine the markets.

        Returns:
            A list of :class:`~brownie.network.contract.Contract` instances representing the markets.

        Examples:
            >>> compound = Compound()
            >>> markets = await compound.markets()
            >>> for market in markets:
            ...     print(market.address)

        See Also:
            - :meth:`underlyings`: To get the list of underlying tokens.
        """
        await self.underlyings()
        return self._markets

    async def _debt(self, address: ChecksumAddress, block: Optional[Block] = None) -> TokenBalances:
        """
        Calculates the debt balance for a given address in the Compound protocol.

        This method fetches the borrow balance for each market and calculates
        the debt in terms of the underlying token and its USD value.

        Args:
            address: The Ethereum address to calculate the debt for.
            block: The block number to query. Defaults to the latest block.

        Returns:
            A :class:`~eth_portfolio.typing.TokenBalances` object representing the debt balances.

        Examples:
            >>> compound = Compound()
            >>> debt_balances = await compound._debt("0x1234567890abcdef1234567890abcdef12345678")
            >>> for token, balance in debt_balances.items():
            ...     print(f"Token: {token}, Balance: {balance.balance}, USD Value: {balance.usd_value}")

        See Also:
            - :meth:`debt`: Public method to get the debt balances.
        """
        # if ypricemagic doesn't support any Compound forks on current chain
        if len(compound.trollers) == 0:
            return TokenBalances(block=block)

        address = str(address)
        markets: List[Contract]
        underlyings: List[ERC20]
        markets, underlyings = await gather(self.markets(), self.underlyings())
        debt_data, underlying_scale = await gather(
            igather(_borrow_balance_stored(market, address, block) for market in markets),
            igather(underlying.__scale__ for underlying in underlyings),
        )

        balances: TokenBalances = TokenBalances(block=block)
        if debts := {
            underlying: Decimal(debt) / scale
            for underlying, scale, debt in zip(underlyings, underlying_scale, debt_data)
            if debt
        }:
            async for underlying, price in map_prices(debts, block=block):
                debt = debts.pop(underlying)
                balances[underlying] += Balance(
                    debt, debt * Decimal(price), token=underlying.address, block=block
                )
        return balances


@stuck_coro_debugger
async def _borrow_balance_stored(
    market: Contract, address: ChecksumAddress, block: Optional[Block] = None
) -> Optional[int]:
    """
    Fetches the stored borrow balance for a given market and address.

    This function attempts to call the `borrowBalanceStored` method on the
    market contract. If the call reverts, it returns None.

    Args:
        market: The market contract to query.
        address: The Ethereum address to fetch the borrow balance for.
        block: The block number to query. Defaults to the latest block.

    Returns:
        The stored borrow balance as an integer, or None if the call reverts.

    Examples:
        >>> market = Contract.from_explorer("0x1234567890abcdef1234567890abcdef12345678")
        >>> balance = await _borrow_balance_stored(market, "0xabcdefabcdefabcdefabcdefabcdefabcdef")
        >>> print(balance)

    See Also:
        - :meth:`_debt`: Uses this function to calculate debt balances.
    """
    try:
        return await market.borrowBalanceStored.coroutine(str(address), block_identifier=block)
    except ValueError as e:
        if str(e) != "No data was returned - the call likely reverted":
            raise
        return None
