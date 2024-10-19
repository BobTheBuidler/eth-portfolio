
import a_sync
import eth_retry
import msgspec
from async_lru import alru_cache
from dank_mids.structs.data import TransactionHash
from eth_utils import to_checksum_address
from y._decorators import stuck_coro_debugger


@eth_retry.auto_retry
@alru_cache(ttl=60*60)
@stuck_coro_debugger
async def _get_transaction_receipt(txhash: TransactionHash) -> msgspec.Raw:
    return await txhash.get_receipt(txhash, decode_to=msgspec.Raw, decode_hook=None)

get_transaction_receipt = a_sync.SmartProcessingQueue(
    _get_transaction_receipt, 
    num_workers=1000, 
    name=__name__ + ".get_transaction_receipt",
)

def checksum(addr: str) -> str:
    """We keep a mapping here to save cpu cycles, checksumming is arduous."""
    try:
        return __checksums[addr]
    except KeyError:
        checksummed = __checksums[addr] = to_checksum_address(addr)
        return checksummed

__checksums = {}
