from importlib import import_module
from inspect import getmodule, stack
from pkgutil import walk_packages
from types import ModuleType
from typing import Dict, Final, List

import y.constants


CHAINID: Final = y.constants.CHAINID


def get_submodules_for_module(module: ModuleType) -> List[ModuleType]:
    """
    Returns a list of submodules of `module`.
    """
    assert isinstance(module, ModuleType), "`module` must be a module"
    return [
        obj
        for obj in module.__dict__.values()
        if isinstance(obj, ModuleType) and obj.__name__.startswith(module.__name__)
    ]


def get_class_defs_from_module(module: ModuleType) -> List[type]:
    """
    Returns a list of class definitions from a module.
    """
    return [
        obj
        for obj in module.__dict__.values()
        if isinstance(obj, type) and obj.__module__ == module.__name__
    ]


def get_protocols() -> List[type]:
    """
    Used to initialize a submodule's class object.
    Returns a list of initialized protocol objects.
    """
    called_from_module = getmodule(stack()[1][0])
    assert called_from_module, "You can only call this function from a module"
    components = [
        module
        for module in get_submodules_for_module(called_from_module)
        if not module.__name__.endswith("._base")
    ]
    return [
        cls()
        for component in components
        for cls in get_class_defs_from_module(component)
        if cls
        and not cls.__name__.startswith("_")
        and cls.__name__ != "Lending"
        and (not hasattr(cls, "networks") or CHAINID in cls.networks)
    ]


def import_submodules() -> Dict[str, ModuleType]:
    """
    Import all submodules of the module from which this was called, recursively.
    Ignores submodules named `"base"`.
    Returns a dict of `{module.__name__: module}`
    """
    called_from_module = getmodule(stack()[1][0])
    if called_from_module is None:
        return {}
    parent = f"{called_from_module.__name__}."
    return {
        name: import_module(parent + name)
        for loader, name, is_pkg in walk_packages(called_from_module.__path__)  # type: ignore
        if name != "base"
    }
