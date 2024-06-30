#pragma once
#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InGameCollectionActor.generated.h"

UCLASS()
class PROJECTPLAYGROUND_API AInGameCollectionActor : public AStaticMeshActor
{
	GENERATED_BODY()

	AInGameCollectionActor(const FObjectInitializer& ObjectInitializer);

public:
	// Called every frame
	// virtual void Tick(float DeltaTime) override;
	// virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UWidgetComponent> WidgetComponent;
};
