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
#include "DOM/JsonObject.h"
#include "JsonObjectConverter.h"
#include "NexusShared.h"
#include "NexusSettings.h"
#include "NexusUnrealSDK.h"

/**
 * Unreal SDK, descriptive comment goes here, notes about implementation, whatever we want really.
 */

/*---------------------------------------------------------------------------------------------
		API Functions
---------------------------------------------------------------------------------------------*/

namespace FGetReferralInfoByPlayerIdHelpers
{
	class FOnGetReferralInfoByPlayerIdRequestContext final : public NexusSDK::FRequestContext
	{
	public:
		FOnGetReferralInfoByPlayerIdRequestContext() = delete;
		FOnGetReferralInfoByPlayerIdRequestContext(const FNexusReferralAPI::FOnGetReferralInfoByPlayerIdResponse& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response is null, bail
				// TODO: Going to call the error delegate with an unknown response code as an answer to this for now
				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusReferralGetReferralInfoByPlayerId200Response OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Parse error
					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					// TODO: Hmm, this probably shouldn't be fatal, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this shouldn't ever happen. So alert a programmer running in the debugger.
					// TODO: Implement this commented out code!
					//UE_LOG( LogNexusSDK, FailureReason );
					UE_DEBUG_BREAK();
					ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Run the main callback!
				Callback.On200Response.ExecuteIfBound(OutputResponse);	
			}
			if (Response->GetResponseCode() == 400)
			{
				FNexusReferralReferralError OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Parse error
					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					// TODO: Hmm, this probably shouldn't be fatal, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this shouldn't ever happen. So alert a programmer running in the debugger.
					// TODO: Implement this commented out code!
					//UE_LOG( LogNexusSDK, FailureReason );
					UE_DEBUG_BREAK();
					ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Run the main callback!
				Callback.On400Response.ExecuteIfBound(OutputResponse);	
			}

