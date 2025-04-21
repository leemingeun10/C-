#include "Actor.h"

AActor::AActor()
{

}

AActor::~AActor()
{
}

void AActor::Tick()
{
}

void AActor::AddActorWorldOffset(FVector2D Delta)
{
	Location.Add(Delta);
}
