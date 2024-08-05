
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
    balance = Decimal(await dank_mids.eth.get_balance(address, block_identifier=block)) / Decimal(10**18)
    value = round(balance * Decimal(await get_price(WRAPPED_GAS_COIN, block, sync=False) if balance else 0), 18)
    return Balance(balance, value)

@stuck_coro_debugger
async def load_token_balance(token: ERC20, address: Address, block: Block) -> Balance:
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
    if price is None:
        return Decimal(0)
    # NOTE If balance * price returns a Decimal with precision < 18, rounding is both impossible and unnecessary.
    value = Decimal(balance) * Decimal(price)
    try:
        return round(value, 18)
    except InvalidOperation:
        return value
