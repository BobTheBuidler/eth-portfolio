from y._db.config import connection_settings

from eth_portfolio._db.entities import db

db.bind(**connection_settings, create_db=True)
db.generate_mapping(create_tables=True)
