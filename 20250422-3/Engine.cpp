#include "Engine.h"
#include "World.h"
#include "UInput.h"
UEngine::UEngine() //:world(nullptr) //�̷������� �ʱ�ȭ
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
	//��ǲ�� �ϳ��� �߻�ȭ��
	inputdevice->tick();
}
