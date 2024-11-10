import pytest
from pandas import DataFrame

from eth_portfolio._decimal import Decimal
from eth_portfolio.typing import (
    Balance,
    PortfolioBalances,
    PortfolioBalancesByCategory,
    RemoteTokenBalances,
    TokenBalances,
    WalletBalances,
    WalletBalancesRaw,
)

# Define constants for Ethereum addresses
ADDRESS_1 = "0x0000000000000000000000000000000000000001"
ADDRESS_2 = "0x0000000000000000000000000000000000000002"
ADDRESS_3 = "0x0000000000000000000000000000000000000003"
ADDRESS_4 = "0x0000000000000000000000000000000000000004"
WALLET_1 = "0x0000000000000000000000000000000000000005"
WALLET_2 = "0x0000000000000000000000000000000000000006"
WALLET_3 = "0x0000000000000000000000000000000000000007"


# Test Balance class
def test_balance_addition():
    b1 = Balance(balance=Decimal("10"), usd_value=Decimal("100"))
    b2 = Balance(balance=Decimal("5"), usd_value=Decimal("50"))
    b3 = b1 + b2
    assert b3.balance == Decimal("15")
    assert b3.usd_value == Decimal("150")


def test_balance_subtraction():
    b1 = Balance(balance=Decimal("10"), usd_value=Decimal("100"))
    b2 = Balance(balance=Decimal("5"), usd_value=Decimal("50"))
    b3 = b1 - b2
    assert b3.balance == Decimal("5")
    assert b3.usd_value == Decimal("50")


def test_balance_bool():
    b1 = Balance(balance=Decimal("0"), usd_value=Decimal("0"))
    b2 = Balance(balance=Decimal("10"), usd_value=Decimal("100"))
    assert not b1
    assert b2


def test_balance_addition_type_error():
    b1 = Balance(balance=Decimal("10"), usd_value=Decimal("100"))
    with pytest.raises(TypeError):
        b1 + 5


def test_balance_subtraction_type_error():
    b1 = Balance(balance=Decimal("10"), usd_value=Decimal("100"))
    with pytest.raises(TypeError):
        b1 - 5


# Test TokenBalances class
def test_tokenbalances_addition():
    tb1 = TokenBalances(
        {
            ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
            ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
        }
    )
    tb2 = TokenBalances(
        {
            ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
            ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
        }
    )
    tb3 = tb1 + tb2
    assert tb3[ADDRESS_1].balance == Decimal("15")
    assert tb3[ADDRESS_1].usd_value == Decimal("150")
    assert tb3[ADDRESS_2].balance == Decimal("30")
    assert tb3[ADDRESS_2].usd_value == Decimal("300")


def test_tokenbalances_subtraction():
    tb1 = TokenBalances(
        {
            ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
            ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
        }
    )
    tb2 = TokenBalances(
        {
            ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
            ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
        }
    )
    tb3 = tb1 - tb2
    assert tb3[ADDRESS_1].balance == Decimal("5")
    assert tb3[ADDRESS_1].usd_value == Decimal("50")
    assert tb3[ADDRESS_2].balance == Decimal("10")
    assert tb3[ADDRESS_2].usd_value == Decimal("100")


