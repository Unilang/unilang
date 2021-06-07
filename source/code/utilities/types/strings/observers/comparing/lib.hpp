#pragma once
#include <string>

//comparing two string
bool Case_Insensitive_String_Compare(std::string const& str1, std::string const& str2);
bool Case_Insensitive_Alpha_Compare(std::string str1, std::string str2);
bool Case_Insensitive_Undercore_Ignoring_String_Compare(std::string str1, std::string str2);
bool Case_Insensitive_Undercore_And_Space_Ignoring_String_Compare(std::string str1, std::string str2);
bool Non_Case_Sensitive_Compare(std::string str1, std::string str2);
bool Case_Sensitive_Compare(std::string const& str1, std::string const& str2);

size_t Levenshtein_Distance(std::string const& str1, std::string const& str2);
