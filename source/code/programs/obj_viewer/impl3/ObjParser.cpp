#include "ObjParser.hpp"
#include "SmartPtr.hpp"

#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>

ObjParser::ObjParser() {
}

ModelPtr ObjParser::parseObj(const std::string& fileName) {
	std::string path = filePath(fileName);
	
	ModelPtr model(new Model());
	
	std::ifstream file;
	file.open(fileName, std::ifstream::in);
	
	if (!file.is_open())
		throw std::runtime_error("Unable to open OBJ file " + fileName);

	std::vector<MaterialPtr> materials;
	MaterialPtr material;
	
	GroupPtr group;
	unsigned int groupId = 0;
	
	std::string line;
	
	while(std::getline(file, line)) {
		std::stringstream sstream(line);
		
		std::string prefix;
		sstream >> prefix;
		
		if (prefix.size() > 0) {
			if ("mtllib" == prefix) {
				std::string fileName = parseFileName(prefix, line);
				std::vector<MaterialPtr> mats = parseMtl(path + fileName);
				materials.insert(materials.begin(), mats.begin(), mats.end());
			} else if ("v" == prefix) {
				model->addVertex(parseVertex(sstream));
			} else if ("vn" == prefix) {
				model->addNormal(parseNormal(sstream));
			} else if ("vt" == prefix) {
				model->addTexCoord(parseTexCoord(sstream));
			} else if ("usemtl" == prefix) {
				if (!group.isNull())
					model->addGroup(group);

				group = GroupPtr(new Group(groupId++, findMaterial(materials, parseName(sstream))));
			} else if ("f" == prefix) {
				group->addFace(parseFace(sstream, material));
			} else {
				continue;
			}
		}
	}
	
	if (!group.isNull())
		model->addGroup(group);
	
	file.close();
	
	return model;
}

std::vector<MaterialPtr> ObjParser::parseMtl(const std::string& fileName) {
	std::string path = filePath(fileName);
	
	std::vector<MaterialPtr> materials;
	
	std::ifstream file;	
	file.open(fileName, std::ifstream::in);
	
	if (!file.is_open())
		throw std::runtime_error("Unable to open material library " + fileName);
	
	MaterialPtr material;
	std::string line;
	
	while(std::getline(file, line)) {
		std::stringstream sstream(line);
		
		std::string prefix;
		sstream >> prefix;
		
		float v1, v2, v3;
		
		if (prefix.size() > 0) {
			if ("newmtl" == prefix) {
				if (!material.isNull())
					materials.push_back(material);
				
				material = MaterialPtr(new Material(parseName(sstream)));
			} else if ("Ka" == prefix) {
				sstream >> v1 >> v2 >> v3;
				material->setKa(v1, v2, v3);
			} else if ("Ks" == prefix) {
				sstream >> v1 >> v2 >> v3;
				material->setKs(v1, v2, v3);
			} else if ("Kd" == prefix) {
				sstream >> v1 >> v2 >> v3;
				material->setKd(v1, v2, v3);
			} else if ("Ke" == prefix) {
				sstream >> v1 >> v2 >> v3;
				material->setKe(v1, v2, v3);
			} else if ("map_Kd" == prefix) {
				std::string fileName = parseFileName(prefix, line);
				material->setTexture(TexturePtr(new Texture(path + fileName)));
			} else {
				continue;
			}
		}
	}
		
	if (!material.isNull())
		materials.push_back(material);
	
	file.close();
	
	return materials;
}

Point3f ObjParser::parseVertex(std::stringstream& sstream) {
	float x, y, z;
	
	sstream >> x >> y >> z;
	
	Point3f p;
	p(0) = x;
	p(1) = y;
	p(2) = z;
	return p;
}

Point3f ObjParser::parseNormal(std::stringstream& sstream) {
	float x, y, z;
	
	sstream >> x >> y >> z;
	
	Point3f p;
	p(0) = x;
	p(1) = y;
	p(2) = z;
	return p;
}

Point2f ObjParser::parseTexCoord(std::stringstream& sstream) {
	float x, y;
	
	sstream >> x >> y;
	
	Point2f p;
	p(0) = x;
	p(1) = 1.0f - y;
	return p;
}

FacePtr ObjParser::parseFace(std::stringstream& sstream, const MaterialPtr& material) {
	FacePtr face;
	
	if (!material.isNull())
		face = FacePtr(new Face(material));
	else
		face = FacePtr(new Face());
	
	std::string indexGroup;
	
	while (sstream >> indexGroup) {
		std::vector<std::string> indices = split(indexGroup, '/');
		
		if (1 == indices.size()) {
			face->addVertexIndex(stou(indices[0]));
		} else if (2 == indices.size()) {
			face->addVertexIndex(stou(indices[0]));
			face->addTexCoordIndex(stou(indices[1]));
		} else if (3 == indices.size()) {
			face->addVertexIndex(stou(indices[0]));
			face->addNormalIndex(stou(indices[2]));
			
			if ("" != indices[1])
				face->addTexCoordIndex(stou(indices[1]));
		} else {
			throw std::runtime_error("Invalid face definition in OBJ file");
		}
	}
	
	return face;
}

std::string ObjParser::parseName(std::stringstream& sstream) {
	std::string name, word;
	
	while (sstream >> word) {
		if (0 == name.size())
			name += word;
		else
			name += " " + word;
	}
	
	return name;
}

std::string ObjParser::parseFileName(const std::string& prefix, const std::string& line) {
	return trim(line.substr(line.find(prefix) + prefix.size() + 1));
}

MaterialPtr ObjParser::findMaterial(const std::vector<MaterialPtr>& materials, const std::string& name) {
	for (unsigned int i = 0; i < materials.size(); i++) {
		if (materials[i]->name() == name)
			return materials[i];
	}
	
	throw std::runtime_error("Unable to find referenced material " + name);
}

std::string ObjParser::filePath(const std::string& fileName) {
	size_t pos = fileName.find_last_of("/");
	
	if (std::string::npos == pos) {
		return "";
	} else
		return fileName.substr(0, pos) + "/";
}

std::vector<std::string> ObjParser::split(const std::string& str, char delim) {
	std::vector<std::string> items;
	std::stringstream sstream(str);
	std::string item;
	
	while (std::getline(sstream, item, delim))
		items.push_back(item);
		
	return items;
}

unsigned int ObjParser::stou(const std::string &str, size_t* idx, int base) {
	unsigned long result = std::stoul(str, idx, base);
	
	if (result > std::numeric_limits<unsigned>::max()) {
		throw std::out_of_range("stou");
	}
	
	return result;
}

std::string ObjParser::trim_right(const std::string& str, const std::string& delim) {
  return str.substr(0, str.find_last_not_of(delim) + 1);
}

std::string ObjParser::trim_left(const std::string& str, const std::string& delim) {
  return str.substr(str.find_first_not_of(delim));
}

std::string ObjParser::trim(const std::string& str, const std::string& delim) {
  return trim_left(trim_right(str, delim), delim);
}
