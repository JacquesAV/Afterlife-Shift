#include "EventManager.h"

UEventManager* UEventManager::Instance = nullptr;

UEventManager* UEventManager::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = NewObject<UEventManager>(nullptr);
	}

	return Instance;
}

UEventManager::UEventManager()
{
	// ...
}

UEventManager::~UEventManager()
{
	// ...
}