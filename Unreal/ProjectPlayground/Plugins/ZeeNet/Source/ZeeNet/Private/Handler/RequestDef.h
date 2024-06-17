#pragma once
#ifndef ZEENET_CASE_CONSUME_REQUEST
	#define ZEENET_CASE_CONSUME_REQUEST(MessageName, PropName) \
	case TZeeNetMapping_UnrealToPoint<FZeeNet##MessageName##PropName>::Point: \
	for (auto& Elem : RequestHandlers) { \
		auto Pin = StaticCastSharedPtr<IZeeNetRequestHandler_##MessageName>(Elem.Pin()); \
		auto Ret = Pin->OnRequest(Responser, Packet->GetCastMessage<FZeeNet##MessageName##PropName>()); \
		if( Ret != EZeeNetRequestHandlerResponse::NoResponse ) { \
			return Ret; \
		} \
	} \
	return EZeeNetRequestHandlerResponse::NoResponse; 
#endif // ifndef ZEENET_CASE_CONSUME_REQUEST

using FZeeNetRequestHandlerArray = TArray<TWeakPtr<struct IZeeNetRequestHandler>>;
