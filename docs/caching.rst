Caching in eth-portfolio
========================

Overview
--------

eth-portfolio uses multiple caching strategies to maximize performance, minimize redundant RPC/database calls, and provide fast access to frequently used data. These strategies closely mirror those in ypricemagic, with some eth_portfolio-specific extensions and customizations. For a detailed overview of the canonical caching system, see ypricemagic's [caching documentation](https://bobthebuidler.github.io/ypricemagic/caching.html).

Disk Caches
-----------

Local SQL Cache
~~~~~~~~~~~~~~~

- **Backend:** Pony ORM with SQLite (default, configurable via environment variables)
- **Location:** ``~/.ypricemagic/ypricemagic.sqlite``
- **Purpose:** Persistent storage for blockchain data, portfolio data, and cache metadata.
- **What is cached:**
  - Blockchain data: chains, blocks, addresses, contracts, tokens, prices
  - Portfolio data: transactions, internal transfers, token transfers, etc.
  - Cache metadata
- **Implementation:** Entities defined in ``eth_portfolio/_db/entities.py``
- **Integration:** If ypricemagic is installed, eth_portfolio will automatically extend and share the same persistent SQL database, unifying cached data and utility functions.

Disk Function Result Cache
~~~~~~~~~~~~~~~~~~~~~~~~~~

- **Backend:** Custom ``cache_to_disk`` decorator (see ``eth_portfolio/_cache.py``)
- **Location:** ``./cache/{chain.id}/...`` (per-chain)
- **Purpose:** Disk-based function result caching for expensive or slow-to-compute results.
- **Usage:** Decorate functions with ``@cache_to_disk`` to persist results to disk.
- **Note:** While ypricemagic uses ``joblib.Memory`` for this purpose, eth_portfolio implements a functionally similar in-house solution.

In-Memory LRU Caches
--------------------

Synchronous LRU Caches
~~~~~~~~~~~~~~~~~~~~~~

- **functools.lru_cache:** Used for pure in-memory caching of function results, especially for database reads (see ``db_session_cached`` in ``eth_portfolio/_db/utils.py``).
- **functools.cached_property:** Used for property-level in-memory caching throughout the codebase.

Asynchronous LRU Caches
~~~~~~~~~~~~~~~~~~~~~~~

- **async_lru.alru_cache:** Used extensively for async LRU caching of coroutine results (e.g., token metadata, block lookups, protocol-specific data). Some usages include TTLs (e.g., 1 hour, 5 minutes) for time-limited caching.

What is LRU-cached
~~~~~~~~~~~~~~~~~~

- Token metadata (symbols, decimals, names, buckets)
- Contract ABIs and deploy blocks
- Block/timestamp lookups
- Price data
- Protocol-specific data
- Results of expensive on-chain or DB queries

Cache Control
~~~~~~~~~~~~~

- Some caches have TTLs (time-limited)
- Some caches are per-chain (partitioned by chain ID)
- Some caches are unlimited size
- Caches are generally transparent to the user; cache control parameters (e.g., skip_cache) may exist at the function level

Summary Table
-------------

+-------------------+--------------------------+-----------------------------+-----------------------------+-------------+
| Cache Type        | Library/Decorator        | Example Usage               | What is Cached              | Sync/Async  |
+===================+==========================+=============================+=============================+=============+
| Local SQL         | Pony ORM (SQLite)        | _db/entities.py             | Blockchain, portfolio data  | Sync        |
+-------------------+--------------------------+-----------------------------+-----------------------------+-------------+
| Disk Function     | cache_to_disk (custom)   | _cache.py                   | Function results            | Sync/Async  |
+-------------------+--------------------------+-----------------------------+-----------------------------+-------------+
| LRU (in-memory)   | functools.lru_cache      | _db/utils.py                | DB reads                    | Sync        |
+-------------------+--------------------------+-----------------------------+-----------------------------+-------------+
| LRU (in-memory)   | functools.cached_property| _utils.py, etc.             | Property values             | Sync        |
+-------------------+--------------------------+-----------------------------+-----------------------------+-------------+
| LRU (in-memory)   | async_lru.alru_cache     | _utils.py, _ledgers/, etc.  | Async function results      | Async       |
+-------------------+--------------------------+-----------------------------+-----------------------------+-------------+

References
----------

- Canonical ypricemagic caching docs: https://bobthebuidler.github.io/ypricemagic/caching.html
- ``eth_portfolio/_cache.py``
- ``eth_portfolio/_db/entities.py``
- ``eth_portfolio/_db/utils.py``
- ``eth_portfolio/_utils.py``
- ``eth_portfolio/_ledgers/``
- ``eth_portfolio/_loaders/``
- ``eth_portfolio/protocols/``
