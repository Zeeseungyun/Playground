#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Private/Messages/Chat.pb.h"
#include "ZeeNet/Public/Messages/Chat.h"

namespace Zee::Net::Message::Convert
{
	template<typename FromT, typename ToT>	struct TIsConvertible;

	FORCEINLINE static void FromTo(const Zee::Proto::Chat::Speak& InFrom, FZeeNetChatSpeak& OutTo);
	FORCEINLINE static void FromTo(const FZeeNetChatSpeak& InFrom, Zee::Proto::Chat::Speak& OutTo);
	template<>	struct TIsConvertible<Zee::Proto::Chat::Speak, FZeeNetChatSpeak> { enum { Value = true }; };
	template<>	struct TIsConvertible<FZeeNetChatSpeak, Zee::Proto::Chat::Speak> { enum { Value = true }; };
}
