#include "wipeEngineComponent.h"

namespace wipengine
{
	wipeEngineComponent::wipeEngineComponent()
	{
	}

	wipeEngineComponent::~wipeEngineComponent()
	{
	}

	void wipeEngineComponent::deleteComponent()
	{
		markedForDeletion = true;
	}
}