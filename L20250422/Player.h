#pragma once
#include"Stat.h"
#include"Skill.h"
#include"String"
class Player
{
public:
	Player();
	virtual ~Player();

	void SetPlayerStat(int a , int b);
	Stat GetPlayerStat();

	void SetPlayerSkill(int a ,std::string b);
	std::string GetPlayerSkill(int a);

	virtual void Attack();

protected:
	Stat PlayerStat;
	Skill PlayerSkill[8];
};

