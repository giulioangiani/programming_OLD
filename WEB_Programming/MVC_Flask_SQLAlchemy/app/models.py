## importazione SQLAlchemy
from sqlalchemy import Table, Column, Integer, String, create_engine, MetaData, Date, ForeignKey, Index
from sqlalchemy.orm import mapper, relationship, sessionmaker, scoped_session
from sqlalchemy.ext.declarative import declarative_base

engine = create_engine("mysql://scuola:scuola@localhost/scuola?charset=utf8mb4")

metadata = MetaData(bind=engine)	## mappa i metadati sulla connessione

db_session = scoped_session(sessionmaker(autocommit=False,
                                         autoflush=False,
                                         bind=engine))
Base = declarative_base()
Base.query = db_session.query_property()

class Customer(Base):
	__tablename__ = 'customers'
	id = Column(Integer, primary_key=True)
	name = Column(String(200))
	familyname = Column(String(200))
	taxcode = Column(String(200))
	birthdate = Column(Date)
	orders = relationship("Order", backref="customer", order_by="Order.id")

class Order(Base):
	__tablename__ = 'orders'
	id = Column(Integer, primary_key=True)
	customer_id = Column(ForeignKey('customers.id'))
	ordercode = Column(String(20))
	orderdate = Column(Date)
	def __repr__(self):
		return self.ordercode + " " + self.orderdate


if __name__ == '__main__':
	print("Dropping tables...")
	Base.metadata.drop_all(engine)

	print("Creating tables...")
	Base.metadata.create_all(engine)
	
	
	Session = sessionmaker(bind = engine)
	dbsession = Session()

	# fill tables
	c1 = Customer(name="Alessandro", familyname="Del Piero", taxcode="DLPLSS10A34H222A", birthdate="1990-10-01");
	c2 = Customer(name="Paolo", familyname="Maldini", taxcode="MLDPLA12E45B232D", birthdate="1992-12-21");
	dbsession.add(c1)
	dbsession.add(c2)
	dbsession.commit()
	
	o1 = Order(ordercode="N001", orderdate="2021-01-10")
	o2 = Order(ordercode="N002", orderdate="2021-01-15")
	o3 = Order(ordercode="N003", orderdate="2021-02-01")
	c1.orders.append(o1)
	c1.orders.append(o2)
	c2.orders.append(o3)
	dbsession.commit()
	
	

	
