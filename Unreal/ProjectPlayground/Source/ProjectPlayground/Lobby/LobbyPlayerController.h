#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerController.generated.h"

UCLASS()
class PROJECTPLAYGROUND_API ALobbyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

private:
	void ShowLoginWidget(bool bVisible);
	void ShowCreateCharacterWidget(bool bVisible, int32 Slot);
	FReply OnLoginClicked();
	void OnConnected(const FString& InMessage);
	void OnCharacterSpotButtonClicked(int32 Slot);
	void OnCreateCharacterConfirm(const FString& InCharacterName, int32 Slot);
	void SetCharacters(const TArray<struct FZeeNetDataCharacter>& Characters);

private:
	TSharedPtr<class SZeeUILobbyLogin> LoginWidget;
	TArray<TWeakObjectPtr<class ALobbyCharacterSpot>> LobbyCharacterSpots;
	FDelegateHandle DelConnected;

	TSharedPtr<class SZeeUICreateCharacter> CreateCharacterWidget;
};
