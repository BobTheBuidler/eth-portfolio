from unittest.mock import AsyncMock, create_autospec, patch

import pytest
from eth_portfolio import protocols
from eth_portfolio.protocols._base import StakingPoolABC
from eth_portfolio.typing import Balance, RemoteTokenBalances, TokenBalances

SOME_ADDRESS = "0x0000000000000000000000000000000000000001"
SOME_TOKEN = "0x0000000000000000000000000000000000000002"
SOME_OTHER_TOKEN = "0x0000000000000000000000000000000000000003"


class MockProtocolA(AsyncMock): ...


class MockProtocolB(AsyncMock): ...


@patch("a_sync.map")
@pytest.mark.asyncio
async def test_balances_no_protocols(mock_map):
    protocols.protocols = []

    balances = await protocols.balances(SOME_ADDRESS)

    assert balances == RemoteTokenBalances()
    mock_map.assert_not_called()


@pytest.mark.asyncio
async def test_balances_with_protocols():
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
