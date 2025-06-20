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
    """
    Extends the base Block entity to add relationships to transactions, internal transfers, and token transfers.
    """

    if typing.TYPE_CHECKING:
        # if we execute this code we get `TypeError: 'type' object is not subscriptable`
        transactions: Set["Transaction"]
        internal_transfers: Set["InternalTransfer"]
        token_transfers: Set["TokenTransfer"]

    transactions = Set("Transaction", lazy=True, reverse="block")
    """All transactions included in this block."""

    internal_transfers = Set("InternalTransfer", lazy=True, reverse="block")
    """All internal transfers in this block."""

    token_transfers = Set("TokenTransfer", lazy=True, reverse="block")
    """All token transfers in this block."""


class AddressExtended(Address):
    """
    Extends the base Address entity to add relationships for sent/received transactions, internal transfers, and token transfers.
    """

    if typing.TYPE_CHECKING:
        # if we execute this code we get `TypeError: 'type' object is not subscriptable`
        transactions_sent: Set["Transaction"]
        transactions_received: Set["Transaction"]
        internal_transfers_sent: Set["InternalTransfer"]
        internal_transfers_received: Set["InternalTransfer"]
        token_transfers_sent: Set["TokenTransfer"]
        token_transfers_received: Set["TokenTransfer"]

    transactions_sent = Set("Transaction", lazy=True, reverse="from_address")
    """Transactions sent from this address."""

    transactions_received = Set("Transaction", lazy=True, reverse="to_address")
    """Transactions received by this address."""

    internal_transfers_sent = Set("InternalTransfer", lazy=True, reverse="from_address")
    """Internal transfers sent from this address."""

    internal_transfers_received = Set("InternalTransfer", lazy=True, reverse="to_address")
    """Internal transfers received by this address."""

    token_transfers_sent = Set("TokenTransfer", lazy=True, reverse="from_address")
    """Token transfers sent from this address."""

    token_transfers_received = Set("TokenTransfer", lazy=True, reverse="to_address")
    """Token transfers received by this address."""


class ContractExtended(Contract, AddressExtended):
    """
    Extends both Contract and AddressExtended to represent a contract with address relationships.
    """


class TokenExtended(Token, AddressExtended):
    """
    Extends both Token and AddressExtended to represent a token contract with address relationships.
    """

    if typing.TYPE_CHECKING:
        # if we execute this code we get `TypeError: 'type' object is not subscriptable`
        transfers: Set["TokenTransfer"]

    transfers = Set("TokenTransfer", lazy=True, reverse="token")
    """All token transfers involving this token."""


class Transaction(DbEntity):
    """
    Represents an Ethereum transaction, including all on-chain and decoded fields.
    """

    _id = PrimaryKey(int, auto=True)
    """Auto-incrementing primary key for the transaction."""

    block = Required(BlockExtended, lazy=True, reverse="transactions")
    """The block containing this transaction."""

    transaction_index = Required(int, lazy=True)
    """The index of this transaction within the block."""

    hash = Required(str, index=True, lazy=True)
    """The transaction hash."""

    from_address = Required(AddressExtended, index=True, lazy=True, reverse="transactions_sent")
    """Sender address."""

    to_address = Optional(AddressExtended, index=True, lazy=True, reverse="transactions_received")
    """Recipient address (None for contract creation)."""

    value = Required(Decimal, 38, 18, lazy=True)
    price = Optional(Decimal, 38, 18, lazy=True)
    value_usd = Optional(Decimal, 38, 18, lazy=True)
    """USD value of the transaction (optional)."""

    nonce = Required(int, lazy=True)
    """Sender's transaction count at the time of this transaction."""

    type = Optional(int, lazy=True)
    """Transaction type (e.g., legacy, EIP-1559)."""

    gas = Required(Decimal, 38, 1, lazy=True)
    """Gas limit for the transaction."""

    gas_price = Required(Decimal, 38, 1, lazy=True)
    """Gas price (in wei)."""

    max_fee_per_gas = Optional(Decimal, 38, 1, lazy=True)
    """Max fee per gas (EIP-1559, optional)."""

    max_priority_fee_per_gas = Optional(Decimal, 38, 1, lazy=True)
    """Max priority fee per gas (EIP-1559, optional)."""

    composite_key(block, transaction_index)

    raw = Required(bytes, lazy=True)

    @cached_property
    def decoded(self) -> structs.Transaction:
        return json.decode(self.raw, type=structs.Transaction)

    @property
    def input(self) -> HexBytes:
        """The data payload sent with the transaction (for contract calls)."""
        return self.decoded.input

    @property
    def r(self) -> HexBytes:
        """ECDSA signature R value."""
        return self.decoded.r

    @property
    def s(self) -> HexBytes:
        """ECDSA signature S value."""
        return self.decoded.s

    @property
    def v(self) -> int:
        """ECDSA signature V value (replay protection)."""
        return self.decoded.v

    @property
    def access_list(self) -> typing.List[AccessListEntry]:
        """EIP-2930 access list (if present)."""
        return self.decoded.access_list

    @property
    def y_parity(self) -> typing.Optional[int]:
        """EIP-1559 y-parity value (if present)."""
        return self.decoded.y_parity


