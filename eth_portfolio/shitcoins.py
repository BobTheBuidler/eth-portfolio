
from y import Network, convert

shitcoins = {
    Network.Mainnet: [
        # Tagged as spam on Etherscan
        "0x1e4A0ADFC2e9bf2Dfd041Bc89405538d0D5A077a",
        "0xb07de4b2989E180F8907B8C7e617637C26cE2776",
        "0xa9517B2E61a57350D6555665292dBC632C76adFe",
        "0x6171136E82a2f1bAA2494c69528f599467EfeA20",
        "0xFD1860C9d602236214652a21753731F9acD2C362",
        # Tagged as phishing on Etherscan
        "0xCf39B7793512F03f2893C16459fd72E65D2Ed00c",
        "0x89532890c2959e836C1Bca52309356841238b8B7",
        "0xD1B0c350f73E6f7Cd5c9978b82B46a59aE9aD524",
        # Generally looks like shit
        "0xdb83eC9EEAC2b3CF8Eb282f91c73C38159578697",
        "0x242a705E8AF8A24B7EB30f3DbAF899eB25E3D76A",
        "0x0795619E02716a81ac9EF6E55363D538DA104e57",
    ],
}

SHITCOINS = {chain: [convert.to_address(token) for token in tokens] for chain, tokens in shitcoins.items()}
