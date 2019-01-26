// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"



#define Print(String,Time, Color); GEngine->AddOnScreenDebugMessage(-1, Time, Color,String);
#define RED		FColor::Red
#define BLUE	FColor::Blue
#define GREEN	FColor::Green
#define YELLOW	FColor::Yellow




UENUM(BlueprintType)
enum class EDirectionMovement : uint8 {
	NONE,
	UP,
	UPRIGHT,
	RIGHT,
	DOWNRIGHT,
	DOWN,
	DOWNLEFT,
	LEFT,
	UPLEFT
};


DECLARE_LOG_CATEGORY_EXTERN(LogKHAGANDOVOY, Log, All);