class InternalTransfer(DbEntity):
    """
    Represents an internal transfer (call, delegatecall, etc.) within a transaction.
    """

    _id = PrimaryKey(int, auto=True)
    """Auto-incrementing primary key for the internal transfer."""

    # common
    block = Required(BlockExtended, lazy=True, reverse="internal_transfers")
    """The block containing this internal transfer."""

    transaction_index = Required(int, lazy=True)
    """The index of the transaction within the block."""

    hash = Required(str, lazy=True)
    """Transaction hash."""

    from_address = Required(
        AddressExtended, index=True, lazy=True, reverse="internal_transfers_sent"
    )
    """Sender address."""

    to_address = Optional(
        AddressExtended, index=True, lazy=True, reverse="internal_transfers_received"
    )
    """Recipient address (None for contract creation)."""

    value = Required(Decimal, 38, 18, lazy=True)
    price = Optional(Decimal, 38, 18, lazy=True)
    value_usd = Optional(Decimal, 38, 18, lazy=True)
    """USD value of the transfer (optional)."""

    # unique
    type = Required(str, lazy=True)
    """Type of call (e.g., "call", "delegatecall", "staticcall")."""

    call_type = Required(str, lazy=True)
    """Call type (e.g., "call", "create")."""

    trace_address = Required(str, lazy=True)
    """Path of sub-calls to reach this transfer."""

    gas = Required(Decimal, 38, 1, lazy=True)
    """Gas provided for the call."""

    gas_used = Optional(Decimal, 38, 1, lazy=True)
    """Gas used by the call (optional)."""

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
        """The input data for the call."""
        return self.decoded.input

    @property
    def output(self) -> HexBytes:
        """The output data from the call."""
        return self.decoded.output

    @property
    def subtraces(self) -> int:
        """The number of sub-operations spawned by this internal transfer."""
        return self.decoded.subtraces


class TokenTransfer(DbEntity):
    """
    Represents an ERC20/ERC721 token transfer event within a transaction.
    """

    _id = PrimaryKey(int, auto=True)
    """Auto-incrementing primary key for the token transfer."""

    # common
    block = Required(BlockExtended, lazy=True, reverse="token_transfers")
    """The block containing this token transfer."""

    transaction_index = Required(int, lazy=True)
    """The index of the transaction within the block."""

    hash = Required(str, lazy=True)
    """Transaction hash."""

    from_address = Required(AddressExtended, index=True, lazy=True, reverse="token_transfers_sent")
    """Sender address."""

    to_address = Required(
        AddressExtended, index=True, lazy=True, reverse="token_transfers_received"
    )
    """Recipient address."""

    value = Required(Decimal, 38, 18, lazy=True)
    """Amount of tokens transferred."""

    price = Optional(Decimal, 38, 18, lazy=True)
    """Price of the token at the time of transfer (optional)."""

    value_usd = Optional(Decimal, 38, 18, lazy=True)
    """USD value of the transfer (optional)."""

    # unique
    log_index = Required(int, lazy=True)
    """Log index of the transfer event within the transaction."""

    token = Optional(TokenExtended, index=True, lazy=True, reverse="transfers")
    """The token contract involved in this transfer."""

    composite_key(block, transaction_index, log_index)

    raw = Required(bytes, lazy=True)

    @cached_property
    def decoded(self) -> structs.TokenTransfer:
        return json.decode(self.raw, type=structs.TokenTransfer)
