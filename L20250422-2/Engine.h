#pragma once

class UWorld;
class UInput;

class UEngine
{
public:
	UEngine();
	virtual ~UEngine();

	void Initiailze();
	void Run();
	void Terminate();

private:
	void Input();
	void Tick();
	void Render();

	UWorld* World;
	UInput* InputDevice;

};

