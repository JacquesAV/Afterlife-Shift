// Copyright (c) 2023, Stinky Cheese, All rights reserved.


#include "ClockComponent.h"


// Sets default values for this component's properties
UClockComponent::UClockComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Initialize variables
	CurrentTimeInHours = 0.0f;
	TimeMultiplier = 0.01666f;  // Set to the following value so that 1 minute=1 hour in game
}


// Called when the game starts
void UClockComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UClockComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Update the current time based on the time multiplier
	CurrentTimeInHours += DeltaTime * TimeMultiplier;

	// Normalize the time to a 24-hour cycle
	if (CurrentTimeInHours >= 24.0f)
	{
		CurrentTimeInHours = FMath::Fmod(CurrentTimeInHours, 24.0f);
	}
}

// Set the time multiplier
void UClockComponent::SetTimeMultiplier(float Multiplier)
{
	TimeMultiplier = FMath::Max(Multiplier, 0.1f);  // Ensure the multiplier is non-negative
}

// Get the current time
float UClockComponent::GetCurrentTime() const
{
	return CurrentTimeInHours;
}

