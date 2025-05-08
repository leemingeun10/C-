#pragma once
#include "SDL3/SDL.h"

class UTimer
{
public:
	UTimer();
	virtual ~UTimer();

	void Tick();

	Uint64 CurrentTime;

	Uint64 LastTime;

	float DeltaSeconds;
};

