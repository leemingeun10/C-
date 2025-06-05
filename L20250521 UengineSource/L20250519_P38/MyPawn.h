// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"


class UBoxComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UFloatingPawnMovement;
class UArrowComponent;

UCLASS()
class L20250519_P38_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere,Category="Components",BlueprintReadOnly);  // 이걸 넣어줘야지 보임 + 카테고리 분류와 + blueprint 에서 읽을수만있게 
	// 하다가 모르면 f12
	
	
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly);
	TObjectPtr < UStaticMeshComponent> Body;
	// 언리얼은 모든게 포인터
	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly);
	TObjectPtr < UStaticMeshComponent> Right;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly);
	TObjectPtr < UStaticMeshComponent> Left;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly);
	TObjectPtr < USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly);
	TObjectPtr < UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly);
	TObjectPtr < UArrowComponent> Arrow;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly);
	TObjectPtr < UFloatingPawnMovement> Movement;

	UPROPERTY(VisibleAnywhere, Category = "Data", BlueprintReadWrite);
	float MoveSpeed;

	UPROPERTY(VisibleAnywhere, Category = "Data", BlueprintReadWrite );
	float RotateSpeed;


	UPROPERTY(VisibleAnywhere, Category = "Data", BlueprintReadWrite);
	float Boost;
	
};
