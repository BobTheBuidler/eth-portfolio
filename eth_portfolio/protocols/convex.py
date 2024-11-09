from y import ERC20, Network

from eth_portfolio.protocols._base import ProtocolWithStakingABC, SingleTokenStakingPoolABC


class _CvxLockerV2(SingleTokenStakingPoolABC):
    contract_address = "0x72a19342e8F1838460eBFCCEf09F6585e32db86E"
    balance_method_name = "lockedBalanceOf"
    token = ERC20("0x4e3FBD56CD56c3e72c1403e103b45Db9da5B9D2B")


class Convex(ProtocolWithStakingABC):
    networks = [Network.Mainnet]

    def __init__(self) -> None:
        super().__init__()
        self.pools = [_CvxLockerV2()]
