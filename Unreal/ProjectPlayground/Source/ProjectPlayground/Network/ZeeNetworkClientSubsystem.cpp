#include "ProjectPlayground/Network/ZeeNetworkClientSubsystem.h"
#include "ZeeNet/Public/ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Authentication.h"

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
}

void UZeeNetworkClientSubsystem::Deinitialize()
{
	MyClient->Shutdown();
	MyClient = nullptr;
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
	Connect(TEXT("127.0.0.1:20500"));
}

void UZeeNetworkClientSubsystem::OnConnected(const FString& InMessage)
{
	
}

void UZeeNetworkClientSubsystem::OnDisconnected()
{

}
