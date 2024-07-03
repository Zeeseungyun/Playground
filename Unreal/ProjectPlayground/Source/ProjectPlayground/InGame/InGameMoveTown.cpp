#include "ProjectPlayground/InGame/InGameMoveTown.h"
#include "Components/SphereComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

#include "ProjectPlayground/Network/ZeeNetworkClientSubsystem.h"
#include "ZeeNet/Public/Messages/Dedicate.h"

AInGameMoveTown::AInGameMoveTown(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SpawnPositionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SpawnPosition"));
	SpawnPositionComponent->SetupAttachment(RootComponent);
	SpawnPositionComponent->SetSphereRadius(5.0f);
	SpawnPositionComponent->bNavigationRelevant = false;
	SpawnPositionComponent->SetCanEverAffectNavigation(false);
	SpawnPositionComponent->SetCollisionProfileName(TEXT("NoCollision"));
	SpawnPositionComponent->SetRelativeLocation(FVector(0.0f, 230.0f, 80.0f));
	SpawnPositionComponent->SetLineThickness(10.0f);
	SpawnPositionComponent->SetSphereRadius(100.0f);

	OnActorBeginOverlap.AddDynamic(this, &AInGameMoveTown::BeginOverlap);
}

void AInGameMoveTown::BeginOverlap(AActor* InOverlappedActor, AActor* InOtherActor)
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
	
	UE_LOG(LogTemp, Log, TEXT("ZeeLog, MoveTown Overlap"));
	
	FZeeNetDedicateMove Req;
	Req.ToServer.MapName = MoveTownMapName;
	Req.Character.UID = NetworkClientSubsystem->CharacterId;
	NetworkClientSubsystem->GetClient()->Request<FZeeNetDedicateMove>(Req, this, [NetworkClientSubsystem](const FZeeNetDedicateMove& InRes)
		{
			if (ZeeNetIsSuccess(InRes.RC))
			{
				const FString Options = FString::Printf(TEXT("Id=%lld"), NetworkClientSubsystem->UserId);
				UGameplayStatics::OpenLevel(NetworkClientSubsystem, *FString::Printf(TEXT("%s:%d"), *InRes.ToServer.Ip, InRes.ToServer.Port), true, Options);
			}
		}
	);
}

FTransform AInGameMoveTown::GetMoveTownTransform() const
{
	if (::IsValid(SpawnPositionComponent))
	{
		return SpawnPositionComponent->GetComponentTransform();
	}

	return FTransform();
}
