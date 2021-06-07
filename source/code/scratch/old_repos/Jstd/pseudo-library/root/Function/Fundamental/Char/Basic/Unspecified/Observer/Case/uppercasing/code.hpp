<----------------------------START---------------------------->
@brief Checks to see if a char is a uppercase letter or a number (uppercase alphanumeric).
The passed in char is checked to see if it is a uppercase letter or a number (uppercase alphanumeric).
@param c is the char that is being checked to see if it is a uppercase letter or a number (uppercase alphanumeric).
@return true if the character is a uppercase alphanumeric, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) #char_uppercase# #character# (in|of) (the|) (alpha(bet|))  (or) ((number|numerical) system)
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) #char_uppercase# #character# (in|of) (the|) (alpha(bet|)) (or) ((number|numerical) system)
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) #char_uppercase# #character# (in|of) (the|) ((number|numerical) system)  (or) (alpha(bet|))
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) #char_uppercase# #character# (in|of) (the|) ((number|numerical) system) (or) (alpha(bet|))
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) #char_uppercase# (alphanumeric|alphanum|numalpha|(alphabetic|alpha|<letter>) or (a|an|) #digit#)
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) #char_uppercase# (alphanumeric|alphanum|numalpha|#digit# or (a|an|) (alphabetic|alpha|<letter>))
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) #char_uppercase# (alphanumeric|alphanum|numalpha|(alphabetic|alpha|<letter>) or (a|an|) #digit#)
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) #char_uppercase# (alphanumeric|alphanum|numalpha|#digit# or (a|an|) (alphabetic|alpha|<letter>))
<----DELIM---->
{
	if (std::isalpha(c)){
		return (bool)std::isupper(c);
	}
	return std::isdigit(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_uppercase_alphanumeric
<----DELIM---->
<-----------------------------END----------------------------->
