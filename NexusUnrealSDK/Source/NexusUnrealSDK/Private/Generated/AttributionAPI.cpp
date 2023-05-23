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
#include "NexusSettings.h"
#include "NexusUnrealSDK.h"

/**
 * Unreal SDK, descriptive comment goes here, notes about implementation, whatever we want really.
 */

namespace FGetCreatorsHelpers
{

	class FOnGetCreatorsRequestContext final : public NexusSDK::FRequestContext
	{
	public:
	FOnGetCreatorsRequestContext() = delete;
		FOnGetCreatorsRequestContext(FNexusAttributionAPI::FOnGetCreators200ResponseCallback InCallback, FNexusOnHttpErrorDelegate InErrorDelegate) 
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
			FNexusAttributionGetCreators200Response OutputResponse;

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
			FText FailureReason;
			bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
			if ( !bResult )
			{
				// Oh no! This shouldn't happen! If it does start happening, we should rethink this error handling.
				// Perhaps this should not be fatal.
				// TODO(JoshD): Log the failure reason at the very least?
				UE_DEBUG_BREAK();
				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				return;
			}

			// Run the callback successfully!
				Callback.ExecuteIfBound(OutputResponse);

			
		}	

		if(Response->GetResponseCode() != 200)
		{
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
}

void FNexusAttributionAPI::GetCreators(const FNexusAttributionGetCreatorsRequestParams& RequestParams, const FOnGetCreators200ResponseCallback& Response, FNexusOnHttpErrorDelegate ErrorDelegate)
{

	if(!FGetCreatorsHelpers::GetCreators_IsValid(RequestParams))
	{
		ErrorDelegate.ExecuteIfBound(0);
		return;
	}
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/attributions/creators?page=%d&pageSize=%d&groupId=%s"), RequestParams.page, RequestParams.pageSize, *RequestParams.groupId);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetCreatorsHelpers::FOnGetCreatorsRequestContext> RequestContext = MakeUnique<FGetCreatorsHelpers::FOnGetCreatorsRequestContext>(Response, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetCreatorsHelpers::FOnGetCreatorsRequestContext::ProcessRequestComplete);

		// Hand ownership of the request over to the module
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
		FOnGetCreatorByUuidRequestContext(FNexusAttributionAPI::FOnGetCreatorByUuid200ResponseCallback InCallback, FNexusOnHttpErrorDelegate InErrorDelegate) 
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
			FNexusAttributionGetCreatorByUuid200Response OutputResponse;

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
			FText FailureReason;
			bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
			if ( !bResult )
			{
				// Oh no! This shouldn't happen! If it does start happening, we should rethink this error handling.
				// Perhaps this should not be fatal.
				// TODO(JoshD): Log the failure reason at the very least?
				UE_DEBUG_BREAK();
				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				return;
			}

			// Run the callback successfully!
				Callback.ExecuteIfBound(OutputResponse);

			
		}	

		if(Response->GetResponseCode() != 200)
		{
			ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
		}
			
		// Now remove and delete ourselves from the module cache
		FNexusUnrealSDKModule::Get().RemoveRequest(this);
	}

	private:
		FNexusAttributionAPI::FOnGetCreatorByUuid200ResponseCallback Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};


}

void FNexusAttributionAPI::GetCreatorByUuid(const FNexusAttributionGetCreatorByUuidRequestParams& RequestParams, const FOnGetCreatorByUuid200ResponseCallback& Response, FNexusOnHttpErrorDelegate ErrorDelegate)
{
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/attributions/creators/%s"), *RequestParams.creatorSlugOrId);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetCreatorByUuidHelpers::FOnGetCreatorByUuidRequestContext> RequestContext = MakeUnique<FGetCreatorByUuidHelpers::FOnGetCreatorByUuidRequestContext>(Response, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetCreatorByUuidHelpers::FOnGetCreatorByUuidRequestContext::ProcessRequestComplete);

		// Hand ownership of the request over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();

}


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
