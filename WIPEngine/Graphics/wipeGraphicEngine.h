#pragma once

#define GLEW_STATIC
#include <GL\glew.h>
#include "../Base/wipeEngineBaseEntity.h"

namespace wipengine
{
	class wipeGraphicEngine : public wipeEngineBaseEntity
	{
	public:
		wipeGraphicEngine();
		~wipeGraphicEngine();
		bool initialize();
		void run();
		void shutdown();
		void setViewport(int width, int height);
	private:

	};
}

