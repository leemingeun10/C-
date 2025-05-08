#include "Wall.h"
#include "PaperFilpbookComponent.h"


AWall::AWall()
{
	Flipbook = (UPaperFilpbookComponent*)CreateDefaultSubobject(new UPaperFilpbookComponent());

	Flipbook->Shape = '0';
	Flipbook->RenderOrder = 9;
	Flipbook->Color = { 255, 255, 255, 0 };
	Flipbook->ColorKey = { 255, 255, 255, 255 };

	Flipbook->Filename = "wall.bmp";
	Flipbook->IsSprite = false;

	Flipbook->Load();
}

AWall::AWall(const FVector2D& InVector)
{
	Location = InVector;

	Flipbook = (UPaperFilpbookComponent*)CreateDefaultSubobject(new UPaperFilpbookComponent());

	Flipbook->Shape = '0';
	Flipbook->RenderOrder = 9;
	Flipbook->Color = { 255, 255, 255, 0 };
	Flipbook->ColorKey = { 255, 255, 255, 255 };

	Flipbook->Filename = "wall.bmp";
	Flipbook->IsSprite = false;

	Flipbook->Load();
}

AWall::~AWall()
{
}
