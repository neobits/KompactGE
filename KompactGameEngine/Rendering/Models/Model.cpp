//
//  Model.cpp
//  KompactGameEngine
//
//  Created by Angelo Moro on 06/11/2015
//

#include "Model.h"
using namespace Rendering;
using namespace Models;

Model::Model(){}

Model::~Model()
{
	Destroy();
}

void Model::Draw() {}
void Model::Update() {}
void Model::SetProgram(GLuint program) { this->program = program; }
GLuint Model::GetVAO() const { return VAO; }
const std::vector<GLuint>& Model::GetVBOs() const { return VBOs; }

void Model::Destroy()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers((int)VBOs.size(), &VBOs[0]);
	VBOs.clear();
}