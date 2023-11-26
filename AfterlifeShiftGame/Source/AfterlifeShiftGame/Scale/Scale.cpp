// Fill out your copyright notice in the Description page of Project Settings.


#include "Scale.h"
#include "InputCoreModule.h"
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
	LeftWeightTrigger->SetRelativeLocation(FVector(-50.0f, 0.0f, 0.0f));
	LeftWeightTrigger->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));

	RightWeightTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("RightWeightTrigger"));
	RightWeightTrigger->SetupAttachment(ScaleMesh);
	RightWeightTrigger->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));
	RightWeightTrigger->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));

	RotationMultiplier = 10.0f;
}

void AScale::BeginPlay()
{
	Super::BeginPlay();

	/*//bind the FOOnLeftInput delegate to the AddWeightLeft function
	UEventManager* EventManager = UEventManager::GetInstance();
	if (EventManager)
	{
		EventManager->OnAddWeightLeft.AddUObject(this, &AScale::AddWeightLeft);
		//EventManager->OnAddWeightRight.AddDynamic(this, &AScale::AddWeightRight(5));
	}*/
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

/*void AScale::AddWeightRight(float Weight)
{
	RightWeight += Weight;
}*/
