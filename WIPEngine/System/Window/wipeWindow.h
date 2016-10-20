#pragma once

#include <GLFW\glfw3.h>

namespace wipengine
{
	class wipeWindow
	{
	public:
		wipeWindow(int width, int height);
		~wipeWindow();
		bool createWindow(char* windowTitle);
		void close();
		void listenForInput();
		void swapBuffer();
		int isWindowClose();

	private:
		int mWindowHeight;
		int mWindowWidth;
		GLFWwindow* mWindowPtr;
	};
}
