// Copyright Epic Games, Inc. All Rights Reserved.

#include "NexusUnrealSDK.h"
#include "NexusPrivate.h"

DEFINE_LOG_CATEGORY(LogNexusSDK)

#define LOCTEXT_NAMESPACE "FNexusUnrealSDKModule"

void FNexusUnrealSDKModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FNexusUnrealSDKModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FNexusUnrealSDKModule::RemoveRequest(NexusSDK::FRequestContext* Request)
{
	// We shouldn't ever have a large backlog of active requests, so this isn't too bad.
	// This will typically be executed on the HTTP thread too.
	for (int32 i = 0; i < ActiveRequestContexts.Num(); ++i)
	{
		const NexusSDK::FRequestContextPtr& RequestPtr = ActiveRequestContexts[i];
		if ( RequestPtr.Get() == Request )
		{
			ActiveRequestContexts.RemoveAt(i);
			return;
		}
	}
	// TODO: Warn if we couldn't find it? This should never happen.
}

FNexusUnrealSDKModule& FNexusUnrealSDKModule::Get()
{
	return FModuleManager::LoadModuleChecked<FNexusUnrealSDKModule>("NexusUnrealSDK");
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNexusUnrealSDKModule, NexusUnrealSDK)