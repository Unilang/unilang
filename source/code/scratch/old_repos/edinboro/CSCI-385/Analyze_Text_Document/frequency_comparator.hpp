#pragma once

#include <string>
#include <utility>

#include "frequency_set_comparator.hpp"

namespace frequency_set{
	namespace comparator{
		template <typename WordType, typename FrequencyType>
		class Frequency_Comparator: public Frequency_Set_Comparator<WordType,FrequencyType>{
			
		public:
			
			//constructor (c++11 method: "using A::A")
			explicit Frequency_Comparator<WordType,FrequencyType>(WordType const& word_, FrequencyType const& frequency_=1)
			: Frequency_Set_Comparator<WordType,FrequencyType>(word_,frequency_)
			{}
			
			//these are the only relational operators we need to implement.
			//we'll deduce the rest through std::rel_ops
			
			//comparing two frequency comparators
			friend bool operator < (Frequency_Comparator<WordType,FrequencyType> const& lhs, Frequency_Comparator<WordType,FrequencyType> const& rhs){
				return lhs.frequency < rhs.frequency;
			}
			friend bool operator == (Frequency_Comparator<WordType,FrequencyType> const& lhs, Frequency_Comparator<WordType,FrequencyType> const& rhs){
				return lhs.frequency == rhs.frequency;
			}

			//comparing a frequency comparator and a FrequencyType
			//Do we really need these? Alternatively, we could just instantiate a new 
			//frequency comparator whose word value would be empty, but then we would be
			//creating an unneeded WordType.  We could also provide an implicit cast
			//to a FrequencyType, but that has other dangers.  I choose to provide more overloads.
			friend bool operator < (Frequency_Comparator<WordType,FrequencyType> const& lhs, FrequencyType const& rhs){
				return lhs.frequency < rhs;
			}
			friend bool operator < (FrequencyType const& lhs, Frequency_Comparator<WordType,FrequencyType> const& rhs){
				return lhs < rhs.frequency;
			}
			friend bool operator == (Frequency_Comparator<WordType,FrequencyType> const& lhs, FrequencyType const& rhs){
				return lhs.frequency == rhs;
			}
			friend bool operator == (FrequencyType const& lhs, Frequency_Comparator<WordType,FrequencyType> const& rhs){
				return lhs == rhs.frequency;
			}
			
		};
	}
}