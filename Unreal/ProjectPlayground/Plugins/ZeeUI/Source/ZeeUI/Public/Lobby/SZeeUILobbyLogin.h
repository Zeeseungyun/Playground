#pragma once
#include "CoreMinimal.h"
#include "Framework/SlateDelegates.h"
#include "Widgets/SCompoundWidget.h"
#include "Types/SlateAttribute.h"
#include "Misc/Attribute.h"
#include "Widgets/SlateControlledConstruction.h"

class SZeeUILobbyLogin : public SCompoundWidget
{
	SLATE_DECLARE_WIDGET_API(SZeeUILobbyLogin, SCompoundWidget, ZEEUI_API)

public:
	SLATE_BEGIN_ARGS(SZeeUILobbyLogin)
		: _OnLoginClicked()
		{ }
		SLATE_EVENT( FOnClicked, OnLoginClicked )
	 SLATE_END_ARGS()
public:
	/**
	 * Construct this widget
	 *
	 * @param	InArgs	The declaration data for this widget
	 */
	ZEEUI_API void Construct( const FArguments& InArgs );

	ZEEUI_API FString GetUserID() const;
	ZEEUI_API FString GetUserPW() const;

private:
	TSharedPtr<class SEditableTextBox> EditableTextBox_ID;
	TSharedPtr<class SEditableTextBox> EditableTextBox_PW;
	/** The delegate to execute when the button is clicked */
	FOnClicked OnLoginClicked;
};
