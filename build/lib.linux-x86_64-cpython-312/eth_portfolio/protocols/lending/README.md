This module contains the base classes for lending protocols in the _base.py file, and all lending protocols supported by eth-portfolio.

If you want to add support for a new lending protocol, there are only a few steps:
1. Create a new python file, named appropriately.
2. Subclass one of the 2 classes in _base.py and define the methods specified in the parent definition with the custom logic for the protocol you wish to add. 
3. That's it, eth-portfolio will automagically handle the rest!