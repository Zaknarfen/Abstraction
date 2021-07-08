// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllers/Entities/Players/CubePlayerController.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/Pawn.h"

void ACubePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Actions
	InputComponent->BindAction("LeftClick", IE_Pressed, this, &ACubePlayerController::OnLeftClick);
	InputComponent->BindAction("LeftClick", IE_MAX, this, &ACubePlayerController::OnLeftClick);

	// Axes
	InputComponent->BindAxis("LookUp", this, &ACubePlayerController::OnAxisInputLookUp);
	InputComponent->BindAxis("MoveRight", this, &ACubePlayerController::OnAxisInputMoveRight);
	InputComponent->BindAxis("MoveForward", this, &ACubePlayerController::OnAxisInputMoveForward);

	// So we can see the cursor and have mouse events
	bShowMouseCursor = true; 
	bEnableClickEvents = true; 
	bEnableMouseOverEvents = true;
}

void ACubePlayerController::OnLeftClick()
{
	UE_LOG(LogTemp, Display, TEXT("Left Click"));
	float mouseX;
	float mouseY;
	GetMousePosition(mouseX, mouseY);

	UE_LOG(LogTemp, Display, TEXT("mouseX, %.2f"), mouseX);
	UE_LOG(LogTemp, Display, TEXT("mouseY, %.2f"), mouseY);

	// Raycast to any static mesh
	FHitResult HitOut = FHitResult(ForceInit);
	GetHitResultUnderCursor(ECC_WorldStatic, true, HitOut);

	UE_LOG(LogTemp, Display, TEXT("--------------------------------"));
	UE_LOG(LogTemp, Display, TEXT("hit, %.2f, %.2f, %.2f"), HitOut.Location.X, HitOut.Location.Y, HitOut.Location.Z);
	
	APawn* CubePawn = GetPawn();
	UE_LOG(LogTemp, Display, TEXT("--------------------------------"));
	UE_LOG(LogTemp, Display, TEXT("pawn, %.2f, %.2f, %.2f"), CubePawn->GetActorLocation().X, CubePawn->GetActorLocation().Y, CubePawn->GetActorLocation().Z);

	// Set new the location
	CubePawn->SetActorLocation(HitOut.Location);
}

void ACubePlayerController::OnAxisInputTurn(float value)
{

}

void ACubePlayerController::OnAxisInputLookUp(float value)
{

}

void ACubePlayerController::OnAxisInputMoveRight(float value)
{

}

void ACubePlayerController::OnAxisInputMoveForward(float value)
{

}
