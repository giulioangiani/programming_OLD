"""
REST Web Service with Python and Flask 

INTRO (in Italian): https://www.html.it/pag/19595/introduzione-ai-web-service/
REST and Python: https://blog.miguelgrinberg.com/post/designing-a-restful-api-with-python-and-flask
HTTP STATUSES: https://restfulapi.net/http-status-codes/

"""
from flask import Flask, jsonify, abort, make_response, request
import json
app = Flask(__name__)
app.secret_key = "12345678901234567890"

response_success_template = {
	"success": True,
	"message": "",
	"data": {}
}	
response_error_template = {
	"success": False,
	"error_code": -1,
	"message": "",
	"data": {}
}	

tasks = [
	{
		'id': 1,
		'title': u'Buy groceries',
		'description': u'Milk, Cheese, Pizza, Fruit, Tylenol', 
		'done': False
	},
	{
		'id': 2,
		'title': u'Learn Python',
		'description': u'Need to find a good Python tutorial on the web', 
		'done': False
	}
]

@app.route('/')
def home():
	return """<h3>Avoid this URI!</h3>
	<h4>This page does not respect the REST protocol!<h4>
	<h4>This is only an entry point!!</h4>
	Use :<br>
	<a href='/tasks'>all tasks</a><br>
	<a href='/tasks/1'>task n.1</a><br>
	<a href='/tasks/3'>no task n.3</a><br>
	<hr>
	<a href='/taskform'>go to the object creation form</a><br>
	"""
	
# READ => GET
@app.route('/tasks', methods=['GET'])
def taskslist():
	response_dict = {
		"success": True,
		"message": "Lista dei task presenti",
		"data": {
			"tasks": tasks
		}
	}	
	
	response = make_response(json.dumps(response_dict))
	response.headers["Content-type"] = "application/json"
	return response

	"""
	in alternativa

	response_success_template["message"] = "Lista dei task presenti"
	response_success_template["data"] = {"tasks": tasks}
	return jsonify(response_success_template), 200
	"""

# READ => GET
@app.route('/tasks/<int:task_id>', methods=['GET'])
def task(task_id):
	for elem in tasks:
		if elem['id'] == task_id:
			response_success_template["message"] = "Task presente"
			response_success_template["data"] = {"task" : elem}
			return jsonify(response_success_template), 200
	# default # not found
	response_error_template["message"] = "Task non presente"
	response_error_template["error_code"] = 5	# un codice applicativo qualsiasi documentato
	return jsonify(response_error_template), 404


@app.route('/taskform', methods=['GET'])
def form_task():
	""" destinatario un browser
		restuisce HTML con content-type text/html
	"""
	return """Create new task <br><br>
	 <form action='/task' method='POST'>
		 titolo : <input name='title' value='esame di stato'><br>
		 descrizione : <input size=50 name='description' value="studiare seriamente per l'esame"><br>
		 <input type='submit' name='submit' value='Crea nuovo task'>
	 </form>
	"""

# CREATE => POST (via form)
@app.route('/task', methods=['POST'])
def endpoint_per_creazione_task_via_post():
	"""
		nel request deve essere specificato il content-type: application/json
	"""
	if not request.form or not 'title' in request.form:
		# gira la richiesta all'errorhandler(400) customizzato in basso
		# se non viene riscritto l'handler viene usato un errore di default
		abort(400)
	task = {
		'id': tasks[-1]['id'] + 1,
		'title': request.form['title'],
		'description': request.form.get('description', ""),
		'done': False
	}
	tasks.append(task)
	response_success_template["message"] = "Task creato correttamente"
	response_success_template["data"] = {"task": task}
	return jsonify(response_success_template), 201


# DELETE => DELETE method
@app.route('/task/<int:task_id>', methods=['DELETE'])
def delete_task_via_ws(task_id):
	"""
		da implementare
	"""
	return jsonify({"message": "to be implemented"}), 401


# UPDATE => PUT method
@app.route('/task/<int:task_id>', methods=['PUT'])
def update_task_via_ws(task_id):
	"""
		da implementare
	"""
	return jsonify({"message": "to be implemented"}), 401


# customize error responses
@app.errorhandler(400)
def not_found(error):
	response_error_template["error_code"] = 3 # formato non valido
	response_error_template["message"] = "Formato task non valido" # messaggio human-readable
	return jsonify(response_error_template), 400


@app.errorhandler(404)
def not_found(error):
	response_error_template["error_code"] = 1000 # formato non valido
	response_error_template["message"] = "Servizio non presente" # messaggio human-readable
	return jsonify(response_error_template), 404


if __name__ == '__main__':
	app.run()
