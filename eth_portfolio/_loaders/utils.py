
from functools import lru_cache

import a_sync
import dank_mids
import eth_retry
import inflection
from async_lru import alru_cache
from eth_utils import to_checksum_address
from web3.types import TxReceipt
from y.decorators import stuck_coro_debugger


@eth_retry.auto_retry
@alru_cache(ttl=60*60)
@stuck_coro_debugger
async def _get_transaction_receipt(txhash: str) -> TxReceipt:
    return await dank_mids.eth.get_transaction_receipt(txhash)

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

@lru_cache(maxsize=None)
def underscore(string: str) -> str:
    """cached to conserve cpu cycles\n\n""" + inflection.underscore.__doc__
    return inflection.underscore(string)   

__checksums = {}
