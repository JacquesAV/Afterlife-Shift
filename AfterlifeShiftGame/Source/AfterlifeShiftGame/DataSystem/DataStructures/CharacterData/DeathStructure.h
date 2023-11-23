// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AfterlifeShiftGame/DataSystem/EnumIdentifiers/DeathIdentifier.h"
#include "DeathStructure.generated.h"

USTRUCT(BlueprintType)
struct FDeathStructure : public FTableRowBase
{
	GENERATED_BODY()
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayText;
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	EDeathIdentifier Identifier;
};
