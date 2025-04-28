#pragma once
#include<Windows.h>
#include"Vector2D.h"

//singleton 으로 만들기 
class URenderer
{
private:
	
	URenderer();
	virtual ~URenderer();
	static URenderer* instance;
	HANDLE ScreenHandles[2];
	int CurrentScreenindex;

public:
	static URenderer* GetInstance();
	void Clear();
	void Render(const FVector2D& Location, char Shape);
	void Flip();
};

