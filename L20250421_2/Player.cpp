#include "Player.h"
#include <iostream>

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	Move();
}

void APlayer::Move()
{
	std::cout << "Player Move" << std::endl;
}
