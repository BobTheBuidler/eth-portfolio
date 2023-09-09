
from decimal import Decimal

from pony.orm import Set, Required, Optional, PrimaryKey, composite_key
from y._db.entities import Address, Block, Token, db


class BlockExtended(Block):
    transactions = Set("Transaction")
    internal_transfers = Set("InternalTransfer")
    token_transfers = Set("TokenTransfer")

class TokenExtended(Token):
    transfers = Set("TokenTransfer")

class AddressExtended(Address):
    transactions_sent = Set("Transaction")
    transactions_received = Set("Transaction")
    internal_transfers_sent = Set("InternalTransfer")
    internal_transfers_received = Set("InternalTransfer")
    token_transfers_sent = Set("TokenTransfer")
    token_transfers_received = Set("TokenTransfer")
    traces = Set("InternalTransfer")
    _not_sure_what_this_field_is = Set("InternalTransfer")

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
    gas = Required(int, lazy=True)
    gas_price = Required(int, lazy=True)
    input = Required(str, lazy=True)
    r = Required(str, lazy=True)
    s = Required(str, lazy=True)
    v = Required(str, lazy=True)
    
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
    gas = Required(int, lazy=True)
    gas_used = Optional(int, lazy=True)
    input = Required(str, lazy=True)
    output = Required(str, lazy=True)
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
    