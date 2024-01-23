
import asyncio
import logging
from decimal import Decimal
from typing import List, Optional, Tuple

import eth_retry
import inflection
from async_lru import alru_cache
from brownie import chain
from pony.orm import TransactionIntegrityError
from web3.types import TxData
from y import get_price
from y.constants import EEE_ADDRESS
from y.datatypes import Address, Block
from y.decorators import stuck_coro_debugger
from y.utils.dank_mids import dank_w3

from eth_portfolio._db import utils as db
from eth_portfolio._loaders.utils import get_transaction_receipt
from eth_portfolio.structs import Transaction

logger = logging.getLogger(__name__)

Nonce = int

@eth_retry.auto_retry
@stuck_coro_debugger
async def load_transaction(address: Address, nonce: Nonce, load_prices: bool) -> Tuple[Nonce, Optional[Transaction]]:
    if transaction := await db.get_transaction(address, nonce):
        if load_prices and transaction.price is None:
            await db.delete_transaction(transaction)
        else:
            return nonce, transaction
    lo = 0
    hi = await dank_w3.eth.block_number
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
                tx['value'] = Decimal(tx['value']) / Decimal(1e18)
                tx['type'] = int(tx['type'], 16) if "type" in tx else None
                tx['r'] = tx['r'].hex()
                tx['s'] = tx['s'].hex()
                if load_prices:
                    tx['price'] = round(Decimal(await get_price(EEE_ADDRESS, block = tx['blockNumber'], sync=False)), 18)
                    tx['value_usd'] = tx['value'] * tx['price']
                try:
                    transaction = Transaction(**{inflection.underscore(k): v for k, v in tx.items()})
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
async def get_transaction_by_nonce_and_block(address: Address, nonce: int, block: Block) -> Optional[TxData]:
    txs = await get_block_transactions(block)
    for tx in txs:
        if tx['from'] == address and tx['nonce'] == nonce:
            return tx
        # Special handler for contract creation transactions
        elif tx['to'] == None and (await get_transaction_receipt(tx['hash']))['contractAddress'] == address:
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
    try:
        return await dank_w3.eth.get_transaction_count(address, block_identifier = block) - 1
    except ValueError as e:
        # NOTE this is known to occur on arbitrum
        if 'error creating execution cursor' in str(e) and block == 0:
            return -1
        raise ValueError(f"For {address} at {block}: {e}")

@eth_retry.auto_retry
@stuck_coro_debugger
async def get_block_transactions(block: Block) -> List[TxData]:
    async with _full_block_semaphore:
        block = await dank_w3.eth.get_block(block, full_transactions=True)
        return block.transactions

_full_block_semaphore = asyncio.Semaphore(100)