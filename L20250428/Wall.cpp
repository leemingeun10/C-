#include "Wall.h"

AWall::AWall()
{
	Shape = '*';
	RenderOrder = 9;
}

AWall::AWall(const FVector2D& InVector)
{
	Shape = '*';
	Location = InVector;
	RenderOrder = 9;
}

AWall::~AWall()
{
}
