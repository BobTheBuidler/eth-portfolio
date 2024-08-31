"""
This module orchestrates the process of loading and processing token transfers and associated metadata within the eth_portfolio ecosystem.

The module's primary responsibilities include decoding token transfer logs, retrieving pertinent transaction details, and persisting processed data in a local database. It leverages semaphores for concurrent operation management and implements caching mechanisms to optimize performance.

The module also encapsulates utility functions for retrieving token symbols and transaction indices.

Classes:
    :class:`~eth_portfolio._loaders.transactions._EventItem`: A type hinting construct extending brownie.EventItem, utilized solely for static analysis and not instantiated at runtime.
"""

import asyncio
import decimal
import logging
from decimal import Decimal
from typing import Optional, Union

import dank_mids
from brownie import chain
from brownie.exceptions import ContractNotFound
from brownie.network.event import _EventItem as brownie_EventItem
from pony.orm import TransactionIntegrityError
from y import ERC20, Contract
from y._decorators import stuck_coro_debugger
from y.exceptions import ContractNotVerified, NonStandardERC20
from y.utils.events import decode_logs

from eth_portfolio._cache import cache_to_disk
from eth_portfolio._db import utils as db
from eth_portfolio._loaders.utils import get_transaction_receipt
from eth_portfolio._shitcoins import SHITCOINS
from eth_portfolio._utils import _get_price
from eth_portfolio.structs import TokenTransfer

logger = logging.getLogger(__name__)

token_transfer_semaphore = dank_mids.BlockSemaphore(10_000, name='eth_portfolio.token_transfers')
"""A semaphore that regulates the concurrent processing of token transfers on a per-block basis."""


@stuck_coro_debugger
async def load_token_transfer(transfer_log: dict, load_prices: bool) -> Optional[TokenTransfer]:
    """
    Processes and loads a token transfer from a log entry, with comprehensive error handling and optional price fetching.

    This function employs a multi-step process:
    1. Validates the transfer against a known set of 'shitcoins', skipping processing if matched.
    2. Checks for existing database entries, potentially deleting and reprocessing if price data is requested but missing.
    3. Utilizes a semaphore to manage concurrent processing within the same block.
    4. Decodes the transfer log and retrieves associated metadata (e.g., token scale, symbol, transaction index).
    5. Optionally fetches the token price at the time of the transaction.
    6. Constructs and persists a :class:`~eth_portfolio.structs.TokenTransfer` object in the database.

    The function handles various exceptions, including :class:`~y.exceptions.NonStandardERC20` for non-compliant tokens and :class:`decimal.InvalidOperation` for extreme token values.

    Args:
        transfer_log: A dictionary containing the raw log entry of the token transfer.
        load_prices: A flag indicating whether to fetch and include price data for the token at the time of transfer.

    Returns:
        Optional: A processed TokenTransfer object if successful, or None if the transfer cannot be processed due to various constraints or errors.

    Raises:
        TypeError: If there's an incompatibility in the data types when constructing the TokenTransfer object.

    Note:
        This function employs caching mechanisms and database operations to optimize performance and maintain data consistency.
    """
    if transfer_log['address'] in SHITCOINS.get(chain.id, set()):
        return None
    
    if transfer := await db.get_token_transfer(transfer_log):
        if load_prices and transfer.price is None:
            await db.delete_token_transfer(transfer)
        else:
            return transfer
    
    async with token_transfer_semaphore[transfer_log["blockNumber"]]:
        decoded = await _decode_token_transfer(transfer_log)
        if decoded is None:
            return None
        token = ERC20(decoded.address, asynchronous=True)
        coros = [token.scale, get_symbol(token), get_transaction_index(decoded.transaction_hash)]
        
        try:
            if load_prices:
                coros.append(_get_price(token.address, decoded.block_number))
                scale, symbol, transaction_index, price = await asyncio.gather(*coros)
            else:
                scale, symbol, transaction_index = await asyncio.gather(*coros)
        except NonStandardERC20 as e:
            # NOTE: if we cant fetch scale or symbol or both, this is probably either a shitcoin or an NFT (which we don't support at this time)
            logger.debug(f"{e} for {transfer_log}, skipping.")
            return None
        
        sender, receiver, value = decoded.values()
        value = Decimal(value) / Decimal(scale)
        
        token_transfer = {
            'chainid': chain.id,
            'block_number': decoded.block_number,
            'transaction_index': transaction_index,
            # TODO figure out why it comes in both ways
            'hash': hash.hex() if isinstance((hash := decoded.transaction_hash), bytes) else hash,  # type: ignore [attr-defined]
            'log_index': decoded.log_index,
            'token': symbol,
            'token_address': decoded.address,
            'from_address': str(sender),
            'to_address': str(receiver),
            'value': value,
        }
        if load_prices:
            try:
                price = round(Decimal(price), 18) if price else None
            except Exception as e:
                logger.error(f"{e.__class__.__name__} {e} for {symbol} {decoded.address} at block {decoded.block_number}.")
                price = None
            token_transfer['price'] = price
            token_transfer['value_usd'] = round(value * price, 18) if price else None
        
        try:
            transfer = TokenTransfer(**token_transfer)
            await db.insert_token_transfer(transfer)
        except decimal.InvalidOperation:
        # Not entirely sure why this happens, probably some crazy uint value
            return None
        except TransactionIntegrityError:
            if load_prices:
                await db.delete_token_transfer(transfer)
                await db.insert_token_transfer(transfer)
        except TypeError as e:
            raise TypeError(str(e), token_transfer) from e
        return transfer

