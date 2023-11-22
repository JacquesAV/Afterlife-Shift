// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#include "DeathTestStruct.h"
#include "DataRulesGameManager.h"
#include "Engine/DataTable.h"

// Gets the display name of a given enum value.
template<typename TEnum>
static FString GetEnumValueDisplayName(TEnum EnumValue)
{
	if (const UEnum* Enum = StaticEnum<TEnum>())
	{
		return Enum->GetDisplayNameTextByValue(static_cast<int32>(EnumValue)).ToString();
	}
    
	return "Failed to fetch enum display name!";
}

// Sets default values.
ADataRulesGameManager::ADataRulesGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create and attach a default scene root component.
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	
	// Set the root component as the RootComponent of the actor.
	RootComponent = Root;
}

// Called when the game starts or when spawned.
void ADataRulesGameManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame.
void ADataRulesGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// TODO: Remove/Separate elements meant for the rule tables, as this debug is not actually for the death rule table, just testing.
void ADataRulesGameManager::DebugDeathDataTable() const
{
	UE_LOG(LogTemp, Display, TEXT("(1/2) Debugging the Death data table..."));
	
	//Make sure the data table holder is valid.
	if (!RuleDataTables)
	{
		UE_LOG(LogTemp, Error, TEXT("No rule data tables provided!"));
		return;
	}
	
	// Make sure the data table is valid.
	if (!RuleDataTables->DeathRuleDataTable)
	{
		UE_LOG(LogTemp, Error, TEXT("Data table is not valid!"));
		return;
	}
	
	// Make sure the data table is using the correct type of struct.
	if(RuleDataTables->DeathRuleDataTable->RowStruct != FDeathTestStruct::StaticStruct())
	{
		UE_LOG(LogTemp, Error, TEXT("Data table is not using the correct type of struct!"));
		return;
	}
	
	// Make sure that the data table has at least one row.
	if (RuleDataTables->DeathRuleDataTable->GetRowNames().Num() <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Data table has no data!"));
		return;
	}
	
	// Iterate over the death data table and print out the name and identifier of each row.
	const TArray<FName> DeathRuleDataTableRowNames = RuleDataTables->DeathRuleDataTable->GetRowNames();
	for (int32 i = 0; i < DeathRuleDataTableRowNames.Num(); i++)
	{
		// Get the row name & row data.
		const FName RowName = DeathRuleDataTableRowNames[i];
		FDeathTestStruct* RowData = RuleDataTables->DeathRuleDataTable->FindRow<FDeathTestStruct>(RowName, FString(""));
		
		// Make sure the row data is valid, otherwise throw an error with the row name.
		if (!RowData)
		{
			UE_LOG(LogTemp, Error, TEXT("Row data is not valid! Row Name: %s"), *RowName.ToString());
			continue;
		}
		
		// Print the row index, name and identifier.
		UE_LOG(LogTemp, Display, TEXT("Row Index: %d, Name: %s, Identifier: %s (%d)"),
			i, *RowData->Name, *GetEnumValueDisplayName(RowData->Identifier), (uint8)RowData->Identifier);
	}
	
	UE_LOG(LogTemp, Display, TEXT("(2/2) Finished Debugging the Death data table!"));
}
