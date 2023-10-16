
import importlib
import inspect
import logging
import pkgutil
from decimal import Decimal as _Decimal
from functools import cached_property
from types import ModuleType
from typing import Dict, List, Optional, Tuple, Union

import sqlite3
from async_lru import alru_cache
from brownie import chain
from brownie.exceptions import ContractNotFound
from eth_abi.exceptions import InsufficientDataBytes
from pandas import DataFrame  # type: ignore
from y import ERC20, Contract, Network
from y.datatypes import Address, Block
from y.exceptions import CantFetchParam, ContractNotVerified, NodeNotSynced, NonStandardERC20, PriceError, yPriceMagicError
from y.prices.magic import get_price
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
        #assert not isinstance(v, _Decimal)
        super().__init__()

async def _describe_err(token: Address, block: Optional[Block]) -> str:
    '''
    Assembles a string used to provide as much useful information as possible in PriceError messages
    '''
    try:
        symbol = await ERC20(token, asynchronous=True).symbol
    except NonStandardERC20:
        symbol = None

    if block is None:
        if symbol:
            return f"{symbol} {token} on {Network.name()}"

        return f"malformed token {token} on {Network.name()}"

    if symbol:
        return f"{symbol} {token} on {Network.name()} at {block}"

    return f"malformed token {token} on {Network.name()} at {block}"

_to_raise = (
    OSError,
    FileNotFoundError,
    NodeNotSynced,
    NotImplementedError,
    sqlite3.OperationalError,
    InsufficientDataBytes,
    UnboundLocalError,
    RuntimeError,
)

async def _get_price(token: Address, block: int = None) -> float:
    try:
        if await is_erc721(token):
            return 0
        return await get_price(token, block, silent=True, sync=False)
    except CantFetchParam as e:
        logger.warning('CantFetchParam %s', e)
    except yPriceMagicError as e:
        # Raise these exceptions
        if isinstance(e.exception, _to_raise) and not isinstance(e.exception, RecursionError):
            raise e.exception
        # The exceptions below are acceptable enough
        elif isinstance(e.exception, NonStandardERC20):
            # Can't get symbol for handling like other excs
            logger.warning(f'NonStandardERC20 while fetching price for {token}')
        elif isinstance(e.exception, PriceError):
            logger.warning(f'PriceError while fetching price for {await _describe_err(token, block)}')
        else:
            logger.warning(f'{e} while fetching price for {await _describe_err(token, block)}')
            logger.warning(e, exc_info=True)
    return 0

@alru_cache(maxsize=None)
async def is_erc721(token: Address) -> bool:
    # This can probably be improved
    try:
        contract = await Contract.coroutine(token)
    except (ContractNotFound, ContractNotVerified):
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

def _get_protocols_for_submodule() -> List[type]:
    """
    Used to initialize a submodule's class object.
    Returns a list of initialized protocol objects.
    """
    called_from_module = inspect.getmodule(inspect.stack()[1][0])
    assert called_from_module, "You can only call this function from a module"
    components = [module for module in get_submodules_for_module(called_from_module) if not module.__name__.endswith('._base')]
    return [
        cls()
        for component in components
        for cls in get_class_defs_from_module(component)
        if cls and not cls.__name__.startswith("_") and
        not cls.__name__ == "Lending" and
        (not hasattr(cls, 'networks') or chain.id in cls.networks)  # type: ignore
    ]

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
        for loader, name, is_pkg in pkgutil.walk_packages(called_from_module.__path__)  # type: ignore
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
