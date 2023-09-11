
import decimal
from typing import Optional, Tuple

import eth_retry
from y import ERC20, get_price
from y.constants import WRAPPED_GAS_COIN
from y.datatypes import Address, Block
from y.utils.dank_mids import dank_w3

from eth_portfolio.typing import Balance
from eth_portfolio.utils import _get_price


@eth_retry.auto_retry
async def load_eth_balance(address: Address, block: Optional[Block]) -> Balance:
    balance = decimal.Decimal(await dank_w3.eth.get_balance(address, block_identifier=block)) / decimal.Decimal(1e18)
    value = round(balance * decimal.Decimal(await get_price(WRAPPED_GAS_COIN, block, sync=False) if balance else 0), 18)
    return Balance(balance, value)

async def load_token_balance(token: ERC20, address: Address, block: Block) -> Tuple[ERC20, Optional[Balance]]:
    balance = await token.balance_of_readable(address, block, sync=False)
    if not balance:
        return
    price = await _get_price(token, block)
    return token, Balance(round(decimal.Decimal(balance), 18), _calc_value(balance, price))

def _calc_value(balance, price) -> decimal.Decimal:
    if price is None:
        return decimal.Decimal(0)
    # NOTE If balance * price returns a Decimal with precision < 18, rounding is both impossible and unnecessary.
    value = decimal.Decimal(balance) * decimal.Decimal(price)
    try:
        return round(value, 18)
    except decimal.InvalidOperation:
        return value