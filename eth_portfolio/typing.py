"""
This module defines a set of classes to represent and manipulate various levels of balance structures
within an Ethereum portfolio. The focus of these classes is on reading, aggregating, and summarizing
balances, including the value in both tokens and their equivalent in USD.

The main classes and their purposes are as follows:

- :class:`~eth_portfolio.typing.Balance`: Represents the balance of a single token, including its token amount and equivalent USD value.
- :class:`~eth_portfolio.typing.TokenBalances`: Manages a collection of :class:`~eth_portfolio.typing.Balance` objects for multiple tokens, providing operations
  such as summing balances across tokens.
- :class:`~eth_portfolio.typing.RemoteTokenBalances`: Extends :class:`~eth_portfolio.typing.TokenBalances` to manage balances across different protocols, enabling
  aggregation and analysis of balances by protocol.
- :class:`~eth_portfolio.typing.WalletBalances`: Organizes token balances into categories such as assets, debts, and external balances
  for a single wallet. It combines :class:`~eth_portfolio.typing.TokenBalances` and :class:`~eth_portfolio.typing.RemoteTokenBalances` to provide a complete view
  of a wallet's balances.
- :class:`~eth_portfolio.typing.PortfolioBalances`: Aggregates :class:`~eth_portfolio.typing.WalletBalances` for multiple wallets, providing operations to sum
  balances across an entire portfolio.
- :class:`~eth_portfolio.typing.WalletBalancesRaw`: Similar to :class:`~eth_portfolio.typing.WalletBalances`, but with a key structure optimized for accessing
  balances directly by wallet and token.
- :class:`~eth_portfolio.typing.PortfolioBalancesByCategory`: Provides an inverted view of :class:`~eth_portfolio.typing.PortfolioBalances`, allowing access
  by category first, then by wallet and token.

These classes are designed for efficient parsing, manipulation, and summarization of portfolio data,
without managing or altering any underlying assets.
"""

from functools import cached_property
from typing import (
    Any,
    Callable,
    DefaultDict,
    Dict,
    Iterable,
    List,
    Literal,
    Optional,
    Tuple,
    TypedDict,
    TypeVar,
    Union,
    final,
)

from checksum_dict import DefaultChecksumDict
from dictstruct import DictStruct
from pandas import DataFrame, concat
from typing_extensions import ParamSpec, Self
from y.datatypes import Address, Block

from eth_portfolio._decimal import Decimal


_T = TypeVar("_T")
_I = TypeVar("_I")
_P = ParamSpec("_P")

Fn = Callable[_P, _T]


@final
class Balance(
    DictStruct, frozen=True, omit_defaults=True, repr_omit_defaults=True, forbid_unknown_fields=True
):
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

    token: Address = None
    """
    The token the balance is of, if known.
    """

    block: Block = None
    """
    The block from which the balance was taken, if known.
    """

    @property
    def usd(self) -> Decimal:
        """
        An alias for `usd_value`. Returns the USD value of the token amount.
        """
        return self.usd_value

    def __add__(self, other: "Balance") -> "Balance":
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
        if self.token != other.token:
            raise ValueError(
                f"These Balance objects represent balances of different tokens ({self.token} and {other.token})"
            )
        if self.block != other.block:
            raise ValueError(
                f"These Balance objects represent balances from different blocks ({self.block} and {other.block})"
            )
        try:
            return Balance(
                balance=self.balance + other.balance,
                usd_value=self.usd_value + other.usd_value,
                token=self.token,
                block=self.block,
            )
        except Exception as e:
            e.args = (f"Cannot add {self} and {other}: {e}", *e.args)
            raise

    def __radd__(self, other: Union["Balance", Literal[0]]) -> "Balance":
        """
        Supports the addition operation from the right side to enable use of `sum`.

        Args:
            other: Another :class:`~eth_portfolio.typing.Balance` object or zero.

        Returns:
            A new :class:`~eth_portfolio.typing.Balance` object with the summed values.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.Balance`.
            Exception: If any other error occurs during addition.

        Example:
            >>> balance = Balance(Decimal('100'), Decimal('2000'))
            >>> sum_balance = sum([balance, Balance()])
            >>> sum_balance.balance
            Decimal('100')
        """
        return self if other == 0 else self.__add__(other)  # type: ignore

    def __sub__(self, other: "Balance") -> "Balance":
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
        if self.token != other.token:
            raise ValueError(
                f"These Balance objects represent balances of different tokens ({self.token} and {other.token})"
            )
        if self.block != other.block:
            raise ValueError(
                f"These Balance objects represent balances from different blocks ({self.block} and {other.block})"
            )
        try:
            return Balance(
                balance=self.balance - other.balance,
                usd_value=self.usd_value - other.usd_value,
                token=self.token,
                block=self.block,
            )
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
TokenAddress = TypeVar("TokenAddress", bound=Address)


class _SummableNonNumericMixin:
    """
    Mixin class for non-numeric summable objects.

    This class provides an interface for objects that can be used with `sum` but are not necessarily numeric.
    """

    def __add__(self, other: Self) -> Self:
        """
        Abstract method for adding two objects of the same type.

        Args:
            other: Another object of the same type.

        Raises:
            NotImplementedError: If no `__add__` method was defined on the subclass.

        Returns:
            A new object representing the sum.
        """
        raise NotImplementedError

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
        return self if other == 0 else self.__add__(other)  # type: ignore


_TBSeed = Union[Dict[Address, Balance], Iterable[Tuple[Address, Balance]]]


