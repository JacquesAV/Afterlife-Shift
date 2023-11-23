// Copyright (c) 2023, Stinky Cheese, All rights reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EDeedIdentifier : uint8
{
	Undefined = 0,
	Volunteering,
	Lifesaving,
	Altruism,
	Organization,
	Violence,
	Infringement,
	Greed,
	Automobile,
	Encroachment,
	Impoliteness,
};
