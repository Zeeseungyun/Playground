#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUISlateStyle_Character.h"

void FZeeUISlateStyle_Character::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
}

const FName FZeeUISlateStyle_Character::TypeName = TEXT("FZeeUISlateStyle_Character");

const FName FZeeUISlateStyle_Character::GetTypeName() const
{
	return TypeName;
}

const FZeeUISlateStyle_Character& FZeeUISlateStyle_Character::GetDefault()
{
	static FZeeUISlateStyle_Character Default;
	return Default;
}
