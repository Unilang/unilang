#include "code/utilities/types/strings/transformers/other/lib.hpp"
#include "code/utilities/types/strings/transformers/appending/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "code/utilities/types/strings/observers/columns/lib.hpp"
#include "code/utilities/types/strings/observers/char/lib.hpp"
#include "code/utilities/types/strings/observers/indexing/lib.hpp"
#include "code/utilities/types/strings/creators/lib.hpp"
#include "code/utilities/types/char/lib.hpp"
#include "code/utilities/types/strings/observers/converting/lib.hpp"
#include "code/utilities/types/booleans/lib.hpp"

#include <sstream>
#include <cctype>
#include <map>
#include <utility>
#include <string>
#include "boost/algorithm/string/predicate.hpp"


std::vector<int> Collect_Whitespace_Separated_Numbers(std::string const& s){
        auto parts = Get_Each_Column(s);
        std::vector<int> numbers;
        for (auto it: parts){
                numbers.push_back(as_signed(it));
        }
        return numbers;
}
std::vector<float> Collect_Whitespace_Separated_Floats(std::string const& s){
        auto parts = Get_Each_Column(s);
        std::vector<float> numbers;
        for (auto it: parts){
                numbers.push_back(std::stof(it));
        }
        return numbers;
}

//both

std::vector<char> Convert_To_Vec_Of_Chars(std::string const& str){
        std::vector<char> all;
        for (auto it: str){
                all.push_back(it);
        }
        return all;
}

std::string& Indent_Each_Line_N_Amount(std::string & str, unsigned int amount){
      std::string indent_line(amount,' ');
      Add_Prefix_To_Each_Line(str,indent_line);
      return str;
}


std::string& Add_Prefix_To_Each_Line(std::string & str, std::string const& prefix){
        std::string new_str = prefix;
        
        for (auto const& it: str){
                new_str += it;
                if (it == '\n'){
                        new_str += prefix;
                }
        }
        
        str = new_str;
        return str;
}

std::string& Add_Prefix_To_All_Lines_Except_First(std::string & str, std::string const& prefix){
        std::string new_str;
        
        for (auto const& it: str){
                new_str += it;
                if (it == '\n'){
                        new_str += prefix;
                }
        }
        
        str = new_str;
        return str;
}
//--



std::string& Turn_Any_Whitespace_Chars_Into_A_Space(std::string & str){
        for (auto & it: str){
                if (Is_A_Whitespace_Character(it)){
                        it = ' ';
                }
        }
        return str;
}

std::string& Append_To_Front(std::string & str, std::string const& part){
        str = part + str;
        return str;
}
std::string& Append_To_Back(std::string & str, std::string const& part){
        str += part;
        return str;
}
std::string& Append_To_Front_Of_Each_Line(std::string & str, std::string const& part){
        std::string new_str = part;
        for (auto const& it: str){
                new_str+=it;
                if (it == '\n'){new_str+= part;}
        }
        
        str = new_str;
        return str;
}
std::string& Append_To_Back_Of_Each_Line(std::string & str, std::string const& part){
        std::string new_str;
        for (auto const& it: str){
                if (it == '\n'){new_str+= part;}
                new_str+=it;
        }
        new_str += part;
        str = new_str;
        return str;
}

std::string& Indent_Each_Line(std::string & str, int indent_amount){
        auto indents = Create_String_Of_N_Spaces(indent_amount);
        Append_To_Front_Of_Each_Line(str,indents);
        return str;
}

std::string& Add_File_Extension(std::string &s, std::string const& extension){
    s+="." + extension;
    return s;
}
std::string As_Added_File_Extension(std::string s, std::string const& extension){
    return s+"." + extension;
}

std::string& Replace_File_Extension(std::string &s, std::string const& new_extension){
    Add_File_Extension(Remove_Suffix(s),new_extension);
    return s;
}
std::string As_Replaced_Extension(std::string s, std::string const& new_extension){
    return As_Added_File_Extension(As_Removed_Suffix(s),new_extension);
}

std::string& Move_First_Word_Of_String_To_The_End(std::string & str){
        auto start_and_length = Get_Start_Position_And_Length_Of_First_Word(str);
        auto word = str.substr (start_and_length.first,start_and_length.second);
        str.erase(start_and_length.first,start_and_length.second);
        str+=word;
        return str;
}
std::string As_First_Word_Of_String_Moved_To_The_End(std::string str){
        return Move_First_Word_Of_String_To_The_End(str);
}

//changing the end of a string (assuming it's a directory name)
std::string Get_Path_As_A_Number_Of_Directories_Back(std::string dir_name, unsigned int const& amount_back){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',amount_back);
    return dir_name;
}
std::string Get_Path_As_One_Directories_Back(std::string dir_name){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',1);
    return dir_name;
}
std::string Get_Path_As_Two_Directories_Back(std::string dir_name){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',2);
    return dir_name;
}
std::string Get_Path_As_Three_Directories_Back(std::string dir_name){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',3);
    return dir_name;
}

std::string& Convert_Non_Digits_To_Spaces(std::string& s){
        for (auto & it: s){
                if (!Is_A_Numeric_Character(it)){
                        it = ' ';
                }
        }
        return s;
}

//strings and bools
void Falsify_Bool_If_Line_Is_Empty(std::string const& line, bool & b){
    if (Contains_Only_Whitespace_Characters(line)){Make_False(b);}
}
void Falsify_Bool_If_Line_Is_Empty(bool & b, std::string const& line){
    if (Contains_Only_Whitespace_Characters(line)){Make_False(b);}
}
