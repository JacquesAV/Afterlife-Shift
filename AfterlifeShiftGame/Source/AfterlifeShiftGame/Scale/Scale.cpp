// Fill out your copyright notice in the Description page of Project Settings.


#include "Scale.h"
#include "InputCoreModule.h"
#include "Weight.h"
#include "AfterlifeShiftGame/EventManager/EventManager.h"
#include "GameFramework/PlayerInput.h"

//DECLARE_MULTICAST_DELEGATE_OneParam(FOnLeftInput, float);

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

	LeftWeightTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftWeightTrigger"));
	LeftWeightTrigger->SetupAttachment(ScaleMesh);
	LeftWeightTrigger->SetRelativeLocation(FVector(0.0f, -55.0f, 0.0f));
	LeftWeightTrigger->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));

	RightWeightTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("RightWeightTrigger"));
	RightWeightTrigger->SetupAttachment(ScaleMesh);
	RightWeightTrigger->SetRelativeLocation(FVector(0.0f, 55.0f, 0.0f));
	RightWeightTrigger->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));

	RotationMultiplier = 10.0f;
}

void AScale::BeginPlay()
{
	Super::BeginPlay();
}

void AScale::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckForWeights();
}

void AScale::AddWeightLeft(float Weight)
{
	LeftWeight += Weight;
}

void AScale::AddWeightRight(float Weight)
{
	RightWeight += Weight;
}

void AScale::CheckForWeights()
{
	//Check how many weights are on the leftweighttrigger
	LeftWeight=0;
	TArray<AActor*> LeftWeightActors;
	LeftWeightTrigger->GetOverlappingActors(LeftWeightActors);
	//check if there are any weights on the leftweighttrigger and add their weight together
	for (auto LeftWeightActor : LeftWeightActors)
	{		
		AWeight* Weight = Cast<AWeight>(LeftWeightActor);
		if (Weight)
		{
			LeftWeight += Weight->Weight;
		}
	}

	//Check how many weights are on the rightweighttrigger
	RightWeight = 0;
	TArray<AActor*> RightWeightActors;
	RightWeightTrigger->GetOverlappingActors(RightWeightActors);
	//check if there are any weights on the rightweighttrigger and add their weight together
	for (auto RightWeightActor : RightWeightActors)
	{
		AWeight* Weight = Cast<AWeight>(RightWeightActor);
		if (Weight)
		{
			RightWeight += Weight->Weight;
		}
	}
	
	float WeightDifference = LeftWeight - RightWeight;

	// Calculate the rotation angle based on the total weight
	float RotationAngle = WeightDifference * RotationMultiplier;

	//get the current rotation
	FRotator CurrentRotation = ScaleMesh->GetRelativeRotation();
	
	// Create a new rotation from the rotation angle
	FRotator NewRotation = FRotator(CurrentRotation.Pitch, CurrentRotation.Yaw, RotationAngle);
	// Apply the rotation to the ScaleMesh component
	ScaleMesh->SetRelativeRotation(NewRotation);
}
