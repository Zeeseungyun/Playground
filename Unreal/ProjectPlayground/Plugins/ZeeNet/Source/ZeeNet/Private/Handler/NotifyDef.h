#pragma once
#ifndef ZEENET_CASE_CONSUME_NOTIFY
	#define ZEENET_CASE_CONSUME_NOTIFY(MessageName, PropName) \
	case TZeeNetPacketTraits<FZeeNet##MessageName##PropName>::Point: \
	for (auto& Elem : NotifyHandlers) { \
		auto Pin = StaticCastSharedPtr<IZeeNetNotifyHandler_##MessageName>(Elem.Pin()); \
		Pin->OnNotify(Packet->GetCastMessage<FZeeNet##MessageName##PropName>()); \
	} \
	return true; 
#endif // ifndef ZEENET_CASE_CONSUME_NOTIFY

using FZeeNetNotifyHandlerArray = TArray<TWeakPtr<struct IZeeNetNotifyHandler>>;
