#include "ZeeUI/Public/ZeeUISlateStyles.h"
#include "Slate/SlateGameResources.h"

void FZeeUISlateStyles::Initialize()
{
	if (!GetMenuStyleInstance().IsValid())
	{
		GetMenuStyleInstance() = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*GetMenuStyleInstance());
	}
}

void FZeeUISlateStyles::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*GetMenuStyleInstance());
	ensure(GetMenuStyleInstance().IsUnique());
	GetMenuStyleInstance().Reset();
}

FName FZeeUISlateStyles::GetStyleSetName()
{
	static const FName StyleSetName(TEXT("ZeeUILobbySlateStyles"));
	return StyleSetName;
}

TSharedRef<FSlateStyleSet> FZeeUISlateStyles::Create()
{
	return FSlateGameResources::New(FZeeUISlateStyles::GetStyleSetName(), "/ZeeUI/Styles/", "/ZeeUI/Styles/");
}

TSharedPtr<class FSlateStyleSet>& FZeeUISlateStyles::GetMenuStyleInstance()
{
	static TSharedPtr<class FSlateStyleSet> MenuStyleInstance;
	return MenuStyleInstance;
}

const ISlateStyle& FZeeUISlateStyles::Get()
{
	Initialize();
	return *GetMenuStyleInstance();
}
