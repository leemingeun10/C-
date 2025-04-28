#include <iostream>
#include "Windows.h"

#include "Actor.h"
#include"Renderer.h"


AActor::AActor()
{
	Shape = ' ';
}

AActor::AActor(const FVector2D& InVector)
{
	Location = InVector;
	//Location.X = InVector.X;
	//Location.Y = InVector.Y;
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
	/*COORD Position = { static_cast<SHORT>(Location.X), (SHORT)Location.Y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);

	std::cout << Shape;*/

	URenderer::GetInstance()->Render(Location,Shape);

}
