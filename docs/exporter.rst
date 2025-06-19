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

Docker Containers
-----------------
When you run the Portfolio Exporter, ETH Portfolio will build and start 3 required Docker containers on your system, as well as up to 1 optional container depending on your configuration. These containers work together to collect, store, and visualize your portfolio data:

- ``grafana``
  The Grafana container provides a web-based dashboard for visualizing your portfolio metrics and balances. It is pre-configured with a "Balances" dashboard and uses victoria-metrics as its Prometheus-compatible data source. Grafana is accessible locally (default port 3000) and supports dashboard image rendering via the renderer container. Anonymous access is enabled for convenience.

- ``renderer`` (optional)
  The renderer container runs the official grafana-image-renderer service, enabling Grafana to export dashboards as images. This is useful for generating reports or sharing visualizations. It is tightly integrated with the Grafana container and operates on port 8091 by default. **This container is only started if you pass the ``--start-renderer`` flag to the infra command.**

- ``victoria-metrics``
  victoria-metrics is a high-performance, long-retention time-series database that stores all portfolio and balance metrics. Data is persisted to a local volume for durability, with a default retention period of 10 years. It receives metrics from vmagent and serves as the main data source for Grafana (default port 8428).

- ``vmagent``
  vmagent is responsible for collecting and forwarding metrics to victoria-metrics. It is configured to remote write all scraped metrics to the victoria-metrics container. vmagent ensures that all relevant portfolio data is reliably collected and stored for visualization and analysis.

Data Flow Summary
-----------------
The containers interact as follows:

1. **eth-portfolio** and/or related exporters expose metrics endpoints.
2. **vmagent** scrapes these endpoints and forwards the data to **victoria-metrics**.
3. **victoria-metrics** stores the time-series data for long-term analysis.
4. **Grafana** is pre-configured to use victoria-metrics as its data source and provides dashboards (such as "Balances") for visualization.
5. The **renderer** container enables Grafana to export dashboards as images for reporting or sharing (if started with ``--start-renderer``).

.. mermaid::

   graph TD
     A[eth-portfolio metrics/exporters] --> B(vmagent)
     B --> C(victoria-metrics)
     C --> D[Grafana]
     D --> E[renderer]
     D --> F[User Dashboard]

Additional Information
----------------------
- All containers are orchestrated via Docker Compose and are automatically started as needed.
- Grafana provisioning files ensure dashboards and data sources are set up out-of-the-box.
- Metrics are stored with a long retention period, enabling historical analysis.
- Dashboard images can be generated for reporting via the renderer (if started).

Data Extraction and Portfolio Calculations
------------------------------------------

The Portfolio Exporter performs a comprehensive extraction and calculation process to ensure accurate and detailed portfolio data. The workflow is as follows:

**1. Data Extraction Process**

- **Per-Wallet, Per-Timestamp:**  
  For each wallet specified via the CLI, the exporter iterates over a series of timestamps (based on the `--interval` argument). At each timestamp, it determines the corresponding Ethereum block and extracts a snapshot of the portfolio at that point in time.

- **Asynchronous Data Loading:**  
  The exporter leverages highly concurrent, asynchronous routines to efficiently load data for all wallets and tokens. It uses specialized loader functions to fetch:
  - Token balances (including ERC-20 and protocol-specific tokens)
  - Transaction history
  - Token transfers
  - Protocol positions (e.g., lending, borrowing, staking)

- **Block and Transaction Resolution:**  
  For each timestamp, the exporter resolves the closest block and loads all relevant on-chain data for the specified wallets. This includes querying balances, fetching transaction receipts, and aggregating protocol positions.

**2. Portfolio Calculations**

- **Balance and Value Computation:**  
  For each token held by a wallet, the exporter calculates:
  - The raw token balance
  - The USD value of the balance (using price oracles or on-chain data)
  - Protocol-specific metrics (e.g., supplied/borrowed amounts, rewards)

- **Aggregation and Structuring:**  
  The exporter organizes data into logical sections, such as "assets", "debts", and "external" protocol positions. It aggregates balances across all wallets and protocols, ensuring a unified view of the portfolio.

- **Metric Formatting:**  
  Each data point is formatted as a Prometheus metric, including metadata such as wallet address, token address, token symbol, protocol name, and a logical "bucket" for grouping. Both the raw balance and USD value are exported for each token.

**3. Export and Storage**

- **Deduplication:**  
  Before exporting, the system checks if data for a given timestamp already exists in the time-series database to avoid redundant processing.

- **Export to VictoriaMetrics:**  
  The processed metrics are sent to the VictoriaMetrics time-series database, where they are stored for long-term analysis and visualization in Grafana.

- **Error Handling and Robustness:**  
  The exporter is designed to handle network errors, missing data, and protocol-specific quirks gracefully, ensuring reliable and repeatable exports.

**Summary**

This architecture allows the Portfolio Exporter to provide a high-fidelity, time-resolved view of all wallet balances, protocol positions, and historical portfolio values. The modular, asynchronous design ensures scalability and performance, even for large portfolios or long time ranges.