def test_tokenbalances_dataframe():
    tb = TokenBalances({ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100"))})
    df = tb.dataframe
    assert isinstance(df, DataFrame)
    assert "token" in df.columns


def test_tokenbalances_setitem_type_error():
    tb = TokenBalances()
    with pytest.raises(TypeError):
        tb[ADDRESS_1] = 100


def test_tokenbalances_default_key():
    tb = TokenBalances()
    assert tb[ADDRESS_1] == Balance()


# Test RemoteTokenBalances class
def test_remotetokenbalances_addition():
    rtb1 = RemoteTokenBalances(
        {
            "protocol1": TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                    ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
                }
            ),
            "protocol2": TokenBalances(
                {ADDRESS_3: Balance(balance=Decimal("30"), usd_value=Decimal("300"))}
            ),
        }
    )
    rtb2 = RemoteTokenBalances(
        {
            "protocol1": TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
                    ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                }
            ),
            "protocol2": TokenBalances(
                {ADDRESS_3: Balance(balance=Decimal("15"), usd_value=Decimal("150"))}
            ),
        }
    )
    rtb3 = rtb1 + rtb2
    assert rtb3["protocol1"][ADDRESS_1].balance == Decimal("15")
    assert rtb3["protocol1"][ADDRESS_1].usd_value == Decimal("150")
    assert rtb3["protocol1"][ADDRESS_2].balance == Decimal("30")
    assert rtb3["protocol1"][ADDRESS_2].usd_value == Decimal("300")
    assert rtb3["protocol2"][ADDRESS_3].balance == Decimal("45")
    assert rtb3["protocol2"][ADDRESS_3].usd_value == Decimal("450")


def test_remotetokenbalances_subtraction():
    rtb1 = RemoteTokenBalances(
        {
            "protocol1": TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                    ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
                }
            ),
            "protocol2": TokenBalances(
                {ADDRESS_3: Balance(balance=Decimal("30"), usd_value=Decimal("300"))}
            ),
        }
    )
    rtb2 = RemoteTokenBalances(
        {
            "protocol1": TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
                    ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                }
            ),
            "protocol2": TokenBalances(
                {ADDRESS_3: Balance(balance=Decimal("15"), usd_value=Decimal("150"))}
            ),
        }
    )
    rtb3 = rtb1 - rtb2
    assert rtb3["protocol1"][ADDRESS_1].balance == Decimal("5")
    assert rtb3["protocol1"][ADDRESS_1].usd_value == Decimal("50")
    assert rtb3["protocol1"][ADDRESS_2].balance == Decimal("10")
    assert rtb3["protocol1"][ADDRESS_2].usd_value == Decimal("100")
    assert rtb3["protocol2"][ADDRESS_3].balance == Decimal("15")
    assert rtb3["protocol2"][ADDRESS_3].usd_value == Decimal("150")


def test_remotetokenbalances_dataframe():
    rtb = RemoteTokenBalances(
        {
            "protocol1": TokenBalances(
                {ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100"))}
            )
        }
    )
    df = rtb.dataframe
    assert isinstance(df, DataFrame)
    assert "protocol" in df.columns


def test_remotetokenbalances_setitem_type_error():
    rtb = RemoteTokenBalances()
    with pytest.raises(TypeError):
        rtb["protocol1"] = 100


def test_remotetokenbalances_default_key():
    rtb = RemoteTokenBalances()
    assert rtb["protocol1"] == TokenBalances()


# Test WalletBalances class
def test_walletbalances_addition():
    wb1 = WalletBalances(
        {
            "assets": TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                    ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
                }
            )
        }
    )
    wb2 = WalletBalances(
        {
            "assets": TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
                    ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                }
            )
        }
    )
    wb3 = wb1 + wb2
    assert wb3.assets[ADDRESS_1].balance == Decimal("15")
    assert wb3.assets[ADDRESS_1].usd_value == Decimal("150")
    assert wb3.assets[ADDRESS_2].balance == Decimal("30")
    assert wb3.assets[ADDRESS_2].usd_value == Decimal("300")


def test_walletbalances_subtraction():
    wb1 = WalletBalances(
        {
            "assets": TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                    ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
                }
            )
        }
    )
    wb2 = WalletBalances(
        {
            "assets": TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
                    ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                }
            )
        }
    )
    wb3 = wb1 - wb2
    assert wb3.assets[ADDRESS_1].balance == Decimal("5")
    assert wb3.assets[ADDRESS_1].usd_value == Decimal("50")
    assert wb3.assets[ADDRESS_2].balance == Decimal("10")
    assert wb3.assets[ADDRESS_2].usd_value == Decimal("100")


