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
    if price is None:
        return Decimal(0)
    # NOTE If balance * price returns a Decimal with precision < 18, rounding is both impossible and unnecessary.
    value = Decimal(balance) * Decimal(price)
    try:
        return round(value, 18)
    except InvalidOperation:
        return value
