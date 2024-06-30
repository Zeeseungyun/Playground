#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUILobbySlateStyles.h"
#include "Slate/SlateGameResources.h"

void FZeeUILobbySlateStyles::Initialize()
{
	if (!GetMenuStyleInstance().IsValid())
	{
		GetMenuStyleInstance() = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*GetMenuStyleInstance());
	}
}

void FZeeUILobbySlateStyles::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*GetMenuStyleInstance());
	ensure(GetMenuStyleInstance().IsUnique());
	GetMenuStyleInstance().Reset();
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

TSharedPtr<class FSlateStyleSet>& FZeeUILobbySlateStyles::GetMenuStyleInstance()
{
	static TSharedPtr<class FSlateStyleSet> MenuStyleInstance;
	return MenuStyleInstance;
}

const ISlateStyle& FZeeUILobbySlateStyles::Get()
{
	Initialize();
	return *GetMenuStyleInstance();
}
