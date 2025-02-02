#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "ZeeNet/Public/Messages/Data/DataCommon.h"
#include "ZeeNet/Public/Messages/Data/DataCharacter.h"
#include "InGamePlayerController.generated.h"


class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;

UCLASS()
class PROJECTPLAYGROUND_API AInGamePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AInGamePlayerController();

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UNiagaraSystem> FXCursor;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> SetDestinationClickAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> SetDestinationTouchAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> SetMoveAction;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type InReason) override;
	/** Input handlers for SetDestination action. */
	void OnInputStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();
	void OnTouchTriggered();
	void OnTouchReleased();
	void OnMoveAction(const struct FInputActionValue& InValue);

private:
	FVector CachedDestination;

	bool bIsTouch; // Is it a touch device
	float FollowTime; // For how long it has been pressed

public:
	FZeeNetDataCharacter DataCharacter;
	FZeeNetDataPosition DataPosition;

	void OnLogout();

	virtual void PawnPendingDestroy(APawn* InPawn) override;
	void UpdatePosition();

private:
	TSharedPtr<class SWidget> SelectCharacterWidget;
	UPROPERTY()	TSubclassOf<class UUserWidget> TouchInputWidgetClass;
	UPROPERTY(transient) TObjectPtr<class UUserWidget> TouchInputWidgetInst;
};
