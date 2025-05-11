import re
from asyncio import Task, create_task, sleep
from datetime import datetime, timedelta, timezone
from typing import Any, AsyncGenerator, Dict, List, Optional

from brownie import chain


def parse_timedelta(value: str) -> timedelta:
    regex = re.compile(r"(\d+)([dhms]?)")
    result = regex.findall(value)

    days, hours, minutes, seconds = 0, 0, 0, 0

    for val, unit in result:
        val = int(val)
        if unit == "d":
            days = val
        elif unit == "h":
            hours = val
        elif unit == "m":
            minutes = val
        elif unit == "s":
            seconds = val

    return timedelta(days=days, hours=hours, minutes=minutes, seconds=seconds)


async def aiter_timestamps(
    *,
    start: Optional[datetime] = None,
    interval: timedelta = timedelta(days=1),
    run_forever: bool = False,
) -> AsyncGenerator[datetime, None]:
    """
    Generates the timestamps to be queried based on the specified range and interval.
    """
    if not isinstance(run_forever, bool):
        raise TypeError(f"`run_forever` must be boolean. You passed {run_forever}")

    if start is None:
        start = datetime.now(tz=timezone.utc)

    block0_ts = datetime.fromtimestamp(chain[0].timestamp, tz=timezone.utc)
    helper = datetime(
        year=block0_ts.year,
        month=block0_ts.month,
        day=block0_ts.day,
        hour=block0_ts.hour,
        minute=block0_ts.minute,
        tzinfo=timezone.utc,
    )
    while helper + interval < start:
        helper += interval
    start = helper
    if start < block0_ts:
        start += interval

    timestamp = start

    while timestamp <= datetime.now(tz=timezone.utc):
        yield timestamp
        timestamp = timestamp + interval

    while run_forever:
        while timestamp > datetime.now(tz=timezone.utc):
            await _get_waiter(timestamp)
        yield timestamp
        timestamp += interval


_waiters: Dict[datetime, "Task[None]"] = {}


def _get_waiter(timestamp: datetime) -> "Task[None]":
    if timestamp not in _waiters:
        waiter = create_task(sleep_until(timestamp))
        waiter.add_done_callback(_sleep_done_callback)
        _waiters[timestamp] = waiter
    return _waiters[timestamp]


async def sleep_until(until: datetime) -> None:
    now = datetime.now(tz=timezone.utc)
    await sleep((until - now).total_seconds())


def _sleep_done_callback(t: "Task[Any]") -> None:
    low_to_hi = sorted(_waiters)
    for k in low_to_hi:
        if _waiters[k] is t:
            _waiters.pop(k)
