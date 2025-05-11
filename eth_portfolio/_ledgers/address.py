"""
This module defines the :class:`~eth_portfolio.AddressLedgerBase`, :class:`~eth_portfolio.TransactionsList`,
:class:`~eth_portfolio.AddressTransactionsLedger`, :class:`~eth_portfolio.InternalTransfersList`,
:class:`~eth_portfolio.AddressInternalTransfersLedger`, :class:`~eth_portfolio.TokenTransfersList`,
and :class:`~eth_portfolio.AddressTokenTransfersLedger` classes. These classes manage and interact with ledger entries
such as transactions, internal transfers, and token transfers associated with Ethereum addresses within the `eth-portfolio` system.

These classes leverage the `a_sync` library to support both synchronous and asynchronous operations, allowing efficient data gathering
and processing without blocking, thus improving the overall responsiveness and performance of portfolio operations.
"""

from abc import ABCMeta, abstractmethod
from asyncio import Lock, Queue, create_task, gather, sleep
from collections import defaultdict
from functools import partial
from http import HTTPStatus
from itertools import product
from logging import getLogger
from typing import (
    TYPE_CHECKING,
    AsyncGenerator,
    AsyncIterator,
    Callable,
    Final,
    Generic,
    List,
    NoReturn,
    Optional,
    Tuple,
    Type,
    TypeVar,
    Union,
)

import a_sync
import dank_mids
import eth_retry
from a_sync.asyncio import sleep0 as yield_to_loop
from aiohttp import ClientResponseError
from async_lru import alru_cache
from brownie import chain
from dank_mids.eth import TraceFilterParams
from eth_typing import BlockNumber, ChecksumAddress
from evmspec import FilterTrace
from evmspec.structs.receipt import Status
from evmspec.structs.trace import call, reward
from typing_extensions import Unpack
from pandas import DataFrame  # type: ignore
from tqdm import tqdm
from y import ERC20, Network
from y._decorators import stuck_coro_debugger
from y.datatypes import Block
from y.utils.events import BATCH_SIZE

from eth_portfolio import _exceptions, _loaders
from eth_portfolio._cache import cache_to_disk
from eth_portfolio._decorators import set_end_block_if_none
from eth_portfolio._loaders.transaction import get_nonce_at_block, load_transaction
from eth_portfolio._utils import PandableList, _AiterMixin, get_buffered_chain_height
from eth_portfolio._ydb.token_transfers import TokenTransfers
from eth_portfolio.structs import InternalTransfer, TokenTransfer, Transaction

if TYPE_CHECKING:
    from eth_portfolio.address import PortfolioAddress

logger = getLogger(__name__)


T = TypeVar("T")

_LedgerEntryList = TypeVar(
    "_LedgerEntryList", "TransactionsList", "InternalTransfersList", "TokenTransfersList"
)
PandableLedgerEntryList = Union["TransactionsList", "InternalTransfersList", "TokenTransfersList"]


