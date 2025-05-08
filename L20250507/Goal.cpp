#include "Goal.h"
#include "PaperFilpbookComponent.h"

AGoal::AGoal()
{
	Flipbook = (UPaperFilpbookComponent*)CreateDefaultSubobject(new UPaperFilpbookComponent());

	Flipbook->Shape = 'G';
	Flipbook->RenderOrder = 6;
	Flipbook->Color = { 0, 255, 0, 0 };
	Flipbook->ColorKey = { 255, 255, 255, 255 };

	Flipbook->Filename = "goal.bmp";
	Flipbook->IsSprite = false;

	Flipbook->Load();
}

AGoal::AGoal(const FVector2D& InVector)
{
	Location = InVector;

	Flipbook = (UPaperFilpbookComponent*)CreateDefaultSubobject(new UPaperFilpbookComponent());

	Flipbook->Shape = 'G';
	Flipbook->RenderOrder = 6;
	Flipbook->Color = { 0, 255, 0, 0 };
	Flipbook->ColorKey = { 255, 255, 255, 255 };

	Flipbook->Filename = "goal.bmp";
	Flipbook->IsSprite = false;

	Flipbook->Load();
}

AGoal::~AGoal()
{
}
