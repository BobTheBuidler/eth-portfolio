from functools import lru_cache
from subprocess import CalledProcessError, check_output


def check_docker() -> None:
    """
    Check that docker is installed on the user's system.

    Raises:
        RuntimeError: If docker is not installed.
    """
    print("    🔍 checking your computer for docker")
    try:
        check_output(["docker", "--version"])
    except (CalledProcessError, FileNotFoundError):
        raise RuntimeError(
            "Docker is not installed. You must install Docker before using dao-treasury."
        ) from None
    else:
        print("    ✔️ eth-portfolio found docker!")


def check_docker_compose() -> str:
    """
    Check that either `docker-compose` or `docker compose` is installed on the user's system.

    Returns:
        A valid compose command.

    Raises:
        RuntimeError: If docker-compose is not installed.
    """
    print("    🔍 checking your computer for docker-compose")
    try:
        check_output(["docker-compose", "--version"])
    except (CalledProcessError, FileNotFoundError):
        print("    ❌ docker-compose not found")
        print("    🔍 checking your computer for docker compose")
        try:
            check_output(["docker", "compose", "--version"])
        except (CalledProcessError, FileNotFoundError):
            raise RuntimeError(
                "Docker Compose is not installed. You must install Docker Compose before using dao-treasury."
            ) from None
        else:
            cmd = "docker compose"
    else:
        cmd = "docker-compose"
    print(f"    ✔️ eth-portfolio found {cmd}!")
    return cmd


@lru_cache(maxsize=None)
def check_system() -> str:
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
