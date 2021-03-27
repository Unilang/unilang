#pragma once

/*
	 enumerated Structure_State class
*/

#include <string>
enum class Structure_State: char { INVALID
	,EXPECTING_HEADER_INCLUDE
	,EXPECTING_SOURCE_INCLUDE
	,EXPECTING_ANYTHING
	,IN_HEADER_INCLUDE
	,IN_SOURCE_INCLUDE
	,IN_INHERITANCE
	,IN_CPP_ONLY
	,IN_HPP_ONLY
	,IN_FUNCTION_BODY
	,IN_ESCAPE_CHAR
  ,IN_SHELL_COMMAND
  ,IN_DATA_MEMBER
};

/**
 * \brief converts a Structure_State to a string representation.
 * 
 * the function takes any value of Structure_State and returns the string representation of that value.
 * 
 * \param[in] enum_structure_state the Structure_State that is going to be used to get a corresponding string value.
 * 
 * \return a string representation of the Structure_State passed in.
 * 
 * \sa C++11 enum classes
 * \note All values should be accounted for.  The string representation returned should be identical to the type value, except that it will be in lowercase.
 * \warning the Structure_State has a value of INVALID, and the string representation will be "invalid" if it is passed in.
 */std::string to_string(Structure_State const& enum_structure_state);

/**
 * \brief sends a string representation of Structure_State to an output stream
 * 
 * the function overloads the insertion operator for all classes of and deriving from ostream.
 * The string representation is sent into the stream.
 * 
 * \param[in] enum_structure_state the Structure_State that is going to be used to get a corresponding string value.
 * \param[out] out the stream which receives the string representation of Structure_State
 * 
 * \return the output stream is returned with the the string value added.
 * 
 * \sa C++11 enum classes.  overloaded operators.  ostream.  insertion operator
 * \note All values should be accounted for.  The string representation returned should be identical to the type value, except that it will be in lowercase.
 * \warning the Structure_State has a value of INVALID, and the string representation will be "invalid" if it is passed in.
 */std::ostream& operator << (std::ostream &out, Structure_State const& enum_structure_state);

/**
 * \brief converts a string representation of Structure_State to the enumerated class value
 * 
 * the function takes a string representation of the enumerated class and converts it into the enumerated class value if possible
 * 
 * \param[in] std::string_structure_state the Structure_State that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 * 
 * \return the enumerated class value is returned.
 * 
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All string values should be accounted for.  The enum class representation returned should be identical to the string-- if the string is invalid, it will be matched with the INVALID type
 * \warning any string value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Structure_State> Structure_State enum_cast(std::string s){
	Structure_State structure_state{Structure_State::INVALID};
	if (s == "expecting_header_include"){structure_state = Structure_State::EXPECTING_HEADER_INCLUDE;}
	else if(s == "expecting_source_include"){structure_state = Structure_State::EXPECTING_SOURCE_INCLUDE;}
	else if(s == "expecting_anything"){structure_state = Structure_State::EXPECTING_ANYTHING;}
	else if(s == "in_header_include"){structure_state = Structure_State::IN_HEADER_INCLUDE;}
	else if(s == "in_source_include"){structure_state = Structure_State::IN_SOURCE_INCLUDE;}
	else if(s == "in_inheritance"){structure_state = Structure_State::IN_INHERITANCE;}
	else if(s == "in_cpp_only"){structure_state = Structure_State::IN_CPP_ONLY;}
	else if(s == "in_hpp_only"){structure_state = Structure_State::IN_HPP_ONLY;}
	else if(s == "in_function_body"){structure_state = Structure_State::IN_FUNCTION_BODY;}
	else if(s == "in_escape_char"){structure_state = Structure_State::IN_ESCAPE_CHAR;}
		return structure_state;
}

/**
 * \brief converts an int representation of Structure_State to the enumerated class value
 * 
 * the function takes an int representation of the enumerated class and converts it into the enumerated class value if possible
 * 
 * \param[in] intstructure_state the Structure_State that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 * 
 * \return the enumerated class value is returned.
 * 
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All int values in range will be accounted for.  The enum class representation returned should be should match the int as the placement of the enum class deceleration
 * \warning any int value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Structure_State> Structure_State enum_cast(int const& i){
	Structure_State structure_state{Structure_State::INVALID};
	switch(i){
	case 1: return Structure_State::EXPECTING_HEADER_INCLUDE;
	case 2: return Structure_State::EXPECTING_SOURCE_INCLUDE;
	case 3: return Structure_State::EXPECTING_ANYTHING;
	case 4: return Structure_State::IN_HEADER_INCLUDE;
	case 5: return Structure_State::IN_SOURCE_INCLUDE;
	case 6: return Structure_State::IN_INHERITANCE;
	case 7: return Structure_State::IN_CPP_ONLY;
	case 8: return Structure_State::IN_HPP_ONLY;
	case 9: return Structure_State::IN_FUNCTION_BODY;
	case 10: return Structure_State::IN_ESCAPE_CHAR;
	default:;
}		return structure_state;
}

/**
 * \brief converts a char(char must be a number character) representation of Structure_State to the enumerated class value
 * 
 * the function takes a char representation of the enumerated class and converts it into the enumerated class value if possible
 * 
 * \param[in] charstructure_state the Structure_State that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 * 
 * \return the enumerated class value is returned.
 * 
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All char values whose number value is in range will be accounted for.  The enum class representation returned should be should match the char numerical value as the placement of the enum class deceleration
 * \warning any char value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Structure_State> Structure_State enum_cast(char const& i){
	Structure_State structure_state{Structure_State::INVALID};
	switch(i){
	case '1': return Structure_State::EXPECTING_HEADER_INCLUDE;
	case '2': return Structure_State::EXPECTING_SOURCE_INCLUDE;
	case '3': return Structure_State::EXPECTING_ANYTHING;
	case '4': return Structure_State::IN_HEADER_INCLUDE;
	case '5': return Structure_State::IN_SOURCE_INCLUDE;
	case '6': return Structure_State::IN_INHERITANCE;
	case '7': return Structure_State::IN_CPP_ONLY;
	case '8': return Structure_State::IN_HPP_ONLY;
	case '9': return Structure_State::IN_FUNCTION_BODY;
	default:;
}		return structure_state;
}

