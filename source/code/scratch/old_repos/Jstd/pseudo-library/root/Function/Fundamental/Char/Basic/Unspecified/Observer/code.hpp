<----------------------------START---------------------------->
@brief Checks to see if a char is a letter or a number (alphanumeric).
The passed in char is checked to see if it is a letter or a number (alphanumeric).
@param c is the char that is being checked to see if it is a letter or a number (alphanumeric).
@return true if the character is alphanumeric, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (in|of) (the|) (alpha(bet|)) (or) ((number|numerical) system)
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (in|of) (the|) (alpha(bet|))  (or) ((number|numerical) system)
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (in|of) (the|) ((number|numerical) system) (or) (alpha(bet|))
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (in|of) (the|) ((number|numerical) system)  (or) (alpha(bet|))
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) #character# (in|of) (the|) (alpha(bet|))  (or) ((number|numerical) system)
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) #character# (in|of) (the|) (alpha(bet|)) (or) ((number|numerical) system)
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) #character# (in|of) (the|) ((number|numerical) system)  (or) (alpha(bet|))
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) #character# (in|of) (the|) ((number|numerical) system) (or) (alpha(bet|))
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) (alphanumeric|alphanum|numalpha|(alphabetic|alpha|<letter>) or (a|an|) #digit#)
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|an|) (alphanumeric|alphanum|numalpha|#digit# or (a|an|) (alphabetic|alpha|<letter>))
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) (alphanumeric|alphanum|numalpha|(alphabetic|alpha|<letter>) or (a|an|) #digit#)
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|an|) (alphanumeric|alphanum|numalpha|#digit# or (a|an|) (alphabetic|alpha|<letter>))
<----DELIM---->
{
	return (bool)std::isalnum(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_alphanumeric
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a control character.
The passed in char is checked to see if it is a control character.
@param c is the char that is being checked to see if it is a control character.
@return true if the character is a control character, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) (cntrl|control) <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) (cntrl|control) <character>
<----DELIM---->
{
	return (bool)std::iscntrl(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_control
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a graphical character.
The passed in char is checked to see if it is a graphical character.
@param c is the char that is being checked to see if it is a graphical character.
@return true if the character is a graphical character, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) (graph|graphical|visible|seeable) <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) (graph|graphical|visible|seeable) <character>
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (seen)
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (seen)
<----DELIM---->
{
	return (bool)std::isgraph(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_graphical
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a printable character.
The passed in char is checked to see if it is a printable character.
@param c is the char that is being checked to see if it is a printable character.
@return true if the character is a printable character, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) (print|printable) <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) (print|printable) <character>
<----DELIM---->
{
	return (bool)std::isprint(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_printable
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a whitespace character.
The passed in char is checked to see if it is a whitespace character.
@param c is the char that is being checked to see if it is a whitespace character.
@return true if the character is a whitespace character, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) (whitespace) <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) (whitespace) <character>
<----DELIM---->
{
	return (bool)std::isspace(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_whitespace
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a blank character.
The passed in char is checked to see if it is a blank character.
@param c is the char that is being checked to see if it is a blank character.
@return true if the character is a blank character, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) (blank) <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) (blank) <character>
<----DELIM---->
{
	return (bool)std::isblank(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_blank
<----DELIM---->
<-----------------------------END----------------------------->

<----------------------------START---------------------------->
@brief Checks to see if a char is a punctuation character.
The passed in char is checked to see if it is a punctuation character.
@param c is the char that is being checked to see if it is a punctuation character.
@return true if the character is a punctuation character, and false if it is not
<----DELIM---->
<----DELIM---->
<----DELIM---->
bool
char const&
c
<----DELIM---->
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) ((punc|punct|punctuation) (mark|)) <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) ((punc|punct|punctuation) (mark|)) <character>
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) #character# (of|) ((punc|punct|punctuation) (mark|))
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) #character# (of|) ((punc|punct|punctuation) (mark|))
(is) (the|this|) (specified|indicated|passed in|given|) <character> (observed (as|to be|)|) (a|) (mark of (punc|punct|punctuation)) <character>
(the|this|) (specified|indicated|passed in|given|) #character# (is) (observed (as|to be|)|) (a|) (mark of (punc|punct|punctuation)) <character>
<----DELIM---->
{
	return (bool)std::ispunct(c);
}
<----DELIM---->
<----DELIM---->
<----DELIM---->
is_punctuation
<----DELIM---->
<-----------------------------END----------------------------->
