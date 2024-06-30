#pragma once
#include "CoreMinimal.h"
#include "Framework/SlateDelegates.h"
#include "Widgets/SCompoundWidget.h"
#include "Types/SlateAttribute.h"
#include "Misc/Attribute.h"
#include "Widgets/SlateControlledConstruction.h"

class ZEEUI_API SZeeUICreateCharacter : public SCompoundWidget
{
public:
	DECLARE_DELEGATE_OneParam(FDel_OnConfirm, const FString&);
	DECLARE_DELEGATE(FDel_OnCancel);

public:
	SLATE_BEGIN_ARGS(SZeeUICreateCharacter)
		{ 		
		}
		SLATE_EVENT(FDel_OnConfirm, OnConfirm)
		SLATE_EVENT(FDel_OnCancel, OnCancel)
	SLATE_END_ARGS()
public:
	/**
	 * Construct this widget
	 *
	 * @param	InArgs	The declaration data for this widget
	 */
	void Construct( const FArguments& InArgs );
	
	FDel_OnConfirm DelConfirm;
private:
	FReply OnCancel();
	FReply OnOK();

private:
	FDel_OnCancel DelCancel;
	TSharedPtr<class SEditableTextBox> ETB_CharacterName;
};
