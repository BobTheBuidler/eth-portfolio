
from decimal import Decimal
from typing import Optional

import inflection
from brownie import chain
from y.constants import EEE_ADDRESS
from y.decorators import stuck_coro_debugger

from eth_portfolio._loaders.utils import checksum, get_transaction_receipt
from eth_portfolio.structs import InternalTransfer
from eth_portfolio.utils import _get_price


@stuck_coro_debugger
async def load_internal_transfer(transfer: dict, load_prices: bool) -> Optional[InternalTransfer]:
    if transfer.get("to") == "0xd9db270c1b5e3bd161e8c8503c55ceabee709552":
        # "0xd9Db270c1B5E3Bd161E8c8503c55cEABeE709552":  # Gnosis Safe Singleton 1.3.0
        # NOTE: Not sure why these appear, but I've yet to come across an internal transfer
        # that actually transmitted value to the singleton even though they appear to.
        return None
        
    if is_block_reward(transfer):
        transfer['transactionHash'] = 'block reward'
    elif is_uncle_reward(transfer):
        transfer['transactionHash'] = 'uncle reward'
    else:
        # NOTE: We don't need to confirm block rewards came from a successful transaction, because they don't come from a transaction
        # In all other cases, we need to confirm the transaction didn't revert
        receipt = await get_transaction_receipt(transfer['transactionHash'])
        if receipt.status == 0:
            return None

    # Un-nest the action dict
    if action := transfer.pop('action', None):
        for key, value in action.items():
            transfer[key] = value
            
    # Un-nest the result dict
    if result := transfer.pop('result', None):
        for key, value in result.items():
            transfer[key] = value

    # Checksum the addresses
    if "from" in transfer:
        transfer['from_address'] = checksum(transfer.pop('from'))
    if "to" in transfer:
        transfer['to_address'] = checksum(transfer.pop('to'))
    if "address" in transfer:
        transfer['address'] = checksum(transfer.pop('address'))
        
    transfer['value'] = Decimal(int(transfer['value'], 16)) / Decimal(1e18)
    transfer['gas'] = 0 if is_block_reward(transfer) or is_uncle_reward(transfer) else int(transfer['gas'], 16)
    transfer['gasUsed'] = int(transfer['gasUsed'], 16) if transfer.get('gasUsed') else None

    if load_prices:
        price = await _get_price(EEE_ADDRESS, transfer['blockNumber'])
        price = round(Decimal(price), 18)
        transfer['price'] = price
        transfer['value_usd'] = round(transfer['value'] * price, 18)
        
    transfer['hash'] = transfer.pop('transactionHash')
    transfer['transaction_index'] = transfer.pop('transactionPosition', None)
    transfer['chainid'] = chain.id
    
    return InternalTransfer(**{inflection.underscore(k): v for k, v in transfer.items()})

def is_block_reward(transfer: dict) -> bool:
    return transfer['type'] == 'reward' and get_reward_type(transfer) == 'block'

def is_uncle_reward(transfer: dict) -> bool:
    return transfer['type'] == 'reward' and get_reward_type(transfer) == 'uncle'

def get_reward_type(transfer: dict) -> str:
    try:
        return transfer.get('rewardType') or transfer['action']['rewardType']
    except KeyError:
        raise ValueError('transfer is not reward type') from None
