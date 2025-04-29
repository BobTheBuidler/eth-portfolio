import os
from typing import Final

from brownie import chain
from y import Network, convert, weth

ERC20_TRANSFER_EVENT_HASH: Final = (
    "0xddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef"
)
ERC677_TRANSFER_EVENT_HASH: Final = (
    "0xe19260aff97b920c7df27010903aeb9c8d2be5d310a2c67824cf3f15396e4c16"
)

NUM_WALLETS: Final = int(os.environ.get("NUM_WALLETS", "10"))
ADDRESSES: Final = [
    convert.to_address(address)
    for address in {os.environ.get(f"PORTFOLIO_ADDRESS_{i}", None) for i in range(NUM_WALLETS)}
    if address is not None
]

TRANSFER_SIGS: Final = [ERC20_TRANSFER_EVENT_HASH, ERC677_TRANSFER_EVENT_HASH]

ETH_LIKE: Final = {
    Network.Mainnet: {
        "ETH",
        weth.address,
        "0xEeeeeEeeeEeEeeEeEeEeeEEEeeeeEeeeeeeeEEeE",
        "0x5e74C9036fb86BD7eCdcb084a0673EFc32eA31cb",  # seth
        "0xEeeeeEeeeEeEeeEeEeEeeEEEeeeeEeeeeeeeEEeE",  # eth
        "0xae7ab96520DE3A18E5e111B5EaAb095312D7fE84",  # steth
        "0x9559Aaa82d9649C7A7b220E7c461d2E74c9a3593",  # reth
        "0xE95A203B1a91a908F9B9CE46459d101078c2c3cb",  # ankreth
    },
}.get(chain.id, set())

BTC_LIKE: Final = {
    Network.Mainnet: {
        "0xEB4C2781e4ebA804CE9a9803C67d0893436bB27D",  # renbtc
        "0x2260FAC5E5542a773Aa44fBCfeDf7C193bc2C599",  # wbtc
        "0xfE18be6b3Bd88A2D2A7f928d00292E7a9963CfC6",  # sbtc
        "0x8064d9Ae6cDf087b1bcd5BDf3531bD5d8C537a68",  # obtc
        "0x9BE89D2a4cd102D8Fecc6BF9dA793be995C22541",  # bbtc
        "0x0316EB71485b0Ab14103307bf65a021042c6d380",  # hbtc
        "0x5228a22e72ccC52d415EcFd199F99D0665E7733b",  # pbtc
        "0x8dAEBADE922dF735c38C80C7eBD708Af50815fAa",  # tbtc
    },
}.get(chain.id, set())

INTL_STABLECOINS: Final = {
    Network.Mainnet: {
        "0xD71eCFF9342A5Ced620049e616c5035F1dB98620",  # sEUR
        "0xC581b735A1688071A1746c968e0798D642EDE491",  # EURT
        "0xdB25f211AB05b1c97D595516F45794528a807ad8",  # EURS
        "0x96E61422b6A9bA0e068B6c5ADd4fFaBC6a4aae27",  # ibEUR
        "0x269895a3dF4D73b077Fc823dD6dA1B95f72Aaf9B",  # sKRW
        "0x3F1B0278A9ee595635B61817630cC19DE792f506",  # sAUD
        "0x97fe22E7341a0Cd8Db6F6C021A24Dc8f4DAD855F",  # sGBP
        "0xF6b1C627e95BFc3c1b4c9B825a032Ff0fBf3e07d",  # sJPY
        "0x0F83287FF768D1c1e17a42F44d644D7F22e8ee1d",  # sCHF
        "0x269895a3dF4D73b077Fc823dD6dA1B95f72Aaf9B",  # sKRW
    },
}.get(chain.id, set())
