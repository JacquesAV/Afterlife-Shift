// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#include "DataStructures/CharacterData/DeathStructure.h"
#include "DataStructures/CharacterData/ProfessionStructure.h"
#include "DataStructures/CharacterData/DeedStructure.h"
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

#pragma region Debugging
template<typename TExpectedStruct>
bool IsDataTableValid(const UDataTable* DataTable)
{
	// Make sure the data table is valid.
	if (!DataTable)
	{
		UE_LOG(LogTemp, Error, TEXT("Data table is not valid!"));
		return false;
	}
	
	// Make sure the data table is using the correct type of struct.
	if(DataTable->RowStruct != TExpectedStruct::StaticStruct())
	{
		UE_LOG(LogTemp, Error, TEXT("Data table is not using the correct type of struct!"));
		UE_LOG(LogTemp, Display, TEXT("Used Struct: %s"), *DataTable->RowStruct->GetName());
		UE_LOG(LogTemp, Display, TEXT("Expected Struct: %s"), *TExpectedStruct::StaticStruct()->GetName());
		return false;
	}
	
	// Make sure that the data table has at least one row.
	if (DataTable->GetRowNames().Num() <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Data table has no data!"));
		return false;
	}
	
	return true;
}

template<typename TExpectedStruct>
bool ADataRulesGameManager::IsRowValid(const FName RowName, TExpectedStruct* RowData)
{
	// Make sure the row data is valid, otherwise throw an error with the row name.
	if (!RowData)
	{
		UE_LOG(LogTemp, Error, TEXT("Row data is not valid! Row Name: %s"), *RowName.ToString());
		return true;
	}
	return false;
}

#pragma region Character Data Debugging
bool ADataRulesGameManager::IsCharacterDataTablesValid() const
{
	//Make sure the data table holder is valid.
	if (!CharacterDataTables)
	{
		UE_LOG(LogTemp, Error, TEXT("No character data tables provided!"));
		return false;
	}
	return true;
}

void ADataRulesGameManager::DebugDeathDataTable() const
{
	UE_LOG(LogTemp, Display, TEXT("(1/2) Debugging the Death data table..."));
	
	// Check for valid data before iterating.
	if (!IsCharacterDataTablesValid()) return;
	if (!IsDataTableValid<FDeathStructure>(CharacterDataTables->DeathDataTable)) return;
	
	// Iterate over the data table and print out the name and identifier of each row.
	const TArray<FName> RowNames = CharacterDataTables->DeathDataTable->GetRowNames();
	for (int32 i = 0; i < RowNames.Num(); i++)
	{
		// Get the row name & row data.
		const FName RowName = RowNames[i];
		FDeathStructure* RowData = CharacterDataTables->DeathDataTable->FindRow<FDeathStructure>(RowName, FString(""));
		
		// Make sure the row data is valid.
		if (IsRowValid(RowName, RowData)) continue;
		
		// Print the row index, name and identifier.
		UE_LOG(LogTemp, Display, TEXT("Row Index: %d, Name: %s, Identifier: %s (%d)"),
			i, *RowData->DisplayText, *GetEnumValueDisplayName(RowData->Identifier), (uint8)RowData->Identifier);
	}
	
	UE_LOG(LogTemp, Display, TEXT("(2/2) Finished Debugging the Death data table!"));
}

void ADataRulesGameManager::DebugProfessionDataTable() const
{
	UE_LOG(LogTemp, Display, TEXT("(1/2) Debugging the Profession data table..."));
	
	// Check for valid data before iterating.
	if (!IsCharacterDataTablesValid()) return;
	if (!IsDataTableValid<FProfessionStructure>(CharacterDataTables->ProfessionDataTable)) return;
	
	// Iterate over the data table and print out the name and identifier of each row.
	const TArray<FName> RowNames = CharacterDataTables->ProfessionDataTable->GetRowNames();
	for (int32 i = 0; i < RowNames.Num(); i++)
	{
		// Get the row name & row data.
		const FName RowName = RowNames[i];
		FProfessionStructure* RowData = CharacterDataTables->ProfessionDataTable->FindRow<FProfessionStructure>(RowName, FString(""));

		// Make sure the row data is valid.
		if (IsRowValid(RowName, RowData)) continue;
		
		// Print the row index, name and identifier.
		UE_LOG(LogTemp, Display, TEXT("Row Index: %d, Name: %s, Identifier: %s (%d)"),
			i, *RowData->DisplayText, *GetEnumValueDisplayName(RowData->Identifier), (uint8)RowData->Identifier);
	}
	
	UE_LOG(LogTemp, Display, TEXT("(2/2) Finished Debugging the Profession data table!"));
}

