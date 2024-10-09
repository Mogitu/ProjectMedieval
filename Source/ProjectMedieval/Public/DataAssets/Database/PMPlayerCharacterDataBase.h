// Project Medieval notice.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DataAssets/Database/PMCharacterDataBase.h"
#include "PMPlayerCharacterDataBase.generated.h"

USTRUCT(BlueprintType)
struct FPlayerCharacterAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UPMGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

/**
 * 
 */
UCLASS()
class PROJECTMEDIEVAL_API UPMPlayerCharacterDataBase : public UPMCharacterDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UPMAbilitySystemComponent* InASCToGive, int32 ApplyLevel) override;

private:
private:
	UPROPERTY(EditDefaultsOnly, Category="StartUpData", meta=(TitleProperty= "InputTag"))
	TArray<FPlayerCharacterAbilitySet> PlayerStartUpAbilitySets;
};
