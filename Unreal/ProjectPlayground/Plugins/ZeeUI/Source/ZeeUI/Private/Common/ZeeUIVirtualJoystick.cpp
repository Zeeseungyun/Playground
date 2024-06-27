#include "ZeeUI/Public/Common/ZeeUIVirtualJoystick.h"
#include "ZeeUI/Public/Common/SZeeUIVirtualJoystick.h"

UZeeUIVirtualJoystick::UZeeUIVirtualJoystick()
	: bIsStickAutoReturnToCenter(true)
	, bIsBoardFixed(false)
	, bIsBoardAutoReturnToCenter(true)
	, bUsingAxisInput(true)
	, bIsXAxisInverted(false)
	, bIsYAxisInverted(false)
{
}

void UZeeUIVirtualJoystick::ReleaseSlateResources(bool bReleaseChildren) 
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyJoystick.Reset();
}

void UZeeUIVirtualJoystick::OnWidgetRebuilt()
{
	MyJoystick->RerfreshPositions(true);
}

#if WITH_EDITOR
const FText UZeeUIVirtualJoystick::GetPaletteCategory()
{
	return FText::FromString(TEXT("ZeeUIVirtualInput"));
}
#endif

TSharedRef<SWidget> UZeeUIVirtualJoystick::RebuildWidget() 
{
	MyJoystick = SNew(SZeeUIVirtualJoystick)
		.Owner(this)
		.CenterOffset(BIND_UOBJECT_ATTRIBUTE(const FVector2D*, GetAddressOfCenterOffset))
		.BoardRadius(BIND_UOBJECT_ATTRIBUTE(float, GetBoardRadius))
		.IsStickAutoReturnToCenter(BIND_UOBJECT_ATTRIBUTE(bool, IsStickAutoReturnToCenter))
		.IsBoardFixed(BIND_UOBJECT_ATTRIBUTE(bool, IsBoardFixed))
		.IsBoardAutoReturnToCenter(BIND_UOBJECT_ATTRIBUTE(bool, IsBoardAutoReturnToCenter))
		.UsingAxisInput(BIND_UOBJECT_ATTRIBUTE(bool, UsingAxisInput))
		.IsXAxisInverted(BIND_UOBJECT_ATTRIBUTE(bool, IsXAxisInverted))
		.IsYAxisInverted(BIND_UOBJECT_ATTRIBUTE(bool, IsYAxisInverted))
		.XAxisKey(BIND_UOBJECT_ATTRIBUTE(const FKey*, GetAddressOfXAxisKey))
		.YAxisKey(BIND_UOBJECT_ATTRIBUTE(const FKey*, GetAddressOfYAxisKey))

		.OnStickActivated(BIND_UOBJECT_DELEGATE(SZeeUIVirtualJoystick::FDel_OnStickActivated, HandleStickActivated))
		.OnBoardMoved(BIND_UOBJECT_DELEGATE(SZeeUIVirtualJoystick::FDel_OnBoardMoved, HandleBoardMoved))
		.OnStickMoved(BIND_UOBJECT_DELEGATE(SZeeUIVirtualJoystick::FDel_OnStickMoved, HandleStickMoved))
		.OnStickInactivated(BIND_UOBJECT_DELEGATE(SZeeUIVirtualJoystick::FDel_OnStickInactivated, HandleStickInactivated))
	;

	return MyJoystick.ToSharedRef();
}

void UZeeUIVirtualJoystick::HandleStickActivated()
{
	OnStickActivated.Broadcast();
}

void UZeeUIVirtualJoystick::HandleBoardMoved(const FVector2D& NewPosition)
{
	OnBoardMoved.Broadcast(NewPosition);
}

void UZeeUIVirtualJoystick::HandleStickMoved(const FVector2D& NewPosition)
{
	OnStickMoved.Broadcast(NewPosition);
}

void UZeeUIVirtualJoystick::HandleStickInactivated()
{
	OnStickInactivated.Broadcast();
}

int32 UZeeUIVirtualJoystick::GetCurrentTouchIndex() const
{
	if (MyJoystick)
	{
		return MyJoystick->GetCapturedTouchIndex();
	}

	return INDEX_NONE;
}

bool UZeeUIVirtualJoystick::IsActivated() const
{
	return GetCurrentTouchIndex() != INDEX_NONE;
}

const FVector2D& UZeeUIVirtualJoystick::GetStickDelta() const
{
	if (MyJoystick)
	{
		return MyJoystick->GetStickDelta();
	}

	return FVector2D::ZeroVector;
}

FVector2D UZeeUIVirtualJoystick::CalculateCenterPosition() const
{
	if (MyJoystick)
	{
		return MyJoystick->CalculateCenterPosition();
	}

	return FVector2D::ZeroVector;
}

const FVector2D& UZeeUIVirtualJoystick::GetBoardPosition() const
{
	if (MyJoystick)
	{
		return MyJoystick->GetBoardPosition();
	}

	return FVector2D::ZeroVector;
}

const FVector2D& UZeeUIVirtualJoystick::GetStickPosition() const
{
	if (MyJoystick)
	{
		return MyJoystick->GetStickPosition();
	}

	return FVector2D::ZeroVector;
}

const FVector2D& UZeeUIVirtualJoystick::GetTouchPosition() const
{
	if (MyJoystick)
	{
		return MyJoystick->GetTouchPosition();
	}

	return FVector2D::ZeroVector;
}

const FVector2D& UZeeUIVirtualJoystick::GetDistanceBoardBetweenStick() const
{
	if (MyJoystick)
	{
		return MyJoystick->GetDistanceBoardBetweenStick();
	}

	return FVector2D::ZeroVector;
}

bool UZeeUIVirtualJoystick::ForceChangeBoardPosition(FVector2D NewPosition)
{
	if (MyJoystick)
	{
		if (!IsBoardAutoReturnToCenter() && !MyJoystick->IsEnabled())
		{
			MyJoystick->BoardPositionChanged(NewPosition);
			return true;
		}
	}

	return false;
}

bool UZeeUIVirtualJoystick::ForceChangeStickPosition(FVector2D NewPosition)
{
	if (MyJoystick)
	{
		if (!IsStickAutoReturnToCenter() && !MyJoystick->IsEnabled())
		{
			MyJoystick->ForceStickPositionChanged(NewPosition);
			return true;
		}
	}

	return false;
}

bool UZeeUIVirtualJoystick::AbsoluteToLocalPositionInThisWidget(FVector2D AbsolutePosition, FVector2D& OutLocalPosition) const
{
	if (MyJoystick)
	{
		OutLocalPosition = MyJoystick->GetTickSpaceGeometry().AbsoluteToLocal(AbsolutePosition);
		return true;
	}

	return false;
}

void UZeeUIVirtualJoystick::ForceTouchEnd()
{
	if (MyJoystick)
	{
		MyJoystick->ForceTouchEnd();
	}
}
