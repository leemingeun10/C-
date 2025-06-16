// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BulletDamage.h"
#include "Engine/DamageEvents.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "InGame/InGamePC.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (IsValid(UIC))
	{
		UIC->BindAction(FireInput, ETriggerEvent::Completed, this, &AMyCharacter::OnFire);
	}

}

void AMyCharacter::OnFire()
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (IsValid(PC))
	{
		int32 SizeX;
		int32 SizeY;
		FVector WorldPosition;
		FVector WorldDirection;

		FVector CameraLocation;
		FRotator CameraRotation;

		PC->GetViewportSize(SizeX, SizeY);
		PC->GetPlayerViewPoint(CameraLocation, CameraRotation);

		PC->DeprojectScreenPositionToWorld(SizeX / 2.0f,
			SizeY / 2.0f,
			WorldPosition,
			WorldDirection
		);

		//FVector SpawnPosition = GetActorLocation() + (WorldDirection * 100.f);
		//FRotator SpawnRotation = WorldDirection.Rotation();

		FVector SpawnPosition = CameraLocation;
		FRotator SpawnRotation = CameraRotation;

		C2S_Fire(SpawnPosition, SpawnRotation);
	}
}

bool AMyCharacter::C2S_Fire_Validate(const FVector& SpawnPosition, const FRotator& SpawnRotation)
{
	return true;
}

void AMyCharacter::C2S_Fire_Implementation(const FVector& SpawnPosition, const FRotator& SpawnRotation)
{

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_PhysicsBody));

	TArray<AActor*> IgnoreActor;

	FHitResult OutHit;

	//AActor* Bullet = GetWorld()->SpawnActor<AActor>(BulletActor, SpawnPosition, SpawnRotation);

	bool bResult = UKismetSystemLibrary::LineTraceSingleForObjects(
		GetWorld(),
		SpawnPosition,
		SpawnPosition + (SpawnRotation.Vector() * 10000.0f),
		ObjectTypes,
		true,
		IgnoreActor,
		EDrawDebugTrace::ForDuration,
		OutHit,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		2.0f
	);
	if (bResult)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit %s"), *OutHit.GetActor()->GetName());
		UE_LOG(LogTemp, Warning, TEXT("Bone %s"), *OutHit.BoneName.ToString());
		
		//UGameplayStatics::ApplyDamage(OutHit.GetActor(),
		//	100.0f,
		//	GetController(),
		//	this, 
		//	UBulletDamage::StaticClass()
		//);

		UGameplayStatics::ApplyPointDamage(
			OutHit.GetActor(),
			100.0f,
			SpawnRotation.Vector(),
			OutHit,
			GetController(),
			this,
			UBulletDamage::StaticClass()
		);

		//UGameplayStatics::ApplyRadialDamage(
		//	GetWorld(),
		//	100.0f,
		//	OutHit.ImpactPoint,
		//	300.0f,
		//	UBulletDamage::StaticClass(),
		//	IgnoreActor,
		//	this,
		//	GetController()
		//);

		//UGameplayStatics::ApplyRadialDamageWithFalloff(
		//	GetWorld(),
		//	100.0f,
		//	10.0f,
		//	OutHit.ImpactPoint,
		//	300.0f,
		//	600.0f,
		//	10.0f,
		//	UBulletDamage::StaticClass(),
		//	IgnoreActor,
		//	this,
		//	GetController()
		//);
	}
}

void AMyCharacter::S2A_Dead_Implementation(const FVector& ImpulseDirection)
{
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->AddImpulse(ImpulseDirection * 100000.0f, FName(TEXT("head")));

	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		PC->DisableInput(PC);
	}
}



float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (DamageEvent.IsOfType(FPointDamageEvent::ClassID))
	{
		FPointDamageEvent* PointDamageEvent = (FPointDamageEvent*)&DamageEvent;
		if (PointDamageEvent->DamageTypeClass == UBulletDamage::StaticClass())
		{
			UE_LOG(LogTemp, Warning, TEXT("FPointDamageEvent %f %s"), DamageAmount, *PointDamageEvent->HitInfo.BoneName.ToString());

			if (PointDamageEvent->HitInfo.BoneName.ToString().Compare(TEXT("head")) == 0)
			{
				S2A_Dead(-PointDamageEvent->HitInfo.ImpactNormal);
			}
		}
	}
	else if (DamageEvent.IsOfType(FRadialDamageEvent::ClassID))
	{
		UE_LOG(LogTemp, Warning, TEXT("FRadialDamageEvent %f"), DamageAmount);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("DamageAmount %f"), DamageAmount);
	}

	

	return 0.0f;
}




