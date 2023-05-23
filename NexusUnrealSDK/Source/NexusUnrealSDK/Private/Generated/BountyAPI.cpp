/**
 * NOTE NOTE NOTE
 * GENERATED CODE
 * ANY CHANGES TO THIS FILE WILL BE OVERWRITTEN
 * PLEASE MAKE ANY CHANGES TO THE SDK TEMPLATES IN THE SDK GENERATOR
 */

#include "Generated/BountyAPI.h"
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

namespace FGetBountiesHelpers
{

	class FOnGetBountiesRequestContext final : public NexusSDK::FRequestContext
	{
	public:
	FOnGetBountiesRequestContext() = delete;
		FOnGetBountiesRequestContext(FNexusBountyAPI::FOnGetBountiesResponse InCallback, FNexusOnHttpErrorDelegate InErrorDelegate) 
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
			FNexusBountyGetBounties200Response OutputResponse;

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
				Callback.On200Response.ExecuteIfBound(OutputResponse);	

			
		}	

		if(Response->GetResponseCode() == static_cast<EHttpResponseCodes::Type>(400))
		{
			FNexusBountyBountyError OutputResponse;

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
		FNexusBountyAPI::FOnGetBountiesResponse Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};



	bool GetBounties_IsValid(const FNexusBountyGetBountiesRequestParams& Request)
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

void FNexusBountyAPI::GetBounties(const FNexusBountyGetBountiesRequestParams& RequestParams, const FOnGetBountiesResponse& Response, FNexusOnHttpErrorDelegate ErrorDelegate)
{

	if(!FGetBountiesHelpers::GetBounties_IsValid(RequestParams))
	{
		ErrorDelegate.ExecuteIfBound(0);
		return;
	}
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/bounties/?groupId=%s&page=%d&pageSize=%d"), *RequestParams.groupId, RequestParams.page, RequestParams.pageSize);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetBountiesHelpers::FOnGetBountiesRequestContext> RequestContext = MakeUnique<FGetBountiesHelpers::FOnGetBountiesRequestContext>(Response, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetBountiesHelpers::FOnGetBountiesRequestContext::ProcessRequestComplete);

		// Hand ownership of the request over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();

}
namespace FGetBountyHelpers
{

	class FOnGetBountyRequestContext final : public NexusSDK::FRequestContext
	{
	public:
	FOnGetBountyRequestContext() = delete;
		FOnGetBountyRequestContext(FNexusBountyAPI::FOnGetBountyResponse InCallback, FNexusOnHttpErrorDelegate InErrorDelegate) 
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
			FNexusBountyGetBounty200Response OutputResponse;

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
				Callback.On200Response.ExecuteIfBound(OutputResponse);	

			
		}	

		if(Response->GetResponseCode() == static_cast<EHttpResponseCodes::Type>(400))
		{
			FNexusBountyBountyError OutputResponse;

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
		FNexusBountyAPI::FOnGetBountyResponse Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};



	bool GetBounty_IsValid(const FNexusBountyGetBountyRequestParams& Request)
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

void FNexusBountyAPI::GetBounty(const FNexusBountyGetBountyRequestParams& RequestParams, const FOnGetBountyResponse& Response, FNexusOnHttpErrorDelegate ErrorDelegate)
{

	if(!FGetBountyHelpers::GetBounty_IsValid(RequestParams))
	{
		ErrorDelegate.ExecuteIfBound(0);
		return;
	}
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/bounties/%s?groupId=%s&includeProgress=%c&page=%d&pageSize=%d"), *RequestParams.bountyId, *RequestParams.groupId, RequestParams.includeProgress, RequestParams.page, RequestParams.pageSize);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetBountyHelpers::FOnGetBountyRequestContext> RequestContext = MakeUnique<FGetBountyHelpers::FOnGetBountyRequestContext>(Response, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetBountyHelpers::FOnGetBountyRequestContext::ProcessRequestComplete);

		// Hand ownership of the request over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();

}
namespace FGetCreatorBountiesByIDHelpers
{

	class FOnGetCreatorBountiesByIDRequestContext final : public NexusSDK::FRequestContext
	{
	public:
	FOnGetCreatorBountiesByIDRequestContext() = delete;
		FOnGetCreatorBountiesByIDRequestContext(FNexusBountyAPI::FOnGetCreatorBountiesByIDResponse InCallback, FNexusOnHttpErrorDelegate InErrorDelegate) 
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
			FNexusBountyGetCreatorBountiesByID200Response OutputResponse;

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
				Callback.On200Response.ExecuteIfBound(OutputResponse);	

			
		}	

		if(Response->GetResponseCode() == static_cast<EHttpResponseCodes::Type>(400))
		{
			FNexusBountyBountyError OutputResponse;

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
		FNexusBountyAPI::FOnGetCreatorBountiesByIDResponse Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};



