from argparse import ArgumentParser


def get_arg_parser(description: str) -> ArgumentParser:
    return ArgumentParser(description)


def add_grafana_port_args(parser: ArgumentParser) -> None:
    parser.add_argument(
        "--grafana-port",
        type=int,
        help="The port that will be used by grafana",
        default=3000,
    )


def add_renderer_port_args(parser: ArgumentParser) -> None:
    parser.add_argument(
        "--renderer-port",
        type=int,
        help="The port that will be used by grafana",
        default=8091,
    )


def add_victoria_port_args(parser: ArgumentParser) -> None:
    parser.add_argument(
        "--victoria-port",
        type=int,
        help="The port that will be used by victoria metrics",
        default=8428,
    )


def add_infra_port_args(parser: ArgumentParser) -> None:
    add_grafana_port_args(parser)
    add_renderer_port_args(parser)
    add_victoria_port_args(parser)
