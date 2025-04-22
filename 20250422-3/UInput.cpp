#include "UInput.h"
#include "Windows.h"
#include "conio.h"

int UInput::KeyCode;

UInput::UInput()
{
}

UInput::~UInput()
{
}

void UInput::tick()
{
	if (_kbhit())
	{
		int KeyCode = _getch();
	}
	else
	{
		KeyCode = 0;
	}
}
