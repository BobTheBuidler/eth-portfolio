import decimal
import logging
from typing import Union

from evmspec.data import Wei


logger = logging.getLogger(__name__)


class Decimal(decimal.Decimal):
    def jsonify(self) -> Union[str, int]:
        """Makes the Decimal as small as possible when converted to json."""
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
            raise Exception("will this ever actually run?", self, scientific_notation)
            return scientific_notation

        if not string:
            raise Exception("no string", self)
        return string

    def __add__(self, other):
        return type(self)(super().__add__(other))

    def __radd__(self, other):
        return type(self)(super().__radd__(other))

    def __sub__(self, other):
        return type(self)(super().__sub__(other))

    def __rsub__(self, other):
        return type(self)(super().__rsub__(other))

    def __mul__(self, other):
        return type(self)(super().__mul__(other))

    def __rmul__(self, other):
        return type(self)(super().__rmul__(other))

    def __truediv__(self, other):
        return type(self)(super().__truediv__(other))

    def __rtruediv__(self, other):
        return type(self)(super().__rtruediv__(other))

    def __floordiv__(self, other):
        return type(self)(super().__floordiv__(other))

    def __rfloordiv__(self, other):
        return type(self)(super().__rfloordiv__(other))


class Gwei(Decimal):
    @property
    def as_wei(self) -> Wei:
        return Wei(self * 10**9)
