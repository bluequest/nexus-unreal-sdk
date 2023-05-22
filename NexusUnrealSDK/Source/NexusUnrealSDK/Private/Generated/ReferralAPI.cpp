/**
 * NOTE NOTE NOTE
 * GENERATED CODE
 * ANY CHANGES TO THIS FILE WILL BE OVERWRITTEN
 * PLEASE MAKE ANY CHANGES TO THE SDK TEMPLATES IN THE SDK GENERATOR
 */

#include "Generated/ReferralAPI.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "HttpModule.h"
#include "NexusShared.h"
#include "NexusUnrealSDK.h"

/**
 * Unreal SDK, descriptive comment goes here, notes about implementation, whatever we want really.
 */

namespace FGetReferralInfoByPlayerIdHelpers
{

	class FOnGetReferralInfoByPlayerIdRequestContext final : public NexusSDK::FRequestContext
	{
	public:
	FOnGetReferralInfoByPlayerIdRequestContext() = delete;
		FOnGetReferralInfoByPlayerIdRequestContext(FNexusReferralAPI::FOnGetReferralInfoByPlayerIdResponse InCallback, FNexusOnHttpErrorDelegate InErrorDelegate) 
		: Callback(InCallback)
		, ErrorDelegate(InErrorDelegate)
	{}

	void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
	{
		//TODO
		if (!bConnectedSuccessfully || !Response.IsValid())
		{
		// Didn't connect, or the response is null, bail
		//TODO: HANDLE THIS GRACEFULLY
		return;
		}
	

		if(Response->GetResponseCode() == static_cast<EHttpResponseCodes::Type>(200))
		{
			FNexusReferralGetReferralInfoByPlayerId200Response OutputResponse;

			// Create a Json object and parser
			const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
			TSharedPtr<FJsonObject> RootObject;

			// Parse it!
			if (!FJsonSerializer::Deserialize(Reader, RootObject))
			{
				// Parse error
				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
				return;
			}

			// Parse the response!
			// TODO(JoshD): Parse it!

			// Run the callback successfully!
				Callback.On200Response.ExecuteIfBound(OutputResponse);	

			
		}	

		if(Response->GetResponseCode() == static_cast<EHttpResponseCodes::Type>(400))
		{
			FNexusReferralReferralError OutputResponse;

			// Create a Json object and parser
			const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
			TSharedPtr<FJsonObject> RootObject;

			// Parse it!
			if (!FJsonSerializer::Deserialize(Reader, RootObject))
			{
				// Parse error
				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
				return;
			}

			// Parse the response!
			// TODO(JoshD): Parse it!

			// Run the callback successfully!
				Callback.On400Response.ExecuteIfBound(OutputResponse);	

			
		}	

		if(Response->GetResponseCode() != 200 || Response->GetResponseCode() != 400)
		{
			ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
		}
			
		// Now remove and delete ourselves from the module cache
		FNexusUnrealSDKModule::Get().RemoveRequest(this);
	}

	private:
		FNexusReferralAPI::FOnGetReferralInfoByPlayerIdResponse Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};



	bool GetReferralInfoByPlayerId_IsValid(const FNexusReferralGetReferralInfoByPlayerIdRequestParams& Request)
	{
		if (Request.page > 9999)
			return false;
		if (Request.page < 1)
			return false;
		if (Request.pageSize > 100)
			return false;
		if (Request.pageSize < 1)
			return false;

		return true;
	}	
}

