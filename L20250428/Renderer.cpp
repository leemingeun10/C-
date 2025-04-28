#include "Renderer.h"


URenderer *URenderer::instance = nullptr;


URenderer::URenderer() 
{
	ScreenHandles[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenHandles[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	CurrentScreenindex = 0;
}


URenderer::~URenderer()
{
	CloseHandle(ScreenHandles[0]);
	CloseHandle(ScreenHandles[1]);
}

URenderer* URenderer::GetInstance()
{
	if (!instance)
	{
		instance = new URenderer();
	}

	return instance;
}

void URenderer::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenHandles[CurrentScreenindex], ' ', 100 * 40, COORD{ 0,0 }, &DW);
}

void URenderer::Render(const FVector2D& Location, char Shape)
{
	char shape[2] = { Shape , '\0' };
	SetConsoleCursorPosition(ScreenHandles[CurrentScreenindex], COORD{ (short)(Location.X),(short)(Location.Y) });
	WriteConsole(ScreenHandles[CurrentScreenindex], shape, 1, NULL, NULL);
}

void URenderer::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenHandles[CurrentScreenindex]);
	CurrentScreenindex++;
	CurrentScreenindex %= 2;
}
