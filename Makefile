
.PHONY: docs

docs:
	rm -r ./docs/source -f
	rm -r ./docs/_templates -f
	rm -r ./docs/_build -f
	sphinx-apidoc -o ./docs/source ./eth_portfolio

test-exporter:
	eth-portfolio export balances --wallet 0xFEB4acf3df3cDEA7399794D0869ef76A6EfAff52 --network tenderly
