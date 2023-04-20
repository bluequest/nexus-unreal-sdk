// Fill out your copyright notice in the Description page of Project Settings.


#include "NexusPrototype.h"
#include "NexusUnrealSDK.h"
#include "NexusShared.h"
#include "Http.h"
#include "HttpManager.h"
#include "PlatformHttp.h"
#include "Json.h"

/**
 * Unreal SDK prototyping code
 * This file will go away once the SDK generator is ready, and we know what we want the interface to look like.
 */

//#define NEXUS_SDK_STUB

namespace NexusSDK
{
#ifndef NEXUS_SDK_STUB
	/** Specialised request context for recieving cat facts. */
	class FCatFactsRequestContext final : public FRequestContext
	{
	public:
		FCatFactsRequestContext() = delete;
		FCatFactsRequestContext(FOnGetCatFactsComplete& InCallback) : Callback(InCallback) {}

		void ProcessRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bConnectedSuccessfully)
		{
			FGetCatFactsResponse Response;

			if (!bConnectedSuccessfully || !HttpResponse.IsValid())
			{
				// Didn't connect, or the response is null, bail
				Callback.ExecuteIfBound(Response);
				return;
			}

			if (!EHttpResponseCodes::IsOk(HttpResponse->GetResponseCode()))
			{
				// We connected and got a response, but the code was bad, bail
				Callback.ExecuteIfBound(Response);
				return;
			}

			// Create a Json object and parser
			const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(HttpResponse->GetContentAsString());
			TSharedPtr<FJsonObject> RootObject;

			// Parse it!
			if (!FJsonSerializer::Deserialize(Reader, RootObject))
			{
				// Parse error
				Callback.ExecuteIfBound(Response);
				return;
			}

			// The cat facts API returns a bunch of stuff we don't care about, we want those facts!
			// There's an array called "data" with the facts in it
			const TArray<TSharedPtr<FJsonValue>>* OutArray;
			if (!RootObject->TryGetArrayField(TEXT("data"), OutArray))
			{
				// Facts are missing!
				Callback.ExecuteIfBound(Response);
				return;
			}

			check(OutArray);

			// Parse the facts!
			for (const TSharedPtr<FJsonValue>& Value : *OutArray)
			{
				const TSharedPtr<FJsonObject>* Object;
				if (Value->TryGetObject(Object))
				{
					check(Object);
					FString Fact;
					if (Object->Get()->TryGetStringField(TEXT("fact"), Fact))
					{
						// Add it to the array
						Response.Facts.Add(MoveTemp(Fact));
					}
				}
			}

			// Mark success!
			Response.bSuccess = true;

			// Run the callback successfully!
			Callback.ExecuteIfBound(Response);

			// Now remove and delete ourselves from the module cache
			FNexusUnrealSDKModule::Get().RemoveRequest(this);
		}

	private:
		FOnGetCatFactsComplete& Callback;

	};
#endif

	NEXUSUNREALSDK_API void GetCatFacts(const FGetCatFactsRequest& Request, FOnGetCatFactsComplete& Callback)
	{
#ifdef NEXUS_SDK_STUB
		TArray<FString> FakeFacts
		{
			TEXT("Cats are 90% jelly."),
			TEXT("Cats go purrrrr."),
			TEXT("Hello."),
			TEXT("What's up."),
			TEXT("How's it going."),
		};

		Callback.Execute(FakeFacts, true);
#else
		FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

		{
			// Initialise some bits and pieces ahead of time
			FString URLString = FString::Printf(TEXT("https://catfact.ninja/facts?max_length=%d&limit=%d"), Request.MaxLength, Request.Limit);
			TUniquePtr<FCatFactsRequestContext> RequestContext = MakeUnique<FCatFactsRequestContext>(Callback);

			// Set-up the HTTP request
			HttpRequest->SetVerb(TEXT("GET"));
			HttpRequest->SetURL(URLString);
			HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FCatFactsRequestContext::ProcessRequestComplete);

			// Hand ownership of the request over to the module
			FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
		}

		// Send it!
		HttpRequest->ProcessRequest();
#endif
	}

	/**
	 * Return all creators and their creator details, including unique id and creator code
	 */

	//
	//
	//
	// TODO(JoshD): UNFINISHED!!!!
	//
	//
	//
	class FGetCreatorsRequestContext final : public FRequestContext
	{
	public:
		FGetCreatorsRequestContext() = delete;
		FGetCreatorsRequestContext(FOnGetCreatorsComplete& InCallback) : Callback(InCallback) {}

		void ProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			FGetCreatorsResponse Facts;

			if (!bConnectedSuccessfully || !Response.IsValid())
			{
				// Didn't connect, or the response is null, bail
				Callback.ExecuteIfBound(Facts);
				return;
			}

			if (!EHttpResponseCodes::IsOk(Response->GetResponseCode()))
			{
				// We connected and got a response, but the code was bad, bail
				Callback.ExecuteIfBound(Facts);
				return;
			}

			// Create a Json object and parser
			const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
			TSharedPtr<FJsonObject> RootObject;

			// Parse it!
			if (!FJsonSerializer::Deserialize(Reader, RootObject))
			{
				// Parse error
				Callback.ExecuteIfBound(Facts);
				return;
			}

			// The cat facts API returns a bunch of stuff we don't care about, we want those facts!
			// There's an array called "data" with the facts in it
			const TArray<TSharedPtr<FJsonValue>>* OutArray;
			if (!RootObject->TryGetArrayField(TEXT("data"), OutArray))
			{
				// Facts are missing!
				Callback.ExecuteIfBound(Facts);
				return;
			}

			check(OutArray);

			// Parse the facts!
			for (const TSharedPtr<FJsonValue>& Value : *OutArray)
			{
				const TSharedPtr<FJsonObject>* Object;
				if (Value->TryGetObject(Object))
				{
					check(Object);
					FString Fact;
					if (Object->Get()->TryGetStringField(TEXT("fact"), Fact))
					{
						// Add it to the array
						//Facts.Add(MoveTemp(Fact));
					}
				}
			}

			// Run the callback successfully!
			Callback.ExecuteIfBound(Facts);

			// Now remove and delete ourselves from the module cache
			FNexusUnrealSDKModule::Get().RemoveRequest(this);
		}

	private:
		FOnGetCreatorsComplete& Callback;

	};

	NEXUSUNREALSDK_API void GetCreators(const FGetCreatorsRequest& Request, FOnGetCreatorsComplete& Callback)
	{
		FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

		{
			// Initialise some bits and pieces ahead of time
			FString URLString = FString::Printf(TEXT("https://api.nexus.gg/v1/attributions/creators"));
			TUniquePtr<FGetCreatorsRequestContext> RequestContext = MakeUnique<FGetCreatorsRequestContext>(Callback);

			// Set-up the HTTP request
			HttpRequest->SetVerb(TEXT("GET"));
			HttpRequest->SetHeader(TEXT("accept"), TEXT("application/json"));
			HttpRequest->SetHeader(TEXT("x-shared-secret"), Request.PublicKey);
			HttpRequest->SetURL(URLString);
			HttpRequest->OnProcessRequestComplete().BindRaw(RequestContext.Get(), &FGetCreatorsRequestContext::ProcessRequestComplete);

			// Hand ownership of the request over to the module
			FNexusUnrealSDKModule::Get().AddRequest(MoveTemp(RequestContext));
		}

		// Send it!
		HttpRequest->ProcessRequest();
	}

}
