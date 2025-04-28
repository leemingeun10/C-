#include "Goal.h"

AGoal::AGoal()
{
	Shape = 'G';
	RenderOrder = 8;
}

AGoal::AGoal(const FVector2D& InVector)
{
	Shape = 'G';
	Location = InVector;
	RenderOrder = 8;
}

AGoal::~AGoal()
{
}
