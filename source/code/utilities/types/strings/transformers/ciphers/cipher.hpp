#pragma once
#include <string>
#include <cstdlib>
#include <boost/lexical_cast.hpp>

namespace cipher{

	using boost::lexical_cast;
    using boost::bad_lexical_cast;

	// base class for a cipher
	template <class Cipher_Type>
	class Cipher {};

	// derived class for a Caesar cipher
	template <class Alphabet = alphabet::Alphabet<alphabet::English_Alphabet>>
	class Caesar {

		//constructor
		public: Caesar(int shift_amount)
		: m_shift_up(shift_amount)
		{Adjust_Shift();}

		//observers
		//decode a string
		public: std::string Decode(std::string const& str) {
			std::string result;
			char char_temp;
			for (auto const& it: str) {
				char_temp = Decode(tolower(it));
				result += (isupper(it)  ? toupper(char_temp) : char_temp);
			}

			return result;
		}

		//decode an individual character
		private: char Decode(char const& c) {
			auto index = Alphabet::Char_To_Index(c);
			if (-1 == index) { return c;}
			index -= m_shift_up;
			return (index < 0) ? Alphabet::At(Alphabet::Size()+index) : Alphabet::At(index);
		}

		//encode a string
		public: std::string Encode(std::string const& str) {
			std::string result;
			char char_temp;
			for (auto const& it: str) {
				char_temp = Encode(tolower(it));
				result += (isupper(it)  ? toupper(char_temp) : char_temp);
			}

			return result;
		}

		//encode an individual character
		private: char Encode(char const& c) {
			auto index = Alphabet::Char_To_Index(c);
			if (-1 == index) { return c;}
			index += m_shift_up;
			return (index >= Alphabet::Size()) ? Alphabet::At(index-Alphabet::Size()) : Alphabet::At(index);
		}

		//reduce the shift for values that are larger than the whole alphabet,
		//and convert negative left shift values to a positive right shift value.
		private: void Adjust_Shift() {
			if (m_shift_up >= Alphabet::Size()) {
				m_shift_up = (m_shift_up%Alphabet::Size());
			}else if (m_shift_up < 0) {
				m_shift_up = (Alphabet::Size() - (abs(m_shift_up)%Alphabet::Size()));
				if (m_shift_up == Alphabet::Size()) { m_shift_up = 0;}
			}
		}

		//data members
		private: int m_shift_up = 0;

	};

	// derived class for a Vigenere cipher
	template <class Alphabet = alphabet::Alphabet<alphabet::English_Alphabet>>
	class Vigenere {

		//constructor
		public: Vigenere(std::string const& encryption_key)
		: m_encryption_key(As_Lowercase(encryption_key))
		, m_encryption_index(0)
		{}

		//observers
		//decode a string
		public: std::string Decode(std::string const& str) {
			std::string result;
			char char_temp;
			for (auto const& it: str) {
				char_temp = Decode(tolower(it));
				result += (isupper(it)  ? toupper(char_temp) : char_temp);
			}
			m_encryption_index = 0;
			return result;
		}

		//decode an individual character
		private: char Decode(char const& c) {
			auto index = Alphabet::Char_To_Index(c);
			if (-1 == index) { return c;}
			index -= Alphabet::Char_To_Index(m_encryption_key[m_encryption_index]);
			++m_encryption_index;
			if (m_encryption_index >= m_encryption_key.size()) {m_encryption_index =0;}
			return (index < 0) ? Alphabet::At(Alphabet::Size()+index) : Alphabet::At(index);
		}

		//encode a string
		public: std::string Encode(std::string const& str) {
			std::string result;
			char char_temp;
			for (auto const& it: str) {
				char_temp = Encode(tolower(it));
				result += (isupper(it)  ? toupper(char_temp) : char_temp);
			}
			m_encryption_index = 0;
			return result;
		}

		//encode an individual character
		private: char Encode(char const& c) {
			auto index = Alphabet::Char_To_Index(c);
			if (-1 == index) { return c;}
			index += Alphabet::Char_To_Index(m_encryption_key[m_encryption_index]);
			++m_encryption_index;
			if (m_encryption_index >= m_encryption_key.size()) {m_encryption_index = 0;}
			return (index >= Alphabet::Size()) ? Alphabet::At(index-Alphabet::Size()) : Alphabet::At(index);
		}

		//data members
		private: std::string m_encryption_key;
		private: size_t m_encryption_index;
	};


	//NOTE: should be better abstracted
	template <class Alphabet = alphabet::Alphabet<alphabet::English_Alphabet>>
	class Straddling_Checkerboard {

