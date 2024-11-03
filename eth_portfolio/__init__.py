import a_sync._smart

a_sync._smart.set_smart_task_factory()


from eth_portfolio.portfolio import Portfolio, portfolio

# make sure we init the extended db before we init ypm somewhere
from eth_portfolio._db import utils
from eth_portfolio._shitcoins import SHITCOINS

__all__ = [
    "Portfolio",
    "portfolio",
    "SHITCOINS",
]
