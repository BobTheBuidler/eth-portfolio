Portfolio Exporter
==================

Overview
--------
The Portfolio Exporter is a command-line tool provided by eth-portfolio. It is designed to extract and compile portfolio data – such as token balances, transaction history, and other relevant financial information – into exportable formats that can be further analyzed or integrated with external services.

Requirements
------------
- Python 3.10 or higher.
- At least 16GB of RAM.
- All dependencies installed as specified in the project’s ``requirements.txt`` file.
- Proper configuration settings (e.g., API keys, network endpoints) must be set up as required by the portfolio and balance loaders. More info below.

Usage
-----
The Portfolio Exporter should be used via the CLI. Include each of your wallets in the command like so:
  
  .. code-block:: bash
  
      eth-portfolio export --wallet 0x123 --wallet 0x234 --wallet 0x345

Command-Line Options
--------------------
The Portfolio Exporter supports several command-line options to customize its behavior:

- ``--wallet <address>``
  Specify a wallet to be included in your portfolio. You can pass this flag multiple times for multiple wallets.

- ``--network <network-id>``
  The brownie network identifier for the rpc you wish to use. default: mainnet

- ``--interval <interval>``
  The time interval between datapoints. default: 6h

- ``--first-tx-block <block>``
  The block of your portfolio's first transaction, if known. This value, if provided, allows us to speed up processing of your data by limiting the block range we need to query. If not provided, the whole blockchain will be scanned. default: 0
  
- ``--export-start-block <block>``
  The first block in the range you wish to export. default: 0

Additional Information
----------------------
TODO: add more details on the underlying data extraction process and portfolio calculations
