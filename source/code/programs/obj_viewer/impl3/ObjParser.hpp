#ifndef _OBJ_PARSER_HPP
#define _OBJ_PARSER_HPP

#include "Model.hpp"
#include "SmartPtr.hpp"

#include <string>
#include <vector>

class ObjParser {
	public:
		ObjParser();
				
		ModelPtr parseObj(const std::string& fileName);
		std::vector<MaterialPtr> parseMtl(const std::string& fileName);
		
	private:
		/*
		 * OBJ parsing methods
		 */
		Point3f parseVertex(std::stringstream& sstream);
		Point3f parseNormal(std::stringstream& sstream);
		Point2f parseTexCoord(std::stringstream& sstream);
		FacePtr parseFace(std::stringstream& sstream, const MaterialPtr& material);
		std::string parseName(std::stringstream& sstream);
		std::string parseFileName(const std::string& prefix, const std::string& line);

		/*
		 * Utility methods
		 */
		MaterialPtr findMaterial(const std::vector<MaterialPtr>& materials, const std::string& name);
		std::string filePath(const std::string& fileName);
		
		/*
		 * String utilities
		 */
		std::vector<std::string> split(const std::string& str, char delim);
		std::string trim_right(const std::string& str, const std::string& delim = " \f\n\r\t\v");
		std::string trim_left(const std::string& str, const std::string& delim = " \f\n\r\t\v");
		std::string trim(const std::string& str, const std::string& delim = " \f\n\r\t\v");
		unsigned int stou(const std::string &str, size_t* idx = 0, int base = 10);
};

#endif
