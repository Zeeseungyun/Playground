#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketMapping.h"
#include "ZeeNet/Public/Interface/ZeeNetResponser.h"

/*
* ��û�� ������ �� �� �ְԲ� �Ǿ�����.
* ���� �ð��� �˳��ϴٸ� �����ϴ°ɷ�. ->FZeeNetClient���� ó���ؾ���.
* Ÿ�Ӿƿ��� �ɰ� �ð����� �ڵ鷯���� ó������ �ʴ´ٸ� FZeeNetClient���� ��޽����� ������ ������ ó���ϸ� ��������.
* ���� �ƹ��� �ڵ鸵 ���� �ʴ´ٸ� FZeeNetClient���� ��޽����� ������ �ٷ� ������ �ص�.
* RequestHandler�� ��� �߻��� ������ ������ ���� �ش� �޽����� ó���ϸ� �����.
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
	//���� �켱 ���� ���ڰ� ���� ���� �켱 ������ �ö�.
	virtual int32 GetPriority() const { return 0; }
};

//struct ZEENET_API IZeeNetRequestHandler_Authentication
//	: public IZeeNetRequestHandler
//{
//public:
//	const TCHAR* GetHandlerName() const final { return TEXT("Request_Authentication"); }
//	
//	//���� �ߴ����� ���� ���θ� ��ȯ.
//	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetAuthenticationLogin& InMessage) {
//		return EZeeNetRequestHandlerResponse::NoResponse;
//	}
//
//	TWeakPtr<IZeeNetResponser> TempResponser;
//	//���� �ߴ����� ���� ���θ� ��ȯ.
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
