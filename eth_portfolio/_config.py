import os
from typing import Final

REORG_BUFFER: Final = int(os.environ.get("REORG_BUFFER", 30))
