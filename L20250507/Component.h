#pragma once
class AActor;

class UComponent
{
public:
	UComponent()
	{
		Owner = nullptr;
	}

	virtual void Tick();

	class AActor* Owner;

	class AActor* GetOwner()
	{
		return Owner;
	}
};

