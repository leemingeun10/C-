#include <iostream>
#include "Windows.h"

#include "Actor.h"
#include "Renderer.h"
#include "SDL3/SDL.h"
#include "Component.h"
#include "SceneComponent.h"


AActor::AActor()
{
}

AActor::AActor(const FVector2D& InVector)
{

}

AActor::~AActor()
{
}

void AActor::AddActorWorldOffset(FVector2D offset)
{
	Location.X += offset.X;
	Location.Y += offset.Y;
}

void AActor::Tick()
{
}

void AActor::Render()
{
	for (auto Component : PropertyList)
	{
		USceneComponent* SceneComponent = dynamic_cast<USceneComponent*>(Component);
		if (Component)
		{
			SceneComponent->Render();
		}
	}

}

UComponent* AActor::CreateDefaultSubobject(UComponent* NewComponent)
{
	NewComponent->Owner = this;
	PropertyList.push_back(NewComponent);
	return NewComponent;
}
