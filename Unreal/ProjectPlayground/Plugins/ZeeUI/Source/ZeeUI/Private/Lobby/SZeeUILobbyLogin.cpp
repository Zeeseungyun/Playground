#include "ZeeUI/Public/Lobby/SZeeUILobbyLogin.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/SOverlay.h"
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

void SZeeUILobbyLogin::Construct( const FArguments& InArgs )
{
	static int BodyRadius = 10.0;
	
	static FSlateBrush RoundedSlateBrush = FSlateRoundedBoxBrush(
		FLinearColor(0.03125f, 0.03125f, 0.03125f, 1.0f), 
		FVector4(BodyRadius, BodyRadius,BodyRadius, BodyRadius)
	);
	
	static FSlateBrush SlateBrush_IDPW = FSlateRoundedBoxBrush(
		FLinearColor(1, 0, 0, 1), 
		FVector4(20, 20, 20, 20)
	);

	static FSlateBrush SlateBrush_IDPW2 = FSlateRoundedBoxBrush(
		FLinearColor(0, 0, 0, 1), 
		FVector4(20, 20, 20, 20)
	);

	const FZeeUISlateStyle_Login& LoginMenuStyle = FZeeUISlateStyles::Get().GetWidgetStyle<FZeeUISlateStyle_Login>("Lobby/Login");
	const FZeeUISlateStyle_Common& CommonMenuStyle = FZeeUISlateStyles::Get().GetWidgetStyle<FZeeUISlateStyle_Common>("Common/Common");

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		[
			SNew(SImage)
			.ColorAndOpacity(FSlateColor(FLinearColor( 0.017642,  0.017642,  0.017642,  1.000000)))
		]
		+ SOverlay::Slot()
		[
			SNew(SGridPanel)
			.FillColumn(0, 1.0f)
			.FillRow(0, 0.3f)
			.FillRow(1, 0.3f)
			.FillRow(2, 0.2f)
			+ SGridPanel::Slot(0, 0)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.TextStyle(&LoginMenuStyle.LoginTitleTextStyle)
				.Text(LOCTEXT("Zee's Playground","Zee's Playground"))
			]
			+ SGridPanel::Slot(0, 1)
			[
				SNew(SGridPanel)
				.FillColumn(0, 2.0f)
				.FillColumn(1, 2.0f)
				.FillColumn(2, 2.0f)
				.FillRow(0, 1.0f)
				+ SGridPanel::Slot(1, 0)
				[
					SNew(SBorder)
					.BorderImage(&CommonMenuStyle.CommonBorderBrush)
					[
						SNew(SGridPanel)
						.FillRow(0, 2.0f)
						.FillRow(1, 2.0f)
						.FillRow(2, 2.0f)
						.FillColumn(0, 1.0f)
						+ SGridPanel::Slot(0, 0)
						.Padding(20)
						[
							SNew(SBorder)
							.BorderImage(&CommonMenuStyle.CommonBorderBrush)
							.Padding(15)
							[
								SNew(SGridPanel)
								.FillColumn(0, 2.0f)
								.FillColumn(1, 7.0f)
								.FillColumn(2, 1.0f)
								.FillRow(0, 1.0f)
								+ SGridPanel::Slot(0, 0)
								.HAlign(HAlign_Center)
								.VAlign(VAlign_Center)
								[
									SNew(STextBlock)
									.TextStyle(&LoginMenuStyle.LoginBoxTextStyle)
									.Text(LOCTEXT("ID", "ID"))
								]
								+ SGridPanel::Slot(1, 0)
								[
									SAssignNew(EditableTextBox_ID, SEditableTextBox)
									.Style(&LoginMenuStyle.LoginBoxEditableTextBoxStyle)
									.ForegroundColor(FSlateColor(FLinearColor(0, 0, 0, 1)))
								]
							]
						]
						+ SGridPanel::Slot(0, 1)
						.Padding(20)
						[
							SNew(SBorder)
							.BorderImage(&CommonMenuStyle.CommonBorderBrush)
							.Padding(15)
							[
								SNew(SGridPanel)
								.FillColumn(0, 2.0f)
								.FillColumn(1, 7.0f)
								.FillColumn(2, 1.0f)
								.FillRow(0, 1.0f)
								+ SGridPanel::Slot(0, 0)
								.HAlign(HAlign_Center)
								.VAlign(VAlign_Center)
								[
									SNew(STextBlock)
									.TextStyle(&LoginMenuStyle.LoginBoxTextStyle)
									.Text(LOCTEXT("PW", "PW"))
								]
								+ SGridPanel::Slot(1, 0)
								[
									SAssignNew(EditableTextBox_PW, SEditableTextBox)
									.Style(&LoginMenuStyle.LoginBoxEditableTextBoxStyle)
									.IsPassword(true)
									.ForegroundColor(FSlateColor(FLinearColor(0,0,0,1)))
								]
							]
						]
						+ SGridPanel::Slot(0, 2)
						.Padding(20)
						[
							SNew(SButton)
							.ButtonStyle(&LoginMenuStyle.LoginButtonStyle)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.OnClicked(InArgs._OnLoginClicked)
							[
								SNew(STextBlock)
								.TextStyle(&LoginMenuStyle.LoginButtonTextStyle)
								.Text(LOCTEXT("Login", "Login"))
							]
						]
					]
				]
			]
		]
	];
}

FString SZeeUILobbyLogin::GetUserID() const
{
	return EditableTextBox_ID->GetText().ToString();
}

FString SZeeUILobbyLogin::GetUserPW() const
{
	return EditableTextBox_PW->GetText().ToString();
}