class TokenBalances(DefaultChecksumDict[Balance], _SummableNonNumericMixin):
    """
    A specialized defaultdict subclass made for holding a mapping of ``token -> balance``.

    Manages a collection of :class:`~eth_portfolio.typing.Balance` objects for multiple tokens, allowing for operations
    such as summing balances across tokens.

    The class uses token addresses as keys and :class:`~eth_portfolio.typing.Balance` objects as values. It supports
    arithmetic operations like addition and subtraction of token balances.

    Token addresses are checksummed automatically when adding items to the dict, and the default value for a token not present is an empty :class:`~eth_portfolio.typing.Balance` object.

    Args:
        seed: An initial seed of token balances, either as a dictionary or an iterable of tuples.

    Example:
        >>> token_balances = TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})
        >>> token_balances['0x123'].balance
        Decimal('100')
    """

    def __init__(self, seed: Optional[_TBSeed] = None, *, block: Optional[int] = None) -> None:
        super().__init__(Balance)
        self.block = block
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()
        if not isinstance(seed, Iterable):
            raise TypeError(f"{seed} is not a valid input for TokenBalances")
        for token, balance in seed:  # type: ignore [misc]
            self[token] += balance

    def __getitem__(self, key) -> Balance:
        return super().__getitem__(key) if key in self else Balance(token=key, block=self.block)

    def __setitem__(self, key, value):
        """
        Sets the balance for a given token address.

        Args:
            key: The token address.
            value: The balance to set for the token.

        Raises:
            TypeError: If the value is not a :class:`~eth_portfolio.typing.Balance` object.

        Example:
            >>> token_balances = TokenBalances()
            >>> token_balances['0x123'] = Balance(Decimal('100'), Decimal('2000'))
            >>> token_balances['0x123'].balance
            Decimal('100')
        """
        if not isinstance(value, Balance):
            raise TypeError(f"value must be a `Balance` object. You passed {value}") from None
        return super().__setitem__(key, value)

    @property
    def dataframe(self) -> DataFrame:
        """
        Converts the token balances into a pandas DataFrame.

        Returns:
            A DataFrame representation of the token balances.
        """
        df = DataFrame(
            {
                token: {"balance": balance.balance, "usd_value": balance.usd_value}
                for token, balance in self.items()
            }
        ).T
        df.reset_index(inplace=True)
        df.rename(columns={"index": "token"}, inplace=True)
        return df

    def sum_usd(self) -> Decimal:
        """
        Sums the USD values of all token balances.

        Returns:
            The total USD value of all token balances.

        Example:
            >>> token_balances = TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})
            >>> total_usd = token_balances.sum_usd()
            >>> total_usd
            Decimal('2000')
        """
        return Decimal(sum(balance.usd for balance in self.values()))

    def __bool__(self) -> bool:
        """
        Evaluates the truth value of the :class:`~eth_portfolio.typing.TokenBalances` object.

        Returns:
            True if any token has a non-zero balance, otherwise False.

        Example:
            >>> token_balances = TokenBalances()
            >>> bool(token_balances)
            False
        """
        return any(self.values())

    def __repr__(self) -> str:
        """
        Returns a string representation of the :class:`~eth_portfolio.typing.TokenBalances` object.

        Returns:
            The string representation of the token balances.
        """
        return f"TokenBalances{dict(self)}"

    def __add__(self, other: "TokenBalances") -> "TokenBalances":
        """
        Adds another :class:`~eth_portfolio.typing.TokenBalances` object to this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.TokenBalances` object.

        Returns:
            A new :class:`~eth_portfolio.typing.TokenBalances` object with the combined balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.TokenBalances`.

        Example:
            >>> tb1 = TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})
            >>> tb2 = TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})
            >>> combined_tb = tb1 + tb2
            >>> combined_tb['0x123'].balance
            Decimal('150')
        """
        if not isinstance(other, TokenBalances):
            raise TypeError(f"{other} is not a TokenBalances object")
        if self.block != other.block:
            raise ValueError(
                f"These TokenBalances objects are not from the same block ({self.block} and {other.block})"
            )
        # NOTE We need a new object to avoid mutating the inputs
        combined: TokenBalances = TokenBalances(block=self.block)
        for token, balance in self.items():
            if balance:
                combined._setitem_nochecksum(
                    token,
                    Balance(balance.balance, balance.usd_value, token=token, block=self.block),
                )
        for token, balance in other.items():
            if balance:
                if token in combined:
                    combined._setitem_nochecksum(
                        token, combined._getitem_nochecksum(token) + balance
                    )
                else:
                    combined._setitem_nochecksum(
                        token,
                        Balance(balance.balance, balance.usd_value, token=token, block=self.block),
                    )
        return combined

    def __sub__(self, other: "TokenBalances") -> "TokenBalances":
        """
        Subtracts another :class:`~eth_portfolio.typing.TokenBalances` object from this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.TokenBalances` object.

        Returns:
            A new :class:`~eth_portfolio.typing.TokenBalances` object with the subtracted balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.TokenBalances`.

        Example:
            >>> tb1 = TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})
            >>> tb2 = TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})
            >>> result_tb = tb1 - tb2
            >>> result_tb['0x123'].balance
            Decimal('50')
        """
        if not isinstance(other, TokenBalances):
            raise TypeError(f"{other} is not a TokenBalances object")
        if self.block != other.block:
            raise ValueError(
                f"These TokenBalances objects are not from the same block ({self.block} and {other.block})"
            )
        # NOTE We need a new object to avoid mutating the inputs
        subtracted: TokenBalances = TokenBalances(self, block=self.block)
        for token, balance in other.items():
            subtracted[token] -= balance
        for token, balance in dict(subtracted).items():
            if not balance:
                del subtracted[token]
        return subtracted

    __slots__ = ("block",)


