from functools import lru_cache
from subprocess import CalledProcessError, check_output


def check_docker() -> None:
    """
    Check that docker is installed on the user's system.

    Raises:
        RuntimeError: If docker is not installed.
    """
    try:
        check_output(["docker", "--version"])
        print("docker found!")
    except (CalledProcessError, FileNotFoundError):
        print("checking your computer for docker")
        raise RuntimeError(
            "Docker is not installed. You must install Docker before using dao-treasury."
        ) from None


def check_docker_compose() -> None:
    """
    Check that docker-compose is installed on the user's system.

    Raises:
        RuntimeError: If docker-compose is not installed.
    """
    try:
        check_output(["docker-compose", "--version"])
        print("docker-compose found!")
    except (CalledProcessError, FileNotFoundError):
        print("checking your computer for docker-compose")
        try:
            check_output(["docker", "compose", "--version"])
            print("docker compose found!")
        except (CalledProcessError, FileNotFoundError):
            print("docker-compose not found, checking your computer for docker compose")
            raise RuntimeError(
                "Docker Compose is not installed. You must install Docker Compose before using dao-treasury."
            ) from None


@lru_cache(maxsize=None)
def check_system() -> None:
    """
    Check that docker and docker-compose is installed on the user's system.

    Raises:
        RuntimeError: If docker-compose is not installed.
    """
    check_docker()
    check_docker_compose()


__all__ = ["check_docker", "check_docker_compose", "check_system"]
