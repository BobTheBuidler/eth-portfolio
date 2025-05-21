import asyncio
from argparse import ArgumentParser
from os import environ

import brownie

from eth_portfolio_scripts import docker, logger
from eth_portfolio_scripts._args import add_infra_port_args
from eth_portfolio_scripts.balances import export_balances


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

args = parser.parse_args()

if hasattr(args, "network"):
    environ["BROWNIE_NETWORK_ID"] = args.network

environ["GRAFANA_PORT"] = str(args.grafana_port)
environ["RENDERER_PORT"] = str(args.renderer_port)
environ["VICTORIA_PORT"] = str(args.victoria_port)


# TODO: run forever arg
def main():
    command = args.command
    if command == "infra":
        if args.cmd == "start":
            # Start the backend containers
            docker.up()
        elif args.cmd == "stop":
            docker.down()
        else:
            raise ValueError(f"{args.target} is not a valid command")

    else:
        # The user's command is `export`
        if args.target == "balances":
            asyncio.run(args.func(args))
        else:
            raise ValueError(f"{args.target} is not a valid command")


if __name__ == "__main__":
    brownie.project.run(__file__)
