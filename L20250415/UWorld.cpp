#include "UWorld.h"
#include <iostream>
#include"Player.h"
#include"Slime.h"
#include"Goblin.h"
#include"Boar.h"
#include<ctime>

#define MAXMONSTER 10


void UWorld::Initialize()
{
	

	vector<int> makerand;

	// makerand init
	makerand.push_back(0);
	makerand.push_back(0);
	makerand.push_back(0);


	
	for (int i = 0; i < MAXMONSTER; i++)
	{
		makerand[rand() % 3]++;
	}

	// init monsters
	for (int i = 0; i < 3; i++)
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
