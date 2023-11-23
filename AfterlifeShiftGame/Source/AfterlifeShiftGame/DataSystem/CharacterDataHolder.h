// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterDataHolder.generated.h"

UCLASS(BlueprintType)
class AFTERLIFESHIFTGAME_API UCharacterDataHolder : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UCharacterDataHolder();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Table")
	UDataTable* DeathDataTable;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Table")
	UDataTable* ProfessionDataTable;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Table")
	UDataTable* MinorGoodDeedDataTable;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Table")
	UDataTable* MajorGoodDeedDataTable;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Table")
	UDataTable* MinorBadDeedDataTable;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Table")
	UDataTable* MajorBadDeedDataTable;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Table")
	UStringTable* NameStringTable;
};
