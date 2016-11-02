#pragma once

namespace wipengine
{
	class wipeTimer
	{
	public:
		static void initializeTimer(double t);
		static void updateTimer(double t);
		static double getFPS();
		static double getDt();
	private:
		wipeTimer();
		~wipeTimer();
		static double mDt;
		static double mPreviousTime;
		static double mFPS;
	};
}