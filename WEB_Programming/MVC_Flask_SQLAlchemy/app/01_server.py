from flask import Flask, render_template, request
import pprint

## importazione per accesso diretto a MySQL
import mysql.connector
cnx = mysql.connector.connect(user='scuola', password='scuola',
		  host='localhost', database='scuola',
		  auth_plugin='mysql_native_password')

app = Flask(__name__)

def make_query(sql):
	cursor = cnx.cursor(dictionary=True)
	cursor.execute(sql)
	rows = cursor.fetchall()
	cursor.close()
	return rows

def update_delete_insert_query(sql):
	cursor = cnx.cursor(dictionary=True)
	cursor.execute(sql)
	cnx.commit()

@app.route('/')
def home():
	content = "I love Python"
	title = "My first page"
	return render_template("home.html", **vars())
	
	
@app.route('/nazioni')
def nazioni():
	content = "Lista delle nazioni presenti"
	title = "Lista nazioni"
	nazioni = make_query("select * from nazioni")
	PANEL = "Utente connesso: Marco"
	return render_template("nazioni.html", **vars())

	
@app.route('/classi')
def classi():
	content = "Lista delle classi presenti"
	title = "Lista classi"
	classi = make_query("select * from classi order by classe, sezione, indirizzo")
	PANEL = "Utente connesso: Marco"
	return render_template("classi.html", **vars())

	
@app.route('/classi/<int:idclasse>')
def classe_singola(idclasse):
	content = "Lista studenti"
	title = "Lista studenti"
	studenti = make_query("select * from studenti where fk_classe_id = '{}' ".format(idclasse))
	classe = make_query("select * from classi where id = '{}' ".format(idclasse))[0]
	return render_template("listastudentiperclasse.html", **vars())

@app.route('/studente/<int:idstudente>')
def studente_form(idstudente):
	studente = make_query("select * from studenti where id = '{}' ".format(idstudente))[0]
	pprint.pprint(studente)
	return render_template("schedastudente.html", **vars())


@app.route('/updatestudente', methods=['POST'])
def updatestudente():
	idstudente = request.form.get("id")		# se non esiste la chiave restituisce None
	cognome = request.form.get("cognome")	
	nome = request.form.get("nome")
	sesso = request.form.get("sesso")
	matricola = request.form.get("matricola")
	datanascita = request.form.get("datanascita")
	sql = """
		update studenti set 
			matricola = '{matricola}', cognome = '{cognome}', nome = '{nome}',
			sesso = '{sesso}', datanascita = '{datanascita}'
		where id = '{idstudente}'
	""".format(**vars())
	# eseguo la query di update/insert/delete e torno alla scheda
	update_delete_insert_query(sql)	
	return studente_form(idstudente)



if __name__ == '__main__':
	app.secret_key = "mysecretkey"
	app.config["TEMPLATES_AUTO_RELOAD"] = True	# ricarica i templates dinamicamente
	app.run(
		host="0.0.0.0",
		port=9000,
	)
