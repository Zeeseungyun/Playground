#include "ZeeUI/Public/Common/SZeeUIVirtualJoystick.h"
#include "SlateOptMacros.h"
#include "Components/Widget.h"
#include "Rendering/DrawElements.h"
#include "Framework/Application/SlateApplication.h"
#include "GameFramework/PlayerInput.h"

static int32 GZeeUIVirtualJoystickPlayTimeDebugVisibility = 0;
static FAutoConsoleVariableRef CVarGZeeUIVirtualJoystickPlayTimeDebugVisibility(
	TEXT("ZeeUI.VirtualJoystick.PlayTime.DebugVisibility"),
	GZeeUIVirtualJoystickPlayTimeDebugVisibility,
	TEXT("Whether to default virtual joystick debug visibility in play time is visible (Default: Invisible.)\n")
	TEXT(" 0: Invisible \n")
	TEXT(" 1: Visible"),
	ECVF_Default
);

static int32 GZeeUIVirtualJoystickDesignTimeDebugVisibility = 1;
static FAutoConsoleVariableRef CVarGZeeUIVirtualJoystickDesignTimeDebugVisibility(
	TEXT("ZeeUI.VirtualJoystick.DesignTime.DebugVisibility"),
	GZeeUIVirtualJoystickDesignTimeDebugVisibility,
	TEXT("Whether to default virtual joystick debug visibility in design time is visible(Default: Visible.)\n")
	TEXT(" 0: Invisible \n")
	TEXT(" 1: Visible"),
	ECVF_Default
);

void SZeeUIVirtualJoystick::Construct(const FArguments& InArgs)
{
	OwnerPtr = InArgs._Owner;
	check(OwnerPtr.IsValid());
	CenterOffset = InArgs._CenterOffset;
	BoardRadius = InArgs._BoardRadius;

	bIsStickAutoReturnToCenter = InArgs._IsStickAutoReturnToCenter;
	bIsBoardFixed = InArgs._IsBoardFixed;
	bIsBoardAutoReturnToCenter = InArgs._IsBoardAutoReturnToCenter;
	bUsingAxisInput = InArgs._UsingAxisInput;

	bIsXAxisInverted = InArgs._IsXAxisInverted;
	bIsYAxisInverted = InArgs._IsYAxisInverted;

	XAxisKey = InArgs._XAxisKey;
	YAxisKey = InArgs._YAxisKey;

	OnStickActivatedEvent = InArgs._OnStickActivated;
	OnBoardMovedEvent = InArgs._OnBoardMoved;
	OnStickMovedEvent = InArgs._OnStickMoved;
	OnStickInactivatedEvent = InArgs._OnStickInactivated;
}

int32 SZeeUIVirtualJoystick::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	if (!bIsPositioned)
	{
		SZeeUIVirtualJoystick* MutableThis = const_cast<SZeeUIVirtualJoystick*>(this);
		MutableThis->RerfreshPositions(true);
		MutableThis->bIsPositioned = true;
	}

	int32 RetLayerId = LayerId;

#if WITH_EDITOR
	static const FSlateBrush DefaultBrush;
	bool bPaint = false;
	bPaint |= !IsDesignTime() && GZeeUIVirtualJoystickPlayTimeDebugVisibility;
	bPaint |= IsDesignTime() && GZeeUIVirtualJoystickDesignTimeDebugVisibility;

	if (bPaint)
	{
		FSlateDrawElement::MakeBox(OutDrawElements, RetLayerId++, AllottedGeometry.ToPaintGeometry(), &DefaultBrush, ESlateDrawEffect::None, FLinearColor(1.0f, 0.0f, 1.0f, 0.3f));

		if (GetCapturedTouchIndex() != INDEX_NONE)
		{
			FSlateDrawElement::MakeLines(
				OutDrawElements,
				RetLayerId++,
				AllottedGeometry.ToPaintGeometry(),
				{
					GetBoardPosition(),
					GetStickPosition()
				},
				ESlateDrawEffect::None,
				FLinearColor(0.0f, 1.0f, 0.0f, 0.8f)
			);
		}
		else
		{
			if (IsStickAutoReturnToCenter())
			{
				FSlateDrawElement::MakeLines(
					OutDrawElements,
					RetLayerId++,
					AllottedGeometry.ToPaintGeometry(),
					{
						GetBoardPosition(),
						GetBoardPosition() + FVector2D(0, -1) * GetBoardRadius()
					},
					ESlateDrawEffect::None,
					FLinearColor(1.0f, 0.0f, 0.0f, 0.4f)
				);
			}
			else
			{
				if (IsDesignTime())
				{
					FSlateDrawElement::MakeLines(
						OutDrawElements,
						RetLayerId++,
						AllottedGeometry.ToPaintGeometry(),
						{
							GetBoardPosition(),
							GetBoardPosition() + FVector2D(0, -1) * GetBoardRadius()
						},
						ESlateDrawEffect::None,
						FLinearColor(1.0f, 0.0f, 0.0f, 0.4f)
					);
				}
				else
				{
					FSlateDrawElement::MakeLines(
						OutDrawElements,
						RetLayerId++,
						AllottedGeometry.ToPaintGeometry(),
						{
							GetBoardPosition(),
							GetStickPosition()
						},
						ESlateDrawEffect::None,
						FLinearColor(1.0f, 0.0f, 0.0f, 0.4f)
					);
				}
			}
		}
	}

