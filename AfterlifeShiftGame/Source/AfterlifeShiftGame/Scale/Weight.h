// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Weight.generated.h"

UCLASS()
class AFTERLIFESHIFTGAME_API AWeight : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Pickup();

	UFUNCTION()
	void SetNewTargetLocation(const FVector& NewLocation);

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* WeightMesh;

	UPROPERTY(EditAnywhere)
	USphereComponent* WeightTrigger;

	UPROPERTY(EditAnywhere)
	float HeightWeightOffset;

	UPROPERTY(EditAnywhere)
	float Weight;
	
	bool holding;
	ACharacter* PlayerCharacter;
	UCameraComponent* PlayerCamera;

	FVector LocationToMoveTo;
};
