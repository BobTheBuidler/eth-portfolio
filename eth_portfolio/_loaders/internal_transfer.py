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
from typing import Optional

from brownie import chain
from dank_mids.structs import Trace
from y._decorators import stuck_coro_debugger
from y.constants import EEE_ADDRESS

from eth_portfolio._cache import cache_to_disk
from eth_portfolio._loaders.utils import get_transaction_receipt
from eth_portfolio._utils import _get_price
from eth_portfolio.structs import InternalTransfer

@cache_to_disk
async def _get_status(txhash: str) -> int:
    """
    Asynchronously retrieves the transaction status for the given hash.

    This function is cached to disk to optimize performance for repeated calls.
    It relies on the :func:`~eth_portfolio._loaders.utils.get_transaction_receipt` function from the utils module.

    Args:
        txhash: The hexadecimal string representation of the transaction hash.

    Returns:
        int: The status of the transaction (1 for success, 0 for failure).

    Example:
        >>> status = await _get_status(txhash="0x123..."); print(status)

    Note:
        This function is primarily used within :func:`~eth_portfolio._loaders.internal_transfer.load_internal_transfer` to verify
        transaction success for non-reward transfers. The caching mechanism helps reduce
        redundant blockchain queries, improving overall performance of the eth_portfolio system.
    """
    receipt = await get_transaction_receipt(txhash)
    return receipt.status
    
@stuck_coro_debugger
async def load_internal_transfer(transfer: dict, load_prices: bool) -> Optional[InternalTransfer]:
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
        Optional: A processed InternalTransfer object, or None if the
        transfer is invalid, irrelevant, or from a failed transaction.

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
    if trace.to == "0xd9Db270c1B5E3Bd161E8c8503c55cEABeE709552":  # Gnosis Safe Singleton 1.3.0
        # NOTE: Not sure why these appear, but I've yet to come across an internal transfer
        # that actually transmitted value to the singleton even though they appear to.
        return None

    if trace.type == "reward:
        if trace.action.rewardType not in ['block', 'uncle']:
            raise NotImplementedError(trace.action.rewardType)
        params = {'hash': f'{trace.action.rewardType} reward'}

    # NOTE: We don't need to confirm block rewards came from a successful transaction, because they don't come from a transaction
    # In all other cases, we need to confirm the transaction didn't revert
    elif await _get_status(trace.transactionHash) == 0:
        return None

    else:
        params = {'hash': trace.transactionHash}
    
    params['transaction_index'] = trace.transactionPosition
    params['chainid'] = chain.id

    # Un-nest the action dict
    if action := trace.action:
        for key, value in action.items():
            if key == 'author':
                # for block reward transfers, the recipient is 'author'
                params['to'] = value
            else:
                params[key] = value
            
    # Un-nest the result dict
    if result := trace.result:
        for key, value in result.items():
            params[key] = value

    # Remap the addresses
    if trace.sender:
        params['from_address'] = trace.sender
    if trace.to:
        params['to_address'] = trace.to

    value = trace.value_scaled
    params['value'] = value
    params['gas'] = 0 if trace.type == "reward" and trace.action.rewardType in ["block", "uncle"] else trace.gas

    if load_prices:
        price = round(Decimal(await _get_price(EEE_ADDRESS, trace.blockNumber)), 18)
        params['price'] = price
        params['value_usd'] = round(value * price, 18)
    
    return InternalTransfer(**params)
    
