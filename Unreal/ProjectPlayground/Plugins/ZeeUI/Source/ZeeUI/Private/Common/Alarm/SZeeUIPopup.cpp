#include "ZeeUI/Public/Common/Alarm/SZeeUIPopup.h"
#include "Engine/GameViewportClient.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/SOverlay.h"

#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUILobbySlateStyles.h"
#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h"

#define LOCTEXT_NAMESPACE "FZeeUIModule"

void SZeeUIPopup::Construct(const FArguments& InArgs)
{
	const FZeeUILobbySlateStyle& MenuStyle = FZeeUILobbySlateStyles::Get().GetWidgetStyle<FZeeUILobbySlateStyle>("Style1");

	ViewportClient = InArgs._ViewportClient.Get();
	ChildSlot[
		SNew(SBorder)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Padding(20)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Text(FText::FromString(InArgs._Message.Get()))
				.TextStyle(&MenuStyle.LoginBoxTextStyle)
			]
			+ SVerticalBox::Slot()
			[
				SNew(SSpacer).Size(FVector2D(1.0f, 10.0f))
			]
			+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.OnClicked(this, &SZeeUIPopup::HandleClicked)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Confirm", "Confirm"))
					.TextStyle(&MenuStyle.LoginBoxTextStyle)
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
