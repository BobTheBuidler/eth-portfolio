import asyncio
import logging
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

OTHER_LONG_TERM_ASSETS: Set[Address] = {
}.get(chain.id, set())


async def get_token_bucket(token: AnyAddressType) -> str:
    token = str(token)
    try:
        token = str(await _unwrap_token(token))
    except ValueError as e:
        if str(e).startswith('Source for') and str(e).endswith('has not been verified'):
            return 'Other short term assets'
        raise
    
    if _is_stable(token):
        return 'Cash & cash equivalents'
    if token in ETH_LIKE:
        return 'ETH'
    if token in BTC_LIKE:
        return 'BTC'
    if token in OTHER_LONG_TERM_ASSETS:
        return 'Other long term assets'
    return 'Other short term assets'

@alru_cache(maxsize=None)
async def _unwrap_token(token) -> str:
    '''
    Unwraps the base
    '''
    if str(token) in ["ETH", "0xEeeeeEeeeEeEeeEeEeEeeEEEeeeeEeeeeeeeEEeE"]:
        return token

    if await is_yearn_vault(token, sync=False):
        #contract = await Contract.coroutine(token)
        #underlying = await contract.token.coroutine()
        underlying = await YearnInspiredVault(token, asynchronous=True).underlying
        return await _unwrap_token(underlying)
    if curve and (pool := await curve.get_pool(token)):
        pool_tokens = set(await asyncio.gather(*[_unwrap_token(coin) for coin in await pool.coins]))
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
    logger.debug(f'Pool tokens: {pool_tokens}')
    if pool_tokens < BTC_LIKE:
        return list(BTC_LIKE)[0]
    if pool_tokens < ETH_LIKE:
        return list(ETH_LIKE)[0]
    if pool_tokens < STABLECOINS.keys():
        return list(STABLECOINS.keys())[0]
    if pool_tokens < INTL_STABLECOINS:
        return list(INTL_STABLECOINS)[0]
    return None

def _is_stable(token: Address) -> bool:
    return any([
        token in STABLECOINS,
        token in INTL_STABLECOINS,
    ])