def test_walletbalances_dataframe():
    wb = WalletBalances(
        {
            "assets": TokenBalances(
                {ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100"))}
            )
        }
    )
    df = wb.dataframe
    assert isinstance(df, DataFrame)
    assert "category" in df.columns


def test_walletbalances_setitem_type_error():
    wb = WalletBalances()
    with pytest.raises(TypeError):
        wb["assets"] = 100


def test_walletbalances_default_key():
    wb = WalletBalances()
    assert wb["assets"] == TokenBalances()
    assert wb["debt"] == RemoteTokenBalances()
    assert wb["external"] == RemoteTokenBalances()


# Test PortfolioBalances class
def test_portfoliobalances_addition():
    pb1 = PortfolioBalances(
        {
            WALLET_1: WalletBalances(
                {
                    "assets": TokenBalances(
                        {
                            ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                            ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
                        }
                    )
                }
            ),
            WALLET_2: WalletBalances(
                {
                    "assets": TokenBalances(
                        {ADDRESS_3: Balance(balance=Decimal("30"), usd_value=Decimal("300"))}
                    )
                }
            ),
        }
    )
    pb2 = PortfolioBalances(
        {
            WALLET_1: WalletBalances(
                {
                    "assets": TokenBalances(
                        {
                            ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
                            ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                        }
                    )
                }
            ),
            WALLET_2: WalletBalances(
                {
                    "assets": TokenBalances(
                        {ADDRESS_3: Balance(balance=Decimal("15"), usd_value=Decimal("150"))}
                    )
                }
            ),
        }
    )
    pb3 = pb1 + pb2
    assert pb3[WALLET_1].assets[ADDRESS_1].balance == Decimal("15")
    assert pb3[WALLET_1].assets[ADDRESS_1].usd_value == Decimal("150")
    assert pb3[WALLET_1].assets[ADDRESS_2].balance == Decimal("30")
    assert pb3[WALLET_1].assets[ADDRESS_2].usd_value == Decimal("300")
    assert pb3[WALLET_2].assets[ADDRESS_3].balance == Decimal("45")
    assert pb3[WALLET_2].assets[ADDRESS_3].usd_value == Decimal("450")


def test_portfoliobalances_subtraction():
    pb1 = PortfolioBalances(
        {
            WALLET_1: WalletBalances(
                {
                    "assets": TokenBalances(
                        {
                            ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                            ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
                        }
                    )
                }
            ),
            WALLET_2: WalletBalances(
                {
                    "assets": TokenBalances(
                        {ADDRESS_3: Balance(balance=Decimal("30"), usd_value=Decimal("300"))}
                    )
                }
            ),
        }
    )
    pb2 = PortfolioBalances(
        {
            WALLET_1: WalletBalances(
                {
                    "assets": TokenBalances(
                        {
                            ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
                            ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                        }
                    )
                }
            ),
            WALLET_2: WalletBalances(
                {
                    "assets": TokenBalances(
                        {ADDRESS_3: Balance(balance=Decimal("15"), usd_value=Decimal("150"))}
                    )
                }
            ),
        }
    )
    pb3 = pb1 - pb2
    assert pb3[WALLET_1].assets[ADDRESS_1].balance == Decimal("5")
    assert pb3[WALLET_1].assets[ADDRESS_1].usd_value == Decimal("50")
    assert pb3[WALLET_1].assets[ADDRESS_2].balance == Decimal("10")
    assert pb3[WALLET_1].assets[ADDRESS_2].usd_value == Decimal("100")
    assert pb3[WALLET_2].assets[ADDRESS_3].balance == Decimal("15")
    assert pb3[WALLET_2].assets[ADDRESS_3].usd_value == Decimal("150")


def test_portfoliobalances_dataframe():
    pb = PortfolioBalances(
        {
            WALLET_1: WalletBalances(
                {
                    "assets": TokenBalances(
                        {ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100"))}
                    )
                }
            )
        }
    )
    df = pb.dataframe
    assert isinstance(df, DataFrame)
    assert "wallet" in df.columns


def test_portfoliobalances_setitem_type_error():
    pb = PortfolioBalances()
    with pytest.raises(TypeError):
        pb[WALLET_1] = 100


def test_portfoliobalances_default_key():
    pb = PortfolioBalances()
    assert pb[WALLET_1] == WalletBalances()


# Test WalletBalancesRaw class
def test_walletbalancesraw_addition():
    wbr1 = WalletBalancesRaw(
        {
            WALLET_1: TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                    ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
                }
            ),
            WALLET_2: TokenBalances(
                {ADDRESS_3: Balance(balance=Decimal("30"), usd_value=Decimal("300"))}
            ),
        }
    )
    wbr2 = WalletBalancesRaw(
        {
            WALLET_1: TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
                    ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                }
            ),
            WALLET_2: TokenBalances(
                {ADDRESS_3: Balance(balance=Decimal("15"), usd_value=Decimal("150"))}
            ),
        }
    )
    wbr3 = wbr1 + wbr2
    assert wbr3[WALLET_1][ADDRESS_1].balance == Decimal("15")
    assert wbr3[WALLET_1][ADDRESS_1].usd_value == Decimal("150")
    assert wbr3[WALLET_1][ADDRESS_2].balance == Decimal("30")
    assert wbr3[WALLET_1][ADDRESS_2].usd_value == Decimal("300")
    assert wbr3[WALLET_2][ADDRESS_3].balance == Decimal("45")
    assert wbr3[WALLET_2][ADDRESS_3].usd_value == Decimal("450")


