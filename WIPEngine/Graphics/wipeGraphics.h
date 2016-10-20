#pragma once

#define GLEW_STATIC
#include <GL\glew.h>
#include "../Base/wipeEngineBase.h"

namespace wipengine
{
	class wipeGraphics : public wipeEngineBase
	{
	public:
		wipeGraphics();
		~wipeGraphics();
		bool initialize();
		void run();
		void shutdown();
		void setViewport(int width, int height);
	private:

	};
}

