"""
This module handles the loading and processing of token transfers and associated data within the eth_portfolio project.

Functions in this module decode token transfer logs, retrieve necessary transaction details, and store processed data in a local database. It uses semaphores to manage concurrency and includes caching mechanisms for improved performance.

Additionally, it includes utility functions for fetching token symbols and transaction indexes.

Classes:
    :class:`~eth_portfolio._loaders.transactions._EventItem`: A helper class for type hinting, extending brownie.EventItem, but not used directly at runtime.
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

token_transfer_semaphore = dank_mids.BlockSemaphore(10_000, name='eth_portfolio.token_transfers')  # Some arbitrary number
"""A semaphore that limits the number of concurrent token transfers being processed per block."""


@stuck_coro_debugger
async def load_token_transfer(transfer_log: dict, load_prices: bool) -> Optional[TokenTransfer]:
    """
    Processes and loads a token transfer from a log entry.

    This function first checks if the transfer is for a known 'shitcoin' and skips it if so.
    It then checks if the transfer has already been processed and stored in the database. If the transfer exists and 
    `load_prices` is set to True but the price data is missing, the function deletes the existing entry and processes the transfer again. 
    If the transfer hasn't been processed, the function decodes the log, retrieves necessary data (e.g., token scale, symbol, transaction index), 
    and optionally fetches the token price at the time of the transaction. The processed transfer is then stored in the database.

    A semaphore is used to limit the number of concurrent token transfer processes within the same block.

    Args:
        transfer_log: The log entry of the token transfer.
        load_prices: Whether to load the token price at the time of the transaction.

    Returns:
        Optional[TokenTransfer]: The processed TokenTransfer object, or None if the transfer cannot be processed.

    Raises:
        TypeError: If there's an issue creating the TokenTransfer object.

    Example:
        >>> transfer = await load_token_transfer(transfer_log={"address": "0x1234567890abcdef1234567890abcdef12345678", "blockNumber": 12345678}, load_prices=True)
        >>> print(transfer)
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
    Retrieves the symbol of the given ERC20 token.

    The function attempts to access the token's symbol. If the token contract does not follow the standard ERC20 interface, indicated by raising a `NonStandardERC20` exception, the function returns `None`.

    Args:
        token: The ERC20 token object.

    Returns:
        Optional[str]: The token symbol, or None if it cannot be retrieved.

    Example:
        >>> symbol = await get_symbol(token=ERC20("0x1234567890abcdef1234567890abcdef12345678", asynchronous=True))
        >>> print(symbol)
    """
    try:
        return await token.__symbol__
    except NonStandardERC20:
        return None

@stuck_coro_debugger
@cache_to_disk
async def get_transaction_index(hash: str) -> int:
    """
    Retrieves the transaction index for a given transaction hash.

    This function fetches the transaction receipt using the provided hash and extracts the transaction index, which indicates the position of the transaction within its block. The result is cached to disk for improved performance.

    Args:
        hash: The transaction hash.

    Returns:
        int: The index of the transaction within its block.

    Example:
        >>> index = await get_transaction_index(hash="0xabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef")
        >>> print(index)
    """
    receipt = await get_transaction_receipt(hash)
    return receipt.transactionIndex

class _EventItem(brownie_EventItem):
    """
    A helper class for type hinting and MyPy only. You will not encounter instances of this class during runtime.

    This class extends brownie_EventItem to provide type hints for additional attributes specific to token transfer events.
    It's used to improve static type checking and IDE support, but does not affect runtime behavior.

    Note:
        The transaction_hash type is a Union[str, bytes] due to inconsistencies in how it's represented. This should be resolved in future versions.
    """
    block_number: int
    """
    block_number: The block number of the event.
    """
    log_index: int
    """
    log_index: The index of the log entry within the block.
    """
    transaction_hash: Union[str, bytes]  # TODO figure out why it comes in both ways
    """
    transaction_hash: The hash of the transaction, which may be a string or bytes.
    """


@stuck_coro_debugger
async def _decode_token_transfer(log) -> Optional[_EventItem]:
    """
    Decodes a token transfer log into :class:`~eth_portfolio._loaders.transactions._EventItem`.

    This function attempts to retrieve the contract for the given log's address. If the contract is found and verified, it decodes the log into a `Transfer` event. This function handles exceptions for ContractNotFound and ContractNotVerified, logging warnings in these cases. 
    It also handles various decoding errors, logging them for debugging purposes.

    Args:
        log: The log entry to be decoded.

    Returns:
        Optional[_EventItem]: The decoded event as an _EventItem, or None if the log cannot be decoded due to contract issues or decoding errors.

    Example:
        >>> decoded_event = await _decode_token_transfer(log={"address": "0x1234567890abcdef1234567890abcdef12345678", "topics": [...], "data": "..."})
        >>> print(decoded_event)
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
