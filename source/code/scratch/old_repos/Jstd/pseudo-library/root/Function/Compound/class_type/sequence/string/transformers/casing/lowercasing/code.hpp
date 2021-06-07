<----------------------------START---------------------------->
@brief Lowercase a std::string.
The passed in std::string has all of its characters changed to lowercase.  The lowercase string is returned by reference.
@param str is the std::string that gets changed to lowercase.
@returns a lowercased string
<----DELIM---->
attributes
<----DELIM---->
<----DELIM---->
std::string&
std::string&
str
<----DELIM---->
#mutate# <string> (to|into|) (lower|lowercase|undercase|small case)
<mutate> (to|into|) (lower|lowercase|undercase|small case|unupper|unuppercase|uncaps|all ununical) <string>
<mutate> (to|into|) (lower|lowercase|undercase|small case|unupper|unuppercase|uncaps|all ununical) (the|this) #string#
<mutate> (to|into|) (lower|lowercase|undercase|small case|unupper|unuppercase|uncaps|all ununical) (the|this|) (specified|indicated|passed in|given) #string#
<----DELIM---->
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
lowercase
<----DELIM---->
<-----------------------------END----------------------------->
