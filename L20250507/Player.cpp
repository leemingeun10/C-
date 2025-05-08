#include "Player.h"
#include "Input.h"
#include "Engine.h"
#include "SDL3/SDL.h"

#include "PaperFilpbookComponent.h"

APlayer::APlayer()
{
	Flipbook = (UPaperFilpbookComponent*)CreateDefaultSubobject(new UPaperFilpbookComponent());
	
	Flipbook->Shape = 'P';
	Flipbook->RenderOrder = 7;
	Flipbook->Color = { 255, 0, 0, 0};
	Flipbook->ColorKey = { 255, 0, 255, 255 };

	Flipbook->Filename = "player.bmp";
	Flipbook->IsSprite = true;

	Flipbook->Load();
}

APlayer::APlayer(const FVector2D& InVector)
{
	Location = InVector;

	Flipbook = (UPaperFilpbookComponent*)CreateDefaultSubobject(new UPaperFilpbookComponent());

	Flipbook->Shape = 'P';
	Flipbook->RenderOrder = 7;
	Flipbook->Color = { 255, 0, 0, 0 };
	Flipbook->ColorKey = { 255, 0, 255, 255 };
	Flipbook->Filename = "player.bmp";
	Flipbook->IsSprite = true;
	Flipbook->Load();
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	if (GEngine->Event.type == SDL_EVENT_KEY_DOWN)
	{
		switch (GEngine->Event.key.key)
		{
		case SDLK_W:
		case SDLK_UP:
			AddActorWorldOffset(FVector2D(0, -1));
			break;
		case SDLK_S:
		case SDLK_DOWN:
			AddActorWorldOffset(FVector2D(0, 1));
			break;
		case SDLK_A:
		case SDLK_LEFT:
			AddActorWorldOffset(FVector2D(-1, 0));
			break;
		case SDLK_D:
		case SDLK_RIGHT:
			AddActorWorldOffset(FVector2D(1, 0));
			break;
		}
	}
}
