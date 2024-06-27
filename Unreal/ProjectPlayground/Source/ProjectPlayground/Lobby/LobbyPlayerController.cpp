#include "LobbyPlayerController.h"
#include "Camera/CameraActor.h"
#include "EngineUtils.h"
#include "Engine/GameInstance.h"
#include "ZeeUI/Public/Lobby/SZeeUILobbyLogin.h"
#include "ZeeNet/Public/Messages/Authentication.h" 
#include "ProjectPlayground/Lobby/LobbyCharacterSpot.h"
#include "ProjectPlayground/Lobby/LobbyCharacter.h"
#include "ProjectPlayground/Network/ZeeNetworkClientSubsystem.h"
#include "ProjectPlayground/Common/ZeeUtils.h"
#include "ZeeUI/Public/Lobby/SZeeUICharacterSpot.h"

void ALobbyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	TSubclassOf<ACameraActor> ClassToFind;
	for (TActorIterator<ACameraActor> It(GetWorld()); It; ++It)
	{
		ACameraActor* Actor = *It;
		SetViewTarget(Actor);
		break;
	}

	for (TActorIterator<ALobbyCharacterSpot> It(GetWorld()); It; ++It)
	{
		LobbyCharacterSpots.Add(*It);
	}

	LobbyCharacterSpots.Sort([](const TWeakObjectPtr<class ALobbyCharacterSpot>& Lhs, const TWeakObjectPtr<class ALobbyCharacterSpot>& Rhs)
		{
			return Lhs->Tags[0].ToString() < Rhs->Tags[0].ToString();
		}
	);

	auto GetLobbyCharacter = [](class ALobbyCharacterSpot* Spot)
		{
			TArray<AActor*> AttachedActors;
			Spot->GetAttachedActors(AttachedActors);
			return Cast<ALobbyCharacter>(AttachedActors[0]);
		};

	for (const TWeakObjectPtr<class ALobbyCharacterSpot>& Elem : LobbyCharacterSpots)
	{
		LobbyCharacters.Add(GetLobbyCharacter(Elem.Get()));
	}

	MyLoginWidget = SNew(SZeeUILobbyLogin).OnLoginClicked_UObject(this, &ALobbyPlayerController::OnLoginClicked);
	GetWorld()->GetGameViewport()->AddViewportWidgetContent(MyLoginWidget.ToSharedRef());
}

FReply ALobbyPlayerController::OnLoginClicked()
{
	UZeeNetworkClientSubsystem* NetworkSubsystem = UZeeNetworkClientSubsystem::Get(this);
	if (!NetworkSubsystem->GetClient()->IsConnected())
	{
		if (!DelConnected.IsValid()) [[unlikely]]
		{
			DelConnected = NetworkSubsystem->GetClient()->OnConnected().AddUObject(this, &ALobbyPlayerController::OnConnected);
		}

		NetworkSubsystem->ConnectToGameServer();
	}
	else
	{
		OnConnected(TEXT(""));
	}

	return FReply::Handled();
}

void ALobbyPlayerController::OnConnected(const FString& InMessage)
{
	UZeeNetworkClientSubsystem* NetworkSubsystem = UZeeNetworkClientSubsystem::Get(this);
	if (InMessage.Len() == 0)
	{
		if (DelConnected.IsValid()) [[likely]]
		{
			NetworkSubsystem->GetClient()->OnConnected().Remove(DelConnected);
			DelConnected.Reset();
		}

		FZeeNetAuthenticationLogin Msg;
		Msg.Account.Id = MyLoginWidget->GetUserID();
		Msg.Account.Password = MyLoginWidget->GetUserPW();

		NetworkSubsystem->GetClient()->Request<FZeeNetAuthenticationLogin>(Msg, this, &ALobbyPlayerController::ResponseLogin);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("connect failed. [%s]"), *InMessage);
	}
}

void ALobbyPlayerController::ResponseLogin(const struct FZeeNetAuthenticationLogin& InRes)
{
	if (ZeeNetIsSuccess(InRes.RC))
	{
		const int32 Num = 3; //LobbyCharacterSpots.Num();
		for (int32 i = 0; i != Num; ++i)
		{
			if (ensure(LobbyCharacterSpots[i].IsValid())) [[likely]]
			{
				FString CharacterName = InRes.Characters.IsValidIndex(i) ? InRes.Characters[i].Name : TEXT("");
				LobbyCharacterSpots[i]->GetSpotWidget()->SetCharacterName(CharacterName);
			}
		}

		GetWorld()->GetGameViewport()->RemoveViewportWidgetContent(MyLoginWidget.ToSharedRef());
		MyLoginWidget = nullptr;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Login failed. [%s]"), *ZeeEnumToString(InRes.RC));
	}
}
