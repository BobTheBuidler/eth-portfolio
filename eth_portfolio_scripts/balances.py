from a_sync import create_task
from a_sync.asyncio import sleep0 as yield_to_loop

from eth_portfolio_scripts import docker
from eth_portfolio_scripts._utils import aiter_timestamps, parse_timedelta


@docker.ensure_containers
async def export_balances(args):
    from eth_portfolio_scripts._portfolio import ExportablePortfolio

    if args.daemon is True:
        raise NotImplementedError("This feature must be implemented")
    
    interval = parse_timedelta(args.interval)
    portfolio = ExportablePortfolio(args.wallet, label=args.label, start_block=args.first_tx_block, load_prices=False)

    print(f"Exporting {portfolio}")
    async for ts in aiter_timestamps(interval=interval, run_forever=True):
        print(f'found ts {ts}')
        create_task(
            coro=portfolio.export_snapshot(ts, sync=False), 
            name=f"eth-portfolio export snapsshot {ts}",
            skip_gc_until_done=True,
        )
        # get some work in before yielding the next task
        await yield_to_loop()
        await yield_to_loop()
        await yield_to_loop()
