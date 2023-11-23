// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AfterlifeShiftGame/DataSystem/EnumIdentifiers/DeedIdentifier.h"
#include "DeedRuleStructure.generated.h"

USTRUCT(BlueprintType)
struct FDeedRuleStructure : public FTableRowBase
{
	GENERATED_BODY()
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayText;
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDeedIdentifier Identifier;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPositiveRule;
};
