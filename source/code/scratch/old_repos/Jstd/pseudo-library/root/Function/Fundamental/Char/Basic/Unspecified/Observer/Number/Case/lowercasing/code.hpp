<----------------------------START---------------------------->
@brief Checks to see if a char is a lowercase roman numeral ('i','v','x','l','c','d','m').
The passed in char is checked to see if it is a lowercase roman numeral ('i','v','x','l','c','d','m').
@param c is the char that is being checked to see if it is a lowercase roman numeral ('i','v','x','l','c','d','m').
@return true if the character is an lowercase roman numeral, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) #char_lowercase# (roman) #digit# <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) #char_lowercase# (roman) #digit# <character>
<----DELIM---->
{
	return (c == 'i' || c == 'v' || c == 'x' || c == 'l' || c == 'c' || c == 'd' || c == 'm');
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_lowercase_roman_numeral
<----DELIM---->
<-----------------------------END----------------------------->
