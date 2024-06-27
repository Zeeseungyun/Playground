#pragma once
#include "CoreMinimal.h"
#include "Framework/SlateDelegates.h"
#include "Widgets/SCompoundWidget.h"
#include "Types/SlateAttribute.h"
#include "Misc/Attribute.h"
#include "Widgets/SlateControlledConstruction.h"

class ZEEUI_API SZeeUICharacterSpot : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SZeeUICharacterSpot)
		: _CharacterName()
		, _OnClicked()
		{ }
		SLATE_ATTRIBUTE(FString, CharacterName)
		SLATE_EVENT( FOnClicked, OnClicked )
	 SLATE_END_ARGS()
public:
	/**
	 * Construct this widget
	 *
	 * @param	InArgs	The declaration data for this widget
	 */
	void Construct( const FArguments& InArgs );

	FString GetCharacterName() const;
	void SetCharacterName(const FString& InCharacterName);

private:
	TSharedPtr<class STextBlock> TB_CharacterName;
	TSharedPtr<class STextBlock> TB_ButtonText;
};
