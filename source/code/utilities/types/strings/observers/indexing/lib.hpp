#pragma once
#include <string>
#include <vector>

size_t Get_Index_After_Found_Substring(std::string const& str, std::string const& substring);
std::pair<size_t,size_t> Get_Start_And_End_Positions_Of_First_Word(std::string const& str);
std::pair<size_t,size_t> Get_Start_Position_And_Length_Of_First_Word(std::string const& str);
std::vector<size_t> Get_Indexes_Of_Character(std::string const& s, char const& c);
std::vector<size_t> Get_Indexes_Of_Substring_Through_Case_Insensitive_Comparing(std::string src, std::string substr);