#endif
	return RetLayerId;
}

FVector2D SZeeUIVirtualJoystick::ComputeDesiredSize(float) const
{
	return FVector2D(100, 100);
}

FReply SZeeUIVirtualJoystick::OnTouchStarted(const FGeometry& MyGeometry, const FPointerEvent& Event)
{
	if (GetCapturedTouchIndex() == INDEX_NONE)
	{
		TouchPosition = MyGeometry.AbsoluteToLocal(Event.GetScreenSpacePosition());
		if (IsBoardFixed())
		{
			const FVector2D TempCenterPosition = CalculateCenterPosition(MyGeometry);
			if (FVector2D::DistSquared(TempCenterPosition, GetTouchPosition()) > GetBoardRadiusSq())
			{
				return FReply::Unhandled();
			}
		}

		BoardPositionChanged(GetTouchPosition());
		StickMoved(GetTouchPosition());
		CapturedTouchIndex = (int32)Event.GetPointerIndex();

		OnStickActivatedEvent.ExecuteIfBound();
		return FReply::Handled().CaptureMouse(AsShared());
	}

	return FReply::Unhandled();
}

void SZeeUIVirtualJoystick::OnPostTouchMoved(int32 TouchIndex, const FVector2D& InTouchPosition)
{
	if (GetCapturedTouchIndex() == TouchIndex)
	{
		if (!bIsConsumedMoved)
		{
			StickMoved(GetTickSpaceGeometry().AbsoluteToLocal(InTouchPosition));
		}

		bIsConsumedMoved = false;
	}
}

void SZeeUIVirtualJoystick::RerfreshPositions(bool ForceToCenter)
{
	if (IsDesignTime() || ForceToCenter)
	{
		TouchPosition = CalculateCenterPosition();
		BoardPositionChanged(GetTouchPosition());

		StickPositionChanged(GetTouchPosition());
		DistanceBoardBetweenStick = StickDelta = FVector2D::ZeroVector;
	}
	else
	{
		if (IsBoardAutoReturnToCenter())
		{
			TouchPosition = CalculateCenterPosition();
			BoardPositionChanged(GetTouchPosition());
		}
		else
		{
			TouchPosition = GetBoardPosition();
		}

		if (IsStickAutoReturnToCenter())
		{
			StickPositionChanged(GetTouchPosition());
			DistanceBoardBetweenStick = StickDelta = FVector2D::ZeroVector;
		}
		else
		{
			StickPositionChanged(GetBoardPosition() + GetDistanceBoardBetweenStick());
			StickDelta = GetDistanceBoardBetweenStick() / GetBoardRadius();
		}

	}

}

void SZeeUIVirtualJoystick::Clear()
{
	if (UsingAxisInput() && IsEnabled())
	{
		ApplyAxis(-StickDelta, PrevAppliedDeltaTime);
	}

	RerfreshPositions();

	PrevAppliedDeltaTime = 0.0f;

	CapturedTouchIndex = INDEX_NONE;
}

void SZeeUIVirtualJoystick::OnPostTouchEnded(int32 TouchIndex, const FVector2D& InTouchPosition)
{
	if (GetCapturedTouchIndex() == TouchIndex)
	{
		ForceTouchEnd();
	}
}

void SZeeUIVirtualJoystick::ForceTouchEnd()
{
	if (GetCapturedTouchIndex() != INDEX_NONE)
	{
		Clear();
		OnStickInactivatedEvent.ExecuteIfBound();
	}
}