class AddressLedgerBase(
    a_sync.ASyncGenericBase, _AiterMixin[T], Generic[_LedgerEntryList, T], metaclass=ABCMeta
):
    """
    Abstract base class for address ledgers in the eth-portfolio system.
    """

    __slots__ = (
        "address",
        "asynchronous",
        "cached_from",
        "cached_thru",
        "load_prices",
        "objects",
        "portfolio_address",
        "_lock",
    )

    def __init__(self, portfolio_address: "PortfolioAddress") -> None:
        """
        Initializes the AddressLedgerBase instance.

        Args:
            portfolio_address: The :class:`~eth_portfolio.address.PortfolioAddress` this ledger belongs to.
        """

        # TODO replace the following line with an abc implementation.
        # assert isinstance(portfolio_address, PortfolioAddress), f"address must be a PortfolioAddress. try passing in PortfolioAddress({portfolio_address}) instead."

        super().__init__()

        self.portfolio_address = portfolio_address
        """
        The portfolio address this ledger belongs to.
        """

        self.address: Final = self.portfolio_address.address
        """
        The Ethereum address being managed.
        """

        self.asynchronous: Final = self.portfolio_address.asynchronous
        """
        Flag indicating if the operations are asynchronous.
        """

        self.load_prices: Final = self.portfolio_address.load_prices
        """
        Indicates if price loading is enabled.
        """

        self.objects: Final[_LedgerEntryList] = self._list_type()
        """
        _LedgerEntryList: List of ledger entries.
        """

        # NOTE: The following two properties will both be ints once the cache has contents
        self.cached_from: int = None  # type: ignore
        """
        The block from which all entries for this ledger have been loaded into memory.
        """

        self.cached_thru: int = None  # type: ignore
        """
        The block through which all entries for this ledger have been loaded into memory.
        """

        self._lock: Final = Lock()
        """
        Lock: Lock for synchronizing access to ledger entries.
        """

    def __hash__(self) -> int:
        """
        Returns the hash of the address.

        Returns:
            The hash value.
        """
        return hash(self.address)

    def __repr__(self) -> str:
        return f"<{type(self).__name__} for {self.address} at {hex(id(self))}>"

    @property
    @abstractmethod
    def _list_type(self) -> Type[_LedgerEntryList]:
        """
        Type of list used to store ledger entries.
        """
        ...

    @property
    def _start_block(self) -> int:
        """
        Returns the starting block for the portfolio address.

        Returns:
            The starting block number.
        """
        return self.portfolio_address._start_block

    async def _get_and_yield(
        self, start_block: Block, end_block: Block, mem_cache: bool
    ) -> AsyncGenerator[T, None]:
        """
        Yields ledger entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Yields:
            AsyncGenerator[T, None]: An async generator of ledger entries.
        """
        num_yielded = 0

        async def unblock_loop() -> None:
            """
            Let the event loop run at least once for every 100
            objects yielded so it doesn't get too congested.
            """
            nonlocal num_yielded
            num_yielded += 1
            if num_yielded % 500 == 0:
                await yield_to_loop()

        if not mem_cache:
            async for ledger_entry in self._get_new_objects(start_block, end_block, False):
                yield ledger_entry
                await unblock_loop()
            return

        if self.objects and end_block and self.objects[-1].block_number > end_block:
            for ledger_entry in self.objects:
                block = ledger_entry.block_number
                if block < start_block:
                    continue
                elif block > end_block:
                    return
                yield ledger_entry
                await unblock_loop()

        yielded = set()
        for ledger_entry in self.objects:
            block = ledger_entry.block_number
            if block < start_block:
                continue
            elif end_block and block > end_block:
                break
            yield ledger_entry
            yielded.add(ledger_entry)
            await unblock_loop()
        async for ledger_entry in self._get_new_objects(start_block, end_block, True):  # type: ignore [assignment, misc]
            if ledger_entry not in yielded:
                yield ledger_entry
                yielded.add(ledger_entry)
                await unblock_loop()
        for ledger_entry in self.objects:
            block = ledger_entry.block_number
            if block < start_block:
                continue
            elif end_block and block > end_block:
                break
            if ledger_entry not in yielded:
                yield ledger_entry
                yielded.add(ledger_entry)
                await unblock_loop()

    @set_end_block_if_none
    @stuck_coro_debugger
    async def get(self, start_block: Block, end_block: Block) -> _LedgerEntryList:
        """
        Retrieves ledger entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Returns:
            _LedgerEntryList: The list of ledger entries.

        Examples:
            >>> entries = await ledger.get(12000000, 12345678)
        """
        return self._list_type([ledger_entry async for ledger_entry in self[start_block:end_block]])

    @stuck_coro_debugger
    async def new(self) -> _LedgerEntryList:
        """
        Retrieves new ledger entries since the last cached block.

        Returns:
            _LedgerEntryList: The list of new ledger entries.

        Examples:
            >>> new_entries = await ledger.new()
        """
        start_block = 0 if self.cached_thru is None else self.cached_thru + 1
        end_block = await get_buffered_chain_height()
        return self[start_block, end_block]  # type: ignore [index, return-value]

    async def sent(
        self, start_block: Optional[Block] = None, end_block: Optional[Block] = None
    ) -> AsyncIterator[T]:
        address = self.portfolio_address.address
        async for obj in self[start_block:end_block]:
            if obj.from_address == address:
                yield obj

    async def received(
        self, start_block: Optional[Block] = None, end_block: Optional[Block] = None
    ) -> AsyncIterator[T]:
        address = self.portfolio_address.address
        async for obj in self[start_block:end_block]:
            if obj.from_address != address:
                yield obj

    @stuck_coro_debugger
    @set_end_block_if_none
    async def _get_new_objects(
        self, start_block: Block, end_block: Block, mem_cache: bool
    ) -> AsyncIterator[T]:
        """
        Retrieves new ledger entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Yields:
            AsyncIterator[T]: An async iterator of new ledger entries.
        """
        async with self._lock:
            async for ledger_entry in self._load_new_objects(start_block, end_block, mem_cache):
                yield ledger_entry

    @abstractmethod
    async def _load_new_objects(
        self, start_block: Block, end_block: Block, mem_cache: bool
    ) -> AsyncIterator[T]:
        """
        Abstract method to load new ledger entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Yields:
            AsyncIterator[T]: An async iterator of new ledger entries.
        """
        yield  # type: ignore [misc]

    def _check_blocks_against_cache(
        self, start_block: Block, end_block: Block
    ) -> Tuple[Block, Block]:
        """
        Checks the specified block range against the cached block range.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Returns:
            Tuple: The adjusted block range.

        Raises:
            ValueError: If the start block is after the end block.
            _exceptions.BlockRangeIsCached: If the block range is already cached.
            _exceptions.BlockRangeOutOfBounds: If the block range is out of bounds.
        """
        if start_block > end_block:
            raise ValueError(f"Start block {start_block} is after end block {end_block}")

        # There is no cache
        elif self.cached_from is None or self.cached_thru is None:
            return start_block, end_block

        # Range is cached
        elif start_block >= self.cached_from and end_block <= self.cached_thru:
            raise _exceptions.BlockRangeIsCached()

        # Beginning of range is cached
        elif (
            start_block >= self.cached_from
            and start_block < self.cached_thru
            and end_block > self.cached_thru
        ):
            return self.cached_thru + 1, end_block

        # End of range is cached
        elif (
            start_block < self.cached_from
            and end_block >= self.cached_from
            and end_block < self.cached_thru
        ):
            return start_block, self.cached_from - 1

        # Beginning and end both outside bounds of cache to high side
        elif start_block > self.cached_thru:
            return self.cached_thru + 1, end_block

        # Beginning and end both outside bounds of cache to low side
        elif end_block < self.cached_from:
            return start_block, self.cached_from - 1

        # Beginning and end both outside bounds of cache, split
        elif start_block < self.cached_from and end_block > self.cached_thru:
            raise _exceptions.BlockRangeOutOfBounds(start_block, end_block, self)

        raise NotImplementedError(
            f"This is a work in progress and we still need code for this specific case. Feel free to create an issue on our github if you need this.\n\nstart_block: {start_block} end_block: {end_block} cached_from: {self.cached_from} cached_thru: {self.cached_thru}"
        )


