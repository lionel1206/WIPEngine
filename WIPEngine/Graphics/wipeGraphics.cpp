#include "wipeGraphics.h"
#include <iostream>

namespace wipengine
{
	wipeGraphics::wipeGraphics()
	{
	}

	wipeGraphics::~wipeGraphics()
	{
	}

	bool wipeGraphics::initialize()
	{
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Failed to initialize GLEW" << std::endl;
			return false;
		}

		return true;
	}

	void wipeGraphics::setViewport(int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void wipeGraphics::run()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void wipeGraphics::shutdown()
	{

	}
}

