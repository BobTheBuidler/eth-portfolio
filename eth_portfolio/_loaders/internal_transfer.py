
from decimal import Decimal
from typing import Optional

import inflection
from brownie import chain
from y.constants import EEE_ADDRESS

from eth_portfolio._loaders.utils import checksum, get_transaction_receipt
from eth_portfolio.structs import InternalTransfer
from eth_portfolio.utils import _get_price


async def load_internal_transfer(transfer: dict, load_prices: bool) -> Optional[InternalTransfer]:
    receipt = await get_transaction_receipt(transfer['transactionHash'])
    if receipt.status == 0:
        return None
    del receipt

    # Un-nest the action dict
    if 'action' in transfer and transfer['action'] is not None:
        for k in list(transfer['action'].keys()):
            transfer[k] = transfer['action'].pop(k)
        if transfer['action']:
            raise ValueError(transfer['action'])
        del transfer['action']

    # Un-nest the result dict
    if 'result' in transfer and transfer['result'] is not None:
        for k in list(transfer['result'].keys()):
            transfer[k] = transfer['result'].pop(k)
        if transfer['result']:
            raise ValueError(transfer['result'])
        del transfer['result']

    # Checksum the addresses
    if "from" in transfer:
        transfer['from_address'] = checksum(transfer.pop('from'))
    if "to" in transfer:
        transfer['to_address'] = checksum(transfer.pop('to'))
    if "address" in transfer:
        transfer['address'] = checksum(transfer.pop('address'))
        
    transfer['value'] = Decimal(int(transfer['value'], 16)) / Decimal(1e18)
    transfer['gas'] = int(transfer['gas'], 16)
    transfer['gasUsed'] = int(transfer['gasUsed'], 16) if transfer['gasUsed'] else None

    if load_prices:
        price = await _get_price(EEE_ADDRESS, transfer['blockNumber'])
        price = round(Decimal(price), 18)
        transfer['price'] = price
        transfer['value_usd'] = round(transfer['value'] * price, 18)
        
    transfer['hash'] = transfer.pop('transactionHash')
    transfer['transaction_index'] = transfer.pop('transactionPosition')
    transfer['chainid'] = chain.id
    
    return InternalTransfer(**{inflection.underscore(k): v for k, v in transfer.items()})