class TransactionsList(PandableList[Transaction]):
    """
    A list subclass for transactions that can convert to a :class:`DataFrame`.
    """

    def _df(self) -> DataFrame:
        """
        Converts the list of transactions to a DataFrame.

        Returns:
            DataFrame: The transactions as a DataFrame.
        """
        df = DataFrame(self)
        if len(df) > 0:
            df.chainId = df.chainId.apply(int)
            df.blockNumber = df.blockNumber.apply(int)
            df.transactionIndex = df.transactionIndex.apply(int)
            df.nonce = df.nonce.apply(int)
            df.gas = df.gas.apply(int)
            df.gasPrice = df.gasPrice.apply(int)
        return df


Nonce = int


class AddressTransactionsLedger(AddressLedgerBase[TransactionsList, Transaction]):
    """
    A ledger for managing transaction entries.
    """

    _list_type = TransactionsList
    __slots__ = ("cached_thru_nonce", "_queue", "_ready", "_num_workers", "_workers")

    def __init__(self, portfolio_address: "PortfolioAddress", num_workers: int = 1000):
        """
        Initializes the AddressTransactionsLedger instance.

        Args:
            portfolio_address: The :class:`~eth_portfolio.address.PortfolioAddress` this ledger belongs to.
        """
        super().__init__(portfolio_address)
        self.cached_thru_nonce = -1
        """
        The nonce through which all transactions have been loaded into memory.
        """
        self._queue = Queue()
        self._ready = Queue()
        self._num_workers = num_workers
        self._workers = []

    def __del__(self) -> None:
        self.__stop_workers()

    @stuck_coro_debugger
    @set_end_block_if_none
    async def _load_new_objects(self, _: Block, end_block: Block, mem_cache: bool) -> AsyncIterator[Transaction]:  # type: ignore [override]
        """
        Loads new transaction entries between the specified blocks.

        Args:
            _: The starting block number (unused).
            end_block: The ending block number.

        Yields:
            AsyncIterator[Transaction]: An async iterator of transaction entries.
        """
        if self.cached_thru and end_block < self.cached_thru:
            return
        if not mem_cache:
            logger.warning(
                f"{type(self).__name__}._load_new_objects mem_cache arg is not yet implemented"
            )
        address = self.address
        end_block_nonce: int = await get_nonce_at_block(address, end_block)
        if nonces := tuple(range(self.cached_thru_nonce + 1, end_block_nonce + 1)):
            for i, nonce in enumerate(nonces):
                self._queue.put_nowait(nonce)

                # Keep the event loop relatively unblocked
                # and let the rpc start doing work asap
                if i % 1000:
                    await yield_to_loop()

            len_nonces = len(nonces)
            del nonces

            self._ensure_workers(min(len_nonces, self._num_workers))

            transactions = []
            transaction: Optional[Transaction]
            for _ in tqdm(range(len_nonces), desc=f"Transactions        {address}"):
                nonce, transaction = await self._ready.get()
                if transaction:
                    if isinstance(transaction, Exception):
                        raise transaction
                    transactions.append(transaction)
                    yield transaction
                elif nonce == 0 and self.cached_thru_nonce == -1:
                    # Gnosis safes
                    self.cached_thru_nonce = 0
                else:
                    # NOTE Are we sure this is the correct way to handle this scenario? Are we sure it will ever even occur with the new gnosis handling?
                    logger.warning("No transaction with nonce %s for %s", nonce, address)

            self.__stop_workers()

            if transactions:
                self.objects.extend(transactions)
            if self.objects:
                self.objects.sort(key=lambda t: t.nonce)
                self.cached_thru_nonce = self.objects[-1].nonce

        if self.cached_from is None:
            self.cached_from = 0
        if self.cached_thru is None or end_block > self.cached_thru:
            self.cached_thru = end_block

    def _ensure_workers(self, num_workers: int) -> None:
        len_workers = len(self._workers)
        if len_workers < num_workers:
            worker_fn = self.__worker_fn
            address = self.address
            load_prices = self.load_prices
            queue_get = stuck_coro_debugger(self._queue.get)
            put_ready = self._ready.put_nowait

            self._workers.extend(
                create_task(
                    coro=worker_fn(address, load_prices, queue_get, put_ready),
                    name=f"AddressTransactionsLedger worker {i} for {address}",
                )
                for i in range(num_workers - len_workers)
            )

    async def __worker_fn(
        self,
        address: ChecksumAddress,
        load_prices: bool,
        queue_get: Callable[[], Nonce],
        put_ready: Callable[[Nonce, Optional[Transaction]], None],
    ) -> NoReturn:
        try:
            while True:
                nonce = await queue_get()
                try:
                    put_ready(await load_transaction(address, nonce, load_prices))
                except Exception as e:
                    put_ready((nonce, e))
        except Exception as e:
            logger.error("%s in %s __worker_coro", type(e), self)
            logger.exception(e)
            raise

    def __stop_workers(self) -> None:
        logger.debug("stopping workers for %s", self)
        workers = self._workers
        pop_next = workers.pop
        for _ in range(len(workers)):
            pop_next().cancel()


