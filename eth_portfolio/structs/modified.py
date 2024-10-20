
from typing import Union

import dank_mids.structs
from dank_mids.structs.transaction import _TransactionBase


# TODO: figure out a better way to do this than using the base class
class _ModifiedTransactionBase(
    _TransactionBase, 
    array_like=True, 
    frozen=True, 
    kw_only=True, 
    forbid_unknown_fields=True, 
    omit_defaults=True, 
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs._TransactionBase` but it encodes to a tuple instead of a dict to save space since keys are known.
    """

class TransactionLegacy(
    dank_mids.structs.TransactionLegacy,
    array_like=True, 
    frozen=True, 
    kw_only=True, 
    forbid_unknown_fields=True, 
    omit_defaults=True, 
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs.TransactionLegacy` but it encodes to a tuple instead of a dict to save space since keys are known.
    """
    
class Transaction2930(
    dank_mids.structs.Transaction2930, 
    array_like=True, 
    frozen=True, 
    kw_only=True, 
    forbid_unknown_fields=True, 
    omit_defaults=True, 
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs.Transaction2930` but it encodes to a tuple instead of a dict to save space since keys are known.
    """
    
class Transaction1559(
    dank_mids.structs.Transaction1559, 
    array_like=True, 
    frozen=True, 
    kw_only=True, 
    forbid_unknown_fields=True, 
    omit_defaults=True, 
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
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


class CallTrace(
    dank_mids.structs.CallTrace, 
    frozen=True, 
    kw_only=True, 
    array_like=True, 
    forbid_unknown_fields=True, 
    omit_defaults=True, 
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs.CallTrace` but it encodes to a tuple instead of a dict to save space since keys are known.
    """

class CreateTrace(
    dank_mids.structs.CreateTrace, 
    frozen=True, 
    kw_only=True, 
    array_like=True, 
    forbid_unknown_fields=True, 
    omit_defaults=True, 
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs.CreateTrace` but it encodes to a tuple instead of a dict to save space since keys are known.
    """

class RewardTrace(
    dank_mids.structs.RewardTrace, 
    frozen=True, 
    kw_only=True, 
    array_like=True, 
    forbid_unknown_fields=True, 
    omit_defaults=True, 
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs.RewardTrace` but it encodes to a tuple instead of a dict to save space since keys are known.
    """

class SuicideTrace(
    dank_mids.structs.SuicideTrace, 
    frozen=True, 
    kw_only=True, 
    array_like=True, 
    forbid_unknown_fields=True, 
    omit_defaults=True, 
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`dank_mids.structs.SuicideTrace` but it encodes to a tuple instead of a dict to save space since keys are known.
    """


_modified_trace_type_map = {
    dank_mids.structs.CallTrace: CallTrace,
    dank_mids.structs.CreateTrace: CreateTrace,
    dank_mids.structs.RewardTrace: RewardTrace,
    dank_mids.structs.SuicideTrace: SuicideTrace,
}

ModifiedTrace = Union[CallTrace, CreateTrace, RewardTrace, SuicideTrace]
