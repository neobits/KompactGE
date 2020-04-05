//
//  Init_GLUT.h
//  KompactGameEngine
//
//  Created by Angelo Moro on 06/11/2015
//

#pragma once
#include "ContextInfo.h"
#include "FrameBufferInfo.h"
#include "WindowInfoh.h"
#include "IListener.h"
#include <iostream>
#include "Init_GLEW.h"
#include "DebugOutput.h"

namespace Core
{
	namespace Initialize
	{
		class Init_GLUT {
		public:
			static void Init(const Core::WindowInfo& window,
							 const Core::ContextInfo& context,
							 const Core::FrameBufferInfo& frameBuffer);

			static void Run();
			static void Close();

			void EnterFullscreen();
			void ExitFullscreen();
			
			static void PrintOpenGLInfo(const WindowInfo& windowInfo,
										const ContextInfo& context);
			
			static void SetListener(Core::IListener*& iListener);

		private:
			static void IdleCallback(void);
			static void DisplayCallback(void);
			static void ReshapeCallback(int width, int height);
			static void CloseCallback();
			static Core::IListener* listener;
			static Core::WindowInfo windowInformation;
		};
	}
}
