<----------------------------START---------------------------->
@brief Checks to see if a char is lowercased.
The passed in char is checked to see if it is a lowercase letter.
@param c is the char that is being checked to see if it is a lowercase letter.
@return true if the character is lowercase, and false if it is not
<----DELIM---->
attributes
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) #char_lowercase#
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) #char_lowercase#
<----DELIM---->
{
	return (bool)std::islower(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_lowercase
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a lowercase vowel ('a','e','i','o','u','y').
The passed in char is checked to see if it is a lowercase vowel ('a','e','i','o','u','y').
@param c is the char that is being checked to see if it is a lowercase vowel ('a','e','i','o','u','y').
@return true if the character is an lowercase vowel, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) #char_lowercase# (vowel) <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) #char_lowercase# (vowel) <character>
<----DELIM---->
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_lowercase_vowel
<----DELIM---->
<-----------------------------END----------------------------->
