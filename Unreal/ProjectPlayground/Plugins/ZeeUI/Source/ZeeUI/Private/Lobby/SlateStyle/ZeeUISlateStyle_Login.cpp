#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUISlateStyle_Login.h"

void FZeeUISlateStyle_Login::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
}

const FName FZeeUISlateStyle_Login::TypeName = TEXT("FZeeUISlateStyle_Login");

const FName FZeeUISlateStyle_Login::GetTypeName() const
{
	return TypeName;
}

const FZeeUISlateStyle_Login& FZeeUISlateStyle_Login::GetDefault()
{
	static FZeeUISlateStyle_Login Default;
	return Default;
}
