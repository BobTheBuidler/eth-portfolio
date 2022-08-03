
import asyncio
import functools
import logging

from brownie import chain
from y.datatypes import Block

from eth_portfolio import _config

logger = logging.getLogger(__name__)


def set_end_block_if_none(func):
    """ 
    Used to set `end_block` = `chain.height - _config.REORG_BUFFER` if `end_block` is None.
    Only works with a class function that takes args (self, start_block, end_block)
    """
    @functools.wraps(func)
    def wrap(obj, start_block: Block, end_block: Block, **kwargs):
        if end_block is None:
            end_block = chain.height - _config.REORG_BUFFER
            logger.debug(f"end_block not provided, using {end_block}")
        return func(obj, start_block, end_block, **kwargs)
    return wrap

def await_if_sync(func):
    """
    The wrapped function will return a coroutine if `obj.asynchronous` is True and a result if False.
    """
    @functools.wraps(func)
    def wrap(obj, *args, **kwargs):
        coro = func(obj, *args, **kwargs)
        if obj.asynchronous:
            return coro
        try:
            return asyncio.get_event_loop().run_until_complete(coro)
        except RuntimeError as e:
            e.args = list(e.args) + "Perhaps you want to set `asynchronous=True`?"
            raise e
    return wrap
