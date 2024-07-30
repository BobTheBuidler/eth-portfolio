
import asyncio
from typing import TYPE_CHECKING

from y.datatypes import Block

if TYPE_CHECKING:
    from eth_portfolio._ledgers.address import AddressLedgerBase

class BlockRangeIsCached(Exception):
    pass

class BlockRangeOutOfBounds(Exception):
    def __init__(self, start_block: Block, end_block: Block, ledger: "AddressLedgerBase") -> None:
        self.ledger = ledger
        self.start_block = start_block
        self.end_block = end_block
    async def load_remaining(self) -> None:
        return await asyncio.gather(
            self.ledger._load_new_objects(self.start_block, self.ledger.cached_thru - 1),
            self.ledger._load_new_objects(self.ledger.cached_from + 1, self.end_block)
        )