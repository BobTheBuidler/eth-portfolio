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


@stuck_coro_debugger
async def load_token_transfer(
    transfer_log: "Log", load_prices: bool
) -> Optional[TokenTransfer]:  # sourcery skip: simplify-boolean-comparison
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
    try:
        return await token.__symbol__
    except NonStandardERC20:
        return None


@stuck_coro_debugger
@cache_to_disk
async def get_transaction_index(hash: str) -> int:
    receipt_bytes = await get_transaction_receipt(hash)
    return msgspec.json.decode(
        receipt_bytes, type=HasTxIndex, dec_hook=TransactionIndex._decode_hook
    ).transactionIndex


class HasTxIndex(msgspec.Struct):
    transactionIndex: TransactionIndex
