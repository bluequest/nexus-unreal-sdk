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
struct FNexusAttributionCode
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString code;

	UPROPERTY(BlueprintReadWrite)
	bool isPrimary;

	UPROPERTY(BlueprintReadWrite)
	bool isGenerated;

	UPROPERTY(BlueprintReadWrite)
	bool isManaged;

	FNexusAttributionCode()
	: code()
		, isPrimary()
		, isGenerated()
		, isManaged()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionPlayerMetadata
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString displayName;

	FNexusAttributionPlayerMetadata()
	: displayName()
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
	bool isDefault;

	FNexusAttributionCreatorGroup()
	: name()
		, id()
		, isDefault()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionCreatorGroupTier
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
	double revShare;

	UPROPERTY(BlueprintReadWrite)
	double memberCount;

	FNexusAttributionCreatorGroupTier()
	: id()
		, name()
		, revShare()
		, memberCount()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionTierRevenueShare
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	double revShare;

	UPROPERTY(BlueprintReadWrite)
	FString tierId;

	UPROPERTY(BlueprintReadWrite)
	FString tierName;

	FNexusAttributionTierRevenueShare()
	: revShare()
		, tierId()
		, tierName()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionAPIError
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString code;

	UPROPERTY(BlueprintReadWrite)
	FString message;

	FNexusAttributionAPIError()
	: code()
		, message()
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
struct FNexusAttributionScheduledRevShare
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	double revShare;

	UPROPERTY(BlueprintReadWrite)
	FDateTime startDate;

	UPROPERTY(BlueprintReadWrite)
	FDateTime endDate;

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	FString groupName;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusAttributionTierRevenueShare> tierRevenueShares;

	FNexusAttributionScheduledRevShare()
	: id()
		, revShare()
		, startDate()
		, endDate()
		, groupId()
		, groupName()
		, tierRevenueShares()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionTransaction
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString memberId;

	UPROPERTY(BlueprintReadWrite)
	FString code;

	UPROPERTY(BlueprintReadWrite)
	FString memberPlayerId;

	UPROPERTY(BlueprintReadWrite)
	FString description;

	UPROPERTY(BlueprintReadWrite)
	FString status;

	UPROPERTY(BlueprintReadWrite)
	double subtotal;

	UPROPERTY(BlueprintReadWrite)
	FString currency;

	UPROPERTY(BlueprintReadWrite)
	double total;

	UPROPERTY(BlueprintReadWrite)
	FString totalCurrency;

	UPROPERTY(BlueprintReadWrite)
	FString transactionId;

	UPROPERTY(BlueprintReadWrite)
	FDateTime transactionDate;

	UPROPERTY(BlueprintReadWrite)
	FString platform;

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
	FString playerName;

	UPROPERTY(BlueprintReadWrite)
	FNexusAttributionMetrics metrics;

	UPROPERTY(BlueprintReadWrite)
	double memberShareAmount;

	UPROPERTY(BlueprintReadWrite)
	double memberSharePercent;

	UPROPERTY(BlueprintReadWrite)
	bool memberPaid;

	UPROPERTY(BlueprintReadWrite)
	FString skuId;

	FNexusAttributionTransaction()
	: id()
		, memberId()
		, code()
		, memberPlayerId()
		, description()
		, status()
		, subtotal()
		, currency()
		, total()
		, totalCurrency()
		, transactionId()
		, transactionDate()
		, platform()
		, playerId()
		, playerName()
		, metrics()
		, memberShareAmount()
		, memberSharePercent()
		, memberPaid()
		, skuId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionMember
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
	FNexusAttributionPlayerMetadata playerMetadata;

	UPROPERTY(BlueprintReadWrite)
	FString logoImage;

	UPROPERTY(BlueprintReadWrite)
	FString profileImage;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusAttributionCode> codes;

	FNexusAttributionMember()
	: id()
		, name()
		, playerId()
		, playerMetadata()
		, logoImage()
		, profileImage()
		, codes()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionGetMembersRequestParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 page;

	UPROPERTY(BlueprintReadWrite)
	int32 pageSize;

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	FNexusAttributionGetMembersRequestParams()
	: page()
		, pageSize()
		, groupId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionGetMemberByCodeOrUuidRequestParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString memberCodeOrID;

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	FNexusAttributionGetMemberByCodeOrUuidRequestParams()
	: memberCodeOrID()
		, groupId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionGetMemberByPlayerIdRequestParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	FNexusAttributionGetMemberByPlayerIdRequestParams()
	: playerId()
		, groupId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusAttributionGetMembers200Response
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	FString groupName;

	UPROPERTY(BlueprintReadWrite)
	int32 currentPage;

	UPROPERTY(BlueprintReadWrite)
	int32 currentPageSize;

	UPROPERTY(BlueprintReadWrite)
	int32 totalCount;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusAttributionMember> members;

	FNexusAttributionGetMembers200Response()
	: groupId()
		, groupName()
		, currentPage()
		, currentPageSize()
		, totalCount()
		, members()
	{
	}

};

