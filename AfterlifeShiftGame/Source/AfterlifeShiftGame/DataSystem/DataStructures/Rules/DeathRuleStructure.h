// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AfterlifeShiftGame/DataSystem/EnumIdentifiers/DeathIdentifier.h"
#include "DeathRuleStructure.generated.h"

USTRUCT(BlueprintType)
struct FDeathRuleStructure : public FTableRowBase
{
	GENERATED_BODY()
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	EDeathIdentifier Identifier;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPositiveRule;
};
