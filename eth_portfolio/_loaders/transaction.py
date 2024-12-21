"""
This module contains loader functions that facilitate the retrieval and loading of blockchain transaction data.

The functions defined here use various async operations to retrieve transaction data from Ethereum-like blockchains, and process them, to then store them in a local database. The module leverages utilities like retry mechanisms, caching, and efficient async processing to handle potentially large amounts of blockchain data.

The primary focus of this module is to support eth-portfolio's internal operations such as loading transactions by address and nonce, retrieving transaction details from specific blocks, and managing transaction-related data.
"""

import asyncio
import itertools
from collections import defaultdict
from logging import DEBUG, getLogger
from typing import DefaultDict, Dict, List, Optional, Tuple

import a_sync
import dank_mids
import eth_retry
import evmspec
import msgspec
from async_lru import alru_cache
from evmspec import data
from pony.orm import TransactionIntegrityError
from y import get_price
from y._decorators import stuck_coro_debugger
from y.constants import EEE_ADDRESS
from y.datatypes import Address, Block
from y.exceptions import reraise_excs_with_extra_context
from y.utils.events import decode_logs

from eth_portfolio.structs import structs
from eth_portfolio._cache import cache_to_disk
from eth_portfolio._db import utils as db
from eth_portfolio._decimal import Decimal
from eth_portfolio._loaders.utils import get_transaction_receipt

logger = getLogger(__name__)

Nonce = int
Nonces = DefaultDict[Nonce, Block]

nonces: DefaultDict[Address, Nonces] = defaultdict(lambda: defaultdict(int))


@eth_retry.auto_retry
@stuck_coro_debugger
async def load_transaction(
    address: Address, nonce: Nonce, load_prices: bool
) -> Tuple[Nonce, Optional[structs.Transaction]]:
    """
    Loads a transaction by address and nonce.

    This function attempts to load a transaction from the local database based on the given address and nonce.

    If the transaction is not found in the local database or if price data is missing but requested by the user, it retrieves the transaction data from the blockchain using a binary search approach, processes it, and stores it back in the local database.

    Args:
        address: The address of the account involved in the transaction.
        nonce: The nonce associated with the transaction.
        load_prices: Whether to load and calculate price-related information for the transaction.

    Returns:
        A tuple containing the nonce and the retrieved or newly created :class:`~eth_portfolio.structs.Transaction` object, or None if the transaction could not be found.

    Example:
        >>> print(await load_transaction(address="0x1234567890abcdef1234567890abcdef12345678", nonce=5, load_prices=True))
        (5, Transaction(...))
    """
    if transaction := await db.get_transaction(address, nonce):
        if load_prices and transaction.price is None:
            await db.delete_transaction(transaction)
        else:
            return nonce, transaction

    block = await get_block_for_nonce(address, nonce)
    tx = await get_transaction_by_nonce_and_block(address, nonce, block)
    if tx is None:
        return nonce, None

    if load_prices:
        # TODO: debug why `tx.value` isnt already a Wei obj
        scaled = data.Wei(tx.value).scaled
        price = Decimal(await get_price(EEE_ADDRESS, block=tx.blockNumber, sync=False))
        transaction = structs.Transaction.from_rpc_response(
            tx, price=round(price, 18), value_usd=round(scaled * price, 18)
        )
    else:
        transaction = structs.Transaction.from_rpc_response(tx)

    a_sync.create_task(
        coro=_insert_to_db(transaction, load_prices),
        skip_gc_until_done=True,
    )

    return nonce, transaction


@alru_cache(maxsize=None, ttl=5)
async def _get_block_number():
    return await dank_mids.eth.block_number


_nonce_cache_locks: DefaultDict[Address, asyncio.Lock] = defaultdict(asyncio.Lock)


async def get_block_for_nonce(address: Address, nonce: Nonce) -> int:
    async with _nonce_cache_locks[address]:
        highest_known_nonce_lower_than_query = None
        lowest_known_nonce_greater_than_query = None

        # it is impossible for n to == nonce
        filtered = filter(lambda n: n != nonce, nonces[address])
        for less_than, ns in itertools.groupby(filtered, lambda n: n < nonce):
            if less_than:
                max_value = max(ns)
                if (
                    highest_known_nonce_lower_than_query is None
                    or max_value > highest_known_nonce_lower_than_query
                ):
                    highest_known_nonce_lower_than_query = max_value

            else:
                min_value = min(ns)
                if (
                    lowest_known_nonce_greater_than_query is None
                    or min_value < lowest_known_nonce_greater_than_query
                ):
                    lowest_known_nonce_greater_than_query = min_value

        if highest_known_nonce_lower_than_query is not None:
            lo = nonces[address][highest_known_nonce_lower_than_query]
        else:
            lo = 0

        if lowest_known_nonce_greater_than_query is not None:
            hi = nonces[address][lowest_known_nonce_greater_than_query]
        else:
            hi = await _get_block_number()

        del highest_known_nonce_lower_than_query, lowest_known_nonce_greater_than_query

        # lets find the general area first before we proceed with our binary search
        range_size = hi - lo + 1
        if range_size > 4:
            num_chunks = _get_num_chunks(range_size)
            chunk_size = range_size // num_chunks
            points: Dict[int, Nonce] = await a_sync.gather(
                {
                    point: get_nonce_at_block(address, point)
                    for point in (lo + i * chunk_size for i in range(num_chunks))
                }
            )

            for block, _nonce in points.items():
                if _nonce >= nonce:
                    hi = block
                    break
                lo = block

            del num_chunks, chunk_size, points, block

        del range_size

    debug_logs_enabled = logger.isEnabledFor(DEBUG)
    while True:
        _nonce = await get_nonce_at_block(address, lo)

        if _nonce < nonce:
            old_lo = lo
            lo += int((hi - lo) / 2) or 1
            if debug_logs_enabled:
                logger._log(
                    DEBUG,
                    "Nonce for %s at %s is %s, checking higher block %s",
                    (address, old_lo, _nonce, lo),
                )
            continue

        prev_block_nonce: int = await get_nonce_at_block(address, lo - 1)
        if prev_block_nonce >= nonce:
            hi = lo
            lo = int(lo / 2)
            if debug_logs_enabled:
                logger._log(
                    DEBUG,
                    "Nonce for %s at %s is %s, checking lower block %s",
                    (address, hi, _nonce, lo),
                )
            continue

        if debug_logs_enabled:
            logger._log(DEBUG, "Found nonce %s for %s at block %s", (nonce, address, lo))

        return lo


