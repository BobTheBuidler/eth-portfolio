from asyncio import gather
from typing import TYPE_CHECKING

from y.datatypes import Block

if TYPE_CHECKING:
    from eth_portfolio._ledgers.address import AddressLedgerBase


class BlockRangeIsCached(Exception):
    """
    Exception raised when a block range is already cached.

    This exception indicates that the requested block range
    has already been loaded into memory and does not need to be fetched again.

    Examples:
        >>> raise BlockRangeIsCached("Block range is already cached.")
    """

    pass


class BlockRangeOutOfBounds(Exception):
    """
    Exception raised when a block range is out of bounds.

    This exception indicates that the requested block range
    is outside the bounds of the cached data. It provides a method to
    handle the loading of the remaining ledger entries that are out of bounds
    by invoking the appropriate method in the associated ledger.

    Args:
        start_block: The starting block number of the out-of-bounds range.
        end_block: The ending block number of the out-of-bounds range.
        ledger: The ledger associated with the block range.

    Examples:
        >>> raise BlockRangeOutOfBounds(100, 200, ledger)

    See Also:
        - :class:`~eth_portfolio._ledgers.address.AddressLedgerBase`: The base class for address ledgers.
    """

    def __init__(self, start_block: Block, end_block: Block, ledger: "AddressLedgerBase") -> None:
        self.ledger = ledger
        self.start_block = start_block
        self.end_block = end_block

    async def load_remaining(self) -> None:
        """
        Asynchronously handles the loading of the remaining ledger entries that are out of bounds.

        This method invokes the :meth:`~eth_portfolio._ledgers.address.AddressLedgerBase._load_new_objects`
        method of the associated ledger to fetch the ledger entries for the blocks that are outside
        the cached range, ensuring that the entire requested block range is covered.

        Examples:
            >>> await exception.load_remaining()

        See Also:
            - :meth:`~eth_portfolio._ledgers.address.AddressLedgerBase._load_new_objects`: Method to load new ledger entries.
        """
        return await gather(
            self.ledger._load_new_objects(self.start_block, self.ledger.cached_thru - 1),
            self.ledger._load_new_objects(self.ledger.cached_from + 1, self.end_block),
        )
