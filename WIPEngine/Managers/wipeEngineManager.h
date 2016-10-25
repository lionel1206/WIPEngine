#pragma once

#include <vector>
#include "../Base/wipeEngineBaseEntity.h"

namespace wipengine
{
	class wipeEngineManager
	{
	public:
		static wipeEngineManager* getSingleton();
		void add(wipeEngineBaseEntity* engine);
		void run();
		void shutdown();
	private:
		wipeEngineManager();
		typedef std::vector<wipeEngineBaseEntity*> engineContainer;
		engineContainer mEngineContainer;
		static wipeEngineManager* mEngineManagerPtr;
	};
}

