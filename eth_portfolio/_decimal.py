import decimal
import logging
from typing import Union

from evmspec.data import Wei


logger = logging.getLogger(__name__)


class Decimal(decimal.Decimal):
    """
    A subclass of :class:`decimal.Decimal` with additional functionality for JSON serialization.

    This class extends the :class:`decimal.Decimal` class to provide an additional
    method for JSON serialization. It also overrides arithmetic operations to ensure
    that the result is of type :class:`Decimal`.

    See Also:
        - :class:`decimal.Decimal`
    """

    def jsonify(self) -> Union[str, int]:
        """
        Converts the Decimal to a JSON-friendly format.

        This method attempts to represent the Decimal in the most compact form
        possible for JSON serialization. It returns an integer if the Decimal
        is equivalent to an integer, otherwise it returns a string in either
        standard or scientific notation, depending on which is shorter.

        Trailing zeros in the string representation are removed. If the
        scientific notation is equivalent to the original Decimal and shorter
        than the standard string representation, it is returned. If the integer
        representation is shorter than the scientific notation plus two characters,
        the integer is returned.

        Raises:
            Exception: If the resulting string representation is empty.

        Examples:
            >>> Decimal('123.4500').jsonify()
            '123.45'
            >>> Decimal('123000').jsonify()
            123000
            >>> Decimal('0.000123').jsonify()
            '1.23E-4'
            >>> Decimal('1000000').jsonify()
            1000000
        """
        string = str(self)
        integer = int(self)

        if integer == self:
            scientific_notation = "%E" % self
            return (
                integer
                if len(str(integer)) <= len(scientific_notation) + 2
                else scientific_notation
            )

        if "E" in string:
            return string

        scientific_notation = "%E" % self
        while string[-1] == "0":
            string = string[:-1]

        if type(self)(scientific_notation) == self and len(scientific_notation) < len(string):
            return scientific_notation

        if not string:
            raise Exception("no string", self)
        return string

    def __add__(self, other):
        """
        Adds two Decimal values, ensuring the result is of type :class:`Decimal`.

        Examples:
            >>> Decimal('1.1') + Decimal('2.2')
            Decimal('3.3')
        """
        return type(self)(super().__add__(other))

    def __radd__(self, other):
        """
        Adds two Decimal values with reflected operands, ensuring the result is of type :class:`Decimal`.

        Examples:
            >>> Decimal('1.1').__radd__(Decimal('2.2'))
            Decimal('3.3')
        """
        return type(self)(super().__radd__(other))

    def __sub__(self, other):
        """
        Subtracts two Decimal values, ensuring the result is of type :class:`Decimal`.

        Examples:
            >>> Decimal('3.3') - Decimal('1.1')
            Decimal('2.2')
        """
        return type(self)(super().__sub__(other))

    def __rsub__(self, other):
        """
        Subtracts two Decimal values with reflected operands, ensuring the result is of type :class:`Decimal`.

        Examples:
            >>> Decimal('3.3').__rsub__(Decimal('1.1'))
            Decimal('-2.2')
        """
        return type(self)(super().__rsub__(other))

    def __mul__(self, other):
        """
        Multiplies two Decimal values, ensuring the result is of type :class:`Decimal`.

        Examples:
            >>> Decimal('2') * Decimal('3')
            Decimal('6')
        """
        return type(self)(super().__mul__(other))

    def __rmul__(self, other):
        """
        Multiplies two Decimal values with reflected operands, ensuring the result is of type :class:`Decimal`.

        Examples:
            >>> Decimal('2').__rmul__(Decimal('3'))
            Decimal('6')
        """
        return type(self)(super().__rmul__(other))

    def __truediv__(self, other):
        """
        Divides two Decimal values, ensuring the result is of type :class:`Decimal`.

        Examples:
            >>> Decimal('6') / Decimal('3')
            Decimal('2')
        """
        return type(self)(super().__truediv__(other))

    def __rtruediv__(self, other):
        """
        Divides two Decimal values with reflected operands, ensuring the result is of type :class:`Decimal`.

        Examples:
            >>> Decimal('6').__rtruediv__(Decimal('3'))
            Decimal('0.5')
        """
        return type(self)(super().__rtruediv__(other))

    def __floordiv__(self, other):
        """
        Performs floor division on two Decimal values, ensuring the result is of type :class:`Decimal`.

        Examples:
            >>> Decimal('7') // Decimal('3')
            Decimal('2')
        """
        return type(self)(super().__floordiv__(other))

    def __rfloordiv__(self, other):
        """
        Performs floor division on two Decimal values with reflected operands, ensuring the result is of type :class:`Decimal`.

        Examples:
            >>> Decimal('7').__rfloordiv__(Decimal('3'))
            Decimal('0')
        """
        return type(self)(super().__rfloordiv__(other))


class Gwei(Decimal):
    """
    A subclass of :class:`Decimal` representing Gwei values.

    This class provides a property to convert Gwei to Wei.

    See Also:
        - :class:`Decimal`
        - :class:`evmspec.data.Wei`
    """

    @property
    def as_wei(self) -> Wei:
        """
        Converts the Gwei value to Wei.

        This property multiplies the Gwei value by 10^9 to convert it to Wei.

        Examples:
            >>> Gwei('1').as_wei
            Wei(1000000000)
        """
        return Wei(self * 10**9)