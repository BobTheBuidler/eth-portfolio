from datetime import datetime, timezone
from logging import getLogger
from math import floor
from typing import Awaitable, Callable, Final, Iterator, List, Optional, Tuple

import a_sync
import eth_retry
from a_sync.functools import cached_property_unsafe as cached_property
from eth_typing import BlockNumber, ChecksumAddress
from msgspec import ValidationError, json
from y import ERC20, Network, NonStandardERC20, get_block_at_timestamp
from y.constants import CHAINID
from y.time import NoBlockFound

from eth_portfolio import Portfolio
from eth_portfolio.buckets import get_token_bucket
from eth_portfolio.portfolio import _DEFAULT_LABEL
from eth_portfolio.typing import (
    Addresses,
    Balance,
    RemoteTokenBalances,
    PortfolioBalances,
    TokenBalances,
)
from eth_portfolio_scripts import victoria


NETWORK_LABEL: Final = Network.label(CHAINID)

decode: Final = json.decode

logger: Final = getLogger("eth_portfolio")
log_debug: Final = logger.debug
log_error: Final = logger.error


class ExportablePortfolio(Portfolio):
    """Adds methods to export full portoflio data."""

    def __init__(
        self,
        addresses: Addresses,
        start_block: int = 0,
        label: str = _DEFAULT_LABEL,
        load_prices: bool = True,
        get_bucket: Callable[[ChecksumAddress], Awaitable[str]] = get_token_bucket,
        num_workers_transactions: int = 1000,
        asynchronous: bool = False,
    ):
        super().__init__(
            addresses, start_block, label, load_prices, num_workers_transactions, asynchronous
        )
        self.get_bucket = get_bucket

    @cached_property
    def _data_queries(self) -> Tuple[str, str]:
        label = self.label.lower().replace(" ", "_")
        return f"{label}_assets", f"{label}_debts"

    @eth_retry.auto_retry
    @a_sync.Semaphore(16)
    async def data_exists(self, dt: datetime) -> bool:
        # sourcery skip: use-contextlib-suppress
        async for data in a_sync.as_completed(list(self.__get_data_exists_coros(dt)), aiter=True):
            try:
                result = decode(data, type=victoria.types.Response)
            except ValidationError:
                raise victoria.VictoriaMetricsError(data.decode()) from None
            if result.status == "success" and len(result.data.result) > 0:
                print(f"{dt} already loaded")
                return True
        return False

    async def export_snapshot(self, dt: datetime) -> None:
        log_debug("checking data at %s for %s", dt, self.label)
        try:
            if not await self.data_exists(dt, sync=False):
                while True:
                    try:
                        block = await get_block_at_timestamp(dt, sync=False)
                    except NoBlockFound:
                        pass
                    else:
                        break
                log_debug("block at %s: %s", dt, block)
                data = await self.get_data_for_export(block, dt, sync=False)
                await victoria.post_data(data)
        except Exception as e:
            log_error("Error processing %s:", dt, exc_info=True)

    @a_sync.Semaphore(60)
    async def get_data_for_export(self, block: BlockNumber, ts: datetime) -> List[victoria.Metric]:
        print(f"exporting {ts} for {self.label}")
        start = datetime.now(tz=timezone.utc)

        metrics_to_export = []
        data: PortfolioBalances = await self.describe(block, sync=False)

        for wallet, wallet_data in dict.items(data):
            for section, section_data in wallet_data.items():
                if isinstance(section_data, TokenBalances):
                    for token, bals in dict.items(section_data):
                        metrics_to_export.extend(
                            await self.__process_token(ts, section, wallet, token, bals)
                        )
                elif isinstance(section_data, RemoteTokenBalances):
                    if section == "external":
                        section = "assets"
                    for protocol, token_bals in section_data.items():
                        for token, bals in dict.items(token_bals):
                            metrics_to_export.extend(
                                await self.__process_token(
                                    ts, section, wallet, token, bals, protocol=protocol
                                )
                            )
                else:
                    raise NotImplementedError()

        print(f"got data for {ts} in {datetime.now(tz=timezone.utc) - start}")
        return metrics_to_export

    def __get_data_exists_coros(self, dt: datetime) -> Iterator[str]:
        for query in self._data_queries:
            yield victoria.get(f"/api/v1/query?query={query}&time={int(dt.timestamp())}")

    async def __process_token(
        self,
        ts: datetime,
        section: str,
        wallet: ChecksumAddress,
        token: ChecksumAddress,
        bal: Balance,
        protocol: Optional[str] = None,
    ) -> Tuple[victoria.types.PrometheusItem, victoria.types.PrometheusItem]:
        # TODO wallet nicknames in grafana
        # wallet = KNOWN_ADDRESSES[wallet] if wallet in KNOWN_ADDRESSES else wallet
        if protocol is not None:
            wallet = f"{protocol} | {wallet}"

        label_and_section = f"{self.label}_{section}".lower().replace(" ", "_")
        symbol = await _get_symbol(token)
        bucket = await self.get_bucket(token)
        ts_millis = floor(ts.timestamp()) * 1000

        return (
            victoria.types.PrometheusItem(
                metric=victoria.Metric(
                    param="balance",
                    wallet=wallet,
                    token_address=token,
                    token=symbol,
                    bucket=bucket,
                    network=NETWORK_LABEL,
                    __name__=label_and_section,
                ),
                values=[float(bal.balance)],
                timestamps=[ts_millis],
            ),
            victoria.types.PrometheusItem(
                metric=victoria.Metric(
                    param="usd value",
                    wallet=wallet,
                    token_address=token,
                    token=symbol,
                    bucket=bucket,
                    network=NETWORK_LABEL,
                    __name__=label_and_section,
                ),
                values=[float(bal.usd)],
                timestamps=[ts_millis],
            ),
        )


async def _get_symbol(token: str) -> str:
    if token == "ETH":
        return "ETH"
    try:
        return await ERC20(token, asynchronous=True).symbol
    except NonStandardERC20:
        return "<NonStandardERC20>"
