// Fill out your copyright notice in the Description page of Project Settings.


#include "Scale.h"
#include "InputCoreModule.h"
#include "GameFramework/PlayerInput.h"


// Sets default values
AScale::AScale()
{
	PrimaryActorTick.bCanEverTick = true;
	//Set default values for this component's properties
	LeftWeight = 0.0f;
	RightWeight = 0.0f;

	RootComp = CreateDefaultSubobject<UPrimitiveComponent>(TEXT("RootComponent"));
	RootComponent = RootComp;

	ScaleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScaleMesh"));
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

	//lerp the rotation between current and target
	FRotator TargetRotation = FRotator(0.0f, 0.0f, RotationAngle);
	FRotator CurrentRotation = ScaleMesh->GetRelativeRotation();
	FRotator NewRotation = FMath::Lerp(CurrentRotation, TargetRotation, DeltaTime);

	// Apply the rotation to the ScaleMesh component
	ScaleMesh->SetRelativeRotation(NewRotation);
}

void AScale::AddWeightLeft(float Weight)
{
	LeftWeight += Weight;
}

void AScale::AddWeightRight(float Weight)
{
	RightWeight += Weight;
}

void AScale::OnLeftInput()
{
	AddWeightLeft(5.0f);
}

void AScale::OnRightInput()
{
	AddWeightRight(5.0f);
}
