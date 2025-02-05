"""
This module initializes the `_loaders` package within the `eth_portfolio` library.
It imports key functions responsible for loading blockchain data related to transactions
and token transfers for use within the package.

The functions imported here are designed to facilitate the retrieval and processing of
Ethereum blockchain data, enabling efficient data handling and storage for portfolio analysis.

Imported Functions:
    - :func:`~eth_portfolio._loaders.transaction.load_transaction`:
      Loads transaction data by address and nonce, with optional price data retrieval.
    - :func:`~eth_portfolio._loaders.token_transfer.load_token_transfer`:
      Processes and loads token transfer data from log entries, with optional price fetching.

Examples:
    These functions can be used to load and process blockchain data for portfolio analysis.
    For example, you might use them as follows:

    >>> from eth_portfolio._loaders import load_transaction, load_token_transfer
    >>> nonce, transaction = await load_transaction(address="0x1234567890abcdef1234567890abcdef12345678", nonce=5, load_prices=True)
    >>> print(transaction)

    >>> transfer_log = {"address": "0xTokenAddress", "data": "0xData", "removed": False}
    >>> token_transfer = await load_token_transfer(transfer_log, load_prices=True)
    >>> print(token_transfer)

See Also:
    - :mod:`eth_portfolio._loaders.transaction`: Contains functions for loading transaction data.
    - :mod:`eth_portfolio._loaders.token_transfer`: Contains functions for processing token transfer logs.
"""

from eth_portfolio._loaders.transaction import load_transaction
from eth_portfolio._loaders.token_transfer import load_token_transfer
