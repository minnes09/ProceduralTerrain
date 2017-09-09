// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ProceduralGame.h"
#include "ProceduralGameGameMode.h"
#include "ProceduralGameHUD.h"
#include "ProceduralGameCharacter.h"

AProceduralGameGameMode::AProceduralGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProceduralGameHUD::StaticClass();
}