_RTBSeed = Dict[ProtocolLabel, TokenBalances]


class RemoteTokenBalances(DefaultDict[ProtocolLabel, TokenBalances], _SummableNonNumericMixin):
    """
    Manages token balances across different protocols, extending the :class:`~eth_portfolio.typing.TokenBalances` functionality
    to multiple protocols.

    The class uses protocol labels as keys and :class:`~eth_portfolio.typing.TokenBalances` objects as values.

    Args:
        seed: An initial seed of remote token balances, either as a dictionary
            or an iterable of tuples.

    Example:
        >>> remote_balances = RemoteTokenBalances({'protocol1': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
        >>> remote_balances['protocol1']['0x123'].balance
        Decimal('100')
    """

    def __init__(self, seed: Optional[_RTBSeed] = None, *, block: Optional[int] = None) -> None:
        super().__init__(lambda: TokenBalances(block=block))
        self.block = block
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()  # type: ignore [assignment]
        if not isinstance(seed, Iterable):
            raise TypeError(f"{seed} is not a valid input for TokenBalances")
        for remote, token_balances in seed:  # type: ignore [misc]
            if self.block != token_balances.block:
                raise ValueError(
                    f"These objects are not from the same block ({self.block} and {token_balances.block})"
                )
            self[remote] += token_balances  # type: ignore [has-type]

    def __setitem__(self, protocol: str, value: TokenBalances):
        """
        Sets the token balances for a given protocol.

        Args:
            key: The protocol label.
            value: The token balances to set for the protocol.

        Raises:
            TypeError: If the value is not a :class:`~eth_portfolio.typing.TokenBalances` object.

        Example:
            >>> remote_balances = RemoteTokenBalances()
            >>> remote_balances['protocol1'] = TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})
            >>> remote_balances['protocol1']['0x123'].balance
            Decimal('100')
        """
        if not isinstance(value, TokenBalances):
            raise TypeError(f"value must be a `TokenBalances` object. You passed {value}") from None
        return super().__setitem__(protocol, value)

    @property
    def dataframe(self) -> DataFrame:
        """
        Converts the remote token balances into a pandas DataFrame.

        Returns:
            A DataFrame representation of the remote token balances.
        """
        dfs: List[DataFrame] = []
        for protocol, balances in self.items():
            df = balances.dataframe
            df["protocol"] = protocol
            dfs.append(df)
        return concat(dfs).reset_index(drop=True) if dfs else DataFrame()

    def sum_usd(self) -> Decimal:
        """
        Sums the USD values of all token balances across all protocols.

        Returns:
            The total USD value of all remote token balances.

        Example:
            >>> remote_balances = RemoteTokenBalances({'protocol1': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
            >>> total_usd = remote_balances.sum_usd()
            >>> total_usd
            Decimal('2000')
        """
        return Decimal(sum(balance.sum_usd() for balance in self.values()))

    def __bool__(self) -> bool:
        """
        Evaluates the truth value of the :class:`~eth_portfolio.typing.RemoteTokenBalances` object.

        Returns:
            True if any protocol has a non-zero balance, otherwise False.

        Example:
            >>> remote_balances = RemoteTokenBalances()
            >>> bool(remote_balances)
            False
        """
        return any(self.values())

    def __repr__(self) -> str:
        """
        Returns a string representation of the :class:`~eth_portfolio.typing.RemoteTokenBalances` object.

        Returns:
            The string representation of the remote token balances.
        """
        return f"RemoteTokenBalances{dict(self)}"

    def __add__(self, other: "RemoteTokenBalances") -> "RemoteTokenBalances":
        """
        Adds another :class:`~eth_portfolio.typing.RemoteTokenBalances` object to this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.RemoteTokenBalances` object.

        Returns:
            A new :class:`~eth_portfolio.typing.RemoteTokenBalances` object with the combined balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.RemoteTokenBalances`.

        Example:
            >>> rb1 = RemoteTokenBalances({'protocol1': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
            >>> rb2 = RemoteTokenBalances({'protocol1': TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})})
            >>> combined_rb = rb1 + rb2
            >>> combined_rb['protocol1']['0x123'].balance
            Decimal('150')
        """
        if not isinstance(other, RemoteTokenBalances):
            raise TypeError(f"{other} is not a RemoteTokenBalances object")
        if self.block != other.block:
            raise ValueError(
                f"These RemoteTokenBalances objects are not from the same block ({self.block} and {other.block})"
            )
        # NOTE We need a new object to avoid mutating the inputs
        combined: RemoteTokenBalances = RemoteTokenBalances(block=self.block)
        for protocol, token_balances in self.items():
            if token_balances:
                combined[protocol] += token_balances
        for protocol, token_balances in other.items():
            if token_balances:
                combined[protocol] += token_balances
        return combined

    def __sub__(self, other: "RemoteTokenBalances") -> "RemoteTokenBalances":
        """
        Subtracts another :class:`~eth_portfolio.typing.RemoteTokenBalances` object from this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.RemoteTokenBalances` object.

        Returns:
            A new :class:`~eth_portfolio.typing.RemoteTokenBalances` object with the subtracted balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.RemoteTokenBalances`.

        Example:
            >>> rb1 = RemoteTokenBalances({'protocol1': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
            >>> rb2 = RemoteTokenBalances({'protocol1': TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})})
            >>> result_rb = rb1 - rb2
            >>> result_rb['protocol1']['0x123'].balance
            Decimal('50')
        """
        if not isinstance(other, RemoteTokenBalances):
            raise TypeError(f"{other} is not a RemoteTokenBalances object")
        if self.block != other.block:
            raise ValueError(
                f"These RemoteTokenBalances objects are not from the same block ({self.block} and {other.block})"
            )
        # NOTE We need a new object to avoid mutating the inputs
        subtracted: RemoteTokenBalances = RemoteTokenBalances(self, block=self.block)
        for protocol, token_balances in other.items():
            subtracted[protocol] -= token_balances
        for protocol, token_balances in dict(subtracted).items():
            if not token_balances:
                del subtracted[protocol]
        return subtracted


