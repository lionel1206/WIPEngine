#include "Graphics\wipeGraphics.h"
#include "System\Window\wipeWindow.h"
#include <Windows.h>
#include "Managers\wipeEngineManager.h";

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR, int)
{
	int width = 1280;
	int height = 720;

	wipeGraphics* graphics = new wipeGraphics();
	wipeWindow* window = new wipeWindow(height, width);

	if (!window->createWindow("WIPEngine"))
		return -1;

	if (!graphics->initialize())
		return -1;

	wipeEngineManager::getSingleton()->add(graphics);

	graphics->setViewport(width, height);
	window->run();
	window->close();

	delete window;
	delete graphics;

	wipeEngineManager::getSingleton()->shutdown();

	return 0;
}