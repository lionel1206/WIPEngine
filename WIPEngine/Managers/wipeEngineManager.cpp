#include "wipeEngineManager.h"

wipeEngineManager* wipeEngineManager::mEngineManagerPtr;

wipeEngineManager::wipeEngineManager()
{

}

wipeEngineManager* wipeEngineManager::getSingleton()
{
	if(!mEngineManagerPtr)
		mEngineManagerPtr = new wipeEngineManager();

	return mEngineManagerPtr;
}

void wipeEngineManager::add(wipeEngineBase* engine)
{
	mEngineContainer.push_back(engine);
}

void wipeEngineManager::run()
{
	for each(wipeEngineBase* engine in mEngineContainer)
	{
		engine->run();
	}
}

void wipeEngineManager::shutdown()
{
	if (!mEngineManagerPtr)
		delete mEngineManagerPtr;
}