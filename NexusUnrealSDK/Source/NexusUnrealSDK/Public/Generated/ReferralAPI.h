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
#include "ReferralAPI.generated.h"

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
struct FNexusReferralReferral
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString code;

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
	FString playerName;

	UPROPERTY(BlueprintReadWrite)
	FDateTime referralDate;

	FNexusReferralReferral()
	: id()
		, code()
		, playerId()
		, playerName()
		, referralDate()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusReferralReferralError
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString code;

	UPROPERTY(BlueprintReadWrite)
	FString message;

	FNexusReferralReferralError()
	: code()
		, message()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusReferralReferralCodeResponse
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

	FNexusReferralReferralCodeResponse()
	: code()
		, isPrimary()
		, isGenerated()
		, isManaged()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusReferralGetReferralInfoByPlayerIdRequestParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	int32 page;

	UPROPERTY(BlueprintReadWrite)
	int32 pageSize;

	UPROPERTY(BlueprintReadWrite)
	bool excludeReferralList;

	FNexusReferralGetReferralInfoByPlayerIdRequestParams()
	: playerId()
		, groupId()
		, page()
		, pageSize()
		, excludeReferralList()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusReferralGetPlayerCurrentReferralRequestParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	FNexusReferralGetPlayerCurrentReferralRequestParams()
	: playerId()
		, groupId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusReferralGetReferralInfoByCodeRequestParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString code;

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	int32 page;

	UPROPERTY(BlueprintReadWrite)
	int32 pageSize;

	UPROPERTY(BlueprintReadWrite)
	bool excludeReferralList;

	FNexusReferralGetReferralInfoByCodeRequestParams()
	: code()
		, groupId()
		, page()
		, pageSize()
		, excludeReferralList()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusReferralGetReferralInfoByPlayerId200Response
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	FString groupName;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusReferralReferralCodeResponse> referralCodes;

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
	int32 currentPage;

	UPROPERTY(BlueprintReadWrite)
	int32 currentPageSize;

	UPROPERTY(BlueprintReadWrite)
	int32 totalCount;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusReferralReferral> referrals;

	FNexusReferralGetReferralInfoByPlayerId200Response()
	: groupId()
		, groupName()
		, referralCodes()
		, playerId()
		, currentPage()
		, currentPageSize()
		, totalCount()
		, referrals()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusReferralGetPlayerCurrentReferral404Response
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString code;

	FNexusReferralGetPlayerCurrentReferral404Response()
	: code()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusReferralGetReferralInfoByCode200Response
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	FString groupName;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusReferralReferralCodeResponse> referralCodes;

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
	int32 currentPage;

	UPROPERTY(BlueprintReadWrite)
	int32 currentPageSize;

	UPROPERTY(BlueprintReadWrite)
	int32 totalCount;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusReferralReferral> referrals;

	FNexusReferralGetReferralInfoByCode200Response()
	: groupId()
		, groupName()
		, referralCodes()
		, playerId()
		, currentPage()
		, currentPageSize()
		, totalCount()
		, referrals()
	{
	}

};

/*---------------------------------------------------------------------------------------------
		API Functions
---------------------------------------------------------------------------------------------*/

class NEXUSUNREALSDK_API FNexusReferralAPI
{
public:
	DECLARE_DELEGATE_OneParam(FOnGetReferralInfoByPlayerId200ResponseCallback, const FNexusReferralGetReferralInfoByPlayerId200Response& /*Response*/);
	DECLARE_DELEGATE_OneParam(FOnGetReferralInfoByPlayerId400ResponseCallback, const FNexusReferralReferralError& /*Response*/);

