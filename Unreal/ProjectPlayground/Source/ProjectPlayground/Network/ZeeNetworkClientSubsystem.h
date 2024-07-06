#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ZeeNet/Public/ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Data/DataCharacter.h"
#include "ZeeNetworkClientSubsystem.generated.h"

UCLASS(Config=Game)
class PROJECTPLAYGROUND_API UZeeNetworkClientSubsystem 
	: public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	static UZeeNetworkClientSubsystem* Get(UObject* InContextObject);

	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	bool IsDedicatedServerInstance() const;

protected:
	TSharedPtr<class FZeeNetClient> MyClient;

	virtual void OnConnected(const FString& InMessage /*if empty is success*/);
	virtual void OnDisconnected();

	void Connect(const FString& InEndPoint);

public:
	void ConnectToGameServer();
	TSharedPtr<class FZeeNetClient> GetClient() const { return MyClient; }
	
	//server only
	FString DedicatedServerMapName;

	//client only
	int64 UserId = 0;
	int64 CharacterId = 0;
	TArray<FZeeNetDataCharacter> Characters;
	TArray<int32> CollectionIds;

	UPROPERTY(Config) FString GameServerEndPointShipping;
	UPROPERTY(Config) FString GameServerEndPointDevelopment;
	UPROPERTY(Config) FString GameServerEndPointPIE;
};
