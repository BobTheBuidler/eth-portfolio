from collections import defaultdict
from typing import DefaultDict, Final, Set

from eth_typing import ChecksumAddress
from y import Network, convert

stableish: Final = {
    Network.Mainnet: [
        "0x674C6Ad92Fd080e4004b2312b45f796a192D27a0",  # USDN
        "0x1456688345527bE1f37E9e627DA0837D6f08C925",  # USDP
        "0x865377367054516e17014CcdED1e7d814EDC9ce4",  # DOLA
        "0x5f98805A4E8be255a32880FDeC7F6728C6568bA0",  # LUSD
        "0x4Fabb145d64652a948d72533023f6E7A623C7C53",  # BUSD
        "0x853d955aCEf822Db058eb8505911ED77F175b99e",  # FRAX
        "0x5BC25f649fc4e26069dDF4cF4010F9f706c23831",  # DUSD
        "0x99D8a9C45b2ecA8864373A26D1459e3Dff1e17F3",  # MIM
        "0x056Fd409E1d7A124BD7017459dFEa2F387b6d5Cd",  # GUSD
        "0x03ab458634910AaD20eF5f1C8ee96F1D6ac54919",  # RAI
        "0x2A8e1E676Ec238d8A992307B495b45B3fEAa5e86",  # OUSD
        "0x57Ab1ec28D129707052df4dF418D58a2D46d5f51",  # sUSD
        "0xe2f2a5C287993345a840Db3B0845fbC70f5935a5",  # mUSD
        "0x5B3b5DF2BF2B6543f78e053bD91C4Bdd820929f1",  # USDM
        "0xdF574c24545E5FfEcb9a659c229253D4111d87e1",  # HUSD
        "0xa47c8bf37f92aBed4A126BDA807A7b7498661acD",  # UST
    ],
}

STABLEISH_COINS: DefaultDict[int, Set[ChecksumAddress]] = defaultdict(set)
"""
A dictionary that contains, for each chain, a set of 'stable-ish' coins that are considered stable by the wider market but not by ypriceamgic.

These coins, and wrapper tokens that contain them, will be considered stablecoins on all dashboards.
"""

for chain, tokens in stableish.items():
    STABLEISH_COINS[chain].update(convert.to_address(token) for token in tokens)
