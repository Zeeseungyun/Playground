// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "Input/Reply.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SLeafWidget.h"

class FPaintArgs;
class FSlateWindowElementList;
class UWidget;
class UPlayerInput;

class ZEEUI_API SZeeUIVirtualJoystick : public SLeafWidget
{
public:
	DECLARE_DELEGATE(FDel_OnStickActivated);
	DECLARE_DELEGATE_OneParam(FDel_OnBoardMoved, const FVector2D&/*NewPosition*/);
	DECLARE_DELEGATE_OneParam(FDel_OnStickMoved, const FVector2D&/*NewPosition*/);
	DECLARE_DELEGATE(FDel_OnStickInactivated);

public:
	SLATE_BEGIN_ARGS(SZeeUIVirtualJoystick)
		: _Owner(nullptr)
		, _CenterOffset(&FVector2D::ZeroVector)
		, _BoardRadius(200.0f)
		, _IsStickAutoReturnToCenter(true)
		, _IsBoardFixed(false)
		, _IsBoardAutoReturnToCenter(true)
		, _UsingAxisInput(true)
		, _IsXAxisInverted(false)
		, _IsYAxisInverted(false)
		, _XAxisKey(&EKeys::Gamepad_LeftX)
		, _YAxisKey(&EKeys::Gamepad_LeftY)
	{
	}
		SLATE_ARGUMENT(UWidget*, Owner)

		SLATE_ATTRIBUTE(const FVector2D*, CenterOffset)
		SLATE_ATTRIBUTE(float, BoardRadius)
		SLATE_ATTRIBUTE(bool, IsStickAutoReturnToCenter)
		SLATE_ATTRIBUTE(bool, IsBoardFixed)
		SLATE_ATTRIBUTE(bool, IsBoardAutoReturnToCenter)
		SLATE_ATTRIBUTE(bool, UsingAxisInput)
		SLATE_ATTRIBUTE(bool, IsXAxisInverted)
		SLATE_ATTRIBUTE(bool, IsYAxisInverted)
		SLATE_ATTRIBUTE(const FKey*, XAxisKey)
		SLATE_ATTRIBUTE(const FKey*, YAxisKey)

		SLATE_EVENT(FDel_OnStickActivated, OnStickActivated)
		SLATE_EVENT(FDel_OnBoardMoved, OnBoardMoved)
		SLATE_EVENT(FDel_OnStickMoved, OnStickMoved)
		SLATE_EVENT(FDel_OnStickInactivated, OnStickInactivated)

	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

	//~Begin SWidget interface

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

	virtual FVector2D ComputeDesiredSize(float) const override;

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

	virtual FReply OnTouchStarted(const FGeometry& MyGeometry, const FPointerEvent& Event) override;
	virtual FReply OnTouchMoved(const FGeometry& MyGeometry, const FPointerEvent& Event) override;
	virtual FReply OnTouchEnded(const FGeometry& MyGeometry, const FPointerEvent& Event) override;

	virtual bool IsInteractable() const override;
	//~End SWidget interface

	//~Begin IZeeUITouchInputConsumable interface

	virtual bool OnTouchInputUnhandledFromViewport(ETouchType::Type TouchType, int32 TouchIndex, const FVector2D& TouchPosition);
	virtual FString GetZeeUITouchInputConsumableDebugName() const;

	//~End IZeeUITouchInputConsumable interface

public:
	bool IsStickAutoReturnToCenter() const { return bIsStickAutoReturnToCenter.Get(); }
	bool IsBoardFixed() const { return bIsBoardFixed.Get(); }
	bool IsBoardAutoReturnToCenter() const { return bIsBoardAutoReturnToCenter.Get(); }
	bool UsingAxisInput() const { return bUsingAxisInput.Get(); }
	bool IsXAxisInverted() const { return bIsXAxisInverted.Get(); }
	bool IsYAxisInverted() const { return bIsYAxisInverted.Get(); }

	const FVector2D& GetStickDelta() const { return StickDelta; }
	const FVector2D& GetBoardPosition() const { return BoardPosition; }
	const FVector2D& GetStickPosition() const { return StickPosition; }
	const FVector2D& GetTouchPosition() const { return TouchPosition; }
	const FVector2D& GetDistanceBoardBetweenStick() const { return DistanceBoardBetweenStick; }

	FVector2D CalculateCenterPosition() const;
	FVector2D CalculateCenterPosition(const FGeometry& TargetGeometry) const;

	float GetBoardRadius() const { return BoardRadius.Get(); }
	float GetBoardRadiusSq() const { return FMath::Square(GetBoardRadius()); }

	int32 GetCapturedTouchIndex() const { return CapturedTouchIndex; }
	void Clear();
	void RerfreshPositions(bool ForceToCenter = false);

protected:
	virtual void OnPostTouchMoved(int32 TouchIndex, const FVector2D& TouchPosition);
	virtual void OnPostTouchEnded(int32 TouchIndex, const FVector2D& TouchPosition);

private:
	void ApplyAxis(const FVector2D& Delta, float InDeltaTime);
	void StickMoved(const FVector2D& NewLocation);

public:
	void ForceTouchEnd();
	void ForceStickPositionChanged(const FVector2D& NewStickPosition);
	void StickPositionChanged(const FVector2D& NewStickPosition);
	void BoardPositionChanged(const FVector2D& NewBoardPosition);

private:
	UPlayerInput* GetPlayerInput() const;

	bool IsDesignTime() const;

	//attributes
private:
	FDel_OnStickActivated OnStickActivatedEvent;
	FDel_OnBoardMoved OnBoardMovedEvent;
	FDel_OnStickMoved OnStickMovedEvent;
	FDel_OnStickInactivated OnStickInactivatedEvent;

	TWeakObjectPtr<UWidget> OwnerPtr;
	TAttribute<const FVector2D*> CenterOffset; // = FVector2D::ZeroVector;
	TAttribute<float> BoardRadius; // = 200.0f;
	TAttribute<bool> bIsStickAutoReturnToCenter; // = true;
	TAttribute<bool> bIsBoardFixed; // = true;
	TAttribute<bool> bIsBoardAutoReturnToCenter; // = true;
	TAttribute<bool> bUsingAxisInput; // = true;

	TAttribute<bool> bIsXAxisInverted; // = false;
	TAttribute<bool> bIsYAxisInverted; // = false;

	TAttribute<const FKey*> XAxisKey; // = Gamepad_LeftX;
	TAttribute<const FKey*> YAxisKey; // = Gamepad_LeftY;

	//variables
private:
	int32 CapturedTouchIndex = INDEX_NONE;
	FDelegateHandle MovedDelegateHandle, EndedDelegateHandle;
	bool bIsPositioned = false;

	bool bIsConsumedMoved = false;

	float PrevAppliedDeltaTime = 0.0f;

	FVector2D BoardPosition = FVector2D::ZeroVector;
	FVector2D StickPosition = FVector2D::ZeroVector;
	FVector2D TouchPosition = FVector2D::ZeroVector;

	FVector2D DistanceBoardBetweenStick = FVector2D::ZeroVector;
	FVector2D StickDelta = FVector2D::ZeroVector;
};

 