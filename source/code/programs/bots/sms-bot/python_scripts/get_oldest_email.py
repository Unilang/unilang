#!/usr/bin/env python

#this script is used for reading email only.

#what it does:
# - IT WILL ONLY PROCCESSES THE OLDEST MESSAGE IN THE INBOX (it will never process more than 1 email per run)
# - you will have to call this script again and again to get to the next and next email.
# - it dumps all of the email message data into a folder and prints the email of the user who sent the email.
# - if the program is run again, it will likely overwrite the previous data that was output.

#parameters
#argv[1] - username
#argv[2] - password


#libraries being used
import gmail
import sys
from pprint import pprint


#so here's the thing.  When a phone texts an email, the data may arrive in a variety of ways
#on android phones, I notice that the message data appears in the body of the email (as expected).
#but with iphones, it usually shows up as a text-file attachment. There are occasions when iphones send data
#in which some of it appears as a text message, and some of it occurs in the body of the email.  Sometimes the 
#data shows up in both places (body and as attachment).  This script will output all the attached data as well as
#the message body.  It will be up to another program to determine whether there is any duplicate data or not between
#the body and the attachment data.
#
#1. message body data is sent to a file called "body"
#2. all the attachments are put in a file that starts with a prefix "1" then the file name. 
#   the prefix number counts up for any additional attachments.
#3. the email address who sent the email is printed through stdout

#this the prefix for attachment data
num = 1

#login to our gmail account
g = gmail.login(sys.argv[1], sys.argv[2])

#get all the emails 
#(we don't technically downloaded the emails, I assume we just got a list of what emails we have the ability to get)
emails = g.inbox().mail()

#loop through the emails. We only want to read one email, and so if
#we enter this loop, we'll only do 1 iteration.  If the inbox
#is empty, then we will not do anything further, and quit the program
for email in emails:

	#lets get the oldest email
	email.fetch()

	#store all the attachments with a prefix that counts up from 1
	for attachment in email.attachments:
		attachment.save('message_data/' + str(num) + ' ' + attachment.name)
		num+=1

	#print the body of the email (if there is one)
	str = email.body
	if str:
		f = open('message_data/body','w')
		f.write(str)
		f.close()

	#print the sender of the email through stdout
	print email.fr

	#delete the email so that when this program gets called again, we'll get something
	#different or do nothing since the inbox is empty.  This is extra important, because
	#we will never have to worry about the size of our inbox filling up
	email.delete()

	#quit the program after only looking at that ONE email.
	#this program will never extract data from more than one email per run
	sys.exit()
