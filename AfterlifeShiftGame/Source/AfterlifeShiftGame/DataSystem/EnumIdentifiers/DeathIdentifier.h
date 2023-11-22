// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EDeathIdentifier : uint8
{
	Undefined = 0,
	Natural,
	Supernatural,
	Misadventure,
	Accident,
	Homicide,
};
