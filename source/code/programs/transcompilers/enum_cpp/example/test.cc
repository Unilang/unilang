#include <iostream>
#include <string>
#include "prettyprint.hpp"
#include "code/programs/transcompilers/enum_cpp/example/test_enum.hpp"

int main(int argc, char** argv){

    //This example will demonstrate all of the generated utility functions you get when using enum_cpp
    
    
	Test_Enum e = Test_Enum::FOO;
	std::cout << "as_string(e): " << as_string(e) << std::endl;
    std::cout << "Test_Enum_all_strings(): " << Test_Enum_all_strings() << std::endl;
}