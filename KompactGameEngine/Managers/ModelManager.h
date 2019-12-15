#pragma once
#include <map>
#include "ShaderManager.h"
#include "../Rendering/IGameObject.h"
#include "../Rendering/Models/Triangle.h"
#include "../Rendering/Models/Quad.h"
using namespace Rendering;

namespace Managers
{
	class ModelManager
	{
	public:
		ModelManager();
		~ModelManager();

		void Draw();
		void Update();
		void DeleteModel(const std::string& gameModelName);
		const IGameObject& GetModel(const std::string& gameModelName) const;
	private:
		// TODO: for a few objects, map is fine. Othewise consider using <vector>
		std::map<std::string, IGameObject*> GameModelList;
	};
}