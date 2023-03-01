// Copyright Epic Games, Inc. All Rights Reserved.

#include "WareHouseGameMode.h"
#include "WareHouseCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "TimerManager.h"

AWareHouseGameMode::AWareHouseGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}