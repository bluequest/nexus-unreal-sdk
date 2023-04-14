// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * Unreal SDK prototyping code
 * This file will go away once the SDK generator is ready, and we know what we want the interface to look like.
 */

namespace NexusSDK
{
	/** Simple abstract base class that represents the state of a request, should not need a virtual destructor. */
	class FRequestContext
	{
	};

	/** The class above as a unique pointer. */
	using FRequestContextPtr = TUniquePtr<FRequestContext>;

	// Don't know yet if we want to go with structs or not for the interface
	/*struct FGetCatFactsRequest
	{
		int32 MaxLength;		// Maximum length of returned fact
		int32 Limit;			// Limit the amount of results returned
	};

	struct FGetCatFactsResponse
	{
		TArray<FString> Facts;	// A list of strings of cat facts
		bool success;
	};*/
	
	/**
	 * Declares the delegate type that returns an array of cat fact strings, and a bool to
	 * indicate whether the data is valid or not.
	 */
	DECLARE_DELEGATE_TwoParams(FGetCatFacts, TArray<FString>&, bool);

	/**
	 * Requests cat facts. Some cool Unreal style javadoc comment would go here, talking
	 * about the parameters, and that Callback will be fired on the HTTP thread.
	 */
	NEXUSUNREALSDK_API void GetCatFacts(int32 MaxLength, int32 Limit, FGetCatFacts& Callback);

}
