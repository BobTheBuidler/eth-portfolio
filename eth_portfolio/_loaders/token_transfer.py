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

@stuck_coro_debugger
async def load_token_transfer(transfer_log: dict, load_prices: bool) -> Optional[TokenTransfer]:
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
    try:
        return await token.__symbol__
    except NonStandardERC20:
        return None

@stuck_coro_debugger
@cache_to_disk
async def get_transaction_index(hash: str) -> int:
    receipt = await get_transaction_receipt(hash)
    return receipt.transactionIndex

class _EventItem(brownie_EventItem):
    """A helper for mypy only. You will not run into any actual instances of this class.\n\n""" + brownie_EventItem.__doc__
    block_number: int
    log_index: int
    transaction_hash: Union[str, bytes]  # TODO figure out why it comes in both ways

@stuck_coro_debugger
async def _decode_token_transfer(log) -> Optional[_EventItem]:
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
