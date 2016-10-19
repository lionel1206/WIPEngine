#pragma once
#include "../Base/wipeEngineBase.h"

class wipeWindow;

namespace wipengine
{
	class wipeEngine : public wipeEngineBase
	{
	public:
		wipeEngine();
		~wipeEngine();

		bool initialize();
		void run();
		void shutdown();
	private:
		int mWindowWidth;
		int mWindowHeight;
		wipeWindow* mWindow;
	};
}