<----------------------------START---------------------------->
@brief Checks to see if a char is a digit.
The passed in char is checked to see if it is a digit.
@param c is the char that is being checked to see if it is an digit.
@return true if the character is a digit, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) <character> #digit#
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) <character> #digit#
<----DELIM---->
{
	return (bool)std::isdigit(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_digit
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a hexadecimal character.
The passed in char is checked to see if it is a hexadecimal character.
@param c is the char that is being checked to see if it is a hexadecimal character.
@return true if the character is a hexadecimal character, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) (hex|hexadecimal) <character> <digit>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) (hex|hexadecimal) <character> <digit>
<----DELIM---->
{
	return (bool)std::isxdigit(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_hexidecimal
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is an even number ('0','2','4','6','8').
The passed in char is checked to see if it is an even number ('0','2','4','6','8').
@param c is the char that is being checked to see if it is an even number ('0','2','4','6','8').
@return true if the character is an even number, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) (even) #digit# <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) (even) #digit# <character>
<----DELIM---->
{
	return (c == '0' || c == '2' || c == '4' || c == '6' || c == '8');
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_even_number
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is an odd number ('1','3','5','7','9').
The passed in char is checked to see if it is an odd number ('1','3','5','7','9').
@param c is the char that is being checked to see if it is an odd number ('1','3','5','7','9').
@return true if the character is an odd number, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) (odd) #digit# <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) (odd) #digit# <character>
<----DELIM---->
{
	return (c == '1' || c == '3' || c == '5' || c == '7' || c == '9');
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_odd_number
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a prime number ('2','3','5','7').
The passed in char is checked to see if it is a prime number ('2','3','5','7').
@param c is the char that is being checked to see if it is a prime number ('2','3','5','7').
@return true if the character is a prime number, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) (prime) #digit# <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) (prime) #digit# <character>
<----DELIM---->
{
	return (c == '2' || c == '3' || c == '5' || c == '7');
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_prime_number
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a roman numeral ('i','v','x','l','c','d','m','I','V','X','L','C','D','M').
The passed in char is checked to see if it is a roman numeral ('i','v','x','l','c','d','m','I','V','X','L','C','D','M').
@param c is the char that is being checked to see if it is a roman numeral ('i','v','x','l','c','d','m','I','V','X','L','C','D','M').
@return true if the character is a roman numeral, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) (roman) #digit# <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) (roman) #digit# <character>
<----DELIM---->
{
	char c2 = std::tolower(c);
	return (c2 == 'i' || c2 == 'v' || c2 == 'x' || c2 == 'l' || c2 == 'c' || c2 == 'd' || c2 == 'm');
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_roman_numeral
<----DELIM---->
<-----------------------------END----------------------------->
