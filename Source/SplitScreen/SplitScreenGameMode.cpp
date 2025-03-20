// Copyright Epic Games, Inc. All Rights Reserved.

#include "SplitScreenGameMode.h"

#include "CustomGameState.h"
#include "UObject/ConstructorHelpers.h"

ASplitScreenGameMode::ASplitScreenGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
