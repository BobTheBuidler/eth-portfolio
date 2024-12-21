from asyncio import create_task, gather, get_event_loop
from contextlib import suppress
from functools import lru_cache
from typing import Any, Dict, Optional, Tuple, Union

import evmspec
import y._db.common
import y._db.config as config
from a_sync import PruningThreadPoolExecutor, a_sync
from brownie import chain
from eth_typing import ChecksumAddress
from evmspec.data import _decode_hook
from logging import getLogger
from msgspec import ValidationError, json
from multicall.utils import get_event_loop
from pony.orm import BindingError, OperationalError, commit, db_session, flush, select
from y._db.entities import db
from y.exceptions import reraise_excs_with_extra_context

from eth_portfolio._db import entities
from eth_portfolio._db.decorators import break_locks, requery_objs_on_diff_tx_err
from eth_portfolio._decimal import Decimal
from eth_portfolio.structs import InternalTransfer, TokenTransfer, Transaction, TransactionRLP
from eth_portfolio.typing import _P, _T, Fn

logger = getLogger(__name__)


def __bind():
    try:
        db.bind(**config.connection_settings)
    except BindingError as e:
        if not str(e).startswith("Database object was already bound to"):
            raise e


__bind()

try:
    db.generate_mapping(create_tables=True)
except OperationalError as e:
    if not str(e).startswith("no such column:"):
        raise
    raise OperationalError(
        "Since eth-portfolio extends the ypricemagic database with additional column definitions, you will need to delete your ypricemagic database at ~/.ypricemagic and rerun this script"
    ) from e

from y._db.decorators import retry_locked
from y._db.entities import Address, Block, Chain, Contract, Token, insert

# The db must be bound before we do this since we're adding some new columns to the tables defined in ypricemagic
from y._db.utils import ensure_chain, get_chain
from y._db.utils.price import _set_price
from y._db.utils.traces import insert_trace
from y import ERC20
from y.constants import EEE_ADDRESS
from y.exceptions import NonStandardERC20
from y.contracts import is_contract


_block_executor = PruningThreadPoolExecutor(4, "eth-portfolio block")
_token_executor = PruningThreadPoolExecutor(4, "eth-portfolio token")
_address_executor = PruningThreadPoolExecutor(4, "eth-portfolio address")
_transaction_read_executor = PruningThreadPoolExecutor(10, "eth-portfolio-transaction-read")
_transaction_write_executor = PruningThreadPoolExecutor(4, "eth-portfolio-transaction-write")
_token_transfer_read_executor = PruningThreadPoolExecutor(10, "eth-portfolio-token-transfer-read")
_token_transfer_write_executor = PruningThreadPoolExecutor(4, "eth-portfolio-token-transfer-write")
_internal_transfer_read_executor = PruningThreadPoolExecutor(
    10, "eth-portfolio-internal-transfer read"
)
_internal_transfer_write_executor = PruningThreadPoolExecutor(
    4, "eth-portfolio-internal-transfer write"
)


def robust_db_session(fn: Fn[_P, _T]) -> Fn[_P, _T]:
    return retry_locked(break_locks(db_session(fn)))


db_session_cached = lambda func: retry_locked(
    lru_cache(maxsize=None)(db_session(retry_locked(func)))
)