CategoryLabel = Literal["assets", "debt", "external"]

_WBSeed = Union[Dict[CategoryLabel, TokenBalances], Iterable[Tuple[CategoryLabel, TokenBalances]]]


class WalletBalances(
    Dict[CategoryLabel, Union[TokenBalances, RemoteTokenBalances]], _SummableNonNumericMixin
):
    """
    Organizes token balances into categories such as assets, debts, and external balances for a single wallet.

    The class uses categories as keys (`assets`, `debt`, `external`) and :class:`~eth_portfolio.typing.TokenBalances` or :class:`~eth_portfolio.typing.RemoteTokenBalances`
    objects as values.

    Args:
        seed: An initial seed of wallet balances, either as a dictionary or an iterable of tuples.

    Example:
        >>> wallet_balances = WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
        >>> wallet_balances['assets']['0x123'].balance
        Decimal('100')
    """

    def __init__(
        self,
        seed: Optional[Union["WalletBalances", _WBSeed]] = None,
        *,
        block: Optional[int] = None,
    ) -> None:
        super().__init__()
        self.block = block
        self._keys = "assets", "debt", "external"
        self["assets"] = TokenBalances(block=block)
        self["debt"] = RemoteTokenBalances(block=block)
        self["external"] = RemoteTokenBalances(block=block)

        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()  # type: ignore
        if not isinstance(seed, Iterable):
            raise TypeError(f"{seed} is not a valid input for WalletBalances")
        for key, balances in seed:  # type: ignore
            if self.block != balances.block:
                raise ValueError(
                    f"These objects are not from the same block ({self.block} and {balances.block})"
                )
            self.__validateitem(key, balances)
            self[key] += balances  # type: ignore [operator]

    @property
    def assets(self) -> TokenBalances:
        """
        Returns the assets held by the wallet.

        Returns:
            :class:`~eth_portfolio.typing.TokenBalances`: The :class:`~eth_portfolio.typing.TokenBalances` object representing the wallet's assets.
        """
        return self["assets"]  # type: ignore

    @property
    def debt(self) -> RemoteTokenBalances:
        """
        Returns the debts associated with the wallet.

        Returns:
            :class:`~eth_portfolio.typing.RemoteTokenBalances`: The :class:`~eth_portfolio.typing.RemoteTokenBalances` object representing the wallet's debts.
        """
        return self["debt"]

    @property
    def external(self) -> RemoteTokenBalances:
        """
        Returns the external balances associated with the wallet.

        Returns:
            :class:`~eth_portfolio.typing.RemoteTokenBalances`: The :class:`~eth_portfolio.typing.RemoteTokenBalances` object representing the wallet's external balances.
        """
        return self["external"]

    @property
    def dataframe(self) -> DataFrame:
        """
        Converts the wallet balances into a pandas DataFrame.

        Returns:
            A DataFrame representation of the wallet balances.
        """
        dfs: List[DataFrame] = []
        for category, category_bals in self.items():
            df = category_bals.dataframe
            df["category"] = category
            dfs.append(df)
        return concat(dfs).reset_index(drop=True) if dfs else DataFrame()

    def sum_usd(self) -> Decimal:
        """
        Sums the USD values of the wallet's assets, debts, and external balances.

        Returns:
            The total USD value of the wallet's net assets (assets - debt + external).

        Example:
            >>> wallet_balances = WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
            >>> total_usd = wallet_balances.sum_usd()
            >>> total_usd
            Decimal('2000')
        """
        return self.assets.sum_usd() - self.debt.sum_usd() + self.external.sum_usd()

    def __bool__(self) -> bool:
        """
        Evaluates the truth value of the :class:`~eth_portfolio.typing.WalletBalances` object.

        Returns:
            True if any category has a non-zero balance, otherwise False.

        Example:
            >>> wallet_balances = WalletBalances()
            >>> bool(wallet_balances)
            False
        """
        return any(self.values())

    def __repr__(self) -> str:
        """
        Returns a string representation of the :class:`~eth_portfolio.typing.WalletBalances` object.

        Returns:
            The string representation of the wallet balances.
        """
        return f"WalletBalances {dict(self)}"

    def __add__(self, other: "WalletBalances") -> "WalletBalances":
        """
        Adds another :class:`~eth_portfolio.typing.WalletBalances` object to this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.WalletBalances` object.

        Returns:
            A new :class:`~eth_portfolio.typing.WalletBalances` object with the combined balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.WalletBalances`.

        Example:
            >>> wb1 = WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
            >>> wb2 = WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})})
            >>> combined_wb = wb1 + wb2
            >>> combined_wb['assets']['0x123'].balance
            Decimal('150')
        """
        if not isinstance(other, WalletBalances):
            raise TypeError(f"{other} is not a WalletBalances object")
        if self.block != other.block:
            raise ValueError(
                f"These WalletBalances objects are not from the same block ({self.block} and {other.block})"
            )
        # NOTE We need a new object to avoid mutating the inputs
        combined: WalletBalances = WalletBalances(block=self.block)
        for category, balances in self.items():
            if balances:
                combined[category] += balances  # type: ignore [operator]
        for category, balances in other.items():
            if balances:
                combined[category] += balances  # type: ignore [operator]
        return combined

    def __sub__(self, other: "WalletBalances") -> "WalletBalances":
        """
        Subtracts another :class:`~eth_portfolio.typing.WalletBalances` object from this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.WalletBalances` object.

        Returns:
            A new :class:`~eth_portfolio.typing.WalletBalances` object with the subtracted balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.WalletBalances`.

        Example:
            >>> wb1 = WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
            >>> wb2 = WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})})
            >>> result_wb = wb1 - wb2
            >>> result_wb['assets']['0x123'].balance
            Decimal('50')
        """
        if not isinstance(other, WalletBalances):
            raise TypeError(f"{other} is not a WalletBalances object")
        if self.block != other.block:
            raise ValueError(
                f"These WalletBalances objects are not from the same block ({self.block} and {other.block})"
            )
        # We need a new object to avoid mutating the inputs
        subtracted: WalletBalances = WalletBalances(self, block=self.block)
        for category, balances in other.items():
            subtracted[category] -= balances  # type: ignore
        for category, balances in dict(subtracted).items():
            if not balances:
                del subtracted[category]
        return subtracted

    def __getitem__(self, key: CategoryLabel) -> Union[TokenBalances, RemoteTokenBalances]:
        """
        Retrieves the balance associated with the given category key.

        Args:
            key: The category label (`assets`, `debt`, or `external`).

        Returns:
            The balances associated with the category.

        Raises:
            KeyError: If the key is not a valid category.

        Example:
            >>> wallet_balances = WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
            >>> assets_balances = wallet_balances['assets']
            >>> assets_balances['0x123'].balance
            Decimal('100')
        """
        self.__validatekey(key)
        return super().__getitem__(key)

    def __setitem__(
        self, key: CategoryLabel, value: Union[TokenBalances, RemoteTokenBalances]
    ) -> None:
        """
        Sets the balance associated with the given category key.

        Args:
            key: The category label (`assets`, `debt`, or `external`).
            value: The balance to associate with the category.

        Raises:
            KeyError: If the key is not a valid category.
            TypeError: If the value is not a valid balance type for the category.

        Example:
            >>> wallet_balances = WalletBalances()
            >>> wallet_balances['assets'] = TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})
            >>> wallet_balances['assets']['0x123'].balance
            Decimal('100')
        """
        self.__validateitem(key, value)
        return super().__setitem__(key, value)

    def __validatekey(self, key: CategoryLabel) -> None:
        """
        Validates that the given key is a valid category.

        Valid keys: "assets", "debt", "external"

        Args:
            key: The category label to validate.

        Raises:
            KeyError: If the key is not a valid category.
        """
        if key not in self._keys:
            raise KeyError(
                f"{key} is not a valid key for WalletBalances. Valid keys are: {self._keys}"
            )

    def __validateitem(self, key: CategoryLabel, item: Any) -> None:
        """
        Validates that the given item is a valid balance type for the category.

        Args:
            key: The category label.
            item: The balance item to validate.

        Raises:
            KeyError: If the key is not a valid category.
            TypeError: If the item is not a valid balance type for the category.
        """
        self.__validatekey(key)
        if key == "assets":
            if not isinstance(item, TokenBalances):
                raise TypeError(
                    f'{item} is not a valid value for "{key}". Must be a TokenBalances object.'
                )
        elif key in ["debt", "external"]:
            if not isinstance(item, RemoteTokenBalances):
                raise TypeError(
                    f'{item} is not a valid value for "{key}". Must be a RemoteTokenBalances object.'
                )
        else:
            raise NotImplementedError(f"key {key} is not yet implemented.")


