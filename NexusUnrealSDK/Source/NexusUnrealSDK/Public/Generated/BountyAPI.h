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
struct FNexusBountyBountySku
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
	FString externalId;

	UPROPERTY(BlueprintReadWrite)
	bool rewardCompleted;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString eventCode;

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString code;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
	double count;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	bool completed;

	UPROPERTY(BlueprintReadWrite)
	double count;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
	FString type;

	UPROPERTY(BlueprintReadWrite)
	FNexusBountyBountySku sku;

	UPROPERTY(BlueprintReadWrite)
	double amount;

	UPROPERTY(BlueprintReadWrite)
	FString currency;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
	FString type;

	UPROPERTY(BlueprintReadWrite)
	FString condition;

	UPROPERTY(BlueprintReadWrite)
	double count;

	UPROPERTY(BlueprintReadWrite)
	FString eventType;

	UPROPERTY(BlueprintReadWrite)
	FString eventCode;

	UPROPERTY(BlueprintReadWrite)
	FString nexusPurchaseObjectiveType;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusBountyBountySku> skus;

	UPROPERTY(BlueprintReadWrite)
	FNexusBountycategory_Struct category;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString objectiveGroupId;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusBountyBountyObjective> objectives;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	FString name;

	UPROPERTY(BlueprintReadWrite)
	FString description;

	UPROPERTY(BlueprintReadWrite)
	FString imageSrc;

	UPROPERTY(BlueprintReadWrite)
	FString rewardDescription;

	UPROPERTY(BlueprintReadWrite)
	double limit;

	UPROPERTY(BlueprintReadWrite)
	FDateTime startsAt;

	UPROPERTY(BlueprintReadWrite)
	FDateTime endsAt;

	UPROPERTY(BlueprintReadWrite)
	FDateTime lastProgressCheck;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusBountyBountyObjective> objectives;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusBountyBountyReward> rewards;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusBountydependants_Struct_Element> dependants;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	bool completed;

	UPROPERTY(BlueprintReadWrite)
	double completionCount;

	UPROPERTY(BlueprintReadWrite)
	FDateTime lastProgressCheck;

	UPROPERTY(BlueprintReadWrite)
	FString currentObjectiveGroupId;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusBountyBountyObjectiveProgress> currentObjectives;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	int32 page;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	bool includeProgress;

	UPROPERTY(BlueprintReadWrite)
	int32 page;

	UPROPERTY(BlueprintReadWrite)
	int32 pageSize;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	int32 page;

	UPROPERTY(BlueprintReadWrite)
	int32 pageSize;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString id;

	UPROPERTY(BlueprintReadWrite)
	bool completed;

	UPROPERTY(BlueprintReadWrite)
	double completionCount;

	UPROPERTY(BlueprintReadWrite)
	FDateTime lastProgressCheck;

	UPROPERTY(BlueprintReadWrite)
	FString currentObjectiveGroupId;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusBountyBountyObjectiveProgress> currentObjectives;

	UPROPERTY(BlueprintReadWrite)
	TArray<FNexusBountycompletedObjectives_Struct_Element> completedObjectives;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	int32 currentPage;

	UPROPERTY(BlueprintReadWrite)
	int32 currentPageSize;

	UPROPERTY(BlueprintReadWrite)
	int32 totalCount;

	UPROPERTY(BlueprintReadWrite)
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

	UPROPERTY(BlueprintReadWrite)
	FString groupId;

	UPROPERTY(BlueprintReadWrite)
	FString groupName;

	UPROPERTY(BlueprintReadWrite)
	FNexusBountyBounty bounty;

	UPROPERTY(BlueprintReadWrite)
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
	FString creatorId;

	UPROPERTY(BlueprintReadWrite)
	FString playerId;

	UPROPERTY(BlueprintReadWrite)
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
