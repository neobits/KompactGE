#include "ModelManager.h"
using namespace Managers;
using namespace Rendering;

ModelManager::ModelManager()
{
	// Creating and adding a single triangle!
	Models::Triangle* triangle = new Models::Triangle();
	triangle->SetProgram(ShaderManager::GetShader("colorShader"));
	triangle->Create();
	GameModelList["triangle"] = triangle;

	Models::Quad* quad = new Models::Quad();
	quad->SetProgram(ShaderManager::GetShader("colorShader"));
	quad->Create();
	GameModelList["quad"] = quad;
}

ModelManager::~ModelManager()
{
	// auto = map iterator
	for (auto model : GameModelList) {
		delete model.second;
	}
	GameModelList.clear();
}

void ModelManager::DeleteModel(const std::string& gameModelName)
{
	IGameObject* model = GameModelList[gameModelName];
	model->Destroy();
	GameModelList.erase(gameModelName);
}

void ModelManager::Draw()
{
	//auto -it's a map iterator
	for (auto model : GameModelList) {
		model.second->Draw();
	}
}

void ModelManager::Update()
{
	//auto -it's a map iterator
	for (auto model : GameModelList) {
		model.second->Update();
	}
}

const IGameObject& ModelManager::GetModel(const std::string& gameModelName) const
{
	return (*GameModelList.at(gameModelName));
}