// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ZeeNet/Public/Messages/Dedicate.h"
#include "InGameModeBase.generated.h"

UCLASS()
class PROJECTPLAYGROUND_API AInGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AInGameModeBase();

	virtual void BeginPlay() override;
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual APawn* SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot) override;
	virtual void Logout(AController* Exiting) override;

private:
	TSharedPtr<class FInGameRequestHandler> RequestHandler;

public:
	UPROPERTY(transient)
	TMap<FString, FZeeNetDedicateMove> DedicateMoveToUIDs;
};
