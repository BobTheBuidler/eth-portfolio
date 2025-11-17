from os import environ

# Set DANKMIDS envs
environ["DANKMIDS_GANACHE_FORK"] = "0"
environ["DANKMIDS_COLLECT_STATS"] = "0"

YDB_CONNECTION_PARAMS = {
    "DB_PROVIDER": "postgres",
    "DB_HOST": "127.0.0.1",
    "DB_PORT": "5445",
    "DB_USER": "eth-portfolio-exporter",
    "DB_PASSWORD": "eth-portfolio-exporter",
    "DB_DATABASE": "eth-portfolio-exporter",
}

for key in YDB_CONNECTION_PARAMS:
    existing = environ.get(key)
    if existing is not None:
        raise RuntimeError(
            f"Environment variable {key} is already set to '{existing}', "
            f"but eth-portfolio requires it to be unset."
        )

# Set the db connection params for ypricemagic so it
# uses our Postgres container instead of sqlite
environ.update(YDB_CONNECTION_PARAMS)


from dotenv import load_dotenv


load_dotenv()


from eth_portfolio_scripts._logging import logger, setup_logging


setup_logging()


__all__ = ["logger"]
