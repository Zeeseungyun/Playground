#include "ZeeUI/Public/Common/SlateStyle/ZeeUISlateStyle_Common.h"

void FZeeUISlateStyle_Common::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
}

const FName FZeeUISlateStyle_Common::TypeName = TEXT("FZeeUISlateStyle_Common");

const FName FZeeUISlateStyle_Common::GetTypeName() const
{
	return TypeName;
}

const FZeeUISlateStyle_Common& FZeeUISlateStyle_Common::GetDefault()
{
	static FZeeUISlateStyle_Common Default;
	return Default;
}
