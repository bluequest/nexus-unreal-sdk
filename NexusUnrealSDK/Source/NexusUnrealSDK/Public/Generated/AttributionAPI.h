/**
 * NOTE NOTE NOTE
 * GENERATED CODE
 * ANY CHANGES TO THIS FILE WILL BE OVERWRITTEN
 * PLEASE MAKE ANY CHANGES TO THE SDK TEMPLATES IN THE SDK GENERATOR
 */
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
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
	};

	
	USTRUCT(BlueprintType)
	struct FNexusAttributionGetCreatorByUuidRequestParams
	{
		GENERATED_BODY()
	
	
		UPROPERTY()
		FString creatorSlugOrId;
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
	};


	/*---------------------------------------------------------------------------------------------
			API Functions
	---------------------------------------------------------------------------------------------*/
NEXUSUNREALSDK_API class FNexusAttributionAPI
{
public:
	DECLARE_DELEGATE_OneParam(FOnGetCreators200ResponseCallback, FNexusAttributionGetCreators200Response);
	static void GetCreators(const FNexusAttributionGetCreatorsRequestParams& RequestParams, FOnGetCreators200ResponseCallback Response);

	DECLARE_DELEGATE_OneParam(FOnGetCreatorByUuid200ResponseCallback, FNexusAttributionGetCreatorByUuid200Response);
	static void GetCreatorByUuid(const FNexusAttributionGetCreatorByUuidRequestParams& RequestParams, FOnGetCreatorByUuid200ResponseCallback Response);

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


	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetCreators200Response, FNexusAttributionGetCreators200Response, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetCreators200Response On200Response;

	void When200Callback(FNexusAttributionGetCreators200Response Param0);

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


	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetCreatorByUuid200Response, FNexusAttributionGetCreatorByUuid200Response, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetCreatorByUuid200Response On200Response;

	void When200Callback(FNexusAttributionGetCreatorByUuid200Response Param0);

	virtual void Activate() override;

private:

	FNexusAttributionGetCreatorByUuidRequestParams RequestParams;
};
