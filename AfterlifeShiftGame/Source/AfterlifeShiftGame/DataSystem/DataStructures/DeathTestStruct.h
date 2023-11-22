// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AfterlifeShiftGame/DataSystem/EnumIdentifiers/DeathIdentifier.h"
#include "DeathTestStruct.generated.h"

USTRUCT(BlueprintType)
struct FDeathTestStruct : public FTableRowBase
{
	GENERATED_BODY()
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	EDeathIdentifier Identifier;
};
