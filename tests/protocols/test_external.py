from unittest.mock import AsyncMock, create_autospec, patch

import pytest
from eth_portfolio import protocols
from eth_portfolio.protocols._base import StakingPoolABC
from eth_portfolio.typing import Balance, RemoteTokenBalances, TokenBalances

SOME_ADDRESS = "0x0000000000000000000000000000000000000001"
SOME_TOKEN = "0x0000000000000000000000000000000000000002"
SOME_OTHER_TOKEN = "0x0000000000000000000000000000000000000003"


class MockProtocolA(AsyncMock):
    """Mock class for simulating Protocol A behavior in tests."""


class MockProtocolB(AsyncMock):
    """Mock class for simulating Protocol B behavior in tests."""


@patch("a_sync.map")
@pytest.mark.asyncio
async def test_balances_no_protocols(mock_map):
    """
    Test the `balances` function with no protocols.

    This test verifies that when there are no protocols in the
    `protocols.protocols` list, the `balances` function returns an
    empty :class:`~eth_portfolio.typing.RemoteTokenBalances` object
    and does not call the `a_sync.map` function.

    Args:
        mock_map: The mock object for `a_sync.map`.

    See Also:
        - :func:`~eth_portfolio.protocols.balances`
    """
    protocols.protocols = []

    balances = await protocols.balances(SOME_ADDRESS)

    assert balances == RemoteTokenBalances()
    mock_map.assert_not_called()


@pytest.mark.asyncio
async def test_balances_with_protocols():
    """
    Test the `balances` function with multiple protocols.

    This test verifies that when there are multiple protocols in the
    `protocols.protocols` list, the `balances` function correctly
    aggregates balances from each protocol.

    The test uses :class:`~unittest.mock.AsyncMock` to simulate
    protocol behavior and checks that each protocol's `balances`
    method is called with the correct arguments.

    See Also:
        - :func:`~eth_portfolio.protocols.balances`
    """
    mock_protocol_a = MockProtocolA()
    mock_protocol_a.balances.return_value = TokenBalances({SOME_TOKEN: Balance(100, 200)})

    mock_protocol_b = MockProtocolB()
    mock_protocol_b.balances.return_value = TokenBalances({SOME_OTHER_TOKEN: Balance(200, 400)})

    protocols.protocols = [mock_protocol_a, mock_protocol_b]

    balances = await protocols.balances(SOME_ADDRESS)

    assert balances == RemoteTokenBalances(
        {
            "MockProtocolA": TokenBalances({SOME_TOKEN: Balance(100, 200)}),
            "MockProtocolB": TokenBalances({SOME_OTHER_TOKEN: Balance(200, 400)}),
        }
    )

    for protocol in protocols.protocols:
        protocol.balances.assert_called_once_with(SOME_ADDRESS, None)


@pytest.mark.asyncio
async def test_balances_with_protocols_and_block():
    """
    Test the `balances` function with protocols and a specific block.

    This test verifies that when there are multiple protocols in the
    `protocols.protocols` list and a specific block is provided, the
    `balances` function correctly aggregates balances from each
    protocol for the specified block.

    The test uses :class:`~unittest.mock.AsyncMock` to simulate
    protocol behavior and checks that each protocol's `balances`
    method is called with the correct arguments, including the block
    number.

    See Also:
        - :func:`~eth_portfolio.protocols.balances`
    """
    block = 1234567

    mock_protocol_a = MockProtocolA()
    mock_protocol_a.balances.return_value = TokenBalances({SOME_TOKEN: Balance(100, 200)})

    mock_protocol_b = MockProtocolB()
    mock_protocol_b.balances.return_value = TokenBalances({SOME_OTHER_TOKEN: Balance(200, 400)})

    protocols.protocols = [mock_protocol_a, mock_protocol_b]

    balances = await protocols.balances(SOME_ADDRESS, block)

    assert balances == RemoteTokenBalances(
        {
            "MockProtocolA": TokenBalances({SOME_TOKEN: Balance(100, 200)}),
            "MockProtocolB": TokenBalances({SOME_OTHER_TOKEN: Balance(200, 400)}),
        }
    )

    for protocol in protocols.protocols:
        protocol.balances.assert_called_once_with(SOME_ADDRESS, block)
