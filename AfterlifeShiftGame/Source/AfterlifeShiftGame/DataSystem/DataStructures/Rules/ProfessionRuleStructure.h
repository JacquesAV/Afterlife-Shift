// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AfterlifeShiftGame/DataSystem/EnumIdentifiers/ProfessionIdentifier.h"
#include "ProfessionRuleStructure.generated.h"

USTRUCT(BlueprintType)
struct FProfessionRuleStructure : public FTableRowBase
{
	GENERATED_BODY()
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayText;
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	EProfessionIdentifier Identifier;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPositiveRule;
};
