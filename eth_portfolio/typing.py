

from typing import Dict, Literal
from y.datatypes import Address

TokenBalanceDetails = Dict[Literal["balance", "usd value"], float]
WalletBalanceDetails = Dict[Address, TokenBalanceDetails]
PortfolioBalanceDetails = Dict[Address, WalletBalanceDetails]