		public: Straddling_Checkerboard(std::string const& high_frequency)
		: m_high_frequency(As_Lowercase(high_frequency))
		{

			//get side numbers
			auto indexes = Get_Indexes_Of_Character(high_frequency, ' ');
			m_alpha_row1.first = std::to_string(indexes[0])[0];
			m_alpha_row2.first = std::to_string(indexes[1])[0];

			//fill with the alphabet
			for (int i = 0; (m_alpha_row1.second.size() + m_alpha_row2.second.size() < 20); ++i) {

				// first row
				if (m_alpha_row1.second.size() < 10) {
					if (i < Alphabet::Size()) {
						if (!Contains_Character(m_high_frequency, Alphabet::At(i))){
							m_alpha_row1.second += Alphabet::At(i);
						}
					}else{
						m_alpha_row1.second += " ";
					}

				// second row
				}else{
					if (i < Alphabet::Size()) {
						if (!Contains_Character(m_high_frequency, Alphabet::At(i))){
							if (m_alpha_row2.second.size() != 2 && m_alpha_row2.second.size() != 9) {
								m_alpha_row2.second += Alphabet::At(i);
							}else{
								--i;
								m_alpha_row2.second += " ";
							}

						}
					}else{
						m_alpha_row2.second += " ";
					}
				}
			}
		}

	public: std::string High_Frequency() {return m_high_frequency;}
	public: std::string Row1() {return m_alpha_row1.second;}
	public: std::string Row2() {return m_alpha_row2.second;}
	public: char Row1_num(){return m_alpha_row1.first;}
	public: char Row2_num(){return m_alpha_row2.first;}

		//data members
  		private:
		std::string m_high_frequency;
		std::pair<char, std::string> m_alpha_row1;
		std::pair<char, std::string> m_alpha_row2;

	};

	//re-naming defaults for convenience
	using Default_Straddling_Checkerboard = Straddling_Checkerboard<>;


	// derived class for a Vic cipher
	template <class Alphabet = alphabet::Alphabet<alphabet::English_Alphabet>, class Board = Default_Straddling_Checkerboard>
	class Vic {

		//constructor
	 	public: Vic(std::string const& encryption_key, std::string const& abc = "et aon ris")
		: m_encryption_key(As_Lowercase(encryption_key))
		, board(abc)
		{}

		//observers
		//decode a string
		public: std::string Encode(std::string const& str) {
			std::string result;
			std::string char_temp;
			for (auto const& it: str) {
				char_temp = Encode(tolower(it));
				result += char_temp;
			}
			return result;
		}

		//encode an individual character
		private: std::string Encode(char const& c) {

			if (c == ' ') {return " ";}
			if (c == '.') {return ".";}

			//check for the character in the first row
			auto row = Get_Indexes_Of_Character(board.High_Frequency(),c);
			if (!row.empty()) {
				return std::to_string(row[0]);
			}

			//check for the character in the second row
			row = Get_Indexes_Of_Character(board.Row1(),c);
			if (!row.empty()) {
				return std::string(std::string("") += board.Row1_num()) +=  std::to_string(row[0]);
			}

			//check for the character in the third row
			row = Get_Indexes_Of_Character(board.Row2(),c);
			if (!row.empty()) {
				return std::string(std::string("") += board.Row2_num()) +=  std::to_string(row[0]);
			}

			return std::to_string(c);

		}

		//observers
		//decode a string
		public: std::string Decode(std::string const& str) {
			std::string result;
			char char_temp;
			std::string part;
			for (auto it = str.begin(); it != str.end(); ++it) {
				if (*it == board.Row1_num()  || *it == board.Row2_num()) {
					part = *it;
					++it;
					part += *it;
					char_temp = Decode_Part(part);
				}else{
					part = *it;
					char_temp = Decode_Part(part);
				}
				result += tolower(char_temp);
			}
			return result;
		}

		//decode an individual char/char set
		private: char Decode_Part(std::string const& c) {

			//check if it is a one letter (first row)
			if (c.size() == 1) {
				if (c[0] == ' ') {return ' ';}
				if (c[0] == '.') {return '.';}
				return board.High_Frequency()[lexical_cast<int>(c[0])];

			}

			//check if it is in the second row
			if (lexical_cast<char>(c[0]) == board.Row1_num()) {
				std::string a = board.Row1();
				int b = lexical_cast<int>(c[1]);
				return a[b];
			}

			//check if it is in the third row
			if (lexical_cast<char>(c[0]) == board.Row2_num()) {
				std::string a = board.Row2();
				int b = lexical_cast<int>(c[1]);
				return a[b];
			}

			return 'X';
		}


		//data members
		private: std::string m_encryption_key;
  		private: Board board;
	};


	// derived class for a Playfair cipher
	template <class Alphabet = alphabet::Alphabet<alphabet::English_Alphabet>>
	class Playfair {

