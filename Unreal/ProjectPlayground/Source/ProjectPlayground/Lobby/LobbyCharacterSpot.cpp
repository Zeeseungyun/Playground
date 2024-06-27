#include "ProjectPlayground/Lobby/LobbyCharacterSpot.h"
#include "Components/WidgetComponent.h"
#include "ZeeUI/Public/Lobby/SZeeUICharacterSpot.h"

ALobbyCharacterSpot::ALobbyCharacterSpot(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetupAttachment(RootComponent);
	WidgetComponent->SetSlateWidget(
		SAssignNew(CharacterSpotWidget, SZeeUICharacterSpot)
		.OnClicked_UObject(this, &ALobbyCharacterSpot::OnCharacterClicked)
	);

	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	WidgetComponent->SetDrawSize(FVector2D(400.f, 200.f));
}

void ALobbyCharacterSpot::Tick(float DeltaTime) //override
{
	Super::Tick(DeltaTime);

}

FReply ALobbyCharacterSpot::OnCharacterClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ZeeLog, ALobbyCharacterSpot::OnCharacterClicked"));
	if (CharacterSpotWidget->GetCharacterName().Len() == 0) //Create Character.
	{

	}
	else //Select Character.
	{
		//todo..
	}

	return FReply::Handled();
}
