#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "code/utilities/types/strings/observers/other/lib.hpp"
#include "code/utilities/types/strings/observers/front_back/lib.hpp"
#include "code/utilities/types/general/lib.hpp"
#include "code/utilities/types/strings/observers/char/lib.hpp"
#include "code/utilities/types/char/lib.hpp"
#include <algorithm>
#include <iostream>


std::string Remove_And_Get_First_Char(std::string & s){
    
    std::string result = "";
    if (!s.empty()){
        result += s.front();
        s.erase(0,1);
    }
    return result;
}

std::string& Remove_All_Instances_Of_Char(std::string & str, char const& c)
{
	str.erase(std::remove(str.begin(), str.end(), c), str.end());
	return str;
}
std::string& Remove_First_Instance_Of_Char(std::string & str, char const& c){
    auto index = str.find(c);
    if (index != std::string::npos) {
        str.erase(index,1);
    }
    
        return str;
}

std::string As_Chars_Removed(std::string const& str, std::string const& chars){
    
    std::string result;
    for (auto const& it: str){
        
        bool found = false;
        for (auto const& c: chars){
            if (c == it){
                found = true;
                break;
            }
        }
        
        if (!found){
            result += it;
        }
    }
    return result;
}

std::string& Remove_Spaces(std::string & str)
{
    return Remove_All_Instances_Of_Char(str,' ');
}
std::string& Remove_Commas(std::string & str)
{
	return Remove_All_Instances_Of_Char(str,',');
}
std::string& Remove_Question_Marks(std::string & str)
{
    return Remove_All_Instances_Of_Char(str,'?');
}
std::string& Remove_Double_Quotes(std::string & str)
{
    return Remove_All_Instances_Of_Char(str,'"');
}
std::string& Remove_Dashes(std::string & str)
{
    return Remove_All_Instances_Of_Char(str,'-');
}
std::string& Remove_Periods(std::string & str)
{
    return Remove_All_Instances_Of_Char(str,'.');
}

std::string As_Removed_Dashes(std::string const& str){
    auto str2 = str;
    return Remove_Dashes(str2);
}

std::string& Remove_Match_If_It_Is_Found_At_Beginning_Or_End(std::string & str, std::string const& match){
        if (Begins_Or_Ends_With(str,match)){
                Remove_Match_Found_At_Beginning_Or_End(str,match);
        }
        return str;
}

std::string& Remove_Match_If_It_Is_Found_At_Beginning(std::string & str, std::string const& match){
        if (Begins_With(str,match)){
                Remove_Match_Found_At_Beginning(str,match);
        }
        return str;
}
std::string& Remove_Match_If_It_Is_Found_At_End(std::string & str, std::string const& match){
        if (Ends_With(str,match)){
                Remove_Match_Found_At_End(str,match);
        }
        return str;
}

std::string& Remove_Match_Found_At_Beginning_Or_End(std::string & str, std::string const& match){
        Remove_Match_Found_At_Beginning(str,match);
        Remove_Match_Found_At_End(str,match);
        return str;
}
std::string& Remove_Match_Found_At_Beginning(std::string & str, std::string const& match){
        if (Begins_With(str,match)){
                Remove_First_N_Chars(str,match.size());
        }
        return str;
}
std::string& Remove_Match_Found_At_End(std::string & str, std::string const& match){
        if (Ends_With(str,match)){
                Remove_Last_N_Chars(str,match.size());
        }
        return str;
}

std::string& Remove_All_Beginning_Characters_That_Match_Any_Of_The_Following_Characters(std::string & str, std::string const& chars){
        while(Contains(chars,First_Char(str))){
                str.erase(0,1);
        }
        return str;
}

std::string& Remove_Matching_Beginning_Part_Of_String(std::string & str, std::string const& match){
        
        auto min = std::min(str.size(),match.size());
        
        int count = 0;
        for (size_t i = 0; i < min; ++i){
                if (str[i] == match[i]){
                        ++count;
                }else{
                        break;
                }
        }
        Remove_First_N_Chars(str, count);
        
        return str;
}
std::string As_Beginning_Matching_Part_Of_String_Removed(std::string const& str, std::string const& match){
        
        auto min = std::min(str.size(),match.size());
        std::string new_string;
        
        int count = 0;
        for (size_t i = 0; i < min; ++i){
                if (str[i] == match[i]){
                        ++count;
                }else{
                        break;
                }
        }
        new_string = str;
        Remove_First_N_Chars(new_string, count);
        
        return new_string;
}

//keeping certain characters
std::string& Keep_Only_Numeric_Chars(std::string & str)
{
    std::string new_str;
    
    //only keep the numbers
    for (auto c: str){
        if (Is_A_Numeric_Character(c)){
            new_str += c;
        }
    }
    
    
    //replace
    str = new_str;
    return str;
}


//changing front
std::string& Remove_First_Char(std::string &s){
    if (!s.empty()){
        s.erase(0,1);
    }
    return s;
}
std::string& Remove_Last_Char(std::string &s){
    if (!s.empty()){
        s.pop_back();
    }
    return s;
}
std::string As_First_Char_Removed(std::string const& s){
    std::string new_string = s;
    return Remove_First_Char(new_string);
}
std::string As_Last_Char_Removed(std::string const& s){
    std::string new_string = s;
    return Remove_Last_Char(new_string);
}

