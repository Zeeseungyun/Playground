#pragma once
#include "CoreMinimal.h"
#include "Framework/SlateDelegates.h"
#include "Widgets/SCompoundWidget.h"
#include "Types/SlateAttribute.h"
#include "Misc/Attribute.h"
#include "Widgets/SlateControlledConstruction.h"

class ZEEUI_API SZeeUILobbyLogin : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SZeeUILobbyLogin)
		: _OnLoginClicked()
		{ }
		SLATE_EVENT( FOnClicked, OnLoginClicked )
	 SLATE_END_ARGS()
public:
	void Construct( const FArguments& InArgs );

	FString GetUserID() const;
	FString GetUserPW() const;

private:
	TSharedPtr<class SEditableTextBox> EditableTextBox_ID;
	TSharedPtr<class SEditableTextBox> EditableTextBox_PW;
};
