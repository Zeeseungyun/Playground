#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h"

void FZeeUILobbySlateStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
}

const FName FZeeUILobbySlateStyle::TypeName = TEXT("FZeeUILobbySlateStyle");

const FName FZeeUILobbySlateStyle::GetTypeName() const
{
	return TypeName;
}

const FZeeUILobbySlateStyle& FZeeUILobbySlateStyle::GetDefault()
{
	static FZeeUILobbySlateStyle Default;
	return Default;
}
