import functools
import inspect
from hashlib import md5
from os import makedirs
from os.path import exists, join
from pickle import dumps, load, loads
from typing import Any, Callable

from a_sync import PruningThreadPoolExecutor
from a_sync._typing import P, T
from a_sync.asyncio import create_task
from aiofiles import open as _aio_open
from brownie import chain

BASE_PATH = f"./cache/{chain.id}/"
EXECUTOR = PruningThreadPoolExecutor(32)


def cache_to_disk(fn: Callable[P, T]) -> Callable[P, T]:
    # sourcery skip: use-contextlib-suppress
    cache_path_for_fn = f"{BASE_PATH}{fn.__module__.replace('.', '/')}/{fn.__name__}"

    def get_cache_file_path(args, kwargs):
        # Create a unique filename based on the function arguments
        key = md5(dumps((args, sorted(kwargs.items())))).hexdigest()
        return join(cache_path_for_fn, f"{key}.json")

    makedirs(cache_path_for_fn, exist_ok=True)

    if inspect.iscoroutinefunction(fn):

        @functools.wraps(fn)
        async def disk_cache_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            cache_path = get_cache_file_path(args, kwargs)
            if await EXECUTOR.run(exists, cache_path):
                async with _aio_open(cache_path, "rb", executor=EXECUTOR) as f:
                    try:
                        return loads(await f.read())
                    except EOFError:
                        pass

            async_result: T = await fn(*args, **kwargs)
            try:
                await __cache_write(cache_path, async_result)
            except OSError as e:
                # I was having some weird issues in docker that I don't want to debug,
                # so I'm going to assume you have another means to let you know you're
                # out of disk space and will pass right on through here so my script
                # can continue
                if e.strerror != "No space left on device":
                    raise
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
                    coro=__cache_write(cache_path, sync_result),
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
