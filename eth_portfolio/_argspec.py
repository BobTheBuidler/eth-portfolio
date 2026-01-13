from collections.abc import Callable
from inspect import getfullargspec
from typing import Any

# WIP:


def get_args_type(sample: Callable) -> tuple[type, ...]:
    argspec = getfullargspec(sample)
    args = {
        arg_name: argspec.annotations[arg_name] if arg_name in argspec.annotations else Any
        for arg_name in argspec.args
        if arg_name != "self"
    }
    return tuple(*args.values())


def get_kwargs_type(sample: Callable) -> tuple[type, ...]:
    argspec = getfullargspec(sample)
    num_kwargs = len(argspec.args) - len(argspec.defaults or [])
    kwarg_names = argspec.args[num_kwargs:]
    kwargs = {
        kwarg_name: argspec.annotations[kwarg_name] if kwarg_name in argspec.annotations else Any
        for kwarg_name in kwarg_names
    }
    _kwarg_types: list[type[object]] = list(*kwargs.values())
    if num_kwargs == 1:
        return tuple[_kwarg_types[0]]  # type: ignore [valid-type,return-value]
    elif num_kwargs == 2:
        return tuple[_kwarg_types[0], _kwarg_types[1]]  # type: ignore [misc,return-value]
    elif num_kwargs == 3:
        return tuple[_kwarg_types[0], _kwarg_types[1], _kwarg_types[2]]  # type: ignore [misc,return-value]
    else:
        return Any  # type: ignore [misc,return-value]


def get_return_type(sample: Callable) -> type:
    argspec = getfullargspec(sample)
    return argspec.annotations["return"] if "return" in argspec.annotations else Any


def get_types(sample: Callable) -> tuple[type, type, type]:
    return get_args_type(sample), get_kwargs_type(sample), get_return_type(sample)  # type: ignore [return-value]
