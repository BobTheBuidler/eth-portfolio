"""
This module contains functions for loading Ethereum and ERC20 token balances, along with their corresponding values.

It interacts with external libraries like `dank_mids` and `eth_retry` to fetch balances from the Ethereum blockchain, 
and it leverages `y` and `eth_portfolio` for token price lookups and calculations.

Dependencies:
    - dank_mids: Provides an interface for querying Ethereum balances.
    - eth_retry: Adds automatic retry mechanisms for Ethereum-related operations.
    - y: A toolkit for fetching ERC20 token balances and prices.
    - eth_portfolio._utils: Internal utility for fetching token prices.
    - eth_portfolio.typing: Defines custom types for the portfolio's balance objects.
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
    Asynchronously loads the Ethereum balance for a given address and block number.

    Args:
        address: The Ethereum address to query.
        block: The block number at which to query the balance. If None, the latest block is used.

    Returns:
        Balance: The balance object containing both the raw Ether balance and its value in USD.

    Example:
        >>> balance = await load_eth_balance(address='0x1234...', block=None)
        >>> print(balance)
    """
    balance = Decimal(await dank_mids.eth.get_balance(address, block_identifier=block)) / Decimal(10**18)
    value = round(balance * Decimal(await get_price(WRAPPED_GAS_COIN, block, sync=False) if balance else 0), 18)
    return Balance(balance, value)

@stuck_coro_debugger
async def load_token_balance(token: ERC20, address: Address, block: Block) -> Balance:
    """
    Asynchronously loads the ERC20 token balance for a given address and block number.

    Args:
        token: The ERC20 token contract to query.
        address: The address holding the ERC20 token.
        block: The block number at which to query the balance.

    Returns:
        Balance: The balance object containing both the raw token balance and its value in USD.

    Raises:
        NonStandardERC20: If the token does not follow the standard ERC20 contract behavior.

    Example:
        >>> balance = await load_token_balance(token=my_erc20_token, address='0x1234...', block=12345678)
        >>> print(balance)
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
    Calculates the value of a given token balance based on its price.

    Args:
        balance: The token balance (in raw units).
        price: The price of the token in USD.

    Returns:
        Decimal: The total value of the token balance in USD, rounded to 18 decimal places.

    Example:
        >>> value = _calc_value(balance=1000, price=0.50)
        >>> print(value)
        500.0
    """
    if price is None:
        return Decimal(0)
    # NOTE If balance * price returns a Decimal with precision < 18, rounding is both impossible and unnecessary.
    value = Decimal(balance) * Decimal(price)
    try:
        return round(value, 18)
    except InvalidOperation:
        return value
