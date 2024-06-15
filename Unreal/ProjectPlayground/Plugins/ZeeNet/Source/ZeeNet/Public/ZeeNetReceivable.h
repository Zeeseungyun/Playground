// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Templates/SharedPointer.h"
#include "CoreMinimal.h"

struct ZEENET_API FZeeNetInvoker_Chat
{
public:
	DECLARE_EVENT_OneParam(FZeeNetClient, FOnConnected2, const struct FZeeNetChatSpeak& /*message if empty is success.*/);
	FOnConnected2& OnConnected2() { return EventConnected2; }
	FOnConnected2 EventConnected2;


};
