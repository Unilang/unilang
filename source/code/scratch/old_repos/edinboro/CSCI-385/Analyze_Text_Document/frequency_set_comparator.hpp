#pragma once

namespace frequency_set{
	namespace comparator{
		template <typename WordType, typename FrequencyType>
		class Frequency_Set_Comparator{
			
		public:
			
			//constructor
			explicit Frequency_Set_Comparator(WordType const& word_, FrequencyType const& frequency_=1)
			: word(word_)
			, frequency(frequency_)
			{}
				
			//Observers
			WordType Word() const{ return word; }
			FrequencyType Frequency() const{ return frequency; }

		protected:
			
			//data
			WordType word;
			mutable FrequencyType frequency; // :)
		};
	}
}