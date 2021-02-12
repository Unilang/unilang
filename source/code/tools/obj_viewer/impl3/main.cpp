#include "ObjParser.hpp"
#include "Shaders.hpp"
#include "Viewer.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

//https://github.com/empyreanx/obj-viewer
int main(int argc, char** argv) {
	bool useParams = false;
	std::string flag, fileName;
	
	if (2 == argc) {
		fileName = std::string(argv[1]);
	} else if (3 == argc) {
		flag = std::string(argv[1]);
		fileName = std::string(argv[2]);
		
		if ("-m" == flag) {
			useParams = true;
		} else {
			std::cerr << "Flag " << flag << " not recognized" << std::endl;
			return -1;
		}
	} else {
		std::cout << "Usage: [-m] obj-viewer FILE" << std::endl;
		return -1;
	}

	ModelPtr model;
	ObjParser parser;
	
	std::cout << "Parsing model " << fileName << std::endl;
	
	try {	
		model = parser.parseObj(fileName);
	} catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	std::cout << "here" << std::endl;
	
	model->setUseParams(useParams);
	
	//compute centroid and center model
	model->centroid();
	model->center();
	
	//setup viewer
	Viewer viewer("Model Viewer", 1024, 768);
			
	viewer.setModel(model);
	viewer.initGlut(argc, argv);
	viewer.initGl();
	
	//load shaders
	std::string prefix = "/home/luxe/Desktop/obj-viewer/shaders";
	std::string vsFile = prefix + "/lambertian.vs";
	std::string fsFile = prefix + "/lambertian.fs";
	
	//ShadersPtr shaders(new Shaders(vsFile, fsFile));
	//shaders->setSamplerName("texMap");
	
	//prepare for rendering
	model->loadTextures();
	model->compileLists();
	//model->setShaders(shaders);
	
	std::cout << "here3" << std::endl;
	Viewer::setInstance(&viewer);
	std::cout << "here4" << std::endl;
	viewer.start();
	std::cout << "here2" << std::endl;
	
	return 0;
}
