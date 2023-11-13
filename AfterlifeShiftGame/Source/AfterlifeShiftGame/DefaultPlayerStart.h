// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DefaultPlayerStart.generated.h"

UCLASS()
class AFTERLIFESHIFTGAME_API ADefaultPlayerStart : public AActor
{
	GENERATED_BODY()
	
public:
	// Constructor.
	ADefaultPlayerStart();

protected:
	// BeginPlay.
	virtual void BeginPlay() override;

};
