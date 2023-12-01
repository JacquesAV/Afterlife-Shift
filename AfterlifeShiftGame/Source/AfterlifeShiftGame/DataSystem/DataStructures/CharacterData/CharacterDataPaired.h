// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeathStructure.h"
#include "ProfessionStructure.h"
#include "DeedStructure.h"

USTRUCT(BlueprintType)
struct FCharacterDataPaired
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data")
	FString Name;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data")
	FDeathStructure CauseOfDeath;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data")
	FProfessionStructure Profession;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data")
	TArray<FDeedStructure> Deeds;
};
