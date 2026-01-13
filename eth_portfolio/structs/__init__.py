"""
This module provides the primary union type and specific ledger entry types used in the `eth_portfolio` package.

The `__all__` list defines the public API for this module, which includes the main union type `LedgerEntry` and its specific types: `Transaction`, `InternalTransfer`, `TokenTransfer`, and `TransactionRLP`.

Examples:
    Importing the main union type and specific ledger entry types:

    >>> from eth_portfolio.structs import LedgerEntry, Transaction, InternalTransfer, TokenTransfer, TransactionRLP

    Using the `LedgerEntry` union type to annotate a variable that can hold any ledger entry type:

    >>> entry: LedgerEntry = Transaction(...)
    >>> entry = InternalTransfer(...)
    >>> entry = TokenTransfer(...)
    >>> entry = TransactionRLP(...)

See Also:
    - :class:`~eth_portfolio.structs.structs.LedgerEntry`
    - :class:`~eth_portfolio.structs.structs.Transaction`
    - :class:`~eth_portfolio.structs.structs.InternalTransfer`
    - :class:`~eth_portfolio.structs.structs.TokenTransfer`
    - :class:`~eth_portfolio.structs.structs.TransactionRLP`
"""

from eth_portfolio.structs.structs import (
    InternalTransfer,
    LedgerEntry,
    TokenTransfer,
    Transaction,
    TransactionRLP,
)

__all__ = [
    # main union type
    "LedgerEntry",
    # LedgerEntry types
    "Transaction",
    "InternalTransfer",
    "TokenTransfer",
    # TODO figure out how to get rid of this
    "TransactionRLP",
]
