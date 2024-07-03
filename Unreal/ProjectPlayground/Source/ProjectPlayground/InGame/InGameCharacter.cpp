// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectPlayground/InGame/InGameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "ProjectPlayground/ProjectPlayground.h"
#include "Net/UnrealNetwork.h"
#include "Components/WidgetComponent.h"

#include "ZeeUI/Public/ZeeUISlateStyles.h"
#include "ZeeUI/Public/InGame/SlateStyle/ZeeUISlateStyle_InGame.h"

AInGameCharacter::AInGameCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	CharacterNameComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("CharacterName"));
	CharacterNameComponent->SetupAttachment(RootComponent);
	CharacterNameComponent->SetWidgetSpace(EWidgetSpace::Screen);
	CharacterNameComponent->SetDrawSize(FVector2D(10.0, 10.f));
	CharacterNameComponent->SetDrawAtDesiredSize(true);

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	bReplicates = true;
}

// Called when the game starts or when spawned
void AInGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (!HasAuthority())
	{
		const FZeeUISlateStyle_InGame& Style = FZeeUISlateStyles::Get().GetWidgetStyle<FZeeUISlateStyle_InGame>("InGame/InGame");

		CharacterNameComponent->SetSlateWidget(
			SNew(SBorder).Padding(20.0f)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.BorderImage(&Style.InGameBorderBrush)
			[
				SNew(STextBlock)
				.TextStyle(&Style.InGameTextStyle)
				.Text(FText::FromString(CharacterName))
			]
		);
	}
}

// Called every frame
void AInGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AInGameCharacter::GetLifetimeReplicatedProps(TArray< class FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AInGameCharacter, CharacterName);
}
