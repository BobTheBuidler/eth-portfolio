from argparse import ArgumentParser

def get_arg_parser(description: str) -> ArgumentParser:
    parser = ArgumentParser(description)
    return parser