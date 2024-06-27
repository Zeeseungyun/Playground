#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "LobbyCharacterSpot.generated.h"

UCLASS(Blueprintable)
class PROJECTPLAYGROUND_API ALobbyCharacterSpot 
	: public AStaticMeshActor
{
	GENERATED_BODY()
	ALobbyCharacterSpot(const FObjectInitializer& ObjectInitializer);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UWidgetComponent> WidgetComponent;

private:
	TSharedPtr<class SZeeUICharacterSpot> CharacterSpotWidget;

	FReply OnCharacterClicked();

public:
	TSharedPtr<class SZeeUICharacterSpot> GetSpotWidget() const { return CharacterSpotWidget; }
};
