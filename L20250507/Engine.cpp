#include "Engine.h"
#include "World.h"
#include "Input.h"
#include "Renderer.h"
#include "Timer.h"




UEngine* UEngine::Instance = nullptr;


UEngine::UEngine() //: World(nullptr)
{
	World = nullptr;
	InputDevice = nullptr;
	Timer = new UTimer();
}

UEngine::~UEngine()
{
	Terminate();
}

void UEngine::Initiailze(std::string filename)
{
	IsRunning = true;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	Window = SDL_CreateWindow("Engine", 800, 600, SDL_WINDOW_OPENGL);

	InputDevice = new UInput();
	World = new UWorld();
	World->Load(filename);
	URenderer::GetInstance();
}

void UEngine::Run()
{
	while (IsRunning)
	{
		Timer->Tick();
		SDL_PollEvent(&Event);
		switch (Event.type)
		{
		case SDL_EVENT_QUIT:
			IsRunning = false;
			break;
		}

		Input();
		Tick();
		Render();
	}
}

void UEngine::Terminate()
{
	if (World)
	{
		delete World;
		World = nullptr;
	}

	if (InputDevice)
	{
		delete InputDevice;
		InputDevice = nullptr;
	}

	SDL_DestroyWindow(Window);
	SDL_Quit();
}

float UEngine::GetWorldDeltaSeconds()
{
	return GEngine->Timer->DeltaSeconds;
}

void UEngine::Input()
{
	InputDevice->Tick();
	//Engine has a Input
	//키보드, 마우스, 조이스틱, 터치, 자이로 센스
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}
