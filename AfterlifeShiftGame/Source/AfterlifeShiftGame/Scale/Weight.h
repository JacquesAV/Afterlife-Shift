// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
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

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* WeightMesh;

	UPROPERTY(EditAnywhere)
	float HeightWeightOffset;
	
	bool holding;
	ACharacter* PlayerCharacter;
	UCameraComponent* PlayerCamera;
};
