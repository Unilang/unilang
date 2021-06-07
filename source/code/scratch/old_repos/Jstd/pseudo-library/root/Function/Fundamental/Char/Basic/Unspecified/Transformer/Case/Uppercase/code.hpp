<----------------------------START---------------------------->
@brief Uppercase a char.
The passed in char has all of its characters changed to uppercase.  The uppercase character is returned by reference.
@param c is the char that gets changed to uppercase.
@return an uppercased character
<----DELIM---->
attributes
<----DELIM---->
<----DELIM---->
char&
char&
c
<----DELIM---->
#mutate# <character> (to|into|) #char_uppercase#
<mutate> (to|into|) #char_uppercase# <character>
<mutate> (to|into|) #char_uppercase# (the|this) #character#
<mutate> (to|into|) #char_uppercase# (the|this|) (specified|indicated|passed in|given) #character#
<----DELIM---->
{
	c = std::toupper(c);
	return c;
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
uppercase
<----DELIM---->
<-----------------------------END----------------------------->
