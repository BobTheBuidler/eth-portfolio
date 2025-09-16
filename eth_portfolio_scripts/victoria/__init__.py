import re
from dateutil import parser
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


def _parse_datetime(dt_str: str) -> int:
    """
    Parse a datetime string using dateutil.parser.parse to a Unix timestamp (seconds).
    """
    try:
        dt = parser.parse(dt_str)
        return int(dt.timestamp())
    except Exception:
        # Try parsing as integer (epoch seconds)
        if re.match(r"^\d+$", dt_str):
            return int(dt_str)
        raise ValueError(f"Could not parse datetime string: {dt_str}")


async def delete_data(start_timestamp: str, end_timestamp: str) -> None:
    """
    Delete ALL datapoints from VictoriaMetrics between two timestamps.

    This deletes ALL time series using match[]={__name__!=""} as required by the VictoriaMetrics API.
    There is no way to restrict this operation to a subset of metrics.

    Args:
        start_timestamp: str, datetime string (inclusive)
        end_timestamp: str, datetime string (exclusive)
    """
    start_ts = _parse_datetime(start_timestamp)
    end_ts = _parse_datetime(end_timestamp)
    # Use match[]={__name__!=""} for all-series deletion (correct for VictoriaMetrics OSS)
    url = f'/api/v1/admin/tsdb/delete_series?match[]={{__name__!=""}}&start={start_ts}&end={end_ts}'
    session = get_session()
    logger.info(
        f"Deleting ALL VictoriaMetrics data from {start_timestamp} to {end_timestamp} (epoch {start_ts} to {end_ts})"
    )
    try:
        async with session.post(url, headers={"Connection": "close"}) as resp:
            if resp.status != 204:
                text = await resp.text()
                logger.error(f"Failed to delete data: {resp.status} {text}")
                raise VictoriaMetricsError(f"Failed to delete data: {resp.status} {text}")
            logger.info("Data deletion successful.")
    except Exception as e:
        logger.error(f"Exception during data deletion: {e}")
        raise


__all__ = ["Metric", "get", "post_data", "delete_data"]
