
from typing import Union

import dank_mids.structs
from dank_mids.structs import CallTrace, CreateTrace, RewardTrace, SuicideTrace
from dank_mids.structs.transaction import _TransactionBase, Transaction1559, Transaction2930, TransactionLegacy


# TODO: figure out a better way to do this than using the base class
class _ModifiedTransactionBase(_TransactionBase, array_like=True, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs._TransactionBase` but it encodes to a tuple instead of a dict to save space since keys are known.
    """

class TransactionLegacy(TransactionLegacy, array_like=True, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs.TransactionLegacy` but it encodes to a tuple instead of a dict to save space since keys are known.
    """
    
class Transaction2930(Transaction2930, array_like=True, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs.Transaction2930` but it encodes to a tuple instead of a dict to save space since keys are known.
    """
    
class Transaction1559(Transaction1559, array_like=True, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs.Transaction1559` but it encodes to a tuple instead of a dict to save space since keys are known.
    """
    
ModifiedTransaction = Union[TransactionLegacy, Transaction2930, Transaction1559]

_modified_tx_type_map = {
    dank_mids.structs.TransactionLegacy: TransactionLegacy,
    dank_mids.structs.Transaction2930: Transaction2930,
    dank_mids.structs.Transaction1559: Transaction1559,
    _TransactionBase: _ModifiedTransactionBase,
}


class CallTrace(CallTrace, frozen=True, kw_only=True, array_like=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    ...
class CreateTrace(CreateTrace, frozen=True, kw_only=True, array_like=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    ...
class RewardTrace(RewardTrace, frozen=True, kw_only=True, array_like=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    ...
class SuicideTrace(SuicideTrace, frozen=True, kw_only=True, array_like=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    ...

FilterTrace = Union[CallTrace, CreateTrace, RewardTrace, SuicideTrace]