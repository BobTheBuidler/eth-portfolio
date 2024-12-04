from typing import Union

from evmspec.structs.trace import call, create, reward, suicide


class CallTrace(
    call.Trace,
    frozen=True,
    kw_only=True,
    array_like=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`evmspec.trace.call.Trace` but it encodes to a tuple instead of a dict to save space since keys are known.
    """


class CreateTrace(
    create.Trace,
    frozen=True,
    kw_only=True,
    array_like=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`evmspec.trace.create.Trace` but it encodes to a tuple instead of a dict to save space since keys are known.
    """


class RewardTrace(
    reward.Trace,
    frozen=True,
    kw_only=True,
    array_like=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`evmspec.trace.reward.Trace` but it encodes to a tuple instead of a dict to save space since keys are known.
    """


class SuicideTrace(
    suicide.Trace,
    frozen=True,
    kw_only=True,
    array_like=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    It works just like a :class:`evmspec.trace.suicide.Trace` but it encodes to a tuple instead of a dict to save space since keys are known.
    """


_modified_trace_type_map = {
    call.Trace: CallTrace,
    create.Trace: CreateTrace,
    reward.Trace: RewardTrace,
    suicide.Trace: SuicideTrace,
}

ModifiedTrace = Union[CallTrace, CreateTrace, RewardTrace, SuicideTrace]
