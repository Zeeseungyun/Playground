#pragma once
#include "Styling/SlateWidgetStyle.h"
#include "SlateBasics.h"
#include "ZeeUISlateStyle_InGame.generated.h" 

USTRUCT()
struct ZEEUI_API FZeeUISlateStyle_InGame : public FSlateWidgetStyle
{
	GENERATED_BODY()
public:
	// Stores a list of Brushes we are using (we aren't using any) into OutBrushes.
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;

	// Stores the TypeName for our widget style.
	static const FName TypeName;

	// Retrieves the type name for our global style, which will be used by our Style Set to load the right file. 
	virtual const FName GetTypeName() const override;

	// Allows us to set default values for our various styles. 
	static const FZeeUISlateStyle_InGame& GetDefault();

	UPROPERTY(EditAnywhere)
	FButtonStyle InGameButtonStyle;

	UPROPERTY(EditAnywhere)
	FTextBlockStyle InGameTextStyle;

	UPROPERTY(EditAnywhere)
	FSlateBrush InGameBorderBrush;
};

// Provides a widget style container to allow us to edit properties in-editor
UCLASS(hidecategories = Object, MinimalAPI)
class UZeeUISlateStyle_InGameContainer : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	// This is our actual Style object. 
	UPROPERTY(EditAnywhere, Category = Appearance, meta = (ShowOnlyInnerProperties))
	FZeeUISlateStyle_InGame SlateStyle;

	// Retrievs the style that this container manages. 
	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast<const struct FSlateWidgetStyle*>(&SlateStyle);
	}

};
