
from decimal import Decimal
from typing import Optional

from brownie import chain
from dank_mids.structs import Trace
from y._decorators import stuck_coro_debugger
from y.constants import EEE_ADDRESS

from eth_portfolio._loaders.utils import checksum, get_transaction_receipt, underscore
from eth_portfolio.structs import InternalTransfer
from eth_portfolio.utils import _get_price


@stuck_coro_debugger
async def load_internal_transfer(trace: Trace, load_prices: bool) -> Optional[InternalTransfer]:
    if trace.to == "0xd9Db270c1B5E3Bd161E8c8503c55cEABeE709552":  # Gnosis Safe Singleton 1.3.0
        # NOTE: Not sure why these appear, but I've yet to come across an internal transfer
        # that actually transmitted value to the singleton even though they appear to.
        return None

    params = {}

    if trace.type == "reward:
        if trace.action.rewardType == 'block':
            params = {'hash': 'block reward'}
        elif trace.action.rewardType == 'uncle':
            params = {'hash': 'uncle reward'}
        else:
            raise NotImplementedError(transfer.action.rewardType)
    else:
        # NOTE: We don't need to confirm block rewards came from a successful transaction, because they don't come from a transaction
        # In all other cases, we need to confirm the transaction didn't revert
        receipt = await get_transaction_receipt(trace.transactionHash)
        if receipt.status == 0:
            return None
        params = {'hash': trace.transactionHash}
        
    params['transaction_index'] = trace.transactionPosition
    params['chainid'] = chain.id

    # Un-nest the action dict
    if action := trace.action:
        for key, value in action.items():
            if key == 'author':
                # for block reward transfers, the recipient is 'author'
                transfer['to'] = value
            else:
                transfer[key] = value
            
    # Un-nest the result dict
    if result := trace.result:
        for key, value in result.items():
            transfer[key] = value

    # Remap the addresses
    if trace.sender:
        params['from_address'] = trace.sender
    if trace.to:
        params['to_address'] = trace.to

    value = Decimal(trace.value) / 10**18
    params['value'] = value
    params['gas'] = 0 if trace.type == "reward" and trace.action.rewardType in ["block", "uncle"] else trace.gas

    if load_prices:
        price = round(Decimal(await _get_price(EEE_ADDRESS, trace.blockNumber)), 18)
        params['price'] = price
        params['value_usd'] = round(value * price, 18)
    
    return InternalTransfer(**params)
    
