import dank_mids
import eth_retry
import msgspec
from a_sync import SmartProcessingQueue
from async_lru import alru_cache
from eth_typing import HexStr
from y._decorators import stuck_coro_debugger


@eth_retry.auto_retry
@alru_cache(maxsize=None, ttl=60 * 60)
@stuck_coro_debugger
async def _get_transaction_receipt(txhash: HexStr) -> msgspec.Raw:
    return await dank_mids.eth.get_transaction_receipt(
        txhash, decode_to=msgspec.Raw, decode_hook=None
    )


get_transaction_receipt = SmartProcessingQueue(_get_transaction_receipt, 5000)
