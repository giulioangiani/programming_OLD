from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
	return "Hi, guys!"
	
	
@app.route('/main')
def main():
	content = "I love Python"
	title = "My first page"
	return "<html><body><h1>{title}</h1><h4>{content}</h4></body></html>".format(**vars())
	

	
@app.route('/lista')
def lista():
	content = "Lista degli articoli presenti"
	title = "Lista articoli"

	lista_articoli = "<ul>"
	articoli = [(1, 'Mouse', 9.99), (2, 'Tastiera', 19.99), (3, 'Tablet', 299.99)]
	for a in articoli:
		lista_articoli += "<li>{} {}".format(a[1], a[2])
	lista_articoli += "</ul>"

	return """<html><body>
						<h1>{title}</h1>
						<h4>{content}</h4>
						{lista_articoli}
					</body></html>
			""".format(**vars())
	

@app.route('/main2')
def main2():
	content = "I love Python"
	title = "My first page"
	return render_template("home.html", **vars())
	

@app.route('/lista2')
def lista2():
	content = "Lista degli articoli presenti"
	title = "Lista articoli"
	articoli = [(1, 'Mouse', 9.99), (2, 'Tastiera', 19.99), (3, 'Tablet', 299.99)]
	return render_template("articoli.html", **vars())


@app.route('/elements')
def elements():
	content = "I love Python and Jinja!"
	title = "My first page"
	elements = [
		{
			"id": 1,
			"description": "Mouse",
			"prezzo": 9.99
		},
		{
			"id": 2,
			"description": "Tastiera",
			"prezzo": 19.99
		},
		{
			"id": 3,
			"description": "Tablet",
			"prezzo": 299.99
		}
	]
	PANEL = "pannello di controllo"
	return render_template("elements.html", **vars())


@app.route('/esercizio2')
def ordine():
	title = "Esercizio n. 2"
	dati_cliente = {
		"nome": "Marcella",
		"cognome": "Bella",
	}
	dati_ordine = {
		"id": 281,
		"data": "2021-01-15",
	}
	righe_ordine = [
		{	"id": 1,
			"descrizione": "Penna",
			"qta": 3,
			"prezzo": 1.19 },
		{	"id": 2,
			"descrizione": "Quaderno",
			"qta": 2,
			"prezzo": 2.35 },
		{	"id": 3,
			"descrizione": "Libro",
			"qta": 1,
			"prezzo": 10.99 },
	]
	totale = sum(elem["prezzo"]*elem["qta"] for elem in righe_ordine)
	return render_template("ordine.html", **vars())



if __name__ == '__main__':
	app.secret_key = "mysecretkey"
	app.config["TEMPLATES_AUTO_RELOAD"] = True	# ricarica i templates dinamicamente
	app.run(
		host="0.0.0.0",
		port=9000,
	)
