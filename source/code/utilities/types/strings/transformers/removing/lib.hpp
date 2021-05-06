#pragma once
#include <string>

//REMOVING
std::string& Remove_All_Instances_Of_Char(std::string & str, char const& c);
std::string& Remove_First_Instance_Of_Char(std::string & str, char const& c);

std::string Remove_And_Get_First_Char(std::string & str);

//remove certain chars
std::string& Remove_Spaces(std::string & str);
std::string& Remove_Commas(std::string & str);
std::string& Remove_Periods(std::string & str);
std::string& Remove_Question_Marks(std::string & str);
std::string& Remove_Dashes(std::string & str);
std::string& Remove_Double_Quotes(std::string & str);
std::string& Remove_Newlines(std::string & str);

std::string As_Removed_Dashes(std::string const& str);

std::string As_Chars_Removed(std::string const& str, std::string const& chars);
std::string As_NonAlphas_Removed(std::string const& str);
std::string& Remove_All_Beginning_Characters_That_Match_Any_Of_The_Following_Characters(std::string & str, std::string const& chars);
std::string& Remove_Match_Found_At_Beginning_Or_End(std::string & str, std::string const& match);
std::string& Remove_Match_If_It_Is_Found_At_Beginning(std::string & str, std::string const& match);
std::string& Remove_Match_If_It_Is_Found_At_End(std::string & str, std::string const& match);
std::string& Remove_Match_Found_At_Beginning(std::string & str, std::string const& match);
std::string& Remove_Match_Found_At_End(std::string & str, std::string const& match);
std::string& Remove_Match_If_It_Is_Found_At_Beginning_Or_End(std::string & str, std::string const& match);
std::string& Remove_Matching_Beginning_Part_Of_String(std::string & str, std::string const& match);
std::string As_Beginning_Matching_Part_Of_String_Removed(std::string const& str, std::string const& match);

//keeping certain characters
std::string& Keep_Only_Numeric_Chars(std::string & str);

//changing front
std::string& Remove_First_Char(std::string &s);
std::string As_First_Char_Removed(std::string const& s);
std::string& Remove_All_Chars_From_Front_Until_Char_Is_Seen(std::string & str, char const& c);
/**/ std::string As_All_Chars_Removed_From_Front_Until_Char_Is_Seen(std::string str, char const& c);
std::string& Remove_All_Chars_From_Front_Until_Char_Is_Seen_A_Number_Of_Times(std::string & str, char const& c, unsigned int number_of_times);
/**/ std::string As_All_Chars_Removed_From_Front_Until_Char_Is_Seen_A_Number_Of_Times(std::string str, char const& c, unsigned int number_of_times);
std::string& Remove_First_N_Chars(std::string & str, unsigned int const& number_of_times);
std::string As_First_N_Chars_Removed(std::string str, unsigned int const& number_of_times);
std::string& Remove_N_Chars_From_Front_And_Back(std::string & str, unsigned int const& number_of_times);
std::string As_N_Chars_Removed_From_Front_And_Back(std::string str, unsigned int const& number_of_times);

//changing back
std::string& Remove_Last_Char(std::string &s);
std::string As_Last_Char_Removed(std::string const& s);
std::string& Remove_All_Chars_From_Back_Until_Char_Is_Seen(std::string & str, char const& c);
/**/ std::string As_All_Chars_Removed_From_Back_Until_Char_Is_Seen(std::string str, char const& c);
std::string& Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(std::string & str, char const& c, unsigned int number_of_times);
/**/ std::string As_All_Chars_Removed_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(std::string str, char const& c, unsigned int number_of_times);
std::string& Remove_Last_N_Chars(std::string & str, unsigned int const& number_of_times);
std::string As_Last_N_Chars_Removed(std::string str, unsigned int const& number_of_times);
std::string As_First_Word_Of_String_Moved_To_The_End(std::string str);

//keeping back
std::string& Keep_End_Chars_Until_Char_Is_Found(std::string & str, char const& c);

//changing both
std::string& Remove_First_And_Last_Char(std::string & str);

//changing the end of a string (assuming it's a filename)
std::string& Remove_Suffix(std::string &s);
std::string As_Removed_Suffix(std::string s);

std::string& Keep_Matching_Beginning_Part_Of_String(std::string & str, std::string const& match);
std::string As_Beginning_Matching_Part_Of_String_Kept(std::string const& str, std::string const& match);
std::string& Keep_Only_First_N_Characters(std::string & str, unsigned int const& count);

std::string& Empty_String_If_It_Only_Contains_Whitespace(std::string & str);
std::string As_Empty_String_If_It_Only_Contains_Whitespace(std::string str);


std::string& Remove_Everything_Before_Found_Instance(std::string & str, std::string const& instance);
std::string& Remove_Everything_After_Found_Instance(std::string & str, std::string const& instance);