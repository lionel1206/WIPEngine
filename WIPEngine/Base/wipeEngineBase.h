#pragma once

namespace wipengine
{
	class wipeEngineBase
	{
	public:
		wipeEngineBase();
		~wipeEngineBase();
		virtual bool initialize() = 0;
		virtual void run() = 0;
		virtual void shutdown() = 0;
	};
}