async def _insert_to_db(transaction: structs.Transaction, load_prices: bool) -> None:
    with reraise_excs_with_extra_context(transaction):
        try:
            await db.insert_transaction(transaction)
        except TransactionIntegrityError:
            if load_prices:
                await db.delete_transaction(transaction)
                await db.insert_transaction(transaction)


@eth_retry.auto_retry
@stuck_coro_debugger
@cache_to_disk
async def get_transaction_by_nonce_and_block(
    address: Address, nonce: int, block: Block
) -> Optional[evmspec.Transaction]:
    """
    This function retrieves a transaction for a specifified address by its nonce and block, if any match.

    It also handles special cases:

        1. Contract creation transactions where the transaction's 'to' field is None.
        2. Gnosis Safe deployments where the transaction's 'to' field is a specific address.

    Args:
        address: The addresses of the accounts that sent the transaction.
        nonce: The nonce associated with the transaction creator.
        block: The block number from which to retrieve the transactions.

    Returns:
        The transaction data if found, otherwise None.

    Example:
        >>> transaction = await get_transaction_by_nonce_and_block(address="0x1234567890abcdef1234567890abcdef12345678", nonce=5, block=1234567)
        >>> if transaction:
        ...     print(transaction.hash)
    """
    for tx in await get_block_transactions(block):
        if tx.sender == address and tx.nonce == nonce:
            return tx

        receipt_bytes: msgspec.Raw
        # Special handler for contract creation transactions
        if tx.to is None:
            receipt_bytes = await get_transaction_receipt(tx.hash.hex())
            receipt_0 = msgspec.json.decode(
                receipt_bytes,
                type=ReceiptContractAddress,
                dec_hook=data.Address._decode_hook,
            )
            if receipt_0.contractAddress == address:
                return tx
        # Special handler for Gnosis Safe deployments
        elif tx.to == "0xa6B71E26C5e0845f74c812102Ca7114b6a896AB2":
            receipt_bytes = await get_transaction_receipt(tx.hash.hex())
            receipt_1 = msgspec.json.decode(
                receipt_bytes,
                type=ReceiptLogs,
                dec_hook=data._decode_hook,
            )
            events = decode_logs(receipt_1.logs)
            if (
                "SafeSetup" in events
                and "ProxyCreation" in events
                and any(event["proxy"] == address for event in events["ProxyCreation"])
            ):
                return tx
    return None


class ReceiptContractAddress(msgspec.Struct):
    """We only decode what we need and immediately discard the rest of the receipt."""

    contractAddress: data.Address


class ReceiptLogs(msgspec.Struct):
    logs: List[evmspec.Log]


@alru_cache(maxsize=None)
@eth_retry.auto_retry
@stuck_coro_debugger
@cache_to_disk
async def get_nonce_at_block(address: Address, block: Block) -> int:
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
    nonce = None
    try:
        # This is a temp fix for a bug in dank mids
        # TODO move this into dank
        while nonce is None:
            nonce = await dank_mids.eth.get_transaction_count(address, block_identifier=block) - 1
        _update_nonces(address, nonce, block)
        return nonce
    except ValueError as e:
        # NOTE this is known to occur on Arbitrum
        if "error creating execution cursor" in str(e) and block == 0:
            return -1
        raise ValueError(f"For {address} at {block}: {e}") from e


def _update_nonces(address: Address, nonce: Nonce, block: Block):
    # if you are searching for `nonce` and you verified it occurs AT or ABOVE `block` call this fn.
    if block > nonces[address][nonce]:
        nonces[address][nonce] = block


@alru_cache(ttl=60 * 60)
@eth_retry.auto_retry
@stuck_coro_debugger
async def _get_block_transactions(block: Block) -> List[evmspec.Transaction]:
    """
    Retrieves all transactions from a specific block.

    This function fetches the full transaction data for a block using async caching to optimize repeated requests.

    The cache has a time-to-live (TTL) of 1 hour to avoid memory leaks for services or long-running scripts.

    Args:
        block: The block number from which to retrieve the transactions.

    Returns:
        A list of transaction data objects from the block.

    Example:
        >>> transactions = await _get_block_transactions(block=12345678)
        >>> [print(tx.hash) for tx in transactions]
    """
    return await dank_mids.eth.get_transactions(block)


get_block_transactions = a_sync.SmartProcessingQueue(_get_block_transactions, 1_000)
"""
A smart processing queue that retrieves transactions from blocks with managable concurrency.

This queue processes the retrieval of block transactions using a limited number of workers to handle potentially overwhelming volume of transactions.
It wraps the _get_block_transactions function to provide efficient concurrent processing.

Example:
    >>> transactions = await get_block_transactions.process(block=12345678)
    >>> [print(tx['hash']) for tx in transactions]
"""


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
