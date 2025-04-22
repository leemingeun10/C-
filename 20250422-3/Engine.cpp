#include "Engine.h"
#include "World.h"
#include "UInput.h"
UEngine::UEngine() //:world(nullptr) //이런식으로 초기화
{
	world = nullptr;
	inputdevice = nullptr;
}

UEngine::~UEngine()
{
	Terminate();
}

void UEngine::Inititialize()
{
	inputdevice = new UInput;
	world = new UWorld;
}

void UEngine::Run()
{
	while (true)
	{
		Input();
		Tick();
		Render();
	}
}

void UEngine::Terminate()
{
	if (world)
	{
		delete world;
		world = nullptr;
	}
	if (inputdevice)
	{
		delete inputdevice;
		inputdevice = nullptr;
	}
}

void UEngine::Render()
{
	world->Render();
}

void UEngine::Tick()
{
	
	world->Tick();
}

void UEngine::Input()
{
	//인풋을 하나로 추상화함
	inputdevice->tick();
}
