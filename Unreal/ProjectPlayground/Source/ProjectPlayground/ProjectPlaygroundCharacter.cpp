// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectPlaygroundCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "ZeeNet/Public/ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Authentication.h"
#include "ProjectPlayground.h"
#include "GameFramework/PlayerController.h"
#include "ZeeUI/Public/Lobby/SZeeUILobbyLogin.h"

AProjectPlaygroundCharacter::AProjectPlaygroundCharacter()
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

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AProjectPlaygroundCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void AProjectPlaygroundCharacter::BeginPlay() /*override*/
{
	Super::BeginPlay();
	MyLoginWidget = SNew(SZeeUILobbyLogin).OnLoginClicked_UObject(this, &AProjectPlaygroundCharacter::OnLoginClicked);
	
	GetWorld()->GetGameViewport()->AddViewportWidgetContent(MyLoginWidget.ToSharedRef());
	//UGameViewportClient;

}

FReply AProjectPlaygroundCharacter::OnLoginClicked()
{
	if (!MyClient.IsValid())
	{
		MyClient = MakeShared<FZeeNetClient>();
		MyClient->OnConnected().AddLambda([this, 
			UserId = MyLoginWidget->GetUserID(), 
			UserPW = MyLoginWidget->GetUserPW()](const FString& InMessage)
			{
				if (!InMessage.IsEmpty())
				{
					return;
				}

				FZeeNetAuthenticationLogin Msg;
				Msg.Account.Id = UserId;
				Msg.Account.Password = UserPW;
				//UE_LOG(LogZeeNet, Log, TEXT("Request Test Message Request, %s"), *Msg.Content);
				MyClient->Request<FZeeNetAuthenticationLogin>(Msg, [](const FZeeNetAuthenticationLogin& InMsg)
					{
						UE_LOG(LogProjectPlayground, Log, TEXT("Login, %s"), ZeeNetIsSuccess(InMsg.RC) ? TEXT("Success") : TEXT("Failed."));
					}
				);
			}
		);
	}

	MyClient->TryConnect(TEXT("127.0.0.1:20500"));
	return FReply::Handled();
}
