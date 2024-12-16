import functools
import inspect
import os
from hashlib import md5
from os import makedirs
from os.path import exists, join
from pickle import dumps, load, loads
from typing import Any

from a_sync import PruningThreadPoolExecutor
from a_sync._typing import AnyFn, P, T
from a_sync.asyncio import create_task
from aiofiles import open as _aio_open
from aiofiles.ospath import exists as _aio_path_exists
from brownie import chain

BASE_PATH = f"./cache/{chain.id}/"
EXECUTOR = PruningThreadPoolExecutor(32)


def cache_to_disk(fn: AnyFn[P, T]) -> AnyFn[P, T]:
    module = fn.__module__.replace(".", "/")
    cache_path_for_fn = BASE_PATH + module + "/" + fn.__name__

    def get_cache_file_path(args, kwargs):
        # Create a unique filename based on the function arguments
        key = md5(dumps((args, sorted(kwargs.items())))).hexdigest()
        return join(cache_path_for_fn, f"{key}.json")

    makedirs(cache_path_for_fn, exist_ok=True)

    if inspect.iscoroutinefunction(fn):

        @functools.wraps(fn)
        async def disk_cache_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            cache_path = get_cache_file_path(args, kwargs)
            if await _aio_path_exists(cache_path, executor=EXECUTOR):
                async with _aio_open(cache_path, "rb", executor=EXECUTOR) as f:
                    try:
                        return loads(await f.read())
                    except EOFError:
                        pass

            async_result: T = await fn(*args, **kwargs)
            await __cache_write(cache_path, async_result)
            return async_result

    else:

        @functools.wraps(fn)
        def disk_cache_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            cache_path = get_cache_file_path(args, kwargs)
            if exists(cache_path):
                with open(cache_path, "rb") as f:
                    try:
                        return load(f)
                    except EOFError:
                        pass

            sync_result: T = fn(*args, **kwargs)  # type: ignore [assignment, return-value]
            try:
                create_task(
                    coro=__cache_write(cache_path, result),
                    skip_gc_until_done=True,
                )
            except RuntimeError:
                pass
            return sync_result

    return disk_cache_wrap


async def __cache_write(cache_path: str, result: Any) -> None:
    result = dumps(result)
    async with _aio_open(cache_path, "wb", executor=EXECUTOR) as f:
        await f.write(result)
