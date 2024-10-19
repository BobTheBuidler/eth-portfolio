
import logging
from decimal import InvalidOperation
from typing import Optional

import dank_mids
import eth_retry
import y
from dank_mids.structs.data import Decimal
from y._decorators import stuck_coro_debugger
from y.datatypes import Address, Block

from eth_portfolio._utils import _get_price
from eth_portfolio.typing import Balance


logger = logging.getLogger(__name__)

@eth_retry.auto_retry
@stuck_coro_debugger
async def load_eth_balance(address: Address, block: Optional[Block]) -> Balance:
    if balance := await dank_mids.eth.get_balance(address, block_identifier=block):
        price = await _get_price(y.WRAPPED_GAS_COIN, block)
        return Balance(balance.scaled, round(balance.scaled * price, 18))
    return Balance()

@stuck_coro_debugger
async def load_token_balance(token: y.ERC20, address: Address, block: Block) -> Balance:
    try:
        balance = await token.balance_of_readable(address, block, sync=False)
    except y.NonStandardERC20:
        logger.warning("NonStandardERC20 exc for %s", token)
        balance = 0
    if not balance:
        return Balance()
    price = await _get_price(token, block)
    return Balance(round(Decimal(balance), 18), _calc_value(balance, price))

def _calc_value(balance, price) -> Decimal:
    if price is None:
        return Decimal(0)
    # NOTE If balance * price returns a Decimal with precision < 18, rounding is both impossible and unnecessary.
    value = Decimal(balance) * Decimal(price)
    try:
        return round(value, 18)
    except InvalidOperation:
        return value
