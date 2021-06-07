#pragma once
#include <set>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

#include "word_comparator.hpp"
#include "frequency_comparator.hpp"

namespace frequency_set{
	
	template <typename WordType, typename FrequencyType>
	class Frequency_Set{
	public:
		
		//constructor
		Frequency_Set()
		: total(0)
		{}
		
		//Transformers
		void Add_Word(WordType const& word){
			
			//attempt to add the word with a frequency of one
			auto ret = this->word_list.insert(comparator::Word_Comparator<WordType,FrequencyType>(word));
			
			//if the word already exists, increment its frequency
			if (!ret.second){
				ret.first->Increment_Frequency();
			}
			
			return;
		}
		
		void All_Data_Added(){
			
			//build the frequency_list
			for (auto const& it: word_list){
				frequency_list.push_back(comparator::Frequency_Comparator<WordType,FrequencyType>(it.Word(),it.Frequency()));
				
				//and count the totals
				total+= it.Frequency();
			}
			
			//sort by frequency
			std::sort(frequency_list.rbegin(), frequency_list.rend());
			
			return;
		}
		
		//Observing
		
			//Counting
			FrequencyType Total_Words() const {return total;}
			FrequencyType Total_Unique_Words() const {return frequency_list.size();}
			
			//Searching
			FrequencyType Search_By_Word(WordType const& word) const {
				using namespace std::rel_ops;
				auto ret = word_list.find(comparator::Word_Comparator<WordType,FrequencyType>(word));
				
				if (ret != word_list.end()){
					return ret->Frequency();
				}
				
				return 0;
			}
			std::vector<WordType> Search_By_Frequency(FrequencyType const& frequency) const{ 
				
				std::vector<WordType> words;
				auto range = std::equal_range(frequency_list.rbegin(),frequency_list.rend(),comparator::Frequency_Comparator<WordType,FrequencyType>("",frequency));
				for ( auto i = range .first; i != range.second; ++i ){
					words.push_back(i->Word());
				}
				
				return words;
			}
			
			//Get Top n Most Frequent
			std::vector<std::pair<WordType,FrequencyType>> Get_Top_N_Most_Frequent(unsigned int number_of_words) const{
				
				std::vector<std::pair<WordType,FrequencyType>> top_n;
				
				//NOTE: you will always get 10 values.  
				//There may be more entries that have an equal frequency count
				//that will not show up in the list.
				for (unsigned int i = 0; i < number_of_words; ++i){
					top_n.push_back(std::pair<WordType,FrequencyType>(frequency_list[i].Word(),frequency_list[i].Frequency()));
				}
				
				return top_n;
			}
		
	private:
		
		//two data structures to hold data sorted by both word and frequency
		std::set<comparator::Word_Comparator<WordType,FrequencyType>>         word_list;
		std::vector<comparator::Frequency_Comparator<WordType,FrequencyType>> frequency_list;
		
		//the total that will be calculated when the frequency list is built
		unsigned int total;
		
	};
}
