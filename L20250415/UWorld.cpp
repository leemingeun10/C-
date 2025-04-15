#include "UWorld.h"
#include <iostream>
#include"Player.h"
#include"Slime.h"
#include"Goblin.h"
#include"Boar.h"
#include<ctime>

#define MAXMONSTER 10
#define monstersNum 3 // if add  must change 

// 램덤하게 몬스터들이 나오면 좋겟다 
// 그걸해보쟝 화장실도 가고싶다



UWorld::UWorld()
{
	this->Initialize();
}

UWorld::~UWorld()
{
	this->Terminate();
}

void UWorld::Initialize()
{
	

	vector<int> makerand;

	// makerand init count of each monster
	for(int i = 0 ; i< monstersNum ; i++)
	{ 
		makerand.push_back(0);
	}
	for (int i = 0; i < MAXMONSTER; i++)
	{
		makerand[rand() % monstersNum]++;
	}


	// init monsters   need add if 
	for (int i = 0; i < monstersNum; i++)
	{
		for (int j = 0; j < makerand[i]; j++)
		{
			if (i == 0)
			{
				Slimes.push_back(new Slime);
			}
			else if (i == 1)
			{
				Boars.push_back(new Boar);
			}
			else if (i == 2)
			{
				Goblins.push_back(new Goblin);
			}
		}
	}



	//init player
	Players.push_back(new Player);

}

void UWorld::Terminate()
{
	for (auto del : Goblins)
	{
		delete del;
	}
	for (auto del : Slimes)
	{
		delete del;
	}
	for (auto del : Boars)
	{
		delete del;
	}
	for (auto del : Players)
	{
		delete del;
	}

	Slimes.clear();
	Boars.clear();
	Goblins.clear();
	Players.clear();

}
