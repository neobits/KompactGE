//
//  Init_GLUT.cpp
//  KompactGameEngine
//
//  Created by Angelo Moro on 06/11/2015
//

#include "Init_GLUT.h"

using namespace Core::Initialize;

// Expose variables
Core::IListener* Init_GLUT::listener = NULL;
Core::WindowInfo Init_GLUT::windowInformation;

void Init_GLUT::Init(const Core::WindowInfo& windowInfo,
					 const Core::ContextInfo& context,
					 const Core::FrameBufferInfo& frameBuffer)
{
	int dummy_argc = 1;
	char *dummy_argv[] = { "dummy", NULL };
	glutInit(&dummy_argc, dummy_argv);

	if (context.isCore) {
		glutInitContextVersion(context.majorVersion, context.minorVersion);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else {
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	windowInformation = windowInfo;

	glutInitDisplayMode(frameBuffer.flags);
	glutInitWindowPosition(windowInfo.position_x, windowInfo.position_y);
	glutInitWindowSize(windowInfo.width, windowInfo.height);
	glutCreateWindow(windowInfo.name.c_str());
	std::cout << "GLUT: Initialized" << std::endl;
	glEnable(GL_DEBUG_OUTPUT);
	// Rendering callbacks
	glutIdleFunc(IdleCallback);
	glutCloseFunc(CloseCallback);
	glutDisplayFunc(DisplayCallback);
	glutReshapeFunc(ReshapeCallback);

	Initialize::Init_GLEW::Init();
	if (GL_DEBUG_OUTPUT) {
		std::cout << "Debug Output supported" << std::endl;
	}
	glDebugMessageCallback(DebugOutput::PrintCallback, NULL);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);

	// Cleanup
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	PrintOpenGLInfo(windowInfo, context);
}

void Init_GLUT::Run()
{
	std::cout << "GLUT:\t Start running." << std::endl;
	glutMainLoop();
}

void Init_GLUT::Close()
{
	std::cout << "GLUT:\t Closed." << std::endl;
	glutLeaveMainLoop();
}

//////////////////// CALLBACKS

void Init_GLUT::IdleCallback()
{
	glutPostRedisplay();
}

void Init_GLUT::DisplayCallback()
{
	if (listener) {
		listener->notifyBeginFrame();
		listener->notifyDisplayFrame();
		glutSwapBuffers();
		listener->notifyEndFrame();
	}
}

void Init_GLUT::ReshapeCallback(int width, int height) 
{
	if (windowInformation.isReshapable) {
		if (listener) {
			listener->notifyReshape(width, height,
				windowInformation.width, windowInformation.height);
		}
		windowInformation.width = width;
		windowInformation.height = height;
	}
}

void Init_GLUT::CloseCallback() { Close(); }

void Init_GLUT::EnterFullscreen() { glutFullScreen(); }

void Init_GLUT::ExitFullscreen() { glutLeaveFullScreen(); }

void Init_GLUT::PrintOpenGLInfo(const Core::WindowInfo& windowInfo, 
								const Core::ContextInfo& context)
{
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "**************************************" << std::endl;
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGL version: " << version << std::endl;
}

void Init_GLUT::SetListener(Core::IListener *& iListener)
{
	listener = iListener;
}
