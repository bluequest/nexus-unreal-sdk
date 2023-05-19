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
#include "NexusShared.h"
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
		FOnGetCreatorsRequestContext(FNexusAttributionAPI::FOnGetCreators200ResponseCallback InCallback) : Callback(InCallback) {}

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
	Callback.ExecuteIfBound(OutputResponse);
	return;
	}

	// Parse the response!
	// TODO(JoshD): Parse it!

	// Run the callback successfully!
	Callback.ExecuteIfBound(OutputResponse);
	}
	
		
		// Now remove and delete ourselves from the module cache
		FNexusUnrealSDKModule::Get().RemoveRequest(this);
	}

	private:
		FNexusAttributionAPI::FOnGetCreators200ResponseCallback Callback;

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

void FNexusAttributionAPI::GetCreators(const FNexusAttributionGetCreatorsRequestParams& RequestParams, FOnGetCreators200ResponseCallback Response)
{

	if(!FGetCreatorsHelpers::GetCreators_IsValid(RequestParams))
	{
		//TODO:Handle This Gracefully
		return;
	}
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		//TODO: @Josh: Most of the request properties are serialized as json and sent in the body of the http request.
		//		Only Parameter names indicated in the Path with {variable} are put in the url
		//		This will need to be fixed
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/attributions/creators?page=%d&pageSize=%d&groupId=%s"), RequestParams.page, RequestParams.pageSize, *RequestParams.groupId);
		TUniquePtr<FGetCreatorsHelpers::FOnGetCreatorsRequestContext> RequestContext = MakeUnique<FGetCreatorsHelpers::FOnGetCreatorsRequestContext>(Response);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
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
		FOnGetCreatorByUuidRequestContext(FNexusAttributionAPI::FOnGetCreatorByUuid200ResponseCallback InCallback) : Callback(InCallback) {}

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
	Callback.ExecuteIfBound(OutputResponse);
	return;
	}

	// Parse the response!
	// TODO(JoshD): Parse it!

	// Run the callback successfully!
	Callback.ExecuteIfBound(OutputResponse);
	}
	
		
		// Now remove and delete ourselves from the module cache
		FNexusUnrealSDKModule::Get().RemoveRequest(this);
	}

	private:
		FNexusAttributionAPI::FOnGetCreatorByUuid200ResponseCallback Callback;

	};


}

void FNexusAttributionAPI::GetCreatorByUuid(const FNexusAttributionGetCreatorByUuidRequestParams& RequestParams, FOnGetCreatorByUuid200ResponseCallback Response)
{
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		//TODO: @Josh: Most of the request properties are serialized as json and sent in the body of the http request.
		//		Only Parameter names indicated in the Path with {variable} are put in the url
		//		This will need to be fixed
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/attributions/creators/{creatorSlugOrId}?creatorSlugOrId=%s"), *RequestParams.creatorSlugOrId);
		TUniquePtr<FGetCreatorByUuidHelpers::FOnGetCreatorByUuidRequestContext> RequestContext = MakeUnique<FGetCreatorByUuidHelpers::FOnGetCreatorByUuidRequestContext>(Response);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
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


UNexusGetCreatorsNode* UNexusGetCreatorsNode::GetCreators(UObject* WorldContextObject, const FNexusAttributionGetCreatorsRequestParams& InRequestParams)
{
	UNexusGetCreatorsNode* Task = NewObject<UNexusGetCreatorsNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetCreatorsNode::Activate()
{	
	FNexusAttributionAPI::GetCreators(RequestParams, FNexusAttributionAPI::FOnGetCreators200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback));
}


void UNexusGetCreatorsNode::When200Callback(FNexusAttributionGetCreators200Response Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

UNexusGetCreatorByUuidNode::UNexusGetCreatorByUuidNode()
	: Super()
{

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
	FNexusAttributionAPI::GetCreatorByUuid(RequestParams, FNexusAttributionAPI::FOnGetCreatorByUuid200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback));
}


void UNexusGetCreatorByUuidNode::When200Callback(FNexusAttributionGetCreatorByUuid200Response Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}
