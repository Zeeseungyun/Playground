#pragma once
#include "CoreMinimal.h"
#include "Framework/SlateDelegates.h"
#include "Widgets/SCompoundWidget.h"
#include "Types/SlateAttribute.h"
#include "Misc/Attribute.h"
#include "Widgets/SlateControlledConstruction.h"

class ZEEUI_API SZeeUIPopup : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SZeeUIPopup)
		: _ViewportClient(nullptr)
		, _Message(TEXT(""))
	{ }
		SLATE_ARGUMENT(class UGameViewportClient*, ViewportClient)
		SLATE_ATTRIBUTE(FString, Message)
	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

private:
	FReply HandleClicked();

private:
	TWeakObjectPtr<class UGameViewportClient> ViewportClient;

public:
	static void Show(const FString& InMessage, class UGameViewportClient* ViewportClient);
};
