#include "InGamePlayerController.h"

#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

#include "ProjectPlayground/Network/ZeeNetworkClientSubsystem.h"
#include "ZeeNet/Public/Messages/Dedicate.h"

AInGamePlayerController::AInGamePlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;

	// DataPosition.Pos = { .X = 1000.0f, .Y = 1810.0f, .Z = 92.1f };
}

void AInGamePlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
}

void AInGamePlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Started, this, &AInGamePlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this, &AInGamePlayerController::OnSetDestinationTriggered);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Completed, this, &AInGamePlayerController::OnSetDestinationReleased);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Canceled, this, &AInGamePlayerController::OnSetDestinationReleased);

		// Setup touch input events
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Started, this, &AInGamePlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Triggered, this, &AInGamePlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Completed, this, &AInGamePlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Canceled, this, &AInGamePlayerController::OnTouchReleased);

		EnhancedInputComponent->BindAction(SetMoveAction, ETriggerEvent::Triggered, this, &AInGamePlayerController::OnMoveAction);
	}
	else
	{
		//UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AInGamePlayerController::OnInputStarted()
{
	//UE_LOG(LogTemplateCharacter, Warning, TEXT("ZeeLog, void AInGamePlayerController::OnInputStarted()"));
	StopMovement();
}

// Triggered every frame when the input is held down
void AInGamePlayerController::OnSetDestinationTriggered()
{
	//UE_LOG(LogTemplateCharacter, Warning, TEXT("ZeeLog, void AInGamePlayerController::OnSetDestinationTriggered()"));
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();

	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;
	if (bIsTouch)
	{
		bHitSuccessful = GetHitResultUnderFinger(ETouchIndex::Touch1, ECollisionChannel::ECC_Visibility, true, Hit);
	}
	else
	{
		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
	}

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}

	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AInGamePlayerController::OnSetDestinationReleased()
{
	//UE_LOG(LogTemplateCharacter, Warning, TEXT("ZeeLog, void AInGamePlayerController::OnSetDestinationReleased()"));
	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}

	FollowTime = 0.f;
}

// Triggered every frame when the input is held down
void AInGamePlayerController::OnTouchTriggered()
{
	//UE_LOG(LogTemplateCharacter, Warning, TEXT("ZeeLog, void AInGamePlayerController::OnTouchTriggered()"));
	bIsTouch = true;
	OnSetDestinationTriggered();
}

void AInGamePlayerController::OnTouchReleased()
{
	//UE_LOG(LogTemplateCharacter, Warning, TEXT("ZeeLog, void AInGamePlayerController::OnTouchReleased()"));
	bIsTouch = false;
	OnSetDestinationReleased();
}

void AInGamePlayerController::OnMoveAction(const FInputActionValue& InValue)
{
	GetPawn()->AddMovementInput(InValue.Get<FVector>());
}

void AInGamePlayerController::OnLogout()
{
	if (::IsValid(GetPawn()))
	{
		UE_LOG(LogTemp, Log, TEXT("ZeeLog,  AInGamePlayerController::OnLogout if (::IsValid(GetPawn()))."));
		DataPosition.Pos = GetPawn()->GetActorLocation();
		DataPosition.Rot = GetPawn()->GetActorRotation();
	}

	UpdatePosition();
}

void AInGamePlayerController::PawnPendingDestroy(APawn* InPawn)
{
	UE_LOG(LogTemp, Log, TEXT("ZeeLog,  AInGamePlayerController::PawnPendingDestroy called."));
	if (::IsValid(InPawn))
	{
		DataPosition.Pos = InPawn->GetActorLocation();
		DataPosition.Rot = InPawn->GetActorRotation();
	}

	UpdatePosition();
	Super::PawnPendingDestroy(InPawn);
}

void AInGamePlayerController::UpdatePosition()
{
	UZeeNetworkClientSubsystem* NetworkClientSubsystem = UZeeNetworkClientSubsystem::Get(this);
	if (!::IsValid(NetworkClientSubsystem))
	{
		UE_LOG(LogTemp, Log, TEXT("ZeeLog,  AInGamePlayerController::UpdatePosition if (!::IsValid(NetworkClientSubsystem))."));
		return;
	}

	if (!NetworkClientSubsystem->IsDedicatedServerInstance())
	{
		UE_LOG(LogTemp, Log, TEXT("ZeeLog,  AInGamePlayerController::UpdatePosition if (!NetworkClientSubsystem->IsDedicatedServerInstance())."));
		return;
	}

	FZeeNetDedicateLeave Msg;
	Msg.Character = DataCharacter;
	Msg.Position = DataPosition;

	NetworkClientSubsystem->GetClient()->Notify(Msg);

	UE_LOG(LogTemp, Log, TEXT("ZeeLog,  AInGamePlayerController::UpdatePosition notify."));
}
