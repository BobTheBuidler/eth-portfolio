
import abc
from decimal import Decimal
from functools import cached_property
from typing import (Any, DefaultDict, Dict, Iterable, List, Literal, Optional,
                    Tuple, TypedDict, TypeVar, Union)

from checksum_dict import DefaultChecksumDict
from pandas import DataFrame, concat
from typing_extensions import ParamSpec, Self
from y.datatypes import Address, Block

from eth_portfolio.structs import _DictStruct

_T = TypeVar('_T')
_I = TypeVar('_I')
_P = ParamSpec('_P')

class Balance(_DictStruct):
    """
    Represents the balance of a single token, including its token amount and equivalent USD value.

    Example:
        >>> balance1 = Balance(Decimal('100'), Decimal('2000'))
        >>> balance2 = Balance(Decimal('50'), Decimal('1000'))
        >>> combined_balance = balance1 + balance2
        >>> combined_balance.balance
        Decimal('150')
        >>> combined_balance.usd_value
        Decimal('3000')
    """
    balance: Decimal = Decimal(0)
    """
    The amount of the token.
    """
    usd_value: Decimal = Decimal(0)
    """
    The USD equivalent value of the token amount.
    """
    
    @property
    def usd(self) -> Decimal:
        """ 
        An alias for `usd_value`. Returns the USD value of the token amount. 
        """
        return self.usd_value
    
    def __add__(self, other: 'Balance') -> 'Balance':
        """
        Adds two :class:`~eth_portfolio.typing.Balance` objects together. It is the user's responsibility to ensure that the two 
        :class:`~eth_portfolio.typing.Balance` instances represent the same token.

        Args:
            other: Another :class:`~eth_portfolio.typing.Balance` object.

        Returns:
            A new :class:`~eth_portfolio.typing.Balance` object with the summed values.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.Balance`.
            Exception: If any other error occurs during addition.

        Example:
            >>> balance1 = Balance(Decimal('100'), Decimal('2000'))
            >>> balance2 = Balance(Decimal('50'), Decimal('1000'))
            >>> combined_balance = balance1 + balance2
            >>> combined_balance.balance
            Decimal('150')
            >>> combined_balance.usd_value
            Decimal('3000')
        """
        if not isinstance(other, Balance):
            raise TypeError(f"{other} is not a `Balance` object")
        try:
            return Balance(balance=self.balance + other.balance, usd_value=self.usd_value + other.usd_value)
        except Exception as e:
            raise e.__class__(f"Cannot add {self} and {other}: {e}") from e
    
    def __radd__(self, other: Union['Balance', Literal[0]]) -> 'Balance':
        """
        Supports the addition operation from the right side to enable use of `sum`.

        Args:
            other: Another :class:`~eth_portfolio.typing.Balance` object or zero.

        Returns:
            A new :class:`~eth_portfolio.typing.Balance` object with the summed values.

        Example:
            >>> balance = Balance(Decimal('100'), Decimal('2000'))
            >>> sum_balance = sum([balance, Balance()])
            >>> sum_balance.balance
            Decimal('100')
        """
        if other == 0:
            return self
        return self.__add__(other)  # type: ignore
    
    def __sub__(self, other: 'Balance') -> 'Balance':
        """
        Subtracts one :class:`~eth_portfolio.typing.Balance` object from another. It is the user's responsibility to ensure that 
        the two :class:`~eth_portfolio.typing.Balance` instances represent the same token.

        Args:
            other: Another :class:`~eth_portfolio.typing.Balance` object.

        Returns:
            A new :class:`~eth_portfolio.typing.Balance` object with the subtracted values.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.Balance`.
            Exception: If any other error occurs during subtraction.

        Example:
            >>> balance1 = Balance(Decimal('100'), Decimal('2000'))
            >>> balance2 = Balance(Decimal('50'), Decimal('1000'))
            >>> result_balance = balance1 - balance2
            >>> result_balance.balance
            Decimal('50')
        """
        if not isinstance(other, Balance):
            raise TypeError(f"{other} is not a `Balance` object.")
        try:
            return Balance(balance=self.balance - other.balance, usd_value=self.usd_value - other.usd_value)
        except Exception as e:
            raise e.__class__(f"Cannot subtract {self} and {other}: {e}") from e
    
    def __bool__(self) -> bool:
        """
        Evaluates the truth value of the :class:`~eth_portfolio.typing.Balance` object.

        Returns:
            True if either the balance or the USD value is non-zero, otherwise False.

        Example:
            >>> balance = Balance(Decimal('0'), Decimal('0'))
            >>> bool(balance)
            False
        """
        return self.balance != 0 or self.usd_value != 0


