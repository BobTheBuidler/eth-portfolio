import logging
from contextlib import suppress
from typing import Optional

from a_sync import a_sync
from msgspec import json
from pony.orm import (BindingError, OperationalError,
                      TransactionIntegrityError, commit, db_session)
from y._db.config import connection_settings

from eth_portfolio._db import entities
from eth_portfolio._db.entities import db
from eth_portfolio.structs import TokenTransfer, Transaction

logger = logging.getLogger(__name__)

try:
    db.bind(**connection_settings, create_db=True)
except BindingError as e:
    if not str(e).startswith('Database object was already bound to'):
        raise e

try:
    db.generate_mapping(create_tables=True)
except OperationalError as e:
    if not str(e).startswith("no such column:"):
        raise e
    raise OperationalError("Since eth-portfolio extends the ypricemagic database with additional column definitions, you will need to delete your ypricemagic database at ~/.ypricemagic and rerun this script")

# The db must be bound before we do this since we're adding some new columns to the tables defined in ypricemagic
from y._db.utils import *


@a_sync(default='async')
@db_session
def get_block(block: int) -> entities.Block:
    chain = get_chain(sync=True)
    if b := entities.BlockExtended.get(chain=chain, number=block):
        return b
    with suppress(TransactionIntegrityError):
        entities.BlockExtended(chain=chain, number=block)
        commit()
        logger.debug('block %s added to ydb', block)
    return entities.BlockExtended.get(chain=get_chain(sync=True), number=block)


@a_sync(default='async')
@db_session
def get_address(address: str) -> entities.Block:
    chain = get_chain(sync=True)
    if a := entities.AddressExtended.get(chain=chain, address=address):
        return a
    with suppress(TransactionIntegrityError):
        entities.AddressExtended(chain=chain, address=address)
        commit()
        logger.debug('address %s added to ydb', address)
    return entities.AddressExtended.get(chain=get_chain(sync=True), address=address)


@a_sync(default='async')
@db_session
def get_token(address: str) -> entities.Block:
    chain = get_chain(sync=True)
    if a := entities.TokenExtended.get(chain=chain, address=address):
        return a
    with suppress(TransactionIntegrityError):
        entities.TokenExtended(chain=chain, address=address)
        commit()
        logger.debug('address %s added to ydb', address)
    return entities.TokenExtended.get(chain=get_chain(sync=True), address=address)
        
    
@a_sync(default='async')
@db_session
def get_transaction(sender: str, nonce: int) -> Optional[Transaction]:
    entity: entities.Transaction
    if entity := entities.Transaction.get(
        from_address = get_address(sender, sync=True),
        nonce = nonce
    ):
        return json.decode(entity.raw, type=Transaction)
    
    
@a_sync(default='async')
@db_session
def delete_transaction(transaction: Transaction) -> None:
    entity = entities.Transaction.get(
        from_address = get_address(transaction.from_address, sync=True),
        nonce = transaction.nonce,
    )
    del entity
    
    
@a_sync(default='async')
@db_session
def insert_transaction(transaction: Transaction) -> None:
    entities.Transaction(
        block = get_block(transaction.block_number, sync=True),
        transaction_index = transaction.transaction_index,
        hash = transaction.hash,
        nonce = transaction.nonce,
        from_address = get_address(transaction.from_address, sync=True),
        to_address = get_address(transaction.to_address, sync=True),
        value = transaction.value,
        price = transaction.price,
        value_usd = transaction.value_usd,
        type = transaction.type,
        gas = transaction.gas,
        gas_price = transaction.gas_price,
        input = transaction.input,
        r = transaction.r,
        s = transaction.s,
        v = transaction.v,
        raw = json.encode(transaction),    
    )
    
    
@a_sync(default='async')
@db_session
def get_token_transfer(transfer_log) -> Optional[TokenTransfer]:
    entity: entities.TokenTransfer
    if entity := entities.TokenTransfer.get(
        block = get_block(transfer_log["blockNumber"], sync=True), 
        transaction_index = transfer_log["transactionIndex"],
        log_index = transfer_log["logIndex"],
    ):
        return json.decode(entity.raw, type=TokenTransfer)
   
    
@a_sync(default='async')
@db_session
def delete_token_transfer(token_transfer: TokenTransfer) -> None:
    entity = entities.TokenTransfer.get(
        block = get_block(token_transfer.block_number, sync=True), 
        transaction_index = token_transfer.transaction_index,
        log_index = token_transfer.log_index,
    )
    del entity


@a_sync(default='async')
@db_session
def insert_token_transfer(token_transfer: TokenTransfer) -> None:
    entities.TokenTransfer(
        block = get_block(token_transfer.block_number), 
        transaction_index = token_transfer.transaction_index,
        log_index = token_transfer.log_index,
        hash = token_transfer.hash,
        token = get_token_extended(token_transfer.token_address, sync=True),
        from_address = get_address(token_transfer.from_address, sync=True),
        to_address = get_address(token_transfer.to_address, sync=True),
        value = token_transfer.value,
        price = token_transfer.price,
        value_usd = token_transfer.value_usd,
        raw = json.encode(token_transfer),
    )