void FNexusReferralAPI::GetReferralInfoByPlayerId(const FNexusReferralGetReferralInfoByPlayerIdRequestParams& RequestParams, FOnGetReferralInfoByPlayerIdResponse Response, FNexusOnHttpErrorDelegate ErrorDelegate)
{

	if(!FGetReferralInfoByPlayerIdHelpers::GetReferralInfoByPlayerId_IsValid(RequestParams))
	{
		ErrorDelegate.ExecuteIfBound(0);
		return;
	}
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/referrals/player/%s?groupId=%s&page=%d&pageSize=%d&excludeReferralList=%c"), *RequestParams.playerId, *RequestParams.groupId, RequestParams.page, RequestParams.pageSize, RequestParams.excludeReferralList);
		TUniquePtr<FGetReferralInfoByPlayerIdHelpers::FOnGetReferralInfoByPlayerIdRequestContext> RequestContext = MakeUnique<FGetReferralInfoByPlayerIdHelpers::FOnGetReferralInfoByPlayerIdRequestContext>(Response, ErrorDelegate);

		// TODO(JoshD): YO! Public key goes here

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetReferralInfoByPlayerIdHelpers::FOnGetReferralInfoByPlayerIdRequestContext::ProcessRequestComplete);

		// Hand ownership of the request over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();

}
namespace FGetPlayerCurrentReferralHelpers
{

	class FOnGetPlayerCurrentReferralRequestContext final : public NexusSDK::FRequestContext
	{
	public:
	FOnGetPlayerCurrentReferralRequestContext() = delete;
		FOnGetPlayerCurrentReferralRequestContext(FNexusReferralAPI::FOnGetPlayerCurrentReferralResponse InCallback, FNexusOnHttpErrorDelegate InErrorDelegate) 
		: Callback(InCallback)
		, ErrorDelegate(InErrorDelegate)
	{}

	void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
	{
		//TODO
		if (!bConnectedSuccessfully || !Response.IsValid())
		{
		// Didn't connect, or the response is null, bail
		//TODO: HANDLE THIS GRACEFULLY
		return;
		}
	

		if(Response->GetResponseCode() == static_cast<EHttpResponseCodes::Type>(200))
		{
			FString OutputResponse;

			// Create a Json object and parser
			const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
			TSharedPtr<FJsonObject> RootObject;

			// Parse it!
			if (!FJsonSerializer::Deserialize(Reader, RootObject))
			{
				// Parse error
				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
				return;
			}

			// Parse the response!
			// TODO(JoshD): Parse it!

			// Run the callback successfully!
				Callback.On200Response.ExecuteIfBound(OutputResponse);	

			
		}	

		if(Response->GetResponseCode() == static_cast<EHttpResponseCodes::Type>(404))
		{
			FNexusReferralGetPlayerCurrentReferral404Response OutputResponse;

			// Create a Json object and parser
			const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
			TSharedPtr<FJsonObject> RootObject;

			// Parse it!
			if (!FJsonSerializer::Deserialize(Reader, RootObject))
			{
				// Parse error
				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
				return;
			}

			// Parse the response!
			// TODO(JoshD): Parse it!

			// Run the callback successfully!
				Callback.On404Response.ExecuteIfBound(OutputResponse);	

			
		}	

		if(Response->GetResponseCode() != 200 || Response->GetResponseCode() != 404)
		{
			ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
		}
			
		// Now remove and delete ourselves from the module cache
		FNexusUnrealSDKModule::Get().RemoveRequest(this);
	}

	private:
		FNexusReferralAPI::FOnGetPlayerCurrentReferralResponse Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};


}

void FNexusReferralAPI::GetPlayerCurrentReferral(const FNexusReferralGetPlayerCurrentReferralRequestParams& RequestParams, FOnGetPlayerCurrentReferralResponse Response, FNexusOnHttpErrorDelegate ErrorDelegate)
{
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/referrals/player/%s/code?groupId=%s"), *RequestParams.playerId, *RequestParams.groupId);
		TUniquePtr<FGetPlayerCurrentReferralHelpers::FOnGetPlayerCurrentReferralRequestContext> RequestContext = MakeUnique<FGetPlayerCurrentReferralHelpers::FOnGetPlayerCurrentReferralRequestContext>(Response, ErrorDelegate);

		// TODO(JoshD): YO! Public key goes here

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetPlayerCurrentReferralHelpers::FOnGetPlayerCurrentReferralRequestContext::ProcessRequestComplete);

		// Hand ownership of the request over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();

}
namespace FGetReferralInfoByCodeHelpers
{

