import asyncio
from argparse import ArgumentParser
from os import environ

import brownie

from eth_portfolio_scripts import docker
from eth_portfolio_scripts._args import add_infra_port_args, add_victoria_port_args
from eth_portfolio_scripts.balances import export_balances
from eth_portfolio_scripts.victoria import delete_data


parser = ArgumentParser(description="eth-portfolio")

subparsers = parser.add_subparsers(title="Commands", dest="command", required=True)

export_parser = subparsers.add_parser("export", help="Export a specific dataset for your portfolio")
export_parser.add_argument("target", help="Choose an exporter to run")
add_infra_port_args(export_parser)
export_parser.set_defaults(func=export_balances)

infra_parser = subparsers.add_parser(
    "infra", help="Start the docker containers required to run any eth-portfolio service"
)
infra_parser.add_argument("cmd", help="What do you want to do?")
add_infra_port_args(infra_parser)
infra_parser.add_argument(
    "--start-renderer",
    action="store_true",
    help="If set, starts the renderer container in addition to the default containers. By default, only grafana, victoria-metrics, and vmagent are started.",
)

export_parser.add_argument(
    "--wallet",
    type=str,
    help="The address of a wallet to export. You can pass multiple, ie. `--wallet 0x123 0x234 0x345`",
    required=True,
    nargs="+",
)
export_parser.add_argument(
    "--network",
    type=str,
    help="The brownie network identifier for the rpc you wish to use. default: mainnet",
    default="mainnet",
)
export_parser.add_argument(
    "--label",
    type=str,
    help='The label for this portfolio, if you want one. Defaults to "MyPortfolio".',
    default="My Portfolio",
)
export_parser.add_argument(
    "--interval",
    type=str,
    help="The time interval between datapoints. default: 6h",
    default="6h",
)
export_parser.add_argument(
    "--concurrency",
    type=int,
    help="The max number of historical blocks to export concurrently. default: 60",
    default=60,
)
export_parser.add_argument(
    "--first-tx-block",
    type=int,
    help=(
        "The block of your portfolio's first transaction, if known. "
        "This value, if provided, allows us to speed up processing of your data by limiting the block range we need to query. "
        "If not provided, the whole blockchain will be scanned."
    ),
    default=0,
)
export_parser.add_argument(
    "--export-start-block",
    type=int,
    help="The first block in the range you wish to export.",
    default=0,
)
export_parser.add_argument(
    "--daemon",
    action="store_true",
    help="TODO: If True, starts a daemon process instead of running in your terminal. Not currently supported.",
)

# data maintenance utils
delete_parser = subparsers.add_parser(
    "delete-grafana-data",
    help=(
        "Delete ALL datapoints from Grafana (VictoriaMetrics) between two timestamps. "
        "WARNING: This is a destructive operation that deletes ALL time series data in the specified range. "
        "There is no way to restrict this operation to a subset of metrics. "
        "All deleted data will be refreshed next time you run the exporter. "
        "Accepted formats: ISO8601 (e.g. 2024-01-01T12:34:56), 'YYYY-MM-DD HH:MM:SS', 'YYYY-MM-DD', or Unix epoch seconds. "
    ),
)
delete_parser.add_argument(
    "start_timestamp",
    type=str,
    help=(
        "Start timestamp (inclusive). "
        "Accepted formats: ISO8601 (e.g. 2024-01-01T12:34:56), 'YYYY-MM-DD HH:MM:SS', 'YYYY-MM-DD', or Unix epoch seconds."
    ),
)
delete_parser.add_argument(
    "end_timestamp",
    type=str,
    help=(
        "End timestamp (exclusive). "
        "Accepted formats: ISO8601 (e.g. 2024-01-01T12:34:56), 'YYYY-MM-DD HH:MM:SS', 'YYYY-MM-DD', or Unix epoch seconds."
    ),
)
add_victoria_port_args(delete_parser)


def handle_delete_grafana_data(args):
    # Ensure VictoriaMetrics is running before deletion
    docker.up("victoria-metrics")
    # Pass raw datetime strings to delete_data; parsing is handled in victoria module
    asyncio.get_event_loop().run_until_complete(
        delete_data(args.start_timestamp, args.end_timestamp)
    )


delete_parser.set_defaults(func=handle_delete_grafana_data)

args = parser.parse_args()

if hasattr(args, "network"):
    environ["BROWNIE_NETWORK_ID"] = args.network

try:
    # These 2 attributes will not be present for the `delete-grafana-data` command
    environ["GRAFANA_PORT"] = str(args.grafana_port)
    environ["RENDERER_PORT"] = str(args.renderer_port)
except AttributeError:
    if args.command != "delete-grafana-data":
        raise


environ["VICTORIA_PORT"] = str(args.victoria_port)


# TODO: run forever arg
def main():
    command = args.command
    if command == "infra":
        if args.cmd == "start":
            # Start the backend containers
            if getattr(args, "start_renderer", False):
                docker.up()
            else:
                docker.up("grafana", "victoria-metrics", "vmagent")
        elif args.cmd == "stop":
            docker.down()
        else:
            raise ValueError(f"{args.target} is not a valid command")

    elif command == "delete-grafana-data":
        # Call the deletion utility via the handler
        args.func(args)
    else:
        # The user's command is `export`
        if args.target == "balances":
            asyncio.run(args.func(args))
        else:
            raise ValueError(f"{args.target} is not a valid command")


if __name__ == "__main__":
    brownie.project.run(__file__)