FReply SZeeUIVirtualJoystick::OnTouchMoved(const FGeometry& MyGeometry, const FPointerEvent& Event)
{
	if (Event.GetPointerIndex() == GetCapturedTouchIndex())
	{
		StickMoved(MyGeometry.AbsoluteToLocal(Event.GetScreenSpacePosition()));
		bIsConsumedMoved = true;
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

FReply SZeeUIVirtualJoystick::OnTouchEnded(const FGeometry& MyGeometry, const FPointerEvent& Event)
{
	if (Event.GetPointerIndex() == GetCapturedTouchIndex())
	{
		ForceTouchEnd();
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

bool SZeeUIVirtualJoystick::IsInteractable() const
{
	return IsEnabled();
}

void SZeeUIVirtualJoystick::ApplyAxis(const FVector2D& Delta, float InDeltaTime)
{
	if (UPlayerInput* PlayerInput = GetPlayerInput())
	{
		FVector2D NewDelta = Delta;
		if (GetRenderTransform().IsSet())
		{
			FTransform2D Temp = *GetRenderTransform();

			FQuat2D Rot(Temp.GetMatrix().GetRotationAngle());

			FMatrix2x2 Mat(Rot.Inverse());
			NewDelta = Mat.TransformVector(NewDelta);
		}

		FInputKeyParams Params;
		Params.NumSamples = 1;

		Params.Key = *XAxisKey.Get();
		Params.bIsGamepadOverride = XAxisKey.Get()->IsGamepadKey();
		Params.Delta = FVector(NewDelta.X * (IsXAxisInverted() ? -1 : 1), 0.0, 0.0);
		PlayerInput->InputKey(Params);

		Params.Key = *YAxisKey.Get();
		Params.bIsGamepadOverride = YAxisKey.Get()->IsGamepadKey();
		Params.Delta = FVector(-NewDelta.Y * (IsYAxisInverted() ? -1 : 1), 0.0, 0.0);
		PlayerInput->InputKey(Params);

		PrevAppliedDeltaTime = InDeltaTime;
	}
}

void SZeeUIVirtualJoystick::StickMoved(const FVector2D& NewStickLocation)
{
	TouchPosition = NewStickLocation;
	ForceStickPositionChanged(GetTouchPosition());
}

void SZeeUIVirtualJoystick::ForceStickPositionChanged(const FVector2D& NewStickPosition)
{
	DistanceBoardBetweenStick = NewStickPosition - GetBoardPosition();
	if (GetDistanceBoardBetweenStick().SizeSquared() > GetBoardRadiusSq())
	{
		DistanceBoardBetweenStick.Normalize();
		DistanceBoardBetweenStick *= GetBoardRadius();
		StickPositionChanged(GetDistanceBoardBetweenStick() + GetBoardPosition());
	}
	else
	{
		StickPositionChanged(NewStickPosition);
	}
}

void SZeeUIVirtualJoystick::StickPositionChanged(const FVector2D& NewStickPosition)
{
	StickPosition = NewStickPosition;
	OnStickMovedEvent.ExecuteIfBound(StickPosition);
}

void SZeeUIVirtualJoystick::BoardPositionChanged(const FVector2D& NewCenterPosition)
{
	if (NewCenterPosition != GetBoardPosition())
	{
		if (IsBoardFixed())
		{
			const FVector2D NewCenterPosition2 = CalculateCenterPosition();
			if (NewCenterPosition2 != BoardPosition)
			{
				BoardPosition = NewCenterPosition2;
				OnBoardMovedEvent.ExecuteIfBound(GetBoardPosition());
			}
		}
		else
		{
			BoardPosition = NewCenterPosition;
			OnBoardMovedEvent.ExecuteIfBound(GetBoardPosition());
		}
	}
}

void SZeeUIVirtualJoystick::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	if (CapturedTouchIndex != INDEX_NONE)
	{
		if (!IsEnabled())
		{
			ApplyAxis(FVector2D::ZeroVector, InDeltaTime);
			ForceTouchEnd();
			return;
		}

		StickDelta = GetDistanceBoardBetweenStick() / GetBoardRadius();

		if (UsingAxisInput())
		{
			ApplyAxis(GetStickDelta(), InDeltaTime);
		}
	}
	else
	{
		if (IsEnabled())
		{
			RerfreshPositions();
		}
	}
}

UPlayerInput* SZeeUIVirtualJoystick::GetPlayerInput() const
{
	if (OwnerPtr.IsValid())
	{
		if (APlayerController* OwningPlayer = OwnerPtr->GetOwningPlayer())
		{
			return OwningPlayer->PlayerInput;
		}
	}

	return nullptr;
}

bool SZeeUIVirtualJoystick::IsDesignTime() const
{
	if (OwnerPtr.IsValid())
	{
		return OwnerPtr->IsDesignTime();
	}

	return true;
}

FVector2D SZeeUIVirtualJoystick::CalculateCenterPosition() const
{
	return CalculateCenterPosition(GetTickSpaceGeometry());
}

FVector2D SZeeUIVirtualJoystick::CalculateCenterPosition(const FGeometry& TargetGeometry) const
{
	return *CenterOffset.Get() + TargetGeometry.AbsoluteToLocal(TargetGeometry.GetAbsolutePosition()) + TargetGeometry.GetLocalSize() / 2;
}

bool SZeeUIVirtualJoystick::OnTouchInputUnhandledFromViewport(ETouchType::Type TouchType, int32 TouchIndex, const FVector2D& InTouchPosition)
{
	if (GetCapturedTouchIndex() == TouchIndex)
	{
		switch (TouchType)
		{
		case ETouchType::Stationary:
		case ETouchType::ForceChanged:
		case ETouchType::FirstMove:
		case ETouchType::Moved:

			return true;
			break;

		case ETouchType::Ended:
			
			return true;
			break;

		case ETouchType::Began:
		default:
			break;
		}
	}
	return false;
}

FString SZeeUIVirtualJoystick::GetZeeUITouchInputConsumableDebugName() const
{
	if (OwnerPtr.IsValid())
	{
		return OwnerPtr->GetName();
	}

	return TEXT("ZeeUIVirtualJoystick");
}

 