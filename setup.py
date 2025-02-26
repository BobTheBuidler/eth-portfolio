from setuptools import find_packages, setup  # type: ignore

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
    Clone the repository and install the package:

    .. code-block:: bash

        git clone https://github.com/BobTheBuidler/eth-portfolio.git
        cd eth-portfolio
        pip install .

If you encounter issues with :mod:`PyYaml` and :mod:`Cython`, you can resolve them by installing specific versions:

Example:
    Install specific versions of dependencies to resolve issues:

    .. code-block:: bash

        pip install wheel
        pip install --no-build-isolation "Cython<3" "pyyaml==5.4.1"
        pip install .

See Also:
    - :mod:`setuptools_scm`: For more information on versioning with setuptools_scm.
    - :mod:`cython`: For more information on Cython.
    - :mod:`requirements.txt`: For more information on managing dependencies.
"""

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