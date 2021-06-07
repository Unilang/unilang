#pragma once
#include <string>
#include <map>

//observers
bool Is_A_Control_Character(char const& c);
bool Is_A_Printable_Character(char const& c);
bool Is_A_Whitespace_Character(char const& c);
bool Is_A_Blank_Character(char const& c);
bool Is_A_Graphical_Character(char const& c);
bool Is_A_Puncuation_Character(char const& c);
bool Is_An_Alphanumberic_Character(char const& c);
bool Is_An_Alpha_Character(char const& c);
bool Is_An_Uppercase_Character(char const& c);
bool Is_A_Lowercase_Character(char const& c);
bool Is_A_Numeric_Character(char const& c);
bool Is_A_Hexidecimal_Character(char const& c);

//printers
void Print_Character_N_Times(char const& c, unsigned int const& amount);

//get individuals
//the double/single quote functions exist because I've confused the syntax highlighter.  This is a work-around
//when working in hcp.  There's no reason they can't be functions though.  Everything should be a function.
//we'll add some more generators as necessary
char Get_Double_Quote();
char Get_Single_Quote();
char Get_Forward_Slash();
char Get_Back_Slash();

std::vector<char> Get_Lowercase_Letters();
std::vector<char> Get_Uppercase_Letters();
std::vector<char> Get_All_Cased_Letters();

char Get_Next_Capital_Letter(char c);

//get unicode characters (just easier)
wchar_t Zero_Width_Space();
wchar_t Zero_Width_Non_Breaking_Space();
wchar_t Zero_Width_Joiner();
wchar_t Zero_Width_Non_Joiner();

//converters
std::string As_4_Bit_Binary(const char c);
std::string Hex_To_4_Bit_Binary_Segments(std::string const& s);
std::string As_Binary(const char c);
char From_Binary(std::string const& str);

int as_number(char const& c);

std::map<std::string,double> Standard_Char_Likelyhood_In_Words();


//character for bars
//█
//██████████████

//■
//■■■■■■■■■■■■
