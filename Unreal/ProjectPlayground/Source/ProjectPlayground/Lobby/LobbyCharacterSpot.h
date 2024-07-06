#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "ZeeNet/Public/Messages/Data/DataCharacter.h" 
#include "LobbyCharacterSpot.generated.h"

UCLASS(Blueprintable)
class PROJECTPLAYGROUND_API ALobbyCharacterSpot 
	: public AStaticMeshActor
{
	GENERATED_BODY()
	ALobbyCharacterSpot(const FObjectInitializer& ObjectInitializer);

public:	
	// Called every frame
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UWidgetComponent> WidgetComponent;

	TWeakObjectPtr<class ALobbyCharacter> LobbyCharacterPtr;
	TSharedPtr<class SZeeUICharacterSpot> CharacterSpotWidget;

	FReply OnCharacterClicked();
	void Update();

public:
	DECLARE_EVENT(ALobbyCharacterSpot, FEventWidgetButtonClicked);
	FEventWidgetButtonClicked OnWidgetButtonClicked;

	void SetCharacterData(const FZeeNetDataCharacter& InData);
	const FZeeNetDataCharacter& GetCharacterData() const { return CharacterData; }

private:
	FZeeNetDataCharacter CharacterData;
};
