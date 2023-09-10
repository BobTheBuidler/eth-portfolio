
from decimal import Decimal

from pony.orm import Set, Required, Optional, PrimaryKey, composite_key
from y._db.entities import Address, Block, Token, db, Token, Contract


class BlockExtended(Block):
    transactions = Set("Transaction", reverse='block')
    internal_transfers = Set("InternalTransfer", reverse='block')
    token_transfers = Set("TokenTransfer", reverse='block')

class AddressExtended(Address):
    transactions_sent = Set("Transaction", reverse='from_address')
    transactions_received = Set("Transaction", reverse='to_address')
    internal_transfers_sent = Set("InternalTransfer", reverse='from_address')
    internal_transfers_received = Set("InternalTransfer", reverse='to_address')
    token_transfers_sent = Set("TokenTransfer", reverse='from_address')
    token_transfers_received = Set("TokenTransfer", reverse='to_address')
    traces = Set("InternalTransfer", reverse='trace_address')
    _not_sure_what_this_field_is = Set("InternalTransfer", reverse='address')

class ContractExtended(Contract, AddressExtended):
    pass

class TokenExtended(Token, AddressExtended):
    transfers = Set("TokenTransfer", reverse='token')

class Transaction(db.Entity):
    _id = PrimaryKey(int, auto=True)
    block = Required(BlockExtended, lazy=True, reverse='transactions')
    transaction_index = Required(int, lazy=True)
    hash = Required(str, index=True, lazy=True)
    from_address = Optional(AddressExtended, index=True, lazy=True, reverse='transactions_sent')
    to_address = Optional(AddressExtended, index=True, lazy=True, reverse='transactions_received')
    value = Required(Decimal, 38, 18, lazy=True)
    price = Optional(Decimal, 38, 18, lazy=True)
    value_usd = Optional(Decimal, 38, 18, lazy=True)
    
    nonce = Required(int, lazy=True)
    type = Required(int, lazy=True)
    gas = Required(Decimal, 38, 1, lazy=True)
    gas_price = Required(Decimal, 38, 1, lazy=True)
    max_fee_per_gas = Optional(Decimal, 38, 1, lazy=True)
    max_priority_fee_per_gas = Optional(Decimal, 38, 1, lazy=True)
    input = Required(str, lazy=True)
    r = Required(str, lazy=True)
    s = Required(str, lazy=True)
    v = Required(int, lazy=True)
    
    composite_key(block, transaction_index)
    
    raw = Required(bytes, lazy=True)
    

class InternalTransfer(db.Entity):
    _id = PrimaryKey(int, auto=True)
    
    # common
    block = Required(BlockExtended, lazy=True, reverse='internal_transfers')
    transaction_index = Required(int, lazy=True)
    hash = Required(str, lazy=True)
    from_address = Optional(AddressExtended, index=True, lazy=True, reverse='internal_transfers_sent')
    to_address = Optional(AddressExtended, index=True, lazy=True, reverse='internal_transfers_received')
    value = Required(Decimal, 38, 18, lazy=True)
    price = Optional(Decimal, 38, 18, lazy=True)
    value_usd = Optional(Decimal, 38, 18, lazy=True)
    
    # unique
    type = Required(str, lazy=True)
    call_type = Required(str, lazy=True)
    trace_address = Required(AddressExtended, lazy=True, reverse='traces')
    gas = Required(Decimal, 38, 1, lazy=True)
    gas_used = Optional(Decimal, 38, 1, lazy=True)
    code = Optional(str, lazy=True)
    input = Optional(str, lazy=True)
    output = Optional(str, lazy=True)
    subtraces = Required(int, lazy=True)
    address = Required(AddressExtended, lazy=True, reverse='_not_sure_what_this_field_is')
    
    composite_key(block, transaction_index, trace_address)
    
    raw = Required(bytes, lazy=True)

class TokenTransfer(db.Entity):
    _id = PrimaryKey(int, auto=True)
    
    # common
    block = Required(BlockExtended, lazy=True, reverse='token_transfers')
    transaction_index = Required(int, lazy=True)
    hash = Required(str, lazy=True)
    from_address = Optional(AddressExtended, index=True, lazy=True, reverse='token_transfers_sent')
    to_address = Optional(AddressExtended, index=True, lazy=True, reverse='token_transfers_received')
    value = Required(Decimal, 38, 18, lazy=True)
    price = Optional(Decimal, 38, 18, lazy=True)
    value_usd = Optional(Decimal, 38, 18, lazy=True)
    
    # unique
    log_index = Required(int, lazy=True)
    token = Optional(TokenExtended, index=True, lazy=True, reverse='transfers')
    
    composite_key(block, transaction_index, log_index)
    
    raw = Required(bytes, lazy=True)
    