
from typing import Callable

import pytest
from eth_portfolio.address import PortfolioAddress
from eth_portfolio.lending import Lending
from eth_portfolio.lending.compound import Compound
from eth_portfolio.lending.maker import Maker
from eth_portfolio.portfolio import Ledger, Portfolio

classes = [Portfolio, Ledger, PortfolioAddress, Lending, Compound, Maker]


@pytest.mark.parametrize('cls', classes)
def test_sync_async_completeness(cls):
    for thing in cls.__dict__:
        if isinstance(getattr(cls, thing), Callable):
            if thing in ["__init__","__str__","__repr__","__eq__","__hash__","__getitem__"]:
                continue
            # we don't need to use async to feth logs, multithreading works just fine
            elif thing in ["watch_token_transfers", "load_token_transfers", "import_token_transfers", "list_tokens_at_block"]:
                continue
            elif thing.endswith("_async"):
                assert thing[:-6] in cls.__dict__
            else:
                assert thing + "_async" in cls.__dict__
