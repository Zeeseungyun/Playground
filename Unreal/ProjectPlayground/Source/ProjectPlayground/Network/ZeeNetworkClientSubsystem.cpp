#include "ProjectPlayground/Network/ZeeNetworkClientSubsystem.h"
#include "ZeeNet/Public/ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Authentication.h"
#include "ZeeNet/Public/Messages/Dedicate.h"
#include "Kismet/GameplayStatics.h"

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
	Connect(TEXT("127.0.0.1:20500"));
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
		GetClient()->Request<FZeeNetDedicateLogin>(EmptyMsg, this, [this](const FZeeNetDedicateLogin& InRes)
			{
				if (ZeeNetIsSuccess(InRes.RC))
				{
					DedicatedServerMapName = InRes.DedicateServer.MapName;
					// GetWorld()->ServerTravel(DedicatedServerMapName, true, true);
				}
			}
		);
	}
}

void UZeeNetworkClientSubsystem::OnDisconnected()
{

}
