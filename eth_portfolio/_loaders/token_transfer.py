
import logging
from decimal import Decimal
from typing import Optional, Union

import a_sync
import dank_mids
from brownie import chain
from brownie.exceptions import ContractNotFound
from brownie.network.event import _EventItem as brownie_EventItem
from dank_mids.structs import Log as dankLog
from pony.orm import TransactionIntegrityError
from y import ERC20, Contract
from y._db.structs import Log as ydbLog
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

Log = Union[dankLog, ydbLog]

token_transfer_semaphore = dank_mids.BlockSemaphore(10_000, name='eth_portfolio.token_transfers')  # Some arbitrary number

@stuck_coro_debugger
async def load_token_transfer(
    transfer_log: Log, 
    load_prices: bool,
) -> Optional[TokenTransfer]:
    
    if transfer_log.removed:
        if transfer := await db.get_token_transfer(transfer_log):
            await db.delete_token_transfer(transfer)
        return
        
    if transfer := await db.get_token_transfer(transfer_log):
        if load_prices and transfer.price is None:
            await db.delete_token_transfer(transfer)
        else:
            return transfer
    
    async with token_transfer_semaphore[transfer_log.block]:
        decoded = await _decode_token_transfer(transfer_log)
        if decoded is None:
            return None
            
        sender, receiver, value = decoded.values()

        token = ERC20(decoded.address, asynchronous=True)
        
        coros = {
            'scale': token.scale, 
            'symbol': get_symbol(token), 
            'transaction_index': get_transaction_index(decoded.transaction_hash),
        }

        if load_prices:
            coros['price'] = _get_price(token.address, decoded.block_number)
        
        try:
            coro_results = await a_sync.gather(coros)
        except NonStandardERC20 as e:
            # NOTE: if we cant fetch scale or symbol or both, this is probably either a shitcoin or an NFT (which we don't support at this time)
            logger.debug(f"{e} for {transfer_log}, skipping.")
            return None
        except Exception as e:
            try:
                logger.error(f"{e.__class__.__name__} {e} for {await get_symbol(token)} {decoded.address} at block {decoded.block_number}.")
            except NonStandardERC20 as e:
                logger.error(f"{e.__class__.__name__} {e} for {decoded.address} at block {decoded.block_number}.")
            return None

    value = Decimal(value) / coro_results.pop('scale')
    
    if price := coro_results.get('price'):
        coro_results['value_usd'] = round(value * price, 18)
            
    try:
        transfer = TokenTransfer(log=transfer_log, value=value, **coro_results)
    except TypeError as e:
        # TODO: get rid of this once its run fine for a few days
        raise TypeError(str(e), token_transfer) from e

    a_sync.create_task(_insert_to_db(transfer, load_prices), skip_gc_until_done=True)
    return transfer

async def _insert_to_db(transfer: TokenTransfer, load_prices: bool) -> None:
    try:
        await db.insert_token_transfer(transfer)
    except TransactionIntegrityError:
        if load_prices:
            await db.delete_token_transfer(transfer)
            await db.insert_token_transfer(transfer)
            
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
async def _decode_token_transfer(log: Log) -> Optional[_EventItem]:
    try:
        await Contract.coroutine(log.address)
    except ContractNotFound:
        logger.warning(f"Token {log.address} cannot be found. Skipping. If the contract has been self-destructed, eth-portfolio will not support it.")
        return None
    except ContractNotVerified:
        logger.warning(f"Token {log.address} is not verified and is most likely a shitcoin. Skipping. Please submit a PR at github.com/BobTheBuidler/eth-portfolio if this is not a shitcoin and should be included.")
        return None
    
    try:
        # NOTE: We have to decode logs here because NFTs prevent us from batch decoding logs
        event = decode_logs([log])[0]
    except Exception as e:
        logger.error(e)
        logger.exception(e)
        logger.error(log)
        return None

    if "tokenId" in event:
        logger.debug("this is a NFT related transfer, skipping %s", event)
        return None
        
    if tuple(event.keys()) == ("topic1", "topic2", "topic3", "data"):
        logger.error(f'unable to decode logs for {event.address}, dev figure out why')
        return None

    _check_event(event)
    return event

_checks = [
    {'from', 'sender', '_from', 'src'},
    {'to', 'receiver', '_to', 'dst'},
    {'value', 'amount', '_value', '_amount', 'wad'},
]

def _check_event(event: _EventItem) -> None:
    if not all(key in keys for key, keys in zip(event.keys(), _checks)):
        exc = NotImplementedError(*event.keys())
        logger.error(exc)
        raise exc
