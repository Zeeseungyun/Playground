// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ZeeNet/Public/Messages/Dedicate.h"
#include "ZeeNet/Public/Messages/UserCharacter.h"
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
	friend class FInGameRequestHandler_Dedicate;
	TSharedPtr<class FInGameRequestHandler_Dedicate> RequestHandler_Dedicate;
	friend class FInGameRequestHandler_UserCharacter;
	TSharedPtr<class FInGameRequestHandler_UserCharacter> RequestHandler_UserCharacter;

	struct FPassport {
		FZeeNetDataCharacter Character;
		FString UserIp;
		FString MapName;
		bool bIsMoveTown = false;
		FVector Pos;
		FRotator Rot;
	};

	TMap<FString, FPassport> Passports;

	FVector MoveTownDestPos;
	FRotator MoveTownDestRot;
};
