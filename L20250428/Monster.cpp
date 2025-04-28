#include "Monster.h"

AMonster::AMonster()
{
	Shape = 'M';
	RenderOrder = 6;
}

AMonster::AMonster(const FVector2D& InVector)
{
	Shape = 'M';
	Location = InVector;
	RenderOrder = 6;
}

AMonster::~AMonster()
{
}