def test_walletbalancesraw_subtraction():
    wbr1 = WalletBalancesRaw(
        {
            WALLET_1: TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                    ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
                }
            ),
            WALLET_2: TokenBalances(
                {ADDRESS_3: Balance(balance=Decimal("30"), usd_value=Decimal("300"))}
            ),
        }
    )
    wbr2 = WalletBalancesRaw(
        {
            WALLET_1: TokenBalances(
                {
                    ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
                    ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                }
            ),
            WALLET_2: TokenBalances(
                {ADDRESS_3: Balance(balance=Decimal("15"), usd_value=Decimal("150"))}
            ),
        }
    )
    wbr3 = wbr1 - wbr2
    assert wbr3[WALLET_1][ADDRESS_1].balance == Decimal("5")
    assert wbr3[WALLET_1][ADDRESS_1].usd_value == Decimal("50")
    assert wbr3[WALLET_1][ADDRESS_2].balance == Decimal("10")
    assert wbr3[WALLET_1][ADDRESS_2].usd_value == Decimal("100")
    assert wbr3[WALLET_2][ADDRESS_3].balance == Decimal("15")
    assert wbr3[WALLET_2][ADDRESS_3].usd_value == Decimal("150")


def test_walletbalancesraw_default_key():
    wbr = WalletBalancesRaw()
    assert wbr[WALLET_1] == TokenBalances()


