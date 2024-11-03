import functools
import os
from inspect import iscoroutinefunction

import toolcache
from a_sync._typing import AnyFn, P, T
from brownie import chain


cache_base_path = f"./cache/{chain.id}/"


def cache_to_disk(fn: AnyFn[P, T]) -> AnyFn[P, T]:
    module = fn.__module__.replace(".", "/")
    cache_path_for_fn = cache_base_path + module + "/" + fn.__name__

    # Ensure the cache dir exists
    os.makedirs(cache_path_for_fn, exist_ok=True)

    cache_decorator = toolcache.cache("disk", cache_dir=cache_path_for_fn)

    if iscoroutinefunction(fn):

        @cache_decorator
        @functools.wraps(fn)
        async def disk_cache_wrap(*args, **kwargs) -> T:
            return await fn(*args, **kwargs)

    else:

        @cache_decorator
        @functools.wraps(fn)
        def disk_cache_wrap(*args, **kwargs) -> T:
            return fn(*args, **kwargs)  # type: ignore [return-value]

    return disk_cache_wrap
