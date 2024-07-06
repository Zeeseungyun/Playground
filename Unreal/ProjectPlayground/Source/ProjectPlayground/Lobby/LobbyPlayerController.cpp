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

	bool bShowLoginWidget = true;
	UZeeNetworkClientSubsystem* NetworkClientSubsystem = UZeeNetworkClientSubsystem::Get(this);
	if (::IsValid(NetworkClientSubsystem))
	{
		bShowLoginWidget = NetworkClientSubsystem->UserId == 0;
		SetCharacters(NetworkClientSubsystem->Characters);
	}

	ShowLoginWidget(bShowLoginWidget);
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
	UZeeNetworkClientSubsystem* NetworkClientSubsystem = UZeeNetworkClientSubsystem::Get(this);
	if (!::IsValid(NetworkClientSubsystem))
	{	
		SZeeUIPopup::Show(TEXT("NetworkClientSubsystem is invalid."), GetWorld()->GetGameViewport());
		return FReply::Handled();
	}

	if (!NetworkClientSubsystem->GetClient()->IsConnected())
	{
		if (!DelConnected.IsValid())
		{
			DelConnected = NetworkClientSubsystem->GetClient()->OnConnected().AddUObject(this, &ALobbyPlayerController::OnConnected);
		}

		NetworkClientSubsystem->ConnectToGameServer();
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
		if (DelConnected.IsValid())
		{
			NetworkClientSubsystem->GetClient()->OnConnected().Remove(DelConnected);
			DelConnected.Reset();
		}

		FZeeNetAuthenticationLogin Req;
		Req.Account.Id = LoginWidget->GetUserID();
		Req.Account.Password = LoginWidget->GetUserPW();

		NetworkClientSubsystem->GetClient()->Request<FZeeNetAuthenticationLogin>(Req, this, [this](const FZeeNetAuthenticationLogin& InRes)
			{
				if (ZeeNetIsSuccess(InRes.RC))
				{
					UZeeNetworkClientSubsystem* NetworkClientSubsystem = UZeeNetworkClientSubsystem::Get(this);
					NetworkClientSubsystem->UserId = InRes.Account.UID;
					NetworkClientSubsystem->Characters = InRes.Characters;
					NetworkClientSubsystem->CollectionIds = InRes.CollectionIds;
					SetCharacters(NetworkClientSubsystem->Characters);
					ShowLoginWidget(false);
				}
				else
				{
					SZeeUIPopup::Show(ZeeEnumToString(InRes.RC), GetWorld()->GetGameViewport());
				}
			}
		);
	}
	else
	{
		SZeeUIPopup::Show(InMessage, GetWorld()->GetGameViewport());
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

		FZeeNetUserCharacterSelect Req;
		Req.Character.Slot = Slot;
		NetworkClientSubsystem->GetClient()->Request<FZeeNetUserCharacterSelect>(Req, this, [this, NetworkClientSubsystem](const FZeeNetUserCharacterSelect& InRes)
			{
				if (ZeeNetIsSuccess(InRes.RC))
				{
					NetworkClientSubsystem->CharacterId = InRes.Character.UID;
					const FString Options = FString::Printf(TEXT("Id=%lld"), NetworkClientSubsystem->UserId);
					UGameplayStatics::OpenLevel(this, *FString::Printf(TEXT("%s:%d"), *InRes.ToServer.Ip, InRes.ToServer.Port), true, Options);
				}
				else
				{
					SZeeUIPopup::Show(ZeeEnumToString(InRes.RC), GetWorld()->GetGameViewport());
				}
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

	NetworkClientSubsystem->GetClient()->Request<FZeeNetUserCharacterCreate>(Req, this, [this, NetworkClientSubsystem](const FZeeNetUserCharacterCreate& InRes)
		{
			if (ZeeNetIsSuccess(InRes.RC))
			{
				LobbyCharacterSpots[InRes.Character.Slot - 1]->SetCharacterData(InRes.Character);
				NetworkClientSubsystem->Characters.Add(InRes.Character);
				ShowCreateCharacterWidget(false, 0);
			}
			else
			{
				SZeeUIPopup::Show(ZeeEnumToString(InRes.RC), GetWorld()->GetGameViewport());
			}
		}
	);
}

void ALobbyPlayerController::SetCharacters(const TArray<struct FZeeNetDataCharacter>& Characters)
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

	for (int32 i = 0; i != LobbyCharacterSpots.Num(); ++i)
	{
		if (LobbyCharacterSpots[i].IsValid()) 
		{
			const FZeeNetDataCharacter* FoundData = FindCharacterDataBySlot(Characters, i + 1);
			LobbyCharacterSpots[i]->SetCharacterData(FoundData ? *FoundData : FZeeNetDataCharacter{});
		}
	}
}
