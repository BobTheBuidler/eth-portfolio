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
