
import asyncio
import functools
import logging
from typing import Any, Callable, Coroutine, overload

from brownie import chain
from multicall.utils import get_event_loop
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


""" This overload is just so your decorated function definitions can have user-friendly type hints.
 - Any function you decorate with `await_if_sync` MUST return a coroutine.
 - You SHOULD define the return type hint as the type that is returned when you await the coroutine. """
@overload
def await_if_sync(func: Callable[..., Coroutine[Any, Any, _T]]) -> Callable[..., _T]:...

@overload
def await_if_sync(func: Callable[..., _T]) -> Callable[..., _T]:...

def await_if_sync(func):
    """
    The wrapped function will return a coroutine if `obj.asynchronous` is True and a result if False.
    - Any function you decorate MUST return a coroutine, not a value.
    - You SHOULD define the return type hint as the type that is returned when you await the coroutine.
    """
    @functools.wraps(func)
    def wrap(obj, *args, **kwargs) -> _T:
        coro = func(obj, *args, **kwargs)
        if obj.asynchronous:
            return coro
        try:
            return get_event_loop().run_until_complete(coro)
        except RuntimeError as e:
            e.args = tuple(list(e.args) + ["Perhaps you want to set `Portfolio(..., asynchronous=True)`?"])
            raise e
    return wrap
