from typing import List, Optional

import a_sync
from y.datatypes import Address, Block

from eth_portfolio._utils import _get_protocols_for_submodule, _import_submodules
from eth_portfolio.protocols import lending
from eth_portfolio.protocols._base import StakingPoolABC
from eth_portfolio.typing import RemoteTokenBalances

_import_submodules()

protocols: List[StakingPoolABC] = _get_protocols_for_submodule()  # type: ignore [assignment]


@a_sync.future
async def balances(address: Address, block: Optional[Block] = None) -> RemoteTokenBalances:
    """Fetches token balances for a given address across various protocols.

    This function retrieves the token balances for a specified Ethereum address
    at a given block across all available protocols. It is decorated with
    :func:`a_sync.future`, allowing it to be used in both synchronous and
    asynchronous contexts.

    If no protocols are available, the function returns an empty
    :class:`~eth_portfolio.typing.RemoteTokenBalances` object.

    Args:
        address (Address): The Ethereum address for which to fetch balances.
        block (Optional[Block]): The block number at which to fetch balances.
            If not provided, the latest block is used.

    Examples:
        Fetching balances asynchronously:

        >>> from eth_portfolio.protocols import balances
        >>> address = "0x1234567890abcdef1234567890abcdef12345678"
        >>> block = 12345678
        >>> remote_balances = await balances(address, block)
        >>> print(remote_balances)

        Fetching balances synchronously:

        >>> remote_balances = balances(address, block).result()
        >>> print(remote_balances)

    The function constructs a dictionary `data` initialized with protocol names
    and their corresponding balances. The `protocol_balances` variable is an
    asynchronous mapping of protocol names to their respective balance data,
    which is then used in an asynchronous comprehension to construct the
    dictionary `data`. This dictionary is subsequently used to initialize the
    :class:`~eth_portfolio.typing.RemoteTokenBalances` object.

    See Also:
        - :class:`~eth_portfolio.typing.RemoteTokenBalances`: For more information on the return type.
        - :func:`a_sync.future`: For more information on the decorator used.
    """
    if not protocols:
        return RemoteTokenBalances(block=block)
    protocol_balances = a_sync.map(
        lambda protocol: protocol.balances(address, block),
        protocols,
    )
    data = {
        type(protocol).__name__: protocol_balances
        async for protocol, protocol_balances in protocol_balances
        if protocol_balances is not None
    }
    return RemoteTokenBalances(data, block=block)