

from decimal import Decimal
from typing import Dict, Iterable, Optional, TypedDict, TypeVar, Union

from y.datatypes import Address, Block

_T = TypeVar('_T')

TransactionData = Dict # TODO define TypedDict
InternalTransferData = Dict # TODO define TypedDict

TokenTransferData = TypedDict('TokenTransferData', {
    'chainId': int,
    'blockNumber': Block,
    'transactionIndex': int,
    'hash': str,
    'log_index': int,
    'token': Optional[str],
    'token_address': Address,
    'from': Address,
    'to': Address,
    'value': Decimal,
})

ProtocolLabel = str

Addresses = Union[Address, Iterable[Address]]
TokenAddress = TypeVar('TokenAddress', bound=Address)

BalanceItem = TypedDict('BalanceItem', {'balance': Decimal, 'usd value': Decimal})
TokenBalances = Dict[TokenAddress, BalanceItem]
CategoryBalances = Dict[str, TokenBalances]
StakedTokenBalances = Dict[ProtocolLabel, Dict[TokenAddress, BalanceItem]]

# these are flexible for now until structure ossifies
WalletBalances = Dict[Address, CategoryBalances]
PortfolioBalances = Dict[Address, WalletBalances]