@stuck_coro_debugger
async def get_symbol(token: ERC20) -> Optional[str]:
    """
    Asynchronously retrieves the symbol of a given ERC20 token, with error handling for non-standard implementations.

    This function attempts to access the token's symbol through its asynchronous interface. If the token contract
    does not adhere to the standard ERC20 interface, indicated by a :class:`~y.exceptions.NonStandardERC20` exception, the function
    returns `None` instead of propagating the error.

    Args:
        token: An asynchronous ERC20 token object representing the token whose symbol is to be retrieved.

    Returns:
        Optional[str]: The token's symbol as a string if successfully retrieved, or None if the token does not
                       implement a standard symbol method.

    Note:
        This function is decorated with :func:`~y._decorators.stuck_coro_debugger`, which may provide additional debugging information
        in case of coroutine-related issues.
    """
    try:
        return await token.__symbol__
    except NonStandardERC20:
        return None

@stuck_coro_debugger
@cache_to_disk
async def get_transaction_index(hash: str) -> int:
    """
    Asynchronously retrieves the transaction index for a given transaction hash, with results cached to disk.

    This function fetches the transaction receipt corresponding to the provided hash and extracts the transaction index,
    which represents the position of the transaction within its containing block. The result is cached to disk to
    optimize performance in subsequent calls with the same hash.

    Args:
        hash: The hexadecimal string representation of the transaction hash.

    Returns:
        int: The zero-based index of the transaction within its block.

    Note:
        1. This function is decorated with both :func:`~y._decorators.stuck_coro_debugger` and :func:`~eth_portfolio._cache.cache_to_disk`. The former aids in
           debugging potential coroutine-related issues, while the latter implements disk-based caching for
           performance optimization.
        2. The function assumes that :func:`~eth_portfolio._loaders.utils.get_transaction_receipt` is an asynchronous function that retrieves
           the full transaction receipt, from which the index is extracted.
    """
    receipt = await get_transaction_receipt(hash)
    return receipt.transactionIndex

class _EventItem(brownie_EventItem):
    """
    A type hinting construct extending :class:`brownie.network.event._EventItem`, designed exclusively for static analysis and IDE support.

    This class augments brownie_EventItem with additional attributes specific to token transfer events, enhancing
    type checking capabilities and IDE autocompletion. It is not intended to be instantiated or used at runtime.

    Attributes:
        block_number: The block number in which the event occurred.
        log_index: The index of the log entry within the block.
        transaction_hash (Union[str, bytes]): The hash of the transaction. Note the dual type to accommodate
                                              inconsistencies in representation.

    Note:
        The dual typing of `transaction_hash` (Union[str, bytes]) is a temporary measure to handle inconsistencies
        in how it's represented. This should be resolved in future versions to standardize the type.
    """
    block_number: int
    """
    The block number in which the event occurred.
    """
    log_index: int
    """
    The index of the log entry within the block.
    """
    transaction_hash: Union[str, bytes]
    """
    transaction_hash: The hash of the transaction. Note the dual type to accommodate inconsistencies in representation.
    """


@stuck_coro_debugger
async def _decode_token_transfer(log) -> Optional[_EventItem]:
    """
    Asynchronously decodes a token transfer log into an :class:`~eth_portfolio._loaders.transactions._EventItem`, with comprehensive error handling.

    This function attempts to retrieve and verify the contract associated with the log's address. If successful,
    it proceeds to decode the log into a 'Transfer' event. The function handles various exceptions that may occur
    during this process, including :class:`brownie.exceptions.ContractNotFound` and :class:`~y.exceptions.ContractNotVerified`, logging appropriate warnings.

    Args:
        log: The raw log entry to be decoded, expected to contain at least an 'address' field.

    Returns:
        Optional[:class:`~eth_portfolio._loaders.transactions._EventItem`]: The decoded event as an _EventItem if successful, or None if the log cannot be
                              decoded due to contract issues or other decoding errors.

    Raises:
        Various exceptions may be logged but not propagated, including :class:`brownie.exceptions.ContractNotFound`, :class:`~y.exceptions.ContractNotVerified`,
        and general decoding errors.

    Note:
        1. This function is crucial for interpreting raw blockchain data and should be maintained with care.
        2. The function employs nested try-except blocks to handle different layers of potential errors,
           providing detailed logging for debugging purposes.
        3. If the contract is not found or not verified, appropriate warning messages are logged, and the
           function returns None.
    """
    try:
        await Contract.coroutine(log['address'])
    except ContractNotFound:
        logger.warning(f"Token {log['address']} cannot be found. Skipping. If the contract has been self-destructed, eth-portfolio will not support it.")
    except ContractNotVerified:
        logger.warning(f"Token {log['address']} is not verified and is most likely a shitcoin. Skipping. Please submit a PR at github.com/BobTheBuidler/eth-portfolio if this is not a shitcoin and should be included.")
        return None
    try:
        try:
            event = decode_logs(
                [log]
            )  # NOTE: We have to decode logs here because NFTs prevent us from batch decoding logs
        except Exception as e:
            raise e
        try:
            events = event['Transfer']
        except Exception as e:
            logger.error(event)
            raise e
        try:
            return events[0]
        except Exception as e:
            logger.error(event)
            raise e
    except Exception as e:
        logger.error('unable to decode logs, dev figure out why')
        logger.error(e)
        logger.error(log)