@a_sync(default="async", executor=_block_executor)
@robust_db_session
def get_block(block: int) -> entities.BlockExtended:
    if b := entities.BlockExtended.get(chain=chain.id, number=block):
        return b
    elif b := Block.get(chain=chain.id, number=block):
        if isinstance(b, entities.BlockExtended):
            # in case of race cndtn
            return b
        raise ValueError(b, b.number, b.chain.id)
        hash = b.hash
        ts = b.timestamp
        prices = [(price.token.address, price.price) for price in b.prices]
        logs = [json.decode(log.raw) for log in b.logs]
        traces = [json.decode(trace.raw) for trace in b.traces]
        for p in b.prices:
            p.delete()
        for l in b.logs:
            l.delete()
        for t in b.traces:
            t.delete()
        flush()
        b.delete()
        commit()
        b = insert(
            type=entities.BlockExtended,
            chain=get_chain(sync=True),
            number=block,
            hash=hash,
            timestamp=ts,
        )
        try:
            # for log in logs:
            #    insert_log(log)
            for trace in traces:
                insert_trace(trace)
        except Exception as e:
            e.args = (
                "This is really bad. Might need to nuke your db if you value your logs/traces",
                *e.args,
            )
            raise
        for token, price in prices:
            _set_price(token, price, sync=True)
    asdasd = get_chain(sync=True)
    if not isinstance(asdasd, Chain):
        raise TypeError(asdasd)
    commit()
    if b := insert(type=entities.BlockExtended, chain=asdasd, number=block):
        return b
    return entities.BlockExtended.get(chain=chain.id, number=block)


@a_sync(default="async", executor=_block_executor)
@db_session_cached
def ensure_block(block: int) -> None:
    get_block(block, sync=True)


# TODO refactor this out, async is annoying sometimes
# process = ProcessPoolExecutor(
#  1,
#  # NOTE: come on apple, what are you dooooin?
#  mp_context=get_context('fork'),
# )


def is_token(address) -> bool:
    if address == EEE_ADDRESS:
        return False
    # with suppress(NonStandardERC20):
    #    erc = ERC20(address)
    #    if all(erc.symbol, erc.name, erc.total_supply(), erc.scale):
    #    #if all(erc._symbol(), erc._name(), erc.total_supply(), erc._scale()):
    #        return True
    # return False
    return get_event_loop().run_until_complete(_is_token(address))


async def _is_token(address) -> bool:
    # just breaking a weird lock, dont mind me
    if retval := await get_event_loop().run_in_executor(process, __is_token, address):
        logger.debug("%s is token")
    else:
        logger.debug("%s is not token")
    return retval


def __is_token(address) -> bool:
    with suppress(NonStandardERC20):
        erc = ERC20(address, asynchronous=True)
        if all(
            get_event_loop().run_until_complete(
                gather(erc._symbol(), erc._name(), erc.total_supply_readable())
            )
        ):
            return True
    return False


@a_sync(default="async", executor=_address_executor)
@robust_db_session
def get_address(address: ChecksumAddress) -> entities.AddressExtended:
    entity_type = entities.TokenExtended
    entity = entities.Address.get(chain=chain.id, address=address)
    """ TODO: fix this later
    entity = entities.Address.get(chain=chain, address=address)
    if isinstance(entity, (Token, entities.TokenExtended)):
        entity_type = entities.TokenExtended
    elif isinstance(entity, (Contract, entities.ContractExtended)):
        entity_type = entities.ContractExtended
    elif isinstance(entity, (Address, entities.AddressExtended)):
        entity_type = entities.AddressExtended
    elif entity is None:
        # TODO: this logic should live in ypm, prob
        entity_type = entities.AddressExtended if not is_contract(address) else entities.TokenExtended if is_token(address) else entities.ContractExtended
    else:
        raise NotImplementedError(entity, entity_type)
        
    if isinstance(entity, entity_type):
        return entity
    
    elif entity:
        logger.debug("deleting %s", entity)
        entity.delete()
        commit()
    """
    if entity := entities.Address.get(chain=chain.id, address=address):
        return entity

    ensure_chain()
    return insert(type=entity_type, chain=chain.id, address=address) or entity_type.get(
        chain=chain.id, address=address
    )


@a_sync(default="async", executor=_address_executor)
@db_session_cached
def ensure_address(address: ChecksumAddress) -> None:
    get_address(address, sync=True)


@a_sync(default="async", executor=_address_executor)
@db_session_cached
def ensure_addresses(*addresses: ChecksumAddress) -> None:
    for address in addresses:
        ensure_address(address, sync=True)