class InternalTransfersList(PandableList[InternalTransfer]):
    """
    A list subclass for internal transfer entries that can convert to a :class:`DataFrame`.
    """


@a_sync.Semaphore(128, __name__ + ".trace_filter")
@stuck_coro_debugger
@eth_retry.auto_retry
async def trace_filter(
    from_block: BlockNumber,
    to_block: BlockNumber,
    params: TraceFilterParams,
) -> List[FilterTrace]:
    return await __trace_filter(from_block, to_block, params)


async def __trace_filter(
    from_block: BlockNumber,
    to_block: BlockNumber,
    params: TraceFilterParams,
) -> List[FilterTrace]:
    try:
        return await dank_mids.eth.trace_filter(
            {"fromBlock": from_block, "toBlock": to_block, **params}
        )
    except ClientResponseError as e:
        if e.status != HTTPStatus.SERVICE_UNAVAILABLE or to_block == from_block:
            raise
    except TypeError as e:
        # This is some intermittent error I need to debug in dank_mids, I think it occurs when we get rate limited
        if str(e) != "a bytes-like object is required, not 'NoneType'":
            raise
        await sleep(0.5)
        # remove this logger when I know there are no looping issues
        logger.info("call failed, trying again")

    range_size = to_block - from_block + 1
    chunk_size = range_size // 2
    halfway = from_block + chunk_size

    results = await gather(
        __trace_filter(from_block, BlockNumber(halfway), params),
        __trace_filter(BlockNumber(halfway + 1), to_block, params),
    )
    return results[0] + results[1]


