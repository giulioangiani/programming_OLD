import pprint 
import os
import time
import csv
import random
import sys
import re

#import python mongo libraries
from pymongo import MongoClient
client = MongoClient()
db = client.unipr
db.twitter.drop()
db.tweets.drop()
db.users.drop()

#Import the necessary methods from tweepy library
from tweepy.streaming import StreamListener
from tweepy import OAuthHandler
from tweepy import Stream
from tweepy import API
from tweepy import Cursor
from tweepy.error import RateLimitError, TweepError

d = {
	"consumer_key": "",
	"consumer_secret": "",
	"access_token": "",
	"access_token_secret": ""
}

args = sys.argv
search_token = args[1]
tweets_to_download = int(args[2])

auth = OAuthHandler(d["consumer_key"], d['consumer_secret'])
auth.set_access_token(d['access_token'], d['access_token_secret'])
api = API(auth)



downloaded = 0
maxid = None

while downloaded < tweets_to_download:
	new = 0
	tweets = api.search(q=search_token, count=100, max_id=maxid)
	for t in tweets:
		#pprint.pprint(t._json)
		print(t.id)
		if not db.tweets.find_one({"id_str": str(t.id)}):
#			print("insert ", t.id)
			db.tweets.insert_one(t._json)
			new += 1
#		else:
#			print("presente ", t.id)
		#print(dir(t))
		u = t.user
		#pprint.pprint(u._json)
		# se non e' presente lo inserisco nella collection
		if not db.users.find_one({"screen_name" : u.screen_name}):
			db.users.insert_one(u._json)
	
	maxid = min([t.id for t in tweets])
		
	print("scaricati nuovi" , new)		
	print("new max id >>> ", maxid)
	downloaded += new
	time.sleep(2)
	


