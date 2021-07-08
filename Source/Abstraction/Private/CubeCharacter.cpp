// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Entities/Players/CubeCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
ACubeCharacter::ACubeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// All the assignments are here so our components show up in the editor. The root component
	// is the capsule collider, it can be seen you if you create a blueprint out of this class

	// Holds the camera
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	// Static mesh, currently a cube
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	MeshComponent->SetupAttachment(RootComponent);

	// Custom player controller
	PlayerController = CreateDefaultSubobject<ACubePlayerController>(TEXT("PlayerController"));
	PlayerController->SetupInputComponent();

	BaseTurnRate = 45.0f;
	BaseLookUpAtRate = 45.0f;
}

// Called when the game starts
void ACubeCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Change capsule collider to match cube dimensions
	if (RootComponent && MeshComponent) {
		UCapsuleComponent* capsuleComponent = GetCapsuleComponent();

		if (capsuleComponent)
		{
			UStaticMesh* staticMesh = MeshComponent->GetStaticMesh();

			if (staticMesh)
			{
				const FVector size = staticMesh->GetBounds().GetBox().GetSize();
				capsuleComponent->SetCapsuleSize(size.X / 2.0f, size.X / 2.0f, false);
			}
		}
    }
}
