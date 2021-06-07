#pragma once
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "code/utilities/language_basic/std_hackery/lib.hpp"

//add static casts to and from different string types
std::string as_string(std::wstring const& wstr);
std::wstring as_wstring(std::string const& str);

//dummies
std::string as_string(std::string const& s);
std::wstring as_wstring(std::wstring const& s);

//char* coverage
std::string as_string(const char* s);
std::wstring as_wstring(const char* s);

//fallback
template <typename T>
std::wstring as_wstring_tmpl(T t){
   return std::to_wstring(t);
}
//fallback
template <typename T>
std::string as_string_tmpl(T t){
   return std::to_string(t);
}

template <typename T, template <class> class Container>
std::vector<T> To_Vector(Container<T> const& c){
  return std::vector<T>( c.begin(), c.end() );
}

template <typename T>
std::vector<T> Set_To_Vector(std::set<T> const& c){
  return std::vector<T>( c.begin(), c.end() );
}

template <typename T, template <class> class Container>
std::set<T> To_Set(Container<T> const& c){
  return std::set<T>( c.begin(), c.end() );
}
template<typename C>
std::string Get_Each_Element_Of_Vector_As_A_Line_In_A_String(C const& c){
  std::string str;
  for (auto const& it: c){
    str += std::to_string(it) + '\n';
  }
  str.pop_back();;
  return str;
}

template <typename T>
std::string as_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(n) << a_value;
    return out.str();
}