@a_sync(default="async", executor=_token_executor)
@robust_db_session
def get_token(address: ChecksumAddress) -> entities.TokenExtended:
    if t := entities.TokenExtended.get(chain=chain.id, address=address):
        return t
    kwargs = {}
    if t := Address.get(chain=chain.id, address=address):
        if isinstance(t, entities.TokenExtended):
            # double check due to possible race cntdn
            return t
        """
        with suppress(TypeError):
            if t.notes:
                kwargs['notes'] = t.notes
        if isinstance(t, Contract):
            with suppress(TypeError):
                if t.deployer:
                    kwargs['deployer'] = t.deployer
            with suppress(TypeError):
                if t.deploy_block:
                    kwargs['deploy_block'] = t.deploy_block
        if isinstance(t, Token):
            with suppress(TypeError):
                if t.symbol:
                    kwargs['symbol'] = t.symbol
            with suppress(TypeError):
                if t.name:
                    kwargs['name'] = t.name
            with suppress(TypeError):
                if t.bucket:
                    kwargs['bucket'] = t.bucket
        """

        try:
            flush()
            t.delete()
            commit()
        except KeyError as e:
            raise KeyError(f"cant delete {t}") from e

    ensure_chain()
    commit()
    return insert(
        type=entities.TokenExtended, chain=chain.id, address=address, **kwargs
    ) or entities.TokenExtended.get(chain=chain.id, address=address)


@a_sync(default="async", executor=_token_executor)
@db_session_cached
def ensure_token(token_address: ChecksumAddress) -> None:
    get_token(token_address, sync=True)


async def get_transaction(sender: ChecksumAddress, nonce: int) -> Optional[Transaction]:
    transactions = await transactions_known_at_startup(chain.id, sender)
    if nonce in transactions:
        return decode_transaction(transactions.pop(nonce))
    return await _get_transaction(sender, nonce)

    
@a_sync(default="async", executor=_transaction_read_executor)
@robust_db_session
def _get_transaction(sender: ChecksumAddress, nonce: int) -> Optional[Transaction]:
    transactions = transactions_known_at_startup(chain.id, sender, sync=True)
    if nonce in transactions:
        return decode_transaction(transactions.pop(nonce))
    entity: entities.Transaction
    if entity := entities.Transaction.get(from_address=(chain.id, sender), nonce=nonce):
        return decode_transaction(entity.raw)


def decode_transaction(data: bytes) -> Union[Transaction, TransactionRLP]:
    try:
        try:
            return json.decode(data, type=Transaction, dec_hook=_decode_hook)
        except ValidationError as e:
            if str(e) == "Object missing required field `type` - at `$[2]`":
                return json.decode(data, type=TransactionRLP, dec_hook=_decode_hook)
            raise
    except Exception as e:
        e.args = *e.args, json.decode(data)
        raise


@a_sync(default="async", executor=_transaction_write_executor)
@robust_db_session
def delete_transaction(transaction: Transaction) -> None:
    if entity := entities.Transaction.get(**transaction.__db_primary_key__):
        entity.delete()


async def insert_transaction(transaction: Transaction) -> None:
    # Make sure these are in the db so below we can call them and use the results all in one transaction
    # NOTE: this create task -> await coro -> await task pattern is faster than a 2-task gather
    block_task = create_task(ensure_block(transaction.block_number))
    if to_address := transaction.to_address:
        await ensure_addresses(to_address, transaction.from_address)
    else:
        await ensure_address(transaction.from_address)
    await block_task
    await _insert_transaction(transaction)


