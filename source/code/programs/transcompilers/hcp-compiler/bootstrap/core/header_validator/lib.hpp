#pragma once
#include <iostream>
#include <string>

class Header_Validator {




public:

static void Validate(std::string const& class_name, std::wstring const& include_name_with_possible_quotes, bool const& is_header);


friend std::ostream &operator<<( std::ostream & out, Header_Validator const& self){
	return out;
}


private:
};