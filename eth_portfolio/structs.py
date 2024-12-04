"""
Defines the data classes used to represent the various types of value-transfer actions on the blockchain. These include transactions, internal transfers, and token transfers. 

The classes are designed to provide a consistent and flexible interface for working with blockchain data. Instance attributes can be fetched with either dot notation or key lookup. Classes are compatible with the standard dictionary interface.
"""

import logging
from functools import cached_property
from typing import (
    TYPE_CHECKING,
    Any,
    ClassVar,
    Dict,
    List,
    Literal,
    Optional,
    Tuple,
    TypeVar,
    Union,
    final,
)

from brownie import chain
from dank_mids.structs.trace import Type
from dictstruct import DictStruct
from evmspec import FilterTrace, Transaction1559, Transaction2930, TransactionLegacy
from evmspec.data import Address
from evmspec.structs.transaction import AccessListEntry
from hexbytes import HexBytes
from msgspec import Struct
from y import Network
from y.datatypes import Block

from eth_portfolio._decimal import Decimal

if TYPE_CHECKING:
    from y._db.utils.logs import ArrayEncodableLog


logger = logging.getLogger(__name__)


class _LedgerEntryBase(DictStruct, kw_only=True, frozen=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    The :class:`~structs._LedgerEntryBase` class is a base class for ledger entries representing on-chain actions in a blockchain.

    Provides common attributes for transactions, internal transfers, and token transfers.

    Extended by specific ledger entry types :class:`~structs.Transaction`, :class:`~structs.InternalTransfer`, and :class:`~structs.TokenTransfer`.
    """

    @property
    def _evm_object(self) -> Union["Transaction", "InternalTransfer", "TokenTransfer"]:
        """
        The EVM object associated with {cls_name}, exactly as it was received from the RPC.
        """
        return getattr(self, self.entry_type)

    @property
    def chainid(self) -> Network:
        """
        The network ID where the {cls_name} occurred.
        """
        try:
            return Network(self._evm_object.chainId)
        except AttributeError:
            return Network(chain.id)

    @property
    def block_number(self) -> Block:
        """
        The block number where the {cls_name} was included.
        """
        return self._evm_object.block

    price: Optional[Decimal] = None
    """
    The price of the cryptocurrency at the time of the {cls_name}, if known.
    """

    value_usd: Optional[Decimal] = None
    """
    The USD value of the cryptocurrency transferred in the {cls_name}, if price is known.
    """

    def __init_subclass__(cls, **kwargs):
        super().__init_subclass__(**kwargs)

        # Replace {cls_name} in attribute-level docstrings
        for key, attr in cls.__dict__.items():
            if attr.__doc__ and "{cls_name}" in attr.__doc__:
                attr.__doc__ = attr.__doc__.replace("{cls_name}", cls.__name__)


class ArrayEncodableTransactionLegacy(TransactionLegacy, array_like=True, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    ...


class ArrayEncodableTransaction2930(Transaction2930, array_like=True, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    ...


class ArrayEncodableTransaction1559(Transaction1559, array_like=True, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    ...


ArrayEncodableTransaction = Union[
    ArrayEncodableTransactionLegacy, ArrayEncodableTransaction2930, ArrayEncodableTransaction1559
]

_types_mapping = {
    TransactionLegacy: ArrayEncodableTransactionLegacy,
    Transaction2930: ArrayEncodableTransaction2930,
    Transaction1559: ArrayEncodableTransaction1559,
}


def _get_init_kwargs(original_struct: Struct) -> Dict[str, Any]:
    kwargs = {}
    for key in original_struct.__struct_fields__:
        try:
            kwargs[key] = getattr(original_struct, key)
        except AttributeError:
            continue
    return kwargs


@final
class Transaction(
    _LedgerEntryBase,
    kw_only=True,
    frozen=True,
    array_like=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
    dict=True,
):
    """
    The :class:`~structs.Transaction` class represents a complete on-chain blockchain transaction.

    Contains detailed information about a single executed transaction on the blockchain,
    including gas parameters, signature components, and transaction-specific data.

    Example:
        >>> tx = Transaction(tx=ArrayEncodableTransaction1559(...))
        >>> tx.chainid
        Network.Mainnet
        >>> tx.type
        2
        >>> tx.max_fee_per_gas
        30000000000
    """

    entry_type: ClassVar[Literal["transaction"]] = "transaction"
    """
    Constant indicating this value transfer is an on-chain transaction entry.
    """

    @classmethod
    def from_rpc_response(
        cls,
        transaction: Union[TransactionLegacy, Transaction2930, Transaction1559],
        *,
        price: Optional[Decimal] = None,
        value_usd: Optional[Decimal] = None,
    ) -> "Transaction":
        try:
            new_type = _types_mapping[type(transaction)]
        except KeyError as e:
            raise TypeError(type(transaction), transaction) from e
        try:
            return cls(
                transaction=new_type(**_get_init_kwargs(transaction)),
                price=price,
                value_usd=value_usd,
            )
        except TypeError as e:  # NOTE keep this around later to help in case new fields are added
            raise TypeError(*e.args, new_type.__qualname__, {**transaction}) from e

    transaction: ArrayEncodableTransaction
    """
    The transaction object received by calling eth_getTransactionByHash.
    """

    @property
    def hash(self) -> HexBytes:
        """
        The unique transaction hash.
        """
        return self.transaction.hash

    @property
    def block_hash(self) -> HexBytes:
        """
        The hash of the block that includes this Transaction.
        """
        return self.transaction.blockHash

    @property
    def transaction_index(self) -> Optional[int]:
        """
        The index of the transaction within its block, if applicable.
        """
        return self.transaction.transactionIndex

    @property
    def nonce(self) -> int:
        """
        The sender's transaction count at the time of this Transaction.
        """
        return self.transaction.nonce

    @cached_property
    def type(self) -> Optional[int]:
        """
        The transaction type (e.g., 0 for legacy, 1 for EIP-2930, 2 for EIP-1559).
        None for chains that don't specify transaction types.
        """
        if typ := self.transaction.type:
            return int(typ.hex(), 16)

    @property
    def from_address(self) -> Optional[Address]:
        """
        The address from which the transaction was sent, if applicable.
        """
        return self.transaction.sender

    @property
    def to_address(self) -> Optional[Address]:
        """
        The address to which the transaction was sent, if applicable.
        """
        return self.transaction.to

    @property
    def value(self) -> Decimal:
        """
        The value/amount of cryptocurrency transferred in the transaction, scaled to a human-readable decimal value.
        """
        return self.transaction.value.scaled

    @property
    def gas(self) -> int:
        """
        The maximum amount of gas the sender is willing to use for the Transaction.
        """
        return self.transaction.gas

    @property
    def gas_price(self) -> int:
        """
        The price per unit of gas the sender is willing to pay (for legacy and EIP-2930 transactions).
        """
        return self.transaction.gasPrice

    @property
    def max_fee_per_gas(self) -> Optional[int]:
        """
        The maximum total fee per gas the sender is willing to pay (for EIP-1559 transactions only).
        """
        return self.transaction.maxFeePerGas

    @property
    def max_priority_fee_per_gas(self) -> Optional[int]:
        """
        The maximum priority fee per gas the sender is willing to pay (for EIP-1559 transactions only).
        """
        return self.transaction.maxPriorityFeePerGas

    @property
    def input(self) -> HexBytes:
        """
        The data payload sent with the Transaction, often used for contract interactions.
        """
        return self.transaction.input

    @property
    def r(self) -> HexBytes:
        """
        The R component of the Transaction's ECDSA signature.
        """
        return self.transaction.r

    @property
    def s(self) -> HexBytes:
        """
        The S component of the Transaction's ECDSA signature.
        """
        return self.transaction.s

    @property
    def v(self) -> int:
        """
        The V component of the Transaction's ECDSA signature, used for replay protection.
        """
        return self.transaction.v

    @property
    def access_list(self) -> Optional[Tuple[AccessListEntry, ...]]:
        """
        List of addresses and storage keys the transaction plans to access (for EIP-2930 and EIP-1559 transactions).
        """
        return self.transaction.accessList

    @property
    def y_parity(self) -> Optional[int]:
        """
        The Y parity of the transaction signature, used in EIP-2718 typed transactions.
        """
        return self.transaction.yParity


class ArrayEncodableFilterTrace(FilterTrace, frozen=True, kw_only=True, array_like=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    ...


@final
class InternalTransfer(
    _LedgerEntryBase,
    kw_only=True,
    frozen=True,
    array_like=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):
    """
    The :class:`~structs.InternalTransfer`class represents an internal transfer or call within a blockchain transaction.

    Captures operations that occur during transaction execution, such as contract-to-contract calls,
    contract creations, or self-destructs. These are not separate on-chain transactions but part of
    the execution of a single transaction.

    Example:
        >>> internal_tx = InternalTransfer(trace=ArrayEncodableFilterTrace(...), ...)
        >>> internal_tx.type
        'call'
        >>> internal_tx.trace_address
        '0.1'
        >>> internal_tx.gas_used
        21000
    """

    @classmethod
    def from_trace(
        cls,
        trace: FilterTrace,
        price: Optional[Decimal] = None,
        value_usd: Optional[Decimal] = None,
    ) -> "InternalTransfer":
        return cls(
            trace=ArrayEncodableFilterTrace(**_get_init_kwargs(trace)),
            price=price,
            value_usd=value_usd,
        )

    entry_type: ClassVar[Literal["internal_transfer"]] = "internal_transfer"
    """
    Constant indicating this value transfer is an internal transfer or call entry.
    """

    @property
    def _evm_object(self) -> ArrayEncodableFilterTrace:
        return self.trace

    trace: ArrayEncodableFilterTrace
    """
    The raw trace object associated with this internal transfer.
    """

    @property
    def block_hash(self) -> HexBytes:
        """
        The hash of the block containing the transaction that includes this InternalTransfer.
        """
        return self.trace.blockHash

    @property
    def transaction_index(self) -> Optional[int]:
        """
        The index of the transaction within its block, if applicable.
        """
        return self.trace.transactionPosition

    @property
    def hash(self) -> Union[HexBytes, str]:
        """
        The unique hash of the transaction containing this internal transfer.
        """
        return (
            f"{self.trace.action.rewardType.name} reward"
            if self.trace.type == Type.reward
            else self.trace.transactionHash
        )

    @property
    def from_address(self) -> Address:
        """
        The address from which the internal transfer was sent, if applicable.
        """
        return self.trace.action.sender

    @property
    def to_address(self) -> Address:
        """
        The address to which the internal transfer was sent, if applicable.
        """
        # NOTE: for block reward transfers, the recipient is 'author'
        return self.trace.action.author if self.trace.type == Type.reward else self.trace.action.to

    @property
    def value(self) -> Decimal:
        """
        The value/amount of cryptocurrency transferred in the internal transfer, scaled to a human-readable decimal value.
        """
        return self.trace.action.value.scaled

    @property
    def type(self) -> Type:
        return self.trace.type

    @property
    def trace_address(self) -> List[int]:
        """
        The path of sub-calls to reach this InternalTransfer within the transaction,

        Example:
        - The following trace_address
        ```python
        [0, 1, 2]
        ```
        represents the third sub-call of the second sub-call of the first top-level call.
        """
        return self.trace.traceAddress

    @property
    def gas(self) -> int:
        """
        The amount of gas allocated for this internal operation.
        """
        return 0 if self.trace.type == Type.reward else self.trace.action.gas

    @property
    def gas_used(self) -> int:
        """
        The amount of gas actually consumed by this internal operation, if known.
        """
        return self.trace.result.gasUsed

    @property
    def subtraces(self) -> int:
        """
        The number of sub-operations spawned by this InternalTransfer.
        """
        return self.trace.subtraces

    @property
    def call_type(self) -> Optional[str]:
        """
        The type of call made in this InternalTransfer (e.g., "call", "delegatecall", "staticcall").
        """
        return self.trace.action.callType.name

    @property
    def reward_type(self) -> Optional[str]:
        """
        The type of the reward, for reward transactions.
        """
        return self.trace.action.rewardType.name

    @property
    def input(self) -> HexBytes:
        """
        The input data for this internal operation, if any.
        """
        return self.trace.action.input

    @property
    def output(self) -> HexBytes:
        """
        The output data from this internal operation, if any.
        """
        return self.trace.result.output

    '''
    init: Optional[HexBytes] = UNSET
    """
    The initialization code for contract creation, if this is a create operation.
    """
    
    address: Optional[HexBytes] = UNSET
    """
    The address of the account or contract involved in this InternalTransfer.
    """
    
    code: Optional[HexBytes] = UNSET
    """
    The code of the contract involved in this InternalTransfer, if applicable.
    """
    '''


@final
class TokenTransfer(
    _LedgerEntryBase,
    kw_only=True,
    frozen=True,
    array_like=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
):
    """
    The :class:`~structs.TokenTransfer` class represents a token transfer event within a blockchain transaction.

    Captures the movement of ERC20-like tokens between addresses. These are typically
    emitted as events by token contracts and are not separate transactions but part of
    the execution of a transaction interacting with the token contract.

    Example:
        >>> token_transfer = TokenTransfer(
        ...     log=Log(...),
        ...     value=Decimal("1000000"),  # 1 USDC (assuming 6 decimals)
        ...     token="USDC",
        ... )
        >>> token_transfer.token
        'USDC'
        >>> token_transfer.value
        Decimal('1000000')
        >>> token_transfer.log_index
        3
    """

    entry_type: ClassVar[Literal["token_transfer"]] = "token_transfer"
    """
    Constant indicating this value transfer is a token transfer entry.
    """

    log: "ArrayEncodableLog"
    """
    The log associated with this token transfer.
    """

    @property
    def from_address(self) -> Address:
        return Address.checksum(self.log.topic1[-20:])

    @property
    def to_address(self) -> Address:
        return Address.checksum(self.log.topic2[-20:])

    @property
    def _evm_object(self) -> "ArrayEncodableLog":
        return self.log

    transaction_index: int

    @property
    def log_index(self) -> int:
        """
        The index of this transfer event within the transaction logs.
        Used to uniquely identify the Transfer event associated with this TokenTransfer within the transaction.
        """
        return self.log.logIndex

    token: Optional[str]
    """
    The symbol of the token being transferred, if known.
    """

    @property
    def hash(self) -> HexBytes:
        """
        The unique hash of the transaction containing this token transfer.
        """
        return self.log.transactionHash

    @property
    def token_address(self) -> Address:
        """
        The contract address of the token being transferred.
        """
        return self.log.address

    value: Decimal
    """
    The amount of tokens transferred, scaled to a human-readable decimal value.
    """


LedgerEntry = Union[Transaction, InternalTransfer, TokenTransfer]
"""
Type alias representing any type of ledger entry (:class:`~structs.Transaction`, :class:`~structs.InternalTransfer`, or :class:`~structs.TokenTransfer`).
"""

_LE = TypeVar("_LE", Transaction, InternalTransfer, TokenTransfer)
"""
Type variable for generic operations on ledger entries. Can be :class:`~structs.Transaction`, :class:`~structs.InternalTransfer`, or :class:`~structs.TokenTransfer`.
"""
