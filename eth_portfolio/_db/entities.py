import typing
from functools import cached_property

from evmspec.structs.transaction import AccessListEntry
from hexbytes import HexBytes
from msgspec import json
from pony.orm import Optional, PrimaryKey, Required, Set, composite_key
from y._db.entities import Address, Block, Contract, DbEntity, Token

from eth_portfolio import structs
from eth_portfolio._decimal import Decimal


class BlockExtended(Block):
    if typing.TYPE_CHECKING:
        # if we execute this code we get `TypeError: 'type' object is not subscriptable`
        transactions: Set["Transaction"]
        internal_transfers: Set["InternalTransfer"]
        token_transfers: Set["TokenTransfer"]

    transactions = Set("Transaction", lazy=True, reverse="block")
    internal_transfers = Set("InternalTransfer", lazy=True, reverse="block")
    token_transfers = Set("TokenTransfer", lazy=True, reverse="block")


class AddressExtended(Address):
    if typing.TYPE_CHECKING:
        # if we execute this code we get `TypeError: 'type' object is not subscriptable`
        transactions_sent: Set["Transaction"]
        transactions_received: Set["Transaction"]
        internal_transfers_sent: Set["InternalTransfer"]
        internal_transfers_received: Set["InternalTransfer"]
        token_transfers_sent: Set["TokenTransfer"]
        token_transfers_received: Set["TokenTransfer"]

    transactions_sent = Set("Transaction", lazy=True, reverse="from_address")
    transactions_received = Set("Transaction", lazy=True, reverse="to_address")
    internal_transfers_sent = Set("InternalTransfer", lazy=True, reverse="from_address")
    internal_transfers_received = Set("InternalTransfer", lazy=True, reverse="to_address")
    token_transfers_sent = Set("TokenTransfer", lazy=True, reverse="from_address")
    token_transfers_received = Set("TokenTransfer", lazy=True, reverse="to_address")


class ContractExtended(Contract, AddressExtended):
    pass


class TokenExtended(Token, AddressExtended):
    if typing.TYPE_CHECKING:
        # if we execute this code we get `TypeError: 'type' object is not subscriptable`
        transfers: Set["TokenTransfer"]

    transfers = Set("TokenTransfer", lazy=True, reverse="token")


class Transaction(DbEntity):
    _id = PrimaryKey(int, auto=True)
    block = Required(BlockExtended, lazy=True, reverse="transactions")
    transaction_index = Required(int, lazy=True)
    hash = Required(str, index=True, lazy=True)
    from_address = Required(AddressExtended, index=True, lazy=True, reverse="transactions_sent")
    to_address = Optional(AddressExtended, index=True, lazy=True, reverse="transactions_received")
    value = Required(Decimal, 38, 18, lazy=True)
    price = Optional(Decimal, 38, 18, lazy=True)
    value_usd = Optional(Decimal, 38, 18, lazy=True)

    nonce = Required(int, lazy=True)
    type = Optional(int, lazy=True)
    gas = Required(Decimal, 38, 1, lazy=True)
    gas_price = Required(Decimal, 38, 1, lazy=True)
    max_fee_per_gas = Optional(Decimal, 38, 1, lazy=True)
    max_priority_fee_per_gas = Optional(Decimal, 38, 1, lazy=True)

    composite_key(block, transaction_index)

    raw = Required(bytes, lazy=True)

    @cached_property
    def decoded(self) -> structs.Transaction:
        return json.decode(self.raw, type=structs.Transaction)

    @property
    def input(self) -> HexBytes:
        structs.Transaction.input.__doc__
        return self.decoded.input

    @property
    def r(self) -> HexBytes:
        structs.Transaction.r.__doc__
        return self.decoded.r

    @property
    def s(self) -> HexBytes:
        structs.Transaction.s.__doc__
        return self.decoded.s

    @property
    def v(self) -> int:
        structs.Transaction.v.__doc__
        return self.decoded.v

    @property
    def access_list(self) -> typing.List[AccessListEntry]:
        structs.Transaction.access_list.__doc__
        return self.decoded.access_list

    @property
    def y_parity(self) -> typing.Optional[int]:
        structs.TokenTransfer.y_parity.__doc__
        return self.decoded.y_parity


class InternalTransfer(DbEntity):
    _id = PrimaryKey(int, auto=True)

    # common
    block = Required(BlockExtended, lazy=True, reverse="internal_transfers")
    transaction_index = Required(int, lazy=True)
    hash = Required(str, lazy=True)
    from_address = Required(
        AddressExtended, index=True, lazy=True, reverse="internal_transfers_sent"
    )
    to_address = Optional(
        AddressExtended, index=True, lazy=True, reverse="internal_transfers_received"
    )
    value = Required(Decimal, 38, 18, lazy=True)
    price = Optional(Decimal, 38, 18, lazy=True)
    value_usd = Optional(Decimal, 38, 18, lazy=True)

    # unique
    type = Required(str, lazy=True)
    call_type = Required(str, lazy=True)
    trace_address = Required(str, lazy=True)
    gas = Required(Decimal, 38, 1, lazy=True)
    gas_used = Optional(Decimal, 38, 1, lazy=True)

    composite_key(
        block,
        transaction_index,
        hash,
        from_address,
        to_address,
        value,
        type,
        call_type,
        trace_address,
        gas,
        gas_used,
    )

    raw = Required(bytes, lazy=True)

    @cached_property
    def decoded(self) -> structs.InternalTransfer:
        structs.InternalTransfer.__doc__
        return json.decode(self.raw, type=structs.InternalTransfer)

    @property
    def code(self) -> HexBytes:
        structs.InternalTransfer.code.__doc__
        return self.decoded.code

    @property
    def input(self) -> HexBytes:
        structs.InternalTransfer.input.__doc__
        return self.decoded.input

    @property
    def output(self) -> HexBytes:
        structs.InternalTransfer.output.__doc__
        return self.decoded.output

    @property
    def subtraces(self) -> int:
        structs.InternalTransfer.subtraces.__doc__
        return self.decoded.subtraces


class TokenTransfer(DbEntity):
    _id = PrimaryKey(int, auto=True)

    # common
    block = Required(BlockExtended, lazy=True, reverse="token_transfers")
    transaction_index = Required(int, lazy=True)
    hash = Required(str, lazy=True)
    from_address = Required(AddressExtended, index=True, lazy=True, reverse="token_transfers_sent")
    to_address = Required(
        AddressExtended, index=True, lazy=True, reverse="token_transfers_received"
    )
    value = Required(Decimal, 38, 18, lazy=True)
    price = Optional(Decimal, 38, 18, lazy=True)
    value_usd = Optional(Decimal, 38, 18, lazy=True)

    # unique
    log_index = Required(int, lazy=True)
    token = Optional(TokenExtended, index=True, lazy=True, reverse="transfers")

    composite_key(block, transaction_index, log_index)

    raw = Required(bytes, lazy=True)

    @cached_property
    def decoded(self) -> structs.TokenTransfer:
        return json.decode(self.raw, type=structs.TokenTransfer)
