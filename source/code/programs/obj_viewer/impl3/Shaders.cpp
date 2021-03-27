#include "Shaders.hpp"

#include <GL/gl.h>

#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>

Shaders::Shaders(std::string vsFile, std::string fsFile) {
	std::string vsSrc = load(vsFile);
	std::string fsSrc = load(fsFile);
	
	unsigned int vsId = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fsId = glCreateShader(GL_FRAGMENT_SHADER);
	
	/*
	 * Compile vertex shader
	 */
	int isCompiled = GL_FALSE;
	
	const char* vsSrcPtr = vsSrc.c_str();
	glShaderSource(vsId, 1, &vsSrcPtr, NULL);
	glCompileShader(vsId);
	glGetShaderiv(vsId, GL_COMPILE_STATUS, &isCompiled);
	
	if (GL_FALSE == isCompiled)
		throw std::runtime_error("Error compiling shader " + vsFile);

	/*
	 * Compile fragment shader
	 */
	isCompiled = GL_FALSE;
	 
	const char* fsSrcPtr = fsSrc.c_str();
	glShaderSource(fsId, 1, &fsSrcPtr, NULL);
	glCompileShader(fsId);
	
	glGetShaderiv(fsId, GL_COMPILE_STATUS, &isCompiled);
	
	if (GL_FALSE == isCompiled)
		throw std::runtime_error("Error compiling shader " + fsFile);
	
	/*
	 * Link program
	 */
	int isLinked = GL_FALSE; 
	 
	prog_ = glCreateProgram();	 
	 
	glAttachShader(prog_, vsId);
	glAttachShader(prog_, fsId);
	glLinkProgram(prog_);
	glGetProgramiv(prog_, GL_LINK_STATUS, &isLinked);
	
	if (GL_FALSE == isLinked)
		throw std::runtime_error("Error linking shader program");
	
	glDeleteShader(vsId);
	glDeleteShader(fsId);
}

void Shaders::setSamplerName(std::string name) {
	samplerName_ = name;
}

bool Shaders::hasSampler() {
	return (samplerName_.size() > 0);
}

unsigned int Shaders::samplerId() {
	if (0 == samplerName_.size())
		throw std::runtime_error("Unable to get sampler ID: no sampler specified");
	
	return glGetUniformLocation(prog_, samplerName_.c_str());
}

void Shaders::use() {
	glUseProgram(prog_);
}

std::string Shaders::load(std::string filePath) {
	std::string src;
	
	std::ifstream file(filePath);
	
	if (!file.is_open())
		throw std::runtime_error("Unable to open shader file " + filePath);
		
	std::string line;
	
	while(std::getline(file, line)) {
		src += line + "\n";
	}
	
	return src;
}
