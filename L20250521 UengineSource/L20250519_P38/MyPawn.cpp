// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
//������ �ؿ� �ؾ� �������ȳ�
#include"Components/StaticMeshComponent.h"
#include"Components/BoxComponent.h"
#include"GameFramework/SpringArmComponent.h"
#include"Components/ArrowComponent.h"
#include"Camera/CameraComponent.h"
#include"GameFramework/FloatingPawnMovement.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// BluePrintTree���� ����°�
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = Box;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body")); // �̸��� ��ġ��ȵ� 
	Body->SetupAttachment(Box);


	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/Script/Engine.StaticMesh'/Game/P38/Meshes/SM_P38_Body.SM_P38_Body'"));
	//������ ������ �ʱ����� static
	if (SM_Body.Succeeded()) // �о����� Ȯ���غ��°�
	{
		Body->SetStaticMesh(SM_Body.Object);
	}





	Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left")); // �̸��� ��ġ��ȵ� 
	Left->SetupAttachment(Body);


	

	Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right")); // �̸��� ��ġ��ȵ� 
	Right->SetupAttachment(Body);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Propeller(TEXT("/Script/Engine.StaticMesh'/Game/P38/Meshes/SM_P38_Propeller.SM_P38_Propeller'"));
	//������ ������ �ʱ����� static
	if (SM_Propeller.Succeeded()) // �о����� Ȯ���غ��°�
	{
		Left->SetStaticMesh(SM_Propeller.Object);
		Right->SetStaticMesh(SM_Propeller.Object);
	}

	Left->SetRelativeLocation(FVector(37.571327, -21.000000, 1.328775));
	Right->SetRelativeLocation(FVector(37.571327, 21.000000, 1.328775));


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm"));
	SpringArm->SetupAttachment(Box);

	SpringArm->TargetArmLength = 170.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bEnableCameraRotationLag = true;
	SpringArm->TargetOffset = FVector(0, 0, 41.0f);


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Box);

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MoveMent"));

	Boost = 0.5f;
	RotateSpeed = 60.0f;
	MoveSpeed = 10.0f;

	Movement->MaxSpeed = MoveSpeed;

	//Ʈ������ ����°�
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	AddMovementInput(GetActorForwardVector(), Boost);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