@alru_cache(maxsize=None)
@eth_retry.auto_retry(min_sleep_time=1, max_sleep_time=3, max_retries=20, suppress_logs=1)
async def get_transaction_status(txhash: str) -> Status:
    """
    Retrieves the status for a transaction.

    This function is cached to disk to reduce resource usage.

    Args:
        txhash: The hash of the transaction.

    Returns:
        The status of the transaction.
    """
    return await dank_mids.eth.get_transaction_status(txhash)


_trace_semaphores = defaultdict(lambda: a_sync.Semaphore(4, __name__ + ".trace_semaphore"))


@cache_to_disk
@eth_retry.auto_retry
async def get_traces(
    from_block: BlockNumber,
    to_block: BlockNumber,
    filter_params: TraceFilterParams,
) -> List[FilterTrace]:
    """
    Retrieves traces from the web3 provider using the given parameters.

    This function is cached to disk to reduce resource usage.

    Args:
        filter_params: The parameters for the trace filter.

    Returns:
        The list of traces.
    """
    if chain.id == Network.Polygon:
        logger.warning(
            "polygon doesnt support trace_filter method, must develop alternate solution"
        )
        return []
    semaphore_key = (
        tuple(filter_params.get("toAddress", ("",))),
        tuple(filter_params.get("fromAddress", ("",))),
    )
    async with _trace_semaphores[semaphore_key]:
        traces = await trace_filter(from_block, to_block, filter_params)
    return await _check_traces(traces) if traces else []


@stuck_coro_debugger
@eth_retry.auto_retry
async def _check_traces(traces: List[FilterTrace]) -> List[FilterTrace]:
    good_traces = []
    append = good_traces.append

    check_status_tasks = a_sync.TaskMapping(get_transaction_status)

    for i, trace in enumerate(traces):
        # Make sure we don't block up the event loop
        if i % 500:
            await yield_to_loop()

        if "error" in trace:
            continue

        # NOTE: Not sure why these appear, but I've yet to come across an internal transfer
        # that actually transmitted value to the singleton even though they appear to.
        if (
            isinstance(trace, call.Trace)
            and trace.action.to == "0xd9Db270c1B5E3Bd161E8c8503c55cEABeE709552"
        ):  # Gnosis Safe Singleton 1.3.0
            continue

        if not isinstance(trace, reward.Trace):
            # NOTE: We don't need to confirm block rewards came from a successful transaction, because they don't come from a transaction
            check_status_tasks[trace.transactionHash]

        append(trace)

    # NOTE: We don't need to confirm block rewards came from a successful transaction, because they don't come from a transaction
    return [
        trace
        for trace in good_traces
        if isinstance(trace, reward.Trace)
        or await check_status_tasks[trace.transactionHash] == Status.success
    ]


