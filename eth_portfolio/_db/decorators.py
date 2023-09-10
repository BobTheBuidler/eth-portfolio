
import asyncio
import logging
import time
from functools import wraps
from typing import Callable, TypeVar

from pony.orm import OperationalError
from typing_extensions import ParamSpec

P = ParamSpec('P')
T = TypeVar('T')

logger = logging.getLogger(__name__)

def break_locks(fn: Callable[P, T]) -> Callable[P, T]:
    if asyncio.iscoroutinefunction(fn):
        @wraps(fn)
        async def break_locks_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            tries = 0
            while True:
                try:
                    return await fn(*args, **kwargs)
                except OperationalError as e:
                    if str(e) != "database is locked":
                        raise e
                    await asyncio.sleep(tries)
                    tries += 1
                    if tries > 5:
                        logger.warning("%s caught in err loop with %s", fn, e)
            
    else:
        @wraps(fn)
        def break_locks_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            tries = 0
            while True:
                try:
                    return fn(*args, **kwargs)
                except OperationalError as e:
                    if str(e) != "database is locked":
                        raise e
                    time.sleep(tries)
                    tries += 1
                    if tries > 5:
                        logger.warning("%s caught in err loop with %s", fn, e)
    return break_locks_wrap