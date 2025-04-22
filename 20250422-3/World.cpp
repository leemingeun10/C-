#include "World.h"
#include"Actor.h"
#include"Player.h"
UWorld::UWorld()
{
	SpawnActors(new APlayer());
}

UWorld::~UWorld()
{
	system("cls");
	for (auto Actor : Actors)
	{
		delete Actor;
		Actor = nullptr;
	}
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{

	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}
