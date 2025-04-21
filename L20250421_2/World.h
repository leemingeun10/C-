#pragma once
#include <vector>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	std::vector<AActor*> GetAllActors()
	{
		return Actors;
	}

	void Run();

	void SpawnActor(AActor* SpawnedActor);

protected:
	std::vector<AActor*> Actors;
};

//world has a actor.
