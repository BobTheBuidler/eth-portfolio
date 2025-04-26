from setuptools import setup
from mypyc.build import mypycify

setup(name='mypyc_output',
      ext_modules=mypycify(['eth_portfolio/typing.py', '--strict', '--pretty', '--disable-error-code', 'unused-ignore'], opt_level="3", debug_level="1", strict_dunder_typing=True),
)
