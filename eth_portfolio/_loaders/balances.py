import logging
from decimal import InvalidOperation

import y
from y._decorators import stuck_coro_debugger
from y.datatypes import Address, Block

from eth_portfolio._decimal import Decimal
from eth_portfolio._utils import _get_price
from eth_portfolio.typing import Balance

logger = logging.getLogger(__name__)


@stuck_coro_debugger
async def load_token_balance(token: y.ERC20, address: Address, block: Block) -> Balance:
    """
    Asynchronously fetch the ERC20 token balance and its USD value for a given address at a specific block.

    Args:
        token: The ERC20 token contract to query.
        address: The address holding the ERC20 tokens.
        block: The block number for the balance query.

    Returns:
        :class:`~eth_portfolio.typing.Balance`: A custom object containing:
            - balance: The token balance (in token's smallest unit).
            - value: The USD value of the balance (18 decimal places).
            - token: The ERC20 token which was checked.
            - block: The block number where the balance was taken.

    Note:
        Non-standard ERC20 tokens are handled gracefully, returning a zero balance.

    Example:
        >>> balance = await load_token_balance(token=dai_contract, address='0x1234...', block=12345678)
        >>> print(f"Token: {balance.token}, Value: {balance.balance}, USD: {balance.usd_value}")
    """
    try:
        balance = await token.balance_of_readable(address, block, sync=False)
    except y.NonStandardERC20:
        logger.warning("NonStandardERC20 exc for %s", token)
        balance = 0
    if not balance:
        return Balance(token=token.address, block=block)
    price = await _get_price(token, block)
    return Balance(
        round(Decimal(balance), 18), _calc_value(balance, price), token=token.address, block=block
    )


def _calc_value(balance, price) -> Decimal:
    """
    Calculate the USD value of a token balance based on its price.

    Args:
        balance: The token balance.
        price: The token price in USD.

    Returns:
        The total USD value, rounded to 18 decimal places if possible.
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
