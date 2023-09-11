
import a_sync
import eth_retry
from async_lru import alru_cache
from eth_utils import to_checksum_address
from web3.types import TxReceipt
from y.utils.dank_mids import dank_w3

receipt_semaphore = a_sync.Semaphore(100)

@eth_retry.auto_retry
@alru_cache
async def get_transaction_receipt(txhash: str) -> TxReceipt:
    async with receipt_semaphore:
        return await dank_w3.eth.get_transaction_receipt(txhash)

def checksum(addr: str) -> str:
    """We keep a mapping here to save cpu cycles, checksumming is arduous."""
    try:
        return __checksums[addr]
    except KeyError:
        checksummed = __checksums[addr] = to_checksum_address(addr)
        return checksummed    

__checksums = {}