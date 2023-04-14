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

	// Here for posterity, this is what the input / output would look like if we went with
	// structs rather than function parameters.
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
	 * Declares a delegate that is executed when GetCatFacts has recieved
	 * and decoded an HTTP response (even on failure).
	 * Keep in mind that this is executed on the HTTP thread.
	 * Returns an array of strings containing the cat facts, and a bool indicating
	 * success, you should not use any of the returned data if this bool is false.
	 *
	 * @param Facts An array of strings containing cat facts.
	 * @param bSuccess Whether the operation was successful, and whether the other parameters are valid.
	 */
	DECLARE_DELEGATE_TwoParams(FOnGetCatFactsComplete, TArray<FString>& /*Facts*/, bool /*bSuccess*/);

	/**
	 * Returns a list of cat facts from the cat facts API.
	 *
	 * @param MaxLength The max length of returned cat fact strings.
	 * @param Limit The number of cat facts to retrieve.
	 * @param Callback The callback to fire.
	 */
	NEXUSUNREALSDK_API void GetCatFacts(int32 MaxLength, int32 Limit, FOnGetCatFactsComplete& Callback);

}