std::string& Remove_All_Chars_From_Front_Until_Char_Is_Seen(std::string & str, char const& c){
    while(1){
        if (str.empty()){
            break;
        }else{
            if(str[0] == c){
                break;
            }else{
                str.erase(0,1);
            }
        }
    }
    return str;
}
std::string& Remove_All_Chars_From_Back_Until_Char_Is_Seen(std::string & str, char const& c){
    while(1){
        if (str.empty()){
            break;
        }else{
            if(Last_Char(str) == c){
                break;
            }else{
                Remove_Last_Char(str);
            }
        }
    }
    return str;
}

std::string As_All_Chars_Removed_From_Back_Until_Char_Is_Seen(std::string str, char const& c){
    while(1){
        if (str.empty()){
            break;
        }else{
            if(Last_Char(str) == c){
                break;
            }else{
                Remove_Last_Char(str);
            }
        }
    }
    return str;
}

std::string& Remove_All_Chars_From_Front_Until_Char_Is_Seen_A_Number_Of_Times(std::string & str, char const& c, unsigned int number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        Remove_All_Chars_From_Front_Until_Char_Is_Seen(str,c);
        if (i < number_of_times-1){
            Remove_First_Char(str);
        }
    }
    return str;
}
std::string& Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(std::string & str, char const& c, unsigned int number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        Remove_All_Chars_From_Back_Until_Char_Is_Seen(str,c);
        if (i < number_of_times-1){
            Remove_Last_Char(str);
        }
    }
    return str;
}

std::string& Remove_First_N_Chars(std::string & str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.erase(0,1);
        }else{
            return str;
        }
    }
    return str;
}
std::string& Remove_Last_N_Chars(std::string & str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.pop_back();
        }else{
            return str;
        }
    }
    return str;
}

std::string As_First_N_Chars_Removed(std::string str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.erase(0,1);
        }else{
            return str;
        }
    }
    return str;
}
std::string As_Last_N_Chars_Removed(std::string str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.pop_back();
        }else{
            return str;
        }
    }
    return str;
}

std::string As_Beginning_Matching_Part_Of_String_Kept(std::string const& str, std::string const& match){
        
        auto min = std::min(str.size(),match.size());
        std::string new_string;
        
        int count = 0;
        for (size_t i = 0; i < min; ++i){
                if (str[i] == match[i]){
                        ++count;
                }else{
                        break;
                }
        }
        new_string = str;
        Keep_Only_First_N_Characters(new_string, count);
        
        return new_string;
}

std::string& Remove_N_Chars_From_Front_And_Back(std::string & str, unsigned int const& number_of_times){
    return Remove_First_N_Chars(Remove_Last_N_Chars(str,number_of_times),number_of_times);
}
std::string As_N_Chars_Removed_From_Front_And_Back(std::string str, unsigned int const& number_of_times){
    return As_First_N_Chars_Removed(As_Last_N_Chars_Removed(str,number_of_times),number_of_times);
}

std::string As_NonAlphas_Removed(std::string const& str){
        std::string new_str;
        
        for (auto const& it: str){
                if (Is_An_Alpha_Character(it)){
                        new_str += it;
                }
        }
        
        return new_str;
}

std::string& Remove_Suffix(std::string &s) {
    auto it = s.rfind(".");
    if (it !=  std::string::npos) {
        s.erase(it, s.size());
    }
    return s;
}
std::string As_Removed_Suffix(std::string s) {
    auto it = s.rfind(".");
    if (it !=  std::string::npos) {
        s.erase(it, s.size());
    }
    return s;
}

std::string& Remove_First_And_Last_Char(std::string & str){
        Remove_First_Char(str);
        Remove_Last_Char(str);
        return str;
}

std::string& Keep_Matching_Beginning_Part_Of_String(std::string & str, std::string const& match){
        
        auto min = std::min(str.size(),match.size());
        
        int count = 0;
        for (size_t i = 0; i < min; ++i){
                if (str[i] == match[i]){
                        ++count;
                }else{
                        break;
                }
        }
        Keep_Only_First_N_Characters(str, count);
        
        return str;
}

std::string& Keep_Only_First_N_Characters(std::string & str, unsigned int const& count){
        std::string new_string;
        for (size_t i = 0; i < count; ++i){
                if (i == count){
                        break;
                }
             if (i > str.size()-1){
                     break;
             }else{
                   new_string += str[i];   
             }
        }
        str = new_string;
        return str;
}

std::string& Empty_String_If_It_Only_Contains_Whitespace(std::string & str){
         if (Contains_Only_Whitespace_Characters(str)){
                str.clear();
        }
        return str;
}
std::string As_Empty_String_If_It_Only_Contains_Whitespace(std::string str){
         if (Contains_Only_Whitespace_Characters(str)){
                str.clear();
        }
        return str;
}

std::string& Remove_Everything_After_Found_Instance(std::string & str, std::string const& instance)
{
    //mystr = str.substr(0, str.find("%", 0));
    str.erase(str.find (instance), str [str.length() - 1]);
    return str;
}
std::string& Remove_Everything_Before_Found_Instance(std::string & str, std::string const& instance)
{
    str.erase(0, str.find(instance) + instance.size());
    return str;
}


//keeping back
std::string& Keep_End_Chars_Until_Char_Is_Found(std::string & str, char const& c)
{
    std::string new_str;
    for (size_t i = str.size()-1; i >= 0; --i){
        if (str[i] == c){
            str = new_str;
            return str;
        }
        new_str = str[i] + new_str;
        
    }
    
    str = new_str;
    return str;
}
