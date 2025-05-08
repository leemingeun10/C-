#include "Timer.h"

UTimer::UTimer()
{
	CurrentTime = 0;
	LastTime = 0;
	DeltaSeconds = 0.f;
}

UTimer::~UTimer()
{
}

void UTimer::Tick()
{
	CurrentTime = SDL_GetTicks();

	DeltaSeconds = (float)(CurrentTime - LastTime) / 1000.f;

	LastTime = CurrentTime;
}
