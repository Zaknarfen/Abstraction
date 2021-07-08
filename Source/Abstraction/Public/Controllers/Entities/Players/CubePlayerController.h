// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CubePlayerController.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(CustomController), meta=(BlueprintSpawnableComponent) )
class ABSTRACTION_API ACubePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACubePlayerController();

protected:
	// Overriding the default input setup
	virtual void SetupInputComponent() override;
	
	// Called every frame
    virtual void PlayerTick(float DeltaTime) override;
	
	uint32 bMoveToMouseCursor : 1;
	
	// Used by BindAction must use 0 parameters
	void OnLeftClick();
	void OnLeftClickUp();

	void MovePlayer();
};
