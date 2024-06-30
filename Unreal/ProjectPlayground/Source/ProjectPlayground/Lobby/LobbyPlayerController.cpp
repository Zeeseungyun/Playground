#include "LobbyPlayerController.h"
#include "Camera/CameraActor.h"
#include "EngineUtils.h"
#include "Engine/GameInstance.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Kismet/GameplayStatics.h"

#include "ZeeUI/Public/Lobby/SZeeUILobbyLogin.h"
#include "ZeeUI/Public/Common/Alarm/SZeeUIPopup.h"
#include "ZeeUI/Public/Lobby/SZeeUICharacterSpot.h"
#include "ZeeUI/Public/Lobby/SZeeUICreateCharacter.h"

#include "ZeeNet/Public/Messages/Authentication.h" 
#include "ZeeNet/Public/Messages/UserCharacter.h" 
#include "ZeeNet/Public/Messages/Dedicate.h" 

#include "ProjectPlayground/Lobby/LobbyCharacterSpot.h"
#include "ProjectPlayground/Lobby/LobbyCharacter.h"
#include "ProjectPlayground/Network/ZeeNetworkClientSubsystem.h"
#include "ProjectPlayground/Common/ZeeUtils.h"

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

	for (int32 i = 0; i != LobbyCharacterSpots.Num(); ++i)
	{
		LobbyCharacterSpots[i]->OnWidgetButtonClicked.AddUObject(this, &ALobbyPlayerController::OnCharacterSpotButtonClicked, i + 1);
	}

	ShowLoginWidget(true);
}

void ALobbyPlayerController::ShowLoginWidget(bool bVisible)
{
	if (bVisible)
	{
		if (!LoginWidget.IsValid())
		{
			LoginWidget = SNew(SZeeUILobbyLogin).OnLoginClicked_UObject(this, &ALobbyPlayerController::OnLoginClicked);
		}
		GetWorld()->GetGameViewport()->AddViewportWidgetContent(LoginWidget.ToSharedRef());
	}
	else
	{
		if (LoginWidget.IsValid())
		{
			GetWorld()->GetGameViewport()->RemoveViewportWidgetContent(LoginWidget.ToSharedRef());
		}
	}
}

void ALobbyPlayerController::ShowCreateCharacterWidget(bool bVisible, int32 Slot)
{
	if (bVisible)
	{
		if (!CreateCharacterWidget.IsValid())
		{
			CreateCharacterWidget =
			SNew(SZeeUICreateCharacter)
			.OnCancel(SZeeUICreateCharacter::FDel_OnCancel::CreateLambda([WeakThis = TWeakObjectPtr<ALobbyPlayerController>(this)]()
				{
					if (WeakThis.IsValid())
					{
						WeakThis->ShowCreateCharacterWidget(false, 0);
					}
				}
			));
		}

		CreateCharacterWidget->DelConfirm = SZeeUICreateCharacter::FDel_OnConfirm::CreateUObject(this, &ALobbyPlayerController::OnCreateCharacterConfirm, Slot);

		GetWorld()->GetGameViewport()->AddViewportWidgetContent(CreateCharacterWidget.ToSharedRef());
	}
	else
	{
		if (CreateCharacterWidget.IsValid())
		{
			GetWorld()->GetGameViewport()->RemoveViewportWidgetContent(CreateCharacterWidget.ToSharedRef());
		}
	}
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
	UZeeNetworkClientSubsystem* NetworkClientSubsystem = UZeeNetworkClientSubsystem::Get(this);
	if (!::IsValid(NetworkClientSubsystem))
	{
		return;
	}

	if (InMessage.Len() == 0)
	{
		if (DelConnected.IsValid()) [[likely]]
		{
				NetworkClientSubsystem->GetClient()->OnConnected().Remove(DelConnected);
			DelConnected.Reset();
		}

		FZeeNetAuthenticationLogin Msg;
		Msg.Account.Id = LoginWidget->GetUserID();
		Msg.Account.Password = LoginWidget->GetUserPW();

		NetworkClientSubsystem->GetClient()->Request<FZeeNetAuthenticationLogin>(Msg, this, &ALobbyPlayerController::ResponseLogin);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("connect failed. [%s]"), *InMessage);
	}
}

