#!/usr/bin/python
#This script will send a tweet with a twitter account

import sys, time, tweepy

#all the important login credentials are passed in via the command line
#./this-script <tweet> <CONSUMER_KEY> <CONSUMER_SECRET> <ACCESS_KEY> <ACCESS_SECRET>
CONSUMER_KEY = sys.argv[2]
CONSUMER_SECRET = sys.argv[3]
ACCESS_KEY = sys.argv[4]
ACCESS_SECRET = sys.argv[5]


def Log_Message(message):
  with open("python_tweet.log", "a") as myfile:
    myfile.write(message)
    
#Send a tweet and return true or false as to whether or not it succeeded
def Send_Tweet(tweet):
 try:
   auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
   auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)
   api = tweepy.API(auth)
   api.update_status(tweet)
   return True
 except:
   return False


open('python_tweet.log', 'w').close()
Log_Message("SENT: " + sys.argv[1] + "\n")
success =  Send_Tweet(sys.argv[1])
while (success == False):
  Log_Message("FAILED TO SEND.  TRYING AGAIN IN 10 SECONDS\n")
  time.sleep( 10 )
  success =  Send_Tweet(sys.argv[1])
  
Log_Message("TWEET SUCCESSFULLY SENT\n")

