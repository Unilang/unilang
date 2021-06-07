<----------------------------START---------------------------->
@brief Checks to see if a char is a lowercase letter or a number (lowercase alphanumeric).
The passed in char is checked to see if it is a lowercase letter or a number (lowercase alphanumeric).
@param c is the char that is being checked to see if it is a lowercase letter or a number (lowercase alphanumeric).
@return true if the character is a lowercase alphanumeric, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) #char_lowercase# #character# (in|of) (the|) (alpha(bet|))  (or) ((number|numerical) system)
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) #char_lowercase# #character# (in|of) (the|) (alpha(bet|)) (or) ((number|numerical) system)
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) #char_lowercase# #character# (in|of) (the|) ((number|numerical) system)  (or) (alpha(bet|))
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) #char_lowercase# #character# (in|of) (the|) ((number|numerical) system) (or) (alpha(bet|))
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) #char_lowercase# (alphanumeric|alphanum|numalpha|(alphabetic|alpha|<letter>) or (a|an|) #digit#)
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) #char_lowercase# (alphanumeric|alphanum|numalpha|#digit# or (a|an|) (alphabetic|alpha|<letter>))
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) #char_lowercase# (alphanumeric|alphanum|numalpha|(alphabetic|alpha|<letter>) or (a|an|) #digit#)
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) #char_lowercase# (alphanumeric|alphanum|numalpha|#digit# or (a|an|) (alphabetic|alpha|<letter>))
<----DELIM---->
{
	if (std::isalpha(c)){
		return (bool)std::islower(c);
	}
	return std::isdigit(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_lowercase_alphanumeric
<----DELIM---->
<-----------------------------END----------------------------->
