#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZeeUITouchInputWidget.generated.h"

class UZeeUIVirtualJoystick;

class UWidgetSwitcher;
class UPanelWidget;
class UImage;
class UWidgetAnimation;


UCLASS(Abstract, ClassGroup = "ZeeUITouchInput")
class ZEEUI_API UZeeUITouchInputWidgetBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UZeeUITouchInputWidgetBase(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;

	virtual void RemoveFromParent() override;

private:
	UFUNCTION() void HandleStickActivated();
	UFUNCTION() void HandleBoardMoved(const FVector2D& NewPosition);
	UFUNCTION() void HandleStickMoved(const FVector2D& NewPosition);
	UFUNCTION() void HandleStickInactivated();

private:
	UPROPERTY(meta = (BindWidget)) UPanelWidget* Panel_Left;
	UPROPERTY(meta = (BindWidget)) UZeeUIVirtualJoystick* Joystick;
	UPROPERTY(meta = (BindWidget)) UPanelWidget* Panel_Board;
	UPROPERTY(meta = (BindWidget)) UImage* Img_Stick;

	UPROPERTY(meta = (BindWidget)) UPanelWidget* Panel_Right;

	// UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true, BindWidgetAnim)) UWidgetAnimation* Anim_Opening;
	// UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true, BindWidgetAnim)) UWidgetAnimation* Anim_Closing;

protected:
	UFUNCTION()
	void HandleCloseAnimFinished();

};
