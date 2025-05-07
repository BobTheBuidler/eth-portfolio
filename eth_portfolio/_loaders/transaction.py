"""
This module contains loader functions that facilitate the retrieval and loading of blockchain transaction data.

The functions defined here use various async operations to retrieve transaction data from Ethereum-like blockchains, and process them, to then store them in a local database. The module leverages utilities like retry mechanisms, caching, and efficient async processing to handle potentially large amounts of blockchain data.

The primary focus of this module is to support eth-portfolio's internal operations such as loading transactions by address and nonce, retrieving transaction details from specific blocks, and managing transaction-related data.
"""

from logging import getLogger
from typing import Awaitable, Callable, Final, List, Optional, Tuple

import a_sync
import dank_mids
import eth_retry
import evmspec
import msgspec
from a_sync import SmartProcessingQueue
from async_lru import alru_cache
from eth_typing import ChecksumAddress
from evmspec import data
from pony.orm import TransactionIntegrityError
from y import get_price
from y._decorators import stuck_coro_debugger
from y.constants import EEE_ADDRESS
from y.datatypes import Block
from y.exceptions import reraise_excs_with_extra_context
from y.utils.events import decode_logs

from eth_portfolio.structs import structs
from eth_portfolio._cache import cache_to_disk
from eth_portfolio._db import utils as db
from eth_portfolio._decimal import Decimal
from eth_portfolio._loaders._nonce import Nonce, get_block_for_nonce
from eth_portfolio._loaders._nonce import get_nonce_at_block as _get_nonce_at_block
from eth_portfolio._loaders.utils import get_transaction_receipt


Transactions = List[evmspec.Transaction]


logger: Final = getLogger(__name__)


@eth_retry.auto_retry
@stuck_coro_debugger
async def load_transaction(
    address: ChecksumAddress, nonce: Nonce, load_prices: bool
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
    address: ChecksumAddress, nonce: int, block: Block
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


get_transaction_count: Final = dank_mids.eth.get_transaction_count


@alru_cache(maxsize=None)
@eth_retry.auto_retry
@stuck_coro_debugger
@cache_to_disk
async def get_nonce_at_block(address: ChecksumAddress, block: Block) -> int:
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
    return await _get_nonce_at_block(address, block)


_get_block_transactions: Final[Callable[[Block], Awaitable[Transactions]]] = alru_cache(
    ttl=60 * 60
)(eth_retry.auto_retry(stuck_coro_debugger(dank_mids.eth.get_transactions)))
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


get_block_transactions: Final[SmartProcessingQueue[Block, [], Transactions]] = SmartProcessingQueue(
    _get_block_transactions, 1_000
)
"""
A smart processing queue that retrieves transactions from blocks with managable concurrency.

This queue processes the retrieval of block transactions using a limited number of workers to handle potentially overwhelming volume of transactions.
It wraps the _get_block_transactions function to provide efficient concurrent processing.

Example:
    >>> transactions = await get_block_transactions.process(block=12345678)
    >>> [print(tx['hash']) for tx in transactions]
"""
