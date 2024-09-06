"""
Loader functions for processing internal transfers on the blockchain.

This module provides utilities for loading and processing internal transfers, 
including those related to rewards like block and uncle rewards. It also 
handles price loading for the transferred value and checksum addresses.

The module implements caching mechanisms and error handling to optimize 
performance and ensure robustness when dealing with blockchain data.

Key components:
- Transaction status retrieval
- Internal transfer processing and conversion
- Reward type identification (block and uncle rewards)
- Address checksumming and value conversion
- Price loading for transferred value (optional)
"""

from decimal import Decimal
from typing import Optional

from brownie import chain
from y._decorators import stuck_coro_debugger
from y.constants import EEE_ADDRESS

from eth_portfolio._cache import cache_to_disk
from eth_portfolio._loaders.utils import checksum, get_transaction_receipt, underscore
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
    - Address checksumming
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
        - This function relies on several helper functions (:func:`~eth_portfolio._loaders.internal_transfer.is_block_reward`, :func:`~eth_portfolio._loaders.internal_transfer.is_uncle_reward`,
          :func:`~eth_portfolio._loaders.internal_transfer._get_status`) and utility functions from other modules (:func:`~eth_portfolio._loaders.utils.checksum`, :func:`~eth_portfolio._utils._get_price`,
          :func:`~eth_portfolio._loaders.utils.underscore`).
        - Transfers to the Gnosis Safe Singleton (0xd9Db270c1B5E3Bd161E8c8503c55cEABeE709552) are filtered out
          as they typically don't represent actual value transfers.
        - The `traceAddress` is converted to a string for consistent representation across different scenarios.
        - For block and uncle rewards, `gas` is set to 0 as these are not regular transactions.
        - When loading prices, the `EEE_ADDRESS` constant is used, which represents the native currency of the chain.
        - The `underscore` function is used to convert camelCase keys to snake_case for the InternalTransfer struct.

    Integration with eth_portfolio ecosystem:
        - Uses the InternalTransfer struct from eth_portfolio.structs for standardized output.
        - Utilizes utility functions from eth_portfolio._loaders.utils and eth_portfolio._utils.
        - Interacts with the global 'chain' object from the brownie library for chain ID.
    """
    if transfer.get("to") == "0xd9db270c1b5e3bd161e8c8503c55ceabee709552":
        # "0xd9Db270c1B5E3Bd161E8c8503c55cEABeE709552":  # Gnosis Safe Singleton 1.3.0
        # NOTE: Not sure why these appear, but I've yet to come across an internal transfer
        # that actually transmitted value to the singleton even though they appear to.
        return None
        
    if is_block_reward(transfer):
        transfer['transactionHash'] = 'block reward'
    elif is_uncle_reward(transfer):
        transfer['transactionHash'] = 'uncle reward'
    else:
        # NOTE: We don't need to confirm block rewards came from a successful transaction, because they don't come from a transaction
        # In all other cases, we need to confirm the transaction didn't revert
        if await _get_status(transfer['transactionHash']) == 0:
            return None

    # Un-nest the action dict
    if action := transfer.pop('action', None):
        for key, value in action.items():
            if key == 'author':
                # for block reward transfers, the recipient is 'author'
                transfer['to'] = value
            else:
                transfer[key] = value
            
    # Un-nest the result dict
    if result := transfer.pop('result', None):
        for key, value in result.items():
            transfer[key] = value

    # Checksum the addresses
    if "from" in transfer:
        transfer['from_address'] = checksum(transfer.pop('from'))
    if "to" in transfer:
        transfer['to_address'] = checksum(transfer.pop('to'))
    if "address" in transfer:
        transfer['address'] = checksum(transfer.pop('address'))
        
    transfer['traceAddress'] = str(transfer['traceAddress'])
    transfer['value'] = Decimal(int(transfer['value'], 16)) / Decimal(10**18)
    transfer['gas'] = 0 if is_block_reward(transfer) or is_uncle_reward(transfer) else int(transfer['gas'], 16)
    transfer['gasUsed'] = int(transfer['gasUsed'], 16) if transfer.get('gasUsed') else None

    if load_prices:
        price = round(Decimal(await _get_price(EEE_ADDRESS, transfer['blockNumber'])), 18)
        transfer['price'] = price
        transfer['value_usd'] = round(transfer['value'] * price, 18)
        
    transfer['hash'] = transfer.pop('transactionHash')
    transfer['transaction_index'] = transfer.pop('transactionPosition', None)
    transfer['chainid'] = chain.id

    # We include this data in the hash field, we don't need it anymore
    transfer.pop('rewardType', None)
    
    return InternalTransfer(**{underscore(k): v for k, v in transfer.items()})

def is_block_reward(transfer: dict) -> bool:
    """
    Determines if the given transfer represents a block reward.

    This function works in conjunction with :func:`~eth_portfolio._loaders.internal_transfer.get_reward_type` to identify
    block reward transfers, which are treated differently in the main processing function.

    Args:
        transfer: The transfer dictionary to check. Expected to have a 'type' key and either a 'rewardType' key
                  or a nested 'action' dictionary with a 'rewardType' key.

    Returns:
        bool: True if the transfer is a block reward, False otherwise.

    Example:
        >>> transfer = {"type": "reward", "rewardType": "block"}
        >>> print(is_block_reward(transfer=transfer))  # Output: True

    Note:
        This function is used within :func:`~eth_portfolio._loaders.internal_transfer.load_internal_transfer` to handle
        special cases for block rewards. Block rewards are not associated with
        regular transactions and require different processing in the eth_portfolio system.
    """
    return transfer['type'] == 'reward' and get_reward_type(transfer) == 'block'

def is_uncle_reward(transfer: dict) -> bool:
    """
    Determines if the given transfer represents an uncle reward.

    Similar to :func:`~eth_portfolio._loaders.internal_transfer.is_block_reward`, this function works with :func:`~eth_portfolio._loaders.internal_transfer.get_reward_type`
    to identify uncle reward transfers, which are also treated as special
    cases in the main processing function.

    Args:
        transfer: The transfer dictionary to check. Expected to have a 'type' key and either a 'rewardType' key
                  or a nested 'action' dictionary with a 'rewardType' key.

    Returns:
        bool: True if the transfer is an uncle reward, False otherwise.

    Example:
        >>> transfer = {"type": "reward", "rewardType": "uncle"}
        >>> print(is_uncle_reward(transfer=transfer))  # Output: True

    Note:
        This function is used within :func:`~eth_portfolio._loaders.internal_transfer.load_internal_transfer` to handle
        special cases for uncle rewards. Uncle rewards, like block rewards,
        are not associated with regular transactions and require different
        processing in the eth_portfolio system.
    """
    return transfer['type'] == 'reward' and get_reward_type(transfer) == 'uncle'

def get_reward_type(transfer: dict) -> str:
    """
    Retrieves the reward type from a transfer dictionary.

    This function handles the potential nested structure of the transfer
    dictionary, looking for the 'rewardType' key in either the main dict
    or a nested 'action' dict.

    Args:
        transfer: The transfer dictionary containing the reward type information. Expected to have either
                  a 'rewardType' key or a nested 'action' dictionary with a 'rewardType' key.

    Returns:
        str: The reward type, either 'block' or 'uncle'.

    Raises:
        ValueError: If the transfer is not of reward type (i.e., neither location contains a 'rewardType' key).

    Example:
        >>> transfer = {"type": "reward", "rewardType": "block"}; print(get_reward_type(transfer=transfer))  # Output: 'block'
        >>> transfer = {"type": "reward", "action": {"rewardType": "uncle"}}; print(get_reward_type(transfer=transfer))  # Output: 'uncle'
        >>> transfer = {"type": "call", "value": "0x0"}; get_reward_type(transfer=transfer)  # Raises ValueError

    Note:
        This function is used by both :func:`~eth_portfolio._loaders.internal_transfer.is_block_reward` and :func:`~eth_portfolio._loaders.internal_transfer.is_uncle_reward`
        to determine the specific type of reward transfer. It's crucial for
        correctly processing different types of rewards in the eth_portfolio system.
        The function accounts for potential variations in the structure of the
        transfer dictionary, which may occur due to differences in data sources
        or blockchain explorers.
    """
    try:
        return transfer.get('rewardType') or transfer['action']['rewardType']
    except KeyError:
        raise ValueError('transfer is not reward type') from None
