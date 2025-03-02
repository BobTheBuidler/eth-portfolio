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
    """
    Represents a transaction entity in the database.

    This class provides a property to access decoded transaction data,
    which includes input data, signature components, and access lists.
    The decoded data is accessed through the :attr:`decoded` property,
    which returns a :class:`structs.Transaction` object.

    See Also:
        - :class:`BlockExtended`
        - :class:`AddressExtended`
        - :class:`TokenTransfer`
    """

    _id = PrimaryKey(int, auto=True)
    "The primary key of the transaction."
    block = Required(BlockExtended, lazy=True, reverse="transactions")
    "The block containing this transaction."
    transaction_index = Required(int, lazy=True)
    "The index of the transaction within the block."
    hash = Required(str, index=True, lazy=True)
    "The hash of the transaction."
    from_address = Required(AddressExtended, index=True, lazy=True, reverse="transactions_sent")
    "The address that sent the transaction."
    to_address = Optional(AddressExtended, index=True, lazy=True, reverse="transactions_received")
    "The address that received the transaction."
    value = Required(Decimal, 38, 18, lazy=True)
    "The value transferred in the transaction."
    price = Optional(Decimal, 38, 18, lazy=True)
    "The price of the transaction."
    value_usd = Optional(Decimal, 38, 18, lazy=True)
    "The USD value of the transaction."

    nonce = Required(int, lazy=True)
    "The nonce of the transaction."
    type = Optional(int, lazy=True)
    "The type of the transaction."
    gas = Required(Decimal, 38, 1, lazy=True)
    "The gas used by the transaction."
    gas_price = Required(Decimal, 38, 1, lazy=True)
    "The gas price of the transaction."
    max_fee_per_gas = Optional(Decimal, 38, 1, lazy=True)
    "The maximum fee per gas for the transaction."
    max_priority_fee_per_gas = Optional(Decimal, 38, 1, lazy=True)
    "The maximum priority fee per gas for the transaction."

    composite_key(block, transaction_index)

    raw = Required(bytes, lazy=True)
    "The raw bytes of the transaction."

    @cached_property
    def decoded(self) -> structs.Transaction:
        """
        Decodes the raw transaction data into a :class:`structs.Transaction` object.

        Example:
            >>> transaction = Transaction(...)
            >>> decoded_transaction = transaction.decoded
            >>> isinstance(decoded_transaction, structs.Transaction)
            True

        See Also:
            - :class:`structs.Transaction`
        """
        return json.decode(self.raw, type=structs.Transaction)

    @property
    def input(self) -> HexBytes:
        """
        Returns the input data of the transaction.

        Example:
            >>> transaction = Transaction(...)
            >>> input_data = transaction.input
            >>> isinstance(input_data, HexBytes)
            True

        See Also:
            - :attr:`structs.Transaction.input`
        """
        structs.Transaction.input.__doc__
        return self.decoded.input

    @property
    def r(self) -> HexBytes:
        """
        Returns the R component of the transaction's signature.

        Example:
            >>> transaction = Transaction(...)
            >>> r_value = transaction.r
            >>> isinstance(r_value, HexBytes)
            True

        See Also:
            - :attr:`structs.Transaction.r`
        """
        structs.Transaction.r.__doc__
        return self.decoded.r

    @property
    def s(self) -> HexBytes:
        """
        Returns the S component of the transaction's signature.

        Example:
            >>> transaction = Transaction(...)
            >>> s_value = transaction.s
            >>> isinstance(s_value, HexBytes)
            True

        See Also:
            - :attr:`structs.Transaction.s`
        """
        structs.Transaction.s.__doc__
        return self.decoded.s

    @property
    def v(self) -> int:
        """
        Returns the V component of the transaction's signature.

        Example:
            >>> transaction = Transaction(...)
            >>> v_value = transaction.v
            >>> isinstance(v_value, int)
            True

        See Also:
            - :attr:`structs.Transaction.v`
        """
        structs.Transaction.v.__doc__
        return self.decoded.v

    @property
    def access_list(self) -> typing.List[AccessListEntry]:
        """
        Returns the access list of the transaction.

        Example:
            >>> transaction = Transaction(...)
            >>> access_list = transaction.access_list
            >>> isinstance(access_list, list)
            True
            >>> isinstance(access_list[0], AccessListEntry)
            True

        See Also:
            - :class:`AccessListEntry`
            - :attr:`structs.Transaction.access_list`
        """
        structs.Transaction.access_list.__doc__
        return self.decoded.access_list

    @property
    def y_parity(self) -> typing.Optional[int]:
        """
        Returns the y_parity of the transaction.

        Example:
            >>> transaction = Transaction(...)
            >>> y_parity_value = transaction.y_parity
            >>> isinstance(y_parity_value, (int, type(None)))
            True

        See Also:
            - :attr:`structs.Transaction.y_parity`
        """
        structs.Transaction.y_parity.__doc__
        return self.decoded.y_parity