_PBSeed = Union[Dict[Address, WalletBalances], Iterable[Tuple[Address, WalletBalances]]]


class PortfolioBalances(DefaultChecksumDict[WalletBalances], _SummableNonNumericMixin):
    """
    Aggregates :class:`~eth_portfolio.typing.WalletBalances` for multiple wallets, providing operations to sum
    balances across an entire portfolio.

    The class uses wallet addresses as keys and :class:`~eth_portfolio.typing.WalletBalances` objects as values.

    Args:
        seed: An initial seed of portfolio balances, either as a dictionary or an iterable of tuples.

    Example:
        >>> portfolio_balances = PortfolioBalances({'0x123': WalletBalances({'assets': TokenBalances({'0x456': Balance(Decimal('100'), Decimal('2000'))})})})
        >>> portfolio_balances['0x123']['assets']['0x456'].balance
        Decimal('100')
    """

    def __init__(self, seed: Optional[_PBSeed] = None, *, block: Optional[int] = None) -> None:
        super().__init__(lambda: WalletBalances(block=block))
        self.block = block
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()
        if not isinstance(seed, Iterable):
            raise TypeError(f"{seed} is not a valid input for PortfolioBalances")
        for wallet, balances in seed:
            if self.block != balances.block:
                raise ValueError(
                    f"These objects are not from the same block ({self.block} and {balances.block})"
                )
            self[wallet] += balances

    def __setitem__(self, key, value):
        if not isinstance(value, WalletBalances):
            raise TypeError(
                f"value must be a `WalletBalances` object. You passed {value}"
            ) from None
        return super().__setitem__(key, value)

    @property
    def dataframe(self) -> DataFrame:
        """
        Converts the portfolio balances into a pandas DataFrame.

        Returns:
            A DataFrame representation of the portfolio balances.
        """
        dfs: List[DataFrame] = []
        for wallet, balances in self.items():
            df = balances.dataframe
            df["wallet"] = wallet
            dfs.append(df)
        return concat(dfs).reset_index(drop=True) if dfs else DataFrame()

    def sum_usd(self) -> Decimal:
        """
        Sums the USD values of all wallet balances in the portfolio.

        Returns:
            The total USD value of all wallet balances in the portfolio.

        Example:
            >>> portfolio_balances = PortfolioBalances({'0x123': WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})})
            >>> total_usd = portfolio_balances.sum_usd()
            >>> total_usd
            Decimal('2000')
        """
        return sum(balances.sum_usd() for balances in self.values())  # type: ignore

    @cached_property
    def inverted(self) -> "PortfolioBalancesByCategory":
        """
        Returns an inverted view of the portfolio balances, grouped by category first.

        Returns:
            :class:`~eth_portfolio.typing.PortfolioBalancesByCategory`: The inverted portfolio balances, grouped by category.

        Example:
            >>> portfolio_balances = PortfolioBalances({'0x123': WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})})
            >>> inverted_pb = portfolio_balances.inverted
            >>> inverted_pb['assets']['0x123'].balance
            Decimal('100')
        """
        inverted = PortfolioBalancesByCategory()
        for wallet, wbalances in self.items():
            for label, tbalances in wbalances.items():
                if tbalances:
                    inverted[label][wallet] += tbalances  # type: ignore [operator]
        return inverted

    def __bool__(self) -> bool:
        """
        Evaluates the truth value of the :class:`~eth_portfolio.typing.PortfolioBalances` object.

        Returns:
            True if any wallet has a non-zero balance of any token, otherwise False.

        Example:
            >>> portfolio_balances = PortfolioBalances()
            >>> bool(portfolio_balances)
            False
        """
        return any(self.values())

    def __repr__(self) -> str:
        """
        Returns a string representation of the :class:`~eth_portfolio.typing.PortfolioBalances` object.

        Returns:
            The string representation of the portfolio balances.
        """
        return f"WalletBalances{dict(self)}"

    def __add__(self, other: "PortfolioBalances") -> "PortfolioBalances":
        """
        Adds another :class:`~eth_portfolio.typing.PortfolioBalances` object to this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.PortfolioBalances` object.

        Returns:
            A new :class:`~eth_portfolio.typing.PortfolioBalances` object with the combined balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.PortfolioBalances`.

        Example:
            >>> pb1 = PortfolioBalances({'0x123': WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})})
            >>> pb2 = PortfolioBalances({'0x123': WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})})})
            >>> combined_pb = pb1 + pb2
            >>> combined_pb['0x123']['assets']['0x123'].balance
            Decimal('150')
        """
        if not isinstance(other, PortfolioBalances):
            raise TypeError(f"{other} is not a PortfolioBalances object")
        if self.block != other.block:
            raise ValueError(
                f"These PortfolioBalances objects are not from the same block ({self.block} and {other.block})"
            )
        # NOTE We need a new object to avoid mutating the inputs
        combined: PortfolioBalances = PortfolioBalances(block=self.block)
        for wallet, balance in self.items():
            if balance:
                combined._setitem_nochecksum(wallet, combined._getitem_nochecksum(wallet) + balance)
        for wallet, balance in other.items():
            if balance:
                combined._setitem_nochecksum(wallet, combined._getitem_nochecksum(wallet) + balance)
        return combined

    def __sub__(self, other: "PortfolioBalances") -> "PortfolioBalances":
        """
        Subtracts another :class:`~eth_portfolio.typing.PortfolioBalances` object from this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.PortfolioBalances` object.

        Returns:
            A new :class:`~eth_portfolio.typing.PortfolioBalances` object with the subtracted balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.PortfolioBalances`.

        Example:
            >>> pb1 = PortfolioBalances({'0x123': WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})})
            >>> pb2 = PortfolioBalances({'0x123': WalletBalances({'assets': TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})})})
            >>> result_pb = pb1 - pb2
            >>> result_pb['0x123']['assets']['0x123'].balance
            Decimal('50')
        """
        if not isinstance(other, PortfolioBalances):
            raise TypeError(f"{other} is not a PortfolioBalances object")
        if self.block != other.block:
            raise ValueError(
                f"These PortfolioBalances objects are not from the same block ({self.block} and {other.block})"
            )
        # We need a new object to avoid mutating the inputs
        subtracted: PortfolioBalances = PortfolioBalances(self, block=self.block)
        for protocol, balances in other.items():
            subtracted[protocol] -= balances
        for protocol, balances in subtracted.items():
            if not balances:
                del subtracted[protocol]
        return subtracted

    __slots__ = ("block",)


