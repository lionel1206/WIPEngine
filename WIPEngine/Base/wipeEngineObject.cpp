#include "wipeEngineObject.h"

namespace wipengine
{
	wipeEngineObject::wipeEngineObject()
	{
	}

	wipeEngineObject::~wipeEngineObject()
	{
	}

	bool wipeEngineObject::initialize()
	{
		return false;
	}

	void wipeEngineObject::run()
	{

	}

	void wipeEngineObject::shutdown()
	{

	}

	void wipeEngineObject::addComponent(wipeEngineComponent* component)
	{
		components.push_back(component);
	}

	void wipeEngineObject::removeComponent(wipeEngineComponent* component)
	{
		component->deleteComponent();
	}
}