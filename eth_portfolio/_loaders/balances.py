import logging
from decimal import InvalidOperation
from typing import Final

import y
from y._decorators import stuck_coro_debugger
from y.datatypes import Address, Block

from eth_portfolio._decimal import Decimal
from eth_portfolio._utils import _get_price
from eth_portfolio.typing import Balance


_ZERO: Final = Decimal(0)

logger: Final = logging.getLogger(__name__)
log_warning: Final = logger.warning


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
        log_warning("NonStandardERC20 exc for %s", token)
        balance = _ZERO
    token_address = token.address
    if not balance:
        return Balance(token=token_address, block=block)
    price = await _get_price(token_address, block)
    return Balance(
        balance=round(balance, 18),
        usd_value=(
            _ZERO
            if price is None
            else round(Decimal(balance) * Decimal(price), 18)
        ),
        token=token_address,
        block=block,
    )
