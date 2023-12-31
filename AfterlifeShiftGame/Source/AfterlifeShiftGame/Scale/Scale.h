﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "InputCoreModule.h"
#include "Scale.generated.h"

UCLASS()
class AFTERLIFESHIFTGAME_API AScale : public AActor
{
	GENERATED_BODY()

public:
	//Set the default values for this component's properties
	AScale();

protected:
	//Called when the game starts
	virtual void BeginPlay() override;

public:
	//Called every frame
	virtual void Tick(float DeltaTime) override;

/*
 *I doubt ill do it but im adding blueprint functionality in case we want to use it later
 */	
	UFUNCTION(BlueprintCallable)
	void AddWeightLeft(float Weight);

	UFUNCTION(BlueprintCallable)
	void AddWeightRight(float Weight);

UFUNCTION()
	void CheckForWeights();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float LeftWeight;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float RightWeight;

	UPROPERTY(VisibleAnywhere)
	UPrimitiveComponent* RootComp;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ScaleMesh;

	UPROPERTY(VisibleAnywhere, Category="Weight Trigger")
	UBoxComponent* LeftWeightTrigger;

	UPROPERTY(VisibleAnywhere, Category="Weight Trigger")
	UBoxComponent* RightWeightTrigger;

	UPROPERTY(EditAnywhere)
	float RotationMultiplier;
};
