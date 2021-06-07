#pragma once
#include <string>

    std::string& CapitalizeFirstChar(std::string & s);
    std::string& LowercaseFirstChar(std::string & s);
    
    std::string& CapitalizeCharIndex(std::string & s, size_t const& index);

    std::string& Uppercase(std::string &s);
    std::string As_Uppercase(std::string s);
    
    std::string& Lowercase(std::string &s);
    std::string As_Lowercase(std::string s);
    
    
    std::string As_Camel_Case(std::string s);
    std::string As_Lower_Camel_Case(std::string s);
    std::string As_Capitalized(std::string s);
    std::string As_Capital_And_Pushed_Together(std::string s);                   //SomethingLikeThis
    std::string Capitalize_Each_With_Space_In_Between(std::string s);            //Something Like This
    std::string Make_Capital_And_Underscored_In_User_Type_Format(std::string s); //Something_Like_This
    std::string As_All_Capital_Letters_With_Spaces_As_Underscores(std::string s); //SOMETHING_LIKE_THIS
    std::string As_All_Lowercase_Letters_With_Spaces_As_Underscores(std::string s);//something_like_this
    std::string As_All_Lowercase_Letters_With_Underscores_As_Spaces(std::string s);//something like this
    std::string As_Capital_And_Pushed_Together_Preserve_Underscores_With_Lowercase_After(std::string s); //something like_this -> SomethingLike_this
    //TODO: look at the sublime plugin for different case names
    //Title Case
    //Upper Case
    //Lower Case
    //Swap Case
    //snake_case
    //camelCase
    //PascalCase
    //dot.case
    //dash-case
    //seperate words
    //seperate/with/slash
    //Toggle Case
    
    
	//CLASS NAME
	//Class Name
	//class name
	//class Name

	//CLASS_NAME
	//Class_Name
	//class_name
	//class_Name

	//CLASS-NAME
	//Class-Name
	//class-name
	//class-Name

	//CLASSNAME
	//ClassName
	//classname
	//className
