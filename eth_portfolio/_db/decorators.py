from asyncio import iscoroutinefunction
from asyncio import sleep as aio_sleep
from functools import wraps
from logging import DEBUG, getLogger
from random import random
from time import sleep as time_sleep
from typing import Callable, TypeVar

from a_sync._typing import AnyFn
from pony.orm import OperationalError, TransactionError
from typing_extensions import ParamSpec


P = ParamSpec("P")
T = TypeVar("T")


logger = getLogger(__name__)
__logger_is_enabled_for = logger.isEnabledFor
__logger_warning = logger.warning
__logger_log = logger._log


def break_locks(fn: AnyFn[P, T]) -> AnyFn[P, T]:
    if iscoroutinefunction(fn):

        @wraps(fn)
        async def break_locks_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            debug_logs_enabled = None
            tries = 0
            while True:
                try:
                    return await fn(*args, **kwargs)
                except OperationalError as e:
                    if str(e) != "database is locked":
                        raise e

                    if debug_logs_enabled is None:
                        debug_logs_enabled = __logger_is_enabled_for(DEBUG)
                        
                    if debug_logs_enabled is True:
                        __logger_log(DEBUG, "%s.%s %s", (fn.__module__, fn.__name__, e))
                        
                    await aio_sleep(tries * random())
                    tries += 1
                    if tries > 5:
                        __logger_warning("%s caught in err loop with %s", fn, e)

    else:

        @wraps(fn)
        def break_locks_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            debug_logs_enabled = None
            tries = 0
            while True:
                try:
                    return fn(*args, **kwargs)  # type: ignore [return-value]
                except OperationalError as e:
                    if str(e) != "database is locked":
                        raise e
                        
                    if debug_logs_enabled is None:
                        debug_logs_enabled = __logger_is_enabled_for(DEBUG)
                        
                    if debug_logs_enabled is True:
                        __logger_log(DEBUG, "%s.%s %s", (fn.__module__, fn.__name__, e))
                        
                    time_sleep(tries * random())
                    tries += 1
                    if tries > 5:
                        __logger_warning("%s caught in err loop with %s", fn, e)

    return break_locks_wrap


def requery_objs_on_diff_tx_err(fn: Callable[P, T]) -> Callable[P, T]:
    if iscoroutinefunction(fn):
        raise TypeError(f"{fn} must not be async")

    @wraps(fn)
    def requery_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
        while True:
            try:
                return fn(*args, **kwargs)
            except TransactionError as e:
                if str(e) != "An attempt to mix objects belonging to different transactions":
                    raise e
                # The error occurs if you committed new objs to the db and started a new transaction while still inside of a `db_session`,
                # and then tried to use the newly committed objects in the next transaction. Now that the objects are in the db this will
                # not reoccur. The next iteration will be successful.

    return requery_wrap
