// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InGameCharacter.generated.h"

UCLASS()
class PROJECTPLAYGROUND_API AInGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AInGameCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//for replicates
	virtual void GetLifetimeReplicatedProps(TArray< class FLifetimeProperty >& OutLifetimeProps) const override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Appearance, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UWidgetComponent> CharacterNameComponent;

public:
	UPROPERTY(Replicated)
	FString CharacterName;
};
