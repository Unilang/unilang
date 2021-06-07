#pragma once
#include <string>

//APPENDING
//appending to string
std::string& Append_With_Newline(std::string & str, std::string const& part);
std::string& Append_With_Newline_Unless_Empty(std::string & str, std::string const& part);
std::string& Append_With_Newline(std::string & str, char const& part);
std::string& Append_With_Space(std::string & str, std::string const& part);
std::string& Append_With_Space(std::string & str, char const& part);
std::string& Append_With_Tab(std::string & str, std::string const& part);
std::string& Append_With_Tab(std::string & str, char const& part);
std::string& Append(std::string & str, std::string const& part);
std::string& Append(std::string & str, char const& part);
std::string& Append_In_DQuotes(std::string & str, std::string const& part);
std::string& Append_In_DQuotes(std::string & str, char const& part);
std::string& Append_Key_Value(std::string & str, std::string const& key, std::string const& val);
std::string& Append_N_Times(std::string & str, std::string const& part, unsigned int number_of_times);
std::string& Append_A_Newline(std::string & str);
std::string& Append_A_Space(std::string & str);
std::string& Append_A_Tab(std::string & str);
std::string& Append_N_Newlines(std::string & str, int number_of_times);
std::string& Append_N_Spaces(std::string & str, int number_of_times);

//language specific
std::string& Append_Tabbed_Bash_Comment_With_Newline(std::string & str, std::string const& part);
std::string& Append_Bash_Comment_With_Newline(std::string & str, std::string const& part);

//appending to wstring
std::string& Append_With_Newline(std::string & str, std::wstring const& part);
std::string& Append(std::string & str, std::wstring const& part);
std::string& Append_N_Times(std::string & str, std::wstring const& part, unsigned int number_of_times);
