"""
Defines the data classes used to represent the various types of value-transfer actions on the blockchain. These include transactions, internal transfers, and token transfers. 

The classes are designed to provide a consistent and flexible interface for working with blockchain data. Instance attributes can be fetched with either dot notation or key lookup. Classes are compatible with the standard dictionary interface.
"""

import logging
from decimal import Decimal
from functools import cached_property
from typing import Any, ClassVar, Iterator, Literal, Optional, Tuple, TypeVar, Union

from dank_mids.structs import DictStruct, FilterTrace, Log, Transaction1559, Transaction2930, TransactionLegacy
from dank_mids.structs.data import Address, checksum
from dank_mids.structs.trace import Type
from dank_mids.structs.transaction import AccessListEntry
from hexbytes import HexBytes
from msgspec import Struct
from y import Network
from y.datatypes import Block


logger = logging.getLogger(__name__)


class Log(Log, frozen=True, array_like=True):
    ...

ArrayEncodableLog = Log


class _LedgerEntryBase(DictStruct, kw_only=True, frozen=True, omit_defaults=True, repr_omit_defaults=True):
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



class ArrayEncodableTransactionLegacy(TransactionLegacy, array_like=True, frozen=True, kw_only=True, forbid_unknown_fields=True):
    ...
    
class ArrayEncodableTransaction2930(Transaction2930, array_like=True, frozen=True, kw_only=True, forbid_unknown_fields=True):
    ...
    
class ArrayEncodableTransaction1559(Transaction1559, array_like=True, frozen=True, kw_only=True, forbid_unknown_fields=True):
    ...
    
ArrayEncodableTransaction = Union[ArrayEncodableTransactionLegacy, ArrayEncodableTransaction2930, ArrayEncodableTransaction1559]


class Transaction(_LedgerEntryBase, kw_only=True, frozen=True, array_like=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True, dict=True):
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

    entry_type: ClassVar[Literal['transaction']] = 'transaction'
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
        if isinstance(transaction, TransactionLegacy):
            return cls(transaction=ArrayEncodableTransactionLegacy(**transaction), price, value_usd)
        if isinstance(transaction, Transaction1559):
            return cls(transaction=ArrayEncodableTransaction2930(**transaction), price, value_usd)
        if isinstance(transaction, Transaction2930):
            return cls(transaction=ArrayEncodableTransaction1559(**transaction), price, value_usd)
        raise TypeError(type(transaction), transaction)

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
        typ = self.transaction.type
        return None if typ is None else int(typ, 16)

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
    def value(self) -> int:
        """
        The value/amount of cryptocurrency transferred in the transaction.
        """
        return self.transaction.value

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


class ArrayEncodableFilterTrace(FilterTrace, frozen=True, kw_only=True, array_like=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    ...
    
class InternalTransfer(_LedgerEntryBase, kw_only=True, frozen=True, array_like=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):
    """
    The :class:`~structs.InternalTransfer`class represents an internal transfer or call within a blockchain transaction.

    Captures operations that occur during transaction execution, such as contract-to-contract calls,
    contract creations, or self-destructs. These are not separate on-chain transactions but part of
    the execution of a single transaction.

    Example:
        >>> internal_tx = InternalTransfer(
        ...     trace=ArrayEncodableFilterTrace(...),
        ...     type="call",
        ...     trace_address="0.1",
        ...     subtraces=1,
        ... )
        >>> internal_tx.type
        'call'
        >>> internal_tx.trace_address
        '0.1'
        >>> internal_tx.gas_used
        21000
    """

    entry_type: ClassVar[Literal['internal_transfer']] = 'internal_transfer'
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
    
    block_hash: HexBytes
    """
    The hash of the block containing the transaction that includes this InternalTransfer.
    """
    
    @property
    def transaction_index(self) -> Optional[int]:
        """
        The index of the transaction within its block, if applicable.
        """
        return self.trace.transactionPosition
        
    @property
    def hash(self) -> Optional[int]:
        """
        The unique hash of the transaction containing this internal transfer.
        """
        return f'{self.trace.action.rewardType.name} reward' if self.trace.type == Type.reward else self.trace.transactionHash

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
    def value(self) -> int:
        """
        The value/amount of cryptocurrency transferred in the internal transfer.
        """
        return self.trace.action.value
        
    type: str
    """
    The type of internal operation (e.g., "call" for contract calls, "create" for contract creation,
    "suicide" for contract self-destruct).
    """
    
    trace_address: str
    """
    The path of sub-calls to reach this InternalTransfer within the transaction.
    Represented as period-separated integers, e.g., "0.1.2" for the third sub-call of the second sub-call
    of the first top-level call.
    """
    
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
    
    subtraces: int
    """
    The number of sub-operations spawned by this InternalTransfer.
    """
    
    @property
    def call_type(self) -> Optional[str]:
        """
        The type of call made in this InternalTransfer (e.g., "call", "delegatecall", "staticcall").
        """
        return trace.action.callType.name
    
    @property
    def reward_type(self) -> Optional[str]:
        """
        The type of the reward, for reward transactions.
        """
        return trace.action.rewardType.name

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
    
    init: Optional[HexBytes]
    """
    The initialization code for contract creation, if this is a create operation.
    """
    
    address: Optional[HexBytes]
    """
    The address of the account or contract involved in this InternalTransfer.
    """
    
    code: Optional[HexBytes]
    """
    The code of the contract involved in this InternalTransfer, if applicable.
    """

    
class TokenTransfer(_LedgerEntryBase, kw_only=True, frozen=True, array_like=True, forbid_unknown_fields=True):
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

    entry_type: ClassVar[Literal['token_transfer']] = 'token_transfer'
    """
    Constant indicating this value transfer is a token transfer entry.
    """

    log: ArrayEncodableLog
    """
    The log associated with this token transfer.
    """

    @property
    def from_address(self) -> Address:
        return checksum(self.log.topics[1][-20:])

    @property
    def to_address(self) -> Address:
        return checksum(self.log.topics[2][-20:])

    @property
    def _evm_object(self) -> ArrayEncodableLog:
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
