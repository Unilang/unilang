<----------------------------START---------------------------->
@brief Checks to see if a char is an uppercase roman numeral ('I','V','X','L','C','D','M').
The passed in char is checked to see if it is an uppercase roman numeral ('I','V','X','L','C','D','M').
@param c is the char that is being checked to see if it is an uppercase roman numeral ('I','V','X','L','C','D','M').
@return true if the character is an uppercase roman numeral, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) #char_uppercase# (roman) #digit# <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) #char_uppercase# (roman) #digit# <character>
<----DELIM---->
{
	return (c == 'I' || c == 'V' || c == 'X' || c == 'L' || c == 'C' || c == 'D' || c == 'M');
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_uppercase_roman_numeral
<----DELIM---->
<-----------------------------END----------------------------->
