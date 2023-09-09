
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
    _ = Set("InternalTransfer")

class Transaction(db.Entity):
    _id = PrimaryKey(int, auto=True)
    block = Required(Block, reverse='transactions')
    transaction_index = Required(int)
    hash = Required(str, index=True)
    from_address = Optional(Address, index=True, reverse='transactions_sent')
    to_address = Optional(Address, index=True, reverse='transactions_received')
    value = Required(Decimal, 38, 18)
    price = Optional(Decimal, 38, 18)
    value_usd = Optional(Decimal, 38, 18)
    
    nonce = Required(int)
    type = Required(int)
    gas = Required(int)
    gas_price = Required(int)
    input = Required(str)
    r = Required(str)
    s = Required(str)
    v = Required(str)
    
    composite_key(block, transaction_index)
    
    raw = Required(bytes)
    

class InternalTransfer(db.Entity, kw_only=True):
    _id = PrimaryKey(int, auto=True)
    
    # common
    block = Required(Block, reverse='internal_transfers')
    transaction_index = Required(int)
    hash = Required(str)
    from_address = Optional(Address, index=True, reverse='internal_transfers_sent')
    to_address = Optional(Address, index=True, reverse='internal_transfers_received')
    value = Required(Decimal, 38, 18)
    price = Optional(Decimal, 38, 18)
    value_usd = Optional(Decimal, 38, 18)
    
    # unique
    type = Required(str)
    call_type = Required(str)
    trace_address = Required(Address, reverse='traces')
    gas = Required(int)
    gas_used = Optional(int)
    input = Required(str)
    output = Required(str)
    subtraces = Required(int)
    address = Required(Address, reverse='_')
    
    composite_key(block, transaction_index, trace_address)
    
    raw = Required(bytes)

class TokenTransfer(db.Entity, kw_only=True):
    _id = PrimaryKey(int, auto=True)
    
    # common
    block = Required(Block, reverse='token_transfers')
    transaction_index = Required(int)
    hash = Required(str)
    from_address = Optional(Address, index=True, reverse='token_transfers_sent')
    to_address = Optional(Address, index=True, reverse='token_transfers_received')
    value = Required(Decimal, 38, 18)
    price = Optional(Decimal, 38, 18)
    value_usd = Optional(Decimal, 38, 18)
    
    # unique
    log_index = Required(int)
    token = Optional(Token, reverse='transfers')
    
    composite_key(block, transaction_index, log_index)
    
    raw = Required(bytes)
    