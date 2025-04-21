#pragma once
#include "Monster.h"

class AGoblin : public AMonster
{
public:
	AGoblin();
	virtual ~AGoblin(); 

	virtual void Tick() override;

	virtual void Move() override;
};

