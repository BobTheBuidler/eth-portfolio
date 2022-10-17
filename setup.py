from setuptools import find_packages, setup # type: ignore

setup(
    name='eth-portfolio',
    packages=find_packages(),
    use_scm_version={
        "root": ".",
        "relative_to": __file__,
        "local_scheme": "no-local-version",
        "version_scheme": "python-simplified-semver",
    },
    description='eth-portfolio makes it easy to analyze your portfolio.',
    author='BobTheBuidler',
    author_email='bobthebuidlerdefi@gmail.com',
    url='https://github.com/BobTheBuidler/eth-portfolio',
    install_requires=[
        "checksum_dict>=1.1.2",
        "pandas>=1.4.3,<1.5",
        "ypricemagic>=1.6.2",
    ],
    setup_requires=[
        'setuptools_scm',
    ],
    package_data={
        "eth_portfolio": ["py.typed"],
    },
)
