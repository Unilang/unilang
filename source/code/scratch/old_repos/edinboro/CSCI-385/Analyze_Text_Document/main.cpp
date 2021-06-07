// Trevor Hickey
// Assignment 8
// Dr. Bennett
// CSCI 385 (Summer 2013)

//STD Headers
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cassert>

//My Headers
#include "globals.hpp"
#include "utilities.hpp"
#include "menu.hpp"
#include "word_analyzer.hpp"
#include "frequency_set.hpp"

//some type defs
using WordType = std::string;
using FrequencyType = unsigned int;
using WordHolder = frequency_set::Frequency_Set<WordType,FrequencyType>;

//FUNCTION DECELERATIONS

	//get file to analyze
	std::string Prompt_For_File_Name();

	//read in the words
	WordHolder Store_Words(std::string const& file_name);

	//perform tasks until user quits
	void Perform_Tasks(WordHolder & frequency_set);

	//Menu Tasks
	void Print_Total_And_Unique(WordHolder const& word_holder);
	void Print_Unique(WordHolder const& word_holder);
	void Print_Top_N_Most_Frequent(WordHolder const& word_holder);
	void Search_And_Print_Frequency(WordHolder const& word_holder);
	void Print_All_Words_Of_A_Given_Frequency(WordHolder const& word_holder);
	void Read_In_New_File(WordHolder & word_holder);

int main(){

	//get the file to analyze
	auto file_name = Prompt_For_File_Name();

	//read in the words
	auto word_holder = Store_Words(file_name);

	//perform tasks until user quits
	Perform_Tasks(word_holder);

	return EXIT_SUCCESS;
}

//get file to analyze
std::string Prompt_For_File_Name(){

	std::string file_name;
	std::cout << "file name: ";

	std::getline(std::cin,file_name);
	while (!File_Exists(file_name)){
		std::cout << "file is missing.\n\nfile name: ";
		std::getline(std::cin,file_name);
	}

	return file_name;
}

//read in the words
WordHolder Store_Words(std::string const& file_name){

	WordHolder word_holder;
	std::ifstream infile(file_name);
	std::string possible_word;

	infile >> possible_word;
	while (infile){

		if (Word_Analyzer::Validate(possible_word)){
			word_holder.Add_Word(Word_Analyzer::Convert_To_Storable_Word(possible_word));
		}

		infile >> possible_word;
	}

	word_holder.All_Data_Added();

	return word_holder;
}

//perform tasks until user quits
void Perform_Tasks(WordHolder & word_holder){

	bool quit = false;
	while (!quit){
		Menu::Print();
		auto choice = Menu::Get_User_Choice();
		switch (choice){

			case 1: Print_Total_And_Unique(word_holder); break;
			case 2: Print_Unique(word_holder); break;
			case 3: Print_Top_N_Most_Frequent(word_holder); break;
			case 4: Search_And_Print_Frequency(word_holder); break;
			case 5: Print_All_Words_Of_A_Given_Frequency(word_holder); break;
			case 6: Read_In_New_File(word_holder); break;
			case 7: quit = true; break;

			default:
			assert (!"Should not have been reached. Get_User_Choice returned in invalid choice");
		}
	}

	return;
}

//Menu Tasks
void Print_Total_And_Unique(WordHolder const& word_holder){

	std::cout << "\nThere are a total of "
	<< Add_Commas(word_holder.Total_Words()) << " words, and "
	<< Add_Commas(word_holder.Total_Unique_Words()) << " unique words.\n";
	return;
}
void Print_Unique(WordHolder const& word_holder){

	std::cout << "\nThere are a total of "
	<< Add_Commas(word_holder.Total_Unique_Words()) << " unique words.\n";
	return;
}
void Print_Top_N_Most_Frequent(WordHolder const& word_holder){

	std::cout << "\nThe top " << constant::NUMBER_OF_TOP_FREQUENT_WORDS << " most frequent words are:\n";
	for (auto const& it: word_holder.Get_Top_N_Most_Frequent(constant::NUMBER_OF_TOP_FREQUENT_WORDS)){
		std::cout << "\t" << Add_Commas(it.second) << " " << it.first << "\n";
	}

	return;
}
void Search_And_Print_Frequency(WordHolder const& word_holder){

	WordType user_word;
	std::cout << "Type in a word to search for: ";
	std::getline(std::cin,user_word);

	std::cout << "\nThe word " << user_word << " occurs " << Add_Commas(word_holder.Search_By_Word(user_word)) << " times.\n";
	return;
}
void Print_All_Words_Of_A_Given_Frequency(WordHolder const& word_holder){

	FrequencyType user_frequency;
	std::cout << "Type in a frequency to search for: ";
	std::cin >> user_frequency;
	std::cin.ignore();
	auto words = word_holder.Search_By_Frequency(user_frequency);

	std::cout << "\nThere are " << Add_Commas(words.size()) << " words, each occurring " << Add_Commas(user_frequency) << " times:\n";
	for (auto const& it: words){
		std::cout << "\t" << it << '\n';
	}

	return;
}
void Read_In_New_File(WordHolder & word_holder){

	//get the new file to analyze
	auto file_name = Prompt_For_File_Name();

	//read in the words
	word_holder = Store_Words(file_name);

	return;
}

