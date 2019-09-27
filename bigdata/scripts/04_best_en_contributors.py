#python e mongo
from pymongo import MongoClient, ASCENDING, DESCENDING
from bson.son import SON
import pprint
client = MongoClient()
db = client.unipr
collections = db.list_collection_names()
c_users = db.users
c_tweets = db.tweets

# aggregation
# tweet per utente - ma filtrati per lingua

pipeline = [
			{"$match": {"lang": "en"} },		# <<<<<
			{"$group": {"_id": "$user.screen_name", "count": {"$sum": 1}}},
			{"$sort": SON([("count", -1), ("_id", -1)])}	# Using SON python library
		]

lista = list(db.tweets.aggregate(pipeline))
print("Primi 3 elementi: ")
for elem in lista[0:3]:
	print elem['_id'], elem['count']
	
first = lista[0]
#print("primo: ", first)
screen_name = first["_id"]

# tutti i tweet dell'utente piu' attivo
#tws = c_tweets.find({"user.screen_name": screen_name})
#for t in tws:
#	print(t["lang"]+ " : " +  t["text"])
#	pprint.pprint(t)

