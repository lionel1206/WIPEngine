#include "wipeEngine.h"

#include "..\Managers\wipeEngineManager.h"
#include "..\Graphics\wipeGraphicEngine.h"
#include "..\System\Window\wipeWindow.h"
#include "..\Utility\wipeTimer.h"

namespace wipengine
{
	wipeEngine::wipeEngine(int width, int height) : mWindowWidth(width),
		mWindowHeight(height), mWindow(nullptr), mFPS(0.0), mDt(0.0)
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

		wipeTimer::initializeTimer(mWindow->getTime());
		TwInit(TW_OPENGL_CORE, NULL);
		TwWindowSize(mWindowWidth, mWindowHeight);

		mATTimerDIsplay = TwNewBar("Timer DIsplay");
		TwAddVarRO(mATTimerDIsplay, "Delta Time", TW_TYPE_DOUBLE, &mDt, "");
		TwAddVarRO(mATTimerDIsplay, "FPS", TW_TYPE_DOUBLE, &mFPS, "");

		return true;
	}

	void wipeEngine::run()
	{
		while (!mWindow->isWindowClose())
		{
			wipeTimer::updateTimer(mWindow->getTime());
			mDt = wipeTimer::getDt();
			mFPS = wipeTimer::getFPS();
			mWindow->listenForInput();
			wipeEngineManager::getSingleton()->run();
			TwDraw();
			mWindow->swapBuffer();
		}
	}

	void wipeEngine::shutdown()
	{
		TwTerminate();
		mWindow->close();

		wipeEngineManager::getSingleton()->shutdown();
	}
}
