"""
Defines the data classes used to represent the various types of value-transfer actions on the blockchain. These include transactions, internal transfers, and token transfers.

The classes are designed to provide a consistent and flexible interface for working with blockchain data. Instance attributes can be fetched with either dot notation or key lookup. Classes are compatible with the standard dictionary interface.
"""

from functools import cached_property
from typing import (
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

import evmspec
from brownie import chain
from dictstruct import DictStruct
from evmspec.data import Address, BlockHash, TransactionHash, Wei
from evmspec.structs.trace import reward
from evmspec.structs.transaction import AccessListEntry
from hexbytes import HexBytes
from msgspec import Struct
from y import Network
from y._db.log import Log
from y._decorators import stuck_coro_debugger
from y.constants import EEE_ADDRESS
from y.datatypes import Block

from eth_portfolio._decimal import Decimal
from eth_portfolio._utils import _get_price
from eth_portfolio.structs.modified import ModifiedTrace, _modified_trace_type_map


class _LedgerEntryBase(DictStruct, kw_only=True, frozen=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    The :class:`~structs._LedgerEntryBase` class is a base class for ledger entries representing on-chain actions in a blockchain.

    Provides common attributes for transactions, internal transfers, and token transfers.

    Extended by specific ledger entry types :class:`~structs.Transaction`, :class:`~structs.InternalTransfer`, and :class:`~structs.TokenTransfer`.
    """

    @property
    def _evm_object(self) -> Union[evmspec.Transaction, evmspec.FilterTrace, Log]:
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


def _get_init_kwargs(original_struct: Struct) -> Dict[str, Any]:
    kwargs = {}
    for key in original_struct.__struct_fields__:
        try:
            kwargs[key] = getattr(original_struct, key)
        except AttributeError:
            continue
    return kwargs


class _TransactionBase(
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
        >>> tx = Transaction(tx=Transaction1559(...))
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
        transaction: evmspec.Transaction,
        *,
        price: Optional[Decimal] = None,
        value_usd: Optional[Decimal] = None,
    ) -> "Transaction":
        return cls(
            transaction=transaction,
            price=price,
            value_usd=value_usd,
        )

    @property
    def hash(self) -> TransactionHash:
        """
        The unique transaction hash.
        """
        return self.transaction.hash

    @property
    def block_hash(self) -> BlockHash:
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
        return Wei(self.transaction.value).scaled

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

    @property
    def __db_primary_key__(self):
        return {"from_address": (chain.id, self.from_address), "nonce": self.nonce}


@final
class Transaction(
    _TransactionBase,
    kw_only=True,
    frozen=True,
    array_like=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
    dict=True,
):

    transaction: evmspec.Transaction
    """
    The transaction object received by calling eth_getTransactionByHash.
    """


@final
class TransactionRLP(
    _TransactionBase,
    kw_only=True,
    frozen=True,
    array_like=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
    dict=True,
):

    transaction: evmspec.TransactionRLP
    """
    The transaction object received by calling eth_getTransactionByHash.
    """


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
        >>> internal_tx = InternalTransfer(trace=evmspec.FilterTrace(...), ...)
        >>> internal_tx.type
        'call'
        >>> internal_tx.trace_address
        '0.1'
        >>> internal_tx.gas_used
        21000
    """

    @staticmethod
    @stuck_coro_debugger
    async def from_trace(trace: evmspec.FilterTrace, load_prices: bool) -> "InternalTransfer":
        # sourcery skip: simplify-boolean-comparison
        """
        Asynchronously processes a raw internal transfer dictionary into an InternalTransfer object.

        This function is the core of the internal transfer processing pipeline. It handles
        various types of transfers, including special cases like block and uncle rewards.
        It also filters out certain transfers (e.g., to Gnosis Safe Singleton) and verifies
        transaction success for non-reward transfers.

        The function performs several data transformations:
        - Value and gas conversions
        - Optional USD price loading
        - Field standardization

        Args:
            transfer: A dictionary containing the raw internal transfer data. Expected to have keys such as
                    'type', 'transactionHash', 'blockNumber', 'from', 'to', 'value', 'gas', 'gasUsed', 'traceAddress'.
            load_prices: Flag to determine whether to load USD prices for the transfer value.

        Returns:
            A processed InternalTransfer object.

        Example:
            >>> transfer = {"type": "call", "transactionHash": "0x123...", "blockNumber": 15537393, "from": "0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48", "to": "0x7a250d5630B4cF539739dF2C5dAcb4c659F2488D", "value": "0x10", "gas": "0x5208", "gasUsed": "0x5208", "traceAddress": [0]}
            >>> internal_tx = await load_internal_transfer(transfer=transfer, load_prices=True); print(internal_tx)

        Note:
            - Transfers to the Gnosis Safe Singleton (0xd9Db270c1B5E3Bd161E8c8503c55cEABeE709552) are filtered out
            as they typically don't represent actual value transfers.
            - The `traceAddress` is converted to a string for consistent representation across different scenarios.
            - For block and uncle rewards, `gas` is set to 0 as these are not regular transactions.
            - When loading prices, the `EEE_ADDRESS` constant is used, which represents the native currency of the chain.

        Integration with eth_portfolio ecosystem:
            - Uses the InternalTransfer struct from eth_portfolio.structs for standardized output.
            - Utilizes utility functions from eth_portfolio._loaders.utils and eth_portfolio._utils.
            - Interacts with the global 'chain' object from the brownie library for chain ID.
        """

        modified_cls = _modified_trace_type_map[type(trace)]
        modified_trace = modified_cls(**_get_init_kwargs(trace))

        if load_prices is False:
            return InternalTransfer(trace=modified_trace)

        price = await _get_price(EEE_ADDRESS, trace.block)
        value_usd = round(trace.action.value.scaled * price, 18)
        return InternalTransfer(trace=modified_trace, price=price, value_usd=value_usd)

    entry_type: ClassVar[Literal["internal_transfer"]] = "internal_transfer"
    """
    Constant indicating this value transfer is an internal transfer or call entry.
    """

    @property
    def _evm_object(self) -> ModifiedTrace:
        return self.trace

    trace: ModifiedTrace
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
            if isinstance(self.trace, reward.Trace)
            else self.trace.transactionHash
        )

    @property
    def from_address(self) -> Address:
        """
        The address from which the internal transfer was sent, if applicable.
        """
        return self.trace.action.sender

    @property
    def to_address(self) -> Optional[Address]:
        """
        The address to which the internal transfer was sent, if applicable.
        """
        action = self.trace.action
        # NOTE: for block reward transfers, the recipient is 'author'
        return action.author if isinstance(action, reward.Action) else action.to

    @property
    def value(self) -> Decimal:
        """
        The value/amount of cryptocurrency transferred in the internal transfer, scaled to a human-readable decimal value.
        """
        return self.trace.action.value.scaled

    @property
    def type(self) -> Literal["call", "create", "reward", "suicide"]:
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
        return 0 if isinstance(self.trace, reward.Trace) else self.trace.action.gas

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

    log: Log
    """
    The log associated with this token transfer.
    """

    @property
    def from_address(self) -> Address:
        return self.log.topic1.as_address

    @property
    def to_address(self) -> Address:
        return self.log.topic2.as_address

    @property
    def _evm_object(self) -> Log:
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
