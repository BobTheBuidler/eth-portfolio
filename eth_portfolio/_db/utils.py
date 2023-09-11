import logging
from contextlib import suppress
from typing import Optional

import y._db.config as config
from a_sync import a_sync
from msgspec import json
from pony.orm import (BindingError, OperationalError,
                      TransactionIntegrityError, commit, db_session)

from eth_portfolio._db import entities
from eth_portfolio._db.decorators import break_locks, requery_objs_on_diff_tx_err
from eth_portfolio._db.entities import db
from eth_portfolio.structs import InternalTransfer, TokenTransfer, Transaction

logger = logging.getLogger(__name__)

try:
    db.bind(**config.connection_settings, create_db=True)
except BindingError as e:
    if not str(e).startswith('Database object was already bound to'):
        raise e

try:
    db.generate_mapping(create_tables=True)
except OperationalError as e:
    if not str(e).startswith("no such column:"):
        raise e
    raise OperationalError("Since eth-portfolio extends the ypricemagic database with additional column definitions, you will need to delete your ypricemagic database at ~/.ypricemagic and rerun this script")

from y._db.entities import Address, Contract, Token
# The db must be bound before we do this since we're adding some new columns to the tables defined in ypricemagic
from y._db.utils import get_chain
from y.contracts import is_contract

robust_db_session = lambda callable: break_locks(db_session(callable))

@a_sync(default='async')
@robust_db_session
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
@robust_db_session
def get_address(address: str) -> entities.Block:
    chain = get_chain(sync=True)
    
    entity = entities.Address.get(chain=chain, address=address)
    if isinstance(entity, Token):
        entity_type = entities.TokenExtended
    elif isinstance(entity, Contract):
        entity_type = entities.ContractExtended
    elif isinstance(entity, Address):
        entity_type = entities.AddressExtended
    elif entity is None:
        # TODO: this should live in ypm
        if is_contract(address):
            entity_type = entities.ContractExtended
        else:
            entity_type = entities.AddressExtended
    else:
        raise NotImplementedError(entity, entity_type)
            
    if isinstance(entity, entity_type):
        return entity
    elif entity:
        entity.delete()
        commit()
            
    with suppress(TransactionIntegrityError):
        entity_type(chain=get_chain(sync=True), address=address)
        commit()
        logger.debug('%s %s added to ydb', entity_type.__name__, address)
    return entity_type.get(chain=get_chain(sync=True), address=address)


@a_sync(default='async')
@robust_db_session
def get_token(address: str) -> entities.Block:
    chain = get_chain(sync=True)
    if t := entities.TokenExtended.get(chain=chain, address=address):
        return t
    elif t := Address.get(chain=chain, address=address):
        t.delete()
        commit()
    with suppress(TransactionIntegrityError):
        entities.TokenExtended(chain=get_chain(sync=True), address=address)
        commit()
        logger.debug('token %s added to ydb', address)
    return entities.TokenExtended.get(chain=get_chain(sync=True), address=address)
        
    
@a_sync(default='async')
@robust_db_session
def get_transaction(sender: str, nonce: int) -> Optional[Transaction]:
    entity: entities.Transaction
    if entity := entities.Transaction.get(
        from_address = get_address(sender, sync=True),
        nonce = nonce
    ):
        return json.decode(entity.raw, type=Transaction)
    
    
@a_sync(default='async')
@robust_db_session
def delete_transaction(transaction: Transaction) -> None:
    if entity := entities.Transaction.get(
        from_address = get_address(transaction.from_address, sync=True),
        nonce = transaction.nonce,
    ):
        entity.delete()
    
    
