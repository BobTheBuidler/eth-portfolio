"""
This module contains loader functions that facilitate the retrieval and loading of blockchain transaction data.

The functions defined here use various async operations to retrieve transaction data from Ethereum-like blockchains, and process them, to then store them in a local database. The module leverages utilities like retry mechanisms, caching, and efficient async processing to handle potentially large amounts of blockchain data.

The primary focus of this module is to support eth-portfolio's internal operations such as loading transactions by address and nonce, retrieving transaction details from specific blocks, and managing transaction-related data.
"""

import logging
from decimal import Decimal
from typing import List, Optional, Tuple

import a_sync
import dank_mids
import eth_retry
from async_lru import alru_cache
from brownie import chain
from dank_mids.types import Transaction as dTransaction
from pony.orm import TransactionIntegrityError
from y import get_price
from y._decorators import stuck_coro_debugger
from y.constants import EEE_ADDRESS
from y.datatypes import Address, Block

from eth_portfolio._db import utils as db
from eth_portfolio._loaders.utils import get_transaction_receipt, underscore
from eth_portfolio.structs import AccessListEntry, Transaction

logger = logging.getLogger(__name__)

Nonce = int

@eth_retry.auto_retry
@stuck_coro_debugger
async def load_transaction(address: Address, nonce: Nonce, load_prices: bool) -> Tuple[Nonce, Optional[Transaction]]:
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
    lo = 0
    hi = await dank_mids.eth.block_number
    while True:
        _nonce = await get_nonce_at_block(address, lo)
        if _nonce < nonce:
            old_lo = lo
            lo += int((hi - lo) / 2) or 1
            logger.debug(f"Nonce at {old_lo} is {_nonce}, checking higher block {lo}")
        elif _nonce >= nonce:
            prev_block_nonce = await get_nonce_at_block(address, lo - 1)
            if prev_block_nonce < nonce:
                logger.debug(f"Found nonce {nonce} at block {lo}")
                tx = await get_transaction_by_nonce_and_block(address, nonce, lo)
                if tx is None:
                    return nonce, None
                tx = dict(tx)
                tx['chainid'] = int(tx.pop('chainId'), 16) if 'chainId' in tx else chain.id
                tx['block_hash'] = tx.pop('blockHash').hex()
                tx['hash'] = tx['hash'].hex()
                tx['from_address'] = tx.pop('from')
                tx['to_address'] = tx.pop('to')
                tx['value'] = Decimal(tx['value']) / Decimal(10**18)
                tx['type'] = int(tx['type'], 16) if "type" in tx else None
                tx['r'] = tx['r'].hex()
                tx['s'] = tx['s'].hex()
                if load_prices:
                    tx['price'] = round(Decimal(await get_price(EEE_ADDRESS, block = tx['blockNumber'], sync=False)), 18)
                    tx['value_usd'] = tx['value'] * tx['price']
                if access := tx.pop('accessList', None):
                    tx['access_list'] = tuple(AccessListEntry(address=obj["address"], storage_keys=obj["storageKeys"]) for obj in access)
                try:
                    transaction = Transaction(**{underscore(k): v for k, v in tx.items()})
                except TypeError as e:
                    raise TypeError(str(e), tx) from e
                try:
                    await db.insert_transaction(transaction)
                except TransactionIntegrityError:
                    if load_prices:
                        await db.delete_transaction(transaction)
                        await db.insert_transaction(transaction)
                return nonce, transaction
            hi = lo
            lo = int(lo / 2)
            logger.debug(f"Nonce at {hi} is {_nonce}, checking lower block {lo}")

@eth_retry.auto_retry
@stuck_coro_debugger
async def get_transaction_by_nonce_and_block(address: Address, nonce: int, block: Block) -> Optional[dTransaction]:
    """
    This function retrieves a transaction for a specifified address by its nonce and block, if any match.
    
    It also handles special cases:

        1. Contract creation transactions where the transaction's 'to' field is None.
        2. Gnosis Safe deployments where the transaction's 'to' field is a specific address.

    Args:
        address: The addresses of the accounts involved in the transaction.
        nonce: The nonce associated with the transaction creator.
        block: The block number from which to retrieve the transactions.

    Returns:
        The transaction data if found, otherwise None.

    Example:
        >>> transaction = await get_transaction_by_nonce_and_block(address="0x1234567890abcdef1234567890abcdef12345678", nonce=5, block=1234567)
        >>> if transaction:
        ...     print(transaction['hash'])
    """
    txs = await get_block_transactions(block)
    for tx in txs:
        if tx['from'] == address and tx['nonce'] == nonce:
            return tx
        # Special handler for contract creation transactions
        elif tx['to'] is None and (await get_transaction_receipt(tx['hash'])).contractAddress == address:
            return tx
        # Special handler for Gnosis Safe deployments
        elif tx['to'] == "0xa6B71E26C5e0845f74c812102Ca7114b6a896AB2":
            events = chain.get_transaction(tx['hash']).events
            if "SafeSetup" in events and "ProxyCreation" in events and any(event['proxy'] == address for event in events['ProxyCreation']):
                return tx
    return None

@alru_cache(maxsize=None)
@eth_retry.auto_retry
@stuck_coro_debugger
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
    try:
        return await dank_mids.eth.get_transaction_count(address, block_identifier = block) - 1
    except ValueError as e:
        # NOTE this is known to occur on Arbitrum
        if 'error creating execution cursor' in str(e) and block == 0:
            return -1
        raise ValueError(f"For {address} at {block}: {e}") from e

@alru_cache(ttl=60*60)
@eth_retry.auto_retry
@stuck_coro_debugger
async def _get_block_transactions(block: Block) -> List[dTransaction]:
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
        >>> [print(tx['hash']) for tx in transactions]
    """
    block = await dank_mids.eth.get_block(block, full_transactions=True)
    return block.transactions

get_block_transactions = a_sync.SmartProcessingQueue(
    _get_block_transactions, 
    num_workers=1_000, 
    name=__name__ + ".get_block_transactions",
)
