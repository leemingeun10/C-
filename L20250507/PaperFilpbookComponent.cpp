#include "PaperFilpbookComponent.h"
#include "Renderer.h"
#include "Actor.h"
#include "Engine.h"
#include "SDL3/SDL.h"

UPaperFilpbookComponent::UPaperFilpbookComponent()
{
	ColorKey = { 255, 255, 255, 255 };
	IsSprite = false;
}

UPaperFilpbookComponent::~UPaperFilpbookComponent()
{
	ColorKey = { 255, 255, 255, 255 };
	IsSprite = false;
}

void UPaperFilpbookComponent::Load()
{
	if (Filename.size() > 0)
	{
		std::string Temp = "./data/" + Filename;
		Surface = SDL_LoadBMP(Temp.c_str()); //RAM
		const SDL_PixelFormatDetails* pixelDetails = SDL_GetPixelFormatDetails(Surface->format);

		SDL_SetSurfaceColorKey(Surface, true,
			SDL_MapRGB(pixelDetails, nullptr, ColorKey.r, ColorKey.g, ColorKey.a));
		//VRAM
		Texture = SDL_CreateTextureFromSurface(URenderer::GetInstance()->Renderer, Surface);
	}
}

bool UPaperFilpbookComponent::CompareByRendeOrder(const AActor* A, const AActor* B)
{
	return true;
	//return (RenderOrder) > (RenderOrder);
}

void UPaperFilpbookComponent::Render()
{
	SDL_FRect Location = {
	(float)Owner->Location.X * 30,
	(float)Owner->Location.Y * 30,
	(float)30,
	(float)30
	};

	static int Index = 0;
	if (IsSprite)
	{
		int SpirteSizeX = Surface->w / 5;
		int SpirteSizeY = Surface->h / 5;
		SDL_FRect SourceLocation{
			(float)(SpirteSizeX)*Index,
			(float)0,
			(float)(SpirteSizeX),
			(float)(SpirteSizeY)
		};
		SDL_RenderTexture(URenderer::GetInstance()->Renderer, Texture, &SourceLocation, &Location);
		if (elapasedTime >= ProcessTime)
		{
			elapasedTime = 0.0f;
			Index++;
			Index %= 5;
		}
		elapasedTime += UEngine::GetWorldDeltaSeconds();
		SDL_Log("%f\n", UEngine::GetWorldDeltaSeconds());
	}
	else
	{
		SDL_RenderTexture(URenderer::GetInstance()->Renderer, Texture, nullptr, &Location);
	}
}
