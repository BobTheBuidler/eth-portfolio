
import asyncio
import logging
import time
from functools import wraps
from random import random
from typing import Callable, TypeVar

from pony.orm import OperationalError, TransactionError
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
                    logger.debug("%s.%s %s", fn.__module__.__name__, fn.__name__, e)
                    if str(e) != "database is locked":
                        raise e
                    sleep = tries * random()
                    await asyncio.sleep(sleep)
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
                    logger.debug("%s.%s %s", fn.__module__.__name__, fn.__name__, e)
                    if str(e) != "database is locked":
                        raise e
                    sleep = tries * random()
                    time.sleep(sleep)
                    tries += 1
                    if tries > 5:
                        logger.warning("%s caught in err loop with %s", fn, e)
    return break_locks_wrap

def requery_objs_on_diff_tx_err(fn: Callable[P, T]) -> Callable[P, T]:
    if asyncio.iscoroutinefunction(fn):
        raise TypeError(f'{fn} must not be async')
    @wraps(fn)
    def requery_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
        while True:
            try:
                return fn(*args, **kwargs)
            except TransactionError as e:
                if str(e) != 'An attempt to mix objects belonging to different transactions':
                    raise e
                # The error occurs if you committed new objs to the db and started a new transaction while still inside of a `db_session`,
                # and then tried to use the newly committed objects in the next transaction. Now that the objects are in the db this will
                # not reoccur. The next iteration will be successful.
    return requery_wrap
