// Fill out your copyright notice in the Description page of Project Settings.


#include "Rocket.h"
#include"Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"
#include"GameFramework/ProjectileMovementComponent.h"

// Sets default values
ARocket::ARocket()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Box->SetGenerateOverlapEvents(true);
	Box->SetCollisionProfileName(TEXT("OverlapAll"));
	Box->OnComponentBeginOverlap.AddDynamic(this, &ARocket::OnBoxBeginOverlap);


	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Rocket(TEXT("/Script/Engine.StaticMesh'/Game/P38/Meshes/SM_Rocket.SM_Rocket'"));

	if (SM_Rocket.Succeeded())
	{
		Body->SetStaticMesh(SM_Rocket.Object);
	}

	Body->SetRelativeRotation(FRotator(-90, 0, 0));


	ProjectileMovement->MaxSpeed = 2000.0f;
	ProjectileMovement->InitialSpeed = 2000.0f;

	Box->SetSimulatePhysics(false);
}


// Called when the game starts or when spawned
void ARocket::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(3);
	
}

// Called every frame
void ARocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ARocket::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		UE_LOG(LogTemp, Warning, TEXT("Rocket overlapped with: %s"), *OtherActor->GetName());

		if (!OtherActor->ActorHasTag(TEXT("Player")))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, OtherActor->GetName());
		}

		// ¿¹½Ã: Æø¹ß Ã³¸®, ÆÄ±« µî
		Destroy();
	}
}
