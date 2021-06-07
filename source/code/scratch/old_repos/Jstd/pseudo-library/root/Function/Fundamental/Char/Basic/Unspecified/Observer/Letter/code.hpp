<----------------------------START---------------------------->
@brief Checks to see if a char is a letter.
The passed in char is checked to see if it is a letter.
@param c is the char that is being checked to see if it is an letter.
@return true if the character is a letter, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (in|of) (the|) (alpha(bet|))
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (in|of) (the|) (alpha(bet|))
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) #character# (in|of) (the|) (alpha(bet|))
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) #character# (in|of) (the|) (alpha(bet|))
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) (alpha|alphabetic)
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) (alpha|alphabetic)
<----DELIM---->
{
	return (bool)std::isalpha(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_alpha
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a vowel ('a','e','i','o','u','y','A','E','I','O','U','Y').
The passed in char is checked to see if it is a vowel ('a','e','i','o','u','y','A','E','I','O','U','Y').
@param c is the char that is being checked to see if it is a vowel ('a','e','i','o','u','y','A','E','I','O','U','Y').
@return true if the character is a vowel, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) (vowel) <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) (vowel) <character>
<----DELIM---->
{
	char c2 = std::tolower(c);
	return (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u' || c2 == 'y');
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_vowel
<----DELIM---->
<-----------------------------END----------------------------->
