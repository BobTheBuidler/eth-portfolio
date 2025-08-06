import logging
from typing import Any, Final, Optional, Set

from a_sync import igather
from async_lru import alru_cache
from eth_typing import ChecksumAddress
from y.constants import CHAINID, STABLECOINS, WRAPPED_GAS_COIN
from y.convert import to_address
from y.datatypes import Address, AnyAddressType
from y.exceptions import ContractNotVerified
from y.prices.lending.aave import aave
from y.prices.lending.compound import CToken, compound
from y.prices.stable_swap.curve import curve
from y.prices.yearn import YearnInspiredVault, is_yearn_vault

from eth_portfolio.constants import BTC_LIKE, ETH_LIKE, INTL_STABLECOINS
from eth_portfolio._stableish import STABLEISH_COINS

logger: Final = logging.getLogger(__name__)
log_debug: Final = logger.debug

SORT_AS_STABLES: Final = STABLECOINS.keys() | STABLEISH_COINS[CHAINID]
OTHER_LONG_TERM_ASSETS: Final[Set[ChecksumAddress]] = {}.get(CHAINID, set())  # type: ignore [call-overload]


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
    token_address = to_address(token)
    try:
        token_address = await _unwrap_token(token_address)
    except ContractNotVerified as e:
        return "Other short term assets"

    if _is_stable(token_address):
        return "Cash & cash equivalents"
    if token_address in ETH_LIKE:
        return "ETH"
    if token_address in BTC_LIKE:
        return "BTC"
    if token_address in OTHER_LONG_TERM_ASSETS:
        return "Other long term assets"
    return "Other short term assets"


@alru_cache(maxsize=None)
async def _unwrap_token(token: Any) -> ChecksumAddress:
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
    log_debug("unwrapping %s", token)
    if str(token) in {"ETH", "0xEeeeeEeeeEeEeeEeEeEeeEEEeeeeEeeeeeeeEEeE"}:
        log_debug("returning eee address")
        return token

    if await is_yearn_vault(token, sync=False):
        underlying = await YearnInspiredVault(token, asynchronous=True).underlying
        log_debug("underlying: %s", underlying)
        return await _unwrap_token(underlying)
    if curve and (pool := await curve.get_pool(token)):
        pool_tokens = set(await igather(map(_unwrap_token, await pool.coins)))
        log_debug("pool_tokens: %s", pool_tokens)
        if pool_bucket := _pool_bucket(pool_tokens):
            log_debug("returning pool bucket: %s", pool_bucket)
            return pool_bucket  # type: ignore
    if aave and await aave.is_atoken(token):
        log_debug("atoken")
        return str(await aave.underlying(token))
    if compound and await compound.is_compound_market(token):
        log_debug("unwrapping ctoken %s", token)
        try:
            return str(await CToken(token, asynchronous=True).underlying)
        except AttributeError:
            return WRAPPED_GAS_COIN
    log_debug("returning: %s", token)
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
    log_debug("Pool tokens: %s", pool_tokens)
    if pool_tokens < BTC_LIKE:
        return list(BTC_LIKE)[0]
    if pool_tokens < ETH_LIKE:
        return list(ETH_LIKE)[0]
    if pool_tokens < SORT_AS_STABLES:
        return list(SORT_AS_STABLES)[0]
    return list(INTL_STABLECOINS)[0] if pool_tokens < INTL_STABLECOINS else None


def _is_stable(token: ChecksumAddress) -> bool:
    """
    Check if a token is a stablecoin or stable-ish coin.

    This function checks if a given token is present in the :data:`STABLECOINS`,
    :data:`INTL_STABLECOINS`, or :data:`STABLEISH_COINS` sets, indicating that it is
    a stablecoin or considered stable by the wider market.

    Args:
        token: The address of the token to check.

    Example:
        Check if a token is a stablecoin or stable-ish coin:

        >>> _is_stable("0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48")
        True

    See Also:
        - :data:`STABLECOINS`
        - :data:`INTL_STABLECOINS`
        - :data:`STABLEISH_COINS`
    """
    return token in SORT_AS_STABLES or token in INTL_STABLECOINS
