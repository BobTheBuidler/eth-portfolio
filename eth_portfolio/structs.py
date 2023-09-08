from decimal import Decimal
from typing import Optional

from msgspec import Struct
from y import Network
from y.datatypes import Address, Block


class _LedgerEntryBase(Struct, kw_only=True):
    chainid: Network
    block_number: Block
    transaction_index: int
    hash: str
    from_address: Optional[Address]
    to_address: Optional[Address]
    value: Decimal
    price: Optional[Decimal] = None
    value_usd: Optional[Decimal] = None

class Transaction(_LedgerEntryBase, kw_only=True):
    block_hash: str
    nonce: int
    type: int
    gas: int
    gas_price: int
    input: str
    r: str
    s: str
    v: str

class InternalTransfer(_LedgerEntryBase, kw_only=True):
    block_hash: str
    type: str
    call_type: str
    trace_address: Address
    gas: int
    gas_used: Optional[int]
    input: str
    output: str
    subtraces: int
    address: Address = None

class TokenTransfer(_LedgerEntryBase, kw_only=True):
    log_index: int
    token: Optional[str]
    token_address: Address
    value: Decimal
