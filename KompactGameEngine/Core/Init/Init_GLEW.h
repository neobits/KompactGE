//
//  Init_GLEW.h
//  KompactGameEngine
//
//  Created by Angelo Moro on 06/11/2015
//

#pragma once
#include <iostream>
#include "../../Dependencies/glew/glew.h"
#include "../../Dependencies/freeglut/freeglut.h"

namespace Core
{
	namespace Initialize 
	{
		class Init_GLEW
		{
		public:
			static void Init();
		};
	}
}