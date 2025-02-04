# eth_portfolio/_loaders/__init__.py

from eth_portfolio._loaders.transaction import load_transaction
from eth_portfolio._loaders.token_transfer import load_token_transfer

"""
This module serves as an initializer for the `_loaders` package within the `eth_portfolio` library. 
It imports key functions responsible for loading blockchain data related to transactions and token transfers.

The functions imported here are intended for internal use within the module and are not part of the public API. 
They facilitate the retrieval and processing of Ethereum blockchain data, enabling efficient data handling 
and storage for portfolio analysis.

Imported Functions:
    - :func:`~eth_portfolio._loaders.transaction.load_transaction`: 
      Loads transaction data by address and nonce, with optional price data retrieval.
    - :func:`~eth_portfolio._loaders.token_transfer.load_token_transfer`: 
      Processes and loads token transfer data from log entries, with optional price fetching.

Examples:
    These functions are used internally and are not intended to be accessed directly by users. 
    For example, within the module, you might see:

    >>> nonce, transaction = await load_transaction(address="0x1234567890abcdef1234567890abcdef12345678", nonce=5, load_prices=True)
    >>> print(transaction)

    >>> transfer_log = {"address": "0xTokenAddress", "data": "0xData", "removed": False}
    >>> token_transfer = await load_token_transfer(transfer_log, load_prices=True)
    >>> print(token_transfer)

See Also:
    - :mod:`eth_portfolio._loaders.transaction`: Contains functions for loading transaction data.
    - :mod:`eth_portfolio._loaders.token_transfer`: Contains functions for processing token transfer logs.
"""