#include "ZeeUI/Public/Lobby/SZeeUICreateCharacter.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SBackgroundBlur.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Layout/SSpacer.h"

#include "Styling/CoreStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateStyleMacros.h"
#include "Styling/SlateTypes.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"

#include "ZeeUI/Public/ZeeUISlateStyles.h"
#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUISlateStyle_Login.h"
#include "ZeeUI/Public/Common/SlateStyle/ZeeUISlateStyle_Common.h"

#define LOCTEXT_NAMESPACE "FZeeUIModule"

void SZeeUICreateCharacter::Construct( const FArguments& InArgs )
{
	const FZeeUISlateStyle_Common& CommonStyle = FZeeUISlateStyles::Get().GetWidgetStyle<FZeeUISlateStyle_Common>("Common/Common");
	const FZeeUISlateStyle_Login& LoginStyle = FZeeUISlateStyles::Get().GetWidgetStyle<FZeeUISlateStyle_Login>("Lobby/Login");

	DelCancel = InArgs._OnCancel;
	DelConfirm = InArgs._OnConfirm;

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SBackgroundBlur)
			.BlurStrength(5)
		]
		+SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SBorder)
			.BorderImage(&CommonStyle.CommonBorderBrush) //todo load from style set.
			.Padding(10.0f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.FillHeight(100.0f)
				.Padding(20.0f)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Enter character name", "Enter character name"))
					.TextStyle(&LoginStyle.LoginBoxTextStyle)
				]
				+ SVerticalBox::Slot()
				.FillHeight(20.0f)
				+ SVerticalBox::Slot()
				.FillHeight(100.0f)
				.Padding(20.0f)
				[
					SNew(SBox)
					.HeightOverride(150.0f)
					[
						SAssignNew(ETB_CharacterName, SEditableTextBox)
						.Style(&LoginStyle.LoginBoxEditableTextBoxStyle)
						.ForegroundColor(FSlateColor(FLinearColor(0, 0, 0, 1)))
					]
				]
				+ SVerticalBox::Slot()
				.FillHeight(20.0f)
				+ SVerticalBox::Slot()
				.FillHeight(100.0f)
				.Padding(20.0f)
				.HAlign(HAlign_Fill)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.FillWidth(200.0f)
					[
						SNew(SButton)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.OnClicked(this, &SZeeUICreateCharacter::OnOK)
						.ButtonStyle(&CommonStyle.CommonButtonStyle)
						.ContentPadding(10.0f)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("OK", "OK"))
							.TextStyle(&LoginStyle.LoginBoxTextStyle)
						]
					]
					+ SHorizontalBox::Slot()
					.FillWidth(20.0f)
					+ SHorizontalBox::Slot()
					.FillWidth(200.0f)
					[
						SNew(SButton)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.ButtonStyle(&CommonStyle.CommonButtonStyle)
						.OnClicked(this, &SZeeUICreateCharacter::OnCancel)
						.ContentPadding(10.0f)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("Cancel", "Cancel"))
							.TextStyle(&LoginStyle.LoginBoxTextStyle)
						]
					]
				]
			]
		]
	];

}

FReply SZeeUICreateCharacter::OnCancel()
{
	DelCancel.ExecuteIfBound();
	return FReply::Handled();
}

FReply SZeeUICreateCharacter::OnOK()
{
	DelConfirm.ExecuteIfBound(ETB_CharacterName->GetText().ToString());
	return FReply::Handled();
}