			if (Response->GetResponseCode() != 200 && Response->GetResponseCode() != 400)
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

} // namespace FGetReferralInfoByPlayerIdHelpers

void FNexusReferralAPI::GetReferralInfoByPlayerId(const FNexusReferralGetReferralInfoByPlayerIdRequestParams& RequestParams, const FOnGetReferralInfoByPlayerIdResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	if (!FGetReferralInfoByPlayerIdHelpers::GetReferralInfoByPlayerId_IsValid(RequestParams))
	{
		ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
		return;
	}

	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/referrals/player/%s?groupId=%s&page=%d&pageSize=%d&excludeReferralList=%c"), *RequestParams.playerId, *RequestParams.groupId, RequestParams.page, RequestParams.pageSize, RequestParams.excludeReferralList);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetReferralInfoByPlayerIdHelpers::FOnGetReferralInfoByPlayerIdRequestContext> RequestContext = MakeUnique<FGetReferralInfoByPlayerIdHelpers::FOnGetReferralInfoByPlayerIdRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetReferralInfoByPlayerIdHelpers::FOnGetReferralInfoByPlayerIdRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
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
		FOnGetPlayerCurrentReferralRequestContext(const FNexusReferralAPI::FOnGetPlayerCurrentReferralResponse& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response is null, bail
				// TODO: Going to call the error delegate with an unknown response code as an answer to this for now
				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FString OutputResponse;

				// 'getPlayerCurrentReferral' returns a single string and no json body, in contrast to everything else.
				// So just paste the response into the string!
				OutputResponse = Response->GetContentAsString();

				// Run the main callback!
				Callback.On200Response.ExecuteIfBound(OutputResponse);	
			}
			if (Response->GetResponseCode() == 404)
			{
				FNexusReferralGetPlayerCurrentReferral404Response OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Parse error
					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					// TODO: Hmm, this probably shouldn't be fatal, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this shouldn't ever happen. So alert a programmer running in the debugger.
					// TODO: Implement this commented out code!
					//UE_LOG( LogNexusSDK, FailureReason );
					UE_DEBUG_BREAK();
					ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Run the main callback!
				Callback.On404Response.ExecuteIfBound(OutputResponse);	
			}

			if (Response->GetResponseCode() != 200 && Response->GetResponseCode() != 404)
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


} // namespace FGetPlayerCurrentReferralHelpers

void FNexusReferralAPI::GetPlayerCurrentReferral(const FNexusReferralGetPlayerCurrentReferralRequestParams& RequestParams, const FOnGetPlayerCurrentReferralResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/referrals/player/%s/code?groupId=%s"), *RequestParams.playerId, *RequestParams.groupId);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetPlayerCurrentReferralHelpers::FOnGetPlayerCurrentReferralRequestContext> RequestContext = MakeUnique<FGetPlayerCurrentReferralHelpers::FOnGetPlayerCurrentReferralRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetPlayerCurrentReferralHelpers::FOnGetPlayerCurrentReferralRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
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
		FOnGetReferralInfoByCodeRequestContext(const FNexusReferralAPI::FOnGetReferralInfoByCodeResponse& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response is null, bail
				// TODO: Going to call the error delegate with an unknown response code as an answer to this for now
				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusReferralGetReferralInfoByCode200Response OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Parse error
					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					// TODO: Hmm, this probably shouldn't be fatal, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this shouldn't ever happen. So alert a programmer running in the debugger.
					// TODO: Implement this commented out code!
					//UE_LOG( LogNexusSDK, FailureReason );
					UE_DEBUG_BREAK();
					ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Run the main callback!
				Callback.On200Response.ExecuteIfBound(OutputResponse);	
			}
			if (Response->GetResponseCode() == 400)
			{
				FNexusReferralReferralError OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Parse error
					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					// TODO: Hmm, this probably shouldn't be fatal, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this shouldn't ever happen. So alert a programmer running in the debugger.
					// TODO: Implement this commented out code!
					//UE_LOG( LogNexusSDK, FailureReason );
					UE_DEBUG_BREAK();
					ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Run the main callback!
				Callback.On400Response.ExecuteIfBound(OutputResponse);	
			}

			if (Response->GetResponseCode() != 200 && Response->GetResponseCode() != 400)
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

} // namespace FGetReferralInfoByCodeHelpers

void FNexusReferralAPI::GetReferralInfoByCode(const FNexusReferralGetReferralInfoByCodeRequestParams& RequestParams, const FOnGetReferralInfoByCodeResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	if (!FGetReferralInfoByCodeHelpers::GetReferralInfoByCode_IsValid(RequestParams))
	{
		ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
		return;
	}

	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/referrals/code/%s?groupId=%s&page=%d&pageSize=%d&excludeReferralList=%c"), *RequestParams.code, *RequestParams.groupId, RequestParams.page, RequestParams.pageSize, RequestParams.excludeReferralList);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetReferralInfoByCodeHelpers::FOnGetReferralInfoByCodeRequestContext> RequestContext = MakeUnique<FGetReferralInfoByCodeHelpers::FOnGetReferralInfoByCodeRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetReferralInfoByCodeHelpers::FOnGetReferralInfoByCodeRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();
}

/*---------------------------------------------------------------------------------------------
		Blueprint Function Nodes
---------------------------------------------------------------------------------------------*/

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


void UNexusGetReferralInfoByPlayerIdNode::When200Callback(const FNexusReferralGetReferralInfoByPlayerId200Response& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

void UNexusGetReferralInfoByPlayerIdNode::When400Callback(const FNexusReferralReferralError& Param0)
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


void UNexusGetPlayerCurrentReferralNode::When200Callback(const FString& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

void UNexusGetPlayerCurrentReferralNode::When404Callback(const FNexusReferralGetPlayerCurrentReferral404Response& Param0)
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


void UNexusGetReferralInfoByCodeNode::When200Callback(const FNexusReferralGetReferralInfoByCode200Response& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

void UNexusGetReferralInfoByCodeNode::When400Callback(const FNexusReferralReferralError& Param0)
{
	On400Response.Broadcast(Param0);
	SetReadyToDestroy();
}
