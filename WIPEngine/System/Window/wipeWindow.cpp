#include "wipeWindow.h"
#include "../../Managers/wipeEngineManager.h"
#include <iostream>

namespace wipengine
{
	wipeWindow::wipeWindow(int width, int height) : mWindowHeight(height),
		mWindowWidth(width)
	{
		glfwInit();
	}

	wipeWindow::~wipeWindow()
	{
	}

	bool wipeWindow::createWindow(char* windowTitle)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		mWindowPtr = glfwCreateWindow(mWindowWidth, mWindowHeight,
			windowTitle, nullptr, nullptr);
		if (mWindowPtr == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(mWindowPtr);

		return true;
	}

	int wipeWindow::isWindowClose()
	{
		return glfwWindowShouldClose(mWindowPtr);
	}

	void wipeWindow::listenForInput()
	{
		glfwPollEvents();
	}

	void wipeWindow::swapBuffer()
	{
		glfwSwapBuffers(mWindowPtr);
	}

	void wipeWindow::close()
	{
		glfwTerminate();
	}

	double wipeWindow::getTime()
	{
		return glfwGetTime();
	}
}

