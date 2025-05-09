import warnings
from logging import INFO, basicConfig, getLogger

from brownie.exceptions import BrownieCompilerWarning, BrownieEnvironmentWarning


logger = getLogger(__name__)


def setup_logging() -> None:
    basicConfig(level=INFO)


warnings.simplefilter("ignore", BrownieCompilerWarning)
warnings.simplefilter("ignore", BrownieEnvironmentWarning)
