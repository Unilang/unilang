#pragma once
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>


//searching
bool Contains_Character(std::string const& s, char const& c);
bool Begins_With(std::string const& str, std::string const& start_part);
bool Begins_With_Any(std::string const& str, std::vector<std::string> const& start_parts);
bool Ends_With(std::string const& str, std::string const& end_part);
bool Begins_And_Ends_With(std::string const& str, std::string const& part);
bool Begins_Or_Ends_With(std::string const& str, std::string const& part);
bool Begins_With(std::string const& str, char const& start_part);

bool Ends_With(std::string const& str, char const& end_part);
bool Begins_And_Ends_With(std::string const& str, char const& part);
bool Contains_Substring(std::string const& str, std::string const& part);
bool Contains_Substring(std::string const& str, char const& part);
std::string Get_Substring_Found_Between_First_Instance_Of_Two_Characters(std::string str, char first, char last);
std::string All_Characters_After_Last_Found_String(std::string const& str, std::string const& search);

//scanning from the front
std::string Get_All_Beginning_Characters_Until_Capital_Letter(std::string const& str);
bool First_Char_Comes_Before_Second_Char(std::string const& s, char const& c1, char const& c2);

template <typename T>
void Alphabetize_And_Print(std::vector<T> results){
	std::sort(results.begin(),results.end());
	for (auto const& it: results){std::cout << it << '\n';}
	return;
}

size_t height(std::string const& str);

int XorCheckSum(std::string const& s);
