#pragma once
#include <string>
#include <vector>
#include <utility>

//converting to other types
unsigned int as_unsigned(std::string str);
signed int as_signed(std::string str);
long as_long(std::string str);
unsigned long as_unsigned_long(std::string str);
std::vector<std::string> Put_Each_Line_Of_String_Into_A_Vector(std::string const& str);
std::vector<std::string> Put_Each_Char_Of_String_Into_A_Vector(std::string const& str);
std::vector<std::pair<std::string,std::string>> Put_Each_Line_Of_String_Into_A_Vector_Of_Pairs_Where_The_First_Pair_Elements_Are_Empty(std::string const& str);
