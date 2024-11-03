from eth_portfolio.protocols._base import SingleTokenStakingPoolABC
from y import ERC20, Network


class LqtyStakingPool(SingleTokenStakingPoolABC):
    networks = [Network.Mainnet]
    contract_address = "0x4f9Fbb3f1E99B56e0Fe2892e623Ed36A76Fc605d"
    balance_method_name = "stakes"
    token = ERC20("0x6DEA81C8171D0bA574754EF6F8b412F2Ed88c54D")  # LQTY


class LiquityStabilityPool(SingleTokenStakingPoolABC):
    networks = [Network.Mainnet]
    contract_address = "0x66017D22b0f8556afDd19FC67041899Eb65a21bb"
    balance_method_name = "getCompoundedLUSDDeposit"
    token = ERC20("0x5f98805A4E8be255a32880FDeC7F6728C6568bA0")  # LUSD
