/**
 * NOTE NOTE NOTE
 * GENERATED CODE
 * ANY CHANGES TO THIS FILE WILL BE OVERWRITTEN
 * PLEASE MAKE ANY CHANGES TO THE SDK TEMPLATES IN THE SDK GENERATOR
 */

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

namespace FGetCreatorsHelpers
{
	class FOnGetCreatorsRequestContext final : public NexusSDK::FRequestContext
	{
	public:
		FOnGetCreatorsRequestContext() = delete;
		FOnGetCreatorsRequestContext(const FNexusAttributionAPI::FOnGetCreators200ResponseCallback& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response was null, bail
				UE_LOG(LogNexusSDK, Error, TEXT("GetCreators: Connection failed, or the response was invalid"));

				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusAttributionGetCreators200Response OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetCreators: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetCreators - JsonObjectToUStruct: %s"), *FailureReason.ToString());

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
				UE_LOG(LogNexusSDK, Error, TEXT("GetCreators: Recieved response code %d, which is an error!"), Response->GetResponseCode());

				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
			}
			
			// Now remove and delete ourselves from the module cache
			FNexusUnrealSDKModule::Get().RemoveRequest(this);
		}

	private:
		FNexusAttributionAPI::FOnGetCreators200ResponseCallback Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};

	bool GetCreators_IsValid(const FNexusAttributionGetCreatorsRequestParams& Request)
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

} // namespace FGetCreatorsHelpers

void FNexusAttributionAPI::GetCreators(const FNexusAttributionGetCreatorsRequestParams& RequestParams, const FOnGetCreators200ResponseCallback& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	if (!FGetCreatorsHelpers::GetCreators_IsValid(RequestParams))
	{
		UE_LOG(LogNexusSDK, Error, TEXT("Invalid parameters passed to GetCreators"));

		ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
		return;
	}

	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/attributions/creators?page=%d&pageSize=%d&groupId=%s"), RequestParams.page, RequestParams.pageSize, *RequestParams.groupId);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetCreatorsHelpers::FOnGetCreatorsRequestContext> RequestContext = MakeUnique<FGetCreatorsHelpers::FOnGetCreatorsRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetCreatorsHelpers::FOnGetCreatorsRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();
}

namespace FGetCreatorByUuidHelpers
{
	class FOnGetCreatorByUuidRequestContext final : public NexusSDK::FRequestContext
	{
	public:
		FOnGetCreatorByUuidRequestContext() = delete;
		FOnGetCreatorByUuidRequestContext(const FNexusAttributionAPI::FOnGetCreatorByUuid200ResponseCallback& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response was null, bail
				UE_LOG(LogNexusSDK, Error, TEXT("GetCreatorByUuid: Connection failed, or the response was invalid"));

				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusAttributionGetCreatorByUuid200Response OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetCreatorByUuid: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetCreatorByUuid - JsonObjectToUStruct: %s"), *FailureReason.ToString());

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
				UE_LOG(LogNexusSDK, Error, TEXT("GetCreatorByUuid: Recieved response code %d, which is an error!"), Response->GetResponseCode());

				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
			}
			
			// Now remove and delete ourselves from the module cache
			FNexusUnrealSDKModule::Get().RemoveRequest(this);
		}

	private:
		FNexusAttributionAPI::FOnGetCreatorByUuid200ResponseCallback Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};


} // namespace FGetCreatorByUuidHelpers

void FNexusAttributionAPI::GetCreatorByUuid(const FNexusAttributionGetCreatorByUuidRequestParams& RequestParams, const FOnGetCreatorByUuid200ResponseCallback& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/attributions/creators/%s"), *RequestParams.creatorSlugOrId);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetCreatorByUuidHelpers::FOnGetCreatorByUuidRequestContext> RequestContext = MakeUnique<FGetCreatorByUuidHelpers::FOnGetCreatorByUuidRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetCreatorByUuidHelpers::FOnGetCreatorByUuidRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();
}

/*---------------------------------------------------------------------------------------------
		Blueprint Function Nodes
---------------------------------------------------------------------------------------------*/

UNexusGetCreatorsNode::UNexusGetCreatorsNode()
	: Super()
{
}

void UNexusGetCreatorsNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetCreatorsNode* UNexusGetCreatorsNode::GetCreators(UObject* WorldContextObject, const FNexusAttributionGetCreatorsRequestParams& InRequestParams)
{
	UNexusGetCreatorsNode* Task = NewObject<UNexusGetCreatorsNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetCreatorsNode::Activate()
{	

	FNexusAttributionAPI::GetCreators(RequestParams, 
		FNexusAttributionAPI::FOnGetCreators200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback),
		FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetCreatorsNode::When200Callback(const FNexusAttributionGetCreators200Response& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

UNexusGetCreatorByUuidNode::UNexusGetCreatorByUuidNode()
	: Super()
{
}

void UNexusGetCreatorByUuidNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetCreatorByUuidNode* UNexusGetCreatorByUuidNode::GetCreatorByUuid(UObject* WorldContextObject, const FNexusAttributionGetCreatorByUuidRequestParams& InRequestParams)
{
	UNexusGetCreatorByUuidNode* Task = NewObject<UNexusGetCreatorByUuidNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetCreatorByUuidNode::Activate()
{	

	FNexusAttributionAPI::GetCreatorByUuid(RequestParams, 
		FNexusAttributionAPI::FOnGetCreatorByUuid200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback),
		FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetCreatorByUuidNode::When200Callback(const FNexusAttributionGetCreatorByUuid200Response& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}