/*---------------------------------------------------------------------------------------------
		API Functions
---------------------------------------------------------------------------------------------*/

class NEXUSUNREALSDK_API FNexusAttributionAPI
{
public:
	DECLARE_DELEGATE_OneParam(FOnGetMembers200ResponseCallback, const FNexusAttributionGetMembers200Response& /*Response*/);
	static void GetMembers(const FNexusAttributionGetMembersRequestParams& RequestParams, const FOnGetMembers200ResponseCallback& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

	DECLARE_DELEGATE_OneParam(FOnGetMemberByCodeOrUuid200ResponseCallback, const FNexusAttributionMember& /*Response*/);
	static void GetMemberByCodeOrUuid(const FNexusAttributionGetMemberByCodeOrUuidRequestParams& RequestParams, const FOnGetMemberByCodeOrUuid200ResponseCallback& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

	DECLARE_DELEGATE_OneParam(FOnGetMemberByPlayerId200ResponseCallback, const FNexusAttributionMember& /*Response*/);
	static void GetMemberByPlayerId(const FNexusAttributionGetMemberByPlayerIdRequestParams& RequestParams, const FOnGetMemberByPlayerId200ResponseCallback& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

};

/*---------------------------------------------------------------------------------------------
		Blueprint Function Nodes
---------------------------------------------------------------------------------------------*/

UCLASS()
class NEXUSUNREALSDK_API UNexusGetMembersNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetMembersNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Attribution", WorldContext = "WorldContextObject"))
	static UNexusGetMembersNode* GetMembers(UObject* WorldContextObject, const FNexusAttributionGetMembersRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetMembers200Response, const FNexusAttributionGetMembers200Response& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetMembers200Response On200Response;

	void When200Callback(const FNexusAttributionGetMembers200Response& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetMembersError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetMembersError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusAttributionGetMembersRequestParams RequestParams;

};

UCLASS()
class NEXUSUNREALSDK_API UNexusGetMemberByCodeOrUuidNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetMemberByCodeOrUuidNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Attribution", WorldContext = "WorldContextObject"))
	static UNexusGetMemberByCodeOrUuidNode* GetMemberByCodeOrUuid(UObject* WorldContextObject, const FNexusAttributionGetMemberByCodeOrUuidRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetMemberByCodeOrUuid200Response, const FNexusAttributionMember& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetMemberByCodeOrUuid200Response On200Response;

	void When200Callback(const FNexusAttributionMember& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetMemberByCodeOrUuidError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetMemberByCodeOrUuidError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusAttributionGetMemberByCodeOrUuidRequestParams RequestParams;

};

UCLASS()
class NEXUSUNREALSDK_API UNexusGetMemberByPlayerIdNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetMemberByPlayerIdNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Attribution", WorldContext = "WorldContextObject"))
	static UNexusGetMemberByPlayerIdNode* GetMemberByPlayerId(UObject* WorldContextObject, const FNexusAttributionGetMemberByPlayerIdRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetMemberByPlayerId200Response, const FNexusAttributionMember& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetMemberByPlayerId200Response On200Response;

	void When200Callback(const FNexusAttributionMember& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetMemberByPlayerIdError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetMemberByPlayerIdError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusAttributionGetMemberByPlayerIdRequestParams RequestParams;

};
