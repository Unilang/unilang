#pragma once

#include <vector>
#include <string>

class Menu{
	
	//non constructible 
	Menu()=delete;
	
public:
	static void Print();
	static size_t Get_User_Choice();

private:
	static std::vector<std::string> menu_choices;
};