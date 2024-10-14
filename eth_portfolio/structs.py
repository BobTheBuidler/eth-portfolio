"""
Defines the data classes used to represent the various types of value-transfer actions on the blockchain. These include transactions, internal transfers, and token transfers. 

The classes are designed to provide a consistent and flexible interface for working with blockchain data. Instance attributes can be fetched with either dot notation or key lookup. Classes are compatible with the standard dictionary interface.
"""

import logging
from decimal import Decimal
from typing import Any, ClassVar, Iterator, Literal, Optional, Tuple, TypeVar, Union

from dank_mids.structs import DictStruct
from msgspec import Struct
from y import Network
from y.datatypes import Block

logger = logging.getLogger(__name__)
    
class _LedgerEntryBase(DictStruct, kw_only=True, frozen=True):
    """
    The :class:`~structs._LedgerEntryBase` class is a base class for ledger entries representing on-chain actions in a blockchain.

    Provides common attributes for transactions, internal transfers, and token transfers.

    Extended by specific ledger entry types :class:`~structs.Transaction`, :class:`~structs.InternalTransfer`, and :class:`~structs.TokenTransfer`.
    """

    chainid: Network
    """
    The network ID where the {cls_name} occurred.    
    """
    
    block_number: Block
    """
    The block number where the {cls_name} was included.
    """
    
    transaction_index: Optional[int] = None
    """
    The index of the transaction within its block, if applicable.
    """
    
    hash: str
    """
    The unique transaction hash.
    """
    
    from_address: Optional[str] = None
    """
    The address from which the {cls_name} was sent, if applicable.
    """
    
    value: Decimal
    """
    The value/amount of cryptocurrency transferred in the {cls_name}.
    """
    
    to_address: Optional[str] = None
    """
    The address to which the {cls_name} was sent, if applicable.
    """
    
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


class AccessListEntry(Struct, frozen=True):
    """
    The :class:`~structs.AccessListEntry` class represents an entry in an Ethereum transaction access list.

    Access lists are used in EIP-2930 and EIP-1559 transactions to specify storage slots
    that the transaction plans to access, potentially reducing gas costs.

    Example:
        >>> entry = AccessListEntry(
        ...     address="0x742d35Cc6634C0532925a3b844Bc454e4438f44e", 
        ...     storage_keys=(b'key1', b'key2')
        ... )
        >>> entry.address
        '0x742d35Cc6634C0532925a3b844Bc454e4438f44e'
        >>> len(entry.storage_keys)
        2
    """

    address: str
    """
    The Ethereum address of the contract whose storage is being accessed.
    """
    
    storage_keys: Tuple[bytes, ...]
    """
    The specific storage slot keys within the contract that will be accessed.
    """
    
