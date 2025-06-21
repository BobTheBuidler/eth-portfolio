import logging
from functools import wraps
from importlib import resources
from os import path
from subprocess import CalledProcessError, check_output
from typing import Callable, Final, Iterable, List, Tuple, TypeVar

from typing_extensions import ParamSpec

from eth_portfolio_scripts.docker.check import check_system


logger: Final = logging.getLogger(__name__)

compose_file: Final = str(
    resources.files("eth_portfolio_scripts").joinpath("docker/docker-compose.yaml")
)


def up(*services: str) -> None:
    build(*services)
    print("starting the infra containers...")
    _exec_command(["up", "-d", *services])


def down() -> None:
    _exec_command(["down"])


def build(*services: str) -> None:
    print("building the grafana containers")
    _exec_command(["build", *services])


def stop(container_name: str) -> None:
    """
    Stop the specified container if it is running.
    Defaults to stopping the 'renderer' container.
    """
    print(f"stopping the {container_name} container...")
    _exec_command(["stop", container_name])


_P = ParamSpec("_P")
_T = TypeVar("_T")


def ensure_containers(fn: Callable[_P, _T]) -> Callable[_P, _T]:
    @wraps(fn)
    async def compose_wrap(*args: _P.args, **kwargs: _P.kwargs) -> _T:
        # register shutdown sequence
        # TODO: argument to leave them up
        # NOTE: do we need both this and the finally?
        # signal.signal(signal.SIGINT, down)

        # start Grafana containers
        up()

        try:
            # attempt to run `fn`
            return await fn(*args, **kwargs)
        finally:
            # stop and remove containers
            # down()
            pass

    return compose_wrap


def _exec_command(command: List[str], *, compose_options: Tuple[str, ...] = ()) -> None:
    check_system()
    try:
        check_output(["docker", "compose", *compose_options, "-f", compose_file, *command])
    except (CalledProcessError, FileNotFoundError) as e:
        try:
            check_output(["docker-compose", *compose_options, "-f", compose_file, *command])
        except (CalledProcessError, FileNotFoundError) as _e:
            raise RuntimeError(f"Error occurred while running {' '.join(command)}: {_e}") from _e
