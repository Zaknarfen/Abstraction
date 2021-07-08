// Copyright Epic Games, Inc. All Rights Reserved.


#include "AbstractionGameModeBase.h"

#include "Characters/Entities/Players/CubeCharacter.h"
#include "Controllers/Entities/Players/CubePlayerController.h"

AAbstractionGameModeBase::AAbstractionGameModeBase()
{
	// use our custom CubePlayerController as default controller
	PlayerControllerClass = ACubePlayerController::StaticClass();

	// Use our custom CubeCharacter as default pawn
	DefaultPawnClass = ACubeCharacter::StaticClass();
}
