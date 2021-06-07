#pragma once
#include <string>

//search and replace
std::string destroy_path_name_with_underscores(std::string path);
std::string string_replace_first_instance( std::string src, std::string const& target, std::string const& repl);
std::string string_replace_all( std::string src, std::string const& target, std::string const& repl);
std::string& replace_spaces_with_plus(std::string & str);
std::string& replace_spaces_with_underscore(std::string & str);
std::string& replace_fwd_slash_with_space(std::string & str);
std::string& replace_space_with_fwd_slash(std::string & str);
std::string& replace_all( std::string & src, char const& c1, char const& c2);
std::string& Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(std::string & str);
