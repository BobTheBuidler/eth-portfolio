import logging
from asyncio import iscoroutinefunction
from functools import wraps
from inspect import isasyncgenfunction
from typing import AsyncIterator, Callable, Optional, overload

from a_sync.iter import ASyncGeneratorFunction
from brownie import chain
from typing_extensions import Concatenate
from y.datatypes import Block

from eth_portfolio import _config
from eth_portfolio._utils import get_buffered_chain_height
from eth_portfolio.typing import _I, _P, _T

logger = logging.getLogger(__name__)


@overload
def set_end_block_if_none(
    func: Callable[Concatenate[_I, Block, Block, _P], AsyncIterator[_T]],
) -> Callable[Concatenate[_I, Block, Optional[Block], _P], AsyncIterator[_T]]: ...


@overload
def set_end_block_if_none(
    func: Callable[Concatenate[_I, Block, Block, _P], _T],
) -> Callable[Concatenate[_I, Block, Optional[Block], _P], _T]: ...


def set_end_block_if_none(
    func: Callable[Concatenate[_I, Block, Block, _P], _T],
) -> Callable[Concatenate[_I, Block, Optional[Block], _P], _T]:
    """
    Used to set `end_block` = `chain.height - _config.REORG_BUFFER` if `end_block` is None.
    Only works with a class function that takes args (self, start_block, end_block, *args, **kwargs).
    """
    if isasyncgenfunction(func) or isinstance(func, ASyncGeneratorFunction):

        @wraps(func)  # type: ignore [arg-type]
        async def wrap(
            obj: _I,
            start_block: Block,
            end_block: Optional[Block],
            *args: _P.args,
            **kwargs: _P.kwargs,
        ) -> AsyncIterator[_T]:
            if end_block is None:
                end_block = await get_buffered_chain_height()
                logger.debug("end_block not provided, using %s", end_block)
            async for thing in func(obj, start_block, end_block, *args, **kwargs):
                yield thing

    elif iscoroutinefunction(func):

        @wraps(func)
        async def wrap(
            obj: _I,
            start_block: Block,
            end_block: Block,
            *args: _P.args,
            **kwargs: _P.kwargs,
        ) -> _T:
            if end_block is None:
                end_block = await get_buffered_chain_height()
                logger.debug("end_block not provided, using %s", end_block)
            return await func(obj, start_block, end_block, *args, **kwargs)

    else:

        @wraps(func)
        def wrap(
            obj: _I,
            start_block: Block,
            end_block: Block,
            *args: _P.args,
            **kwargs: _P.kwargs,
        ) -> _T:
            if end_block is None:
                end_block = chain.height - _config.REORG_BUFFER
                logger.debug("end_block not provided, using %s", end_block)
            return func(obj, start_block, end_block, *args, **kwargs)

    return wrap
