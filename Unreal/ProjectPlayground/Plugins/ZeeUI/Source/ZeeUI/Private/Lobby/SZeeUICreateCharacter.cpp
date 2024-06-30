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

#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUILobbySlateStyles.h"
#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h"

#define LOCTEXT_NAMESPACE "FZeeUIModule"

void SZeeUICreateCharacter::Construct( const FArguments& InArgs )
{
	const FZeeUILobbySlateStyle& MenuStyle = FZeeUILobbySlateStyles::Get().GetWidgetStyle<FZeeUILobbySlateStyle>("Style1");

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
			.HAlign(HAlign_Center)
			.HAlign(HAlign_Center)
			[
				SNew(SBorder)
				.BorderImage(&SlateBrush_IDPW) //todo load from style set.
				.Padding(FMargin(20.0f, 30.0f))
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					[
						SNew(STextBlock)
						.Text(LOCTEXT("Enter character name", "Enter character name"))
						.TextStyle(&MenuStyle.LoginBoxTextStyle)
					]
					+ SVerticalBox::Slot()
					[
						SNew(SSpacer)
						.Size(FVector2D(1.f, 10.0f))
					]
					+ SVerticalBox::Slot()
					[
						SAssignNew(ETB_CharacterName, SEditableTextBox)
						.Style(&MenuStyle.LoginBoxEditableTextBoxStyle)
						.ForegroundColor(FSlateColor(FLinearColor(0, 0, 0, 1)))
					]
					+ SVerticalBox::Slot()
					[
						SNew(SSpacer)
						.Size(FVector2D(1.f, 10.0f))
					]
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Center)
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.OnClicked(this, &SZeeUICreateCharacter::OnCancel)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("Cancel", "Cancel"))
								.TextStyle(&MenuStyle.LoginBoxTextStyle)
							]
						]
						+ SHorizontalBox::Slot()
						[
							SNew(SSpacer)
							.Size(FVector2D(30.f, 1.0f))
						]
						+ SHorizontalBox::Slot()
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.OnClicked(this, &SZeeUICreateCharacter::OnOK)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("OK", "OK"))
								.TextStyle(&MenuStyle.LoginBoxTextStyle)
							]
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
