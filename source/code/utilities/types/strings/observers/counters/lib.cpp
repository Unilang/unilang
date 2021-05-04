#include "code/utilities/types/strings/observers/counters/lib.hpp"
#include "code/utilities/types/char/lib.hpp"
#include <vector>

unsigned int Starts_With_Char_How_Many_Times(std::string const& str, char c){
	unsigned int count=0;
	
	for (std::size_t i = 0; i < str.size(); ++i){
		if (str[i] == c){
			++count;
		}
		else{
			break;
		}
	}
	
	return count;
}
unsigned int Starts_With_How_Many_Spaces(std::string const& str){
	return Starts_With_Char_How_Many_Times(str,' ');
}
unsigned int Starts_With_How_Many_Dots(std::string const& str){
    return Starts_With_Char_How_Many_Times(str,'.');
}
unsigned int Count_Instances_Of_Character(std::string const& s, char const& c) {
    unsigned int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            ++count;
        }
    }

    return count;
}

unsigned int Count_Newlines(std::string const& s){
    return Count_Instances_Of_Character(s,'\n');
}


unsigned int Count_Instances_Of_Character(std::vector<std::string> const& vec, char const& c){
    unsigned int total = 0;
    for (auto const& it: vec){
        total += Count_Instances_Of_Character(it,c);
    }
    return total;
}


//specific
unsigned int Count_Instances_Of_Zeros(std::vector<std::string> const& vec){
    return Count_Instances_Of_Character(vec,'0');
}
unsigned int Count_Instances_Of_Ones(std::vector<std::string> const& vec){
    return Count_Instances_Of_Character(vec,'1');
}
unsigned int Count_Instances_Of_Twos(std::vector<std::string> const& vec){
    return Count_Instances_Of_Character(vec,'2');
}
