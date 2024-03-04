
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
	FString BaseURL = UNexusUnrealSDKSettings::Get()->GetBaseURL();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("%s?groupId=%s&page=%d&pageSize=%d"),*BaseURL, *RequestParams.groupId, RequestParams.page, RequestParams.pageSize);
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
	FString BaseURL = UNexusUnrealSDKSettings::Get()->GetBaseURL();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("%s/%s?groupId=%s&includeProgress=%c&page=%d&pageSize=%d"),*BaseURL, *RequestParams.bountyId, *RequestParams.groupId, RequestParams.includeProgress, RequestParams.page, RequestParams.pageSize);
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

namespace FGetMemberBountiesByIDHelpers
{
	class FOnGetMemberBountiesByIDRequestContext final : public NexusSDK::FRequestContext
	{
	public:
		FOnGetMemberBountiesByIDRequestContext() = delete;
		FOnGetMemberBountiesByIDRequestContext(const FNexusBountyAPI::FOnGetMemberBountiesByIDResponse& InCallback, const FNexusOnHttpErrorDelegate& InErrorDelegate) 
			: Callback(InCallback)
			, ErrorDelegate(InErrorDelegate)
		{}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response was null, bail
				UE_LOG(LogNexusSDK, Error, TEXT("GetMemberBountiesByID: Connection failed, or the response was invalid"));

				ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
				FNexusUnrealSDKModule::Get().RemoveRequest(this);
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				FNexusBountyGetMemberBountiesByID200Response OutputResponse;

				// Create a json object and reader
				const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
				TSharedPtr<FJsonObject> RootObject;

				// Deserialize it!
				if (!FJsonSerializer::Deserialize(Reader, RootObject))
				{
					// Invalid json?
					UE_LOG(LogNexusSDK, Error, TEXT("GetMemberBountiesByID: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetMemberBountiesByID - JsonObjectToUStruct: %s"), *FailureReason.ToString());

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
					UE_LOG(LogNexusSDK, Error, TEXT("GetMemberBountiesByID: Failed to deserialize json"));

					ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
					FNexusUnrealSDKModule::Get().RemoveRequest(this);
					return;
				}

				// Parse the response!
				FText FailureReason;
				bool bResult = FJsonObjectConverter::JsonObjectToUStruct(RootObject.ToSharedRef(), &OutputResponse, 0, 0, false, &FailureReason);
				if ( !bResult )
				{
					UE_LOG(LogNexusSDK, Error, TEXT("GetMemberBountiesByID - JsonObjectToUStruct: %s"), *FailureReason.ToString());

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
				UE_LOG(LogNexusSDK, Error, TEXT("GetMemberBountiesByID: Recieved response code %d, which is an error!"), Response->GetResponseCode());

				ErrorDelegate.ExecuteIfBound(Response->GetResponseCode());
			}
			
			// Now remove and delete ourselves from the module cache
			FNexusUnrealSDKModule::Get().RemoveRequest(this);
		}

	private:
		FNexusBountyAPI::FOnGetMemberBountiesByIDResponse Callback;
		FNexusOnHttpErrorDelegate ErrorDelegate;

	};

	bool GetMemberBountiesByID_IsValid(const FNexusBountyGetMemberBountiesByIDRequestParams& Request)
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

} // namespace FGetMemberBountiesByIDHelpers

void FNexusBountyAPI::GetMemberBountiesByID(const FNexusBountyGetMemberBountiesByIDRequestParams& RequestParams, const FOnGetMemberBountiesByIDResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate)
{
	if (!FGetMemberBountiesByIDHelpers::GetMemberBountiesByID_IsValid(RequestParams))
	{
		UE_LOG(LogNexusSDK, Error, TEXT("Invalid parameters passed to GetMemberBountiesByID"));

		ErrorDelegate.ExecuteIfBound(EHttpResponseCodes::Unknown);
		return;
	}

	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();
	FString BaseURL = UNexusUnrealSDKSettings::Get()->GetBaseURL();

	{
		// Initialise some bits and pieces ahead of time
		FString URLString = FString::Printf(TEXT("%s/member/id/%s?groupId=%s&page=%d&pageSize=%d"),*BaseURL, *RequestParams.memberId, *RequestParams.groupId, RequestParams.page, RequestParams.pageSize);
		FString PublicKey = UNexusUnrealSDKSettings::Get()->PublicKey.ToString();
		TUniquePtr<FGetMemberBountiesByIDHelpers::FOnGetMemberBountiesByIDRequestContext> RequestContext = MakeUnique<FGetMemberBountiesByIDHelpers::FOnGetMemberBountiesByIDRequestContext>(ResponseDelegate, ErrorDelegate);

		// Set-up the HTTP request
		HttpRequest->SetVerb(TEXT("GET"));
		HttpRequest->SetURL(URLString);
		HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
		HttpRequest->SetHeader(TEXT("x-shared-secret"), PublicKey);
		HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetMemberBountiesByIDHelpers::FOnGetMemberBountiesByIDRequestContext::ProcessRequestComplete);

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

UNexusGetMemberBountiesByIDNode::UNexusGetMemberBountiesByIDNode()
	: Super()
{
}

void UNexusGetMemberBountiesByIDNode::WhenError(int32 ErrorCode)
{
	OnError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}


UNexusGetMemberBountiesByIDNode* UNexusGetMemberBountiesByIDNode::GetMemberBountiesByID(UObject* WorldContextObject, const FNexusBountyGetMemberBountiesByIDRequestParams& InRequestParams)
{
	UNexusGetMemberBountiesByIDNode* Task = NewObject<UNexusGetMemberBountiesByIDNode>();
	Task->RequestParams = InRequestParams;
	Task->RegisterWithGameInstance(WorldContextObject);

	return Task;
}

void UNexusGetMemberBountiesByIDNode::Activate()
{	

	FNexusBountyAPI::FOnGetMemberBountiesByIDResponse Callback;
	Callback.On200Response = FNexusBountyAPI::FOnGetMemberBountiesByID200ResponseCallback::CreateUObject(this, &ThisClass::When200Callback);
	Callback.On400Response = FNexusBountyAPI::FOnGetMemberBountiesByID400ResponseCallback::CreateUObject(this, &ThisClass::When400Callback);
	FNexusBountyAPI::GetMemberBountiesByID(RequestParams, Callback, FNexusOnHttpErrorDelegate::CreateUObject(this, &ThisClass::WhenError));
}


void UNexusGetMemberBountiesByIDNode::When200Callback(const FNexusBountyGetMemberBountiesByID200Response& Param0)
{
	On200Response.Broadcast(Param0);
	SetReadyToDestroy();
}

void UNexusGetMemberBountiesByIDNode::When400Callback(const FNexusBountyBountyError& Param0)
{
	On400Response.Broadcast(Param0);
	SetReadyToDestroy();
}