ProtocolLabel = str

Addresses = Union[Address, Iterable[Address]]
TokenAddress = TypeVar('TokenAddress', bound=Address)


class _SummableNonNumeric(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def __add__(self, other: Self) -> Self:
        """
        Abstract method for adding two objects of the same type.

        Args:
            other: Another object of the same type.

        Returns:
            A new object representing the sum.
        """

    def __radd__(self, other: Union[Self, Literal[0]]) -> Self:
        """
        Supports the addition operation from the right side to enable use of `sum`.

        Args:
            other: Another object of the same type or zero.

        Returns:
            A new object representing the sum.

        Example:
            >>> class Summable(_SummableNonNumeric):
            ...     def __init__(self, value: int):
            ...         self.value = value
            ...     def __add__(self, other):
            ...         return Summable(self.value + other.value)
            ...     def __radd__(self, other):
            ...         return self.__add__(other)
            >>> a = Summable(10)
            >>> b = Summable(20)
            >>> sum_result = a + b
            >>> sum_result.value
            30
        """
        if other == 0:
            return self
        return self.__add__(other)  # type: ignore


_TBSeed = Union[Dict[Address, Balance], Iterable[Tuple[Address, Balance]]]

class TokenBalances(DefaultChecksumDict[Balance], _SummableNonNumeric):
    """
    A specialized defaultdict subclass made for holding a mapping of ``token -> balance``

    Token addresses are checksummed automatically when adding items to the dict, and the default value for a token not present is an empty :class:`~eth_portfolio.typing.Balance` object.
    """
    def __init__(self, seed: Optional[_TBSeed] = None) -> None:
        super().__init__(Balance)
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()
        if isinstance(seed, Iterable):
            for token, balance in seed:
                self[token] += balance
        else:
            raise TypeError(f"{seed} is not a valid input for TokenBalances")
    
    def __setitem__(self, key, value):
        if not isinstance(value, Balance):
            raise TypeError(f'value must be a `Balance` object. You passed {value}') from None
        return super().__setitem__(key, value)
    
    @property
    def dataframe(self) -> DataFrame:
        df = DataFrame({token: {**balance} for token, balance in self.items()}).T
        df.rename(columns = {'index': 'token'}, inplace = True)
        df.reset_index(inplace=True)
        return df
    
    def sum_usd(self) -> Decimal:
        return Decimal(sum(balance.usd for balance in self.values()))
    
    def __bool__(self) -> bool:
        return any(self.values())

    def __repr__(self) -> str:
        return f"TokenBalances{str(dict(self))}"
    
    def __add__(self, other: 'TokenBalances') -> 'TokenBalances':
        if not isinstance(other, TokenBalances):
            raise TypeError(f"{other} is not a TokenBalances object")
        # NOTE We need a new object to avoid mutating the inputs
        combined: TokenBalances = TokenBalances()
        for token, balance in self.items():
            if balance:
                combined._setitem_nochecksum(token, Balance(balance.balance, balance.usd_value))
        for token, balance in other.items():
            if balance:
                if token in combined:
                    combined._setitem_nochecksum(token, combined._getitem_nochecksum(token) + balance)
                else:
                    combined._setitem_nochecksum(token, Balance(balance.balance, balance.usd_value))
        return combined
    
    def __sub__(self, other: 'TokenBalances') -> 'TokenBalances':
        if not isinstance(other, TokenBalances):
            raise TypeError(f"{other} is not a TokenBalances object")
        # We need a new object to avoid mutating the inputs
        subtracted: TokenBalances = TokenBalances(self)
        for token, balance in other.items():
            subtracted[token] -= balance
        for token, balance in dict(subtracted).items():
            if not balance:
                del subtracted[token]
        return subtracted


_RTBSeed = Dict[ProtocolLabel, TokenBalances]

class RemoteTokenBalances(DefaultDict[ProtocolLabel, TokenBalances], _SummableNonNumeric):
    def __init__(self, seed: Optional[_RTBSeed] = None) -> None:
        super().__init__(TokenBalances)
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()  # type: ignore [assignment]
        if isinstance(seed, Iterable):
            for remote, token_balances in seed:  # type: ignore [misc]
                self[remote] += token_balances  # type: ignore [has-type]
        else:
            raise TypeError(f"{seed} is not a valid input for TokenBalances")
    
    def __setitem__(self, key, value):
        if not isinstance(value, TokenBalances):
            raise TypeError(f'value must be a `TokenBalances` object. You passed {value}') from None
        return super().__setitem__(key, value)
    
    @property
    def dataframe(self) -> DataFrame:
        dfs: List[DataFrame] = []
        for protocol, balances in self.items():
            df = balances.dataframe
            df['protocol'] = protocol
            dfs.append(df)
        if dfs:
            return concat(dfs).reset_index(drop=True)
        else:
            return DataFrame()

    def sum_usd(self) -> Decimal:
        return Decimal(sum(balance.sum_usd() for balance in self.values()))
    
    def __bool__(self) -> bool:
        return any(self.values())

    def __repr__(self) -> str:
        return f"RemoteTokenBalances{str(dict(self))}"
    
    def __add__(self, other: 'RemoteTokenBalances') -> 'RemoteTokenBalances':
        if not isinstance(other, RemoteTokenBalances):
            raise TypeError(f"{other} is not a RemoteTokenBalances object")
        # NOTE We need a new object to avoid mutating the inputs
        combined: RemoteTokenBalances = RemoteTokenBalances()
        for protocol, token_balances in self.items():
            if token_balances:
                combined[protocol] += token_balances
        for protocol, token_balances in other.items():
            if token_balances:
                combined[protocol] += token_balances
        return combined
    
    def __sub__(self, other: 'RemoteTokenBalances') -> 'RemoteTokenBalances':
        if not isinstance(other, RemoteTokenBalances):
            raise TypeError(f"{other} is not a RemoteTokenBalances object")
        # We need a new object to avoid mutating the inputs
        subtracted: RemoteTokenBalances = RemoteTokenBalances(self)
        for protocol, token_balances in other.items():
            subtracted[protocol] -= token_balances
        for protocol, token_balances in dict(subtracted).items():
            if not token_balances:
                del subtracted[protocol]
        return subtracted


CategoryLabel = Literal["assets", "debt", "external"]

_WBSeed = Union[Dict[CategoryLabel, TokenBalances], Iterable[Tuple[CategoryLabel, TokenBalances]]]

class WalletBalances(Dict[CategoryLabel, Union[TokenBalances, RemoteTokenBalances]], _SummableNonNumeric):
    """
    Keyed: ``category -> token -> balance``
    """
    def __init__(self, seed: Optional[Union["WalletBalances", _WBSeed]] = None) -> None:
        super().__init__()
        self._keys = 'assets', 'debt', 'external'
        self['assets'] = TokenBalances()
        self['debt'] = RemoteTokenBalances()
        self['external'] = RemoteTokenBalances()

        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()  # type: ignore
        if not isinstance(seed, Iterable):
            raise TypeError(f"{seed} is not a valid input for WalletBalances")
        for key, balances in seed:  # type: ignore
            self.__validateitem(key, balances)
            self[key] += balances            
        
    @property
    def assets(self) -> TokenBalances:
        return self['assets']  # type: ignore
    
    @property
    def debt(self) -> RemoteTokenBalances:
        return self['debt']
    
    @property
    def external(self) -> RemoteTokenBalances:
        return self['external']
    
    @property
    def dataframe(self) -> DataFrame:
        dfs: List[DataFrame] = []
        for category, category_bals in self.items():
            df = category_bals.dataframe
            df['category'] = category
            dfs.append(df)
        if dfs:
            return concat(dfs).reset_index(drop=True)
        else:
            return DataFrame()
    
    def sum_usd(self) -> Decimal:
        return self.assets.sum_usd() - self.debt.sum_usd() + self.external.sum_usd()
    
    def __bool__(self) -> bool:
        return any(self.values())
    
    def __repr__(self) -> str:
        return f"WalletBalances {str(dict(self))}"

    def __add__(self, other: 'WalletBalances') -> 'WalletBalances':
        if not isinstance(other, WalletBalances):
            raise TypeError(f"{other} is not a WalletBalances object")
        # NOTE We need a new object to avoid mutating the inputs
        combined: WalletBalances = WalletBalances()
        for category, balances in self.items():
            if balances:
                combined[category] += balances
        for category, balances in other.items():
            if balances:
                combined[category] += balances
        return combined
    
    def __sub__(self, other: 'WalletBalances') -> 'WalletBalances':
        if not isinstance(other, WalletBalances):
            raise TypeError(f"{other} is not a WalletBalances object")
        # We need a new object to avoid mutating the inputs
        subtracted: WalletBalances = WalletBalances(self)
        for category, balances in other.items():
            subtracted[category] -= balances  # type: ignore
        for category, balances in dict(subtracted).items():
            if not balances:
                del subtracted[category]
        return subtracted
    
    def __getitem__(self, key: CategoryLabel) -> Union[TokenBalances, RemoteTokenBalances]:
        self.__validatekey(key)
        return super().__getitem__(key)

    def __setitem__(self, key: CategoryLabel, value: Union[TokenBalances, RemoteTokenBalances]) -> None:
        self.__validateitem(key, value)
        return super().__setitem__(key, value)
    
    def __validatekey(self, key: CategoryLabel) -> None:
        if key not in self._keys:
            raise KeyError(f"{key} is not a valid key for WalletBalances. Valid keys are: {self._keys}")

    def __validateitem(self, key: CategoryLabel, item: Any) -> None:
        self.__validatekey(key)
        if key == 'assets':
            if not isinstance(item, TokenBalances):
                raise TypeError(f'{item} is not a valid value for "{key}". Must be a TokenBalances object.')
        elif key in ['debt', 'external']:
            if not isinstance(item, RemoteTokenBalances):
                raise TypeError(f'{item} is not a valid value for "{key}". Must be a RemoteTokenBalances object.')
        else:
            raise NotImplementedError(f'key {key} is not yet implemented.')


_PBSeed = Union[Dict[Address, WalletBalances], Iterable[Tuple[Address, WalletBalances]]]

class PortfolioBalances(DefaultChecksumDict[WalletBalances], _SummableNonNumeric):
    """
    Keyed: ``wallet -> category -> token -> balance``
    """ 
    def __init__(self, seed: Optional[_PBSeed] = None) -> None:
        super().__init__(WalletBalances)
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()
        if isinstance(seed, Iterable):
            for wallet, balances in seed:
                self[wallet] += balances
        else:
            raise TypeError(f"{seed} is not a valid input for PortfolioBalances")
    
    def __setitem__(self, key, value):
        if not isinstance(value, WalletBalances):
            raise TypeError(f'value must be a `WalletBalances` object. You passed {value}') from None
        return super().__setitem__(key, value)
    
    @property
    def dataframe(self) -> DataFrame:
        dfs: List[DataFrame] = []
        for wallet, balances in self.items():
            df = balances.dataframe
            df['wallet'] = wallet
            dfs.append(df)
        if dfs:
            return concat(dfs).reset_index(drop=True)
        else:
            return DataFrame()
    
    def sum_usd(self) -> Decimal:
        return sum(balances.sum_usd() for balances in self.values())  # type: ignore
    
    @cached_property
    def inverted(self) -> "PortfolioBalancesByCategory":
        inverted = PortfolioBalancesByCategory()
        for wallet, wbalances in self.items():
            for label, tbalances in wbalances.items():
                if tbalances:
                    inverted[label][wallet] += tbalances
        return inverted
    
    def __bool__(self) -> bool:
        return any(self.values())

    def __repr__(self) -> str:
        return f"WalletBalances{str(dict(self))}"
    
    def __add__(self, other: 'PortfolioBalances') -> 'PortfolioBalances':
        if not isinstance(other, PortfolioBalances):
            raise TypeError(f"{other} is not a WalletBalances object")
        # NOTE We need a new object to avoid mutating the inputs
        combined: PortfolioBalances = PortfolioBalances()
        for wallet, balance in self.items():
            if balance:
                combined._setitem_nochecksum(wallet, combined._getitem_nochecksum(wallet) + balance)
        for wallet, balance in other.items():
            if balance:
                combined._setitem_nochecksum(wallet, combined._getitem_nochecksum(wallet) + balance)
        return combined
    
    def __sub__(self, other: 'PortfolioBalances') -> 'PortfolioBalances':
        if not isinstance(other, PortfolioBalances):
            raise TypeError(f"{other} is not a WalletBalances object")
        # We need a new object to avoid mutating the inputs
        subtracted: PortfolioBalances = PortfolioBalances(self)
        for protocol, balances in other.items():
            subtracted[protocol] -= balances
        for protocol, balances in subtracted.items():
            if not balances:
                del subtracted[protocol]
        return subtracted


_WTBInput = Union[Dict[Address, TokenBalances], Iterable[Tuple[Address, TokenBalances]]]

class WalletBalancesRaw(DefaultChecksumDict[TokenBalances], _SummableNonNumeric):
    """
    Since PortfolioBalances key lookup is:    ``wallet   -> category -> token    -> balance``
    and WalletBalances key lookup is:         ``category -> token    -> balance``
    We need a new structure for key pattern:  ``wallet   -> token    -> balance``

    WalletBalancesRaw fills this role.
    """ 
    def __init__(self, seed: Optional[_WTBInput] = None) -> None:
        super().__init__(TokenBalances)
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()
        if isinstance(seed, Iterable):
            for wallet, balances in seed:
                self[wallet] += balances
        else:
            raise TypeError(f"{seed} is not a valid input for WalletBalancesRaw")
    
    def __bool__(self) -> bool:
        return any(self.values())

    def __repr__(self) -> str:
        return f"WalletBalances{str(dict(self))}"
    
    def __add__(self, other: 'WalletBalancesRaw') -> 'WalletBalancesRaw':
        if not isinstance(other, WalletBalancesRaw):
            raise TypeError(f"{other} is not a WalletBalancesRaw object")
        # NOTE We need a new object to avoid mutating the inputs
        combined: WalletBalancesRaw = WalletBalancesRaw()
        for wallet, balance in self.items():
            if balance:
                combined._setitem_nochecksum(wallet, combined._getitem_nochecksum(wallet) + balance)
        for wallet, balance in other.items():
            if balance:
                combined._setitem_nochecksum(wallet, combined._getitem_nochecksum(wallet) + balance)
        return combined
    
    def __sub__(self, other: 'WalletBalancesRaw') -> 'WalletBalancesRaw':
        if not isinstance(other, WalletBalancesRaw):
            raise TypeError(f"{other} is not a WalletBalancesRaw object")
        # We need a new object to avoid mutating the inputs
        subtracted: WalletBalancesRaw = WalletBalancesRaw(self)
        for wallet, balances in other.items():
            if balances:
                subtracted[wallet] -= balances
        for wallet, balances in subtracted.items():
            if not balances:
                del subtracted[wallet]
        return subtracted

_CBInput = Union[Dict[CategoryLabel, WalletBalancesRaw], Iterable[Tuple[CategoryLabel, WalletBalancesRaw]]]

class PortfolioBalancesByCategory(DefaultDict[CategoryLabel, WalletBalancesRaw], _SummableNonNumeric):
    """
    Keyed: ``category -> wallet -> token -> balance``
    """ 
    def __init__(self, seed: Optional[_CBInput] = None) -> None:
        super().__init__(WalletBalancesRaw)
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()
        if isinstance(seed, Iterable):
            for label, balances in seed:  # type: ignore
                self[label] += balances
        else:
            raise TypeError(f"{seed} is not a valid input for PortfolioBalancesByCategory")

    @property
    def assets(self) -> WalletBalancesRaw:
        return self['assets']
    
    @property
    def debt(self) -> WalletBalancesRaw:
        return self['debt']
    
    def invert(self) -> "PortfolioBalances":
        inverted = PortfolioBalances()
        for label, wtbalances in self.items():
            for wallet, tbalances in wtbalances.items():
                if tbalances:
                    inverted[wallet][label] += tbalances
        return inverted
    
    def __bool__(self) -> bool:
        return any(self.values())

    def __repr__(self) -> str:
        return f"PortfolioBalancesByCategory{str(dict(self))}"
    
    def __add__(self, other: 'PortfolioBalancesByCategory') -> 'PortfolioBalancesByCategory':
        if not isinstance(other, PortfolioBalancesByCategory):
            raise TypeError(f"{other} is not a PortfolioBalancesByCategory object")
        # NOTE We need a new object to avoid mutating the inputs
        combined: PortfolioBalancesByCategory = PortfolioBalancesByCategory()
        for protocol, balances in self.items():
            if balances:
                combined[protocol] += balances
        for protocol, balances in other.items():
            if balances:
                combined[protocol] += balances
        return combined
    
    def __sub__(self, other: 'PortfolioBalancesByCategory') -> 'PortfolioBalancesByCategory':
        if not isinstance(other, PortfolioBalancesByCategory):
            raise TypeError(f"{other} is not a PortfolioBalancesByCategory object")
        # We need a new object to avoid mutating the inputs
        subtracted: PortfolioBalancesByCategory = PortfolioBalancesByCategory(self)
        for protocol, balances in other.items():
            subtracted[protocol] -= balances
        for protocol, balances in subtracted.items():
            if not balances:
                del subtracted[protocol]
        return subtracted
