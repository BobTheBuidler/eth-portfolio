
import abc
import asyncio
from typing import AsyncIterator, List

import a_sync
from brownie import chain
from eth_abi import encode_single
from eth_utils import encode_hex
from y.datatypes import Address
from y.utils.events import ProcessedEvents

from eth_portfolio import _loaders
from eth_portfolio.constants import TRANSFER_SIGS
from eth_portfolio.structs import TokenTransfer


class _TokenTransfers(ProcessedEvents["asyncio.Task[TokenTransfer]"]):
    __slots__ = "address", "_load_prices"
    def __init__(self, address: Address, from_block: int, load_prices: bool = False):
        self.address = address
        self._load_prices = load_prices
        super().__init__(topics=self._topics, from_block=from_block)
    def __repr__(self) -> str:
        return f"<{self.__class__.__module__}.{self.__class__.__name__} address={self.address}>"
    @abc.abstractproperty
    def _topics(self) -> List:
        ...
    async def yield_thru_block(self, block) -> AsyncIterator["asyncio.Task[TokenTransfer]"]:
        async for task in self._objects_thru(block=block):
            yield task
    def _extend(self, objs: List[dict]) -> None:
        tasks = []
        for log in objs:
            task = asyncio.create_task(_loaders.load_token_transfer(log, self._load_prices))
            task.block = log["blockNumber"]
            tasks.append(task)
    def _get_obj_block(self, task: "asyncio.Task[TokenTransfer]") -> int:
        return task.block
    def _process_event(self, task: "asyncio.Task[TokenTransfer]") -> "asyncio.Task[TokenTransfer]":
        return task

class InboundTokenTransfers(_TokenTransfers):
    """Transfers into Portfolio wallets"""
    @property
    def _topics(self) -> List:
        return [TRANSFER_SIGS, None, [encode_hex(encode_single('address', str(self.address)))]]

class OutboundTokenTransfers(_TokenTransfers):
    """Transfers out of Portfolio wallets"""
    @property
    def _topics(self) -> List:
        return [TRANSFER_SIGS, [encode_hex(encode_single('address', str(self.address)))]]
    
class TokenTransfers(a_sync.ASyncIterable[TokenTransfer]):
    """NOTE: These do not come back in numeric block order"""
    def __init__(self, address: Address, from_block: int, load_prices: bool = False):
        self.transfers_in = InboundTokenTransfers(address, from_block, load_prices=load_prices)
        self.transfers_out = OutboundTokenTransfers(address, from_block, load_prices=load_prices)
    
    def __aiter__(self):
        return self.yield_thru_block(chain.height)
    
    def yield_thru_block(self, block: int) -> a_sync.ASyncIterator["asyncio.Task[TokenTransfer]"]:
        return a_sync.ASyncIterator.wrap(
            a_sync.as_yielded(self.transfers_in.yield_thru_block(block), self.transfers_out.yield_thru_block(block))
        )
