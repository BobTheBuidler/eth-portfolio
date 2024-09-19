"""
This module provides asynchronous functions for fetching Ethereum and ERC20 token balances along with their USD values.

Key features:
- Fetches ETH and ERC20 token balances for specified addresses and blocks
- Calculates USD values based on current token prices
- Handles non-standard ERC20 tokens gracefully
- Implements automatic retries for network-related issues
- Uses efficient async operations for improved performance

Main Classes and Functions:
- :func:`~eth_portfolio.loaders.balances.load_eth_balance`: Fetches ETH balance and USD value.
- :func:`~eth_portfolio.loaders.balances.load_token_balance`: Fetches ERC20 token balance and USD value.
- :class:`~y.ERC20`: ERC20 token contract interface.
- :class:`~eth_portfolio.typing.Balance`: Custom object representing balance and value.
- :exc:`~y.NonStandardERC20`: Exception raised for non-standard ERC20 tokens.

Dependencies:
    - dank_mids: Fast Ethereum balance querying
    - eth_retry: Automatic retry mechanism for Ethereum operations
    - y: Comprehensive toolkit for ERC20 token operations and price fetching
    - eth_portfolio._utils: Internal utility for token price retrieval
    - eth_portfolio.typing: Custom type definitions for balance objects

Note: This module is designed to work with asynchronous code. Ensure you're calling these functions
from an async context or use appropriate async runners.
"""

import logging
from decimal import Decimal, InvalidOperation
from typing import Optional

import dank_mids
import eth_retry
from y import ERC20, NonStandardERC20, get_price
from y._decorators import stuck_coro_debugger
from y.constants import WRAPPED_GAS_COIN
from y.datatypes import Address, Block

from eth_portfolio._utils import _get_price
from eth_portfolio.typing import Balance


logger = logging.getLogger(__name__)

@eth_retry.auto_retry
@stuck_coro_debugger
async def load_eth_balance(address: Address, block: Optional[Block]) -> Balance:
    """
    Asynchronously fetches the Ethereum balance for a given address at a specific block.

    This function queries the Ethereum blockchain for the ETH balance of the specified address.
    It also calculates the USD value of the balance using the current ETH price.

    Args:
        address: The Ethereum address to query, as a string or :class:`~y.datatypes.Address`.
        block: The block number for the balance query. If None, uses the latest block. 
            Accepts a string, int, or :class:`~y.datatypes.Block`.

    Returns:
        :class:`~eth_portfolio.typing.Balance`: A custom object containing:
            - `balance`: The ETH balance as a :class:`~decimal.Decimal` (18 decimal places).
            - `value`: The USD value of the balance as a :class:`~decimal.Decimal` (18 decimal places).

    Raises:
        :exc:`~eth_retry.RetryError`: If the balance fetch fails after multiple retries.

    Example:
        >>> balance = await load_eth_balance(address='0x1234...', block=12345678)
        >>> print(f"ETH: {balance.balance}, USD: {balance.value}")
    """
    balance = Decimal(await dank_mids.eth.get_balance(address, block_identifier=block)) / Decimal(10**18)
    value = round(balance * Decimal(await get_price(WRAPPED_GAS_COIN, block, sync=False) if balance else 0), 18)
    return Balance(balance, value)


@stuck_coro_debugger
async def load_token_balance(token: ERC20, address: Address, block: Block) -> Balance:
    """
    Asynchronously fetches the ERC20 token balance for a given address at a specific block.

    This function queries the specified ERC20 token contract for the balance of the given address.
    It also calculates the USD value of the balance using the current token price.

    Args:
        token: The ERC20 token contract instance to query.
        address: The address holding the ERC20 tokens, as a string or :class:`~y.datatypes.Address`.
        block: The block number for the balance query.

    Returns:
        :class:`~eth_portfolio.typing.Balance`: A custom object containing:
            - `balance`: The token balance as a :class:`~decimal.Decimal` (18 decimal places).
            - `value`: The USD value of the balance as a :class:`~decimal.Decimal` (18 decimal places).

    Raises:
        :exc:`~y.NonStandardERC20`: If the token contract doesn't follow the standard ERC20 interface.
            This exception is caught and logged, returning a zero balance in such cases.

    Example:
        >>> balance = await load_token_balance(token=dai_contract, address='0x1234...', block=12345678)
        >>> print(f"Token: {balance.balance}, USD: {balance.value}")
    """
    try:
        balance = await token.balance_of_readable(address, block, sync=False)
    except NonStandardERC20:
        logger.warning("NonStandardERC20 exc for %s", token)
        balance = 0
    if not balance:
        return Balance()
    price = await _get_price(token, block)
    return Balance(round(Decimal(balance), 18), _calc_value(balance, price))


def _calc_value(balance, price) -> Decimal:
    """
    Calculates the USD value of a token balance based on its price.

    This internal function handles the multiplication of balance and price,
    ensuring proper decimal precision and rounding where possible.

    Args:
        balance: The token balance as a float, int, or :class:`~decimal.Decimal`.
        price: The token price in USD as a float, int, or :class:`~decimal.Decimal`.

    Returns:
        :class:`~decimal.Decimal`: The total USD value, rounded to 18 decimal places if possible.
                 If rounding is not possible due to high precision, returns the unrounded value.

    Note:
        Returns :class:`~decimal.Decimal(0)` if the price is None, handling cases where price data is unavailable.

    Example:
        >>> value = _calc_value(balance=1000, price=0.50)
        >>> print(f"USD Value: {value}")
    """
    if price is None:
        return Decimal(0)
    # NOTE If balance * price returns a Decimal with precision < 18, rounding is both impossible and unnecessary.
    value = Decimal(balance) * Decimal(price)
    try:
        return round(value, 18)
    except InvalidOperation:
        return value
