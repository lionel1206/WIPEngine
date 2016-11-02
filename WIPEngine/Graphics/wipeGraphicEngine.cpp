#include "wipeGraphicEngine.h"
#include "..\Utility\wipeTimer.h"
#include <iostream>

namespace wipengine
{
	wipeGraphicEngine::wipeGraphicEngine()
	{
	}

	wipeGraphicEngine::~wipeGraphicEngine()
	{
	}

	bool wipeGraphicEngine::initialize()
	{
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Failed to initialize GLEW" << std::endl;
			return false;
		}
		
		return true;
	}

	void wipeGraphicEngine::setViewport(int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void wipeGraphicEngine::run()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void wipeGraphicEngine::shutdown()
	{
		
	}
}

