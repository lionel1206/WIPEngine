#pragma once

namespace wipengine
{
	class wipeEngineBaseEntity
	{
	public:
		wipeEngineBaseEntity();
		~wipeEngineBaseEntity();
		virtual bool initialize() = 0;
		virtual void run() = 0;
		virtual void shutdown() = 0;
	};
}

