<----------------------------START---------------------------->
@brief Checks to see if a char is uppercased.
The passed in char is checked to see if it is an uppercase letter.
@param c is the char that is being checked to see if it is an uppercase letter.
@return true if the character is uppercase, and false if it is not
<----DELIM---->
attributes
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) #char_uppercase#
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) #char_uppercase#
<----DELIM---->
{
	return (bool)std::isupper(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_uppercase
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is an uppercase vowel ('A','E','I','O','U','Y').
The passed in char is checked to see if it is an uppercase vowel ('A','E','I','O','U','Y').
@param c is the char that is being checked to see if it is an uppercase vowel ('A','E','I','O','U','Y').
@return true if the character is an uppercase vowel, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) #char_uppercase# (vowel) <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) #char_uppercase# (vowel) <character>
<----DELIM---->
{
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y');
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_uppercase_vowel
<----DELIM---->
<-----------------------------END----------------------------->
