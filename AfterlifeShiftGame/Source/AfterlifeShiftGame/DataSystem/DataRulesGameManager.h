// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterDataHolder.h"
#include "RulesetHolder.h"
#include "GameFramework/Actor.h"
#include "DataRulesGameManager.generated.h"

UCLASS()
class AFTERLIFESHIFTGAME_API ADataRulesGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties.
	ADataRulesGameManager();
	
protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;
	
	// Debugs the current rule data tables.
	UFUNCTION(CallInEditor, Category = "Debugging Character Data")
	void DebugDeathDataTable() const;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Reference to the root component of the actor.
	UPROPERTY()
	USceneComponent* Root;
	
	// Asset holders for game related data tables.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Set Holders")
	URulesetHolder* RulesetTables;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Set Holders")
	UCharacterDataHolder* CharacterDataTables;
};
