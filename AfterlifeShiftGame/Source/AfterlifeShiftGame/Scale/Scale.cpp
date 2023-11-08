// Fill out your copyright notice in the Description page of Project Settings.


#include "Scale.h"


// Sets default values
UScale::UScale()
{
	//Set default values for this component's properties
	LeftWeight = 0.0f;
	RightWeight = 0.0f;
	ScaleMesh = nullptr;
	RotationMultiplier = 10.0f;
}

void UScale::BeginPlay()
{
	Super::BeginPlay();

	ScaleMesh = GetOwner()->GetRootComponent();
}

void UScale::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	float TotalWeight = LeftWeight + RightWeight;

	// Calculate the rotation angle based on the total weight
	float RotationAngle = TotalWeight * RotationMultiplier;

	// Apply the rotation to the ScaleMesh component
	ScaleMesh->SetRelativeRotation(FRotator(0.0f, RotationAngle, 0.0f));
}

void UScale :: AddWeightLeft(float Weight)
{
	LeftWeight += Weight;
}

void UScale :: AddWeightRight(float Weight)
{
	RightWeight += Weight;
}

void UScale :: OnLeftInput()
{
	AddWeightLeft(1.0f);
}

void UScale :: OnRightInput()
{
	AddWeightRight(1.0f);
}