		//constructor
	 	public: Playfair(std::string const& encryption_key)
		{
			std::string m_encryption_key(As_Lowercase(encryption_key));
			m_encryption_key = string_replace_all(m_encryption_key, " ", "");
			m_encryption_key += "abcdefghijklmnopqrstuvwxyz";
			if (First_Char_Comes_Before_Second_Char(m_encryption_key, 'i', 'j')) {
				replace_all(m_encryption_key, 'j', 'i');
			}else{
				replace_all(m_encryption_key, 'i', 'j');
			}
			Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(m_encryption_key);

			std::string r1, r2, r3, r4, r5;
			box.push_back(m_encryption_key.substr(0, 5));
			box.push_back(m_encryption_key.substr(5, 5));
			box.push_back(m_encryption_key.substr(10, 5));
			box.push_back(m_encryption_key.substr(15, 5));
			box.push_back(m_encryption_key.substr(20, 5));
		}

		std::string Encode(std::string const& message) {
			std::string new_message;
			auto parts = Get_Message_Split(message);
			for (auto const& it: parts) {new_message += Encode_Part(it);}

		//std::cout << "-------------" << std::endl;
	  // for(auto const& it: box) {
		//	std::cout << it << std::endl;
	 //  }
	 //  std::cout << "-------------" << std::endl;

			return new_message;
		}

		std::string Decode(std::string const& message) {
			std::string new_message;
			auto parts = Get_Message_Split(message);
			for (auto const& it: parts) {new_message += Decode_Part(it);}

			return new_message;
		}

		std::string Encode_Part(std::string const& part) {
			std::pair<int, int> location1;
			std::pair<int, int> location2;
			Get_Locations(location1, location2, part);
			auto new_part = Get_New_Part(location1, location2, part, 1);

			//std::cout << location1.first << "," << location1.second <<  box[location1.first][location1.second] << " ";
			//std::cout << location2.first << "," << location2.second <<  box[location2.first][location2.second] << " = ";
			//std::cout << new_part << std::endl;

			return new_part;
		}

		std::string Decode_Part(std::string const& part) {
			std::pair<int, int> location1;
			std::pair<int, int> location2;
			Get_Locations(location1, location2, part);
			auto new_part = Get_New_Part(location1, location2, part, -1);

			return new_part;
		}

	private: std::string Get_New_Part(std::pair<int, int> const& location1, std::pair<int, int> const& location2, std::string const& part, int num) {
		std::string new_part;
			if (location1.first == location2.first) {
				//needs bound checked
				if (location1.second+num > box.size()) {
					new_part += box[location1.first][0];
				}else{
					new_part += box[location1.first][location1.second+num];
				}

				if (location2.second+num > box.size()) {
					new_part += box[location2.first][0];
				}else{
					new_part += box[location2.first][location2.second+num];
				}
				std::swap(new_part[0], new_part[1]);
			}
			else if (location1.second == location2.second) {
				//needs bound checked
				if (location1.first+num > box.size()) {
					new_part += box[0][location1.second];
				}else{
					new_part += box[location1.first+num][location1.second];
				}

				if (location2.first+num > box.size()) {
					new_part += box[0][location2.second];
				}else{
					new_part += box[location2.first+num][location2.second];
				}
				std::swap(new_part[0], new_part[1]);
			}else{
				int height_offset = location1.first - location2.first;
				if (height_offset < 0) {height_offset *=  -1;}

				if (location1.first < location2.first) {
					new_part += box[location1.first+height_offset][location1.second];
					new_part += box[location2.first-height_offset][location2.second];
				}else{
					new_part += box[location1.first-height_offset][location1.second];
					new_part += box[location2.first+height_offset][location2.second];
				}
			}

		std::swap(new_part[0], new_part[1]);

		return new_part;
	}
	private: std::vector<std::string> Get_Message_Split(std::string const& message) {
			std::vector<std::string> parts;
			std::string part;
			for (auto it = message.begin(); it != message.end(); ++it) {
				if ((it+1) == message.end()) {
					part = *it;
					part += 'x';
					--it;
				}else{
					char a = *it;
					part = *it;
					++it;

					char b = *it;
					if (a == b) {
						part += 'x';
						--it;
					}else{
						part += *it;
					}
				}
				parts.push_back(part);
			}
			return parts;
	}

   	private: void Get_Locations(std::pair<int, int> & location1, std::pair<int, int> & location2, std::string const& part) {
			for (int i =0; i < box.size(); ++i) {
				for (int j =0; j < box[i].size(); ++j) {
					if (box[i][j] == part[0]) {
						location1.first = i;
						location1.second = j;
					}
					if (box[i][j] == part[1]) {
						location2.first = i;
						location2.second = j;
					}
				}
			}

		return;
   	}
		//data members
		private: std::vector<std::string> box;
	};

	//re-name defaults for convenience
	using English_Caesar = Caesar<>;
	using English_Vigenere = Vigenere<>;
	using English_Vic = Vic<>;
	using English_Playfair = Playfair<>;
}