_WTBInput = Union[Dict[Address, TokenBalances], Iterable[Tuple[Address, TokenBalances]]]


class WalletBalancesRaw(DefaultChecksumDict[TokenBalances], _SummableNonNumericMixin):
    # Since PortfolioBalances key lookup is:    ``wallet   -> category -> token    -> balance``
    # We need a new structure for key pattern:  ``wallet   -> token    -> balance``

    # WalletBalancesRaw fills this role.
    """
    A structure for key pattern `wallet -> token -> balance`.

    This class is similar to :class:`~eth_portfolio.typing.WalletBalances` but optimized for key lookups by wallet and token directly.
    It manages :class:`~eth_portfolio.typing.TokenBalances` objects for multiple wallets.

    Args:
        seed: An initial seed of wallet balances, either as a dictionary or an iterable of tuples.

    Example:
        >>> raw_balances = WalletBalancesRaw({'0x123': TokenBalances({'0x456': Balance(Decimal('100'), Decimal('2000'))})})
        >>> raw_balances['0x123']['0x456'].balance
        Decimal('100')
    """

    def __init__(self, seed: Optional[_WTBInput] = None, *, block: Optional[int] = None) -> None:
        super().__init__(lambda: TokenBalances(block=block))
        self.block = block
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()
        if not isinstance(seed, Iterable):
            raise TypeError(f"{seed} is not a valid input for WalletBalancesRaw")
        for wallet, balances in seed:
            if self.block != balances.block:
                raise ValueError(
                    f"These objects are not from the same block ({self.block} and {balances.block})"
                )
            self[wallet] += balances

    def __bool__(self) -> bool:
        """
        Evaluates the truth value of the :class:`~eth_portfolio.typing.WalletBalancesRaw` object.

        Returns:
            True if any wallet has a non-zero balance, otherwise False.

        Example:
            >>> raw_balances = WalletBalancesRaw()
            >>> bool(raw_balances)
            False
        """
        return any(self.values())

    def __repr__(self) -> str:
        """
        Returns a string representation of the :class:`~eth_portfolio.typing.WalletBalancesRaw` object.

        Returns:
            The string representation of the raw wallet balances.
        """
        return f"WalletBalances{dict(self)}"

    def __add__(self, other: "WalletBalancesRaw") -> "WalletBalancesRaw":
        """
        Adds another :class:`~eth_portfolio.typing.WalletBalancesRaw` object to this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.WalletBalancesRaw` object.

        Returns:
            A new :class:`~eth_portfolio.typing.WalletBalancesRaw` object with the combined balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.WalletBalancesRaw`.

        Example:
            >>> raw_balances1 = WalletBalancesRaw({'0x123': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
            >>> raw_balances2 = WalletBalancesRaw({'0x123': TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})})
            >>> combined_raw = raw_balances1 + raw_balances2
            >>> combined_raw['0x123']['0x123'].balance
            Decimal('150')
        """
        if not isinstance(other, WalletBalancesRaw):
            raise TypeError(f"{other} is not a WalletBalancesRaw object")
        if self.block != other.block:
            raise ValueError(
                f"These WalletBalancesRaw objects are not from the same block ({self.block} and {other.block})"
            )
        # NOTE We need a new object to avoid mutating the inputs
        combined: WalletBalancesRaw = WalletBalancesRaw(block=self.block)
        for wallet, balance in self.items():
            if balance:
                combined._setitem_nochecksum(wallet, combined._getitem_nochecksum(wallet) + balance)
        for wallet, balance in other.items():
            if balance:
                combined._setitem_nochecksum(wallet, combined._getitem_nochecksum(wallet) + balance)
        return combined

    def __sub__(self, other: "WalletBalancesRaw") -> "WalletBalancesRaw":
        """
        Subtracts another :class:`~eth_portfolio.typing.WalletBalancesRaw` object from this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.WalletBalancesRaw` object.

        Returns:
            A new :class:`~eth_portfolio.typing.WalletBalancesRaw` object with the subtracted balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.WalletBalancesRaw`.

        Example:
            >>> raw_balances1 = WalletBalancesRaw({'0x123': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})
            >>> raw_balances2 = WalletBalancesRaw({'0x123': TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})})
            >>> result_raw = raw_balances1 - raw_balances2
            >>> result_raw['0x123']['0x123'].balance
            Decimal('50')
        """
        if not isinstance(other, WalletBalancesRaw):
            raise TypeError(f"{other} is not a WalletBalancesRaw object")
        if self.block != other.block:
            raise ValueError(
                f"These WalletBalancesRaw objects are not from the same block ({self.block} and {other.block})"
            )
        # NOTE We need a new object to avoid mutating the inputs
        subtracted: WalletBalancesRaw = WalletBalancesRaw(self, block=other.block)
        for wallet, balances in other.items():
            if balances:
                subtracted[wallet] -= balances
        for wallet, balances in subtracted.items():
            if not balances:
                del subtracted[wallet]
        return subtracted

    __slots__ = ("block",)


