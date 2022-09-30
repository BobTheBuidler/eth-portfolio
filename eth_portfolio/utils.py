
import importlib
import inspect
import logging
import pkgutil
from decimal import Decimal as _Decimal
from functools import cached_property
from types import ModuleType
from typing import Any, Dict, List, Optional, Tuple, Union

from brownie import chain, convert
from pandas import DataFrame  # type: ignore
from y import Contract
from y.classes.common import ERC20
from y.datatypes import Address, Block
from y.exceptions import ContractNotVerified, NonStandardERC20, PriceError
from y.networks import Network
from y.prices.magic import get_price_async
from y.utils.dank_mids import dank_w3

from eth_portfolio import _config
from eth_portfolio.typing import _T

logger = logging.getLogger(__name__)

NON_STANDARD_ERC721 = {
    Network.Mainnet: [
        "0xb47e3cd837dDF8e4c57F05d70Ab865de6e193BBB" # CryptoPunks
    ],
}.get(chain.id, [])

async def get_buffered_chain_height() -> int:
    ''' Returns an int equal to the current height of the chain minus `_config.REORG_BUFFER`.'''
    return await dank_w3.eth.get_block_number() - _config.REORG_BUFFER


class PandableList(List[_T]):
    def __init__(self):
        super().__init__()
    
    @cached_property
    def df(self) -> DataFrame:
        return self._df()
    
    def _df(self) -> DataFrame:
        """ Override this method if you need to manipulate your dataframe before returning it. """
        return DataFrame(self)


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
        if await is_erc721(token):
            return 0
        return await get_price_async(token, block)
    except PriceError:
        desc_str = await _describe_err(token, block)
        if desc_str.startswith('yv'):
            raise
        logger.critical(f'PriceError while fetching price for {desc_str}')
    except NonStandardERC20:
        logger.critical(f'NonStandardERC20 while fetching price for {token}')
    except Exception as e:
        desc_str = await _describe_err(token, block)
        if desc_str.startswith('yv'):
            raise
        logger.critical(f'{type(e).__name__} while fetching price for {desc_str} | {e}')
    return 0

async def is_erc721(token: Address) -> bool:
    # This can probably be improved
    try:
        contract = Contract(token)
    except ContractNotVerified:
        return False
    attrs = 'setApprovalForAll','getApproved','isApprovedForAll'
    if all(hasattr(contract, attr) for attr in attrs):
        return True
    elif contract.address in NON_STANDARD_ERC721:
        return True
    return False

def get_submodules_for_module(module: ModuleType) -> List[ModuleType]:
    """
    Returns a list of submodules of `module`.
    """
    assert isinstance(module, ModuleType), "`module` must be a module"
    return [obj for obj in module.__dict__.values() if isinstance(obj, ModuleType) and obj.__name__.startswith(module.__name__)]

def get_class_defs_from_module(module: ModuleType) -> List[type]:
    """
    Returns a list of class definitions from a module.
    """
    return [obj for obj in module.__dict__.values() if isinstance(obj, type) and obj.__module__ == module.__name__]

def _get_protocols_for_submodule(asynchronous: bool) -> List[type]:
    """
    Used to initialize a submodule's class object.
    Returns a list of initialized protocol objects.
    """
    called_from_module = inspect.getmodule(inspect.stack()[1][0])
    assert called_from_module, "You can only call this function from a module"
    components = [module for module in get_submodules_for_module(called_from_module) if not module.__name__.endswith('._base')]
    return [cls(asynchronous) for component in components for cls in get_class_defs_from_module(component) if cls and not cls.__name__.startswith("_") and not cls.__name__ == "Lending"]

def _import_submodules() -> Dict[str, ModuleType]:
    """ 
    Import all submodules of the module from which this was called, recursively.
    Ignores submodules named `"base"`.
    Returns a dict of `{module.__name__: module}`
    """
    called_from_module = inspect.getmodule(inspect.stack()[1][0])
    if called_from_module is None:
        return {}
    return {
        name: importlib.import_module(called_from_module.__name__ + '.' + name)
        for loader, name, is_pkg in pkgutil.walk_packages(called_from_module.__path__)
        if name != 'base'
    }

def _unpack_indicies(indicies: Union[Block,Tuple[Block,Block]]) -> Tuple[Block,Block]:
    """ Unpacks indicies and returns a tuple (start_block, end_block)."""
    if isinstance(indicies, tuple):
        start_block, end_block = indicies
    else:
        start_block = 0
        end_block = indicies
    return start_block, end_block