BlockRange = Tuple[Block, Block]


def _get_block_ranges(start_block: Block, end_block: Block) -> List[BlockRange]:
    return [(i, i + BATCH_SIZE - 1) for i in range(start_block, end_block, BATCH_SIZE)]


class AddressInternalTransfersLedger(AddressLedgerBase[InternalTransfersList, InternalTransfer]):
    """
    A ledger for managing internal transfer entries.
    """

    _list_type = InternalTransfersList

    @stuck_coro_debugger
    @set_end_block_if_none
    async def _load_new_objects(
        self, start_block: Block, end_block: Block, mem_cache: bool
    ) -> AsyncIterator[InternalTransfer]:
        """
        Loads new internal transfer entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Yields:
            AsyncIterator[InternalTransfer]: An async iterator of internal transfer entries.
        """
        if start_block == 0:
            start_block = 1

        if mem_cache:
            try:
                start_block, end_block = self._check_blocks_against_cache(start_block, end_block)
            except _exceptions.BlockRangeIsCached:
                return
            except _exceptions.BlockRangeOutOfBounds as e:
                await e.load_remaining()
                return

        # TODO: figure out where this float comes from and raise a TypeError there
        if isinstance(start_block, float) and int(start_block) == start_block:
            start_block = int(start_block)
        if isinstance(end_block, float) and int(end_block) == end_block:
            end_block = int(end_block)

        address = self.address
        if start_block == end_block:
            trace_filter_coros = [
                get_traces(start_block, end_block, {"toAddress": [address]}),
                get_traces(start_block, end_block, {"fromAddress": [address]}),
            ]
        else:
            block_ranges = _get_block_ranges(start_block, end_block)
            addr_filters = {"toAddress": [address]}, {"fromAddress": [address]}
            trace_filter_coros = [
                get_traces(start, end, addr_filter)
                for (start, end), addr_filter in product(block_ranges, addr_filters)
            ]

        # NOTE: We only want tqdm progress bar when there is work to do
        if len(trace_filter_coros) < 10:
            generator_function = a_sync.as_completed
        else:
            generator_function = partial(  # type: ignore [assignment]
                a_sync.as_completed, tqdm=True, desc=f"Trace Filters       {address}"
            )

        load = InternalTransfer.from_trace

        if mem_cache:
            internal_transfers = []
            append_transfer = internal_transfers.append

        done = 0
        if self.load_prices:
            traces = []
            async for chunk in generator_function(trace_filter_coros, aiter=True):
                traces.extend(chunk)

            if traces:
                tasks = []
                while traces:
                    tasks.extend(
                        create_task(load(trace, load_prices=True)) for trace in traces[:5000]
                    )
                    traces = traces[5000:]
                    # let the tasks start sending calls to your node now
                    # without waiting for all tasks to be created
                    await yield_to_loop()

                async for internal_transfer in a_sync.as_completed(
                    tasks, aiter=True, tqdm=True, desc=f"Internal Transfers  {address}"
                ):
                    if internal_transfer is not None:
                        if mem_cache:
                            append_transfer(internal_transfer)
                        yield internal_transfer

                    done += 1
                    if done % 1000 == 0:
                        await yield_to_loop()

        else:
            async for chunk in generator_function(trace_filter_coros, aiter=True):
                for trace in chunk:
                    internal_transfer = await load(trace, load_prices=False)
                    if internal_transfer is not None:
                        if mem_cache:
                            append_transfer(internal_transfer)
                        yield internal_transfer

                    done += 1
                    if done % 1000 == 0:
                        await yield_to_loop()

        if mem_cache and internal_transfers:
            self.objects.extend(internal_transfers)
            self.objects.sort(key=lambda t: (t.block_number, t.transaction_index))

        if self.cached_from is None or start_block < self.cached_from:
            self.cached_from = start_block
        if self.cached_thru is None or end_block > self.cached_thru:
            self.cached_thru = end_block


