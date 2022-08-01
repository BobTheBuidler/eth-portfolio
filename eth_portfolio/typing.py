

from decimal import Decimal
from typing import Dict, Literal
from y.datatypes import Address


Protocol = str
Token = Address

BalanceKey = Literal["balance", "usd value"]
TokenBalanceDetails = Dict[BalanceKey, Decimal]

StakedTokenBalances = Dict[Protocol, Dict[Token, TokenBalanceDetails]]

# these are flexible
WalletBalanceDetails = Dict[Address, TokenBalanceDetails]
PortfolioBalanceDetails = Dict[Address, WalletBalanceDetails]