from asyncio import iscoroutinefunction
from asyncio import sleep as aio_sleep
from functools import wraps
from logging import DEBUG, getLogger
from random import random
from time import sleep as time_sleep
from typing import Callable, Final, TypeVar

from a_sync._typing import AnyFn
from pony.orm import OperationalError, TransactionError
from typing_extensions import ParamSpec


P = ParamSpec("P")
T = TypeVar("T")


logger: Final = getLogger(__name__)
__logger_is_enabled_for: Final = logger.isEnabledFor
__logger_warning: Final = logger.warning
__logger_log: Final = logger._log


def break_locks(fn: AnyFn[P, T]) -> AnyFn[P, T]:
    """
    Decorator to handle database lock errors by retrying the function.

    This decorator is designed to wrap functions that interact with a database
    and may encounter `OperationalError` due to database locks. It will retry
    the function indefinitely if a "database is locked" error occurs. After
    5 attempts, a warning is logged, but the function will continue to retry
    until it succeeds or a non-lock-related error occurs.

    Args:
        fn: The function to be wrapped, which may be a coroutine or a regular function.

    Examples:
        Basic usage with a regular function:

        >>> @break_locks
        ... def my_function():
        ...     # Function logic that may encounter a database lock
        ...     pass

        Basic usage with an asynchronous function:

        >>> @break_locks
        ... async def my_async_function():
        ...     # Async function logic that may encounter a database lock
        ...     pass

    See Also:
        - :func:`pony.orm.db_session`: For managing database sessions.
    """
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
    """
    Decorator to handle transaction errors by retrying the function.

    This decorator is designed to wrap functions that may encounter
    `TransactionError` due to mixing objects from different transactions.
    It will retry the function until it succeeds or a non-transaction-related
    error occurs.

    Args:
        fn: The function to be wrapped, which must not be a coroutine.

    Raises:
        TypeError: If the function is a coroutine.

    Examples:
        Basic usage with a function that may encounter transaction errors:

        >>> @requery_objs_on_diff_tx_err
        ... def my_function():
        ...     # Function logic that may encounter a transaction error
        ...     pass

    See Also:
        - :func:`pony.orm.db_session`: For managing database sessions.
    """
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