_CBInput = Union[
    Dict[CategoryLabel, WalletBalancesRaw], Iterable[Tuple[CategoryLabel, WalletBalancesRaw]]
]


class PortfolioBalancesByCategory(
    DefaultDict[CategoryLabel, WalletBalancesRaw], _SummableNonNumericMixin
):
    """
    Provides an inverted view of :class:`~eth_portfolio.typing.PortfolioBalances`, allowing access by category first,
    then by wallet and token.

    The class uses category labels as keys (`assets`, `debt`, `external`) and :class:`~eth_portfolio.typing.WalletBalancesRaw`
    objects as values.

    Args:
        seed: An initial seed of portfolio balances by category, either as a dictionary or an iterable of tuples.

    Example:
        >>> pb_by_category = PortfolioBalancesByCategory({'assets': WalletBalancesRaw({'0x123': TokenBalances({'0x456': Balance(Decimal('100'), Decimal('2000'))})})})
        >>> pb_by_category['assets']['0x123']['0x456'].balance
        Decimal('100')
    """

    def __init__(self, seed: Optional[_CBInput] = None, *, block: Optional[int] = None) -> None:
        super().__init__(lambda: WalletBalancesRaw(block=block))
        self.block = block
        if seed is None:
            return
        if isinstance(seed, dict):
            seed = seed.items()
        if not isinstance(seed, Iterable):
            raise TypeError(f"{seed} is not a valid input for PortfolioBalancesByCategory")
        for label, balances in seed:  # type: ignore
            if self.block != balances.block:
                raise ValueError(
                    f"These objects are not from the same block ({self.block} and {balances.block})"
                )
            self[label] += balances

    @property
    def assets(self) -> WalletBalancesRaw:
        """
        Returns the asset balances across all wallets.

        Returns:
            :class:`~eth_portfolio.typing.WalletBalancesRaw`: The :class:`~eth_portfolio.typing.WalletBalancesRaw` object representing the asset balances.
        """
        return self["assets"]

    @property
    def debt(self) -> WalletBalancesRaw:
        """
        Returns the debt balances across all wallets.

        Returns:
            :class:`~eth_portfolio.typing.WalletBalancesRaw`: The :class:`~eth_portfolio.typing.WalletBalancesRaw` object representing the debt balances.
        """
        return self["debt"]

    def invert(self) -> "PortfolioBalances":
        """
        Inverts the portfolio balances by category to group by wallet first.

        Returns:
            :class:`~eth_portfolio.typing.PortfolioBalances`: The inverted portfolio balances, grouped by wallet first.

        Example:
            >>> pb_by_category = PortfolioBalancesByCategory({'assets': WalletBalancesRaw({'0x123': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})})
            >>> inverted_pb = pb_by_category.invert()
            >>> inverted_pb['0x123']['assets']['0x123'].balance
            Decimal('100')
        """
        inverted = PortfolioBalances()
        for label, wtbalances in self.items():
            for wallet, tbalances in wtbalances.items():
                if tbalances:
                    inverted[wallet][label] += tbalances  # type: ignore [operator]
        return inverted

    def __bool__(self) -> bool:
        """
        Evaluates the truth value of the :class:`~eth_portfolio.typing.PortfolioBalancesByCategory` object.

        Returns:
            True if any category has a non-zero balance, otherwise False.

        Example:
            >>> pb_by_category = PortfolioBalancesByCategory()
            >>> bool(pb_by_category)
            False
        """
        return any(self.values())

    def __repr__(self) -> str:
        """
        Returns a string representation of the :class:`~eth_portfolio.typing.PortfolioBalancesByCategory` object.

        Returns:
            The string representation of the portfolio balances by category.
        """
        return f"PortfolioBalancesByCategory{dict(self)}"

    def __add__(self, other: "PortfolioBalancesByCategory") -> "PortfolioBalancesByCategory":
        """
        Adds another :class:`~eth_portfolio.typing.PortfolioBalancesByCategory` object to this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.PortfolioBalancesByCategory` object.

        Returns:
            A new :class:`~eth_portfolio.typing.PortfolioBalancesByCategory` object with the combined balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.PortfolioBalancesByCategory`.

        Example:
            >>> pb_by_category1 = PortfolioBalancesByCategory({'assets': WalletBalancesRaw({'0x123': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})})
            >>> pb_by_category2 = PortfolioBalancesByCategory({'assets': WalletBalancesRaw({'0x123': TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})})})
            >>> combined_pb_by_category = pb_by_category1 + pb_by_category2
            >>> combined_pb_by_category['assets']['0x123']['0x123'].balance
            Decimal('150')
        """
        if not isinstance(other, PortfolioBalancesByCategory):
            raise TypeError(f"{other} is not a PortfolioBalancesByCategory object")
        if self.block != other.block:
            raise ValueError(
                f"These PortfolioBalancesByCategory objects are not from the same block ({self.block} and {other.block})"
            )
        # NOTE We need a new object to avoid mutating the inputs
        combined: PortfolioBalancesByCategory = PortfolioBalancesByCategory(block=self.block)
        for protocol, balances in self.items():
            if balances:
                combined[protocol] += balances
        for protocol, balances in other.items():
            if balances:
                combined[protocol] += balances
        return combined

    def __sub__(self, other: "PortfolioBalancesByCategory") -> "PortfolioBalancesByCategory":
        """
        Subtracts another :class:`~eth_portfolio.typing.PortfolioBalancesByCategory` object from this one.

        Args:
            other: Another :class:`~eth_portfolio.typing.PortfolioBalancesByCategory` object.

        Returns:
            A new :class:`~eth_portfolio.typing.PortfolioBalancesByCategory` object with the subtracted balances.

        Raises:
            TypeError: If the other object is not a :class:`~eth_portfolio.typing.PortfolioBalancesByCategory`.

        Example:
            >>> pb_by_category1 = PortfolioBalancesByCategory({'assets': WalletBalancesRaw({'0x123': TokenBalances({'0x123': Balance(Decimal('100'), Decimal('2000'))})})})
            >>> pb_by_category2 = PortfolioBalancesByCategory({'assets': WalletBalancesRaw({'0x123': TokenBalances({'0x123': Balance(Decimal('50'), Decimal('1000'))})})})
            >>> result_pb_by_category = pb_by_category1 - pb_by_category2
            >>> result_pb_by_category['assets']['0x123']['0x123'].balance
            Decimal('50')
        """
        if not isinstance(other, PortfolioBalancesByCategory):
            raise TypeError(f"{other} is not a PortfolioBalancesByCategory object")
        if self.block != other.block:
            raise ValueError(
                f"These PortfolioBalancesByCategory objects are not from the same block ({self.block} and {other.block})"
            )
        # NOTE We need a new object to avoid mutating the inputs
        subtracted: PortfolioBalancesByCategory = PortfolioBalancesByCategory(
            self, block=self.block
        )
        for protocol, balances in other.items():
            subtracted[protocol] -= balances
        for protocol, balances in subtracted.items():
            if not balances:
                del subtracted[protocol]
        return subtracted
