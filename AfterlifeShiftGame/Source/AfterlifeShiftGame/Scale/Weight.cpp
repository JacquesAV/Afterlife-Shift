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

	WeightTrigger = CreateDefaultSubobject<USphereComponent>("WeightTrigger");
	WeightTrigger->SetupAttachment(WeightMesh);
	WeightTrigger->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	WeightTrigger->SetSphereRadius(100.f);
	WeightTrigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	//enable overlap events
	WeightMesh->SetGenerateOverlapEvents(true);

	holding = false;
	Weight = 1.f;
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
		//move to location to move to
		this->SetActorLocation(FMath::VInterpTo(this->GetActorLocation(), LocationToMoveTo, DeltaTime, 10.f));
	}
}

void AWeight::Pickup()
{
	holding = !holding;

	WeightMesh->SetCollisionEnabled(holding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);
}

void AWeight::SetNewTargetLocation(const FVector& NewLocation)
{
	LocationToMoveTo.Z += this->GetActorLocation().Z;
	LocationToMoveTo = NewLocation;
}