	class FOnGetReferralInfoByCodeRequestContext final : public NexusSDK::FRequestContext
	{
	public:
	FOnGetReferralInfoByCodeRequestContext() = delete;
		FOnGetReferralInfoByCodeRequestContext(FNexusReferralAPI::FOnGetReferralInfoByCodeResponse InCallback, FNexusOnHttpErrorDelegate InErrorDelegate) 
		: Callback(InCallback)
		, ErrorDelegate(InErrorDelegate)
	{}

	void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
	{
		//TODO
		if (!bConnectedSuccessfully || !Response.IsValid())
		{
		// Didn't connect, or the response is null, bail
		//TODO: HANDLE THIS GRACEFULLY
		return;
		}
	

		if(Response->GetResponseCode() == static_cast<EHttpResponseCodes::Type>(200))
		{
			FNexusReferralGetReferralInfoByCode200Response OutputResponse;

			// Create a Json object and parser
			const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
			TSharedPtr<FJsonObject> RootObject;

			// Parse it!
			if (!FJsonSerializer::Deserialize(Reader, RootObject))
			{
				// Parse error
				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
				return;
			}

			// Parse the response!
			// TODO(JoshD): Parse it!

			// Run the callback successfully!
				Callback.On200Response.ExecuteIfBound(OutputResponse);	

			
		}	

		if(Response->GetResponseCode() == static_cast<EHttpResponseCodes::Type>(400))
		{
			FNexusReferralReferralError OutputResponse;

			// Create a Json object and parser
			const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
			TSharedPtr<FJsonObject> RootObject;

			// Parse it!
			if (!FJsonSerializer::Deserialize(Reader, RootObject))
			{
				// Parse error
				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
				return;
			}

			// Parse the response!
			// TODO(JoshD): Parse it!

			// Run the callback successfully!
				Callback.On400Response.ExecuteIfBound(OutputResponse);	

			
		}	

		if(Response->GetResponseCode() != 200 || Response->GetResponseCode() != 400)
		{
			ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
		}
			
		// Now remove and delete ourselves from the module cache
		FNexusUnrealSDKModule::Get().RemoveRequest(this);
	}

	private:
		FNexusReferralAPI::FOnGetReferralInfoByCodeResponse Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};



	bool GetReferralInfoByCode_IsValid(const FNexusReferralGetReferralInfoByCodeRequestParams& Request)
	{
		if (Request.page > 9999)
			return false;
		if (Request.page < 1)
			return false;
		if (Request.pageSize > 100)
			return false;
		if (Request.pageSize < 1)
			return false;

		return true;
	}	
}

void FNexusReferralAPI::GetReferralInfoByCode(const FNexusReferralGetReferralInfoByCodeRequestParams& RequestParams, FOnGetReferralInfoByCodeResponse Response, FNexusOnHttpErrorDelegate ErrorDelegate)
{

	if(!FGetReferralInfoByCodeHelpers::GetReferralInfoByCode_IsValid(RequestParams))
	{
		ErrorDelegate.ExecuteIfBound(0);
		return;
	}
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/referrals/code/%s?groupId=%s&page=%d&pageSize=%d&excludeReferralList=%c"), *RequestParams.code, *RequestParams.groupId, RequestParams.page, RequestParams.pageSize, RequestParams.excludeReferralList);
		TUniquePtr<FGetReferralInfoByCodeHelpers::FOnGetReferralInfoByCodeRequestContext> RequestContext = MakeUnique<FGetReferralInfoByCodeHelpers::FOnGetReferralInfoByCodeRequestContext>(Response, ErrorDelegate);

		// TODO(JoshD): YO! Public key goes here

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetReferralInfoByCodeHelpers::FOnGetReferralInfoByCodeRequestContext::ProcessRequestComplete);

		// Hand ownership of the request over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();

}


UNexusGetReferralInfoByPlayerIdNode::UNexusGetReferralInfoByPlayerIdNode()
	: Super()
{

}

void UNexusGetReferralInfoByPlayerIdNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetReferralInfoByPlayerIdNode* UNexusGetReferralInfoByPlayerIdNode::GetReferralInfoByPlayerId(UObject* WorldContextObject, const FNexusReferralGetReferralInfoByPlayerIdRequestParams& InRequestParams)
{
	UNexusGetReferralInfoByPlayerIdNode* Task = NewObject<UNexusGetReferralInfoByPlayerIdNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetReferralInfoByPlayerIdNode::Activate()
{	

	FNexusReferralAPI::FOnGetReferralInfoByPlayerIdResponse Callback;
	Callback.On200Response = FNexusReferralAPI::FOnGetReferralInfoByPlayerId200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback);
	Callback.On400Response = FNexusReferralAPI::FOnGetReferralInfoByPlayerId400ResponseCallback::CreateUObject(this, &ThisClass::When400Callback);
	FNexusReferralAPI::GetReferralInfoByPlayerId(RequestParams, Callback, FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetReferralInfoByPlayerIdNode::When200Callback(FNexusReferralGetReferralInfoByPlayerId200Response Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

void UNexusGetReferralInfoByPlayerIdNode::When400Callback(FNexusReferralReferralError Param0)
{
	On400Response.Broadcast(Param0);
	SetReadyToDestroy();
}

UNexusGetPlayerCurrentReferralNode::UNexusGetPlayerCurrentReferralNode()
	: Super()
{

}

void UNexusGetPlayerCurrentReferralNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetPlayerCurrentReferralNode* UNexusGetPlayerCurrentReferralNode::GetPlayerCurrentReferral(UObject* WorldContextObject, const FNexusReferralGetPlayerCurrentReferralRequestParams& InRequestParams)
{
	UNexusGetPlayerCurrentReferralNode* Task = NewObject<UNexusGetPlayerCurrentReferralNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetPlayerCurrentReferralNode::Activate()
{	

	FNexusReferralAPI::FOnGetPlayerCurrentReferralResponse Callback;
	Callback.On200Response = FNexusReferralAPI::FOnGetPlayerCurrentReferral200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback);
	Callback.On404Response = FNexusReferralAPI::FOnGetPlayerCurrentReferral404ResponseCallback::CreateUObject(this, &ThisClass::When404Callback);
	FNexusReferralAPI::GetPlayerCurrentReferral(RequestParams, Callback, FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetPlayerCurrentReferralNode::When200Callback(FString Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

void UNexusGetPlayerCurrentReferralNode::When404Callback(FNexusReferralGetPlayerCurrentReferral404Response Param0)
{
	On404Response.Broadcast(Param0);
	SetReadyToDestroy();
}

UNexusGetReferralInfoByCodeNode::UNexusGetReferralInfoByCodeNode()
	: Super()
{

}

void UNexusGetReferralInfoByCodeNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetReferralInfoByCodeNode* UNexusGetReferralInfoByCodeNode::GetReferralInfoByCode(UObject* WorldContextObject, const FNexusReferralGetReferralInfoByCodeRequestParams& InRequestParams)
{
	UNexusGetReferralInfoByCodeNode* Task = NewObject<UNexusGetReferralInfoByCodeNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetReferralInfoByCodeNode::Activate()
{	

	FNexusReferralAPI::FOnGetReferralInfoByCodeResponse Callback;
	Callback.On200Response = FNexusReferralAPI::FOnGetReferralInfoByCode200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback);
	Callback.On400Response = FNexusReferralAPI::FOnGetReferralInfoByCode400ResponseCallback::CreateUObject(this, &ThisClass::When400Callback);
	FNexusReferralAPI::GetReferralInfoByCode(RequestParams, Callback, FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetReferralInfoByCodeNode::When200Callback(FNexusReferralGetReferralInfoByCode200Response Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

void UNexusGetReferralInfoByCodeNode::When400Callback(FNexusReferralReferralError Param0)
{
	On400Response.Broadcast(Param0);
	SetReadyToDestroy();
}
