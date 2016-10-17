#include "wipeWindow.h"
#include "../../Managers/wipeEngineManager.h"
#include <iostream>
wipeWindow::wipeWindow(int height, int width) : mWindowHeight(height),
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

void wipeWindow::run()
{
	while (!glfwWindowShouldClose(mWindowPtr))
	{
		glfwPollEvents();
		wipeEngineManager::getSingleton()->run();
		glfwSwapBuffers(mWindowPtr);
	}
}

void wipeWindow::close()
{
	glfwTerminate();
}