#include "Floor.h"

AFloor::AFloor()
{
	Shape = ' ';
	RenderOrder = 10;
}

AFloor::AFloor(const FVector2D& InVector)
{
	Shape = ' ';
	Location = InVector;
	RenderOrder = 10;
}

AFloor::~AFloor()
{
}
