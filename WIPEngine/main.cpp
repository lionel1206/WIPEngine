
#include <Windows.h>
#include <iostream>
#include "Engine\wipeEngine.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR, int)
{
	int width = 1280;
	int height = 720;
	
	wipengine::wipeEngine* engine = new wipengine::wipeEngine(width, height);
	
	if (!engine->initialize())
	{
		std::cout << "Initialize engine failed..." << std::endl;
	}

	engine->run();
	engine->shutdown();

	delete engine;

	return 0;
}