from pony.orm import OperationalError
from y._db.config import connection_settings

from eth_portfolio._db.entities import db

try:
    db.bind(**connection_settings, create_db=True)
except TypeError as e:
    if not str(e).startswith('Database object was already bound to'):
        raise e
try:
    db.generate_mapping(create_tables=True)
except OperationalError as e:
    if str(e).startswith("no such column:"):
        raise OperationalError("Since eth-portfolio extends the ypricemagic database with additional column definitions, you will need to delete your ypricemagic database at ~/.ypricemagic and rerun this script")
    raise e
