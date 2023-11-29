// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ClockComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AFTERLIFESHIFTGAME_API UClockComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UClockComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	//Time functionality
	UFUNCTION(BlueprintCallable, Category="Clock")
	void SetTimeMultiplier(float Multiplier);

	UFUNCTION(BlueprintCallable, Category="Clock")
	float GetCurrentTime() const;

private:
	UPROPERTY(EditAnywhere, Category="Clock")
	float CurrentTimeInHours;

	UPROPERTY(EditAnywhere, Category="Clock")
	float TimeMultiplier;
};
