from setuptools import find_packages, setup  # type: ignore

with open("requirements.txt", "r") as f:
    requirements = list(map(str.strip, f.read().split("\n")))[:-1]

setup(
    name="eth-portfolio",
    packages=find_packages(),
    use_scm_version={
        "root": ".",
        "relative_to": __file__,
        "local_scheme": "no-local-version",
        "version_scheme": "python-simplified-semver",
    },
    description="eth-portfolio makes it easy to analyze your portfolio.",
    author="BobTheBuidler",
    author_email="bobthebuidlerdefi@gmail.com",
    url="https://github.com/BobTheBuidler/eth-portfolio",
    install_requires=requirements,
    setup_requires=["setuptools_scm", "cython"],
    package_data={
        "eth_portfolio": ["py.typed"],
    },
)
