#pragma once

#include<vector>
using namespace std;
class Player;
class Slime;
class Goblin;
class Boar;

class UWorld
{
public:

	UWorld();
	~UWorld();

	vector<Player*> Players;
	vector<Slime*> Slimes;
	vector<Goblin*> Goblins;
	vector<Boar*> Boars;

	void Initialize();
	void Terminate();

	
};

