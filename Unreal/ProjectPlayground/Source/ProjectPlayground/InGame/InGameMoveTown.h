#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "InGameMoveTown.generated.h"

UCLASS()
class PROJECTPLAYGROUND_API AInGameMoveTown 
	: public ATriggerBox
{
	GENERATED_BODY()
public:
	AInGameMoveTown(const FObjectInitializer& ObjectInitializer);

private:
	UFUNCTION()	void BeginOverlap(AActor* InOverlappedActor, AActor* InOtherActor);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MoveTown, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> SpawnPositionComponent;

	UPROPERTY(EditInstanceOnly, Category = MoveTown)
	FString MoveTownMapName;

public:
	const FString& GetMoveTownMapName() const { return MoveTownMapName; }
	FTransform GetMoveTownTransform() const;
};
