#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUILobbySlateStyles.h"
#include "Slate/SlateGameResources.h"

TSharedPtr<FSlateStyleSet> FZeeUILobbySlateStyles::MenuStyleInstance;

void FZeeUILobbySlateStyles::Initialize()
{
	if (!MenuStyleInstance.IsValid())
	{
		MenuStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*MenuStyleInstance);
	}
}

void FZeeUILobbySlateStyles::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*MenuStyleInstance);
	ensure(MenuStyleInstance.IsUnique());
	MenuStyleInstance.Reset();
}

FName FZeeUILobbySlateStyles::GetStyleSetName()
{
	static const FName StyleSetName(TEXT("ZeeUILobbySlateStyles"));
	return StyleSetName;
}

TSharedRef<FSlateStyleSet> FZeeUILobbySlateStyles::Create()
{
	return FSlateGameResources::New(FZeeUILobbySlateStyles::GetStyleSetName(), "/ZeeUI/Styles/", "/ZeeUI/Styles/");
}

const ISlateStyle& FZeeUILobbySlateStyles::Get()
{
	return *MenuStyleInstance;
}