//
//  Triangle.h
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
		class Triangle : public Model
		{
		public:
			Triangle();
			~Triangle();

			void Create();
			virtual void Update() override final;
			virtual void Draw() override final;
		};
	}
}