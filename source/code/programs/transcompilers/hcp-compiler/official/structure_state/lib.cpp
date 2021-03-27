#include "lib.hpp"

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
 */std::string to_string(Structure_State const& enum_structure_state){
	std::string str{"INVALID"};
	switch (enum_structure_state){
		case Structure_State::EXPECTING_HEADER_INCLUDE: str = "expecting_header_include"; break;
		case Structure_State::EXPECTING_SOURCE_INCLUDE: str = "expecting_source_include"; break;
		case Structure_State::EXPECTING_ANYTHING: str = "expecting_anything"; break;
		case Structure_State::IN_HEADER_INCLUDE: str = "in_header_include"; break;
		case Structure_State::IN_SOURCE_INCLUDE: str = "in_source_include"; break;
		case Structure_State::IN_INHERITANCE: str = "in_inheritance"; break;
		case Structure_State::IN_CPP_ONLY: str = "in_cpp_only"; break;
		case Structure_State::IN_HPP_ONLY: str = "in_hpp_only"; break;
		case Structure_State::IN_FUNCTION_BODY: str = "in_function_body"; break;
		case Structure_State::IN_ESCAPE_CHAR: str = "in_escape_char"; break;
		default:;
	}
	return str;
}

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
 */std::ostream& operator << (std::ostream &out, Structure_State const& enum_structure_state){
	out << to_string(enum_structure_state);
	return out;
}
