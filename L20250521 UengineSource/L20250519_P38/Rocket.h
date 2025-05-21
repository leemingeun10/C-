// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rocket.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class L20250519_P38_API ARocket : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly);
	TObjectPtr < UStaticMeshComponent> Body;
	
	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly);
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;


};
