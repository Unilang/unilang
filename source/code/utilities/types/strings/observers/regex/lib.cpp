#include "code/utilities/types/strings/observers/regex/lib.hpp"
#include <regex>

bool Matches_Regex(std::string const& str, std::string const& regex){
    std::regex obj_regex(regex);
    return std::regex_match(str, obj_regex);
}