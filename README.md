# eth-portfolio
Use `eth-portfolio` to output information about your portfolio in a streamlined, speed-optimized way.

### Requirements
- Python 3.10 or higher.
- At least 16GB of RAM, 32GB for Base chain.

### Prerequisites
- First, you will need to bring your own archive node. This can be one you run yourself, or one from one of the common providers (Tenderly, Alchemy, QuickNode, etc.)
- You must configure a [brownie network](https://eth-brownie.readthedocs.io/en/stable/network-management.html) to use your RPC.
- You will also need an auth token for [Etherscan](https://etherscan.io/)'s API. Follow their [guide](https://docs.etherscan.io/etherscan-v2/getting-an-api-key) to get your key, and set env var `ETHERSCAN_TOKEN` with its value.

### Installation:
- Make sure you are using Python >= 3.9 and < 3.13. You should start with a fresh virtual environment, and then just...
```
pip install git+https://github.com/BobTheBuidler/eth-portfolio
```

### Usage:
For basic use, input each of your addresses as environment variables using the following pattern:
```
PORTFOLIO_ADDRESS_0=0x123...
PORTFOLIO_ADDRESS_1=0x234...
PORTFOLIO_ADDRESS_2=0x345...
```

Then do...
```
from eth_portfolio import portfolio
portfolio.eth_balance(block)

>>> {
        0xaddress0: _BalanceItem(balance=1234, usd_value=5678)
        0xaddress1: _BalanceItem(balance=1234, usd_value=5678)
        0xaddress2: _BalanceItem(balance=1234, usd_value=5678)
    }
```

Getting token transfers:
```
from eth_portfolio import portfolio
token_transfers = portfolio.token_transfers.get(start_block, end_block)
token_transfers.df()

>>> {
        0xaddress0: AddressTokenTransfersLedger(...)  # Each of these contains the token transfers for the specified address
        0xaddress1: AddressTokenTransfersLedger(...)
        0xaddress2: AddressTokenTransfersLedger(...)
    }
```

Getting transactions as a DataFrame:
```
from eth_portfolio import portfolio
txs = portfolio.transactions.get(start_block, end_block)
txs.df()

>>> [I am a pretend DataFrame]
```

Getting assets:
```
from eth_portfolio import portfolio
portfolio.describe(start_block, end_block)

>>>  {
        'assets': {
            'wallet0_address': {
                'token0': {
                    'amount': 123,
                    'value usd: 456,
                },
                'token1': {
                    'amount': 123,
                    'value usd: 456,
                },
            },
            'wallet0_address': {
                'token0': {
                    'amount': 123,
                    'value usd: 456,
                },
                'token1': {
                    'amount': 123,
                    'value usd: 456,
                },
            },
        },
        'debt': {
            'wallet0_address': {
                'token0': {
                    'amount': 123,
                    'value usd: 456,
                },
                'token1': {
                    'amount': 123,
                    'value usd: 456,
                },
            },
            'wallet1_address': {
                'token0': {
                    'amount': 123,
                    'value usd: 456,
                },
                'token1': {
                    'amount': 123,
                    'value usd: 456,
                },
            },
        },
    }
```

Getting net worth:
```
from eth_portfolio import portfolio
desc = portfolio.describe(block)
assets = desc['assets']     # OR you can do `assets = portfolio.assets(block)`
debt = desc['debt']         # OR you can do `debt = portfolio.debt(block)`
assets = sum(assets.values())
debt = sum(debt.values())
net = assets - debt
net.sum_usd()

>>> Decimal("123456.78900")
```

### Advanced:
You also have more granular control available using the Portfolio object:
```
from eth_portfolio import Portfolio
port = Portfolio([0xaddress0, 0xaddress1, 0xaddress2])
port.describe(chain.height)

# Or for async code
async_port = Portfolio([0xaddress0, 0xaddress1, 0xaddress2], asynchronous=True)
await port.describe(chain.height)
```
