// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NexusEnvironmentEnum.h"
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

	UPROPERTY(Config, EditAnywhere, Category = "General", meta = (
		DisplayName = "Nexus Environment",
		ToolTip = "Select a nexus environment"))
	ENexusEnvironment NexusEnvironment;

	FString GetBaseURL() const
	{
		switch (NexusEnvironment)
		{
		case ENexusEnvironment::Production:
			return TEXT("https://api.nexus.gg/v1");
		case ENexusEnvironment::Sandbox:
			return TEXT("https://api.nexus-dev.gg/v1");
		default:
			return TEXT("");
		}
	}
};
