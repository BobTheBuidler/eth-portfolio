"""
These 2 helpers enable us to decode only the relevant data in the json response and discard the rest
They're in a separate file so mypyc doesn't try to compile them
"""

from typing import TypedDict, final

from eth_typing import ChecksumAddress
from msgspec import Raw, Struct


@final
class Metric(TypedDict):
    param: str
    wallet: ChecksumAddress
    token_address: ChecksumAddress
    token: str
    bucket: str
    network: str
    __name__: str


@final
class PrometheusItem(TypedDict):
    metric: Metric
    values: list[float]
    timestamps: list[float]


@final
class Data(Struct):
    result: tuple[Raw, ...]


@final
class Response(Struct):
    status: str
    data: Data
