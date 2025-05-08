#include "Floor.h"
#include "PaperFilpbookComponent.h"

AFloor::AFloor()
{
	Flipbook = (UPaperFilpbookComponent*)CreateDefaultSubobject(new UPaperFilpbookComponent());

	Flipbook->Shape = ' ';
	Flipbook->RenderOrder = 10;
	Flipbook->Color = { 255, 255, 255, 0 };
	Flipbook->ColorKey = { 255, 255, 255, 255 };

	Flipbook->Filename = "floor.bmp";
	Flipbook->IsSprite = false;

	Flipbook->Load();
}

AFloor::AFloor(const FVector2D& InVector)
{
	Location = InVector;

	Flipbook = (UPaperFilpbookComponent*)CreateDefaultSubobject(new UPaperFilpbookComponent());

	Flipbook->Shape = ' ';
	Flipbook->RenderOrder = 10;
	Flipbook->Color = { 255, 255, 255, 0 };
	Flipbook->ColorKey = { 255, 255, 255, 255 };

	Flipbook->Filename = "floor.bmp";
	Flipbook->IsSprite = false;

	Flipbook->Load();
}

AFloor::~AFloor()
{
}
