from typing import Literal, Optional, Union, final

from dictstruct import DictStruct
from eth_typing import BlockNumber, ChecksumAddress

from eth_portfolio._decimal import Decimal


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

    token: Optional[ChecksumAddress] = None
    """
    The token the balance is of, if known.
    """

    block: Optional[BlockNumber] = None
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
