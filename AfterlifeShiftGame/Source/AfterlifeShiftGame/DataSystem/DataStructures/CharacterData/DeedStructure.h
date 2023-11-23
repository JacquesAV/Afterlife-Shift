// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AfterlifeShiftGame/DataSystem/EnumIdentifiers/DeedIdentifier.h"
#include "DeedStructure.generated.h"

USTRUCT(BlueprintType)
struct FDeedStructure : public FTableRowBase
{
	GENERATED_BODY()
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayText;
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<EDeedIdentifier> Identifier;
};
