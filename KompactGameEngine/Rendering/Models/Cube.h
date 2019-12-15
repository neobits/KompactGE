#pragma once
#include "Model.h"
#include<time.h>
#include<stdarg.h>
using namespace glm;

namespace Rendering 
{
	namespace Models 
	{
		class Cube : public Model
		{
		public:
			Cube();
			~Cube();

			void Create();
			//void Draw(const mat4& projection_matrix, const mat4& view_matrix) override final;
			void Drawing(const mat4& projectionMatrix, const mat4& viewMatrix);
			virtual void Update() override final;

		private:
			vec3 rotation;
			vec3 rotationSpeed;
			time_t timer;
		};
	}
}