class InternalTransfer(DbEntity):
    """
    Represents an internal transfer entity in the database.

    This class provides properties to access decoded internal transfer data,
    including input, output, and code.

    See Also:
        - :class:`BlockExtended`
        - :class:`AddressExtended`
    """

    _id = PrimaryKey(int, auto=True)
    "The primary key of the internal transfer."

    # common
    block = Required(BlockExtended, lazy=True, reverse="internal_transfers")
    "The block containing this internal transfer."
    transaction_index = Required(int, lazy=True)
    "The index of the transaction within the block."
    hash = Required(str, lazy=True)
    "The hash of the internal transfer."
    from_address = Required(
        AddressExtended, index=True, lazy=True, reverse="internal_transfers_sent"
    )
    "The address that sent the internal transfer."
    to_address = Optional(
        AddressExtended, index=True, lazy=True, reverse="internal_transfers_received"
    )
    "The address that received the internal transfer."
    value = Required(Decimal, 38, 18, lazy=True)
    "The value transferred in the internal transfer."
    price = Optional(Decimal, 38, 18, lazy=True)
    "The price of the internal transfer."
    value_usd = Optional(Decimal, 38, 18, lazy=True)
    "The USD value of the internal transfer."

    # unique
    type = Required(str, lazy=True)
    "The type of the internal transfer."
    call_type = Required(str, lazy=True)
    "The call type of the internal transfer."
    trace_address = Required(str, lazy=True)
    "The trace address of the internal transfer."
    gas = Required(Decimal, 38, 1, lazy=True)
    "The gas used by the internal transfer."
    gas_used = Optional(Decimal, 38, 1, lazy=True)
    "The gas used by the internal transfer."

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
    "The raw bytes of the internal transfer."

    @cached_property
    def decoded(self) -> structs.InternalTransfer:
        """
        Decodes the raw internal transfer data into a :class:`structs.InternalTransfer` object.

        Example:
            >>> internal_transfer = InternalTransfer(...)
            >>> decoded_transfer = internal_transfer.decoded
            >>> isinstance(decoded_transfer, structs.InternalTransfer)
            True

        See Also:
            - :class:`structs.InternalTransfer`
        """
        structs.InternalTransfer.__doc__
        return json.decode(self.raw, type=structs.InternalTransfer)

    @property
    def code(self) -> HexBytes:
        """
        Returns the code of the internal transfer.

        Example:
            >>> internal_transfer = InternalTransfer(...)
            >>> code_data = internal_transfer.code
            >>> isinstance(code_data, HexBytes)
            True

        See Also:
            - :attr:`structs.InternalTransfer.code`
        """
        structs.InternalTransfer.code.__doc__
        return self.decoded.code

    @property
    def input(self) -> HexBytes:
        """
        Returns the input data of the internal transfer.

        Example:
            >>> internal_transfer = InternalTransfer(...)
            >>> input_data = internal_transfer.input
            >>> isinstance(input_data, HexBytes)
            True

        See Also:
            - :attr:`structs.InternalTransfer.input`
        """
        structs.InternalTransfer.input.__doc__
        return self.decoded.input

    @property
    def output(self) -> HexBytes:
        """
        Returns the output data of the internal transfer.

        Example:
            >>> internal_transfer = InternalTransfer(...)
            >>> output_data = internal_transfer.output
            >>> isinstance(output_data, HexBytes)
            True

        See Also:
            - :attr:`structs.InternalTransfer.output`
        """
        structs.InternalTransfer.output.__doc__
        return self.decoded.output

    @property
    def subtraces(self) -> int:
        """
        Returns the number of subtraces of the internal transfer.

        Example:
            >>> internal_transfer = InternalTransfer(...)
            >>> subtraces_count = internal_transfer.subtraces
            >>> isinstance(subtraces_count, int)
            True

        See Also:
            - :attr:`structs.InternalTransfer.subtraces`
        """
        structs.InternalTransfer.subtraces.__doc__
        return self.decoded.subtraces


class TokenTransfer(DbEntity):
    """
    Represents a token transfer entity in the database.

    This class provides properties to access decoded token transfer data.

    See Also:
        - :class:`BlockExtended`
        - :class:`AddressExtended`
        - :class:`TokenExtended`
    """

    _id = PrimaryKey(int, auto=True)
    "The primary key of the token transfer."

    # common
    block = Required(BlockExtended, lazy=True, reverse="token_transfers")
    "The block containing this token transfer."
    transaction_index = Required(int, lazy=True)
    "The index of the transaction within the block."
    hash = Required(str, lazy=True)
    "The hash of the token transfer."
    from_address = Required(AddressExtended, index=True, lazy=True, reverse="token_transfers_sent")
    "The address that sent the token transfer."
    to_address = Required(
        AddressExtended, index=True, lazy=True, reverse="token_transfers_received"
    )
    "The address that received the token transfer."
    value = Required(Decimal, 38, 18, lazy=True)
    "The value transferred in the token transfer."
    price = Optional(Decimal, 38, 18, lazy=True)
    "The price of the token transfer."
    value_usd = Optional(Decimal, 38, 18, lazy=True)
    "The USD value of the token transfer."

    # unique
    log_index = Required(int, lazy=True)
    "The log index of the token transfer."
    token = Optional(TokenExtended, index=True, lazy=True, reverse="transfers")
    "The token involved in the transfer."

    composite_key(block, transaction_index, log_index)

    raw = Required(bytes, lazy=True)
    "The raw bytes of the token transfer."

    @cached_property
    def decoded(self) -> structs.TokenTransfer:
        """
        Decodes the raw token transfer data into a :class:`structs.TokenTransfer` object.

        Example:
            >>> token_transfer = TokenTransfer(...)
            >>> decoded_transfer = token_transfer.decoded
            >>> isinstance(decoded_transfer, structs.TokenTransfer)
            True

        See Also:
            - :class:`structs.TokenTransfer`
        """
        return json.decode(self.raw, type=structs.TokenTransfer)
