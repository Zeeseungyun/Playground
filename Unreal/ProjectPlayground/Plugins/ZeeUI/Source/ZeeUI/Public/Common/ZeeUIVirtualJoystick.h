#pragma once
#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "ZeeUIVirtualJoystick.generated.h"

class SZeeUIVirtualJoystick;

UCLASS(ClassGroup = "ZeeUITouchInput")
class ZEEUI_API UZeeUIVirtualJoystick : public UWidget
{
	GENERATED_BODY()

public:
	UZeeUIVirtualJoystick();

	//~ Begin UVisual interface
public:
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	//~ End UWidget interface

	//~ Begin UWidget interface

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void OnWidgetRebuilt() override;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif
	//~ End UWidget interface


public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDel_OnStickActivated);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDel_OnBoardMoved, const FVector2D&, NewPosition);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDel_OnStickMoved, const FVector2D&, NewPosition);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDel_OnStickInactivated);

	UPROPERTY(BlueprintAssignable, Category = "ZeeUIVirtualJoystick|Event") FDel_OnStickActivated OnStickActivated;
	UPROPERTY(BlueprintAssignable, Category = "ZeeUIVirtualJoystick|Event") FDel_OnBoardMoved OnBoardMoved;
	UPROPERTY(BlueprintAssignable, Category = "ZeeUIVirtualJoystick|Event") FDel_OnStickMoved OnStickMoved;
	UPROPERTY(BlueprintAssignable, Category = "ZeeUIVirtualJoystick|Event") FDel_OnStickInactivated OnStickInactivated;

	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Appearance") const FVector2D& GetCenterOffset() const { return CenterOffset; }

	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") const FKey& GetXAxisKey() const { return XAxisKey; }
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") const FKey& GetYAxisKey() const { return YAxisKey; }

	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") float GetBoardRadius() const { return BoardRaidus; }

	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick") bool IsStickAutoReturnToCenter() const { return bIsStickAutoReturnToCenter; }
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick") bool IsBoardFixed() const { return bIsBoardFixed; }
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick") bool IsBoardAutoReturnToCenter() const { return !IsBoardFixed() && bIsBoardAutoReturnToCenter; }
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") bool IsXAxisInverted() const { return bIsXAxisInverted; }
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") bool IsYAxisInverted() const { return bIsYAxisInverted; }
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") bool UsingAxisInput() const { return bUsingAxisInput; }

	//Returns INDEX_NONE if inactivated
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") int32 GetCurrentTouchIndex() const;
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") bool IsActivated() const;

	//Size was bounded by [0 ~ 1]
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") const FVector2D& GetStickDelta() const;

	//Returns a ZeroVector if not painting
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") FVector2D CalculateCenterPosition() const;

	//Returns a position mapped to this widget geometry.
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") const FVector2D& GetBoardPosition() const;

	//Returns a position mapped to this widget geometry.
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") const FVector2D& GetStickPosition() const;

	//Returns a position mapped to this widget geometry.
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") const FVector2D& GetTouchPosition() const;

	//Returns a distance mapped to this widget geometry.
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick|Interaction") const FVector2D& GetDistanceBoardBetweenStick() const;

	//Fails if IsBoardAutoReturnToCenter is true and 'IsEnabled' is true.
	//@param NewPosition must be in this widget's local position.
	//@return Returns false on failure
	UFUNCTION(BlueprintCallable, Category = "ZeeUIVirtualJoystick") bool ForceChangeBoardPosition(FVector2D NewLocalPosition);

	//Fails if IsStickAutoReturnToCenter is true and 'IsEnabled' is true.
	//NewPosition must be in this widget's local position.
	//@param NewPosition must be in this widget's local position.
	//@return Returns false on failure
	UFUNCTION(BlueprintCallable, Category = "ZeeUIVirtualJoystick") bool ForceChangeStickPosition(FVector2D NewLocalPosition);

	//Returns false if not painting
	UFUNCTION(BlueprintPure, Category = "ZeeUIVirtualJoystick") bool AbsoluteToLocalPositionInThisWidget(FVector2D AbsolutePosition, FVector2D& OutLocalPosition) const;

	//Do nothing if stick is inactivated.
	UFUNCTION(BlueprintCallable, Category = "ZeeUIVirtualJoystick") void ForceTouchEnd();

private:
	void HandleStickActivated();
	void HandleBoardMoved(const FVector2D& NewPosition);
	void HandleStickMoved(const FVector2D& NewPosition);
	void HandleStickInactivated();

	const FKey* GetAddressOfXAxisKey() const { return &XAxisKey; }
	const FKey* GetAddressOfYAxisKey() const { return &YAxisKey; }

	const FVector2D* GetAddressOfCenterOffset() const { return &CenterOffset; }

private:
	TSharedPtr<SZeeUIVirtualJoystick> MyJoystick;

private:
	UPROPERTY(EditAnywhere, Category = "Interaction")
	FVector2D CenterOffset = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float BoardRaidus = 200.0f;

	UPROPERTY(EditAnywhere, Category = "Interaction") 
	uint8 bIsStickAutoReturnToCenter : 1;

	UPROPERTY(EditAnywhere, Category = "Interaction") 
	uint8 bIsBoardFixed : 1;

	UPROPERTY(EditAnywhere, Category = "Interaction", meta = (EditCondition = "!bIsBoardFixed")) 
	uint8 bIsBoardAutoReturnToCenter : 1;

	//Whether to generate an axis input
	//Disable members of category 'Interaction|Input' if false
	UPROPERTY(EditAnywhere, Category = "Interaction") 
	uint8 bUsingAxisInput : 1;

	//Whether to invert the X-axis input
	UPROPERTY(EditAnywhere, Category = "Interaction|Input", meta = (EditCondition = "bUsingAxisInput")) 
	uint8 bIsXAxisInverted : 1;

	//Whether to invert the Y-axis input
	UPROPERTY(EditAnywhere, Category = "Interaction|Input", meta = (EditCondition = "bUsingAxisInput")) 
	uint8 bIsYAxisInverted : 1;

	UPROPERTY(EditAnywhere, Category = "Interaction|Input", meta = (EditCondition = "bUsingAxisInput")) 
	FKey XAxisKey = EKeys::Gamepad_LeftX;

	UPROPERTY(EditAnywhere, Category = "Interaction|Input", meta = (EditCondition = "bUsingAxisInput")) 
	FKey YAxisKey = EKeys::Gamepad_LeftY;

};
