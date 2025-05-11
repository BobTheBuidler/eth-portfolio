from argparse import ArgumentParser


def get_arg_parser(description: str) -> ArgumentParser:
    return ArgumentParser(description)


def add_infra_port_args(parser: ArgumentParser) -> None:
    parser.add_argument(
        "--grafana-port",
        type=int,
        help="The port that will be used by grafana",
        default=3000,
    )
    parser.add_argument(
        "--renderer-port",
        type=int,
        help="The port that will be used by grafana",
        default=8091,
    )
    parser.add_argument(
        "--victoria-port",
        type=int,
        help="The port that will be used by victoria metrics",
        default=8428,
    )
