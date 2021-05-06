#include "code/utilities/types/strings/observers/splitting/lib.hpp"
#include<boost/tokenizer.hpp>
#include <string>
#include <iostream>
#include <sstream>

std::vector<std::vector<std::string>> Split_Into_Parts(std::string const& str, int part1, int part2){
    std::vector<std::vector<std::string>> results;
    std::vector<std::string> temp;
    std::string stemp;
    int at_part1 = 0;
    int at_part2 = 0;
    for (auto const& it: str){
        stemp += it;
        ++at_part1;
        
        //first layer
        if (at_part1 == part1){
            temp.emplace_back(stemp);
            stemp.clear();
            at_part1 = 0;
            ++at_part2;
        }
        
        if (at_part2 == part2){
            results.emplace_back(temp);
            temp.clear();
            at_part2 = 0;
        }
    }
    
    return results;
}

std::vector<std::string> Split_By_Whitespace(std::string const& str){
    std::istringstream buffer(str);
    std::vector<std::string> ret;

    std::copy(std::istream_iterator<std::string>(buffer), 
              std::istream_iterator<std::string>(),
              std::back_inserter(ret));
    return ret;
}

std::vector<std::string> Split_Into_Parts_From_Delimiter(std::string const& i_str, std::string const& i_delim)
{
    std::vector<std::string> result;
    
    size_t found = i_str.find(i_delim);
    size_t startIndex = 0;

    while(found != std::string::npos)
    {
        result.push_back(std::string(i_str.begin()+startIndex, i_str.begin()+found));
        startIndex = found + i_delim.size();
        found = i_str.find(i_delim, startIndex);
    }
    if(startIndex != i_str.size())
        result.push_back(std::string(i_str.begin()+startIndex, i_str.end()));
    return result;      
}

std::vector<std::string> Split_Into_Parts_From_Delimiter(std::string const& str, char const& delimiter){
	std::vector<std::string> parts;
	
	std::string part;
	for (auto const& c: str){
		if (c == delimiter){
			parts.push_back(part);
			part.clear();
		}else{
			part+=c;
		}
	}

	if (!part.empty()){
		parts.push_back(part);
	}
	return parts;
 }
std::vector<std::string> Split_Into_Parts_From_Comma(std::string const& str){
	return Split_Into_Parts_From_Delimiter(str,',');
}
std::vector<std::string> Split_Into_Parts_From_Colon(std::string const& str){
    return Split_Into_Parts_From_Delimiter(str,':');
}
std::vector<std::string> Split_Into_Parts_From_Dot(std::string const& str){
    return Split_Into_Parts_From_Delimiter(str,'.');
}
std::vector<std::string> Split_Into_Parts_From_Fwd_Slash(std::string const& str){
    return Split_Into_Parts_From_Delimiter(str,'/');
}
std::vector<std::string> Split_Into_Parts_From_Back_Slash(std::string const& str){
    return Split_Into_Parts_From_Delimiter(str,'\\');
}
 std::vector<std::string> Get_Path_In_Parts(std::string const& str){
 	return Split_Into_Parts_From_Delimiter(str,'/');
}
std::string Get_Path_Basename(std::string const& str)
{
    auto parts = Get_Path_In_Parts(str);
    if (!parts.empty()){
        return parts[parts.size()-1];
    }
    return "";
}

std::vector<std::vector<std::string>> Split_By_Spaces(std::vector<std::string> const& strs){
    std::vector<std::vector<std::string>> results;
    
    std::vector<std::string> tmp;
    for (auto const& it: strs){
        if (it == ""){
            results.emplace_back(tmp);
            tmp.clear();
        }
        else{
            tmp.emplace_back(it);
        }
    }
    
    if (!tmp.empty()){
        results.emplace_back(tmp);
    }
    
    return results;
}

std::vector<std::string> Split_By_Spaces(std::string const& str){
 	return Split_Into_Parts_From_Delimiter(str,' ');
}
std::vector<std::string> Split_Into_Parts_From_Newline(std::string const& str){
    return Split_Into_Parts_From_Delimiter(str,'\n');
}
std::vector<std::string> Split_Into_Parts_From_Dash(std::string const& str){
    return Split_Into_Parts_From_Delimiter(str,'-');
}
std::vector<std::string> Split_Into_Parts_From_Open_Paren(std::string const& str){
    return Split_Into_Parts_From_Delimiter(str,')');
}
std::vector<std::string> Split_Into_Parts_From_Close_Paren(std::string const& str){
    return Split_Into_Parts_From_Delimiter(str,')');
}

std::string Get_Last_Line(std::string const& str){
    auto parts = Split_Into_Parts_From_Newline(str);
    
    if (parts.empty()){
        return "";
    }
    
    return parts[parts.size() - 1];
}

std::string Get_Path_After_Desktop(std::string const& str)
{
	auto parts = Get_Path_In_Parts(str);
	
	//rebuild after Desktop
	std::string path;
	bool found = false;
	for (auto it: parts){
		if (found){
			path += it + '/';
		}
		else{
			if (it == "Desktop"){
				found = true;
			}
		}
		
	}
	path.pop_back();
	return path;
}

std::pair<std::string,std::string> Split_On_First_Instance_Of_Char(std::string const& str, char const& c){
 	 std::pair<std::string,std::string> results;
 	 std::string first;
 	 std::string second;
 	 bool found = false;
 	 for (auto it: str){
 	 	if (!found){
 	 		first += it;
 	 	}else{
 	 		second += it;
 	 	}
 	 	
 	 	
 	 	if (it == c){
 	 		found = true;
 	 	}
 	 	
 	 }
 	 
 	 results.first = first;
 	 results.second = second;
 	 
 	 return results;
 }
std::pair<std::string,std::string> Split_On_Second_Instance_Of_Char(std::string const& str, char const& c){
 	 std::pair<std::string,std::string> results;
 	 std::string first;
 	 std::string second;
 	 int found = 0;
 	 for (auto it: str){
 	 	if (found < 2){
 	 		first += it;
 	 	}else{
 	 		second += it;
 	 	}
 	 	
 	 	
 	 	if (it == c){
 	 		found++;
 	 	}
 	 	
 	 }
 	 
 	 results.first = first;
 	 results.second = second;
 	 
 	 return results;
 }

std::pair<std::string,std::string> Split_By_Char(std::string const& str, char const& c){
    std::pair<std::string,std::string> p;
    bool left = true;
    for (auto const& it: str){
    
        if (left){
            if (it == c){left = false;}
            else{p.first+=it;}
        }
        else{p.second+=it;}
        
    }    
    return p;
}
std::vector<std::string> Default_Boost_Tokenize(std::string const& str)
{
    std::vector<std::string> results;
    using namespace std;
    using namespace boost;
    tokenizer<> tok(str);
    for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg){
       results.emplace_back(*beg);
    }
    return results;
}
std::vector<int> Default_Boost_Tokenize_To_Ints(std::string const& str)
{
    using namespace std;
    using namespace boost;
    std::vector<int> results;
    tokenizer<> tok(str);
    for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg){
       results.emplace_back(std::stoi(*beg));
    }
    return results;
}



