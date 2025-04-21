#include <iostream>
#include <vector>
#include "Monster.h"
#include "Goblin.h"
#include "Slime.h"
#include "World.h"
#include "Boar.h"
#include "Player.h"
#include "Floor.h"
#include "Goal.h"
#include "Wall.h"

using namespace std;

int main()
{
    UWorld* MyWorld = new UWorld();

    MyWorld->SpawnActor(new AGoblin());
    MyWorld->SpawnActor(new ASlime());
    MyWorld->SpawnActor(new APlayer());
    MyWorld->SpawnActor(new ABoar());
    MyWorld->SpawnActor(new AFloor());
    MyWorld->SpawnActor(new AFloor());
    MyWorld->SpawnActor(new AFloor());
    MyWorld->SpawnActor(new AFloor());
    MyWorld->SpawnActor(new AFloor());
    MyWorld->SpawnActor(new AFloor());
    MyWorld->SpawnActor(new AGoal());
    MyWorld->SpawnActor(new AWall());
    MyWorld->SpawnActor(new AWall());
    MyWorld->SpawnActor(new AWall());
    MyWorld->SpawnActor(new AWall());
    MyWorld->SpawnActor(new AWall());
    MyWorld->SpawnActor(new AWall());


    MyWorld->Run();

    delete MyWorld;
    MyWorld = nullptr;

 	return 0;
}