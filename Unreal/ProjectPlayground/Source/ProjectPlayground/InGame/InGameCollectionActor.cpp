#include "ProjectPlayground/InGame/InGameCollectionActor.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

#include "ProjectPlayground/Network/ZeeNetworkClientSubsystem.h"
#include "ZeeNet/Public/Messages/Collection.h" 

#include "ZeeUI/Public/ZeeUISlateStyles.h"
#include "ZeeUI/Public/InGame/SlateStyle/ZeeUISlateStyle_InGame.h"

#define LOCTEXT_NAMESPACE "InGameCollectionActor"

AInGameCollectionActor::AInGameCollectionActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	PrimaryActorTick.bCanEverTick = false;

	GetStaticMeshComponent()->SetCollisionProfileName(TEXT("NoCollision"));
	GetStaticMeshComponent()->bNavigationRelevant = false;
	UStaticMesh* Mokoko = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, TEXT("/Script/Engine.StaticMesh'/Game/InGame/Mokoko.Mokoko'")));
	GetStaticMeshComponent()->SetStaticMesh(Mokoko);
	GetStaticMeshComponent()->SetRelativeScale3D(FVector(20.0f, 20.0f, 20.0f));
	GetStaticMeshComponent()->SetCanEverAffectNavigation(false);

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetupAttachment(RootComponent);
	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	WidgetComponent->SetDrawAtDesiredSize(true);
	WidgetComponent->SetVisibility(false);
	
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->SetSphereRadius(5.0f);
	SphereComponent->bNavigationRelevant = false;
	SphereComponent->SetCanEverAffectNavigation(false);
	SphereComponent->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	OnActorBeginOverlap.AddDynamic(this, &AInGameCollectionActor::BeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AInGameCollectionActor::EndOverlap);
}

void AInGameCollectionActor::BeginOverlap(AActor* InOverlappedActor, AActor* InOtherActor)
{
	if (HasAuthority())
	{
		return;
	}

	if (GetWorld()->GetFirstPlayerController()->GetPawn() != InOtherActor)
	{
		return;
	}

	UZeeNetworkClientSubsystem* NetworkClientSubsystem = UZeeNetworkClientSubsystem::Get(this);
	if (!::IsValid(NetworkClientSubsystem))
	{
		return;
	}

	if (NetworkClientSubsystem->CollectionIds.Contains(CollectionId))
	{
		return;
	}

	WidgetComponent->SetVisibility(true);
	if (!WidgetComponent->GetSlateWidget().IsValid())
	{
		const FZeeUISlateStyle_InGame& Style = FZeeUISlateStyles::Get().GetWidgetStyle<FZeeUISlateStyle_InGame>("InGame/InGame");
		
		WidgetComponent->SetSlateWidget(
			SNew(SButton)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.OnClicked(FOnClicked::CreateUObject(this, &AInGameCollectionActor::OnCollect))
			.ButtonStyle(&Style.InGameButtonStyle)
			[
				SNew(STextBlock)
				.TextStyle(&Style.InGameTextStyle)
				.Text(LOCTEXT("Collect", "Collect"))
			]
		);
	}
}

FReply AInGameCollectionActor::OnCollect()
{
	UZeeNetworkClientSubsystem* NetworkClientSubsystem = UZeeNetworkClientSubsystem::Get(this);
	if (!::IsValid(NetworkClientSubsystem))
	{
		return FReply::Handled();
	}

	if (NetworkClientSubsystem->CollectionIds.Contains(CollectionId))
	{
		return FReply::Handled();
	}

	FZeeNetCollectionCollect Req;
	Req.Id = CollectionId;

	NetworkClientSubsystem->GetClient()->Request<FZeeNetCollectionCollect>(Req, this, [this, NetworkClientSubsystem](const FZeeNetCollectionCollect& InRes)
		{
			if (ZeeNetIsSuccess(InRes.RC))
			{
				NetworkClientSubsystem->CollectionIds.Add(InRes.Id);
				WidgetComponent->SetVisibility(false);
			}
		}
	);

	return FReply::Handled();
}

void AInGameCollectionActor::EndOverlap(AActor* InOverlappedActor, AActor* InOtherActor)
{
	if (HasAuthority())
	{
		return;
	}

	if (GetWorld()->GetFirstPlayerController()->GetPawn() != InOtherActor)
	{
		return;
	}

	WidgetComponent->SetVisibility(false);
}
