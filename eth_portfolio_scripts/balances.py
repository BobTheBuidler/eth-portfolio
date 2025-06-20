from argparse import Namespace
from datetime import datetime, timezone
from typing import Final

import a_sync
import a_sync.asyncio

from eth_portfolio_scripts import docker
from eth_portfolio_scripts._utils import aiter_timestamps, parse_timedelta


_UTC: Final = timezone.utc

create_task: Final = a_sync.create_task
yield_to_loop: Final = a_sync.asyncio.sleep0


@docker.ensure_containers
async def export_balances(args: Namespace) -> None:
    import dank_mids

    from eth_portfolio_scripts._portfolio import ExportablePortfolio

    if args.daemon is True:
        raise NotImplementedError("This feature must be implemented")

    interval = parse_timedelta(args.interval)
    portfolio = ExportablePortfolio(
        args.wallet, label=args.label, start_block=args.first_tx_block, load_prices=False
    )

    if export_start_block := args.export_start_block or args.first_tx_block:
        start = datetime.fromtimestamp(
            await dank_mids.eth.get_block_timestamp(args.export_start_block), tz=timezone.utc
        )
    else:
        start = None

    print(f"Exporting {portfolio}")
    async for ts in aiter_timestamps(start=start, interval=interval, run_forever=True):
        create_task(
            coro=portfolio.export_snapshot(ts, sync=False),
            name=f"eth-portfolio export snapshot {ts}",
            skip_gc_until_done=True,
        )
        # get some work in before yielding the next task
        await yield_to_loop()
        await yield_to_loop()
        await yield_to_loop()
