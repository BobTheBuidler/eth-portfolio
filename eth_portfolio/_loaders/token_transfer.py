"""
This module orchestrates the process of loading and processing token transfers within the eth_portfolio ecosystem.
"""

import decimal
import logging
from typing import Optional

import a_sync
import dank_mids
import msgspec
from evmspec._ids import TransactionIndex
from pony.orm import TransactionIntegrityError, UnexpectedError
from y import ERC20
from y._db.log import Log
from y._decorators import stuck_coro_debugger
from y.exceptions import NonStandardERC20, reraise_excs_with_extra_context

from eth_portfolio._cache import cache_to_disk
from eth_portfolio._db import utils as db
from eth_portfolio._decimal import Decimal
from eth_portfolio._loaders.utils import get_transaction_receipt
from eth_portfolio._utils import _get_price
from eth_portfolio.structs import TokenTransfer


logger = logging.getLogger(__name__)

token_transfer_semaphore = dank_mids.BlockSemaphore(
    10_000, name="eth_portfolio.token_transfers"
)  # Some arbitrary number
"""A semaphore that regulates the concurrent processing of token transfers by processing lower blocks first."""


@stuck_coro_debugger
async def load_token_transfer(
    transfer_log: "Log", load_prices: bool
) -> Optional[TokenTransfer]:  # sourcery skip: simplify-boolean-comparison
    """
    Processes and loads a token transfer from a log entry, with comprehensive error handling and optional price fetching.

    This function employs a multi-step process:
    1. Validates the transfer against a known set of 'shitcoins', skipping processing if matched.
    2. Checks for existing database entries, potentially deleting and reprocessing if price data is requested but missing.
    3. Decodes the transfer log and retrieves associated metadata (e.g., token scale, symbol, transaction index).
    4. Optionally fetches the token price at the time of the transaction.
    5. Constructs and persists a :class:`~eth_portfolio.structs.TokenTransfer` object in the database.

    The function handles various exceptions, including :class:`~y.exceptions.NonStandardERC20` for non-compliant tokens and :class:`decimal.InvalidOperation` for extreme :class:`~Decimal` values.

    Args:
        transfer_log: A dictionary containing the raw log entry of the token transfer.
        load_prices: A flag indicating whether to fetch and include price data for the token at the time of transfer.

    Returns:
        A processed TokenTransfer object if successful, or None if the transfer cannot be processed due to various constraints or errors.

    Note:
        This function employs caching mechanisms and database operations to optimize performance.
    """
    if transfer_log.removed:
        if transfer := await db.get_token_transfer(transfer_log):
            await db.delete_token_transfer(transfer)
        return None

    if transfer := await db.get_token_transfer(transfer_log):
        if load_prices is False or transfer.price:
            return transfer
        await db.delete_token_transfer(transfer)

    async with token_transfer_semaphore[transfer_log.block]:
        token = ERC20(transfer_log.address, asynchronous=True)

        coros = {
            "scale": token.scale,
            "token": get_symbol(token),
            "transaction_index": get_transaction_index(transfer_log.transactionHash.hex()),
        }

        if load_prices:
            coros["price"] = _get_price(token.address, transfer_log.blockNumber)

        try:
            coro_results = await a_sync.gather(coros)
        except NonStandardERC20 as e:
            # NOTE: if we cant fetch scale or symbol or both, this is probably either a shitcoin or an NFT (which we don't support at this time)
            logger.debug("%s for %s, skipping.", e, transfer_log)
            return None
        except Exception as e:
            try:
                logger.error(
                    f"{e.__class__.__name__} {e} for {await get_symbol(token)} {transfer_log.address} at block {transfer_log.blockNumber}:"
                )
                logger.exception(e)
            except NonStandardERC20 as e:
                logger.error(
                    f"{e.__class__.__name__} {e} for {transfer_log.address} at block {transfer_log.blockNumber}."
                )
            return None

        value = Decimal(transfer_log.data.as_uint256) / coro_results.pop("scale")

        if price := coro_results.get("price"):
            coro_results["value_usd"] = round(value * price, 18)

        transfer = TokenTransfer(log=transfer_log, value=value, **coro_results)

        a_sync.create_task(
            _insert_to_db(transfer, load_prices),
            skip_gc_until_done=True,
        )

        return transfer


async def _insert_to_db(transfer: TokenTransfer, load_prices: bool) -> None:
    with reraise_excs_with_extra_context(transfer):
        try:
            await db.insert_token_transfer(transfer)
        except TransactionIntegrityError:
            if load_prices:
                await db.delete_token_transfer(transfer)
                await db.insert_token_transfer(transfer)
        except UnexpectedError:
            digits_before_decimal = str(transfer.value).split(".")[0]
            if len(digits_before_decimal) <= 20:
                raise
        except decimal.InvalidOperation:
            # TODO: debug why this happens sometimes
            pass


@stuck_coro_debugger
async def get_symbol(token: ERC20) -> Optional[str]:
    """
    Retrieves the symbol of a given ERC20 token, with error handling for non-standard implementations.

    This function attempts to access the token's symbol through the standard ERC20 symbol method. If the token contract
    does not adhere to the standard ERC20 interface, indicated by a :class:`~y.exceptions.NonStandardERC20` exception, the function
    returns `None` instead of propagating the error.

    Args:
        token: An ERC20 token object representing the token whose symbol is to be retrieved.

    Returns:
        The token's symbol as a string if successfully retrieved, or None if the token does not implement a standard symbol method.
    """
    try:
        return await token.__symbol__
    except NonStandardERC20:
        return None


@stuck_coro_debugger
@cache_to_disk
async def get_transaction_index(hash: str) -> int:
    """
    Retrieves the transaction index for a given transaction hash, with results cached to disk.

    This function fetches the transaction receipt corresponding to the provided hash and extracts the transaction index,
    which represents the position of the transaction within its containing block. The result is cached to disk to
    optimize performance for future runs.

    Args:
        hash: The hexadecimal string representation of the transaction hash.

    Returns:
        The zero-based index of the transaction within its block.
    """
    receipt_bytes = await get_transaction_receipt(hash)
    return msgspec.json.decode(
        receipt_bytes, type=HasTxIndex, dec_hook=TransactionIndex._decode_hook
    ).transactionIndex


class HasTxIndex(msgspec.Struct):
    transactionIndex: TransactionIndex
