#pragma once
#include <string>

class UWorld;
class UInput;



class UEngine
{
private:
	UEngine();
	static UEngine* Instance;

public:

	static UEngine* GetInstance()
	{
		if (!Instance)
		{
			Instance = new UEngine();
		}

		return Instance;
	}

	virtual ~UEngine();

	void Initiailze(std::string filename = "level01.map");
	void Run();
	void Terminate();

private:
	void Input();
	void Tick();
	void Render();

	UWorld* World;
	UInput* InputDevice;

};


#define	GEngine		UEngine::GetInstance()