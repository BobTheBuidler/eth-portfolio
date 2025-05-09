from datetime import datetime, timedelta, timezone

import pytest
from unittest.mock import AsyncMock

from eth_portfolio_scripts._utils import aiter_timestamps, parse_timedelta


@pytest.mark.parametrize(
    "test_input, expected",
    [
        ("1d", timedelta(days=1)),  # days
        ("2h", timedelta(hours=2)),  # hours
        ("30m", timedelta(minutes=30)),  # minutes
        ("15s", timedelta(seconds=15)),  # seconds
        ("1d2h30m15s", timedelta(days=1, hours=2, minutes=30, seconds=15)),  # combined
        ("1d30m", timedelta(days=1, minutes=30)),  # days and minutes
        ("2h15s", timedelta(hours=2, seconds=15)),  # hours and seconds
        (
            "100d200h300m6000s",
            timedelta(days=100, hours=200, minutes=300, seconds=6000),
        ),  # large values
        (
            "1d2h30m15s45z",
            timedelta(days=1, hours=2, minutes=30, seconds=15),
        ),  # ignore invalid unit
        ("42", timedelta()),  # no unit
    ],
    ids=[
        "days",
        "hours",
        "minutes",
        "seconds",
        "combined",
        "days_minutes",
        "hours_seconds",
        "large_values",
        "invalid_unit",
        "no_unit",
    ],
)
def test_parse_timedelta_happy_path(test_input, expected):
    actual = parse_timedelta(test_input)
    assert actual == expected


@pytest.mark.parametrize(
    "test_input, expected",
    [
        ("", timedelta()),  # empty string
        ("   ", timedelta()),  # whitespace only
    ],
    ids=["empty_string", "whitespace_only"],
)
def test_parse_timedelta_edge_cases(test_input, expected):
    actual = parse_timedelta(test_input)
    assert actual == expected


@pytest.mark.parametrize(
    "test_input",
    [
        "1x",  # invalid unit
        "abc",  # non-numeric value
        "1d2x3m",  # invalid unit in combined input
    ],
    ids=[
        "invalid_unit",
        "non_numeric",
        "invalid_unit_combined",
    ],
)
def test_parse_timedelta_error_cases(test_input):
    with pytest.raises(ValueError):
        parse_timedelta(test_input)


_ts_is_ready = AsyncMock()  # type: ignore
_get_waiter = AsyncMock()  # type: ignore


@pytest.mark.asyncio
@pytest.mark.parametrize(
    "start, interval, run_forever, expected_timestamps",
    [
        (
            datetime(2024, 1, 1, tzinfo=timezone.utc),
            timedelta(days=1),
            False,
            [datetime(2024, 1, 1, tzinfo=timezone.utc)],
        ),  # single timestamp
        (
            datetime(2024, 1, 1, tzinfo=timezone.utc),
            timedelta(hours=12),
            False,
            [datetime(2024, 1, 1, tzinfo=timezone.utc)],
        ),  # different interval
        (
            datetime(2024, 1, 1, tzinfo=timezone.utc),
            timedelta(days=1),
            True,
            [datetime(2024, 1, 1, tzinfo=timezone.utc)],
        ),  # run forever
    ],
    ids=["single_timestamp", "different_interval", "run_forever"],
)
async def test_aiter_timestamps_happy_path(
    start, interval, run_forever, expected_timestamps, mocker
):
    # Arrange
    _ts_is_ready.return_value = True  # for initial timestamp
    _ts_is_ready.side_effect = [True] + [False] * 100  # for subsequent timestamps if run_forever

    # Act
    actual_timestamps = [
        ts async for ts in aiter_timestamps(start=start, interval=interval, run_forever=run_forever)
    ]

    # Assert
    assert actual_timestamps == expected_timestamps


@pytest.mark.asyncio
@pytest.mark.parametrize(
    "start, interval, run_forever, expected_timestamps",
    [
        (None, timedelta(days=1), False, []),
    ],
    ids=["start_none"],
)
async def test_aiter_timestamps_edge_cases(
    start, interval, run_forever, expected_timestamps, mocker
):
    # Arrange
    _ts_is_ready.return_value = False

    chain_mock = mocker.patch("brownie.chain", create=True)
    chain_mock[0].timestamp = 0

    # Act
    actual_timestamps = [
        ts async for ts in aiter_timestamps(start=start, interval=interval, run_forever=run_forever)
    ]

    # Assert
    assert actual_timestamps == expected_timestamps


@pytest.mark.asyncio
@pytest.mark.parametrize(
    "run_forever",
    [
        (123),  # invalid run_forever type
        (None),  # invalid run_forever type
        ("True"),  # invalid run_forever type
    ],
    ids=["invalid_run_forever_int", "invalid_run_forever_none", "invalid_run_forever_str"],
)
async def test_aiter_timestamps_error_cases(run_forever):

    # Act & Assert
    with pytest.raises(TypeError):
        [ts async for ts in aiter_timestamps(run_forever=run_forever)]
