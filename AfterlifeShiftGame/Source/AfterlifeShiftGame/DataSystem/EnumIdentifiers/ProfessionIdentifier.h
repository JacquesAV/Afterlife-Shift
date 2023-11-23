// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EProfessionIdentifier : uint8
{
	Undefined = 0,
	Social,
	Creative,
	Medical,
	Physical,
	Mathematical,
};
