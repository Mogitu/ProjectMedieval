// Project Medieval notice.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "PMGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EPMAbilityActivationPolicy:uint8
{
	OnTriggered,
	OnGiven
};

/**
 * 
 */
UCLASS()
class PROJECTMEDIEVAL_API UPMGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility,
	                        bool bWasCancelled) override;

	UPROPERTY(EditDefaultsOnly, Category="Warrior|Ability")
	EPMAbilityActivationPolicy AbilityActivationPolicy = EPMAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, category="Warrior|Ability")
	UPMAbilitySystemComponent* GetPMAbilitySystemComponentFromActorInfo() const;
};
