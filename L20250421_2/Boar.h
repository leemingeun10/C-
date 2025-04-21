#pragma once
#include "Monster.h"
class ABoar : public AMonster
{
public:
	ABoar();
	virtual ~ABoar();

	virtual void Tick() override;
	virtual void Move() override;
};

