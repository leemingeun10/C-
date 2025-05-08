#pragma once
#include <vector>
#include <string>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Tick();
	void Render();

	void Load(std::string filename);

	void SpawnActor(AActor* NewActor);
	void DestoryActor(AActor* DestroyedActor);

	std::vector<AActor*>& GetAllActors();

protected:
	//[][][][][][][]
	std::vector<AActor*> Actors;
};

//World has a actor.

