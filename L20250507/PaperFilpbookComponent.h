#pragma once
#include <string>

#include "SceneComponent.h"
#include "SDL3/SDL.h"

class AActor;

class UPaperFilpbookComponent : public USceneComponent
{
public:
	UPaperFilpbookComponent();
	virtual ~UPaperFilpbookComponent();

	virtual void Render() override;

	void Load();


	char Shape;

	static bool CompareByRendeOrder(const AActor* A, const AActor* B);

	SDL_Color Color;
	SDL_Color ColorKey;

	std::string Filename;
	SDL_Surface* Surface;
	SDL_Texture* Texture;

	bool IsSprite;

	float ProcessTime = 0.25f;
	float elapasedTime = 0.0;
};

