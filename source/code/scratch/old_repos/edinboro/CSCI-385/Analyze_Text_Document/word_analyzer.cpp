#include "word_analyzer.hpp"
#include <cctype>

bool Word_Analyzer::Validate(std::string const& str){
	
	for (size_t i = 0; i < str.size()-1; ++i){
		if (!std::isalpha(str[i])){
			return false;
		}
	}
	
	if (!Is_Alpha_Or_Puncuation(str[str.size()-1])){
		return false;
	}
	
	return true;
}
bool Word_Analyzer::Is_Alpha_Or_Puncuation(char const& c){
	return (std::isalpha(c) || Is_Puncuation(c));
}

std::string& Word_Analyzer::Convert_To_Storable_Word(std::string & str){
	return Remove_Puncuation(Lowercase(str));
}
std::string& Word_Analyzer::Lowercase(std::string & str){
	
	for (auto & it: str){
		it = std::tolower(it);
	}
	return str;
}
std::string& Word_Analyzer::Remove_Puncuation(std::string & str){
	
	if (Is_Puncuation(str[str.size()-1])){
		str.pop_back();
	}
	
	return str;
}
bool Word_Analyzer::Is_Puncuation(char const& c){
	return (bool)ispunct(c);
}
