#include "Monster.h"
#include "PaperFilpbookComponent.h"

AMonster::AMonster()
{

	Flipbook = (UPaperFilpbookComponent*)CreateDefaultSubobject(new UPaperFilpbookComponent());

	Flipbook->Shape = 'M';
	Flipbook->RenderOrder = 6;
	Flipbook->Color = { 255, 0, 0, 0 };
	Flipbook->ColorKey = { 255, 255, 255, 255 };

	Flipbook->Filename = "monster.bmp";
	Flipbook->IsSprite = false;

	Flipbook->Load();
}

AMonster::AMonster(const FVector2D& InVector)
{
	Location = InVector;

	Flipbook = (UPaperFilpbookComponent*)CreateDefaultSubobject(new UPaperFilpbookComponent());

	Flipbook->Shape = 'M';
	Flipbook->RenderOrder = 6;
	Flipbook->Color = { 255, 0, 0, 0 };
	Flipbook->ColorKey = { 255, 255, 255, 255 };

	Flipbook->Filename = "monster.bmp";
	Flipbook->IsSprite = false;

	Flipbook->Load();
}

AMonster::~AMonster()
{
}
