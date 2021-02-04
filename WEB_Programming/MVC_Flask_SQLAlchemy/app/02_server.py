from flask import Flask, render_template, request
import pprint

## importazione SQLAlchemy
from sqlalchemy import create_engine, MetaData, Table
from sqlalchemy.orm import scoped_session, sessionmaker
from sqlalchemy.ext.declarative import declarative_base

engine = create_engine("mysql://scuola:scuola@localhost/scuola?charset=utf8mb4")

metadata = MetaData(bind=engine)	## mappa i metadati sulla connessione

db_session = scoped_session(sessionmaker(autocommit=False,
                                         autoflush=False,
                                         bind=engine))
Base = declarative_base()
Base.query = db_session.query_property()

app = Flask(__name__)

@app.route('/')
def home():
	content = "I love Python and SQLAlchemy"
	title = "My first page"
	return render_template("alchemy01.html", **vars())
	
@app.route('/classi')
def classi():
	content = "Lista Classi"
	title = "Lista Classi con SQLAlchemy"
	table_classi = Table('classi', metadata, autoload=True)
	classi = table_classi.select().execute()
	return render_template("classi.html", **vars())

@app.route('/classi/<int:idclasse>')
def classe_singola(idclasse):
	content = "Lista studenti"
	title = "Lista studenti"
	table_classi = Table('classi', metadata, autoload=True)
	# first perche' essendo una query per ID se esiste ne trovo solo uno
	classe = table_classi.select(table_classi.c.id == idclasse).execute().first() 
	
	table_studenti = Table('studenti', metadata, autoload=True)
	# tutti gli elementi selezionati dal filtro per fk_classe_id
	studenti = table_studenti.select(table_studenti.c.fk_classe_id == idclasse).execute()

	return render_template("listastudentiperclasse.html", **vars())


if __name__ == '__main__':
	app.secret_key = "mysecretkey"
	app.config["TEMPLATES_AUTO_RELOAD"] = True	# ricarica i templates dinamicamente
	app.run(
		host="0.0.0.0",
		port=9000,
	)
