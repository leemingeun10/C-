#pragma once
#include "Vector2D.h"

class AActor
{
public:
	AActor();
	AActor(const FVector2D& InVector);
	virtual ~AActor();

	void AddActorWorldOffset(FVector2D offset);
	FVector2D Location;

	virtual void Tick();
	virtual void Render();

	char Shape;
	int RenderOrder = 0;
};

//Actor has a Fvector2D
