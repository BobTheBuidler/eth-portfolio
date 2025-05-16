import asyncio
import logging
from collections import defaultdict
from time import time
from typing import ClassVar, DefaultDict, Dict, Final, Tuple, final

import a_sync
import dank_mids
from eth_typing import BlockNumber, ChecksumAddress

from eth_portfolio._loaders import utils


logger: Final = logging.getLogger("eth_portfolio.nonces")
logger_is_enabled: Final = logger.isEnabledFor
__log: Final = logger._log

DEBUG: Final = logging.DEBUG

Nonce = int
AccountNonces = DefaultDict[Nonce, BlockNumber]
GlobalNonces = DefaultDict[ChecksumAddress, AccountNonces]

nonces: Final[GlobalNonces] = defaultdict(lambda: defaultdict(int))  # type: ignore [arg-type]
locks: Final[DefaultDict[ChecksumAddress, asyncio.Lock]] = defaultdict(asyncio.Lock)

get_transaction_count: Final = dank_mids.eth.get_transaction_count

igather: Final = a_sync.igather

now: Final = time


async def get_nonce_at_block(address: ChecksumAddress, block: BlockNumber) -> int:
    """
    Retrieves the nonce of an address at a specific block.

    This function gets the transaction count (nonce) for the given address at the specified block. It also includes a special case to handle known issues on certain networks like Arbitrum.

    Args:
        address: The address of the account.
        block: The block number at which to retrieve the nonce.

    Returns:
        The nonce of the address at the given block.

    Example:
        >>> block = 12345678
        >>> nonce = await get_nonce_at_block("0x1234567890abcdef1234567890abcdef12345678", block)
        >>> print(f"The nonce at block {block} is {nonce}.")

    """
    try:
        nonce = await get_transaction_count(address, block_identifier=block) - 1
        _update_nonces(address, nonce, block)
        return nonce
    except ValueError as e:
        # NOTE this is known to occur on Arbitrum
        if "error creating execution cursor" in str(e) and block == 0:
            return -1
        raise ValueError(f"For {address} at {block}: {e}") from e


async def get_block_for_nonce(address: ChecksumAddress, nonce: Nonce) -> int:
    highest_known_nonce_lt_query: Optional[int]
    lowest_known_nonce_gt_query: Optional[int]

    async with locks[address]:
        highest_known_nonce_lt_query = None
        lowest_known_nonce_gt_query = None

        # it is impossible for n to == nonce
        for n in nonces[address]:
            if n < nonce:
                if highest_known_nonce_lt_query is None or n > highest_known_nonce_lt_query:
                    highest_known_nonce_lt_query = n
            elif n == nonce:
                continue
            elif lowest_known_nonce_gt_query is None or n < lowest_known_nonce_gt_query:
                lowest_known_nonce_gt_query = n

        if highest_known_nonce_lt_query is not None:
            lo = nonces[address][highest_known_nonce_lt_query]
        else:
            lo = BlockNumber(0)

        if lowest_known_nonce_gt_query is not None:
            hi = nonces[address][lowest_known_nonce_gt_query]
        else:
            hi = await get_block_number()

        # lets find the general area first before we proceed with our binary search
        range_size = hi - lo + 1
        if range_size > 4:
            lo, hi = await _get_area(address, nonce, lo, hi, range_size)

    debug_logs_enabled = logger_is_enabled(DEBUG)
    while True:
        _nonce = await get_nonce_at_block(address, lo)

        if _nonce < nonce:
            old_lo = lo
            lo += int((hi - lo) / 2) or 1  # type: ignore [assignment]
            if debug_logs_enabled:
                __log(
                    DEBUG,
                    "Nonce for %s at %s is %s, checking higher block %s",
                    (address, old_lo, _nonce, lo),
                )
            continue

        prev_block_nonce: int = await get_nonce_at_block(address, lo - 1)  # type: ignore [arg-type]
        if prev_block_nonce >= nonce:
            hi = lo
            lo = int(lo / 2)  # type: ignore [assignment]
            if debug_logs_enabled:
                __log(
                    DEBUG,
                    "Nonce for %s at %s is %s, checking lower block %s",
                    (address, hi, _nonce, lo),
                )
            continue

        if debug_logs_enabled:
            __log(DEBUG, "Found nonce %s for %s at block %s", (nonce, address, lo))

        return lo


async def _get_area(
    address: ChecksumAddress,
    nonce: Nonce,
    lo: BlockNumber,
    hi: BlockNumber,
    range_size: int,
) -> Tuple[BlockNumber, BlockNumber]:
    num_chunks = _get_num_chunks(range_size)
    chunk_size = range_size // num_chunks
    points = [BlockNumber(lo + i * chunk_size) for i in range(num_chunks)]
    nonces = await igather(get_nonce_at_block(address, point) for point in points)
    for block, n in zip(points, nonces):
        if n >= nonce:
            return lo, block
        lo = block
    return lo, hi


def _update_nonces(address: ChecksumAddress, nonce: Nonce, block: BlockNumber):
    # if you are searching for `nonce` and you verified it occurs AT or ABOVE `block` call this fn.
    if block > nonces[address][nonce]:
        nonces[address][nonce] = block


def _get_num_chunks(range_size: int) -> int:
    if range_size >= 4096:
        return 100
    elif range_size >= 2048:
        return 80
    elif range_size >= 1024:
        return 40
    elif range_size >= 512:
        return 20
    elif range_size >= 256:
        return 10
    elif range_size >= 128:
        return 8
    elif range_size >= 64:
        return 6
    elif range_size >= 32:
        return 5
    elif range_size >= 16:
        return 4
    elif range_size >= 8:
        return 3
    else:
        return 2


@final
class BlockCache:
    block: ClassVar = 0
    updated_at: ClassVar = 0.0
    lock: Final = asyncio.Lock()
    ttl: Final = 5.0


async def get_block_number():
    if now() - BlockCache.updated_at < BlockCache.ttl:
        return BlockCache.block
    async with BlockCache.lock:
        if now() - BlockCache.updated_at < BlockCache.ttl:
            return BlockCache.block
        ts = now()
        block = BlockCache.block = await dank_mids.eth.block_number
        BlockCache.updated_at = ts
        return block