void ADataRulesGameManager::DebugMinorGoodDeedDataTable() const
{
	UE_LOG(LogTemp, Display, TEXT("(1/2) Debugging the MinorGoodDeed data table..."));
	
	// Check for valid data before iterating.
	if (!IsCharacterDataTablesValid()) return;
	if (!IsDataTableValid<FDeedStructure>(CharacterDataTables->MinorGoodDeedDataTable)) return;
	
	// Iterate over the data table and print out the name and identifier of each row.
	const TArray<FName> RowNames = CharacterDataTables->MinorGoodDeedDataTable->GetRowNames();
	for (int32 i = 0; i < RowNames.Num(); i++)
	{
		// Get the row name & row data.
		const FName RowName = RowNames[i];
		const FDeedStructure* RowData = CharacterDataTables->MinorGoodDeedDataTable->FindRow<FDeedStructure>(RowName, FString(""));
		
		// Make sure the row data is valid.
		if (IsRowValid(RowName, RowData)) continue;
		
		// Print the row index, name and identifier.
		// TODO: Implement proper identifier printing.
		UE_LOG(LogTemp, Display, TEXT("Row Index: %d, Name: %s, Identifier Count: %d"),
			i, *RowData->DisplayText, RowData->Identifier.Num());
	}
	
	UE_LOG(LogTemp, Display, TEXT("(2/2) Finished Debugging the MinorGoodDeed data table!"));
}

void ADataRulesGameManager::DebugMinorBadDeedDataTable() const
{
	UE_LOG(LogTemp, Display, TEXT("(1/2) Debugging the MinorBadDeed data table..."));
	
	// Check for valid data before iterating.
	if (!IsCharacterDataTablesValid()) return;
	if (!IsDataTableValid<FDeedStructure>(CharacterDataTables->MinorBadDeedDataTable)) return;
	
	// Iterate over the data table and print out the name and identifier of each row.
	const TArray<FName> RowNames = CharacterDataTables->MinorBadDeedDataTable->GetRowNames();
	for (int32 i = 0; i < RowNames.Num(); i++)
	{
		// Get the row name & row data.
		const FName RowName = RowNames[i];
		const FDeedStructure* RowData = CharacterDataTables->MinorBadDeedDataTable->FindRow<FDeedStructure>(RowName, FString(""));
		
		// Make sure the row data is valid.
		if (IsRowValid(RowName, RowData)) continue;
		
		// Print the row index, name and identifier.
		// TODO: Implement proper identifier printing.
		UE_LOG(LogTemp, Display, TEXT("Row Index: %d, Name: %s, Identifier Count: %d"),
			i, *RowData->DisplayText, RowData->Identifier.Num());
	}
	
	UE_LOG(LogTemp, Display, TEXT("(2/2) Finished Debugging the MinorBadDeed data table!"));
}

void ADataRulesGameManager::DebugMajorBadDeedDataTable() const
{
	UE_LOG(LogTemp, Display, TEXT("(1/2) Debugging the MajorBadDeed data table..."));
	
	// Check for valid data before iterating.
	if (!IsCharacterDataTablesValid()) return;
	if (!IsDataTableValid<FDeedStructure>(CharacterDataTables->MajorBadDeedDataTable)) return;
	
	// Iterate over the data table and print out the name and identifier of each row.
	const TArray<FName> RowNames = CharacterDataTables->MajorBadDeedDataTable->GetRowNames();
	for (int32 i = 0; i < RowNames.Num(); i++)
	{
		// Get the row name & row data.
		const FName RowName = RowNames[i];
		const FDeedStructure* RowData = CharacterDataTables->MajorBadDeedDataTable->FindRow<FDeedStructure>(RowName, FString(""));
		
		// Make sure the row data is valid.
		if (IsRowValid(RowName, RowData)) continue;
		
		// Print the row index, name and identifier.
		// TODO: Implement proper identifier printing.
		UE_LOG(LogTemp, Display, TEXT("Row Index: %d, Name: %s, Identifier Count: %d"),
			i, *RowData->DisplayText, RowData->Identifier.Num());
	}
	
	UE_LOG(LogTemp, Display, TEXT("(2/2) Finished Debugging the MajorBadDeed data table!"));
}

void ADataRulesGameManager::DebugMajorGoodDeedDataTable() const
{
	UE_LOG(LogTemp, Display, TEXT("(1/2) Debugging the MajorGoodDeed data table..."));
	
	// Check for valid data before iterating.
	if (!IsCharacterDataTablesValid()) return;
	if (!IsDataTableValid<FDeedStructure>(CharacterDataTables->MajorGoodDeedDataTable)) return;
	
	// Iterate over the data table and print out the name and identifier of each row.
	const TArray<FName> RowNames = CharacterDataTables->MajorGoodDeedDataTable->GetRowNames();
	for (int32 i = 0; i < RowNames.Num(); i++)
	{
		// Get the row name & row data.
		const FName RowName = RowNames[i];
		const FDeedStructure* RowData = CharacterDataTables->MajorGoodDeedDataTable->FindRow<FDeedStructure>(RowName, FString(""));
		
		// Make sure the row data is valid.
		if (IsRowValid(RowName, RowData)) continue;
		
		// Print the row index, name and identifier.
		// TODO: Implement proper identifier printing.
		UE_LOG(LogTemp, Display, TEXT("Row Index: %d, Name: %s, Identifier Count: %d"),
			i, *RowData->DisplayText, RowData->Identifier.Num());
	}
	
	UE_LOG(LogTemp, Display, TEXT("(2/2) Finished Debugging the MajorGoodDeed data table!"));
}
#pragma endregion Character Data Debugging
#pragma region Ruleset Data Debugging
// TODO: Implement ruleset data debugging.
#pragma endregion Ruleset Data Debugging
#pragma endregion Debugging
