#include "menu.hpp"
#include "globals.hpp"

#include <iostream>

std::vector<std::string> Menu::menu_choices =
{ "Print the total number of \"words\", along with the number of unique words."
, "Print the number of unique words."
, "Print the top " + std::to_string(constant::NUMBER_OF_TOP_FREQUENT_WORDS) + " most frequently occurring words."
, "Search for a word, if found, print out the word's frequency."
, "Print out all words occurring with a given frequency."
, "New File."
};

void Menu::Print(){
	
	std::cout << "\nMenu\n";
	std::cout << "----\n";
	for (size_t i = 1; i < menu_choices.size()+1; ++i){
		std::cout << i << ". " << menu_choices[i-1] << '\n';
	}
	std::cout << menu_choices.size()+1 << ". Quit.\n\n";
	
	return;
}
size_t Menu::Get_User_Choice(){
	
	std::cout << "Enter a number: ";
	size_t choice;
	std::cin >> choice;
	std::cin.ignore();
	while (choice <= 0 or choice > menu_choices.size()+1){
		std::cout << "Invalid. Enter a number: ";
		std::cin >> choice;
		std::cin.ignore();
	}
	
	return choice;
}