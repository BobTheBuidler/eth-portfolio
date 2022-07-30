
import logging
from decimal import Decimal as _Decimal
from typing import Optional
from brownie import chain

from brownie.network.event import _EventItem
from y import Contract
from y.classes.common import ERC20
from y.datatypes import Address, Block
from y.exceptions import NonStandardERC20, PriceError
from y.networks import Network
from y.prices.magic import get_price_async

logger = logging.getLogger(__name__)

NON_STANDARD_ERC721 = {
    Network.Mainnet: [
        "0xb47e3cd837dDF8e4c57F05d70Ab865de6e193BBB" # CryptoPunks
    ],
}.get(chain.id, [])


class Decimal(_Decimal):
    """
    I'm in the process of moving from floats to decimals, this will help be as I buidl.
    """
    def __init__(self, v) -> None:
        assert not isinstance(v, _Decimal)
        super().__init__()

async def _describe_err(token: Address, block: Optional[Block]) -> str:
    '''
    Assembles a string used to provide as much useful information as possible in PriceError messages
    '''
    try:
        symbol = await ERC20(token).symbol_async
    except NonStandardERC20:
        symbol = None

    if block is None:
        if symbol:
            return f"{symbol} {token} on {Network.name()}"

        return f"malformed token {token} on {Network.name()}"

    if symbol:
        return f"{symbol} {token} on {Network.name()} at {block}"

    return f"malformed token {token} on {Network.name()} at {block}"

async def _get_price(token: Address, block: int = None) -> float:
    # TODO put these somewhere else
    """
    SKIP_PRICE = [  # shitcoins
        "0xa9517B2E61a57350D6555665292dBC632C76adFe",
        "0xb07de4b2989E180F8907B8C7e617637C26cE2776",
        "0x1368452Bfb5Cd127971C8DE22C58fBE89D35A6BF",
        "0x5cB5e2d7Ab9Fd32021dF8F1D3E5269bD437Ec3Bf",
        "0x11068577AE36897fFaB0024F010247B9129459E6",
        "0x9694EED198C1b7aB81ADdaf36255Ea58acf13Fab",
        "0x830Cbe766EE470B67F77ea62a56246863F75f376",
        "0x8F49cB69ee13974D6396FC26B0c0D78044FCb3A7",
        "0x53d345839E7dF5a6c8Cf590C5c703AE255E44816",
        "0xcdBb37f84bf94492b44e26d1F990285401e5423e",
        "0xE256CF1C7caEff4383DabafEe6Dd53910F97213D",
        "0x528Ff33Bf5bf96B5392c10bc4748d9E9Fb5386B2",
    ]
    if token in SKIP_PRICE:
        return 0
    """
    try:
        return await get_price_async(token, block)
    except PriceError:
        desc_str = await _describe_err(token, block)
        if desc_str.startswith('yv'):
            raise
        logger.critical(f'PriceError while fetching price for {desc_str}')
    except Exception as e:
        desc_str = await _describe_err(token, block)
        if desc_str.startswith('yv'):
            raise
        logger.critical(f'{type(e).__name__} while fetching price for {desc_str} | {e}')
    return 0

async def is_erc721(token: Address) -> bool:
    # This can probably be improved
    attrs = 'setApprovalForAll','getApproved','isApprovedForAll'
    contract = Contract(token)
    if all(hasattr(contract, attr) for attr in attrs):
        return True
    elif contract.address in NON_STANDARD_ERC721:
        return True
    return False