@a_sync(default="async", executor=_transaction_write_executor)
@requery_objs_on_diff_tx_err
@robust_db_session
def _insert_transaction(transaction: Transaction) -> None:
    with reraise_excs_with_extra_context(transaction):
        entities.Transaction(
            **transaction.__db_primary_key__,
            block=(chain.id, transaction.block_number),
            transaction_index=transaction.transaction_index,
            hash=transaction.hash.hex(),
            to_address=(chain.id, transaction.to_address) if transaction.to_address else None,
            value=transaction.value,
            price=transaction.price,
            value_usd=transaction.value_usd,
            type=getattr(transaction, "type", None),
            gas=transaction.gas,
            gas_price=transaction.gas_price,
            max_fee_per_gas=getattr(transaction, "max_fee_per_gas", None),
            max_priority_fee_per_gas=getattr(transaction, "max_priority_fee_per_gas", None),
            raw=json.encode(transaction, enc_hook=enc_hook),
        )


@a_sync(default="async", executor=_internal_transfer_read_executor)
@robust_db_session
def get_internal_transfer(trace: evmspec.FilterTrace) -> Optional[InternalTransfer]:
    block = trace.blockNumber
    entity: entities.InternalTransfer
    if entity := entities.InternalTransfer.get(
        block=(chain.id, block),
        transaction_index=trace.transactionPosition,
        hash=trace.transactionHash,
        type=trace.type.name,
        call_type=trace.callType,
        from_address=(chain.id, trace.sender),
        to_address=(chain.id, trace.to),
        value=trace.value.scaled,
        trace_address=(chain.id, trace.traceAddress),
        gas=trace.gas,
        gas_used=trace.gasUsed if "gasUsed" in trace else None,
        input=trace.input,
        output=trace.output,
        subtraces=trace.subtraces,
        address=(chain.id, trace.address),
    ):
        return json.decode(entity.raw, type=InternalTransfer, dec_hook=_decode_hook)


@a_sync(default="async", executor=_internal_transfer_write_executor)
@robust_db_session
def delete_internal_transfer(transfer: InternalTransfer) -> None:
    if entity := entities.InternalTransfer.get(
        block=(chain.id, transfer.block_number),
        transaction_index=transfer.transaction_index,
        hash=transfer.hash,
        type=transfer.type,
        call_type=transfer.call_type,
        from_address=(chain.id, transfer.from_address),
        to_address=(chain.id, transfer.to_address),
        value=transfer.value,
        trace_address=(chain.id, transfer.trace_address),
        gas=transfer.gas,
        gas_used=transfer.gas_used,
        input=transfer.input,
        output=transfer.output,
        subtraces=transfer.subtraces,
        address=(chain.id, transfer.address),
    ):
        entity.delete()


async def insert_internal_transfer(transfer: InternalTransfer) -> None:
    # NOTE: this create task -> await coro -> await task pattern is faster than a 2-task gather
    block_task = create_task(ensure_block(transfer.block_number))
    if to_address := getattr(transfer, "to_address", None):
        await ensure_addresses(to_address, transfer.from_address)
    else:
        await ensure_address(transfer.from_address)
    await block_task
    await _insert_internal_transfer(transfer)


@a_sync(default="async", executor=_internal_transfer_write_executor)
@robust_db_session
def _insert_internal_transfer(transfer: InternalTransfer) -> None:
    entities.InternalTransfer(
        block=(chain.id, transfer.block_number),
        transaction_index=transfer.transaction_index,
        hash=transfer.hash,
        type=transfer.type,
        call_type=transfer.call_type,
        from_address=(chain.id, transfer.from_address),
        to_address=(chain.id, transfer.to_address),
        value=transfer.value,
        price=transfer.price,
        value_usd=transfer.value_usd,
        trace_address=str(transfer.trace_address),
        gas=transfer.gas,
        gas_used=transfer.gas_used,
        raw=json.encode(transfer, enc_hook=enc_hook),
    )


async def get_token_transfer(transfer: evmspec.Log) -> Optional[TokenTransfer]:
    pk = {
        "block": (chain.id, transfer.blockNumber),
        "transaction_index": transfer.transactionIndex,
        "log_index": transfer.logIndex,
    }
    db_transfers = await token_transfers_known_at_startup()
    data = db_transfers.pop(tuple(pk.values()), None) or await __get_token_transfer_bytes_from_db(pk)
    with reraise_excs_with_extra_context(tt_bytes):
        return json.decode(tt_bytes, type=TokenTransfer, dec_hook=_decode_hook)


