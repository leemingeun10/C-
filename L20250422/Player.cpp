#include "Player.h"
#include <iostream>
Player::Player()
{
	SetPlayerStat(100, 100);
}

Player::~Player()
{
}

void Player::SetPlayerStat(int a, int b)
{
	PlayerStat.HP = a;
	PlayerStat.Mp = b;
}

Stat Player::GetPlayerStat()
{


	return PlayerStat;
}

void Player::SetPlayerSkill(int a, std::string b)
{
	PlayerSkill[a - 1].Skillname = b;
}

std::string Player::GetPlayerSkill(int a)
{
	return PlayerSkill[a - 1].Skillname;
}

void Player::Attack()
{
	std::cout << "플레이어가 공격한다" << std::endl;
}
