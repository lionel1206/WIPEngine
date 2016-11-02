#pragma once
#include "../Base/wipeEngineBaseEntity.h"
#include "../include/AntTweakBar.h"

namespace wipengine
{
	class wipeWindow;

	class wipeEngine : public wipeEngineBaseEntity
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
		double mFPS;
		double mDt;
		wipeWindow* mWindow;
		TwBar* mATTimerDIsplay;
	};
}