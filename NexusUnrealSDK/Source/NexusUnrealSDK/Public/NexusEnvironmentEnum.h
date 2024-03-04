#pragma once

#include "CoreMinimal.h"
#include "NexusEnvironmentEnum.generated.h"

UENUM(BlueprintType)
enum class ENexusEnvironment : uint8
{
    Production UMETA(DisplayName = "Production"),
    Sandbox UMETA(DisplayName = "Sandbox")
};