# Test PortfolioBalancesByCategory class
def test_portfoliobalancesbycategory_addition():
    pbc1 = PortfolioBalancesByCategory(
        {
            "assets": WalletBalancesRaw(
                {
                    WALLET_1: TokenBalances(
                        {
                            ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                            ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
                        }
                    ),
                    WALLET_2: TokenBalances(
                        {ADDRESS_3: Balance(balance=Decimal("30"), usd_value=Decimal("300"))}
                    ),
                }
            ),
            "debt": WalletBalancesRaw(
                {
                    WALLET_3: TokenBalances(
                        {ADDRESS_4: Balance(balance=Decimal("40"), usd_value=Decimal("400"))}
                    )
                }
            ),
        }
    )
    pbc2 = PortfolioBalancesByCategory(
        {
            "assets": WalletBalancesRaw(
                {
                    WALLET_1: TokenBalances(
                        {
                            ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
                            ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                        }
                    ),
                    WALLET_2: TokenBalances(
                        {ADDRESS_3: Balance(balance=Decimal("15"), usd_value=Decimal("150"))}
                    ),
                }
            ),
            "debt": WalletBalancesRaw(
                {
                    WALLET_3: TokenBalances(
                        {ADDRESS_4: Balance(balance=Decimal("20"), usd_value=Decimal("200"))}
                    )
                }
            ),
        }
    )
    pbc3 = pbc1 + pbc2
    assert pbc3["assets"][WALLET_1][ADDRESS_1].balance == Decimal("15")
    assert pbc3["assets"][WALLET_1][ADDRESS_1].usd_value == Decimal("150")
    assert pbc3["assets"][WALLET_1][ADDRESS_2].balance == Decimal("30")
    assert pbc3["assets"][WALLET_1][ADDRESS_2].usd_value == Decimal("300")
    assert pbc3["assets"][WALLET_2][ADDRESS_3].balance == Decimal("45")
    assert pbc3["assets"][WALLET_2][ADDRESS_3].usd_value == Decimal("450")
    assert pbc3["debt"][WALLET_3][ADDRESS_4].balance == Decimal("60")
    assert pbc3["debt"][WALLET_3][ADDRESS_4].usd_value == Decimal("600")


def test_portfoliobalancesbycategory_subtraction():
    pbc1 = PortfolioBalancesByCategory(
        {
            "assets": WalletBalancesRaw(
                {
                    WALLET_1: TokenBalances(
                        {
                            ADDRESS_1: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                            ADDRESS_2: Balance(balance=Decimal("20"), usd_value=Decimal("200")),
                        }
                    ),
                    WALLET_2: TokenBalances(
                        {ADDRESS_3: Balance(balance=Decimal("30"), usd_value=Decimal("300"))}
                    ),
                }
            ),
            "debt": WalletBalancesRaw(
                {
                    WALLET_3: TokenBalances(
                        {ADDRESS_4: Balance(balance=Decimal("40"), usd_value=Decimal("400"))}
                    )
                }
            ),
        }
    )
    pbc2 = PortfolioBalancesByCategory(
        {
            "assets": WalletBalancesRaw(
                {
                    WALLET_1: TokenBalances(
                        {
                            ADDRESS_1: Balance(balance=Decimal("5"), usd_value=Decimal("50")),
                            ADDRESS_2: Balance(balance=Decimal("10"), usd_value=Decimal("100")),
                        }
                    ),
                    WALLET_2: TokenBalances(
                        {ADDRESS_3: Balance(balance=Decimal("15"), usd_value=Decimal("150"))}
                    ),
                }
            ),
            "debt": WalletBalancesRaw(
                {
                    WALLET_3: TokenBalances(
                        {ADDRESS_4: Balance(balance=Decimal("20"), usd_value=Decimal("200"))}
                    )
                }
            ),
        }
    )
    pbc3 = pbc1 - pbc2
    assert pbc3["assets"][WALLET_1][ADDRESS_1].balance == Decimal("5")
    assert pbc3["assets"][WALLET_1][ADDRESS_1].usd_value == Decimal("50")
    assert pbc3["assets"][WALLET_1][ADDRESS_2].balance == Decimal("10")
    assert pbc3["assets"][WALLET_1][ADDRESS_2].usd_value == Decimal("100")
    assert pbc3["assets"][WALLET_2][ADDRESS_3].balance == Decimal("15")
    assert pbc3["assets"][WALLET_2][ADDRESS_3].usd_value == Decimal("150")
    assert pbc3["debt"][WALLET_3][ADDRESS_4].balance == Decimal("20")
    assert pbc3["debt"][WALLET_3][ADDRESS_4].usd_value == Decimal("200")


def test_portfoliobalancesbycategory_default_key():
    pbc = PortfolioBalancesByCategory()
    assert pbc["assets"] == WalletBalancesRaw()
    assert pbc["debt"] == WalletBalancesRaw()
