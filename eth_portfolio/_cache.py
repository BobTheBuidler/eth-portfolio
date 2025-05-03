import functools
import inspect
from asyncio import AbstractEventLoop, PriorityQueue, Task, current_task, get_event_loop
from concurrent.futures import Executor
from hashlib import md5
from logging import getLogger
from os import makedirs
from os.path import exists, join
from pickle import dumps, load, loads
from random import random
from typing import Any, Callable, Final, List, NoReturn, Optional

from a_sync import PruningThreadPoolExecutor
from a_sync._typing import P, T
from a_sync.asyncio import create_task

# TODO: rip out this deprecated func
from a_sync.primitives.queue import log_broken
from aiofiles import open as _aio_open
from brownie import chain

BASE_PATH: Final = f"./cache/{chain.id}/"
_THREAD_NAME_PREFIX: Final = "eth-portfolio-cache-decorator"
_EXISTS_EXECUTOR: Final = PruningThreadPoolExecutor(8, f"{_THREAD_NAME_PREFIX}-exists")


def cache_to_disk(fn: Callable[P, T]) -> Callable[P, T]:
    # sourcery skip: use-contextlib-suppress
    name = fn.__name__
    cache_path_for_fn = f"{BASE_PATH}{fn.__module__.replace('.', '/')}/{name}"
    logger = getLogger(f"eth_portfolio.cache_to_disk.{name}")

    def get_cache_file_path(args, kwargs):
        # Create a unique filename based on the function arguments
        key = md5(dumps((args, sorted(kwargs.items())))).hexdigest()
        return join(cache_path_for_fn, f"{key}.json")

    write_executor = PruningThreadPoolExecutor(8, f"{_THREAD_NAME_PREFIX}-{fn.__qualname__}-write")

    makedirs(cache_path_for_fn, exist_ok=True)

    if inspect.iscoroutinefunction(fn):
        read_executor = PruningThreadPoolExecutor(
            8, f"{_THREAD_NAME_PREFIX}-{fn.__qualname__}-read"
        )

        queue: PriorityQueue = PriorityQueue()

        async def cache_deco_worker_coro(func) -> NoReturn:
            try:
                while True:
                    _, fut, cache_path, args, kwargs = await queue.get()
                    try:
                        async with _aio_open(cache_path, "rb", executor=read_executor) as f:
                            fut.set_result(loads(await f.read()))
                    except Exception as e:
                        fut.set_exception(e)
            except Exception as e:
                logger.error("%s for %s is broken!!!", current_task(), func)
                logger.exception(e)
                raise

        loop: Optional[AbstractEventLoop] = None
        workers: List[Task[NoReturn]] = []

        @functools.wraps(fn)
        async def disk_cache_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            cache_path = get_cache_file_path(args, kwargs)
            if await _EXISTS_EXECUTOR.run(exists, cache_path):
                nonlocal loop
                if loop is None:
                    loop = get_event_loop()
                fut = loop.create_future()
                # we intentionally mix up the order to break up heavy load block ranges
                queue.put_nowait((random(), fut, cache_path, args, kwargs))
                if not workers:
                    workers.extend(create_task(cache_deco_worker_coro(fn)) for _ in range(100))
                try:
                    return await fut
                except EOFError:
                    pass

            async_result: T = await fn(*args, **kwargs)
            try:
                await __cache_write(cache_path, async_result, write_executor)
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
            try:
                with open(cache_path, "rb") as f:
                    return load(f)
            except (FileNotFoundError, EOFError):
                pass

            sync_result: T = fn(*args, **kwargs)  # type: ignore [assignment, return-value]
            try:
                create_task(
                    coro=__cache_write(cache_path, sync_result, write_executor),
                    skip_gc_until_done=True,
                )
            except RuntimeError:
                pass
            return sync_result

    return disk_cache_wrap


async def __cache_write(cache_path: str, result: Any, executor: Executor) -> None:
    async with _aio_open(cache_path, "wb", executor=executor) as f:
        await f.write(dumps(result))
