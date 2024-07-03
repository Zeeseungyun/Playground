#include "ZeeUI/Public/InGame/SlateStyle/ZeeUISlateStyle_InGame.h"

void FZeeUISlateStyle_InGame::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
}

const FName FZeeUISlateStyle_InGame::TypeName = TEXT("FZeeUISlateStyle_InGame");

const FName FZeeUISlateStyle_InGame::GetTypeName() const
{
	return TypeName;
}

const FZeeUISlateStyle_InGame& FZeeUISlateStyle_InGame::GetDefault()
{
	static FZeeUISlateStyle_InGame Default;
	return Default;
}
