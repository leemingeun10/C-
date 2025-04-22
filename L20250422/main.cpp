#include<iostream>
#include"Player.h"
#include"Striker.h"
using namespace std;

int main()
{
	Player* NewPlayer1 = new Player;
	NewPlayer1->Attack();


	Player* NewPlayer2 = new Striker;
	NewPlayer2->Attack();


	delete NewPlayer1, NewPlayer2;
	NewPlayer1 = nullptr;
	NewPlayer2 = nullptr;

	return 0;

}