@a_sync(default="async", executor=_token_transfer_read_executor)
@robust_db_session
def __get_token_transfer_bytes_from_db(pk: dict) -> Optional[bytes]:
    entity: entities.TokenTransfer
    if entity := entities.TokenTransfer.get(**pk):
        return entity.raw


_TPK = Tuple[Tuple[int, ChecksumAddress], int]


@a_sync(default="async", executor=_transaction_read_executor, ram_cache_maxsize=None)
@lru_cache(maxsize=None)
def transactions_known_at_startup(chainid: int, from_address: ChecksumAddress) -> Dict[_TPK, bytes]:
    return dict(
        select(
            (t.nonce, t.raw)
            for t in entities.Transaction  # type: ignore [attr-defined]
            if t.from_address.chain.id == chainid and t.from_address.address == from_address
        )
    )


_TokenTransferPK = Tuple[Tuple[int, int], int, int]


@a_sync(default="async", executor=_transaction_read_executor, ram_cache_maxsize=None)
@lru_cache(maxsize=None)
def token_transfers_known_at_startup() -> Dict[_TokenTransferPK, bytes]:
    chainid: int
    block: int
    tx_index: int
    log_index: int
    raw: bytes

    transfers = {}
    for chainid, block, tx_index, log_index, raw in select(
        (t.block.chain.id, t.block.number, t.transaction_index, t.log_index, t.raw)
        for t in entities.TokenTransfer  # type: ignore [attr-defined]
        if t.block.chain.id == chain.id
    ):
        pk = ((chainid, block), tx_index, log_index)
        transfers[pk] = raw
    return transfers


@a_sync(default="async", executor=_token_transfer_write_executor)
@robust_db_session
def delete_token_transfer(token_transfer: TokenTransfer) -> None:
    if entity := entities.TokenTransfer.get(
        block=(chain.id, token_transfer.block_number),
        transaction_index=token_transfer.transaction_index,
        log_index=token_transfer.log_index,
    ):
        entity.delete()


async def insert_token_transfer(token_transfer: TokenTransfer) -> None:
    # two tasks and a coroutine like this should be faster than gather
    block_task = create_task(ensure_block(token_transfer.block_number))
    while True:
        try:
            token_task = create_task(ensure_token(token_transfer.token_address))
        except KeyError:
            # This KeyError comes from a bug in cachetools.ttl_cache
            # TODO: move this handler into evmspec
            pass
        else:
            break

    while True:
        try:
            address_coro = ensure_addresses(token_transfer.to_address, token_transfer.from_address)
        except KeyError:
            # This KeyError comes from a bug in cachetools.ttl_cache
            # TODO: move this handler into evmspec
            pass
        else:
            break

    await address_coro
    await block_task
    await token_task
    await _insert_token_transfer(token_transfer)


@a_sync(default="async", executor=_token_transfer_write_executor)
@requery_objs_on_diff_tx_err
@robust_db_session
def _insert_token_transfer(token_transfer: TokenTransfer) -> None:
    entities.TokenTransfer(
        block=(chain.id, token_transfer.block_number),
        transaction_index=token_transfer.transaction_index,
        log_index=token_transfer.log_index,
        hash=token_transfer.hash.hex(),
        token=(chain.id, token_transfer.token_address),
        from_address=(chain.id, token_transfer.from_address),
        to_address=(chain.id, token_transfer.to_address),
        value=token_transfer.value,
        price=token_transfer.price,
        value_usd=token_transfer.value_usd,
        raw=json.encode(token_transfer, enc_hook=enc_hook),
    )
    commit()


def enc_hook(obj: Any) -> Any:
    try:
        return y._db.common.enc_hook(obj)
    except TypeError:
        if type(obj) is Decimal:
            return obj.jsonify()
        raise TypeError(type(obj), obj) from None
