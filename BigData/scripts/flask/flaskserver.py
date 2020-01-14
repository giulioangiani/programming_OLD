from flask import Flask, render_template
import sys
import random
import pprint
import os
app = Flask(__name__)
app.secret_key = "super secret key"

from flask_sqlalchemy import SQLAlchemy


DATABASE = 'database.db'
project_dir = os.path.dirname(os.path.abspath(__file__))
database_file = "sqlite:///{}".format(os.path.join(project_dir, DATABASE))
app.config["SQLALCHEMY_DATABASE_URI"] = database_file
db = SQLAlchemy(app)

class Item(db.Model):
	code = db.Column(db.String(10), unique=True, nullable=False, primary_key=True)
	description = db.Column(db.String(80), unique=True, nullable=False, primary_key=False)
	price = db.Column(db.Float(), unique=True, nullable=False, primary_key=False)

	def __init__(self, code=None, description=None, price=0):
		self.code = code
		self.description = description
		self.price = price
		
	def __repr__(self):
		return "<Item: {} {} - Price {}>".format(self.code, self.description, self.price)
"""
def get_db():
    db = getattr(g, '_database', None)
    if db is None:
        db = g._database = sqlite3.connect(DATABASE)
    return db
    
def query_db(query, args=(), one=False):
    cur = get_db().execute(query, args)
    rv = cur.fetchall()
    cur.close()
    return (rv[0] if rv else None) if one else rv

@app.teardown_appcontext
def close_connection(exception):
    db = getattr(g, '_database', None)
    if db is not None:
        db.close()

"""

@app.route('/')
def hello_world():
	return """Hello World!"""
	
@app.route('/saluta')
def bye():
	return "Ciao ragazze e ragazzi!"	
	
@app.route('/home')
def home():
	return render_template("base.html")

@app.route('/home1')
def home1():
	x = "QUESTA E' LA HOME PAGE"
	
	return render_template("base.html", content = x)

@app.route('/home2')
def home2():
	x = "QUESTA E' LA HOME PAGE"
	messages = [
		"primo messaggio",
		"secondo messaggio",
		"terzo",
	]
	return render_template("base.html", content = x, msgs=messages)

@app.route('/home3')
def home3():
	content = "Terza pagina"
	var_dict = {
		"nome": "Giulio",
		"cognome": "Angiani"
	}
	return render_template("ext1.html", content = content, d = var_dict)
	
"""
@app.route('/makedb')
def makedb():
	d = get_db()
	query = "drop table if exists items;"
	d.execute(query)
	query = "create table items (code char(5), description char(50), price float);"
	d.execute(query)
	query = "insert into items(code, description, price) values ('APP001', 'iPhone X', 1025.99);"
	d.execute(query)
	query = "insert into items(code, description, price) values ('SAM003', 'Samsung 10', 899.99);"
	d.execute(query)
	return "DB CREATO"

@app.route('/list')
def lista():
	items = []
	for i in query_db('select * from items'):
		items.append(dict(zip(["code", "description", "price"], i)))
	print(items)
	return render_template("lista.html", items = items)
"""

@app.route('/makedb')
def makedb():
	db.create_all()
	i = Item(code="APP001", description="Apple iPhoneX", price=1200.00)
	db.session.add(i)
	i = Item(code="SAM201", description="Samsung 10", price=95.00)
	db.session.add(i)
	i = Item(code="LG0002", description="LG Q60", price=249.9)
	db.session.add(i)
	db.session.commit()
	return "DB CREATO"
	
@app.route('/list')
def lista():
	items = Item.query.all()
	return render_template("lista.html", items = items)

	
				
if __name__ == '__main__':

	app.run(
		host="0.0.0.0",
		port=5000
	)
