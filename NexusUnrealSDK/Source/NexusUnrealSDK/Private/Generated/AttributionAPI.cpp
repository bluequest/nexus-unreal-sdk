
#include "Generated/AttributionAPI.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "HttpModule.h"
#include "DOM/JsonObject.h"
#include "JsonObjectConverter.h"
#include "NexusShared.h"
#include "NexusPrivate.h"
#include "NexusSettings.h"
#include "NexusUnrealSDK.h"

/**
 * Auto-generated implementation file for the Nexus Unreal SDK.
 * Feel free to dig through this code! We've tried to keep things as straight forward and simple as
 * possible on the header side, but checking this code out might reveal useful implementation details.
 */

/*---------------------------------------------------------------------------------------------
		API Functions
---------------------------------------------------------------------------------------------*/

namespace FGetMembersHelpers
{
	class FOnGetMembersRequestContext final : public NexusSDK::FRequestContext
	{
	public:
		FOnGetMembersRequestContext() = delete;
		FOnGetMembersRequestContext(const FNexusAttributionAPI::FOnGetMembers200ResponseCallback& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response was null, bail
				UE_LOG(LogNexusSDK, Error, TEXT("GetMembers: Connection failed, or the response was invalid"));

				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusAttributionGetMembers200Response OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetMembers: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetMembers - JsonObjectToUStruct: %s"), *FailureReason.ToString());

					// Hmm, this probably shouldn't be an error, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this "shouldn't" ever happen. So alert a programmer running in the debugger.
					UE_DEBUG_BREAK();
					ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Run the main callback!
				Callback.ExecuteIfBound(OutputResponse);
			}

			if (Response->GetResponseCode() != 200)
			{
				UE_LOG(LogNexusSDK, Error, TEXT("GetMembers: Recieved response code %d, which is an error!"), Response->GetResponseCode());

				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
			}
			
			// Now remove and delete ourselves from the module cache
			FNexusUnrealSDKModule::Get().RemoveRequest(this);
		}

	private:
		FNexusAttributionAPI::FOnGetMembers200ResponseCallback Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};

	bool GetMembers_IsValid(const FNexusAttributionGetMembersRequestParams& Request)
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

} // namespace FGetMembersHelpers

void FNexusAttributionAPI::GetMembers(const FNexusAttributionGetMembersRequestParams& RequestParams, const FOnGetMembers200ResponseCallback& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	if (!FGetMembersHelpers::GetMembers_IsValid(RequestParams))
	{
		UE_LOG(LogNexusSDK, Error, TEXT("Invalid parameters passed to GetMembers"));

		ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
		return;
	}

	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();
	FString BaseURL = UNexusUnrealSDKSettings::Get()->GetBaseURL();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("%s/manage/members?page=%d&pageSize=%d&groupId=%s"),*BaseURL, RequestParams.page, RequestParams.pageSize, *RequestParams.groupId);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetMembersHelpers::FOnGetMembersRequestContext> RequestContext = MakeUnique<FGetMembersHelpers::FOnGetMembersRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetMembersHelpers::FOnGetMembersRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();
}

namespace FGetMemberByCodeOrUuidHelpers
{
	class FOnGetMemberByCodeOrUuidRequestContext final : public NexusSDK::FRequestContext
	{
	public:
		FOnGetMemberByCodeOrUuidRequestContext() = delete;
		FOnGetMemberByCodeOrUuidRequestContext(const FNexusAttributionAPI::FOnGetMemberByCodeOrUuid200ResponseCallback& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response was null, bail
				UE_LOG(LogNexusSDK, Error, TEXT("GetMemberByCodeOrUuid: Connection failed, or the response was invalid"));

				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusAttributionMember OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetMemberByCodeOrUuid: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetMemberByCodeOrUuid - JsonObjectToUStruct: %s"), *FailureReason.ToString());

					// Hmm, this probably shouldn't be an error, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this "shouldn't" ever happen. So alert a programmer running in the debugger.
					UE_DEBUG_BREAK();
					ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Run the main callback!
				Callback.ExecuteIfBound(OutputResponse);
			}

			if (Response->GetResponseCode() != 200)
			{
				UE_LOG(LogNexusSDK, Error, TEXT("GetMemberByCodeOrUuid: Recieved response code %d, which is an error!"), Response->GetResponseCode());

				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
			}
			
			// Now remove and delete ourselves from the module cache
			FNexusUnrealSDKModule::Get().RemoveRequest(this);
		}

	private:
		FNexusAttributionAPI::FOnGetMemberByCodeOrUuid200ResponseCallback Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};


} // namespace FGetMemberByCodeOrUuidHelpers

void FNexusAttributionAPI::GetMemberByCodeOrUuid(const FNexusAttributionGetMemberByCodeOrUuidRequestParams& RequestParams, const FOnGetMemberByCodeOrUuid200ResponseCallback& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();
	FString BaseURL = UNexusUnrealSDKSettings::Get()->GetBaseURL();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("%s/manage/members/%s?groupId=%s"),*BaseURL, *RequestParams.memberCodeOrID, *RequestParams.groupId);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetMemberByCodeOrUuidHelpers::FOnGetMemberByCodeOrUuidRequestContext> RequestContext = MakeUnique<FGetMemberByCodeOrUuidHelpers::FOnGetMemberByCodeOrUuidRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetMemberByCodeOrUuidHelpers::FOnGetMemberByCodeOrUuidRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();
}

