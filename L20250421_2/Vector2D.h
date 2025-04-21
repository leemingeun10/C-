#pragma once

struct FVector2D
{
	FVector2D()
	{
		X = 0;
		Y = 0;
	}
	
	~FVector2D()
	{

	}

	void Add(FVector2D Delta)
	{
		X += Delta.X;
		Y += Delta.Y;
	}

	int X;
	int Y;
};

