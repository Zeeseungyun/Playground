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

	void ShowLoginWidget(bool bVisible);
	void ShowCreateCharacterWidget(bool bVisible, int32 Slot);

private:
	FReply OnLoginClicked();
	void OnConnected(const FString& InMessage);
	void OnCharacterSpotButtonClicked(int32 Slot);
	void OnCreateCharacterConfirm(const FString& InCharacterName, int32 Slot);

private:
	TSharedPtr<class SZeeUILobbyLogin> LoginWidget;
	TArray<TWeakObjectPtr<class ALobbyCharacterSpot>> LobbyCharacterSpots;
	FDelegateHandle DelConnected;

	void ResponseLogin(const struct FZeeNetAuthenticationLogin& InRes);

private:
	TSharedPtr<class SZeeUICreateCharacter> CreateCharacterWidget;
};
