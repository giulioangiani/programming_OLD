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