_yield_tokens_semaphore = a_sync.Semaphore(
    10, name="eth_portfolio._ledgers.address._yield_tokens_semaphore"
)


class TokenTransfersList(PandableList[TokenTransfer]):
    """
    A list subclass for token transfer entries that can convert to a :class:`DataFrame`.
    """


class AddressTokenTransfersLedger(AddressLedgerBase[TokenTransfersList, TokenTransfer]):
    """
    A ledger for managing token transfer entries.
    """

    _list_type = TokenTransfersList
    __slots__ = ("_transfers",)

    def __init__(self, portfolio_address: "PortfolioAddress"):
        """
        Initializes the AddressTokenTransfersLedger instance.

        Args:
            portfolio_address: The :class:`~eth_portfolio.address.PortfolioAddress` this ledger belongs to.
        """
        super().__init__(portfolio_address)
        self._transfers = TokenTransfers(
            self.address, self.portfolio_address._start_block, load_prices=self.load_prices
        )
        """
        TokenTransfers: Instance for handling token transfer operations.
        """

    @stuck_coro_debugger
    async def list_tokens_at_block(self, block: Optional[int] = None) -> List[ERC20]:
        """
        Lists the tokens held at a specific block.

        Args:
            block (Optional[int], optional): The block number. Defaults to None.

        Returns:
            List[ERC20]: The list of ERC20 tokens.

        Examples:
            >>> tokens = await ledger.list_tokens_at_block(12345678)
        """
        return [token async for token in self._yield_tokens_at_block(block)]

    async def _yield_tokens_at_block(self, block: Optional[int] = None) -> AsyncIterator[ERC20]:
        """
        Yields the tokens held at a specific block.

        Args:
            block (Optional[int], optional): The block number. Defaults to None.

        Yields:
            AsyncIterator[ERC20]: An async iterator of ERC20 tokens.
        """
        async with _yield_tokens_semaphore:
            yielded = set()
            async for transfer in self[:block]:
                address = transfer.token_address
                if address not in yielded:
                    yielded.add(address)
                    yield ERC20(address, asynchronous=self.asynchronous)

    @stuck_coro_debugger
    @set_end_block_if_none
    async def _load_new_objects(self, start_block: Block, end_block: Block, mem_cache: bool) -> AsyncIterator[TokenTransfer]:  # type: ignore [override]
        """
        Loads new token transfer entries between the specified blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Yields:
            AsyncIterator[TokenTransfer]: An async iterator of token transfer entries.
        """
        if mem_cache:
            try:
                start_block, end_block = self._check_blocks_against_cache(start_block, end_block)
            except _exceptions.BlockRangeIsCached:
                return
            except _exceptions.BlockRangeOutOfBounds as e:
                await e.load_remaining()
                return

        if tasks := [
            task
            async for task in self._transfers.yield_thru_block(end_block)
            if start_block <= task.block  # type: ignore [attr-defined]
        ]:
            token_transfers = []
            append_token_transfer = token_transfers.append
            done = 0
            async for token_transfer in a_sync.as_completed(
                tasks, aiter=True, tqdm=True, desc=f"Token Transfers     {self.address}"
            ):
                if token_transfer:
                    if mem_cache:
                        append_token_transfer(token_transfer)
                    yield token_transfer

                # Don't let the event loop get congested
                done += 1
                if done % 100 == 0:
                    await yield_to_loop()

            if mem_cache and token_transfers:
                self.objects.extend(token_transfers)
                self.objects.sort(key=lambda t: (t.block_number, t.transaction_index, t.log_index))

        if self.cached_from is None or start_block < self.cached_from:
            self.cached_from = start_block
        if self.cached_thru is None or end_block > self.cached_thru:
            self.cached_thru = end_block
