#python e mongo#import python mongo libraries

from pymongo import MongoClient
client = MongoClient()
db = client.unipr
db.twitter.drop()
db.tweets.drop()
db.users.drop()