	struct FOnGetReferralInfoByPlayerIdResponse
	{
			FOnGetReferralInfoByPlayerId200ResponseCallback On200Response;
			FOnGetReferralInfoByPlayerId400ResponseCallback On400Response;
	};
	static void GetReferralInfoByPlayerId(const FNexusReferralGetReferralInfoByPlayerIdRequestParams& RequestParams, const FOnGetReferralInfoByPlayerIdResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

	DECLARE_DELEGATE_OneParam(FOnGetPlayerCurrentReferral200ResponseCallback, const FString& /*Response*/);
	DECLARE_DELEGATE_OneParam(FOnGetPlayerCurrentReferral404ResponseCallback, const FNexusReferralGetPlayerCurrentReferral404Response& /*Response*/);

	struct FOnGetPlayerCurrentReferralResponse
	{
			FOnGetPlayerCurrentReferral200ResponseCallback On200Response;
			FOnGetPlayerCurrentReferral404ResponseCallback On404Response;
	};
	static void GetPlayerCurrentReferral(const FNexusReferralGetPlayerCurrentReferralRequestParams& RequestParams, const FOnGetPlayerCurrentReferralResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

	DECLARE_DELEGATE_OneParam(FOnGetReferralInfoByCode200ResponseCallback, const FNexusReferralGetReferralInfoByCode200Response& /*Response*/);
	DECLARE_DELEGATE_OneParam(FOnGetReferralInfoByCode400ResponseCallback, const FNexusReferralReferralError& /*Response*/);

	struct FOnGetReferralInfoByCodeResponse
	{
			FOnGetReferralInfoByCode200ResponseCallback On200Response;
			FOnGetReferralInfoByCode400ResponseCallback On400Response;
	};
	static void GetReferralInfoByCode(const FNexusReferralGetReferralInfoByCodeRequestParams& RequestParams, const FOnGetReferralInfoByCodeResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

};

/*---------------------------------------------------------------------------------------------
		Blueprint Function Nodes
---------------------------------------------------------------------------------------------*/

UCLASS()
class NEXUSUNREALSDK_API UNexusGetReferralInfoByPlayerIdNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetReferralInfoByPlayerIdNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Referral", WorldContext = "WorldContextObject"))
	static UNexusGetReferralInfoByPlayerIdNode* GetReferralInfoByPlayerId(UObject* WorldContextObject, const FNexusReferralGetReferralInfoByPlayerIdRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetReferralInfoByPlayerId200Response, const FNexusReferralGetReferralInfoByPlayerId200Response& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetReferralInfoByPlayerId200Response On200Response;

	void When200Callback(const FNexusReferralGetReferralInfoByPlayerId200Response& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetReferralInfoByPlayerId400Response, const FNexusReferralReferralError& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetReferralInfoByPlayerId400Response On400Response;

	void When400Callback(const FNexusReferralReferralError& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetReferralInfoByPlayerIdError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetReferralInfoByPlayerIdError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusReferralGetReferralInfoByPlayerIdRequestParams RequestParams;

};

UCLASS()
class NEXUSUNREALSDK_API UNexusGetPlayerCurrentReferralNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetPlayerCurrentReferralNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Referral", WorldContext = "WorldContextObject"))
	static UNexusGetPlayerCurrentReferralNode* GetPlayerCurrentReferral(UObject* WorldContextObject, const FNexusReferralGetPlayerCurrentReferralRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetPlayerCurrentReferral200Response, const FString& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetPlayerCurrentReferral200Response On200Response;

	void When200Callback(const FString& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetPlayerCurrentReferral404Response, const FNexusReferralGetPlayerCurrentReferral404Response& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetPlayerCurrentReferral404Response On404Response;

	void When404Callback(const FNexusReferralGetPlayerCurrentReferral404Response& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetPlayerCurrentReferralError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetPlayerCurrentReferralError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusReferralGetPlayerCurrentReferralRequestParams RequestParams;

};

UCLASS()
class NEXUSUNREALSDK_API UNexusGetReferralInfoByCodeNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetReferralInfoByCodeNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Referral", WorldContext = "WorldContextObject"))
	static UNexusGetReferralInfoByCodeNode* GetReferralInfoByCode(UObject* WorldContextObject, const FNexusReferralGetReferralInfoByCodeRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetReferralInfoByCode200Response, const FNexusReferralGetReferralInfoByCode200Response& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetReferralInfoByCode200Response On200Response;

	void When200Callback(const FNexusReferralGetReferralInfoByCode200Response& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetReferralInfoByCode400Response, const FNexusReferralReferralError& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetReferralInfoByCode400Response On400Response;

	void When400Callback(const FNexusReferralReferralError& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetReferralInfoByCodeError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetReferralInfoByCodeError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusReferralGetReferralInfoByCodeRequestParams RequestParams;

};
