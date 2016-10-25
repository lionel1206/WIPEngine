#include "wipeEngineManager.h"

namespace wipengine
{
	wipeEngineManager* wipeEngineManager::mEngineManagerPtr;

	wipeEngineManager::wipeEngineManager()
	{

	}

	wipeEngineManager* wipeEngineManager::getSingleton() 
	{
		if (!mEngineManagerPtr)
			mEngineManagerPtr = new wipeEngineManager();

		return mEngineManagerPtr;
	}

	void wipeEngineManager::add(wipeEngineBaseEntity* engine)
	{
		mEngineContainer.push_back(engine);
	}

	void wipeEngineManager::run()
	{
		for each(wipeEngineBaseEntity* engine in mEngineContainer)
		{
			engine->run();
		}
	}

	void wipeEngineManager::shutdown()
	{
		for each(wipeEngineBaseEntity* engine in mEngineContainer)
		{
			engine->shutdown();
			delete engine;
		}

		if (!mEngineManagerPtr)
			delete mEngineManagerPtr;
	}
}

