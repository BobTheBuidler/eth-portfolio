from abc import abstractmethod
from asyncio import Task, create_task, sleep
from logging import DEBUG, getLogger
from typing import AsyncIterator, List

import dank_mids
import evmspec
import y._db.log
from a_sync import ASyncIterable, ASyncIterator, as_yielded
from brownie import chain
from eth_utils import encode_hex
from y.datatypes import Address
from y.utils.events import ProcessedEvents

from eth_portfolio._loaders import load_token_transfer
from eth_portfolio._shitcoins import SHITCOINS
from eth_portfolio.constants import TRANSFER_SIGS
from eth_portfolio.structs import TokenTransfer


try:
    # this is only available in 4.0.0+
    from eth_abi import encode

    encode_address = lambda address: encode_hex(encode(["address"], [str(address)]))
except ImportError:
    from eth_abi import encode_single

    encode_address = lambda address: encode_hex(encode_single("address", str(address)))

logger = getLogger(__name__)
_logger_is_enabled_for = logger.isEnabledFor
_logger_log = logger._log


class _TokenTransfers(ProcessedEvents["Task[TokenTransfer]"]):
    """A helper mixin that contains all logic for fetching token transfers for a particular wallet address"""

    __slots__ = "address", "_load_prices"

    def __init__(self, address: Address, from_block: int, load_prices: bool = False):
        self.address = address
        self._load_prices = load_prices
        super().__init__(topics=self._topics, from_block=from_block)

    def __repr__(self) -> str:
        return f"{self.__class__.__name__}(address={self.address})"

    @property
    @abstractmethod
    def _topics(self) -> List: ...

    @ASyncIterator.wrap  # type: ignore [call-overload]
    async def yield_thru_block(self, block) -> AsyncIterator["Task[TokenTransfer]"]:
        if not _logger_is_enabled_for(DEBUG):
            async for task in self._objects_thru(block=block):
                yield task
            return

        _logger_log(DEBUG, "%s yielding all objects thru block %s", (self, block))
        async for task in self._objects_thru(block=block):
            _logger_log(
                DEBUG,
                "yielding %s at block %s [thru: %s, lock: %s]",
                (task, task.block, block, self._lock.value),
            )
            yield task
        _logger_log(DEBUG, "%s yield thru %s complete", (self, block))

    async def _extend(self, objs: List[evmspec.Log]) -> None:
        shitcoins = SHITCOINS.get(chain.id, set())
        append_loader_task = self._objects.append
        done = 0
        for log in objs:
            if log.address in shitcoins:
                continue
            # save i/o
            array_encodable_log = y._db.log.Log(**log)
            task = create_task(load_token_transfer(array_encodable_log, self._load_prices))
            task.block = log.block  # type: ignore [attr-defined]
            append_loader_task(task)
            done += 1
            # Make sure the event loop doesn't get blocked
            if done % 100 == 0:
                await sleep(0)

    def _get_block_for_obj(self, task: "Task[TokenTransfer]") -> int:
        return task.block  # type: ignore [attr-defined]

    def _process_event(self, task: "Task[TokenTransfer]") -> "Task[TokenTransfer]":
        return task

    def _done_callback(self, task: Task) -> None:
        if e := task.exception():
            self._exc = e
            logger.exception(e)
            raise e


class InboundTokenTransfers(_TokenTransfers):
    """A container that fetches and iterates over all inbound token transfers for a particular wallet address"""

    @property
    def _topics(self) -> List:
        return [TRANSFER_SIGS, None, encode_address(self.address)]


class OutboundTokenTransfers(_TokenTransfers):
    """A container that fetches and iterates over all outbound token transfers for a particular wallet address"""

    @property
    def _topics(self) -> List:
        return [TRANSFER_SIGS, encode_address(self.address)]


class TokenTransfers(ASyncIterable[TokenTransfer]):
    """
    A container that fetches and iterates over all token transfers for a particular wallet address.
    NOTE: These do not come back in chronologcal order.
    """

    def __init__(self, address: Address, from_block: int, load_prices: bool = False):
        self.transfers_in = InboundTokenTransfers(address, from_block, load_prices=load_prices)
        self.transfers_out = OutboundTokenTransfers(address, from_block, load_prices=load_prices)

    async def __aiter__(self):
        async for transfer in self.__yield_thru_block(await dank_mids.eth.block_number):
            yield transfer

    def yield_thru_block(self, block: int) -> ASyncIterator["Task[TokenTransfer]"]:
        return ASyncIterator(self.__yield_thru_block(block))

    def __yield_thru_block(self, block: int) -> AsyncIterator["Task[TokenTransfer]"]:
        return as_yielded(
            self.transfers_in.yield_thru_block(block), self.transfers_out.yield_thru_block(block)
        )
