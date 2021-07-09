// Copyright Epic Games, Inc. All Rights Reserved.


#include "AbstractionGameModeBase.h"

#include "Characters/Entities/Players/PlayerCharacter.h"
#include "Controllers/Entities/Players/DefaultPlayerController.h"

AAbstractionGameModeBase::AAbstractionGameModeBase()
{
	// use our custom CubePlayerController as default controller
	PlayerControllerClass = ADefaultPlayerController::StaticClass();

	// Use our custom CubeCharacter as default pawn
	DefaultPawnClass = APlayerCharacter::StaticClass();
}
