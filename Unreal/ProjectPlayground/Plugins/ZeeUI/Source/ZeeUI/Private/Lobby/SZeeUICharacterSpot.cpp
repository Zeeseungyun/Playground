#include "ZeeUI/Public/Lobby/SZeeUICharacterSpot.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"
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

#define LOCTEXT_NAMESPACE "FZeeUIModule"

void SZeeUICharacterSpot::Construct( const FArguments& InArgs )
{
	const FZeeUISlateStyle_Login& Style = FZeeUISlateStyles::Get().GetWidgetStyle<FZeeUISlateStyle_Login>("Lobby/Login");
	
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.ButtonStyle(&Style.LoginButtonStyle)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.OnClicked(InArgs._OnClicked)
			[
				SNew(SBox)
				.HeightOverride(100.0f)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SAssignNew(TB_CharacterName, STextBlock)
						.TextStyle(&Style.LoginButtonTextStyle)
						.Visibility(EVisibility::Collapsed)
					]
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Center)
					[
						SAssignNew(TB_ButtonText, STextBlock)
						.TextStyle(&Style.LoginButtonTextStyle)
					]
				]
			]
		]
	];

	SetCharacterName(InArgs._CharacterName.Get());
}

FString SZeeUICharacterSpot::GetCharacterName() const
{
	return TB_CharacterName->GetText().ToString();
}

void SZeeUICharacterSpot::SetCharacterName(const FString& InCharacterName)
{
	TB_CharacterName->SetText(FText::FromString(InCharacterName));
	if (InCharacterName.Len() > 0)
	{
		TB_CharacterName->SetVisibility(EVisibility::HitTestInvisible);
		TB_ButtonText->SetText(LOCTEXT("Select Character", "Select Character"));
	}
	else
	{
		TB_CharacterName->SetVisibility(EVisibility::Collapsed);
		TB_ButtonText->SetText(LOCTEXT("Create Character", "Create Character"));
	}
}
