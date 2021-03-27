#lol this script is kinda stupid.
#I actually just print a 1 for failure and 0 for success,
#and then analyze that string value in the core program.
#Yeah, there is probably a better way to bind python code into c++,
#but for right now, I have no problem just calling the script directly and get information back through the shell.
#the return values are meaningless since I just look at the printed values.
#I would like to not have to print, and instead look at the return values; so if you want to add that to the pre-Jstd, thanks! :)

#!/usr/bin/env python

#parameters
#argv[1] - username
#argv[2] - password

#libraries being used
import gmail
import sys
from pprint import pprint

try:
	#login to our gmail account
	g = gmail.login(sys.argv[1], sys.argv[2])
	g.logged_in
except:
	print str(1)
	sys.exit(1) #threw an exception catch and return bad

print str(0)
sys.exit(0) #passed. return good