@a_sync(default='async')
@requery_objs_on_diff_tx_err
@robust_db_session
def insert_transaction(transaction: Transaction) -> None:
    # Make sure these are in the db so below we can call them and use the results all in one transaction
    block = get_block(transaction.block_number, sync=True)
    from_address = get_address(transaction.from_address, sync=True)
    to_address = get_address(transaction.to_address, sync=True) if transaction.to_address else None
    
    # Now requery and use the values
    entities.Transaction(
        block = get_block(transaction.block_number, sync=True),
        transaction_index = transaction.transaction_index,
        hash = transaction.hash,
        nonce = transaction.nonce,
        from_address = get_address(transaction.from_address, sync=True),
        to_address = get_address(transaction.to_address, sync=True) if transaction.to_address else None,
        value = transaction.value,
        price = transaction.price,
        value_usd = transaction.value_usd,
        type = transaction.type,
        gas = transaction.gas,
        gas_price = transaction.gas_price,
        max_fee_per_gas = transaction.max_fee_per_gas, 
        max_priority_fee_per_gas = transaction.max_priority_fee_per_gas,
        input = transaction.input,
        r = transaction.r,
        s = transaction.s,
        v = transaction.v,
        access_list = json.encode(transaction.access_list) if transaction.access_list else None,
        raw = json.encode(transaction),    
    )
    
    
@a_sync(default='async')
@robust_db_session
def get_internal_transfer(transfer_log) -> Optional[InternalTransfer]:
    ...
    
@a_sync(default='async')
@robust_db_session
def delete_internal_transfer(transfer: InternalTransfer) -> None:
    if entity := entities.InternalTransfer.get(...):
        entity.delete()
    
@a_sync(default='async')
@requery_objs_on_diff_tx_err
@robust_db_session
def insert_internal_transfer(transfer: InternalTransfer) -> None:
    entities.InternalTransfer(
        block = get_block(transfer.block_number, sync=True),
        transaction_index = transfer.transaction_index,
        hash = transfer.hash,
        type = transfer.type,
        call_type = transfer.call_type,
        from_address = get_address(transfer.from_address, sync=True),
        to_address = get_address(transfer.to_address, sync=True),
        value = transfer.value,
        price = transfer.price,
        value_usd = transfer.value_usd,
        trace_address = get_address(transfer.trace_address, sync=True),
        gas = transfer.gas,
        gas_used = transfer.gas_used,
        input = transfer.input,
        output = transfer.output,
        subtraces = transfer.subtraces,
        address = get_address(transfer.address, sync=True),
        raw = json.encode(transfer),
    )
    
@a_sync(default='async')
@robust_db_session
def get_token_transfer(transfer_log) -> Optional[TokenTransfer]:
    entity: entities.TokenTransfer
    if entity := entities.TokenTransfer.get(
        block = get_block(transfer_log["blockNumber"], sync=True), 
        transaction_index = transfer_log["transactionIndex"],
        log_index = transfer_log["logIndex"],
    ):
        return json.decode(entity.raw, type=TokenTransfer)
   
    
@a_sync(default='async')
@robust_db_session
def delete_token_transfer(token_transfer: TokenTransfer) -> None:
    if entity := entities.TokenTransfer.get(
        block = get_block(token_transfer.block_number, sync=True), 
        transaction_index = token_transfer.transaction_index,
        log_index = token_transfer.log_index,
    ):
        entity.delete()


@a_sync(default='async')
@requery_objs_on_diff_tx_err
@robust_db_session
def insert_token_transfer(token_transfer: TokenTransfer) -> None:
    # Make sure these are in the db so below we can call them and use the results all in one transaction
    block = get_block(token_transfer.block_number, sync=True)
    token = get_token(token_transfer.token_address, sync=True)
    from_address = get_address(token_transfer.from_address, sync=True)
    to_address = get_address(token_transfer.to_address, sync=True)
    commit()
    
    # Now requery and use the values
    entities.TokenTransfer(
        block = get_block(token_transfer.block_number, sync=True), 
        transaction_index = token_transfer.transaction_index,
        log_index = token_transfer.log_index,
        hash = token_transfer.hash,
        token = get_token(token_transfer.token_address, sync=True),
        from_address = get_address(token_transfer.from_address, sync=True),
        to_address = get_address(token_transfer.to_address, sync=True),
        value = token_transfer.value,
        price = token_transfer.price,
        value_usd = token_transfer.value_usd,
        raw = json.encode(token_transfer),
    )

            