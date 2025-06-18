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
When you run the Portfolio Exporter, ETH Portfolio will build and start 4 required Docker containers on your system. These containers work together to collect, store, and visualize your portfolio data:

- ``grafana``
  The Grafana container provides a web-based dashboard for visualizing your portfolio metrics and balances. It is pre-configured with a "Balances" dashboard and uses victoria-metrics as its Prometheus-compatible data source. Grafana is accessible locally (default port 3000) and supports dashboard image rendering via the renderer container. Anonymous access is enabled for convenience.

- ``renderer``
  The renderer container runs the official grafana-image-renderer service, enabling Grafana to export dashboards as images. This is useful for generating reports or sharing visualizations. It is tightly integrated with the Grafana container and operates on port 8091 by default.

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
5. The **renderer** container enables Grafana to export dashboards as images for reporting or sharing.

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
- Dashboard images can be generated for reporting via the renderer.

TODO: add more details on the underlying data extraction process and portfolio calculations
