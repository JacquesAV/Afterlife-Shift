// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RulesetHolder.generated.h"

UCLASS(BlueprintType)
class AFTERLIFESHIFTGAME_API URulesetHolder : public UDataAsset
{
	GENERATED_BODY()
	
public:
	URulesetHolder();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Rules")
	UDataTable* DeathRuleDataTable;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Rules")
	UDataTable* ProfessionRuleDataTable;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Rules")
	UDataTable* DeedRuleDataTable;
};
