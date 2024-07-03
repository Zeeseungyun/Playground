#include "ZeeUI/Public/Common/Alarm/SZeeUIPopup.h"
#include "Engine/GameViewportClient.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Layout/SBackgroundBlur.h"

#include "ZeeUI/Public/ZeeUISlateStyles.h"
#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUISlateStyle_Login.h"
#include "ZeeUI/Public/Common/SlateStyle/ZeeUISlateStyle_Common.h"

#define LOCTEXT_NAMESPACE "FZeeUIModule"

void SZeeUIPopup::Construct(const FArguments& InArgs)
{
	const FZeeUISlateStyle_Common& MenuStyle = FZeeUISlateStyles::Get().GetWidgetStyle<FZeeUISlateStyle_Common>("Common/Common");
	
	ViewportClient = InArgs._ViewportClient.Get();
	ChildSlot
	[
		SNew(SOverlay)
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SBackgroundBlur)
			.BlurStrength(10)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
		]
		+SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SBorder)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.Padding(20)
			.BorderImage(&MenuStyle.CommonBorderBrush)
			[
				SNew(SGridPanel)
				.FillColumn(0, 1.0f)
				.FillRow(0, 0.3f)
				.FillRow(1, 0.1f)
				.FillRow(2, 0.5f)
				+ SGridPanel::Slot(0, 0)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.Padding(20)
				[
					SNew(STextBlock)
					.Text(FText::FromString(InArgs._Message.Get()))
					.TextStyle(&MenuStyle.CommonTextStyle)
				]
				+ SGridPanel::Slot(0, 2)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.Padding(20)
				[
					SNew(SButton)
					.ButtonStyle(&MenuStyle.CommonButtonStyle)
					.OnClicked(this, &SZeeUIPopup::HandleClicked)
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					[
						SNew(SBox)
						.HeightOverride(150.0f)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("Confirm", "Confirm"))
							.TextStyle(&MenuStyle.CommonTextStyle)
						]
					]
				]
			]
		]
	];
}

FReply SZeeUIPopup::HandleClicked()
{
	if (ViewportClient.IsValid())
	{
		ViewportClient->RemoveViewportWidgetContent(AsShared());
	}

	return FReply::Handled();
}