	bool GetCreatorBountiesByID_IsValid(const FNexusBountyGetCreatorBountiesByIDRequestParams& Request)
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

void FNexusBountyAPI::GetCreatorBountiesByID(const FNexusBountyGetCreatorBountiesByIDRequestParams& RequestParams, const FOnGetCreatorBountiesByIDResponse& Response, FNexusOnHttpErrorDelegate ErrorDelegate)
{

	if(!FGetCreatorBountiesByIDHelpers::GetCreatorBountiesByID_IsValid(RequestParams))
	{
		ErrorDelegate.ExecuteIfBound(0);
		return;
	}
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/bounties/creator/id/%s?groupId=%s&page=%d&pageSize=%d"), *RequestParams.creatorId, *RequestParams.groupId, RequestParams.page, RequestParams.pageSize);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetCreatorBountiesByIDHelpers::FOnGetCreatorBountiesByIDRequestContext> RequestContext = MakeUnique<FGetCreatorBountiesByIDHelpers::FOnGetCreatorBountiesByIDRequestContext>(Response, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetCreatorBountiesByIDHelpers::FOnGetCreatorBountiesByIDRequestContext::ProcessRequestComplete);

		// Hand ownership of the request over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();

}


UNexusGetBountiesNode::UNexusGetBountiesNode()
	: Super()
{

}

void UNexusGetBountiesNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetBountiesNode* UNexusGetBountiesNode::GetBounties(UObject* WorldContextObject, const FNexusBountyGetBountiesRequestParams& InRequestParams)
{
	UNexusGetBountiesNode* Task = NewObject<UNexusGetBountiesNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetBountiesNode::Activate()
{	

	FNexusBountyAPI::FOnGetBountiesResponse Callback;
	Callback.On200Response = FNexusBountyAPI::FOnGetBounties200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback);
	Callback.On400Response = FNexusBountyAPI::FOnGetBounties400ResponseCallback::CreateUObject(this, &ThisClass::When400Callback);
	FNexusBountyAPI::GetBounties(RequestParams, Callback, FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetBountiesNode::When200Callback(const FNexusBountyGetBounties200Response& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

void UNexusGetBountiesNode::When400Callback(const FNexusBountyBountyError& Param0)
{
	On400Response.Broadcast(Param0);
	SetReadyToDestroy();
}

UNexusGetBountyNode::UNexusGetBountyNode()
	: Super()
{

}

void UNexusGetBountyNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetBountyNode* UNexusGetBountyNode::GetBounty(UObject* WorldContextObject, const FNexusBountyGetBountyRequestParams& InRequestParams)
{
	UNexusGetBountyNode* Task = NewObject<UNexusGetBountyNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetBountyNode::Activate()
{	

	FNexusBountyAPI::FOnGetBountyResponse Callback;
	Callback.On200Response = FNexusBountyAPI::FOnGetBounty200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback);
	Callback.On400Response = FNexusBountyAPI::FOnGetBounty400ResponseCallback::CreateUObject(this, &ThisClass::When400Callback);
	FNexusBountyAPI::GetBounty(RequestParams, Callback, FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetBountyNode::When200Callback(const FNexusBountyGetBounty200Response& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

void UNexusGetBountyNode::When400Callback(const FNexusBountyBountyError& Param0)
{
	On400Response.Broadcast(Param0);
	SetReadyToDestroy();
}

UNexusGetCreatorBountiesByIDNode::UNexusGetCreatorBountiesByIDNode()
	: Super()
{

}

void UNexusGetCreatorBountiesByIDNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetCreatorBountiesByIDNode* UNexusGetCreatorBountiesByIDNode::GetCreatorBountiesByID(UObject* WorldContextObject, const FNexusBountyGetCreatorBountiesByIDRequestParams& InRequestParams)
{
	UNexusGetCreatorBountiesByIDNode* Task = NewObject<UNexusGetCreatorBountiesByIDNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetCreatorBountiesByIDNode::Activate()
{	

	FNexusBountyAPI::FOnGetCreatorBountiesByIDResponse Callback;
	Callback.On200Response = FNexusBountyAPI::FOnGetCreatorBountiesByID200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback);
	Callback.On400Response = FNexusBountyAPI::FOnGetCreatorBountiesByID400ResponseCallback::CreateUObject(this, &ThisClass::When400Callback);
	FNexusBountyAPI::GetCreatorBountiesByID(RequestParams, Callback, FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetCreatorBountiesByIDNode::When200Callback(const FNexusBountyGetCreatorBountiesByID200Response& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

void UNexusGetCreatorBountiesByIDNode::When400Callback(const FNexusBountyBountyError& Param0)
{
	On400Response.Broadcast(Param0);
	SetReadyToDestroy();
}
