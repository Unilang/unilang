#pragma once

#include <string>
#include <utility>

#include "frequency_set_comparator.hpp"

namespace frequency_set{
	namespace comparator{
		template <typename WordType, typename FrequencyType>
		class Word_Comparator: public Frequency_Set_Comparator<WordType,FrequencyType>{
			
		public:
			
			//constructor (c++11 method: "using A::A")
			explicit Word_Comparator<WordType,FrequencyType>(WordType const& word_, FrequencyType const& frequency_=1)
			: Frequency_Set_Comparator<WordType,FrequencyType>(word_,frequency_)
			{}
			
			//these are the only relational operators we need to implement.
			//we'll deduce the rest through std::rel_ops
			
			//comparing two word comparators
			friend bool operator < (Word_Comparator<WordType,FrequencyType> const& lhs, Word_Comparator<WordType,FrequencyType> const& rhs){
				return lhs.word < rhs.word;
			}
			friend bool operator == (Word_Comparator<WordType,FrequencyType> const& lhs, Word_Comparator<WordType,FrequencyType> const& rhs){
				return lhs.word == rhs.word;
			}

			//comparing a word comparator and a WordType.
			//Do we really need these? Alternatively, we could just instantiate a new 
			//word comparator whose frequency would always be 0, but then we would be
			//creating an unneeded FrequencyType.  We could also provide an implicit cast
			//to a WordType, but that has other dangers.  I choose to provide more overloads.
			friend bool operator < (Word_Comparator<WordType,FrequencyType> const& lhs, WordType const& rhs){
				return lhs.word < rhs;
			}
			friend bool operator < (WordType const& lhs, Word_Comparator<WordType,FrequencyType> const& rhs){
				return lhs < rhs.word;
			}
			friend bool operator == (Word_Comparator<WordType,FrequencyType> const& lhs, WordType const& rhs){
				return lhs.word == rhs;
			}
			friend bool operator == (WordType const& lhs, Word_Comparator<WordType,FrequencyType> const& rhs){
				return lhs == rhs.word;
			}
			
			//Transformers
			void Increment_Frequency() const{
				++this->frequency;
				return;
			}
			
		};
	}
}