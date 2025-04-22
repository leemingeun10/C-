#include<iostream>
#include"Windows.h"
#include "Actor.h"

AActor::AActor()
{
	Shape = ' ';
}

AActor::~AActor()
{
}

void AActor::AddActorWorldOffset(FVector2D offset)
{
	Location.x += offset.x;
	Location.y += offset.y;
}

void AActor::Tick()
{
}

void AActor::Render()
{
	COORD Position = {(SHORT)Location.x,(SHORT)Location.y }; //x, y ÁÂÇ¥ ¼³Á¤
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);

	std::cout << Shape;

}
