<----------------------------START---------------------------->
@brief Lowercase a char.
The passed in char has all of its characters changed to lowercase.  The lowercase character is returned by reference.
@param c is the char that gets changed to lowercase.
@returns a lowercased character
<----DELIM---->
attributes
<----DELIM---->
<----DELIM---->
char&
char&
c
<----DELIM---->
#mutate# <character> (to|into|) #char_lowercase#
<mutate> (to|into|) #char_lowercase# <character>
<mutate> (to|into|) #char_lowercase# (the|this) #character#
<mutate> (to|into|) #char_lowercase# (specified|indicated|passed in|given) #character#
<----DELIM---->
{
	c = std::tolower(c);
	return c;
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
lowercase
<----DELIM---->
<-----------------------------END----------------------------->
