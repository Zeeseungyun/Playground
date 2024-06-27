// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ZeeNet/Public/ZeeNetClient.h"
#include "ZeeNetworkClientSubsystem.generated.h"

UCLASS()
class PROJECTPLAYGROUND_API UZeeNetworkClientSubsystem 
	: public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	static UZeeNetworkClientSubsystem* Get(UObject* InContextObject);

	/** Implement this for initialization of instances of the system */
	void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	void Deinitialize() override;

protected:
	TSharedPtr<class FZeeNetClient> MyClient;

	virtual void OnConnected(const FString& InMessage /*if empty is success*/);
	virtual void OnDisconnected();

	void Connect(const FString& InEndPoint);

public:
	void ConnectToGameServer();
	TSharedPtr<class FZeeNetClient> GetClient() const { return MyClient; }

};
