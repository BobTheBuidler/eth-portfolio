"""
This module defines the :class:`~PortfolioAddress` class, which represents an address managed by the `eth-portfolio` system.
The :class:`~PortfolioAddress` class is designed to manage different aspects of an Ethereum address within the portfolio,
such as transactions, transfers, balances, and interactions with both external and lending protocols.

Key components and functionalities provided by the :class:`~eth_portfolio.address.PortfolioAddress` class include:
- Handling Ethereum and token balances
- Managing debt and collateral from lending protocols
- Tracking transactions and transfers (both internal and token transfers)
- Providing comprehensive balance descriptions at specific block heights

The class leverages asynchronous operations using the `a_sync` library to efficiently gather and process data.
It also integrates with various submodules from `eth-portfolio` to load balances, manage ledgers, and interact
with external protocols.
"""

import logging
from asyncio import Task, create_task, gather
from typing import Dict, Final, Optional, final

import a_sync
import dank_mids
import eth_retry
import y
from a_sync.exceptions import MappingIsEmptyError
from y import convert
from y._decorators import stuck_coro_debugger
from y.datatypes import Address, Block

from eth_portfolio import protocols
from eth_portfolio._ledgers.address import (
    AddressInternalTransfersLedger,
    AddressLedgerBase,
    AddressTokenTransfersLedger,
    AddressTransactionsLedger,
    PandableLedgerEntryList,
)
from eth_portfolio._loaders import balances
from eth_portfolio._utils import _LedgeredBase, _get_price
from eth_portfolio.typing import Balance, RemoteTokenBalances, TokenBalances, WalletBalances


logger: Final = logging.getLogger(__name__)

checksum: Final = convert.to_address


