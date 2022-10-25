
from eth_portfolio.protocols._base import SingleTokenStakingPoolABC
from y.classes.common import ERC20


class LiquityStabilityPool(SingleTokenStakingPoolABC):
    contract_address = "0x66017D22b0f8556afDd19FC67041899Eb65a21bb"
    balance_method_name = "getCompoundedLUSDDeposit"
    token = ERC20("0x5f98805A4E8be255a32880FDeC7F6728C6568bA0")  # LUSD

