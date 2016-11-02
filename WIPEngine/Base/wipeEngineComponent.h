#pragma once
#include "wipeEngineBaseEntity.h"

namespace wipengine
{
	class wipeEngineComponent : public wipeEngineBaseEntity
	{
	public:
		wipeEngineComponent();
		~wipeEngineComponent();
		void deleteComponent();
	private:
		int mID;
		bool mEnabled;
		bool markedForDeletion;
	};
}