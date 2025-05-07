from typing import Final

import dank_mids
import eth_retry
import msgspec
from a_sync import SmartProcessingQueue
from async_lru import alru_cache
from eth_typing import HexStr
from y._decorators import stuck_coro_debugger


Raw: Final = msgspec.Raw
TxReceiptQueue = SmartProcessingQueue[HexStr, [], msgspec.Raw]


@eth_retry.auto_retry(min_sleep_time=1, max_sleep_time=3, max_retries=20, suppress_logs=1)
@alru_cache(maxsize=None, ttl=60 * 60)
@stuck_coro_debugger
async def _get_transaction_receipt(txhash: HexStr) -> msgspec.Raw:
    """
    Fetches the transaction receipt for a given transaction hash.

    This function retrieves the transaction receipt from the Ethereum network
    using the provided transaction hash. It utilizes caching to store results
    for a specified time-to-live (TTL) to improve performance and reduce
    network calls. The function is also decorated to automatically retry
    in case of failures and to debug if the coroutine gets stuck.

    Args:
        txhash: The transaction hash for which to retrieve the receipt.

    Returns:
        msgspec.Raw: The raw transaction receipt data.

    Examples:
        >>> txhash = "0x1234567890abcdef..."
        >>> receipt = await _get_transaction_receipt(txhash)
        >>> print(receipt)

    See Also:
        - :func:`eth_retry.auto_retry`: For automatic retry logic.
        - :func:`async_lru.alru_cache`: For caching the results.
        - :func:`y._decorators.stuck_coro_debugger`: For debugging stuck coroutines.
    """
    return await __get_transaction_receipt(txhash, decode_to=Raw, decode_hook=None)


get_transaction_receipt: Final[TxReceiptQueue] = SmartProcessingQueue(
    _get_transaction_receipt, 5000
)
"""
A queue for processing transaction receipt requests.

This queue manages the processing of transaction receipt requests, allowing
up to 5000 concurrent requests. It uses the `_get_transaction_receipt` function
to fetch the receipts.

Examples:
    >>> txhash = "0x1234567890abcdef..."
    >>> receipt = await get_transaction_receipt(txhash)
    >>> print(receipt)

See Also:
    - :class:`a_sync.SmartProcessingQueue`: For managing asynchronous processing queues.
"""


__get_transaction_receipt: Final = dank_mids.eth.get_transaction_receipt
