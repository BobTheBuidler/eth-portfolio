

import abc
from dataclasses import dataclass, field
from decimal import Decimal
from typing import (Any, DefaultDict, Dict, Iterable, Literal, Optional, Tuple,
                    TypedDict, TypeVar, Union)

from brownie import convert
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


class ChecksumAddressDict(dict):
    """
    A dict that maps addresses to PortfolioAddress objects.
    Will automatically checksum your provided address key when setting and getting.
    """
    def __init__(self):
        super().__init__()
        self.__dict__ = self
    
    def __getitem__(self, key: Address) -> Any:
        return super().__getitem__(convert.to_address(key))
    
    def __setitem__(self, key: Address, value: Any) -> None:
        return super().__setitem__(convert.to_address(key), value)

class _SummableNonNumeric(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def __add__(self: _T, other: Union[_T, Literal[0]]) -> _T:
        ...
    def __radd__(self: _T, other: Union[_T, Literal[0]]) -> _T:
        if other == 0:
            return self
        return self.__add__(other)  # type: ignore


@dataclass
class _BalanceItem(Dict[Literal["balance", "usd_value"], Decimal], _SummableNonNumeric):
    balance: Decimal = field(default=Decimal())
    usd_value: Decimal = field(default=Decimal())
    
    def __post_init__(self):
        """ This just supports legacy code that uses key lookup and will be removed. """
        self['balance'] = self.balance
        self['usd_value'] = self.usd_value

    def __repr__(self) -> str:
        return f"_BalanceItem{str(dict(self))}"
    
    def __add__(self, other: Union['_BalanceItem', Literal[0]]) -> '_BalanceItem':
        """ It is on you to ensure the two BalanceItems are for the same token. """
        assert isinstance(other, _BalanceItem), f"{other} is not a BalanceItem"
        try:
            return _BalanceItem(self['balance'] + other['balance'], self['usd_value'] + other['usd_value'])
        except:
            raise ValueError(f"Cannot add {self} and {other}")
    
    def __sub__(self, other: Union['_BalanceItem', Literal[0]]) -> '_BalanceItem':
        """ It is on you to ensure the two BalanceItems are for the same token. """
        assert isinstance(other, _BalanceItem), f"{other} is not a BalanceItem"
        try:
            return _BalanceItem(self['balance'] - other['balance'], self['usd_value'] - other['usd_value'])
        except:
            raise ValueError(f"Cannot subtract {self} and {other}")
    
    @property
    def usd(self) -> Decimal:
        ''' An alias for usd_value. ''' 
        return self.usd_value


_TBInput = Union[Dict[Address, _BalanceItem], Iterable[Tuple[Address, _BalanceItem]]]

class TokenBalances(DefaultDict[TokenAddress, _BalanceItem], ChecksumAddressDict, _SummableNonNumeric):
    def __init__(self, seed: Optional[_TBInput] = None) -> None:
        super().__init__(_BalanceItem)
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()
        if isinstance(seed, Iterable):
            for token, balance in seed:
                self[token] += balance
        else:
            raise TypeError(f"{seed} is not a valid input for TokenBalances")
    
    def sum_usd(self) -> Decimal:
        return Decimal(sum(balance.usd for balance in self.values()))

    def __repr__(self) -> str:
        return f"TokenBalances{str(dict(self))}"
    
    def __add__(self, other: Union['TokenBalances', Literal[0]]) -> 'TokenBalances':
        assert isinstance(other, TokenBalances), f"{other} is not a TokenBalances object"
        # NOTE We need a new object to avoid mutating the inputs
        if len(self) == 0:
            return TokenBalances(other)
        elif len(other) == 0:
            return TokenBalances(self)
        combined: TokenBalances = TokenBalances()
        for token, balance in self.items():
            combined[token] += balance
        for token, balance in other.items():
            combined[token] += balance
        return combined
    
    def __sub__(self, other: Union['TokenBalances', Literal[0]]) -> 'TokenBalances':
        assert isinstance(other, TokenBalances), f"{other} is not a TokenBalances object"
        # We need a new object to avoid mutating the inputs
        subtracted: TokenBalances = TokenBalances(self)
        for token, balance in other.items():
            subtracted[token] -= balance
        return subtracted

CategoryLabel = Literal["assets", "debt"]

_CBInput = Union[Dict[CategoryLabel, TokenBalances], Iterable[Tuple[CategoryLabel, TokenBalances]]]

class CategoryBalances(DefaultDict[CategoryLabel, TokenBalances], _SummableNonNumeric):
    def __init__(self, seed: Optional[_CBInput] = None) -> None:
        super().__init__(TokenBalances)
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()
        if isinstance(seed, Iterable):
            for category, balances in seed:  # type: ignore
                self[category] += balances
        else:
            raise TypeError(f"{seed} is not a valid input for CategoryBalances")
        
    def sum_usd(self) -> Decimal:
        return Decimal(sum(balances.sum_usd() for balances in self.values()))
    
    def __repr__(self) -> str:
        return f"CategoryBalances{str(dict(self))}"

    def __add__(self, other: Union['CategoryBalances', Literal[0]]) -> 'CategoryBalances':
        assert isinstance(other, CategoryBalances), f"{other} is not a CategoryBalances object"
        # NOTE We need a new object to avoid mutating the inputs
        if len(self) == 0:
            return CategoryBalances(other)
        elif len(other) == 0:
            return CategoryBalances(self)
        combined: CategoryBalances = CategoryBalances()
        for category, balances in self.items():
            combined[category] += balances
        for category, balances in other.items():
            combined[category] += balances
        return combined
    
    def __sub__(self, other: Union['CategoryBalances', Literal[0]]) -> 'CategoryBalances':
        assert isinstance(other, CategoryBalances), f"{other} is not a CategoryBalances object"
        # We need a new object to avoid mutating the inputs
        subtracted: CategoryBalances = CategoryBalances(self)
        for category, balances in other.items():
            subtracted[category] -= balances
        return subtracted


RemoteTokenBalances = Dict[ProtocolLabel, TokenBalances]

# these are flexible for now until structure ossifies
WalletBalances = Dict[Address, CategoryBalances]
PortfolioBalances = Dict[Address, WalletBalances]
