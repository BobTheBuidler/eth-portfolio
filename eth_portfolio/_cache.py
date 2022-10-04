import functools
import os
from inspect import iscoroutinefunction
from typing import Callable, TypeVar

import toolcache
from brownie import chain

T = TypeVar('T')

cache_base_path = f'./cache/{chain.id}/'


def cache_to_disk(fn: Callable[..., T]) -> Callable[..., T]:
    module = fn.__module__.replace('.','/')
    name = fn.__name__
    cache_path_for_fn = cache_base_path + module + '/' + name

    # Ensure the cache dir exists
    os.makedirs(cache_path_for_fn, exist_ok=True)

    cache_decorator = toolcache.cache('disk', cache_dir=cache_path_for_fn)

    if iscoroutinefunction(fn):
        @cache_decorator
        @functools.wraps(fn)
        async def disk_cache_wrap(*args, **kwargs) -> T:
            return await fn(*args, **kwargs)
    else:
        @cache_decorator
        @functools.wraps(fn)
        def disk_cache_wrap(*args, **kwargs) -> T:
            return fn(*args, **kwargs)
    return disk_cache_wrap
