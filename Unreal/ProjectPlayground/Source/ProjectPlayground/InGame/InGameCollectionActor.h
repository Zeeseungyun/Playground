#pragma once
#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InGameCollectionActor.generated.h"

UCLASS()
class PROJECTPLAYGROUND_API AInGameCollectionActor : public AStaticMeshActor
{
	GENERATED_BODY()

	AInGameCollectionActor(const FObjectInitializer& ObjectInitializer);

private:
	UFUNCTION()	void BeginOverlap(AActor* InOverlappedActor, AActor* InOtherActor);
	UFUNCTION()	void EndOverlap(AActor* InOverlappedActor, AActor* InOtherActor);

	FReply OnCollect();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Appearance, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UWidgetComponent> WidgetComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Collection, meta = (AllowPrivateAccess = "true"))
	int32 CollectionId = -1;
};