@final
class PortfolioAddress(_LedgeredBase[AddressLedgerBase]):
    """
    Represents a portfolio address within the eth-portfolio system.

    This class is designed to manage different aspects of an Ethereum address within the portfolio,
    such as transactions, transfers, balances, and interactions with both external and lending protocols.

    Key components and functionalities provided by the :class:`~eth_portfolio.address.PortfolioAddress` class include:
    - Handling Ethereum and token balances
    - Managing debt and collateral from lending protocols
    - Tracking transactions and transfers (both internal and token transfers)
    - Providing comprehensive balance descriptions at specific block heights

    The class leverages asynchronous operations using the `a_sync` library to efficiently gather and process data.
    It also integrates with various submodules from `eth-portfolio` to load balances, manage ledgers, and interact
    with external protocols.
    """

    def __init__(
        self,
        address: Address,
        start_block: Block,
        load_prices: bool,
        num_workers_transactions: int = 1000,
        asynchronous: bool = False,
    ) -> None:  # type: ignore
        """
        Initializes the :class:`~PortfolioAddress` instance.

        Args:
            address: The Ethereum address to manage.
            start_block: The block number from which to start tracking.
            load_prices: Flag indicating if price loading is enabled.
            num_workers_transactions (optional): Number of workers for transaction processing. Defaults to 1000.
            asynchronous (optional): Flag for asynchronous operation. Defaults to False.

        Raises:
            TypeError: If `asynchronous` is not a boolean.

        Examples:
            >>> address = PortfolioAddress('0x1234...', 0, True)
            >>> print(address)

            >>> address = PortfolioAddress('0x1234...', 0, False, num_workers_transactions=500, asynchronous=True)
            >>> print(address)

        See Also:
            - :class:`~eth_portfolio.portfolio.Portfolio`
            - :class:`~eth_portfolio._ledgers.address.AddressTransactionsLedger`
            - :class:`~eth_portfolio._ledgers.address.AddressInternalTransfersLedger`
            - :class:`~eth_portfolio._ledgers.address.AddressTokenTransfersLedger`
        """
        self.address: Final = convert.to_address(address)
        """
        The address being managed.
        """
        if not isinstance(asynchronous, bool):
            raise TypeError(f"`asynchronous` must be a boolean, you passed {type(asynchronous)}")

        self.asynchronous: Final = asynchronous
        """
        Flag indicating if the operations are asynchronous.
        """

        self.load_prices: Final = load_prices
        """
        Indicates if price loading is enabled.
        """

        super().__init__(start_block)

        self.transactions: Final = AddressTransactionsLedger(self, num_workers_transactions)  # type: ignore [misc]
        """
        Ledger for tracking transactions.
        """

        self.internal_transfers: Final = AddressInternalTransfersLedger(self)  # type: ignore [misc]
        """
        Ledger for tracking internal transfers.
        """

        self.token_transfers: Final = AddressTokenTransfersLedger(self)  # type: ignore [misc]
        """
        Ledger for tracking token transfers.
        """

    def __str__(self) -> str:
        """
        Returns the string representation of the address.

        Returns:
            The address as a string.
        """
        return self.address

    def __repr__(self) -> str:
        """
        Returns the string representation of the PortfolioAddress instance.

        Returns:
            The string representation.
        """
        return f"<{self.__class__.__name__} address={self.address} at {hex(id(self))}>"

    def __eq__(self, other: object) -> bool:
        """
        Checks equality with another object.

        Args:
            other: The object to compare with.

        Returns:
            True if equal, False otherwise.
        """
        if isinstance(other, PortfolioAddress):
            return self.address == other.address
        elif isinstance(other, str):
            return self.address == checksum(other)
        return False

    def __hash__(self) -> int:
        """
        Returns the hash of the address.

        Returns:
            The hash value.
        """
        return hash(self.address)

    # Primary functions

    @stuck_coro_debugger
    async def describe(self, block: int) -> WalletBalances:
        """
        Describes all of the wallet's balances at a given block.

        Args:
            block: The block number.

        Returns:
            :class:`~eth_portfolio.typing.WalletBalances`: The wallet balances.

        Raises:
            TypeError: If block is not an integer.

        Examples:
            >>> wallet_balances = await address.describe(12345678)
        """
        if not isinstance(block, int):
            raise TypeError(f"Block must be an integer. You passed {type(block)} {block}")
        coros = {
            "assets": self.assets(block, sync=False),
            "debt": self.debt(block, sync=False),
            "external": self.external_balances(block, sync=False),
        }
        return WalletBalances(await a_sync.gather(coros), block=block)  # type: ignore [arg-type]

    @stuck_coro_debugger
    async def assets(self, block: Optional[Block] = None) -> TokenBalances:
        """
        Retrieves the balances for every asset in the wallet at a given block.

        Args:
            block (optional): The block number to query. Defaults to None, which uses the latest block.

        Returns:
            :class:`~eth_portfolio.typing.TokenBalances`: The asset balances at `block`.

        Examples:
            >>> assets = await address.assets(12345678)
        """
        return await self.balances(block=block, sync=False)  # type: ignore [return-value]

    @stuck_coro_debugger
    async def debt(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        """
        Retrieves all debt balances for the wallet at a given block.

        Args:
            block (optional): The block number. Defaults to None, which uses the latest block.

        Returns:
            :class:`~eth_portfolio.typing.RemoteTokenBalances`: The debt balances at `block`.

        Examples:
            >>> debt = await address.debt(12345678)
        """
        return await protocols.lending.debt(self.address, block=block)

    @stuck_coro_debugger
    async def external_balances(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        """
        Retrieves the balances owned by the wallet, but not held *in* the wallet, at a given block.

        Args:
            block (optional): The block number. Defaults to None, which uses the latest block.

        Returns:
            :class:`~eth_portfolio.typing.RemoteTokenBalances`: The external balances.

        Examples:
            >>> external_balances = await address.external_balances(12345678)
        """
        staking: "Task[RemoteTokenBalances]"
        collateral: RemoteTokenBalances

        staking = create_task(self.staking(block, sync=False))  # type: ignore [arg-type]
        try:
            collateral = await self.collateral(block, sync=False)  # type: ignore [assignment]
        except:
            staking.cancel()
            raise
        else:
            return collateral + await staking

    # Assets

    @stuck_coro_debugger
    async def balances(self, block: Optional[Block]) -> TokenBalances:
        """
        Retrieves balances for all assets in the wallet at a given block.

        Args:
            block: The block number.

        Returns:
            :class:`~eth_portfolio.typing.TokenBalances`: The balances.

        Examples:
            >>> balances = await address.balances(12345678)
        """
        eth_balance, token_balances = await gather(
            self.eth_balance(block, sync=False),
            self.token_balances(block, sync=False),
        )
        token_balances[y.EEE_ADDRESS] = eth_balance  # type: ignore [call-overload]
        return token_balances  # type: ignore [return-value]

    @eth_retry.auto_retry
    @stuck_coro_debugger
    async def eth_balance(self, block: Optional[Block]) -> Balance:
        """
        Retrieves the ETH balance for the wallet at a given block.

        Args:
            block: The block number.

        Returns:
            :class:`~eth_portfolio.typing.Balance`: The ETH balance at `block`.

        Examples:
            >>> eth_balance = await address.eth_balance(12345678)
        """
        if balance := await dank_mids.eth.get_balance(
            self.address, block_identifier=block  # type: ignore [arg-type]
        ):  # TODO: move hex into dank
            price = await _get_price(y.WRAPPED_GAS_COIN, block)
            return Balance(
                balance.scaled,
                round(balance.scaled * price, 18),
                token=y.EEE_ADDRESS,
                block=block,
            )
        return Balance(token=y.EEE_ADDRESS, block=block)

    @stuck_coro_debugger
    async def token_balances(self, block) -> TokenBalances:
        """
        Retrieves the balances for all tokens in the wallet at a given block.

        Args:
            block: The block number.

        Returns:
            :class:`~eth_portfolio.typing.TokenBalances`: The token balances at `block`.

        Examples:
            >>> token_balances = await address.token_balances(12345678)
        """
        try:
            data = a_sync.map(
                balances.load_token_balance,
                self.token_transfers._yield_tokens_at_block(block=block),
                address=self.address,
                block=block,
            )
            return TokenBalances(await data, block=block)
        except MappingIsEmptyError:
            return TokenBalances(block=block)

    @stuck_coro_debugger
    async def collateral(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        """
        Retrieves all balances held by lending protocols on behalf of the wallet at a given block.

        Args:
            block (optional): The block number. Defaults to None, which uses the latest block.

        Returns:
            :class:`~eth_portfolio.typing.RemoteTokenBalances`: The collateral balances.

        Examples:
            >>> collateral = await address.collateral(12345678)
        """
        return await protocols.lending.collateral(self.address, block=block)

    @stuck_coro_debugger
    async def staking(self, block: Optional[Block] = None) -> RemoteTokenBalances:
        """
        Retrieves all balances staked in protocols supported by eth_portfolio on behalf of the wallet at a given block.

        Args:
            block (optional): The block number. Defaults to None, which uses the latest block.

        Returns:
            :class:`~eth_portfolio.typing.RemoteTokenBalances`: The staked balances.

        Examples:
            >>> staking_balances = await address.staking(12345678)
        """
        return await protocols.balances(self.address, block=block)

    # Ledger Entries

    @stuck_coro_debugger
    async def all(self, start_block: Block, end_block: Block) -> Dict[str, PandableLedgerEntryList]:
        """
        Retrieves all ledger entries between two blocks.

        Args:
            start_block: The starting block number.
            end_block: The ending block number.

        Returns:
            Dict[str, :class:`~eth_portfolio._ledgers.address.PandableLedgerEntryList`]: The ledger entries.

        Examples:
            >>> all_entries = await address.all(12000000, 12345678)
        """
        return await a_sync.gather(
            {
                "transactions": self.transactions.get(start_block, end_block, sync=False),
                "internal_transactions": self.internal_transfers.get(
                    start_block, end_block, sync=False
                ),
                "token_transfers": self.token_transfers.get(start_block, end_block, sync=False),
            }
        )
