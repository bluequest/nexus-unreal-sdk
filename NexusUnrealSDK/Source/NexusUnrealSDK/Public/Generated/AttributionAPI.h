/**
 * NOTE NOTE NOTE
 * GENERATED CODE
 * ANY CHANGES TO THIS FILE WILL BE OVERWRITTEN
 * PLEASE MAKE ANY CHANGES TO THE SDK TEMPLATES IN THE SDK GENERATOR
 */
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "NexusShared.h"
#include "AttributionAPI.generated.h"

/**
 * Auto-generated header file for the Nexus Unreal SDK.
 * Sections:
 *  - Request and Response Types	- Types for this header
 *  - API Functions					- Static class containing functions
 *  - Blueprint Function Nodes		- Blueprint support
 *
 * Detailed documentation for the Unreal SDK is available at https://docs.nexus.gg
 *
 * Quick start:
 * Pick a function from the API functions section and check out the parameters it takes.
 * Fill out a request parameters structure for the function.
 * Set up a few delegate callbacks depending on how many the function takes,
 * some take just a success and error delegate, though they may take more passed in via a struct.
 * Call the function! You will recieve a success or error callback later depending on parameters
 * passed in and server availability.
 */

/*---------------------------------------------------------------------------------------------
		Request and Response Types
---------------------------------------------------------------------------------------------*/

USTRUCT(BlueprintType)
struct FNexusAttributionCreator
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
	FString logoImage;

	UPROPERTY(BlueprintReadWrite)
	FString nexusUrl;

	UPROPERTY(BlueprintReadWrite)
	FString code;

	UPROPERTY(BlueprintReadWrite)
	FString profileImage;

	FNexusAttributionCreator()
	: id()
		, name()
		, logoImage()
		, nexusUrl()
		, code()
		, profileImage()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionCreatorGroup
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString status;

	FNexusAttributionCreatorGroup()
	: name()
		, id()
		, status()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributiontotalSpendToDate_Struct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	double total;

	UPROPERTY(BlueprintReadWrite)
	FString currency;

	FNexusAttributiontotalSpendToDate_Struct()
	: total()
		, currency()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionconversion_Struct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FDateTime lastPurchaseDate;

	UPROPERTY(BlueprintReadWrite)
	FNexusAttributiontotalSpendToDate_Struct totalSpendToDate;

	FNexusAttributionconversion_Struct()
	: lastPurchaseDate()
		, totalSpendToDate()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionMetrics
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FDateTime joinDate;

	UPROPERTY(BlueprintReadWrite)
	FNexusAttributionconversion_Struct conversion;

	FNexusAttributionMetrics()
	: joinDate()
		, conversion()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionTransaction
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString creatorId;

	UPROPERTY(BlueprintReadWrite)
	FString currency;

	UPROPERTY(BlueprintReadWrite)
	FString description;

	UPROPERTY(BlueprintReadWrite)
	FString status;

	UPROPERTY(BlueprintReadWrite)
	double subtotal;

	UPROPERTY(BlueprintReadWrite)
	FString transactionId;

	UPROPERTY(BlueprintReadWrite)
	FDateTime transactionDate;

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
	FString playerName;

	UPROPERTY(BlueprintReadWrite)
	FNexusAttributionMetrics metrics;

	FNexusAttributionTransaction()
	: creatorId()
		, currency()
		, description()
		, status()
		, subtotal()
		, transactionId()
		, transactionDate()
		, playerId()
		, playerName()
		, metrics()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionGetCreatorsRequestParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 page;

	UPROPERTY(BlueprintReadWrite)
	int32 pageSize;

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	FNexusAttributionGetCreatorsRequestParams()
	: page()
		, pageSize()
		, groupId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionGetCreatorByUuidRequestParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString creatorSlugOrId;

	FNexusAttributionGetCreatorByUuidRequestParams()
	: creatorSlugOrId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionGetCreators200Response
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 currentPage;

	UPROPERTY(BlueprintReadWrite)
	int32 currentPageSize;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusAttributionCreator> creators;

	FNexusAttributionGetCreators200Response()
	: currentPage()
		, currentPageSize()
		, creators()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributiongroups_Struct_Element
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString groupName;

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	FString status;

	FNexusAttributiongroups_Struct_Element()
	: groupName()
		, groupId()
		, status()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributioncreator_Struct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
	FString logoImage;

	UPROPERTY(BlueprintReadWrite)
	FString nexusUrl;

	UPROPERTY(BlueprintReadWrite)
	FString code;

	UPROPERTY(BlueprintReadWrite)
	FString profileImage;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusAttributiongroups_Struct_Element> groups;

	FNexusAttributioncreator_Struct()
	: id()
		, name()
		, logoImage()
		, nexusUrl()
		, code()
		, profileImage()
		, groups()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionGetCreatorByUuid200Response
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FNexusAttributioncreator_Struct creator;

	FNexusAttributionGetCreatorByUuid200Response()
	: creator()
	{
	}

};

/*---------------------------------------------------------------------------------------------
		API Functions
---------------------------------------------------------------------------------------------*/

class NEXUSUNREALSDK_API FNexusAttributionAPI
{
public:
	DECLARE_DELEGATE_OneParam(FOnGetCreators200ResponseCallback, const FNexusAttributionGetCreators200Response& /*Response*/);
	static void GetCreators(const FNexusAttributionGetCreatorsRequestParams& RequestParams, const FOnGetCreators200ResponseCallback& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

	DECLARE_DELEGATE_OneParam(FOnGetCreatorByUuid200ResponseCallback, const FNexusAttributionGetCreatorByUuid200Response& /*Response*/);
	static void GetCreatorByUuid(const FNexusAttributionGetCreatorByUuidRequestParams& RequestParams, const FOnGetCreatorByUuid200ResponseCallback& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

};

/*---------------------------------------------------------------------------------------------
		Blueprint Function Nodes
---------------------------------------------------------------------------------------------*/

UCLASS()
class NEXUSUNREALSDK_API UNexusGetCreatorsNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetCreatorsNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Attribution", WorldContext = "WorldContextObject"))
	static UNexusGetCreatorsNode* GetCreators(UObject* WorldContextObject, const FNexusAttributionGetCreatorsRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetCreators200Response, const FNexusAttributionGetCreators200Response& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetCreators200Response On200Response;

	void When200Callback(const FNexusAttributionGetCreators200Response& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetCreatorsError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetCreatorsError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusAttributionGetCreatorsRequestParams RequestParams;

};

UCLASS()
class NEXUSUNREALSDK_API UNexusGetCreatorByUuidNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetCreatorByUuidNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Attribution", WorldContext = "WorldContextObject"))
	static UNexusGetCreatorByUuidNode* GetCreatorByUuid(UObject* WorldContextObject, const FNexusAttributionGetCreatorByUuidRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetCreatorByUuid200Response, const FNexusAttributionGetCreatorByUuid200Response& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetCreatorByUuid200Response On200Response;

	void When200Callback(const FNexusAttributionGetCreatorByUuid200Response& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetCreatorByUuidError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetCreatorByUuidError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusAttributionGetCreatorByUuidRequestParams RequestParams;

};
