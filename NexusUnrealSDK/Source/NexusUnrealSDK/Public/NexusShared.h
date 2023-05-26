// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EngineMinimal.h"

/**
 * Shared stuff between all Nexus interfaces.
 */

DECLARE_DELEGATE_OneParam(FNexusOnHttpErrorDelegate, int32);

namespace NexusSDK
{
	/** Simple abstract base class that represents the state of a request, should not need a virtual destructor. */
	class FRequestContext
	{
	};

	/** The class above as a unique pointer. */
	using FRequestContextPtr = TUniquePtr<FRequestContext>;

} // namespace NexusSDK
