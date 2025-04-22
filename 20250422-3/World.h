#pragma once
#include<vector>
class AActor;

class UWorld
{
public:
	UWorld();
	~UWorld();
	void Tick();
	void Render();

	void SpawnActors();
	void DestroyActor();
	std::vector<AActor*>& GetAllActors();

protected:
	std::vector<AActor*> Actors;
};

//World Has a Actor