#include "ProjectPlayground/Network/ZeeNetworkClientSubsystem.h"
#include "Kismet/GameplayStatics.h"

#include "ZeeNet/Public/ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Authentication.h"
#include "ZeeNet/Public/Messages/Dedicate.h"

UZeeNetworkClientSubsystem* UZeeNetworkClientSubsystem::Get(UObject* InWorldContextObject)
{
	if (::IsValid(InWorldContextObject))
	{
		UWorld* World = GEngine->GetWorldFromContextObject(InWorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
		return World->GetGameInstance()->GetSubsystem<UZeeNetworkClientSubsystem>();
	}

	return nullptr;
}

void UZeeNetworkClientSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	MyClient = FZeeNetClient::MakeClient();
	MyClient->OnConnected().AddUObject(this, &UZeeNetworkClientSubsystem::OnConnected);
	MyClient->OnDisconnected().AddUObject(this, &UZeeNetworkClientSubsystem::OnDisconnected);

	if (IsDedicatedServerInstance())
	{
		ConnectToGameServer();
	}
}

void UZeeNetworkClientSubsystem::Deinitialize()
{
	MyClient->Shutdown();
	MyClient = nullptr;
}

bool UZeeNetworkClientSubsystem::IsDedicatedServerInstance() const
{
	return GetGameInstance()->IsDedicatedServerInstance();
}

void UZeeNetworkClientSubsystem::Connect(const FString& InEndPoint)
{
	if (MyClient.IsValid()) [[likely]]
	{
		MyClient->TryConnect(InEndPoint);
	}
}

void UZeeNetworkClientSubsystem::ConnectToGameServer()
{
	//TODO:: ini로부터 읽어들이도록 하거나 client와 server를 분리 할 필요가 있음.
#if UE_BUILD_SHIPPING
	Connect(GameServerEndPointShipping);
#elif UE_BUILD_DEVELOPMENT
	if (GIsEditor)
	{
		Connect(GameServerEndPointDevelopment);
	}
	else
	{
		Connect(GameServerEndPointPIE);
	}
#endif
}

void UZeeNetworkClientSubsystem::OnConnected(const FString& InMessage)
{
	if (!InMessage.IsEmpty())
	{
		return;
	}
	
	if (IsDedicatedServerInstance())
	{
		FZeeNetDedicateLogin EmptyMsg;
		EmptyMsg.DedicateServer.Port = GetGameInstance()->GetWorldContext()->LastURL.Port;

		GetClient()->Request<FZeeNetDedicateLogin>(EmptyMsg, this, [this](const FZeeNetDedicateLogin& InRes)
			{
				if (ZeeNetIsSuccess(InRes.RC))
				{
					DedicatedServerMapName = InRes.DedicateServer.MapName;
					const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
					if (!DedicatedServerMapName.Contains(CurrentLevelName))
					{
						UE_LOG(LogTemp, Log, TEXT("ZeeLog, Server level travel. [%s] to [%s]"), *CurrentLevelName, *DedicatedServerMapName);
						GetWorld()->ServerTravel(DedicatedServerMapName, true, true);
						return;
					}

					UE_LOG(LogTemp, Log, TEXT("ZeeLog, Server logged in."));
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("ZeeLog, maybe invalid port."));
					GetGameInstance()->Shutdown();
				}
			}
		);
	}
}

void UZeeNetworkClientSubsystem::OnDisconnected()
{
	if (IsDedicatedServerInstance())
	{
		DedicatedServerMapName.Empty();
		UE_LOG(LogTemp, Warning, TEXT("ZeeLog, game server shutdown."));
		GetGameInstance()->Shutdown();
	}
	else
	{
		UserId = 0;
		CharacterId = 0;
		Characters.Empty();
		CollectionIds.Empty();

		const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
		if (CurrentLevelName != TEXT("ZeeClientEntry"))
		{
			UGameplayStatics::OpenLevel(this, TEXT("ZeeClientEntry"));
		}
	}
}
