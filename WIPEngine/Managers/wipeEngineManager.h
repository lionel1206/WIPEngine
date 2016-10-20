#pragma once

#include <vector>
#include "../Base/wipeEngineBase.h"

namespace wipengine
{
	class wipeEngineManager
	{
	public:
		static wipeEngineManager* getSingleton();
		void add(wipeEngineBase* engine);
		void run();
		void shutdown();
	private:
		wipeEngineManager();
		typedef std::vector<wipeEngineBase*> engineContainer;
		engineContainer mEngineContainer;
		static wipeEngineManager* mEngineManagerPtr;
	};
}

