// Fill out your copyright notice in the Description page of Project Settings.


#include "Scale.h"


// Sets default values
AScale::AScale()
{
	PrimaryActorTick.bCanEverTick = true;
	//Set default values for this component's properties
	LeftWeight = 0.0f;
	RightWeight = 0.0f;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX Comp"));
	BoxComp->InitBoxExtent(FVector(150, 100, 100));
	BoxComp->SetCollisionProfileName("Trigger");
	RootComponent = BoxComp;
	
	ScaleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScaleMesh"));
	ScaleMesh->SetRelativeLocation(FVector(0.0f, 50.0f, -100.0f));
	ScaleMesh->SetWorldScale3D(FVector(1.0f));
	ScaleMesh->SetupAttachment(RootComponent);
	
	RotationMultiplier = 10.0f;
}

void AScale::BeginPlay()
{
	Super::BeginPlay();
}

void AScale::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float TotalWeight = LeftWeight + RightWeight;

	// Calculate the rotation angle based on the total weight
	float RotationAngle = TotalWeight * RotationMultiplier;

	AddWeightLeft(0.01f);
	//log the rotation angle
	UE_LOG(LogTemp, Warning, TEXT("Rotation Angle: %f"), RotationAngle);

	// Apply the rotation to the ScaleMesh component
	ScaleMesh->SetRelativeRotation(FRotator(0.0f, RotationAngle, 0.0f));
}

void AScale :: AddWeightLeft(float Weight)
{
	LeftWeight += Weight;
}

void AScale :: AddWeightRight(float Weight)
{
	RightWeight += Weight;
}

void AScale :: OnLeftInput()
{
	AddWeightLeft(1.0f);
}

void AScale :: OnRightInput()
{
	AddWeightRight(1.0f);
}