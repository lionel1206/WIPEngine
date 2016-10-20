#include "wipeEngine.h"

#include "..\Managers\wipeEngineManager.h"
#include "..\Graphics\wipeGraphics.h"
#include "..\System\Window\wipeWindow.h"

namespace wipengine
{
	wipeEngine::wipeEngine(int width, int height) : mWindowWidth(width), mWindowHeight(height), mWindow(nullptr)
	{
	}

	wipeEngine::~wipeEngine()
	{

	}

	bool wipeEngine::initialize()
	{
		mWindow = new wipeWindow(mWindowWidth, mWindowHeight);

		if (!mWindow->createWindow("WIPEngine"))
			return false;

		if (!initializeEngines())
			return false;

		return true;
	}

	bool wipeEngine::initializeEngines()
	{
		wipeGraphics* graphics = new wipeGraphics();
		if (!graphics->initialize())
			return false;

		graphics->setViewport(mWindowWidth, mWindowHeight);

		wipeEngineManager::getSingleton()->add(graphics);

		return true;
	}

	void wipeEngine::run()
	{
		while (!mWindow->isWindowClose())
		{
			mWindow->listenForInput();
			wipeEngineManager::getSingleton()->run();
			mWindow->swapBuffer();
		}
	}

	void wipeEngine::shutdown()
	{
		mWindow->close();

		wipeEngineManager::getSingleton()->shutdown();
	}
}
