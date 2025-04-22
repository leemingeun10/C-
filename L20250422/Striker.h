#include "Player.h"
#pragma once
class Striker :public Player
{
public:
	Striker();
	virtual ~Striker();

	virtual void Attack() override;



};

