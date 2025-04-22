#include"Engine.h"

int main()
{
	UEngine* Engine = new UEngine();

	Engine->Inititialize();
	Engine->Run();

	return 0;
}