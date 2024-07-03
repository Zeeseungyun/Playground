#pragma once
#include "Styling/SlateWidgetStyle.h"
#include "SlateBasics.h"
#include "ZeeUISlateStyle_Common.generated.h" 

USTRUCT()
struct ZEEUI_API FZeeUISlateStyle_Common : public FSlateWidgetStyle
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
	static const FZeeUISlateStyle_Common& GetDefault();

	UPROPERTY(EditAnywhere)
	FButtonStyle CommonButtonStyle;

	UPROPERTY(EditAnywhere)
	FTextBlockStyle CommonTextStyle;

	UPROPERTY(EditAnywhere)
	FSlateBrush CommonBorderBrush;
};

// Provides a widget style container to allow us to edit properties in-editor
UCLASS(hidecategories = Object, MinimalAPI)
class UZeeUISlateStyle_CommonContainer : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	// This is our actual Style object. 
	UPROPERTY(EditAnywhere, Category = Appearance, meta = (ShowOnlyInnerProperties))
	FZeeUISlateStyle_Common SlateStyle;

	// Retrievs the style that this container manages. 
	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast<const struct FSlateWidgetStyle*>(&SlateStyle);
	}

};
