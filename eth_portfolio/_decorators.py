
import asyncio
import functools
import logging
from typing import Callable

from brownie import chain
from y.datatypes import Block

from eth_portfolio import _config
from eth_portfolio.typing import _T
from eth_portfolio.utils import get_buffered_chain_height

logger = logging.getLogger(__name__)


def set_end_block_if_none(func: Callable[..., _T]) -> Callable[..., _T]:
    """ 
    Used to set `end_block` = `chain.height - _config.REORG_BUFFER` if `end_block` is None.
    Only works with a class function that takes args (self, start_block, end_block, *args, **kwargs).
    """
    if asyncio.iscoroutinefunction(func):
        @functools.wraps(func)
        async def wrap(obj, start_block: Block, end_block: Block, *args, **kwargs) -> _T:
            if end_block is None:
                end_block = await get_buffered_chain_height()
                logger.debug(f"end_block not provided, using {end_block}")
            return await func(obj, start_block, end_block, *args, **kwargs)
    else:
        @functools.wraps(func)
        def wrap(obj, start_block: Block, end_block: Block, *args, **kwargs) -> _T:
            if end_block is None:
                end_block = chain.height - _config.REORG_BUFFER
                logger.debug(f"end_block not provided, using {end_block}")
            return func(obj, start_block, end_block, *args, **kwargs)
    return wrap
