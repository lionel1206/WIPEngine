#pragma once

#include <GLFW\glfw3.h>

class wipeWindow
{
public:
	wipeWindow(int height, int width);
	~wipeWindow();
	bool createWindow(char* windowTitle);
	void run();
	void close();
private:
	int mWindowHeight;
	int mWindowWidth;
	GLFWwindow* mWindowPtr;
};