#pragma once
#include <string>

//apply character testing on all elements of string
bool Is_Only_Control_Characters(std::string const& str);
bool Is_Only_Printable_Characters(std::string const& str);
bool Is_Only_Whitespace_Characters(std::string const& str);
bool Is_Only_Blank_Characters(std::string const& str);
bool Is_Only_Graphical_Characters(std::string const& str);
bool Is_Only_Puncuation_Characters(std::string const& str);
bool Is_Only_Alphanumberic_Characters(std::string const& str);
bool Is_Only_Alpha_Characters(std::string const& str);
bool Is_Only_Uppercase_Characters(std::string const& str);
bool Is_Only_Lowercase_Characters(std::string const& str);
bool Is_Only_Numeric_Characters(std::string const& str);
bool Is_Only_Hexidecimal_Characters(std::string const& str);
bool Has_Only_Lowercase_Letters_And_Underscores(std::string const& str);
bool Has_Only_Uppercase_Letters_And_Underscores(std::string const& str);
bool Has_Only_Lowercase_Letters_Underscores_And_Forward_Slashes(std::string const& str);
bool Has_Only_Uppercase_Letters_Underscores_And_Forward_Slashes(std::string const& str);
bool Has_Only_Alpha_Letters_And_Underscores(std::string const& str);
bool Has_Only_Alphanumeric_And_Underscores(std::string const& str);
bool Has_Only_Uppercase_Letters_Numbers_And_Underscores(std::string const& str);
bool Starts_With_Digit(std::string const& str);


//character testing on at least 1 char
bool Has_A_Numeric_Character(std::string const& str);

//character observing
bool Consecutive_Space_In_The_Middle(std::string s);
bool Contains_Only_Whitespace_Characters(std::string const& str);
bool Contains_Capital_Letters(std::string const& s);
