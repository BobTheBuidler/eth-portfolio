import logging
from decimal import Decimal
from typing import Any, ClassVar, Iterator, List, Literal, Optional, Union

from msgspec import Struct
from y import Network
from y.datatypes import Block

logger = logging.getLogger(__name__)

class _DictStruct(Struct):
    def keys(self) -> Iterator[str]:
        return iter(self.__struct_fields__)
    def __getitem__(self, item: str) -> Any:
        return getattr(self, item)
    
class _LedgerEntryBase(_DictStruct, kw_only=True, frozen=True):
    chainid: Network
    block_number: Block
    transaction_index: Optional[int] = None
    hash: str
    from_address: str
    value: Decimal
    to_address: Optional[str] = None
    price: Optional[Decimal] = None
    value_usd: Optional[Decimal] = None
    

class _AccessListEntry(Struct, frozen=True):
    address: str
    storage_keys: List[bytes]
    
class Transaction(_LedgerEntryBase, kw_only=True, frozen=True):
    entry_type: ClassVar[Literal['transaction']] = 'transaction'
    block_hash: str
    nonce: int
    type: int
    gas: int
    gas_price: int
    max_fee_per_gas: Optional[int] = None
    max_priority_fee_per_gas: Optional[int] = None
    input: str
    r: str
    s: str
    v: int
    access_list: Optional[List[_AccessListEntry]] = None


class InternalTransfer(_LedgerEntryBase, kw_only=True, frozen=True):
    entry_type: ClassVar[Literal['internal_transfer']] = 'internal_transfer'
    block_hash: str
    type: str
    trace_address: str
    gas: int
    gas_used: Optional[int]
    subtraces: int
    call_type: Optional[str] = None
    input: Optional[str] = None
    output: Optional[str] = None
    init: Optional[str] = None
    address: Optional[str] = None
    code: Optional[str] = None


class TokenTransfer(_LedgerEntryBase, kw_only=True, frozen=True):
    entry_type: ClassVar[Literal['token_transfer']] = 'token_transfer'
    log_index: int
    token: Optional[str]
    token_address: str
    value: Decimal


LedgerEntry = Union[Transaction, InternalTransfer, TokenTransfer]
