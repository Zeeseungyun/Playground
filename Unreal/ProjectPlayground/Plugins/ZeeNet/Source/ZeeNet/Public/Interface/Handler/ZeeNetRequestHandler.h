#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketMapping.h"
#include "ZeeNet/Public/Interface/ZeeNetResponser.h"

/*
* 요청을 묵살할 수 도 있게끔 되어있음.
* 만약 시간이 넉넉하다면 수정하는걸로. ->FZeeNetClient에서 처리해야함.
* 타임아웃을 걸고 시간내에 핸들러들이 처리하지 않는다면 FZeeNetClient에서 빈메시지를 보내는 식으로 처리하면 좋을듯함.
* 현재 아무도 핸들링 하지 않는다면 FZeeNetClient에서 빈메시지로 응답을 바로 보내게 해둠.
* RequestHandler의 경우 발생할 문제로 누군가 먼저 해당 메시지를 처리하면 사라짐.
*/

enum class EZeeNetRequestHandlerResponse : uint8
{
	NoResponse,
	ResponseDirectly,
	ResponsePending,
};

struct ZEENET_API IZeeNetRequestHandler
{
public:
	virtual ~IZeeNetRequestHandler() = default;
	virtual const FString& GetHandlerName() const = 0;
	//응답 우선 순위 숫자가 작을 수록 우선 순위가 올라감.
	virtual int32 GetPriority() const { return 0; }
};

//struct ZEENET_API IZeeNetRequestHandler_Authentication
//	: public IZeeNetRequestHandler
//{
//public:
//	const TCHAR* GetHandlerName() const final { return TEXT("Request_Authentication"); }
//	
//	//응답 했는지에 대한 여부를 반환.
//	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetAuthenticationLogin& InMessage) {
//		return EZeeNetRequestHandlerResponse::NoResponse;
//	}
//
//	TWeakPtr<IZeeNetResponser> TempResponser;
//	//응답 했는지에 대한 여부를 반환.
//	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetAuthenticationLogin& InMessage) {
//		FZeeNetAuthenticationLogin Msg = InMessage;
//		//Msg.//
//		TempResponser = InResponser;
//		return EZeeNetRequestHandlerResponse::ResponsePending;
//	}
//
//	void DoSome() {
//		FZeeNetAuthenticationLogin Msg;
//
//		TempResponser->Response(Msg);
//	}
//};
