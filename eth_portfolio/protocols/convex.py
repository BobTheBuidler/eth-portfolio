
from eth_portfolio.protocols._base import SingleTokenStakingPoolABC, ProtocolWithStakingABC

class CvxLockerV2(SingleTokenStakingPoolABC):
    contract_address = "0x72a19342e8F1838460eBFCCEf09F6585e32db86E"
    balance_method_name = "balanceOf"
    token = "0x4e3FBD56CD56c3e72c1403e103b45Db9da5B9D2B"

class Convex(ProtocolWithStakingABC):
    pools = [
        CvxLockerV2()
    ]
    