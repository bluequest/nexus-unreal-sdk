// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NexusSettings.generated.h"

/**
 * Nexus SDK plugin settings
 */

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Nexus SDK"))
class UNexusUnrealSDKSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	/** Shortcut for GetDefault. */
	static const UNexusUnrealSDKSettings *Get()
	{
		return GetDefault<UNexusUnrealSDKSettings>();
	}

	UPROPERTY(Config, EditAnywhere, Category = "General", meta = (
		DisplayName = "Public API Key",
		ToolTip = "This is your public facing Nexus API key."))
	FName PublicKey;
};
