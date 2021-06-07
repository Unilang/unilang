<----------------------------START---------------------------->
@brief Uppercase a std::string.
The passed in std::string has all of its characters changed to uppercase.  The uppercase string is returned by reference.
@param str is the std::string that gets changed to uppercase.
@return an uppercased string
<----DELIM---->
attributes
<----DELIM---->
<----DELIM---->
std::string&
std::string&
str
<----DELIM---->
#mutate# <string> (to|into|) (upper|uppercase|caps|all unical)
<mutate> (to|into|) (upper|uppercase|caps|all unical|unlower|unlowercase|unundercase|unsmall case) <string>
<mutate> (to|into|) (upper|uppercase|caps|all unical|unlower|unlowercase|unundercase|unsmall case) (the|this) #string#
<mutate> (to|into|) (upper|uppercase|caps|all unical|unlower|unlowercase|unundercase|unsmall case) (the|this|) (specified|indicated|passed in|given) #string#
<----DELIM---->
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
uppercase
<----DELIM---->
<-----------------------------END----------------------------->
