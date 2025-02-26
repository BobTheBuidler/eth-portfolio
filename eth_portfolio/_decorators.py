import asyncio
import functools
import inspect
import logging
from typing import Callable, Optional

from brownie import chain
from typing_extensions import Concatenate
from y.datatypes import Block

from eth_portfolio import _config
from eth_portfolio._utils import get_buffered_chain_height
from eth_portfolio.typing import _I, _P, _T

logger = logging.getLogger(__name__)


def set_end_block_if_none(
    func: Callable[Concatenate[_I, Block, Block, _P], _T],
) -> Callable[Concatenate[_I, Block, Optional[Block], _P], _T]:
    """
    Used to set `end_block` = `chain.height - _config.REORG_BUFFER` if `end_block` is None.
    Only works with a class function that takes args (self, start_block, end_block, *args, **kwargs).
    """
    if inspect.isasyncgenfunction(func):

        @functools.wraps(func)
        async def wrap(
            obj: _I,
            start_block: Block,
            end_block: Optional[Block],
            *args: _P.args,
            **kwargs: _P.kwargs,
        ) -> _T:
            if end_block is None:
                end_block = await get_buffered_chain_height()
                logger.debug("end_block not provided, using %s", end_block)
            async for thing in func(obj, start_block, end_block, *args, **kwargs):
                yield thing

    elif asyncio.iscoroutinefunction(func):

        @functools.wraps(func)
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

        @functools.wraps(func)
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
