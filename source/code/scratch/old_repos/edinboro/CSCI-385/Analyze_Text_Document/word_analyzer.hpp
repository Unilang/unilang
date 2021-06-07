#pragma once

#include <string>

class Word_Analyzer{
	
	//non constructible
	Word_Analyzer()=delete;
	
public:
	
	//interface
	static bool Validate(std::string const& str);
	static std::string& Convert_To_Storable_Word(std::string & str);
	
private:
	
	//utility functions
	static bool Is_Alpha_Or_Puncuation(char const& c);
	static std::string& Lowercase(std::string & str);
	static std::string& Remove_Puncuation(std::string & str);
	static bool Is_Puncuation(char const& c);
	
};