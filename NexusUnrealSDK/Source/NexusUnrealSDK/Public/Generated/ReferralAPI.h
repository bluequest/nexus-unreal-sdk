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

/*---------------------------------------------------------------------------------------------
		Request and Response Types
---------------------------------------------------------------------------------------------*/

USTRUCT(BlueprintType)
struct FNexusReferralReferral
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString code;

	UPROPERTY()
	FString playerId;

	UPROPERTY()
	FString playerName;

	UPROPERTY()
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

	UPROPERTY()
	FString code;

	UPROPERTY()
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

	UPROPERTY()
	FString code;

	UPROPERTY()
	bool isPrimary;

	UPROPERTY()
	bool isGenerated;

	UPROPERTY()
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

	UPROPERTY()
	FString playerId;

	UPROPERTY()
	FString groupId;

	UPROPERTY()
	int32 page;

	UPROPERTY()
	int32 pageSize;

	UPROPERTY()
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

	UPROPERTY()
	FString playerId;

	UPROPERTY()
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

	UPROPERTY()
	FString code;

	UPROPERTY()
	FString groupId;

	UPROPERTY()
	int32 page;

	UPROPERTY()
	int32 pageSize;

	UPROPERTY()
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

	UPROPERTY()
	FString groupId;

	UPROPERTY()
	FString groupName;

	UPROPERTY()
	TArray<FNexusReferralReferralCodeResponse> referralCodes;

	UPROPERTY()
	FString playerId;

	UPROPERTY()
	int32 currentPage;

	UPROPERTY()
	int32 currentPageSize;

	UPROPERTY()
	int32 totalCount;

	UPROPERTY()
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

	UPROPERTY()
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

	UPROPERTY()
	FString groupId;

	UPROPERTY()
	FString groupName;

	UPROPERTY()
	TArray<FNexusReferralReferralCodeResponse> referralCodes;

	UPROPERTY()
	FString playerId;

	UPROPERTY()
	int32 currentPage;

	UPROPERTY()
	int32 currentPageSize;

	UPROPERTY()
	int32 totalCount;

	UPROPERTY()
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
