#ifndef _SHADERS_HPP
#define _SHADERS_HPP

#include "SmartPtr.hpp"

#include <string>

class Shaders {
	public:
		Shaders(std::string vsFile, std::string fsFile);
		
		void setSamplerName(std::string name);
		bool hasSampler();
		unsigned int samplerId();
		
		void use();
		
	private:
		unsigned int prog_;
		
		std::string samplerName_;
		
		std::string load(std::string file);
};

typedef SmartPtr<Shaders> ShadersPtr;

#endif
