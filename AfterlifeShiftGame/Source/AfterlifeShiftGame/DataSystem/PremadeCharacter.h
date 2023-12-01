// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataStructures/CharacterData/CharacterDataPaired.h"
#include "PremadeCharacter.generated.h"

// TODO: This is a temporary character asset to test the data system. Should likely be removed once the data system is fully implemented.
UCLASS(BlueprintType)
class AFTERLIFESHIFTGAME_API UPremadeCharacter : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPremadeCharacter();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data")
	FCharacterDataPaired PairedData;
};
