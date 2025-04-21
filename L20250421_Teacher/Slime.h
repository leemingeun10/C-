#pragma once

#include "Monster.h"
class ASlime : public AMonster
{
public:
	ASlime();
	virtual ~ASlime();

	virtual void Tick() override;
	virtual void Move() override;

};

