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

namespace FGetBountiesHelpers
{
	class FOnGetBountiesRequestContext final : public NexusSDK::FRequestContext
	{
	public:
		FOnGetBountiesRequestContext() = delete;
		FOnGetBountiesRequestContext(const FNexusBountyAPI::FOnGetBountiesResponse& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response was null, bail
				UE_LOG(LogNexusSDK, Error, TEXT("GetBounties: Connection failed, or the response was invalid"));

				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusBountyGetBounties200Response OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetBounties: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetBounties - JsonObjectToUStruct: %s"), *FailureReason.ToString());

					// Hmm, this probably shouldn't be an error, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this "shouldn't" ever happen. So alert a programmer running in the debugger.
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
				FNexusBountyBountyError OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetBounties: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetBounties - JsonObjectToUStruct: %s"), *FailureReason.ToString());

					// Hmm, this probably shouldn't be an error, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this "shouldn't" ever happen. So alert a programmer running in the debugger.
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
				UE_LOG(LogNexusSDK, Error, TEXT("GetBounties: Recieved response code %d, which is an error!"), Response->GetResponseCode());

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

} // namespace FGetBountiesHelpers

void FNexusBountyAPI::GetBounties(const FNexusBountyGetBountiesRequestParams& RequestParams, const FOnGetBountiesResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	if (!FGetBountiesHelpers::GetBounties_IsValid(RequestParams))
	{
		UE_LOG(LogNexusSDK, Error, TEXT("Invalid parameters passed to GetBounties"));

		ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
		return;
	}

	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/bounties/?groupId=%s&page=%d&pageSize=%d"), *RequestParams.groupId, RequestParams.page, RequestParams.pageSize);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetBountiesHelpers::FOnGetBountiesRequestContext> RequestContext = MakeUnique<FGetBountiesHelpers::FOnGetBountiesRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetBountiesHelpers::FOnGetBountiesRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
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
		FOnGetBountyRequestContext(const FNexusBountyAPI::FOnGetBountyResponse& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response was null, bail
				UE_LOG(LogNexusSDK, Error, TEXT("GetBounty: Connection failed, or the response was invalid"));

				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusBountyGetBounty200Response OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetBounty: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetBounty - JsonObjectToUStruct: %s"), *FailureReason.ToString());

					// Hmm, this probably shouldn't be an error, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this "shouldn't" ever happen. So alert a programmer running in the debugger.
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
				FNexusBountyBountyError OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetBounty: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetBounty - JsonObjectToUStruct: %s"), *FailureReason.ToString());

					// Hmm, this probably shouldn't be an error, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this "shouldn't" ever happen. So alert a programmer running in the debugger.
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
				UE_LOG(LogNexusSDK, Error, TEXT("GetBounty: Recieved response code %d, which is an error!"), Response->GetResponseCode());

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

} // namespace FGetBountyHelpers

void FNexusBountyAPI::GetBounty(const FNexusBountyGetBountyRequestParams& RequestParams, const FOnGetBountyResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	if (!FGetBountyHelpers::GetBounty_IsValid(RequestParams))
	{
		UE_LOG(LogNexusSDK, Error, TEXT("Invalid parameters passed to GetBounty"));

		ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
		return;
	}

	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/bounties/%s?groupId=%s&includeProgress=%c&page=%d&pageSize=%d"), *RequestParams.bountyId, *RequestParams.groupId, RequestParams.includeProgress, RequestParams.page, RequestParams.pageSize);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetBountyHelpers::FOnGetBountyRequestContext> RequestContext = MakeUnique<FGetBountyHelpers::FOnGetBountyRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetBountyHelpers::FOnGetBountyRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
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
		FOnGetCreatorBountiesByIDRequestContext(const FNexusBountyAPI::FOnGetCreatorBountiesByIDResponse& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response was null, bail
				UE_LOG(LogNexusSDK, Error, TEXT("GetCreatorBountiesByID: Connection failed, or the response was invalid"));

				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusBountyGetCreatorBountiesByID200Response OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetCreatorBountiesByID: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetCreatorBountiesByID - JsonObjectToUStruct: %s"), *FailureReason.ToString());

					// Hmm, this probably shouldn't be an error, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this "shouldn't" ever happen. So alert a programmer running in the debugger.
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
				FNexusBountyBountyError OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetCreatorBountiesByID: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetCreatorBountiesByID - JsonObjectToUStruct: %s"), *FailureReason.ToString());

					// Hmm, this probably shouldn't be an error, false doesn't indicate complete failure, just that some part of the json
					// wasn't recognised using reflection... Either way, this "shouldn't" ever happen. So alert a programmer running in the debugger.
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
				UE_LOG(LogNexusSDK, Error, TEXT("GetCreatorBountiesByID: Recieved response code %d, which is an error!"), Response->GetResponseCode());

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

} // namespace FGetCreatorBountiesByIDHelpers

void FNexusBountyAPI::GetCreatorBountiesByID(const FNexusBountyGetCreatorBountiesByIDRequestParams& RequestParams, const FOnGetCreatorBountiesByIDResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	if (!FGetCreatorBountiesByIDHelpers::GetCreatorBountiesByID_IsValid(RequestParams))
	{
		UE_LOG(LogNexusSDK, Error, TEXT("Invalid parameters passed to GetCreatorBountiesByID"));

		ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
		return;
	}

	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/bounties/creator/id/%s?groupId=%s&page=%d&pageSize=%d"), *RequestParams.creatorId, *RequestParams.groupId, RequestParams.page, RequestParams.pageSize);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetCreatorBountiesByIDHelpers::FOnGetCreatorBountiesByIDRequestContext> RequestContext = MakeUnique<FGetCreatorBountiesByIDHelpers::FOnGetCreatorBountiesByIDRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetCreatorBountiesByIDHelpers::FOnGetCreatorBountiesByIDRequestContext::ProcessRequestComplete);

		// Hand ownership of the request context over to the module
		FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
	}

	// Send it!
	HttpRequest->ProcessRequest();
}

/*---------------------------------------------------------------------------------------------
		Blueprint Function Nodes
---------------------------------------------------------------------------------------------*/

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
