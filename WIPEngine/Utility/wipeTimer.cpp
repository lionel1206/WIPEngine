#include "wipeTimer.h"

namespace wipengine
{
	double wipeTimer::mDt;
	double wipeTimer::mPreviousTime;
	double wipeTimer::mFPS;

	wipeTimer::wipeTimer()
	{
	}

	wipeTimer::~wipeTimer()
	{
	}

	void wipeTimer::initializeTimer(double t)
	{
		mDt = 0.0;
		mPreviousTime = t;
		mFPS = 0.0;
	}

	void wipeTimer::updateTimer(double t)
	{
		double currentTIme = t;
		mDt = currentTIme - mPreviousTime;
		mFPS = 1.0 / mDt;
		mPreviousTime = currentTIme;
	}

	double wipeTimer::getFPS()
	{
		return mFPS;
	}

	double wipeTimer::getDt()
	{
		return mDt;
	}
}