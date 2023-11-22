#pragma once

#include "Engine/DataTable.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DeathTestStruct.generated.h"

UENUM(BlueprintType)
enum class EDeathTestIdentifier : uint8
{
	Undefined = 0,
	Natural,
	Supernatural,
	Misadventure,
	Accident,
	Homicide,
};

USTRUCT(BlueprintType)
struct FDeathTestStruct : public FTableRowBase
{
	GENERATED_BODY()
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	EDeathTestIdentifier Identifier;
};
