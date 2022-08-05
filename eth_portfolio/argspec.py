from inspect import getfullargspec
from typing import Any, Callable, List, Tuple, Type

# WIP:

def get_args_type(sample: Callable) -> Tuple[Type,...]:
    argspec = getfullargspec(sample)
    args = {arg_name: argspec.annotations[arg_name] if arg_name in argspec.annotations else Any for arg_name in argspec.args if arg_name != 'self'}
    return tuple(*args.values())

def get_kwargs_type(sample: Callable) -> Tuple[Type,...]:
    argspec = getfullargspec(sample)
    num_kwargs = len(argspec.args) - len(argspec.defaults if argspec.defaults else [])
    kwarg_names = argspec.args[num_kwargs:]
    kwargs = {kwarg_name: argspec.annotations[kwarg_name] if kwarg_name in argspec.annotations else Any for kwarg_name in kwarg_names}
    _kwarg_types: List[Type[object]] = list(*kwargs.values())
    if num_kwargs == 1:
        kwarg1 = _kwarg_types[0]
        kwarg_types = Tuple[kwarg1]
    elif num_kwargs == 2:
        kwarg_types = Tuple[_kwarg_types[0], _kwarg_types[1]]
    elif num_kwargs == 3:
        kwarg_types = Tuple[_kwarg_types[0], _kwarg_types[1], _kwarg_types[2]]
    else:
        kwarg_types = Any
    return kwarg_types

def get_return_type(sample: Callable) -> Type:
    argspec = getfullargspec(sample)
    return argspec.annotations['return'] if 'return' in argspec.annotations else Any

def get_types(sample: Callable) -> Tuple[Type, Type, Type]:
    return get_args_type(sample), get_kwargs_type(sample), get_return_type(sample)
