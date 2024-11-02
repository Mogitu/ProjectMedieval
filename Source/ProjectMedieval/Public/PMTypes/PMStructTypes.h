// Project Medieval notice.

#pragma once

#include "GameplayTagContainer.h"
#include "AbilitySystem/Abilities/PMGameplayAbility.h"
#include "PMStructTypes.generated.h"

USTRUCT(BlueprintType)
struct FPMAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories="InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UPMGameplayAbility> AbilityToGrant;

	bool IsValid() const { return InputTag.IsValid() && AbilityToGrant; }
};

USTRUCT(BlueprintType)
struct FPMWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(TitleProperty="InputTag"))
	TArray<FPMAbilitySet> DefaultWeaponAbilities;
};
