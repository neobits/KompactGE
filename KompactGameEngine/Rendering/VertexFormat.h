//
//  VertexFormat.h
//  KompactGameEngine
//
//  Created by Angelo Moro on 06/11/2015
//

#ifndef VertexFormat_H_
#define VertexFormat_H_

#include "glm\glm.hpp"
// Using glm to scope vectors
using namespace glm;

namespace Rendering
{
	struct VertexFormat
	{
		vec3 position;
		vec4 color;

		VertexFormat(const vec3& position, const vec4& color)
		{
			this->position = position;
			this->color = color;
		}
	};
}
#endif
