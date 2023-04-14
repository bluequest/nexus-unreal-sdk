// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "NexusPrototype.h"

class FNexusUnrealSDKModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** Add a request to the module cache. */
	inline void AddRequest(NexusSDK::FRequestContextPtr RequestPtr)
	{
		ActiveRequestContexts.Add(MoveTemp(RequestPtr));
	}

	/** Remove (and delete) a request from the module cache, takes a raw pointer. */
	NEXUSUNREALSDK_API void RemoveRequest(NexusSDK::FRequestContext* RequestPtr);

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	NEXUSUNREALSDK_API static FNexusUnrealSDKModule& Get();

private:
	/*
	 * Under the hood, the SDK makes REST API calls to get the info it needs. We store the states
	 * here to keep the interface as simple as possible.
	 */
	TArray<NexusSDK::FRequestContextPtr> ActiveRequestContexts;
};
