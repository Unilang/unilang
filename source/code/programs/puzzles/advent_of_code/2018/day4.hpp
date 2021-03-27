#pragma once
#include "utilities.hpp"
#include "systems.hpp"
#include "encryption.hpp"

class Day4{






public: static void Go();

private: static std::string As_Shifted(std::string name, int shift_amount);

private: static void CycleThroughLowercase(char & ch, int skipcount);

private: static Encryption Parse(std::string str);



private: static void Decide_Valids_And_Invalids(std::vector<Encryption> const& lines,std::vector<Encryption> & valid, std::vector<Encryption> & invalid);


private: static bool Valid(Encryption const& line);

};