import logging
from functools import wraps
from importlib import resources
from os import path
from subprocess import CalledProcessError, check_output
from typing import Callable, Final, Iterable, List, Literal, Tuple, TypeVar

from typing_extensions import ParamSpec

from eth_portfolio_scripts.docker.check import check_system


logger: Final = logging.getLogger(__name__)

COMPOSE_FILE: Final = str(
    resources.files("eth_portfolio_scripts").joinpath("docker/docker-compose.yaml")
)


def up(*services: str) -> None:
    """Build and start the specified docker-compose services."""
    build(*services)
    _print_notice("starting", services)
    _exec_command(["up", "-d", *services])


def down() -> None:
    """Stop all of eth-portfolio's docker-compose services."""
    _exec_command(["down"])


def build(*services: str) -> None:
    """Build the specified docker-compose services."""
    _print_notice("building", services)
    _exec_command(["build", *services])


def stop(*services: str) -> None:
    """Stop the specified docker-compose services, if running."""
    _print_notice("stopping", services)
    _exec_command(["stop", *services])


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


def _print_notice(
    doing: Literal["building", "starting", "stopping"],
    services: Tuple[str, ...],
) -> None:
    if len(services) == 1:
        container = services[0]
        print(f"{doing} the {container} container")
    elif len(services) == 2:
        first, second = services
        print(f"{doing} the {first} and {second} containers")
    else:
        *all_but_last, last = services
        print(f"{doing} the {', '.join(all_but_last)}, and {last} containers")


def _exec_command(
    command: List[str],
    *,
    compose_file: str = COMPOSE_FILE,
    compose_options: Tuple[str, ...] = (),
) -> None:
    compose = check_system()
    full_command = [*compose, *compose_options, "-f", compose_file, *command]
    try:
        check_output(full_command)
    except (CalledProcessError, FileNotFoundError) as e:
        raise RuntimeError(f"Error occurred while running `{' '.join(full_command)}`: {e}") from e
