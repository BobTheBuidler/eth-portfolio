import os
import sys

from brownie import network

sys.path.insert(0, os.path.abspath("."))

try:
    brownie_network = os.environ["PYTEST_NETWORK"]
except KeyError:
    raise ValueError(
        "Please set the PYTEST_NETWORK environment variable to the name of the brownie network you want to use for testing."
    )

if not network.is_connected():
    network.connect(brownie_network)

"""
This module configures the testing environment for the project by ensuring
that the Brownie network is connected using the specified network. It also
modifies the system path to include the current directory, allowing for
importing modules from the project root.

Environment Variables:
    PYTEST_NETWORK: The name of the Brownie network to use for testing. This
    environment variable must be set before running the tests.

Raises:
    ValueError: If the PYTEST_NETWORK environment variable is not set.

Examples:
    To set the PYTEST_NETWORK environment variable and run tests:

    .. code-block:: bash

        export PYTEST_NETWORK=mainnet-fork
        pytest

    This will connect to the specified Brownie network and run the tests.

See Also:
    - :mod:`brownie.network`: For more information on managing network connections with Brownie.
    - :mod:`os`: For more information on interacting with the operating system.
    - :mod:`sys`: For more information on the system-specific parameters and functions.
"""
