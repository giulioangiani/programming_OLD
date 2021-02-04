import pprint

from flask import Flask, render_template, request
from models import *

app = Flask(__name__)

@app.route('/')
def home():
	content = "I love Python and SQLAlchemy"
	title = "My first page"
	return render_template("alchemy01.html", **vars())
	
@app.route('/customers')
def customers():
	content = "Customers list"
	title = "Customers list"
	customers = db_session.query(Customer).all()
	return render_template("customers.html", **vars())

@app.route('/customer/<int:customer_id>')
def customer_orders(customer_id):
	content = "Customer Orders list"
	title = "Customer Orders list"
	customer = db_session.query(Customer).get(customer_id)
	return render_template("customerorders.html", **vars())

@app.route('/order/<int:order_id>')
def order_detail(order_id):
	content = "Order detail"
	title = "Order detail"
	order = db_session.query(Order).get(order_id)
	return render_template("order_detail.html", **vars())

@app.route('/orderupdate', methods=['POST'])
def order_update():
	order_id = request.form.get("id")		# se non esiste la chiave restituisce None
	ordercode = request.form.get("ordercode")
	orderdate = request.form.get("orderdate")
	order = db_session.query(Order).get(order_id)
	order.ordercode = ordercode
	order.orderdate = orderdate
	db_session.commit()
	return customer_orders(order.customer.id)


@app.route('/orderupdate_refactoring', methods=['POST'])
def order_update_refactoring():
	id = request.form.get("id")		# se non esiste la chiave restituisce None
	order = db_session.query(Order).get(id)
	attributes = [k for k in Order.__dict__.keys() if not k.startswith("_")]
	for a in attributes:
		if request.form.get(a):
			order.__setattr__(a, request.form.get(a))
	db_session.commit()
	return customer_orders(order.customer.id)


if __name__ == '__main__':
	app.secret_key = "mysecretkey"
	app.config["TEMPLATES_AUTO_RELOAD"] = True	# ricarica i templates dinamicamente
	app.run(
		host="0.0.0.0",
		port=9000,
	)
