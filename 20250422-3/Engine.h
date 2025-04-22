#pragma once
class UWorld;
class UInput;
class UEngine
{
public:
	UEngine();
	virtual ~UEngine();

	void Inititialize();
	void Run();
	void Terminate();
private:
	void Render();
	void Tick();
	void Input();
	
	UWorld* world;
	UInput* inputdevice;
};

