
from decimal import Decimal

from pony.orm import Json, Optional, PrimaryKey, Required, Set, composite_key
from y._db.entities import Address, Block, Contract, Token, db


class BlockExtended(Block):
    transactions = Set("Transaction", lazy=True, reverse='block')
    internal_transfers = Set("InternalTransfer", lazy=True, reverse='block')
    token_transfers = Set("TokenTransfer", lazy=True, reverse='block')

class AddressExtended(Address):
    transactions_sent = Set("Transaction", lazy=True, reverse='from_address')
    transactions_received = Set("Transaction", lazy=True, reverse='to_address')
    internal_transfers_sent = Set("InternalTransfer", lazy=True, reverse='from_address')
    internal_transfers_received = Set("InternalTransfer", lazy=True, reverse='to_address')
    token_transfers_sent = Set("TokenTransfer", lazy=True, reverse='from_address')
    token_transfers_received = Set("TokenTransfer", lazy=True, reverse='to_address')
    traces = Set("InternalTransfer", lazy=True, reverse='trace_address')
    _not_sure_what_this_field_is = Set("InternalTransfer", lazy=True, reverse='address')

class ContractExtended(Contract, AddressExtended):
    pass

class TokenExtended(Token, AddressExtended):
    transfers = Set("TokenTransfer", lazy=True, reverse='token')

class Transaction(db.Entity):
    _id = PrimaryKey(int, auto=True)
    block = Required(BlockExtended, lazy=True, reverse='transactions')
    transaction_index = Required(int, lazy=True)
    hash = Required(str, index=True, lazy=True)
    from_address = Required(AddressExtended, index=True, lazy=True, reverse='transactions_sent')
    to_address = Optional(AddressExtended, index=True, lazy=True, reverse='transactions_received')
    value = Required(Decimal, 38, 18, lazy=True)
    price = Optional(Decimal, 38, 18, lazy=True)
    value_usd = Optional(Decimal, 38, 18, lazy=True)
    access_list = Optional(bytes, lazy=True)
    
    nonce = Required(int, lazy=True)
    type = Optional(int, lazy=True)
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
    from_address = Required(AddressExtended, index=True, lazy=True, reverse='internal_transfers_sent')
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
    
    composite_key(block, transaction_index, hash, from_address, to_address, value, type, call_type, trace_address, gas, gas_used, code, input, output, subtraces, address)
    
    raw = Required(bytes, lazy=True)

class TokenTransfer(db.Entity):
    _id = PrimaryKey(int, auto=True)
    
    # common
    block = Required(BlockExtended, lazy=True, reverse='token_transfers')
    transaction_index = Required(int, lazy=True)
    hash = Required(str, lazy=True)
    from_address = Required(AddressExtended, index=True, lazy=True, reverse='token_transfers_sent')
    to_address = Required(AddressExtended, index=True, lazy=True, reverse='token_transfers_received')
    value = Required(Decimal, 38, 18, lazy=True)
    price = Optional(Decimal, 38, 18, lazy=True)
    value_usd = Optional(Decimal, 38, 18, lazy=True)
    
    # unique
    log_index = Required(int, lazy=True)
    token = Optional(TokenExtended, index=True, lazy=True, reverse='transfers')
    
    composite_key(block, transaction_index, log_index)
    
    raw = Required(bytes, lazy=True)
    