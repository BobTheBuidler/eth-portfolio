import logging
from functools import wraps
from os import path
from subprocess import CalledProcessError, check_output
from typing import Callable, Iterable, Tuple, TypeVar

from typing_extensions import ParamSpec

from eth_portfolio_scripts.docker.check import check_system


logger = logging.getLogger(__name__)

compose_file = path.join(path.dirname(path.abspath(__file__)), "docker-compose.yaml")


def up() -> None:
    build()
    print("starting the infra containers...")
    _exec_command(["up", "-d"])


def down(*_) -> None:
    _exec_command(["down"])


def build() -> None:
    print("building the grafana containers")
    _exec_command(["build"])


_P = ParamSpec("_P")
_T = TypeVar("_T")


def ensure_containers(fn: Callable[_P, _T]) -> Callable[_P, _T]:
    @wraps(fn)
    async def compose_wrap(*args: _P.args, **kwargs: _P.kwargs):
        # register shutdown sequence
        # TODO: argument to leave them up
        # NOTE: do we need both this and the finally?
        # signal.signal(signal.SIGINT, down)

        # start Grafana containers
        up()

        try:
            # attempt to run `fn`
            await fn(*args, **kwargs)
        finally:
            # stop and remove containers
            # down()
            ...

    return compose_wrap


def _exec_command(command: Iterable[str], *, compose_options: Tuple[str] = ()) -> None:
    check_system()
    try:
        check_output(["docker", "compose", *compose_options, "-f", compose_file, *command])
    except (CalledProcessError, FileNotFoundError) as e:
        try:
            check_output(["docker-compose", *compose_options, "-f", compose_file, *command])
        except (CalledProcessError, FileNotFoundError) as _e:
            raise RuntimeError(f"Error occurred while running {' '.join(command)}: {_e}") from _e
