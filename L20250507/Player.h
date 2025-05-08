#pragma once
#include "Actor.h"
class UPaperFilpbookComponent;

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(const FVector2D& InVector);
	virtual	~APlayer();

	virtual void Tick() override;

	class UPaperFilpbookComponent* Flipbook;

};

