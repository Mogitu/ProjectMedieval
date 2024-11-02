// Project Medieval notice.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "PMGameplayAbility.generated.h"

class UPMCombatComponent;

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

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	EPMAbilityActivationPolicy AbilityActivationPolicy = EPMAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category="Ability")
	UPMCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, category="Ability")
	UPMAbilitySystemComponent* GetPMAbilitySystemComponentFromActorInfo() const;

	// UFUNCTION(BlueprintCallable, Category="Ability", meta=(ApplyLevel = "1"))
	// void GrantWeaponAbilities();
	//
	// UFUNCTION(BlueprintCallable, Category="Ability")
	// void RemoveGrantedWeaponAbilities();
};
