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
	const FZeeUISlateStyle_Common& CommonMenuStyle = FZeeUISlateStyles::Get().GetWidgetStyle<FZeeUISlateStyle_Common>("Common/Common");
	const FZeeUISlateStyle_Login& MenuStyle = FZeeUISlateStyles::Get().GetWidgetStyle<FZeeUISlateStyle_Login>("Lobby/Login");

	static FSlateBrush SlateBrush_IDPW = FSlateRoundedBoxBrush(
		FLinearColor(1, 0, 0, 1),
		FVector4(20, 20, 20, 20)
	);

	static FSlateBrush SlateBrush_IDPW2 = FSlateRoundedBoxBrush(
		FLinearColor(0, 0, 0, 1),
		FVector4(20, 20, 20, 20)
	);

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
			.BorderImage(&CommonMenuStyle.CommonBorderBrush) //todo load from style set.
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
					.TextStyle(&MenuStyle.LoginBoxTextStyle)
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
						.Style(&MenuStyle.LoginBoxEditableTextBoxStyle)
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
						.ButtonStyle(&CommonMenuStyle.CommonButtonStyle)
						.ContentPadding(10.0f)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("OK", "OK"))
							.TextStyle(&MenuStyle.LoginBoxTextStyle)
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
						.ButtonStyle(&CommonMenuStyle.CommonButtonStyle)
						.OnClicked(this, &SZeeUICreateCharacter::OnCancel)
						.ContentPadding(10.0f)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("Cancel", "Cancel"))
							.TextStyle(&MenuStyle.LoginBoxTextStyle)
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
