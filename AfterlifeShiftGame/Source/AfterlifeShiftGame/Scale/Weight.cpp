// Copyright (c) 2023, Stinky Cheese, All rights reserved.


#include "Weight.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AWeight::AWeight()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");

	WeightMesh = CreateDefaultSubobject<UStaticMeshComponent>("WeightMesh");
	WeightMesh->SetupAttachment(RootComponent);

	holding = false;
}

// Called when the game starts or when spawned
void AWeight::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	PlayerCamera = PlayerCharacter->FindComponentByClass<UCameraComponent>();

	TArray<USceneComponent*> Components;

	PlayerCharacter->GetComponents(Components);
}

// Called every frame
void AWeight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (holding)
	{
		//raycast from the mouse cursor to the ground
		FHitResult HitResult;
		FVector StartLocation = PlayerCamera->GetComponentLocation();
		FVector EndLocation = StartLocation + PlayerCamera->GetForwardVector() * 1000.f;
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
		TraceParams.AddIgnoredActor(PlayerCharacter);

		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, TraceParams))
		{
			//move the weight to the hit location
			FVector NewLocation = HitResult.Location;
			NewLocation.Z += HeightWeightOffset;
			SetActorLocation(NewLocation);
		}
	}
}

void AWeight::Pickup()
{
	holding = !holding;

	WeightMesh->SetCollisionEnabled(holding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);
}
