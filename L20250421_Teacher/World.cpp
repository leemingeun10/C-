#include "World.h"
#include "Actor.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::Run()
{
	while (true)
	{
		for (auto Actor : Actors)
		{
			Actor->Tick();
		}
	}
}

void UWorld::SpawnActor(AActor* SpawnedActor)
{
	Actors.push_back(SpawnedActor);
}
