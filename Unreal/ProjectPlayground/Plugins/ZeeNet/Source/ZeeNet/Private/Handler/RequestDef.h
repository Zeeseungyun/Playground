#pragma once
#ifndef ZEENET_CASE_CONSUME_REQUEST
	#define ZEENET_CASE_CONSUME_REQUEST(CategoryName, MessageName) \
	case TZeeNetPacketTraits<FZeeNet##CategoryName##MessageName>::Point: \
	for (auto& Elem : RequestHandlers) { \
		auto Pin = StaticCastSharedPtr<IZeeNetRequestHandler_##CategoryName>(Elem.Pin()); \
		auto Ret = Pin->OnRequest(Responser, Packet->GetCastPacket<FZeeNet##CategoryName##MessageName>()); \
		if( Ret != EZeeNetRequestHandlerResponse::NoResponse ) { \
			return Ret; \
		} \
	} \
	return EZeeNetRequestHandlerResponse::NoResponse; 
#endif // ifndef ZEENET_CASE_CONSUME_REQUEST

using FZeeNetRequestHandlerArray = TArray<TWeakPtr<struct IZeeNetRequestHandler>>;
