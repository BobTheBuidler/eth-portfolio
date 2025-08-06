from gzip import compress
from logging import getLogger
from os import environ
from typing import Final, List

import a_sync
from aiohttp import ClientError, ClientSession, ServerDisconnectedError
from msgspec import json

from eth_portfolio_scripts.victoria import types
from eth_portfolio_scripts.victoria.types import Metric


BASE_URL: Final = environ.get("VM_URL", "http://127.0.0.1:8430")

# this will be populated later
session: ClientSession = None  # type: ignore [assignment]

logger: Final = getLogger("eth_portfolio.victoria")

encode: Final = json.encode
decode: Final = json.decode


class VictoriaMetricsError(ValueError): ...


def get_session() -> ClientSession:
    sesh = session
    if sesh is None:
        sesh = ClientSession(BASE_URL, raise_for_status=True)
        __set_session(sesh)
    return sesh


async def get(url: str) -> bytes:
    session = get_session()
    while True:
        try:
            async with session.get(url=url, headers={"Connection": "close"}) as response:
                return await response.read()
        except ServerDisconnectedError:
            continue


@a_sync.Semaphore(2)
async def post_data(metrics_to_export: List["Metric"]) -> None:
    """Post all metrics at once."""
    data = compress(b"\n".join(encode(metric) for metric in metrics_to_export))
    attempts = 0
    session = get_session()
    while True:
        try:
            async with session.post(
                "/api/v1/import",
                headers={"Connection": "close", "Content-Encoding": "gzip"},
                data=data,
            ):
                logger.debug(f"posted {len(data)} datas")
                return
        except ClientError as e:
            attempts += 1
            logger.debug("You had a ClientError: %s", e)
            if attempts >= 10:
                raise e


def __set_session(sesh: ClientSession) -> None:
    global session
    session = sesh


__all__ = ["Metric", "get", "post_data"]
