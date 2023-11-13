// Copyright (c) 2023, Stinky Cheese, All rights reserved.


#include "DefaultPlayerStart.h"

// Sets default values
ADefaultPlayerStart::ADefaultPlayerStart()
{
	PrimaryActorTick.bCanEverTick = false;

	//create root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
}

// Called when the game starts or when spawned
void ADefaultPlayerStart::BeginPlay()
{
	Super::BeginPlay();

	// Spawn the player at the player start location.
	GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(GetActorLocation());
}

