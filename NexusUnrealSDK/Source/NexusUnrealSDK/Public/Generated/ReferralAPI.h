/**
 * NOTE NOTE NOTE
 * GENERATED CODE
 * ANY CHANGES TO THIS FILE WILL BE OVERWRITTEN
 * PLEASE MAKE ANY CHANGES TO THE SDK TEMPLATES IN THE SDK GENERATOR
 */
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
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
	};

	
	USTRUCT(BlueprintType)
	struct FNexusReferralReferralError
	{
		GENERATED_BODY()
	
	
		UPROPERTY()
		FString code;

		UPROPERTY()
		FString message;
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
	};

	
	USTRUCT(BlueprintType)
	struct FNexusReferralGetPlayerCurrentReferralRequestParams
	{
		GENERATED_BODY()
	
	
		UPROPERTY()
		FString playerId;

		UPROPERTY()
		FString groupId;
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
	};

	
	USTRUCT(BlueprintType)
	struct FNexusReferralGetPlayerCurrentReferral404Response
	{
		GENERATED_BODY()
	
	
		UPROPERTY()
		FString code;
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
	};


	/*---------------------------------------------------------------------------------------------
			API Functions
	---------------------------------------------------------------------------------------------*/
NEXUSUNREALSDK_API class FNexusReferralAPI
{
public:
	DECLARE_DELEGATE_OneParam(FOnGetReferralInfoByPlayerId200ResponseCallback, FNexusReferralGetReferralInfoByPlayerId200Response);
	DECLARE_DELEGATE_OneParam(FOnGetReferralInfoByPlayerId400ResponseCallback, FNexusReferralReferralError);

	struct FOnGetReferralInfoByPlayerIdResponse
	{
			FOnGetReferralInfoByPlayerId200ResponseCallback On200Response;
			FOnGetReferralInfoByPlayerId400ResponseCallback On400Response;
	};
	static void GetReferralInfoByPlayerId(const FNexusReferralGetReferralInfoByPlayerIdRequestParams& RequestParams, FOnGetReferralInfoByPlayerIdResponse Response);

	DECLARE_DELEGATE_OneParam(FOnGetPlayerCurrentReferral200ResponseCallback, FString);
	DECLARE_DELEGATE_OneParam(FOnGetPlayerCurrentReferral404ResponseCallback, FNexusReferralGetPlayerCurrentReferral404Response);

	struct FOnGetPlayerCurrentReferralResponse
	{
			FOnGetPlayerCurrentReferral200ResponseCallback On200Response;
			FOnGetPlayerCurrentReferral404ResponseCallback On404Response;
	};
	static void GetPlayerCurrentReferral(const FNexusReferralGetPlayerCurrentReferralRequestParams& RequestParams, FOnGetPlayerCurrentReferralResponse Response);

	DECLARE_DELEGATE_OneParam(FOnGetReferralInfoByCode200ResponseCallback, FNexusReferralGetReferralInfoByCode200Response);
	DECLARE_DELEGATE_OneParam(FOnGetReferralInfoByCode400ResponseCallback, FNexusReferralReferralError);

	struct FOnGetReferralInfoByCodeResponse
	{
			FOnGetReferralInfoByCode200ResponseCallback On200Response;
			FOnGetReferralInfoByCode400ResponseCallback On400Response;
	};
	static void GetReferralInfoByCode(const FNexusReferralGetReferralInfoByCodeRequestParams& RequestParams, FOnGetReferralInfoByCodeResponse Response);

};

//Blueprint Function Nodes


UCLASS()
class NEXUSUNREALSDK_API UNexusGetReferralInfoByPlayerIdNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	UNexusGetReferralInfoByPlayerIdNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Referral", WorldContext = "WorldContextObject"))
					static UNexusGetReferralInfoByPlayerIdNode* GetReferralInfoByPlayerId(UObject* WorldContextObject, const FNexusReferralGetReferralInfoByPlayerIdRequestParams& InRequestParams);


	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetReferralInfoByPlayerId200Response, FNexusReferralGetReferralInfoByPlayerId200Response, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetReferralInfoByPlayerId200Response On200Response;

	void When200Callback(FNexusReferralGetReferralInfoByPlayerId200Response Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetReferralInfoByPlayerId400Response, FNexusReferralReferralError, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetReferralInfoByPlayerId400Response On400Response;

	void When400Callback(FNexusReferralReferralError Param0);

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


	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetPlayerCurrentReferral200Response, FString, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetPlayerCurrentReferral200Response On200Response;

	void When200Callback(FString Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetPlayerCurrentReferral404Response, FNexusReferralGetPlayerCurrentReferral404Response, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetPlayerCurrentReferral404Response On404Response;

	void When404Callback(FNexusReferralGetPlayerCurrentReferral404Response Param0);

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


	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetReferralInfoByCode200Response, FNexusReferralGetReferralInfoByCode200Response, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetReferralInfoByCode200Response On200Response;

	void When200Callback(FNexusReferralGetReferralInfoByCode200Response Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetReferralInfoByCode400Response, FNexusReferralReferralError, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetReferralInfoByCode400Response On400Response;

	void When400Callback(FNexusReferralReferralError Param0);

	virtual void Activate() override;

private:

	FNexusReferralGetReferralInfoByCodeRequestParams RequestParams;
};
