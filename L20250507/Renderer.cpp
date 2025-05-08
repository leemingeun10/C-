#include "Renderer.h"
#include "Engine.h"
#include "Actor.h"

URenderer* URenderer::Instance = nullptr;

URenderer::URenderer()
{
	ScreenHandles[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenHandles[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CurrentScreenIndex = 0;

	Renderer = SDL_CreateRenderer(GEngine->Window, nullptr);
}

URenderer::~URenderer()
{
	CloseHandle(ScreenHandles[0]);
	CloseHandle(ScreenHandles[1]);
	SDL_DestroyRenderer(Renderer);
}

URenderer* URenderer::GetInstance()
{
	if (!Instance)
	{
		Instance = new URenderer();
	}

	return Instance;
}

void URenderer::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenHandles[CurrentScreenIndex], ' ', 100 * 40, COORD{ 0, 0 }, &DW);

	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
	SDL_RenderClear(Renderer);
}

//void URenderer::Render(const FVector2D& Location, char Shape)
//{
//	char Shapes[2] = { Shape, '\0' };
//	SetConsoleCursorPosition(ScreenHandles[CurrentScreenIndex], COORD{ (short)(Location.X), (short)(Location.Y)});
//
//	WriteConsole(ScreenHandles[CurrentScreenIndex], Shapes, 1, NULL, NULL);
//}

void URenderer::Render(AActor* RenderObject)
{
	//char Shapes[2] = { RenderObject->Shape, '\0' };
	//SetConsoleCursorPosition(ScreenHandles[CurrentScreenIndex], COORD{ (short)(RenderObject->Location.X), (short)(RenderObject->Location.Y) });

	//WriteConsole(ScreenHandles[CurrentScreenIndex], Shapes, 1, NULL, NULL);

	//SDL_FRect Location = { 
	//	(float)RenderObject->Location.X * 30,
	//	(float)RenderObject->Location.Y * 30,
	//	(float)30,
	//	(float)30
	//};

	//static int Index = 0;
	//if (RenderObject->IsSprite)
	//{
	//	int SpirteSizeX = RenderObject->Surface->w / 5;
	//	int SpirteSizeY = RenderObject->Surface->h / 5;
	//	SDL_FRect SourceLocation{
	//		(float)(SpirteSizeX) * Index,
	//		(float)0,
	//		(float)(SpirteSizeX),
	//		(float)(SpirteSizeY)
	//	};
	//	SDL_RenderTexture(Renderer, RenderObject->Texture, &SourceLocation, &Location);
	//	if (RenderObject->elapasedTime >= RenderObject->ProcessTime)
	//	{
	//		RenderObject->elapasedTime = 0.0f;
	//		Index++;
	//		Index %= 5;
	//	}
	//	RenderObject->elapasedTime += UEngine::GetWorldDeltaSeconds();
	//	SDL_Log("%f\n", UEngine::GetWorldDeltaSeconds());
	//}
	//else
	//{
	//	SDL_RenderTexture(Renderer, RenderObject->Texture, nullptr, &Location);
	//}
}

void URenderer::Present()
{
	SetConsoleActiveScreenBuffer(ScreenHandles[CurrentScreenIndex]);

	CurrentScreenIndex++;
	CurrentScreenIndex %= 2;

	SDL_RenderPresent(Renderer);
}
