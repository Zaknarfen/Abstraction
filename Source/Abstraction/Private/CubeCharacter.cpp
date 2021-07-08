// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Entities/Players/CubeCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACubeCharacter::ACubeCharacter()
{
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// All the assignments are here so our components show up in the editor. The root component
	// is the capsule collider, it can be seen you if you create a blueprint out of this class

	// Holds the camera
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts
void ACubeCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Change capsule collider to match cube dimensions
	USkeletalMeshComponent* MeshComponent = GetMesh();
	if (RootComponent && MeshComponent) {
		UCapsuleComponent* capsuleComponent = GetCapsuleComponent();

		if (capsuleComponent)
		{
			const FBox Bounds = MeshComponent->GetNavigationBounds();
			const FVector size = Bounds.GetSize();
			//capsuleComponent->SetCapsuleSize(size.X / 2.0f, size.X / 2.0f, false);
		}
    }
}
