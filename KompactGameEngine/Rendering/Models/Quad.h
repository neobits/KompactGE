//
//  Quad.h
//  KompactGameEngine
//
//  Created by Angelo Moro on 06/11/2015
//

#pragma once
#include "Model.h"

namespace Rendering
{
	namespace Models
	{
		class Quad : public Models::Model
		{
		public:
			Quad();
			~Quad();

			void Create();
			virtual void Draw() override final;
			virtual void Update() override final;
		};
	}
}