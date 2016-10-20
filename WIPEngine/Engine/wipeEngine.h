#pragma once
#include "../Base/wipeEngineBase.h"

namespace wipengine
{
	class wipeWindow;

	class wipeEngine : public wipeEngineBase
	{
	public:
		wipeEngine(int width, int height);
		~wipeEngine();

		bool initialize();
		void run();
		void shutdown();
	private:

		bool initializeEngines();

		int mWindowWidth;
		int mWindowHeight;
		wipeWindow* mWindow;
	};
}