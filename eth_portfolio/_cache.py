import contextlib
import functools
import hashlib
import inspect
import os
import pickle
from typing import Any

import a_sync
import aiofiles
import aiofiles.os
from a_sync._typing import AnyFn, P, T
from brownie import chain

BASE_PATH = f"./cache/{chain.id}/"
EXECUTOR = a_sync.PruningThreadPoolExecutor(32)

def cache_to_disk(fn: AnyFn[P, T]) -> AnyFn[P, T]:
    module = fn.__module__.replace(".", "/")
    cache_path_for_fn = BASE_PATH + module + "/" + fn.__name__

    def get_cache_file_path(args, kwargs):
        # Create a unique filename based on the function arguments
        key = hashlib.md5(pickle.dumps((args, sorted(kwargs.items())))).hexdigest()
        return os.path.join(cache_path_for_fn, f"{key}.json")

    os.makedirs(cache_path_for_fn, exist_ok=True)

    if inspect.iscoroutinefunction(fn):

        @functools.wraps(fn)
        async def disk_cache_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            cache_path = get_cache_file_path(args, kwargs)
            if await aiofiles.os.path.exists(cache_path, executor=EXECUTOR):
                async with aiofiles.open(cache_path, "rb", executor=EXECUTOR) as f:
                    with contextlib.suppress(EOFError):
                        return pickle.loads(await f.read())
                        
            async_result: T = await fn(*args, **kwargs)
            await __cache_write(cache_path, result)
            return async_result

    else:

        @functools.wraps(fn)
        def disk_cache_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            cache_path = get_cache_file_path(args, kwargs)
            if os.path.exists(cache_path):
                with open(cache_path, "rb") as f:
                    with contextlib.suppress(EOFError):
                        return pickle.load(f)

            sync_result: T = fn(*args, **kwargs)  # type: ignore [assignment, return-value]
            try:
                a_sync.create_task(
                    coro=__cache_write(cache_path, result),
                    skip_gc_until_done=True,
                )
            except RuntimeError:
                pass
            return sync_result

    return disk_cache_wrap


async def __cache_write(cache_path: str, result: Any) -> None:
    async with aiofiles.open(cache_path, "wb", executor=EXECUTOR) as f:
        await f.write(pickle.dumps(result))
