// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "KHAGANDOVOYGameMode.h"
#include "KHAGANDOVOYPlayerController.h"
#include "KHAGANDOVOYCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKHAGANDOVOYGameMode::AKHAGANDOVOYGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AKHAGANDOVOYPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}