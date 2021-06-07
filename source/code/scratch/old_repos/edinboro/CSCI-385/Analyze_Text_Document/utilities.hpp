#pragma once
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>

bool File_Exists(std::string const& filename);

template<class T>
std::string Add_Commas(T value)
{
	static std::locale l(""); //constructor is said to be slow
    std::stringstream ss;
    ss.imbue(l);
    ss << std::fixed << value;
    return ss.str();
}