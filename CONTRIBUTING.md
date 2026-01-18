# Contributing to eth-portfolio

## y.stuck? logger

eth-portfolio relies on ypricemagic for price lookups. ypricemagic wraps long-running async calls with a DEBUG logger named `y.stuck?`. It only emits when the logger is enabled for DEBUG, and logs "module.function still executing after Xm with args ... kwargs ..." every 5 minutes until completion.

Enable it locally when debugging slow price calls:
```python
import logging

logging.basicConfig(level=logging.INFO)
logging.getLogger("y.stuck?").setLevel(logging.DEBUG)
```
