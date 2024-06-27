// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTPLAYGROUND_API ALobbyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

private:
	FReply OnLoginClicked();
	void OnConnected(const FString& InMessage);

private:
	TSharedPtr<class SZeeUILobbyLogin> MyLoginWidget;
	TArray<TWeakObjectPtr<class ALobbyCharacterSpot>> LobbyCharacterSpots;
	TArray<TWeakObjectPtr<class ALobbyCharacter>> LobbyCharacters;
	FDelegateHandle DelConnected;

	void ResponseLogin(const struct FZeeNetAuthenticationLogin& InRes);
};
