import logging
import sqlite3
from abc import abstractmethod
from datetime import datetime
from functools import cached_property
from typing import (
    TYPE_CHECKING,
    AsyncGenerator,
    AsyncIterator,
    Final,
    Generic,
    List,
    Optional,
    Tuple,
    TypeVar,
    Union,
)

import dank_mids
from a_sync import ASyncGenericBase, ASyncIterable, ASyncIterator, as_yielded
from async_lru import alru_cache
from brownie import chain
from brownie.exceptions import ContractNotFound
from faster_eth_abi.exceptions import InsufficientDataBytes
from eth_typing import ChecksumAddress
from pandas import DataFrame  # type: ignore
from y import ERC20, Contract, Network
from y.constants import CHAINID, NETWORK_NAME
from y.datatypes import AddressOrContract, Block
from y.exceptions import (
    CantFetchParam,
    ContractNotVerified,
    NodeNotSynced,
    NonStandardERC20,
    PriceError,
    reraise_excs_with_extra_context,
    yPriceMagicError,
)
from y.prices.magic import get_price

from eth_portfolio import _config, _decimal
from eth_portfolio.typing import _T

if TYPE_CHECKING:
    from eth_portfolio.structs import LedgerEntry


logger: Final = logging.getLogger(__name__)

NON_STANDARD_ERC721: Final = {
    Network.Mainnet: ["0xb47e3cd837dDF8e4c57F05d70Ab865de6e193BBB"],  # CryptoPunks
}.get(CHAINID, [])


async def get_buffered_chain_height() -> int:
    """Returns an int equal to the current height of the chain minus `_config.REORG_BUFFER`."""
    return await dank_mids.eth.get_block_number() - _config.REORG_BUFFER


class PandableList(List[_T]):
    @cached_property
    def df(self) -> DataFrame:
        return self._df()

    def _df(self) -> DataFrame:
        """Override this method if you need to manipulate your dataframe before returning it."""
        return DataFrame(self)


class Decimal(_decimal.Decimal):
    """
    I'm in the process of moving from floats to decimals, this will help be as I buidl.
    """

    # TODO i forget why I had this lol, should I delete?

    def __init__(self, v) -> None:
        # assert not isinstance(v, _decimal.Decimal)
        super().__init__()


async def _describe_err(token: AddressOrContract, block: Optional[Block]) -> str:
    """
    Assembles a string used to provide as much useful information as possible in PriceError messages
    """
    try:
        symbol = await ERC20(token, asynchronous=True).symbol
    except NonStandardERC20:
        symbol = None

    if block is None:
        if symbol:
            return f"{symbol} {token} on {NETWORK_NAME}"

        return f"malformed token {token} on {NETWORK_NAME}"

    if symbol:
        return f"{symbol} {token} on {NETWORK_NAME} at {block}"

    return f"malformed token {token} on {NETWORK_NAME} at {block}"


_to_raise: Final = (
    OSError,
    FileNotFoundError,
    NodeNotSynced,
    NotImplementedError,
    sqlite3.OperationalError,
    InsufficientDataBytes,
    UnboundLocalError,
    RuntimeError,
)


async def _get_price(token: AddressOrContract, block: Optional[int] = None) -> _decimal.Decimal:
    token = str(token)
    with reraise_excs_with_extra_context(token, block):
        try:
            if await is_erc721(token):
                return _decimal.Decimal(0)
            maybe_float = await get_price(token, block, silent=True, sync=False)
            dprice = _decimal.Decimal(maybe_float)
            return round(dprice, 18)
        except CantFetchParam as e:
            logger.warning("CantFetchParam %s", e)
        except yPriceMagicError as e:
            # Raise these exceptions
            if isinstance(e.exception, _to_raise) and not isinstance(e.exception, RecursionError):
                raise e.exception
            # The exceptions below are acceptable enough
            elif isinstance(e.exception, NonStandardERC20):
                # Can't get symbol for handling like other excs
                logger.warning(f"NonStandardERC20 while fetching price for {token}")
            elif isinstance(e.exception, PriceError):
                logger.warning(
                    f"PriceError while fetching price for {await _describe_err(token, block)}"
                )
            else:
                logger.warning(f"{e} while fetching price for {await _describe_err(token, block)}")
                logger.warning(e, exc_info=True)
    return _decimal.Decimal(0)


@alru_cache(maxsize=None)
async def is_erc721(token: ChecksumAddress) -> bool:
    # This can probably be improved
    try:
        contract = await Contract.coroutine(token)
    except (ContractNotFound, ContractNotVerified):
        return False
    attrs = "setApprovalForAll", "getApproved", "isApprovedForAll"
    if all(hasattr(contract, attr) for attr in attrs):
        return True
    elif contract.address in NON_STANDARD_ERC721:
        return True
    return False


def _unpack_indicies(indicies: Union[Block, Tuple[Block, Block]]) -> Tuple[Block, Block]:
    """Unpacks indicies and returns a tuple (start_block, end_block)."""
    if isinstance(indicies, tuple):
        start_block, end_block = indicies
    else:
        start_block = 0
        end_block = indicies
    return start_block, end_block


class _AiterMixin(ASyncIterable[_T]):
    def __aiter__(self) -> AsyncIterator[_T]:
        return self[self._start_block : chain.height].__aiter__()

    def __getitem__(self, slice: slice) -> ASyncIterator[_T]:
        if slice.start is not None and not isinstance(slice.start, (int, datetime)):
            raise TypeError(f"start must be int or datetime. you passed {slice.start}")
        if slice.stop and not isinstance(slice.stop, (int, datetime)):
            raise TypeError(f"start must be int or datetime. you passed {slice.start}")
        if slice.step is not None:
            raise ValueError("You cannot use a step here.")
        return ASyncIterator(self._get_and_yield(slice.start or 0, slice.stop, True))  # type: ignore [truthy-function]

    def yield_forever(self, mem_cache: bool = True) -> ASyncIterator[_T]:
        return ASyncIterator(self._get_and_yield(self._start_block or 0, None, mem_cache))

    @abstractmethod
    async def _get_and_yield(
        self, start_block: Block, end_block: Block, mem_cache: bool
    ) -> AsyncGenerator[_T, None]:
        yield

    @property
    @abstractmethod
    def _start_block(self) -> int: ...


_LT = TypeVar("_LT")


class _LedgeredBase(ASyncGenericBase, _AiterMixin["LedgerEntry"], Generic[_LT]):
    """A mixin class for things with ledgers"""

    transactions: _LT
    internal_transfers: _LT
    token_transfers: _LT

    def __init__(self, start_block: Block) -> None:
        self.start_block = start_block
        super().__init__()

    @property
    def _start_block(self) -> Block:
        # in the middle of refactoring this
        return self.start_block

    @cached_property
    def _ledgers(self) -> Tuple[_LT, _LT, _LT]:
        """A tuple with the 3 ledgers (transactions, internal transfers, token transfers)"""
        return self.transactions, self.internal_transfers, self.token_transfers

    def _get_and_yield(
        self, start_block: Block, end_block: Block, mem_cache: bool
    ) -> AsyncGenerator["LedgerEntry", None]:
        return as_yielded(*(ledger._get_and_yield(start_block, end_block, mem_cache) for ledger in self._ledgers))  # type: ignore [return-value,index]
