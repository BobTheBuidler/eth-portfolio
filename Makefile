
.PHONY: docs

docs:
	rm -r ./docs/source -f
	rm -r ./docs/_templates -f
	rm -r ./docs/_build -f
	sphinx-apidoc -o ./docs/source ./eth_portfolio

mypyc:
	mypyc eth_portfolio/typing.py --strict --pretty --disable-error-code unused-ignore