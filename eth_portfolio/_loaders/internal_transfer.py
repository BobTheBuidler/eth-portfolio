"""
Loader functions for processing internal transfers on the blockchain.

This module provides utilities for loading and processing internal transfers, 
including those related to rewards like block and uncle rewards. It also 
handles price loading for the transferred value.

The module implements caching mechanisms and error handling to optimize 
performance and ensure robustness when dealing with blockchain data.

Key components:
- Transaction status retrieval
- Internal transfer processing and conversion
- Reward type identification (block and uncle rewards)
- Price loading for transferred value (optional)
"""

from decimal import Decimal

from brownie import chain
from dank_mids.structs import FilterTrace
from dank_mids.structs.trace import Type as TxType
from y._decorators import stuck_coro_debugger
from y.constants import EEE_ADDRESS

from eth_portfolio._cache import cache_to_disk
from eth_portfolio._loaders.utils import get_transaction_receipt
from eth_portfolio._utils import _get_price
from eth_portfolio.structs import InternalTransfer

    
@stuck_coro_debugger
async def load_internal_transfer(trace: FilterTrace, load_prices: bool) -> InternalTransfer:
    """
    Asynchronously processes a raw internal transfer dictionary into an InternalTransfer object.

    This function is the core of the internal transfer processing pipeline. It handles
    various types of transfers, including special cases like block and uncle rewards.
    It also filters out certain transfers (e.g., to Gnosis Safe Singleton) and verifies
    transaction success for non-reward transfers.

    The function performs several data transformations:
    - Value and gas conversions
    - Optional USD price loading
    - Field standardization

    Args:
        transfer: A dictionary containing the raw internal transfer data. Expected to have keys such as
                  'type', 'transactionHash', 'blockNumber', 'from', 'to', 'value', 'gas', 'gasUsed', 'traceAddress'.
        load_prices: Flag to determine whether to load USD prices for the transfer value.

    Returns:
        A processed InternalTransfer object.

    Example:
        >>> transfer = {"type": "call", "transactionHash": "0x123...", "blockNumber": 15537393, "from": "0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48", "to": "0x7a250d5630B4cF539739dF2C5dAcb4c659F2488D", "value": "0x10", "gas": "0x5208", "gasUsed": "0x5208", "traceAddress": [0]}
        >>> internal_tx = await load_internal_transfer(transfer=transfer, load_prices=True); print(internal_tx)

    Note:
        - Transfers to the Gnosis Safe Singleton (0xd9Db270c1B5E3Bd161E8c8503c55cEABeE709552) are filtered out
          as they typically don't represent actual value transfers.
        - The `traceAddress` is converted to a string for consistent representation across different scenarios.
        - For block and uncle rewards, `gas` is set to 0 as these are not regular transactions.
        - When loading prices, the `EEE_ADDRESS` constant is used, which represents the native currency of the chain.

    Integration with eth_portfolio ecosystem:
        - Uses the InternalTransfer struct from eth_portfolio.structs for standardized output.
        - Utilizes utility functions from eth_portfolio._loaders.utils and eth_portfolio._utils.
        - Interacts with the global 'chain' object from the brownie library for chain ID.
    """
    
    params = {"trace": trace}

    if load_prices:
        block = trace.block
        value = trace.action.value
        del trace  # we dont need to maintain this reference while we fetch the price
        price = round(Decimal(await _get_price(EEE_ADDRESS, block)), 18)
        params['price'] = price
        params['value_usd'] = round(value * price, 18)
    
    return InternalTransfer(**params)
    
