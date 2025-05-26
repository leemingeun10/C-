// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include"GameFramework/SpringArmComponent.h"
#include"Camera/CameraComponent.h"
#include"Components/SkeletalMeshComponent.h"
#include"Components/CapsuleComponent.h"
#include"EnhancedInputComponent.h" 
#include"EnhancedInputSubsystems.h"

// 경로가 퍼블릭이라 이렇게입력하면됨

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false; // 직접 회전 허용
	//GetCharacterMovement()->bOrientRotationToMovement = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()),
		FRotator(0, -90.0f, 0)
	);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	
	// 밑에 부분은 enhancedinputsystem을 사용하기 위해서 필요한것 
	Super::BeginPlay();

	APlayerController* PC = Cast<APlayerController>(Controller);

	if (PC)
	{
		if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(PC->Player))
		{
			if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (IMC_Default)
				{
					InputSystem->AddMappingContext(IMC_Default, 0);
				}
			}
		}
	}
}

// Called every frame 
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);  // 블루프린트에서의 casting 이라고 생각하면된다 다운 캐스팅 자동으로 되게해줌 Cast 는 Uengine의것 c++의 dynamic_cast같음
	if (UEIC)
	{
		UEIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
		UEIC->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &AMyCharacter::Jump);
		UEIC->BindAction(IA_Jump, ETriggerEvent::Canceled, this, &AMyCharacter::StopJumping);
		UEIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AMyCharacter::Look);
		UEIC->BindAction(IA_Zoom, ETriggerEvent::Triggered, this, &AMyCharacter::Zoom);
	}
}

void AMyCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MoveVector = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), MoveVector.X);
	AddMovementInput(GetActorRightVector(), MoveVector.Y);

}

void AMyCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();

	// 마우스 X 입력으로 캐릭터 자체 회전 (Yaw)
	FRotator YawRotation(0.f, LookVector.X * RotationSpeed, 0.f); // RotationSpeed는 감도
	AddActorLocalRotation(YawRotation);
}


void AMyCharacter::Zoom(const FInputActionValue& Value)
{
	float Zoomvalue = Value.Get<float>();
}
