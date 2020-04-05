//
//  Model.h
//  KompactGameEngine
//
//  Created by Angelo Moro on 06/11/2015
//

#pragma once
#include <vector>
#include "../IGameObject.h"

namespace Rendering 
{
	namespace Models 
	{
		class Model : public IGameObject
		{
		public:
			Model();
			virtual ~Model();
			// Interface Methods : C++11 override to ensure interface match
			virtual void Draw() override;
			virtual void Update() override;
			virtual void SetProgram(GLuint shaderName) override;
			virtual void Destroy() override;

			virtual GLuint GetVAO() const override;
			virtual const std::vector<GLuint>& GetVBOs() const override;
		protected:
			GLuint VAO;
			GLuint program;
			std::vector<GLuint> VBOs;
		};
	}
}
