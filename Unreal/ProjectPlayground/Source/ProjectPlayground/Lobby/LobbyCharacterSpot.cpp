#include "ProjectPlayground/Lobby/LobbyCharacterSpot.h"
#include "Components/WidgetComponent.h"

#include "ProjectPlayground/Lobby/LobbyCharacter.h"
#include "ZeeUI/Public/Lobby/SZeeUICharacterSpot.h"

ALobbyCharacterSpot::ALobbyCharacterSpot(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetupAttachment(RootComponent);
	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	WidgetComponent->SetDrawSize(FVector2D(400.f, 200.f));
	Update();
	PrimaryActorTick.bCanEverTick = false;
}

void ALobbyCharacterSpot::BeginPlay()
{
	Super::BeginPlay();
	WidgetComponent->SetSlateWidget(
		SAssignNew(CharacterSpotWidget, SZeeUICharacterSpot)
		.OnClicked_UObject(this, &ALobbyCharacterSpot::OnCharacterClicked)
	);

	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);
	if (AttachedActors.Num() > 0)
	{
		LobbyCharacterPtr = Cast<ALobbyCharacter>(AttachedActors[0]);
	}

	Update();
}

void ALobbyCharacterSpot::Update()
{
	const bool bVisible = CharacterSpotWidget.IsValid() && CharacterSpotWidget->GetCharacterName().Len() != 0;
	if (LobbyCharacterPtr.IsValid())
	{
		LobbyCharacterPtr->SetActorHiddenInGame(!bVisible);
	}
}

void ALobbyCharacterSpot::SetCharacterData(const FZeeNetDataCharacter& InData)
{
	CharacterData = InData;
	if (CharacterSpotWidget.IsValid())
	{
		CharacterSpotWidget->SetCharacterName(CharacterData.Name);
	}
	Update();
}

FReply ALobbyCharacterSpot::OnCharacterClicked()
{
	OnWidgetButtonClicked.Broadcast();
	return FReply::Handled();
}
