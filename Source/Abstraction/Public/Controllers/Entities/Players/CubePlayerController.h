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
	UPROPERTY(EditAnywhere)
	AActor* actor;

	// Overriding the default input setup
	virtual void SetupInputComponent() override;
	
protected:
	// Used by BindAction must use 0 parameters
	UFUNCTION()
	void OnLeftClick();
	
	UFUNCTION()
	void OnAxisInputTurn(float value);

	UFUNCTION()
	void OnAxisInputLookUp(float value);

	UFUNCTION()
	void OnAxisInputMoveRight(float value);

	UFUNCTION()
	void OnAxisInputMoveForward(float value);
};