void ALobbyPlayerController::OnCharacterSpotButtonClicked(int32 Slot)
{
	if (LobbyCharacterSpots[Slot - 1]->GetCharacterData().UID == 0)
	{
		ShowCreateCharacterWidget(true, Slot);
	}
	else
	{
		UZeeNetworkClientSubsystem* NetworkClientSubsystem = UZeeNetworkClientSubsystem::Get(this);
		if (!::IsValid(NetworkClientSubsystem))
		{
			return;
		}

		FZeeNetDedicateMove ReqMsg;
		ReqMsg.Character.Slot = Slot;
		NetworkClientSubsystem->GetClient()->Request<FZeeNetDedicateMove>(ReqMsg, this, [this](const FZeeNetDedicateMove& InRes)
			{
				const FString Options = FString::Printf(TEXT("Id=%lld"), UZeeNetworkClientSubsystem::Get(this)->UserId);
				UGameplayStatics::OpenLevel(this, *FString::Printf(TEXT("%s:%d"), *InRes.ToServer.Ip, InRes.ToServer.Port), true, Options);
			}
		);
	}
}

void ALobbyPlayerController::OnCreateCharacterConfirm(const FString& InCharacterName, int32 Slot)
{
	UZeeNetworkClientSubsystem* NetworkClientSubsystem = UZeeNetworkClientSubsystem::Get(this);
	if (!::IsValid(NetworkClientSubsystem))
	{
		return;
	}

	FZeeNetUserCharacterCreate Req;
	Req.Character.Slot = Slot;
	Req.Character.Name = InCharacterName;

	NetworkClientSubsystem->GetClient()->Request<FZeeNetUserCharacterCreate>(Req, this, [this](const FZeeNetUserCharacterCreate& InRes) 
		{
			UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
			if (!::IsValid(ViewportClient))
			{
				return;
			}

			if (ZeeNetIsSuccess(InRes.RC))
			{
				LobbyCharacterSpots[InRes.Character.Slot - 1]->SetCharacterData(InRes.Character);
				ShowCreateCharacterWidget(false, 0);
			}
			else
			{
				ViewportClient->AddViewportWidgetContent(
					SNew(SZeeUIPopup)
					.ViewportClient(ViewportClient)
					.Message(ZeeEnumToString(InRes.RC))
				);
			}
		}
	);
}

void ALobbyPlayerController::ResponseLogin(const struct FZeeNetAuthenticationLogin& InRes)
{
	if (ZeeNetIsSuccess(InRes.RC))
	{
		static auto FindCharacterDataBySlot = [](const TArray<FZeeNetDataCharacter>& Datas, int32 Slot) -> const FZeeNetDataCharacter*
			{
				for (const auto& Elem : Datas)
				{
					if (Elem.Slot == Slot)
					{
						return &Elem;
					}
				}

				return nullptr;
			};

		UZeeNetworkClientSubsystem::Get(this)->UserId = InRes.Account.UID;

		const int32 Num = 3; //LobbyCharacterSpots.Num();
		for (int32 i = 0; i != Num; ++i)
		{
			if (ensure(LobbyCharacterSpots[i].IsValid())) [[likely]]
			{
				const FZeeNetDataCharacter* FoundData = FindCharacterDataBySlot(InRes.Characters, i + 1);
				LobbyCharacterSpots[i]->SetCharacterData(FoundData ? *FoundData : FZeeNetDataCharacter{});
			}
		}

		ShowLoginWidget(false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Login failed. [%s]"), *ZeeEnumToString(InRes.RC));
	}
}
