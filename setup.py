import logging
from pathlib import Path
from setuptools import find_packages, setup  # type: ignore

try:
    from mypyc.build import mypycify
except ModuleNotFoundError:
    logging.warning("Cannot find mypyc, installing in iterpreted python mode (without compiling)")
    mypycify = lambda *a, **k: []


requirements = list(map(str.strip, Path("requirements.txt").read_text().split("\n")))[:-1]

try:
    ext_modules = mypycify(
        [
            "eth_portfolio/_loaders/_nonce.py",
            "eth_portfolio/_loaders/balances.py",
            "eth_portfolio/_loaders/utils.py",
            "eth_portfolio/_argspec.py",
            "eth_portfolio/_config.py",
            "eth_portfolio/_shitcoins.py",
            # "eth_portfolio/_submodules.py",
            "eth_portfolio/constants.py",
            # "eth_portfolio_scripts/victoria/__init__.py",  # this one built fine with other files but wont alone
            # "eth_portfolio_scripts/_portfolio.py",
            # "eth_portfolio_scripts/_utils.py",
            # "eth_portfolio_scripts/balances.py",
            "--strict",
            "--pretty",
            "--install-types",
            "--disable-error-code=unused-ignore",
            "--disable-error-code=import-not-found",
            "--disable-error-code=import-untyped",
            # temporary
            "--disable-error-code=call-arg",
            "--disable-error-code=misc",
            "--disable-error-code=type-arg",
            "--disable-error-code=attr-defined",
            "--disable-error-code=name-defined",
            "--disable-error-code=no-any-return",
            "--disable-error-code=arg-type",
            "--disable-error-code=no-untyped-call",
            "--disable-error-code=no-untyped-def",
            "--disable-error-code=override",
            "--disable-error-code=var-annotated",
            "--disable-error-code=return-value",
            "--disable-error-code=assignment",
            "--disable-error-code=union-attr",
            "--disable-error-code=comparison-overlap",
            "--disable-error-code=no-redef",
            "--disable-error-code=valid-type",
            "--disable-error-code=call-overload",
            "--disable-error-code=dict-item",
            "--disable-error-code=has-type",
            "--disable-error-code=typeddict-item",
            "--disable-error-code=str-bytes-safe",
            "--disable-error-code=index",
        ],
    )
except Exception as e:  # fallback in case build fails
    logging.error("Error compiling eth-portfolio:", exc_info=True)
    ext_modules = []


setup(
    # NOTE: somebody stole our name on pypi, we have this placeholder until we steal it back
    name="eth_portfolio_temp",
    python_requires=">=3.8,<3.13",
    # name="eth-portfolio",
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
    setup_requires=["setuptools_scm"],
    package_data={
        "eth_portfolio": ["py.typed"],
    },
    include_package_data=True,
    ext_modules=ext_modules,
    zip_safe=False,
    entry_points={
        "console_scripts": [
            "eth-portfolio=eth_portfolio_scripts.main:main",
        ],
    },
)

"""
Installation
------------
To install the `eth-portfolio` package, you should start with a fresh virtual environment. 
Due to the use of :mod:`setuptools_scm` for versioning, it is recommended to clone the repository first 
to ensure the version can be determined correctly. 

The `setup.py` file automatically handles the installation of :mod:`setuptools_scm` and :mod:`cython`, 
so you do not need to install them manually before running the setup process. Additionally, 
the `requirements.txt` file is used to specify additional dependencies that are installed via 
the `install_requires` parameter. Note that the last line of `requirements.txt` is intentionally excluded 
from installation, so ensure that any necessary dependency is not placed on the last line.

Example:
    .. code-block:: bash

        git clone https://github.com/BobTheBuidler/eth-portfolio.git
        cd eth-portfolio
        pip install .

If you encounter issues with :mod:`PyYaml` and :mod:`Cython`, you can resolve them by installing specific versions:

Example:
    .. code-block:: bash

        pip install wheel
        pip install --no-build-isolation "Cython<3" "pyyaml==5.4.1"
        pip install .

See Also:
    - :mod:`setuptools_scm`: For more information on versioning with setuptools_scm.
    - :mod:`cython`: For more information on Cython.
    - :mod:`requirements.txt`: For more information on managing dependencies.
"""
