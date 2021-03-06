// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllers/Entities/Players/DefaultPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/Pawn.h"

ADefaultPlayerController::ADefaultPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ADefaultPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Actions
	InputComponent->BindAction("LeftClick", IE_Pressed, this, &ADefaultPlayerController::OnLeftClick);
	InputComponent->BindAction("LeftClick", IE_Released, this, &ADefaultPlayerController::OnLeftClickUp);
}

void ADefaultPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MovePlayer();
	}
}

void ADefaultPlayerController::OnLeftClick()
{
	bMoveToMouseCursor = true;
}

void ADefaultPlayerController::OnLeftClickUp()
{
	bMoveToMouseCursor = false;
}

void ADefaultPlayerController::MovePlayer()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		UE_LOG(LogTemp, Display, TEXT("--------------------------------"));
		UE_LOG(LogTemp, Display, TEXT("hit, %.2f, %.2f, %.2f"), Hit.ImpactPoint.X, Hit.ImpactPoint.Y, Hit.ImpactPoint.Z);
	
		APawn* CubePawn = GetPawn();
		if (CubePawn)
		{
			UE_LOG(LogTemp, Display, TEXT("--------------------------------"));
			UE_LOG(LogTemp, Display, TEXT("pawn, %.2f, %.2f, %.2f"), CubePawn->GetActorLocation().X, CubePawn->GetActorLocation().Y, CubePawn->GetActorLocation().Z);

			float const Distance = FVector::Dist(Hit.ImpactPoint, CubePawn->GetActorLocation());

			// We need to issue move command only if far enough in order for walk animation to play correctly
			if ((Distance > 120.0f))
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Hit.ImpactPoint);
			}
		}
	}
}
