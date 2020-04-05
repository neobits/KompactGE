//
//  main.cpp
//  KompactGameEngine
//
//  Created by Angelo Moro on 06/11/2015
//

#pragma once
#include "Core\Init\Init_GLUT.h"
#include "Managers\SceneManager.h"

using namespace Core;
using namespace Initialize;

int main(int argc, char **argv)
{
	std::string title = "Kompact - OpenGL GAME ENGINE";
	WindowInfo window(title, 600, 100, 800, 600, true);
	ContextInfo context(4, 4, true);
	FrameBufferInfo frameBufferInfo(true, true, true, true);
	Init_GLUT::Init(window, context, frameBufferInfo);

	IListener* scene = new Managers::SceneManager();
	Initialize::Init_GLUT::SetListener(scene);

	Init_GLUT::Run();

	delete scene;
	return 0;
}