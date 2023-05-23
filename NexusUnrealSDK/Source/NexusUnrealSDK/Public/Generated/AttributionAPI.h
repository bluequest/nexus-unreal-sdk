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
 * Hullo there, this is the Nexus Unreal SDK, and this is my cool temp comment.
 * TODO: Here's the old descriptions from the two structs and delegate:
 *
 * Request:
 * A struct containing input values accepted by <NAME>
 *
 * Response:
 * A struct containing output values returned by <NAME>.
 * Always check bSuccess, if it is false, all other data is empty / defaulted.
 *
 * Delegate:
 * Declares a delegate that is executed when <NAME> has recieved
 * and decoded an HTTP response (even on failure).
 * Keep in mind that this is executed on the HTTP thread.
 *
 * @param Response Struct filled with data returned by the API.
 *
 */


	
	USTRUCT(BlueprintType)
	struct FNexusAttributionTransaction
	{
		GENERATED_BODY()
	
	
		UPROPERTY()
		FString creatorId;

		UPROPERTY()
		FString currency;

		UPROPERTY()
		FString description;

		UPROPERTY()
		FString status;

		UPROPERTY()
		double subtotal;

		UPROPERTY()
		FString transactionId;

		UPROPERTY()
		FDateTime transactionDate;

		UPROPERTY()
		FString playerId;

		UPROPERTY()
		FDateTime playerLastPurchase;

		UPROPERTY()
		FDateTime playerJoinDate;

		UPROPERTY()
		FString playerName;

		FNexusAttributionTransaction()
		: creatorId()
		, currency()
		, description()
		, status()
		, subtotal()
		, transactionId()
		, transactionDate()
		, playerId()
		, playerLastPurchase()
		, playerJoinDate()
		, playerName()
		{

		}

	
};

	
	USTRUCT(BlueprintType)
	struct FNexusAttributionCreator
	{
		GENERATED_BODY()
	
	
		UPROPERTY()
		FString id;

		UPROPERTY()
		FString name;

		UPROPERTY()
		FString logoImage;

		UPROPERTY()
		FString nexusUrl;

		UPROPERTY()
		FString profileImage;

		FNexusAttributionCreator()
		: id()
		, name()
		, logoImage()
		, nexusUrl()
		, profileImage()
		{

		}

	
};

	
	USTRUCT(BlueprintType)
	struct FNexusAttributionCreatorGroup
	{
		GENERATED_BODY()
	
	
		UPROPERTY()
		FString name;

		UPROPERTY()
		FString id;

		UPROPERTY()
		FString status;

		FNexusAttributionCreatorGroup()
		: name()
		, id()
		, status()
		{

		}

	
};

	
	USTRUCT(BlueprintType)
	struct FNexusAttributionGetCreatorsRequestParams
	{
		GENERATED_BODY()
	
	
		UPROPERTY()
		int32 page;

		UPROPERTY()
		int32 pageSize;

		UPROPERTY()
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
	
	
		UPROPERTY()
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
	
	
		UPROPERTY()
		int32 currentPage;

		UPROPERTY()
		int32 currentPageSize;

		UPROPERTY()
		TArray<FNexusAttributionCreator> creators;

		FNexusAttributionGetCreators200Response()
		: currentPage()
		, currentPageSize()
		, creators()
		{

		}

	
};

	
	USTRUCT(BlueprintType)
	struct FNexusAttributionGetCreatorByUuid200Response
	{
		GENERATED_BODY()
	
	
		UPROPERTY()
		TArray<FNexusAttributionCreatorGroup> groups;

		UPROPERTY()
		FString id;

		UPROPERTY()
		FString name;

		UPROPERTY()
		FString logoImage;

		UPROPERTY()
		FString nexusUrl;

		UPROPERTY()
		FString profileImage;

		FNexusAttributionGetCreatorByUuid200Response()
		: groups()
		, id()
		, name()
		, logoImage()
		, nexusUrl()
		, profileImage()
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
	static void GetCreators(const FNexusAttributionGetCreatorsRequestParams& RequestParams, const FOnGetCreators200ResponseCallback& Response, FNexusOnHttpErrorDelegate ErrorDelegate = {});

	DECLARE_DELEGATE_OneParam(FOnGetCreatorByUuid200ResponseCallback, const FNexusAttributionGetCreatorByUuid200Response& /*Response*/);
	static void GetCreatorByUuid(const FNexusAttributionGetCreatorByUuidRequestParams& RequestParams, const FOnGetCreatorByUuid200ResponseCallback& Response, FNexusOnHttpErrorDelegate ErrorDelegate = {});

};

//Blueprint Function Nodes


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


	virtual void Activate() override;

private:

	FNexusAttributionGetCreatorByUuidRequestParams RequestParams;
};