class Transaction(_LedgerEntryBase, kw_only=True, frozen=True):
    """
    The :class:`~structs.Transaction` class represents a complete on-chain blockchain transaction.

    Contains detailed information about a single executed transaction on the blockchain,
    including gas parameters, signature components, and transaction-specific data.

    Example:
        >>> tx = Transaction(
        ...     chainid=Network.Mainnet,
        ...     block_number=Block(15537393),
        ...     hash="0x123...",
        ...     from_address="0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48",
        ...     to_address="0x7a250d5630B4cF539739dF2C5dAcb4c659F2488D",
        ...     value=Decimal("0.1"),
        ...     block_hash="0xabc...",
        ...     nonce=42,
        ...     type=2,  # EIP-1559 transaction
        ...     gas=21000,
        ...     gas_price=20000000000,
        ...     max_fee_per_gas=30000000000,
        ...     max_priority_fee_per_gas=1000000000,
        ...     input="0x",
        ...     r="0x123...",
        ...     s="0x456...",
        ...     v=27
        ... )
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
    
    block_hash: str
    """
    The hash of the block that includes this Transaction.
    """
    
    nonce: int
    """
    The sender's transaction count at the time of this Transaction.
    """
    
    type: Optional[int]
    """
    The transaction type (e.g., 0 for legacy, 1 for EIP-2930, 2 for EIP-1559).
    None for chains that don't specify transaction types.
    """
    
    gas: int
    """
    The maximum amount of gas the sender is willing to use for the Transaction.
    """
    
    gas_price: int
    """
    The price per unit of gas the sender is willing to pay (for legacy and EIP-2930 transactions).
    """
    
    max_fee_per_gas: Optional[int] = None
    """
    The maximum total fee per gas the sender is willing to pay (for EIP-1559 transactions).
    """
    
    max_priority_fee_per_gas: Optional[int] = None
    """
    The maximum priority fee per gas the sender is willing to pay (for EIP-1559 transactions).
    """
    
    input: str
    """
    The data payload sent with the Transaction, often used for contract interactions.
    """
    
    r: str
    """
    The R component of the Transaction's ECDSA signature.
    """
    
    s: str
    """
    The S component of the Transaction's ECDSA signature.
    """
    
    v: int
    """
    The V component of the Transaction's ECDSA signature, used for replay protection.
    """
    
    access_list: Optional[Tuple[AccessListEntry, ...]] = None
    """
    List of addresses and storage keys the transaction plans to access (for EIP-2930 and EIP-1559 transactions).
    """
    
    y_parity: Optional[int] = None
    """
    The Y parity of the transaction signature, used in EIP-2718 typed transactions.
    """


class InternalTransfer(_LedgerEntryBase, kw_only=True, frozen=True):
    """
    The :class:`~structs.InternalTransfer`class represents an internal transfer or call within a blockchain transaction.

    Captures operations that occur during transaction execution, such as contract-to-contract calls,
    contract creations, or self-destructs. These are not separate on-chain transactions but part of
    the execution of a single transaction.

    Example:
        >>> internal_tx = InternalTransfer(
        ...     chainid=Network.Mainnet,
        ...     block_number=Block(15537393),
        ...     hash="0x123...",
        ...     from_address="0x7a250d5630B4cF539739dF2C5dAcb4c659F2488D",
        ...     to_address="0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48",
        ...     value=Decimal("0"),
        ...     block_hash="0xabc...",
        ...     type="call",
        ...     trace_address="0.1",
        ...     gas=100000,
        ...     gas_used=21000,
        ...     subtraces=1,
        ...     call_type="call",
        ...     input="0x123...",
        ...     output="0x456..."
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
    
    block_hash: str
    """
    The hash of the block containing the transaction that includes this InternalTransfer.
    """
    
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
    
    gas: int
    """
    The amount of gas allocated for this internal operation.
    """
    
    gas_used: Optional[int]
    """
    The amount of gas actually consumed by this internal operation, if known.
    """
    
    subtraces: int
    """
    The number of sub-operations spawned by this InternalTransfer.
    """
    
    call_type: Optional[str] = None
    """
    The type of call made in this InternalTransfer (e.g., "call", "delegatecall", "staticcall").
    """
    
    input: Optional[str] = None
    """
    The input data for this internal operation, if any.
    """
    
    output: Optional[str] = None
    """
    The output data from this internal operation, if any.
    """
    
    init: Optional[str] = None
    """
    The initialization code for contract creation, if this is a create operation.
    """
    
    address: Optional[str] = None
    """
    The address of the account or contract involved in this InternalTransfer.
    """
    
    code: Optional[str] = None
    """
    The code of the contract involved in this InternalTransfer, if applicable.
    """


class TokenTransfer(_LedgerEntryBase, kw_only=True, frozen=True):
    """
    The :class:`~structs.TokenTransfer` class represents a token transfer event within a blockchain transaction.

    Captures the movement of ERC20-like tokens between addresses. These are typically
    emitted as events by token contracts and are not separate transactions but part of
    the execution of a transaction interacting with the token contract.

    Example:
        >>> token_transfer = TokenTransfer(
        ...     chainid=Network.Mainnet,
        ...     block_number=Block(15537393),
        ...     hash="0x123...",
        ...     from_address="0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48",
        ...     to_address="0x7a250d5630B4cF539739dF2C5dAcb4c659F2488D",
        ...     value=Decimal("1000000"),  # 1 USDC (assuming 6 decimals)
        ...     log_index=3,
        ...     token="USDC",
        ...     token_address="0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48"
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
    
    log_index: int
    """
    The index of this transfer event within the transaction logs.
    Used to uniquely identify the Transfer event associated with this TokenTransfer within the transaction.
    """
    
    token: Optional[str]
    """
    The identifier or symbol of the token being transferred, if known.
    """
    
    token_address: str
    """
    The contract address of the token being transferred.
    """
    
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
