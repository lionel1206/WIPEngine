#include "wipeEngine.h"

#include "..\Managers\wipeEngineManager.h"
#include "..\Graphics\wipeGraphicEngine.h"
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
		wipeGraphicEngine* graphicEngine = new wipeGraphicEngine();
		if (!graphicEngine->initialize())
			return false;

		graphicEngine->setViewport(mWindowWidth, mWindowHeight);

		wipeEngineManager::getSingleton()->add(graphicEngine);

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
