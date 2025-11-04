from functools import lru_cache
from subprocess import CalledProcessError, check_output
from typing import List


def check_docker() -> None:
    """
    Check that docker is installed on the user's system.

    Raises:
        RuntimeError: If docker is not installed.
    """
    print(" 🔍 checking your computer for docker")
    try:
        check_output(["docker", "--version"])
    except (CalledProcessError, FileNotFoundError):
        raise RuntimeError(
            "Docker is not installed. You must install Docker before using dao-treasury."
        ) from None
    else:
        print(" ✔️ eth-portfolio found docker!")


def check_docker_compose() -> List[str]:
    """
    Check that either `docker-compose` or `docker compose` is installed on the user's system.

    Returns:
        A valid compose command.

    Raises:
        RuntimeError: If docker-compose is not installed.
    """
    for cmd in ["docker-compose", "docker compose"]:
        print(f" 🔍 checking your computer for {cmd}")

        try:
            check_output([*cmd.split(" "), "--version"])
        except (CalledProcessError, FileNotFoundError):
            print(f" ❌ {cmd} not found")
            continue
        else:
            print(f" ✔️ eth-portfolio found {cmd}!")
            return cmd.split(" ")

    raise RuntimeError(
        "Docker Compose is not installed. You must install Docker Compose before using dao-treasury."
    ) from None


@lru_cache(maxsize=None)
def check_system() -> List[str]:
    """
    Check that docker and docker-compose is installed on the user's system.

    Returns:
        A valid compose command.

    Raises:
        RuntimeError: If docker-compose is not installed.
    """
    print("eth-portfolio is checking for the required docker dependencies...")
    check_docker()
    return check_docker_compose()


__all__ = ["check_docker", "check_docker_compose", "check_system"]
