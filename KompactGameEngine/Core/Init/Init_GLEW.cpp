//
//  Init_GLEW.cpp
//  KompactGameEngine
//
//  Created by Angelo Moro on 06/11/2015
//

#include "Init_GLEW.h"
using namespace Core;
using namespace Core::Initialize;

void Init_GLEW::Init() 
{
	glewExperimental = true;
	if (glewInit() == GLEW_OK) {
		std::cout << "GLEW: Initialized" << std::endl;
	}
	if (glewIsSupported("GL_VERSION_4_5")) {
		std::cout << "GLEW GL_VERSION is 4.5\n";
	}
	else if (glewIsSupported("GL_VERSION_4_4")) {
		std::cout << "GLEW GL_VERSION is 4.4\n";
	}
	else if (glewIsSupported("GL_VERSION_4_3")) {
		std::cout << "GLEW GL_VERSION is 4.3\n";
	}
	else {
		std::cout << "GLEW GL_VERSION < 4.3, too old :(\n";
	}
}