Contributing: Adding New Protocols
==================================

This guide explains how to add support for new staking pools, lending/borrowing protocols, and other DeFi integrations to eth-portfolio. The system is designed for extensibility, using abstract base classes (ABCs) and a modular protocol architecture.

Choosing the Appropriate Base Class
-----------------------------------

eth-portfolio supports several types of protocols, each with a corresponding abstract base class. To add a new protocol, first determine which category your integration fits into:

- **Generic Protocol** (`ProtocolABC`):  
  Use this for most DeFi protocols that do not fit a more specific category. This is the most flexible base class and is suitable for lending, borrowing, or any protocol with custom logic.  
  See: `Adding a New Lending/Borrowing or Generic Protocol`_

- **Staking Pool** (`StakingPoolABC`):  
  Use this for protocols where users stake tokens to earn rewards, and the pool may have multiple tokens or custom reward logic.  
  See: `Adding a New Staking Pool`_

- **Single-Token Staking Pool** (`SingleTokenStakingPoolABC`):  
  Use this for staking pools that only accept a single token and have a straightforward staking/reward structure.  
  See: `Adding a New Single-Token Staking Pool`_

- **Protocol with Staking** (`ProtocolWithStakingABC`):  
  Use this if your protocol combines lending/borrowing or other DeFi features with an integrated staking component.  
  See: `Adding a Protocol with Staking`_

If you are unsure, start with `ProtocolABC` for lending/borrowing or custom protocols, and use the staking pool base classes for staking integrations. See the subsections below for details and examples.

Adding a New Staking Pool
-------------------------

Subclass `StakingPoolABC` from `eth_portfolio/protocols/_base.py` for pools with multiple tokens or custom logic.

**Steps:**
1. Subclass `StakingPoolABC`.
2. Implement the `_balances` method to return a `TokenBalances` mapping for a given address and block.
3. Implement any required methods such as `contract`, `deploy_block`, etc.
4. Register your pool in the appropriate protocol module.

**Example:**

.. code-block:: python

   from eth_portfolio.protocols._base import StakingPoolABC

   class MyStakingPool(StakingPoolABC):
       def contract(self):
           # Return a web3 contract instance for the staking pool
           ...

       async def _balances(self, address, block=None):
           # Query the staked balance and rewards for the address
           ...

See `eth_portfolio/protocols/liquity.py` for real-world examples.

Adding a New Single-Token Staking Pool
--------------------------------------

Subclass `SingleTokenStakingPoolABC` from `eth_portfolio/protocols/_base.py` for pools that only accept a single token.

**Example:**

.. code-block:: python

   from eth_portfolio.protocols._base import SingleTokenStakingPoolABC

   class MySingleTokenStakingPool(SingleTokenStakingPoolABC):
       def contract(self):
           ...

       async def _balances(self, address, block=None):
           ...

See `eth_portfolio/protocols/liquity.py` and `eth_portfolio/protocols/convex.py` for examples.

Adding a New Lending/Borrowing or Generic Protocol
--------------------------------------------------

Subclass `ProtocolABC` from `eth_portfolio/protocols/_base.py` for lending, borrowing, or other custom DeFi protocols.

**Steps:**
1. Subclass `ProtocolABC`.
2. Implement the `_balances` method to return a `TokenBalances` mapping, including supplied, borrowed, and reward tokens.
3. Register your protocol in the appropriate module.

**Example:**

.. code-block:: python

   from eth_portfolio.protocols._base import ProtocolABC

   class MyLendingProtocol(ProtocolABC):
       async def _balances(self, address, block=None):
           # Query supplied and borrowed balances for the address
           ...

See `eth_portfolio/protocols/dsr.py` and `eth_portfolio/protocols/lending/` for examples.

Adding a Protocol with Staking
------------------------------

If your protocol combines lending/borrowing with staking, subclass `ProtocolWithStakingABC` from `eth_portfolio/protocols/_base.py`.

**Example:**

.. code-block:: python

   from eth_portfolio.protocols._base import ProtocolWithStakingABC

   class MyProtocolWithStaking(ProtocolWithStakingABC):
       async def _balances(self, address, block=None):
           # Query balances and staking positions
           ...

See `eth_portfolio/protocols/convex.py` for an example.

Best Practices and Tips
-----------------------

- **Use Async Methods:** All balance queries should be asynchronous for performance.
- **Handle Edge Cases:** Account for protocol-specific quirks, such as non-standard tokens or special reward logic.
- **Testing:** Add tests for your protocol to ensure correctness and compatibility.
- **Documentation:** Document your protocol’s behavior and any configuration requirements.

References
----------

- Abstract base classes: `eth_portfolio/protocols/_base.py`
- Example staking pools: `eth_portfolio/protocols/liquity.py`, `eth_portfolio/protocols/convex.py`
- Example lending protocols: `eth_portfolio/protocols/dsr.py`, `eth_portfolio/protocols/lending/`
- Protocol registration: `eth_portfolio/protocols/__init__.py`
