#pragma once
#include "ShaderManager.h"
#include "ModelManager.h"
#include "../Core/Init/IListener.h"

namespace Managers
{
	class SceneManager : public Core::IListener 
	{
	public:
		SceneManager();
		~SceneManager();

		virtual void notifyBeginFrame();
		virtual void notifyDisplayFrame();
		virtual void notifyEndFrame();
		virtual void notifyReshape(int width, int height, int prev_w, int prev_h);
	private:
		Managers::ShaderManager* shaderManager;
		Managers::ModelManager* modelManager;
	};
}