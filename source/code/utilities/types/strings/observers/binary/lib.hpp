#pragma once
#include <string>
#include <vector>


//ascii string <-> binary
std::vector<std::string> To_Binary(std::string const& str);
std::string From_Binary(std::vector<std::string> const& str);
