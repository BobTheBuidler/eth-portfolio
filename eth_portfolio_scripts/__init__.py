from os import environ


environ["DANKMIDS_GANACHE_FORK"] = "0"
environ["DANKMIDS_COLLECT_STATS"] = "0"


from dotenv import load_dotenv


load_dotenv()


from eth_portfolio_scripts._logging import logger, setup_logging


setup_logging()


__all__ = ["logger"]
