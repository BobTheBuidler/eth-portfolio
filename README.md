# eth-portfolio
Use `eth-portfolio` to generate a dict that decsribes your full portfolio in detail at a given block.

Specify each of your addresses as environment variables using the following pattern:
```
PORTFOLIO_ADDRESS_0=0x123...
PORTFOLIO_ADDRESS_1=0x234...
PORTFOLIO_ADDRESS_2=0x345...
```
## Output
Output dict will take this format: 
```
{
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