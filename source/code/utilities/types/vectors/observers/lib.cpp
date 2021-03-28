#include "code/utilities/types/vectors/observers/lib.hpp"
#include "code/utilities/types/general/lib.hpp"
#include "code/utilities/types/strings/observers/other/lib.hpp"

size_t Get_Longest_String_Length_In_Vector(std::vector<std::string> const& v){
    return (*max_element ( v.begin(), v.end())).length();
}
bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str){
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}
bool An_Element_Ends_With(std::vector<std::string> const& strs, std::string const& str){
    for (auto const& it: strs){
        if (Ends_With(it,str)){
            return true;
        }
    }
    return false;
}

std::string Get_As_Comma_Seperated_String(std::vector<std::string> strs){
  std::string list;
  
  Call_Function_On_All_Elements_Except_Last_Element_Then_Call_Function_On_Last_Element(strs,
  [&](std::string str){list += str + ",";},[&](std::string str){list += str;});
  
  return list;
}
std::string Get_As_Space_Seperated_String(std::vector<std::string> strs){
  std::string list;
  
  Call_Function_On_All_Elements_Except_Last_Element_Then_Call_Function_On_Last_Element(strs,
  [&](std::string str){list += str + " ";},[&](std::string str){list += str;});
  
  return list;
}
std::string Get_As_Newline_Seperated_String(std::vector<std::string> strs){
  std::string list;
  
  Call_Function_On_All_Elements_Except_Last_Element_Then_Call_Function_On_Last_Element(strs,
  [&](std::string str){list += str + "\n";},[&](std::string str){list += str;});
  
  return list;
}
size_t Longest_Element_Size(std::vector<std::string> strs)
{
    size_t max_size = 0;
    for (auto it: strs){
        if (it.size() > max_size){
            max_size = it.size();
        }
    }
    return max_size;
}
std::string Table_As_Column_Aligned(std::vector<std::vector<std::string>> table)
{
    //early return on empty table
    if (table.empty()){return "";}
    
    //what we expect all the column size to remain moving forward
    size_t column_count = table[0].size();
    
    
    //decide the max column widths
    std::vector<size_t> row_maxes;
    for (size_t i = 0; i < column_count; ++i){
        size_t a_max = 0;
        for (auto t: table){
            if (t[i].size() > a_max){
                a_max = t[i].size();
            }
        }
        row_maxes.emplace_back(a_max);
    }
    
    //rebuild as string while applying column widths
    std::string results;
    for (auto row: table){
        for (size_t i = 0; i < row.size(); ++i){
            results += row[i];
            auto spacing = row_maxes[i] - row[i].size();
            for (size_t j = 0; j < spacing; ++j){
                results += " ";
            }
        }
        results += "\n";
    }
    return results;
}

std::vector<std::string> Each_Element_As_Space_Seperated_String(std::vector<std::vector<std::string>> const& v)
{
  
    std::vector<std::string> results;
    for (auto const& set: v){
        auto target_set = Get_As_Space_Seperated_String(set);
        results.emplace_back(target_set);
    }
    return results;
}