namespace FGetMemberByPlayerIdHelpers
{
	class FOnGetMemberByPlayerIdRequestContext final : public NexusSDK::FRequestContext
	{
	public:
		FOnGetMemberByPlayerIdRequestContext() = delete;
		FOnGetMemberByPlayerIdRequestContext(const FNexusAttributionAPI::FOnGetMemberByPlayerId200ResponseCallback& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response was null, bail
				UE_LOG(LogNexusSDK, Error, TEXT("GetMemberByPlayerId: Connection failed, or the response was invalid"));

				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusAttributionMember OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetMemberByPlayerId: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetMemberByPlayerId - JsonObjectToUStruct: %s"), *FailureReason.ToString());

					// Hmm, this probably shouldn't be an error, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this "shouldn't" ever happen. So alert a programmer running in the debugger.
					UE_DEBUG_BREAK();
					ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Run the main callback!
				Callback.ExecuteIfBound(OutputResponse);
			}

			if (Response->GetResponseCode() != 200)
			{
				UE_LOG(LogNexusSDK, Error, TEXT("GetMemberByPlayerId: Recieved response code %d, which is an error!"), Response->GetResponseCode());

				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
			}
			
			// Now remove and delete ourselves from the module cache
			FNexusUnrealSDKModule::Get().RemoveRequest(this);
		}

	private:
		FNexusAttributionAPI::FOnGetMemberByPlayerId200ResponseCallback Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};


} // namespace FGetMemberByPlayerIdHelpers

void FNexusAttributionAPI::GetMemberByPlayerId(const FNexusAttributionGetMemberByPlayerIdRequestParams& RequestParams, const FOnGetMemberByPlayerId200ResponseCallback& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();
	FString BaseURL = UNexusUnrealSDKSettings::Get()->GetBaseURL();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("%s/manage/members/player/%s?groupId=%s"),*BaseURL, *RequestParams.playerId, *RequestParams.groupId);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetMemberByPlayerIdHelpers::FOnGetMemberByPlayerIdRequestContext> RequestContext = MakeUnique<FGetMemberByPlayerIdHelpers::FOnGetMemberByPlayerIdRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetMemberByPlayerIdHelpers::FOnGetMemberByPlayerIdRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();
}

/*---------------------------------------------------------------------------------------------
		Blueprint Function Nodes
---------------------------------------------------------------------------------------------*/

UNexusGetMembersNode::UNexusGetMembersNode()
	: Super()
{
}

void UNexusGetMembersNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetMembersNode* UNexusGetMembersNode::GetMembers(UObject* WorldContextObject, const FNexusAttributionGetMembersRequestParams& InRequestParams)
{
	UNexusGetMembersNode* Task = NewObject<UNexusGetMembersNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetMembersNode::Activate()
{	

	FNexusAttributionAPI::GetMembers(RequestParams, 
		FNexusAttributionAPI::FOnGetMembers200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback),
		FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetMembersNode::When200Callback(const FNexusAttributionGetMembers200Response& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

UNexusGetMemberByCodeOrUuidNode::UNexusGetMemberByCodeOrUuidNode()
	: Super()
{
}

void UNexusGetMemberByCodeOrUuidNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetMemberByCodeOrUuidNode* UNexusGetMemberByCodeOrUuidNode::GetMemberByCodeOrUuid(UObject* WorldContextObject, const FNexusAttributionGetMemberByCodeOrUuidRequestParams& InRequestParams)
{
	UNexusGetMemberByCodeOrUuidNode* Task = NewObject<UNexusGetMemberByCodeOrUuidNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetMemberByCodeOrUuidNode::Activate()
{	

	FNexusAttributionAPI::GetMemberByCodeOrUuid(RequestParams, 
		FNexusAttributionAPI::FOnGetMemberByCodeOrUuid200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback),
		FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetMemberByCodeOrUuidNode::When200Callback(const FNexusAttributionMember& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

UNexusGetMemberByPlayerIdNode::UNexusGetMemberByPlayerIdNode()
	: Super()
{
}

void UNexusGetMemberByPlayerIdNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetMemberByPlayerIdNode* UNexusGetMemberByPlayerIdNode::GetMemberByPlayerId(UObject* WorldContextObject, const FNexusAttributionGetMemberByPlayerIdRequestParams& InRequestParams)
{
	UNexusGetMemberByPlayerIdNode* Task = NewObject<UNexusGetMemberByPlayerIdNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetMemberByPlayerIdNode::Activate()
{	

	FNexusAttributionAPI::GetMemberByPlayerId(RequestParams, 
		FNexusAttributionAPI::FOnGetMemberByPlayerId200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback),
		FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetMemberByPlayerIdNode::When200Callback(const FNexusAttributionMember& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}
