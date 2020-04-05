//
//  SceneManager.cpp
//  KompactGameEngine
//
//  Created by Angelo Moro on 06/11/2015
//

#include "SceneManager.h"
using namespace Managers;

SceneManager::SceneManager()
{
	glEnable(GL_DEPTH_TEST);

	shaderManager = new ShaderManager();
	shaderManager->CreateProgram("colorShader",
		"Shaders\\VertexShader.glsl",
		"Shaders\\FragmentShader.glsl");
	modelManager = new ModelManager();
}

SceneManager::~SceneManager()
{
	delete shaderManager;
	delete modelManager;
}

void SceneManager::notifyBeginFrame()
{
	//nothing here for the moment
	modelManager->Update();
}

void SceneManager::notifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	modelManager->Draw();
}

void SceneManager::notifyEndFrame()
{
	//nothing here for the moment
}

void SceneManager::notifyReshape(int width, int height,
								 int prev_w, int prev_h)
{
	//nothing here for the moment 

}