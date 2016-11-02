#pragma once

#include "wipeEngineBaseEntity.h"
#include "wipeEngineComponent.h"
#include <vector>

namespace wipengine
{
	class wipeEngineObject : public wipeEngineBaseEntity
	{
	public:
		wipeEngineObject();
		~wipeEngineObject();
		bool initialize();
		void run();
		void shutdown();

		void addComponent(wipeEngineComponent* component);
		void removeComponent(wipeEngineComponent* component);
	private:
		typedef std::vector<wipeEngineComponent*> componentContainer;
		componentContainer components;
	};
}
