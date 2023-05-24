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
#include "BountyAPI.generated.h"

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
struct FNexusBountyBountySku
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	UPROPERTY()
	FString slug;

	FNexusBountyBountySku()
	: id()
		, name()
		, slug()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyBountyProgressReward
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	UPROPERTY()
	FString externalId;

	UPROPERTY()
	bool rewardCompleted;

	UPROPERTY()
	FString rewardReferenceId;

	FNexusBountyBountyProgressReward()
	: id()
		, name()
		, externalId()
		, rewardCompleted()
		, rewardReferenceId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyCreator
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString playerId;

	UPROPERTY()
	FString name;

	UPROPERTY()
	TArray<FString> slugs;

	FNexusBountyCreator()
	: id()
		, playerId()
		, name()
		, slugs()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyCreatorGroupEvent
{
	GENERATED_BODY()

	UPROPERTY()
	FString eventCode;

	UPROPERTY()
	FString playerId;

	UPROPERTY()
	FString referralCode;

	FNexusBountyCreatorGroupEvent()
	: eventCode()
		, playerId()
		, referralCode()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyBountyError
{
	GENERATED_BODY()

	UPROPERTY()
	FString code;

	UPROPERTY()
	FString message;

	FNexusBountyBountyError()
	: code()
		, message()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountycategory_Struct
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	UPROPERTY()
	FString slug;

	FNexusBountycategory_Struct()
	: id()
		, name()
		, slug()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountypublisher_Struct
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	FNexusBountypublisher_Struct()
	: id()
		, name()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountydependants_Struct_Element
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	FNexusBountydependants_Struct_Element()
	: id()
		, name()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyprerequisites_Struct_Element
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	FNexusBountyprerequisites_Struct_Element()
	: id()
		, name()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyobjective_Struct
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	UPROPERTY()
	double count;

	UPROPERTY()
	FString condition;

	FNexusBountyobjective_Struct()
	: id()
		, name()
		, count()
		, condition()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyBountyObjectiveProgress
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	bool completed;

	UPROPERTY()
	double count;

	UPROPERTY()
	FNexusBountyobjective_Struct objective;

	FNexusBountyBountyObjectiveProgress()
	: id()
		, completed()
		, count()
		, objective()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyBountyReward
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	UPROPERTY()
	FString type;

	UPROPERTY()
	FNexusBountyBountySku sku;

	UPROPERTY()
	double amount;

	UPROPERTY()
	FString currency;

	UPROPERTY()
	FString externalId;

	FNexusBountyBountyReward()
	: id()
		, name()
		, type()
		, sku()
		, amount()
		, currency()
		, externalId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyBountyObjective
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	UPROPERTY()
	FString type;

	UPROPERTY()
	FString condition;

	UPROPERTY()
	double count;

	UPROPERTY()
	FString eventType;

	UPROPERTY()
	FString eventCode;

	UPROPERTY()
	FString nexusPurchaseObjectiveType;

	UPROPERTY()
	TArray<FNexusBountyBountySku> skus;

	UPROPERTY()
	FNexusBountycategory_Struct category;

	UPROPERTY()
	FNexusBountypublisher_Struct publisher;

	FNexusBountyBountyObjective()
	: id()
		, name()
		, type()
		, condition()
		, count()
		, eventType()
		, eventCode()
		, nexusPurchaseObjectiveType()
		, skus()
		, category()
		, publisher()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountycompletedObjectives_Struct_Element
{
	GENERATED_BODY()

	UPROPERTY()
	FString objectiveGroupId;

	UPROPERTY()
	TArray<FNexusBountyBountyObjective> objectives;

	UPROPERTY()
	TArray<FNexusBountyBountyReward> rewards;

	FNexusBountycompletedObjectives_Struct_Element()
	: objectiveGroupId()
		, objectives()
		, rewards()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyBounty
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	UPROPERTY()
	FString description;

	UPROPERTY()
	FString imageSrc;

	UPROPERTY()
	FString rewardDescription;

	UPROPERTY()
	double limit;

	UPROPERTY()
	FDateTime startsAt;

	UPROPERTY()
	FDateTime endsAt;

	UPROPERTY()
	FDateTime lastProgressCheck;

	UPROPERTY()
	TArray<FNexusBountyBountyObjective> objectives;

	UPROPERTY()
	TArray<FNexusBountyBountyReward> rewards;

	UPROPERTY()
	TArray<FNexusBountydependants_Struct_Element> dependants;

	UPROPERTY()
	TArray<FNexusBountyprerequisites_Struct_Element> prerequisites;

	FNexusBountyBounty()
	: id()
		, name()
		, description()
		, imageSrc()
		, rewardDescription()
		, limit()
		, startsAt()
		, endsAt()
		, lastProgressCheck()
		, objectives()
		, rewards()
		, dependants()
		, prerequisites()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyBountyProgress
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	bool completed;

	UPROPERTY()
	double completionCount;

	UPROPERTY()
	FDateTime lastProgressCheck;

	UPROPERTY()
	FString currentObjectiveGroupId;

	UPROPERTY()
	TArray<FNexusBountyBountyObjectiveProgress> currentObjectives;

	UPROPERTY()
	TArray<FNexusBountycompletedObjectives_Struct_Element> completedObjectives;

	FNexusBountyBountyProgress()
	: id()
		, completed()
		, completionCount()
		, lastProgressCheck()
		, currentObjectiveGroupId()
		, currentObjectives()
		, completedObjectives()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyGetBountiesRequestParams
{
	GENERATED_BODY()

	UPROPERTY()
	FString groupId;

	UPROPERTY()
	int32 page;

	UPROPERTY()
	int32 pageSize;

	FNexusBountyGetBountiesRequestParams()
	: groupId()
		, page()
		, pageSize()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyGetBountyRequestParams
{
	GENERATED_BODY()

	UPROPERTY()
	FString groupId;

	UPROPERTY()
	bool includeProgress;

	UPROPERTY()
	int32 page;

	UPROPERTY()
	int32 pageSize;

	UPROPERTY()
	FString bountyId;

	FNexusBountyGetBountyRequestParams()
	: groupId()
		, includeProgress()
		, page()
		, pageSize()
		, bountyId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyGetCreatorBountiesByIDRequestParams
{
	GENERATED_BODY()

	UPROPERTY()
	FString groupId;

	UPROPERTY()
	int32 page;

	UPROPERTY()
	int32 pageSize;

	UPROPERTY()
	FString creatorId;

	FNexusBountyGetCreatorBountiesByIDRequestParams()
	: groupId()
		, page()
		, pageSize()
		, creatorId()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyGetBounties200Response
{
	GENERATED_BODY()

	UPROPERTY()
	FString groupId;

	UPROPERTY()
	FString groupName;

	UPROPERTY()
	int32 currentPage;

	UPROPERTY()
	int32 currentPageSize;

	UPROPERTY()
	int32 totalCount;

	UPROPERTY()
	TArray<FNexusBountyBounty> bounties;

	FNexusBountyGetBounties200Response()
	: groupId()
		, groupName()
		, currentPage()
		, currentPageSize()
		, totalCount()
		, bounties()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountydata_Struct_Element
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	bool completed;

	UPROPERTY()
	double completionCount;

	UPROPERTY()
	FDateTime lastProgressCheck;

	UPROPERTY()
	FString currentObjectiveGroupId;

	UPROPERTY()
	TArray<FNexusBountyBountyObjectiveProgress> currentObjectives;

	UPROPERTY()
	TArray<FNexusBountycompletedObjectives_Struct_Element> completedObjectives;

	UPROPERTY()
	FNexusBountyCreator creator;

	FNexusBountydata_Struct_Element()
	: id()
		, completed()
		, completionCount()
		, lastProgressCheck()
		, currentObjectiveGroupId()
		, currentObjectives()
		, completedObjectives()
		, creator()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyprogress_Struct
{
	GENERATED_BODY()

	UPROPERTY()
	int32 currentPage;

	UPROPERTY()
	int32 currentPageSize;

	UPROPERTY()
	int32 totalCount;

	UPROPERTY()
	TArray<FNexusBountydata_Struct_Element> data;

	FNexusBountyprogress_Struct()
	: currentPage()
		, currentPageSize()
		, totalCount()
		, data()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyGetBounty200Response
{
	GENERATED_BODY()

	UPROPERTY()
	FString groupId;

	UPROPERTY()
	FString groupName;

	UPROPERTY()
	FNexusBountyBounty bounty;

	UPROPERTY()
	FNexusBountyprogress_Struct progress;

	FNexusBountyGetBounty200Response()
	: groupId()
		, groupName()
		, bounty()
		, progress()
	{
	}

};

USTRUCT(BlueprintType)
struct FNexusBountyGetCreatorBountiesByID200Response
{
	GENERATED_BODY()

	UPROPERTY()
	FString groupId;

	UPROPERTY()
	FString groupName;

	UPROPERTY()
	int32 currentPage;

	UPROPERTY()
	int32 currentPageSize;

	UPROPERTY()
	int32 totalCount;

	UPROPERTY()
	FString creatorId;

	UPROPERTY()
	FString playerId;

	UPROPERTY()
	FNexusBountyprogress_Struct progress;

	FNexusBountyGetCreatorBountiesByID200Response()
	: groupId()
		, groupName()
		, currentPage()
		, currentPageSize()
		, totalCount()
		, creatorId()
		, playerId()
		, progress()
	{
	}

};

/*---------------------------------------------------------------------------------------------
		API Functions
---------------------------------------------------------------------------------------------*/

class NEXUSUNREALSDK_API FNexusBountyAPI
{
public:
	DECLARE_DELEGATE_OneParam(FOnGetBounties200ResponseCallback, const FNexusBountyGetBounties200Response& /*Response*/);
	DECLARE_DELEGATE_OneParam(FOnGetBounties400ResponseCallback, const FNexusBountyBountyError& /*Response*/);

	struct FOnGetBountiesResponse
	{
			FOnGetBounties200ResponseCallback On200Response;
			FOnGetBounties400ResponseCallback On400Response;
	};
	static void GetBounties(const FNexusBountyGetBountiesRequestParams& RequestParams, const FOnGetBountiesResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

	DECLARE_DELEGATE_OneParam(FOnGetBounty200ResponseCallback, const FNexusBountyGetBounty200Response& /*Response*/);
	DECLARE_DELEGATE_OneParam(FOnGetBounty400ResponseCallback, const FNexusBountyBountyError& /*Response*/);

	struct FOnGetBountyResponse
	{
			FOnGetBounty200ResponseCallback On200Response;
			FOnGetBounty400ResponseCallback On400Response;
	};
	static void GetBounty(const FNexusBountyGetBountyRequestParams& RequestParams, const FOnGetBountyResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

	DECLARE_DELEGATE_OneParam(FOnGetCreatorBountiesByID200ResponseCallback, const FNexusBountyGetCreatorBountiesByID200Response& /*Response*/);
	DECLARE_DELEGATE_OneParam(FOnGetCreatorBountiesByID400ResponseCallback, const FNexusBountyBountyError& /*Response*/);

	struct FOnGetCreatorBountiesByIDResponse
	{
			FOnGetCreatorBountiesByID200ResponseCallback On200Response;
			FOnGetCreatorBountiesByID400ResponseCallback On400Response;
	};
	static void GetCreatorBountiesByID(const FNexusBountyGetCreatorBountiesByIDRequestParams& RequestParams, const FOnGetCreatorBountiesByIDResponse& ResponseDelegate, const FNexusOnHttpErrorDelegate& ErrorDelegate = {});

};

/*---------------------------------------------------------------------------------------------
		Blueprint Function Nodes
---------------------------------------------------------------------------------------------*/

UCLASS()
class NEXUSUNREALSDK_API UNexusGetBountiesNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetBountiesNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Bounty", WorldContext = "WorldContextObject"))
	static UNexusGetBountiesNode* GetBounties(UObject* WorldContextObject, const FNexusBountyGetBountiesRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetBounties200Response, const FNexusBountyGetBounties200Response& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetBounties200Response On200Response;

	void When200Callback(const FNexusBountyGetBounties200Response& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetBounties400Response, const FNexusBountyBountyError& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetBounties400Response On400Response;

	void When400Callback(const FNexusBountyBountyError& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetBountiesError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetBountiesError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusBountyGetBountiesRequestParams RequestParams;

};

UCLASS()
class NEXUSUNREALSDK_API UNexusGetBountyNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetBountyNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Bounty", WorldContext = "WorldContextObject"))
	static UNexusGetBountyNode* GetBounty(UObject* WorldContextObject, const FNexusBountyGetBountyRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetBounty200Response, const FNexusBountyGetBounty200Response& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetBounty200Response On200Response;

	void When200Callback(const FNexusBountyGetBounty200Response& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetBounty400Response, const FNexusBountyBountyError& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetBounty400Response On400Response;

	void When400Callback(const FNexusBountyBountyError& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetBountyError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetBountyError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusBountyGetBountyRequestParams RequestParams;

};

UCLASS()
class NEXUSUNREALSDK_API UNexusGetCreatorBountiesByIDNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UNexusGetCreatorBountiesByIDNode();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nexus|Bounty", WorldContext = "WorldContextObject"))
	static UNexusGetCreatorBountiesByIDNode* GetCreatorBountiesByID(UObject* WorldContextObject, const FNexusBountyGetCreatorBountiesByIDRequestParams& InRequestParams);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetCreatorBountiesByID200Response, const FNexusBountyGetCreatorBountiesByID200Response& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetCreatorBountiesByID200Response On200Response;

	void When200Callback(const FNexusBountyGetCreatorBountiesByID200Response& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetCreatorBountiesByID400Response, const FNexusBountyBountyError& /*Response*/, Param0);

	UPROPERTY(BlueprintAssignable)
	FGetCreatorBountiesByID400Response On400Response;

	void When400Callback(const FNexusBountyBountyError& Param0);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNexusGetCreatorBountiesByIDError, int32, ErrorCode);

	UPROPERTY(BlueprintAssignable)
	FNexusGetCreatorBountiesByIDError OnError;

	void WhenError(int32 ErrorCode);

	// See UBlueprintAsyncActionBase::Activate()
	virtual void Activate() override;

private:
	FNexusBountyGetCreatorBountiesByIDRequestParams RequestParams;

};
