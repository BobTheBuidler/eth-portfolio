import logging
from asyncio import gather
from typing import Optional, Set

from async_lru import alru_cache
from brownie import chain
from y.constants import STABLECOINS, WRAPPED_GAS_COIN
from y.datatypes import Address, AnyAddressType
from y.prices.lending.aave import aave
from y.prices.lending.compound import CToken, compound
from y.prices.stable_swap.curve import curve
from y.prices.yearn import YearnInspiredVault, is_yearn_vault

from eth_portfolio.constants import BTC_LIKE, ETH_LIKE, INTL_STABLECOINS

logger = logging.getLogger(__name__)

OTHER_LONG_TERM_ASSETS: Set[Address] = {}.get(chain.id, set())


async def get_token_bucket(token: AnyAddressType) -> str:
    """
    Categorize a token into a specific bucket based on its type.

    This function attempts to categorize a given token into predefined buckets
    such as "Cash & cash equivalents", "ETH", "BTC", "Other long term assets",
    or "Other short term assets". The categorization is based on the token's
    characteristics and its presence in specific sets like :data:`ETH_LIKE`, :data:`BTC_LIKE`,
    and :data:`OTHER_LONG_TERM_ASSETS`.

    Args:
        token: The address of the token to categorize.

    Returns:
        A string representing the bucket category of the token.

    Raises:
        ValueError: If the token's source has not been verified and the error message
        does not match the expected pattern.

    Example:
        Categorize a stablecoin:

        >>> await get_token_bucket("0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48")
        'Cash & cash equivalents'

        Categorize an ETH-like token:

        >>> await get_token_bucket("0xEeeeeEeeeEeEeeEeEeEeeEEEeeeeEeeeeeeeEEeE")
        'ETH'

    See Also:
        - :func:`_unwrap_token`
        - :func:`_is_stable`
    """
    token = str(token)
    try:
        token = str(await _unwrap_token(token))
    except ValueError as e:
        if str(e).startswith("Source for") and str(e).endswith("has not been verified"):
            return "Other short term assets"
        raise

    if _is_stable(token):
        return "Cash & cash equivalents"
    if token in ETH_LIKE:
        return "ETH"
    if token in BTC_LIKE:
        return "BTC"
    if token in OTHER_LONG_TERM_ASSETS:
        return "Other long term assets"
    return "Other short term assets"


@alru_cache(maxsize=None)
async def _unwrap_token(token) -> str:
    """
    Recursively unwrap a token to its underlying asset.

    This function attempts to unwrap a given token to its underlying asset by
    checking if the token is a Yearn vault, a Curve pool, an Aave aToken, or a
    Compound market. It recursively retrieves the underlying asset until it
    reaches the base token.

    Args:
        token: The address of the token to unwrap.

    Returns:
        The address of the underlying asset.

    Example:
        Unwrap a Yearn vault token:

        >>> await _unwrap_token("0x5f18C75AbDAe578b483E5F43f12a39cF75b973a9")
        '0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48'

    See Also:
        - :func:`y.prices.yearn.is_yearn_vault`
        - :class:`y.prices.yearn.YearnInspiredVault`
        - :class:`y.prices.stable_swap.curve`
        - :class:`y.prices.lending.aave`
        - :class:`y.prices.lending.compound.CToken`
    """
    if str(token) in {"ETH", "0xEeeeeEeeeEeEeeEeEeEeeEEEeeeeEeeeeeeeEEeE"}:
        return token

    if await is_yearn_vault(token, sync=False):
        underlying = await YearnInspiredVault(token, asynchronous=True).underlying
        return await _unwrap_token(underlying)
    if curve and (pool := await curve.get_pool(token)):
        pool_tokens = set(await gather(*[_unwrap_token(coin) for coin in await pool.coins]))
        if pool_bucket := _pool_bucket(pool_tokens):
            return pool_bucket  # type: ignore
    if aave and await aave.is_atoken(token):
        return str(await aave.underlying(token))
    if compound and await compound.is_compound_market(token):
        try:
            return str(await CToken(token, asynchronous=True).underlying)
        except AttributeError:
            return WRAPPED_GAS_COIN
    return token


def _pool_bucket(pool_tokens: set) -> Optional[str]:
    """
    Determine the bucket for a set of pool tokens.

    This function checks if a set of pool tokens belongs to specific categories
    such as BTC-like, ETH-like, or stablecoins, and returns the corresponding
    bucket.

    Args:
        pool_tokens: A set of token addresses representing the pool tokens.

    Returns:
        A string representing the bucket category of the pool tokens, or None if
        no specific category is found.

    Example:
        Determine the bucket for a BTC-like pool:

        >>> _pool_bucket({"0x2260FAC5E5542a773Aa44fBCfeDf7C193bc2C599"})
        '0x2260FAC5E5542a773Aa44fBCfeDf7C193bc2C599'

    See Also:
        - :data:`BTC_LIKE`
        - :data:`ETH_LIKE`
        - :data:`STABLECOINS`
        - :data:`INTL_STABLECOINS`
    """
    logger.debug("Pool tokens: %s", pool_tokens)
    if pool_tokens < BTC_LIKE:
        return list(BTC_LIKE)[0]
    if pool_tokens < ETH_LIKE:
        return list(ETH_LIKE)[0]
    if pool_tokens < STABLECOINS.keys():
        return list(STABLECOINS.keys())[0]
    return list(INTL_STABLECOINS)[0] if pool_tokens < INTL_STABLECOINS else None


def _is_stable(token: Address) -> bool:
    """
    Check if a token is a stablecoin.

    This function checks if a given token is present in the :data:`STABLECOINS` or
    :data:`INTL_STABLECOINS` sets, indicating that it is a stablecoin.

    Args:
        token: The address of the token to check.

    Example:
        Check if a token is a stablecoin:

        >>> _is_stable("0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48")
        True

    See Also:
        - :data:`STABLECOINS`
        - :data:`INTL_STABLECOINS`
    """
    return token in STABLECOINS or token in INTL_STABLECOINS
