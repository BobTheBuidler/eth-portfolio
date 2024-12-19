import functools
import inspect
from asyncio import Queue, get_event_loop
from hashlib import md5
from logging import getLogger
from os import makedirs
from os.path import exists, join
from pickle import dumps, load, loads
from typing import Any, Callable, NoReturn

from a_sync import PruningThreadPoolExecutor
from a_sync._typing import P, T
from a_sync.asyncio import create_task
from aiofiles import open as _aio_open
from brownie import chain

BASE_PATH = f"./cache/{chain.id}/"
EXECUTOR = PruningThreadPoolExecutor(32, "eth-portfolio-cache-decorator")


def cache_to_disk(fn: Callable[P, T]) -> Callable[P, T]:
    # sourcery skip: use-contextlib-suppress
    name = fn.__name__
    cache_path_for_fn = f"{BASE_PATH}{fn.__module__.replace('.', '/')}/{name}"
    logger = getLogger(f"eth_portfolio.cache_to_disk.{name}")

    def get_cache_file_path(args, kwargs):
        # Create a unique filename based on the function arguments
        key = md5(dumps((args, sorted(kwargs.items())))).hexdigest()
        return join(cache_path_for_fn, f"{key}.json")

    makedirs(cache_path_for_fn, exist_ok=True)

    if inspect.iscoroutinefunction(fn):
        queue = Queue()

        async def cache_deco_worker_coro() -> NoReturn:
            try:
                while True:
                    fut, cache_path, args, kwargs = await queue.get()
                    try:
                        async with _aio_open(cache_path, "rb", executor=EXECUTOR) as f:
                            fut.set_result(loads(await f.read()))
                    except Exception as e:
                        fut.set_result(e)
            except Exception as e:
                logger.error(f"{type(e).__name__} in {fn}:")
                logger.exception(e)
                raise

        workers = None

        @functools.wraps(fn)
        async def disk_cache_wrap(*args: P.args, **kwargs: P.kwargs) -> T:
            cache_path = get_cache_file_path(args, kwargs)
            fut = get_event_loop().create_future()
            queue.put_nowait((fut, cache_path, args, kwargs))
            if workers is None:
                workers = tuple(create_task(cache_deco_worker_coro()) for _ in range(1000))
            try:
                return await fut
            except (FileNotFoundError, EOFError):
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
