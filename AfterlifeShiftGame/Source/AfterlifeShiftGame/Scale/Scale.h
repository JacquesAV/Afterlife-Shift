// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scale.generated.h"

UCLASS()
class UScale : public UActorComponent
{
	GENERATED_BODY()

public:
	//Set the default values for this component's properties
	UScale();

protected:
	//Called when the game starts
	virtual void BeginPlay() override;

public:
	//Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

/*
 *I doubt ill do it but im adding blueprint functionality in case we want to use it later
 */
	
	UFUNCTION(BlueprintCallable)
	void AddWeightLeft(float Weight);

	UFUNCTION(BlueprintCallable)
	void AddWeightRight(float Weight);

	UFUNCTION(BlueprintCallable)
	void OnLeftInput();

	UFUNCTION(BlueprintCallable)
	void OnRightInput();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float LeftWeight;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float RightWeight;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USceneComponent* ScaleMesh;

	UPROPERTY(EditAnywhere)
	float RotationMultiplier;
};
