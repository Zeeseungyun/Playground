#include "ZeeUI/Public/Common/ZeeUITouchInputWidget.h"

#include "Components/Image.h"
#include "Components/WidgetSwitcher.h"
#include "Components/PanelWidget.h"
#include "Animation/WidgetAnimation.h"
#include "Animation/UMGSequenceTickManager.h"
#include "ZeeUI/Public/Common/ZeeUIVirtualJoystick.h"

UZeeUITouchInputWidgetBase::UZeeUITouchInputWidgetBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UZeeUITouchInputWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (::IsValid(Joystick))
	{
		Joystick->OnBoardMoved.AddDynamic(this, &UZeeUITouchInputWidgetBase::HandleBoardMoved);
		Joystick->OnStickMoved.AddDynamic(this, &UZeeUITouchInputWidgetBase::HandleStickMoved);
		Joystick->OnStickActivated.AddDynamic(this, &UZeeUITouchInputWidgetBase::HandleStickActivated);
		Joystick->OnStickInactivated.AddDynamic(this, &UZeeUITouchInputWidgetBase::HandleStickInactivated);

		FWidgetAnimationDynamicEvent FinishEvent;
		FinishEvent.BindDynamic(this, &UZeeUITouchInputWidgetBase::HandleCloseAnimFinished);
		// BindToAnimationFinished(Anim_Closing, FinishEvent);
	}
}

void UZeeUITouchInputWidgetBase::NativePreConstruct()
{
	if (::IsValid(Joystick) && ::IsValid(Panel_Left))
	{
		if (IsDesignTime())
		{
			Joystick->OnBoardMoved.AddDynamic(this, &UZeeUITouchInputWidgetBase::HandleBoardMoved);
			Joystick->OnStickMoved.AddDynamic(this, &UZeeUITouchInputWidgetBase::HandleStickMoved);
			Joystick->OnStickActivated.AddDynamic(this, &UZeeUITouchInputWidgetBase::HandleStickActivated);
			Joystick->OnStickInactivated.AddDynamic(this, &UZeeUITouchInputWidgetBase::HandleStickInactivated);
		}
		else
		{
			//if (::IsValid(Anim_Opening))
			//{
			//	PlayAnimationForward(Anim_Opening, 1.0f, true);
			//}
		}
	}
	Super::NativePreConstruct();
}

void UZeeUITouchInputWidgetBase::RemoveFromParent()
{
	//if (!HasAnyFlags(RF_BeginDestroyed) && ::IsValid(Anim_Closing))
	//{
	//	PlayAnimationForward(Anim_Closing);
	//}
	//else
	//{
		Super::RemoveFromParent();
	//}
}

void UZeeUITouchInputWidgetBase::HandleStickActivated()
{

}

void UZeeUITouchInputWidgetBase::HandleBoardMoved(const FVector2D& NewPosition)
{
	if (::IsValid(Joystick) && ::IsValid(Panel_Left) && ::IsValid(Panel_Board))
	{
		const FVector2D AbsoluteBoardPosition = Joystick->GetTickSpaceGeometry().LocalToAbsolute(NewPosition);
		const FVector2D NewBoardTranslation = Panel_Left->GetTickSpaceGeometry().AbsoluteToLocal(AbsoluteBoardPosition);
		Panel_Board->SetRenderTranslation(NewBoardTranslation);
	}
}

void UZeeUITouchInputWidgetBase::HandleStickMoved(const FVector2D& NewPosition)
{
	if (::IsValid(Joystick) && ::IsValid(Panel_Left) && ::IsValid(Img_Stick))
	{
		const FVector2D AbsoluteBoardPosition = Joystick->GetTickSpaceGeometry().LocalToAbsolute(NewPosition);
		const FVector2D NewBoardTranslation = Panel_Left->GetTickSpaceGeometry().AbsoluteToLocal(AbsoluteBoardPosition);
		Img_Stick->SetRenderTranslation(NewBoardTranslation);
	}
}

void UZeeUITouchInputWidgetBase::HandleStickInactivated()
{

}

void UZeeUITouchInputWidgetBase::HandleCloseAnimFinished()
{
	// ForceRemoveFromParent();
}

